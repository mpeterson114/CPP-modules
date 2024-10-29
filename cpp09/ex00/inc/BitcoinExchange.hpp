#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>

class BitcoinExchange 
{
    private:
        // <date, bitcoin price> from database
        std::map<std::string, double> _data;
    
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void parseDb(const std::string& filename);
        void parseInputFile(std::string filename);

        void printDb() const;
        std::string intToString(int i);
        bool isLeapYear(int year);
        void isValidDate(const std::string& date);

        void checkLineDB(const std::string& line);
        void checkInputLine(const std::string& line);
        

};

#endif
