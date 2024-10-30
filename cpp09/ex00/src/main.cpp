#include "BitcoinExchange.hpp"

/* Parsing:
    -CSV Database: store bitcoin prices by date in map (date = key, price = value)
    -Input file (date | value entries)
    -For both: ensure valid date format and that values are between 0-1000

    Data Storage:
    -Store Database info in map structure (date | price)
    
    Date lookup:
    -Compare input file date with dates in map container
        -Exact match vs lower-bound search: get bitcoin price at that date

    Price Calculation:
    -Multiply price on given date by the int specified in the input file
    -Output result with proper formatting ([date] => [input value] = [price x input result])

    Error Handling:
    -Add exceptions for formatting or invalid range errors w/o exiting program
*/

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Invalid number of arguments (Usage: ./btc <input.csv>)" << std::endl;
        return (1);
    }   
    BitcoinExchange btc = BitcoinExchange();
    btc.parseDb("data.csv");
    btc.parseInputFile(argv[1]);
    return (0);
}