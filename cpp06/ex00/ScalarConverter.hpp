#pragma once
#include <iostream>
#include <limits>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cctype>

typedef enum e_types {
    ERR,
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO_LITERAL,
} t_types;

class ScalarConverter {
    public:
        static void convert(const std::string &input);

    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);

        // detectar tipo
        static t_types getType(const std::string &param);
        static bool isChar(const std::string &param);
        static bool isInt(const std::string &param);
        static bool isFloat(const std::string &param);
        static bool isDouble(const std::string &param);
        static bool isPseudoLiteral(const std::string &param);

        // conversao e prints de um unico numero
        static void convertData(const std::string &param, long double nbr);
        static void convertChar(const std::string &param, char c);
        static void convertInt(const std::string &param, int i);
        static void convertDouble(const std::string &param, double d);
        static void convertFloat(const std::string &param,float f);

        // check overflow
        static bool isOverflow(const std::string &param, t_types type);

        // prints auxiliares
        static void printPseudoliteral(const std::string &param);
        static void printInvalidInput(const std::string &param);
};