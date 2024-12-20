#include <BitcoinExchange.hpp>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <exception>
#include <string>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _data(other._data)
{}
        
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) 
{
    if (this != &other)
        this->_data = other._data;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::printDb() const
{
    for (std::map<std::string, double>::const_iterator it = _data.begin(); it != _data.end(); ++it)
        std::cout << it->first << "," << it ->second << std::endl;
}

std::string BitcoinExchange::intToString(int i)
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}

/* Year is leap year if:
    -Divisible by 4 but not by 100 (ex: 2020)
    -Divisible by 4, by 100 and by 400 (ex: 2000)
*/
bool BitcoinExchange::isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void BitcoinExchange::isValidDate(const std::string& date)
{
    std::stringstream ss(date);
    int year, month, day;
    char delim1, delim2;

    if (!(ss >> year >> delim1 >> month >> delim2 >> day) || delim1 != '-' || delim2 != '-' || !ss.eof() || ss.fail())
        throw std::runtime_error("Error: Invalid date format => " + date);
    if (month < 1 || month > 12)
        throw std::runtime_error("Error: Invalid month value '" + intToString(month) + "' => " + date);
    if (year < 2009 || year > 2022)
        throw std::runtime_error("Error: Data for year '" + intToString(year) + "' not available in database => " + date);

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
        daysInMonth[2] = 29;
    
    if (day < 1 || day > daysInMonth[month])
        throw std::runtime_error("Error: Invalid day value '" + intToString(day) + "' => "  + date);
}

void BitcoinExchange::checkLineDB(const std::string& line)
{
    std::stringstream ss(line);
    std::string key;
    double value;

    std::getline(ss, key, ',');
    ss >> value;
    isValidDate(key);
    if (value < 0)
        throw std::runtime_error("Error: Value must be a positive number => " + line);
    if (!ss.eof() || ss.fail())
        throw std::runtime_error("Error: Invalid exchange rate format => " + line);
    this->_data[key] = value;
}

void BitcoinExchange::parseDb(const std::string& filename)
{
    /* Need to convert filename to c string to work with ifstream in c++98 */
    std::ifstream db(filename.c_str());
    std::string line;

    try
    {
        if (!db.is_open())
            throw std::runtime_error("Error: Could not open database file");
        std::getline(db, line);
        if (line != "date,exchange_rate")
            throw std::runtime_error("Error: Invalid header format in database file");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    while (std::getline(db, line))
    {
        std::stringstream ss(line);
        try
        {
            checkLineDB(line);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
            continue ;
        }
    }
    db.close();
}

void BitcoinExchange::checkInputLine(std::string line)
{
    if (line[0] == ' ' || line[0] == '\t')
        throw std::runtime_error("Error: Input file line cannot begin with whitespace => " + line);
    
    size_t delimIndex = line.find(" | ");
    if (delimIndex == std::string::npos)
        throw std::runtime_error("Error: Valid delimiter not found in input file line => " + line);
    if (std::count(line.begin(), line.end(), ' ' > 2))
        throw std::runtime_error("Error: Invalid amount of whitespace in input file line => " + line);
    line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
    std::stringstream ss(line);
    std::string key;
    double value;
    std::getline(ss, key, '|');
    ss >> value;
    isValidDate(key);
    if (value < 0 || value > 1000)
        throw std::runtime_error("Error: Invalid input value, must be between 0 and 1000 => " + line);
    if (!ss.eof() || ss.fail())
        throw std::runtime_error("Error: Invalid input line format => " + line);
    if (_data.find(key) != _data.end())
        std::cout << key << " => " << value << " = " << value * _data[key] << std::endl;
    else
    {
        std::map<std::string, double>::iterator it = _data.lower_bound(key);
        if (it == _data.begin())
            throw std::runtime_error("Error: No exchange rate found for entered date => " + line);
        else
        {
            it--;
            std::cout << key << " => " << value << " = " << value * it->second << std::endl;
        }
    }

}

void BitcoinExchange::parseInputFile(const std::string& filename)
{
    /* Need to convert filename to c string to work with ifstream in c++98 */
    std::ifstream input(filename.c_str());
    std::string line;

    try
    {
        if (!input.is_open())
            throw std::runtime_error("Error: Could not open input file");
        std::getline(input, line);
        if (line != "date | value")
            throw std::runtime_error("Error: Invalid header format in input file");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    while (std::getline(input, line))
    {
        std::stringstream ss(line);
        if (line.empty())
            continue;
        try
        {
            checkInputLine(line);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
            continue ;
        }
    }
    input.close();
}

/* Std::stringstream: 
    -Works with variety of data types
    -Uses ' ' as delimeter by default (ex: "42 3.14 hello")-would treat
     '42', '3.14' and 'hello' as their own tokens 
    - >> operator is type-safe in stringstream, meaning that data on the 
     right side of the '>>' will be extracted only if it matches the expected data
     type.
    -**Variable types and their order must match the data types and order in the input
        -ex: to extract variables from "42 3.14 hello", have to declare variables in 
        order that they appear in the input string (int a, float b, std::string c) or 
        won't work
*/  


