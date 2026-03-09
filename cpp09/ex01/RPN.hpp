#pragma once

#include <stack>
#include <string>

class RPN {
public:
    RPN();
    ~RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);

    int calculate(const std::string& expression);

private:
    std::stack<int> _numbers;

    bool isOperator(char c) const;
    bool isDigit(const std::string& token) const;

    void performOperation(char op);
};

