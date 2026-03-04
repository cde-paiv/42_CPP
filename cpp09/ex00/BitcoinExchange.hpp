#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void run(const std::string& inputFilePath);

private:
    std::map<std::string, double> _rates; // key: "YYYY-MM-DD", value: rate

    void loadDatabase(const std::string& csvPath);
    void processInputFile(const std::string& inputFilePath);

    bool    parseinputLine(const std::string& line, std::string& dateOut, std::string& valueOut);
    
    bool    isValidDate(const std::string& date) const;
    bool    isLeapYear(int y) const;
    int     daysInMonth(int y, int m) const;

    bool    parseValue(const std::string& valueStr, double& valueOut, std::string& errMsg) const;

    bool    findRateForDate(const std::string& date, double& ratOut) const;

    static std::string trim(const std::string& s);
};

#endif
