#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cerrno>

BitcoinExchange::BitcoinExchange() : _rates() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _rates(other._rates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        _rates = other._rates;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void    BitcoinExchange::run(const std::string& inputFilePath) {
    loadDatabase("data.csv");
    processInputFile(inputFilePath);
}

void    BitcoinExchange::loadDatabase(const std::string& csvPath) {
    std::ifstream file(csvPath.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database." << std::endl;
        return;
    }

    std::string line;
    if (!std::getline(file, line)) {
        std::cerr << "Error: empty database." << std::endl;
        return;
    }

    while (std::getline(file, line)) {
        if (line.empty())
            continue;
        
        std::size_t comma = line.find(',');
        if (comma == std::string::npos)
            continue;
        
        std::string date = trim(line.substr(0, comma));
        std::string rateStr = trim(line.substr(comma + 1));

        if (!isValidDate(date))
            continue;
        
        char* end = 0;
        errno = 0;
        double rate = std::strtod(rateStr.c_str(), &end);
        if (errno != 0 || end == rateStr.c_str() || *end != '\0')
            continue;
        
        _rates[date] = rate;
    }
}

void BitcoinExchange::processInputFile(const std::string& inputFilePath) {
    std::ifstream file(inputFilePath.c_str());
    if (!file.is_open()) {
        std::cout << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;

    if (!std::getline(file, line))
        return;

    if (trim(line) != "date | value") {
        std::string date, valueStr;
        if (parseInputLine(line, date, valueStr)) {
            if (!isValidDate(date)) {
                std::cout << "Error: bad input => " << line << std::endl;
            } else {
                double value = 0.0;
                std::string err;
                if (!parseValue(valueStr, value, err)) {
                    std::cout << err << std::endl;
                } else {
                    double rate = 0.0;
                    if (!findRateForDate(date, rate)) {
                        std::cout << "Error: bad input => " << line << std::endl;
                    } else {
                        std::cout << date << " => " << valueStr << " = " << (value * rate) << std::endl;
                    }
                }
            }
        } else if (!trim(line).empty()) {
            std::cout << "Error: bad input => " << line << std::endl;
        }
    }

    while (std::getline(file, line)) {
        if (trim(line).empty())
            continue;

        std::string date, valueStr;
        if (!parseInputLine(line, date, valueStr)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (!isValidDate(date)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        double value = 0.0;
        std::string err;
        if (!parseValue(valueStr, value, err)) {
            std::cout << err << std::endl;
            continue;
        }

        double rate = 0.0;
        if (!findRateForDate(date, rate)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::cout << date << " => " << valueStr << " = " << (value * rate) << std::endl;
    }
}

bool BitcoinExchange::parseInputLine(const std::string& line, std::string& dateOut, std::string& valueOut) const {
    std::size_t pipe = line.find('|');
    if (pipe == std::string::npos)
        return false;

    std::string left = trim(line.substr(0, pipe));
    std::string right = trim(line.substr(pipe + 1));

    if (left.empty() || right.empty())
        return false;

    dateOut = left;
    valueOut = right;
    return true;
}

bool BitcoinExchange::isLeapYear(int y) const {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int BitcoinExchange::daysInMonth(int y, int m) const {
    static const int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2)
        return days[m - 1] + (isLeapYear(y) ? 1 : 0);
    return days[m - 1];
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7)
            continue;
        if (date[i] < '0' || date[i] > '9')
            return false;
    }

    int y = std::atoi(date.substr(0, 4).c_str());
    int m = std::atoi(date.substr(5, 2).c_str());
    int d = std::atoi(date.substr(8, 2).c_str());

    if (m < 1 || m > 12)
        return false;

    int dim = daysInMonth(y, m);
    if (d < 1 || d > dim)
        return false;

    return true;
}

bool BitcoinExchange::parseValue(const std::string& valueStr, double& valueOut, std::string& errMsg) const {
    char* end = 0;
    errno = 0;

    double v = std::strtod(valueStr.c_str(), &end);

    if (end == valueStr.c_str() || *end != '\0' || errno == ERANGE) {
        errMsg = "Error: bad input => " + valueStr;
        return false;
    }

    if (v < 0.0) {
        errMsg = "Error: not a positive number.";
        return false;
    }

    if (v > 1000.0) {
        errMsg = "Error: too large a number.";
        return false;
    }

    valueOut = v;
    return true;
}

bool BitcoinExchange::findRateForDate(const std::string& date, double& rateOut) const {
    if (_rates.empty())
        return false;

    std::map<std::string, double>::const_iterator it = _rates.find(date);
    if (it != _rates.end()) {
        rateOut = it->second;
        return true;
    }

    it = _rates.lower_bound(date);

    if (it == _rates.begin())
        return false;

    if (it == _rates.end() || it->first != date)
        --it;

    rateOut = it->second;
    return true;
}

std::string BitcoinExchange::trim(const std::string& s) {
    std::size_t b = 0;
    while (b < s.size() && (s[b] == ' ' || s[b] == '\t'))
        ++b;

    std::size_t e = s.size();
    while (e > b && (s[e - 1] == ' ' || s[e - 1] == '\t'))
        --e;

    return s.substr(b, e - b);
}