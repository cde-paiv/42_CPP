#include "RPN.hpp"

#include <stdexcept>
#include <sstream>
#include <climits>
#include <cctype>

RPN::RPN() {}
RPN::RPN(const RPN& other) : _numbers(other._numbers) {}
RPN& RPN::operator=(const RPN& other) {
    if (this != &other)
        _numbers = other._numbers;
    return *this;
}
RPN::~RPN() {}

bool RPN::isOperator(char c) const {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool RPN::isDigit(const std::string& token) const {
    if (token.length() != 1)
        return false;
    return std::isdigit(static_cast<unsigned char>(token[0])) != 0;
}

void RPN::performOperation(char op) {
    if (_numbers.size() < 2)
        throw std::runtime_error("Error");

    int b = _numbers.top(); _numbers.pop();
    int a = _numbers.top(); _numbers.pop();

    long result = 0;

    if (op == '+')
        result = (long)a + (long)b;
    else if (op == '-')
        result = (long)a - (long)b;
    else if (op == '*')
        result = (long)a * (long)b;
    else if (op == '/') {
        if (b == 0)
            throw std::runtime_error("Error");
        result = (long)a / (long)b;
    } else
        throw std::runtime_error("Error");

    if (result < INT_MIN || result > INT_MAX)
        throw std::runtime_error("Error");

    _numbers.push((int)result);
}

int RPN::calculate(const std::string& expression) {
    _numbers = std::stack<int>();

    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isDigit(token)) {
            _numbers.push(token[0] - '0');
        } else if (token.size() == 1 && isOperator(token[0])) {
            performOperation(token[0]);
        } else {
            throw std::runtime_error("Error");
        }
    }

    if (_numbers.size() != 1)
        throw std::runtime_error("Error");

    return _numbers.top();
}