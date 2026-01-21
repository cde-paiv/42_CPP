#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return (*this);
}

// unico caracter e nao digito
bool ScalarConverter::isChar(const std::string &param) {
    return (param.length() == 1
            && std::isprint(static_cast<unsigned char>(param[0]))
            && !std::isdigit(static_cast<unsigned char>(param[0])));
}

//int decimal
bool ScalarConverter::isInt(const std::string &param) {
    if (param.empty()) return false;
    size_t i = 0;
    if (param[i] == '+' || param[i] == '-') i++;

    if (i == param.length())  // sinal, sem digito
        return false;
    for (; i < param.length(); i++)
        if (!std::isdigit(static_cast<unsigned char>(param[i])))
            return false;
    return true;
}

//precisa de ponto e termina com F
bool ScalarConverter::isFloat(const std::string &value)
{
    if (value.empty())
        return false;

    // tem que terminar com 'f'
    if (value[value.size() - 1] != 'f')
        return false;

    // remove o 'f' final
    std::string temp = value.substr(0, value.size() - 1);
    if (temp.empty())
        return false;

    size_t i = 0;
    bool decimal = false;
    bool hasDigit = false;

    if (temp[i] == '+' || temp[i] == '-')
    {
        i++;
        if (i == temp.size())
            return false;
    }

    while (i < temp.size())
    {
        if (temp[i] == '.')
        {
            if (decimal)
                return false;
            decimal = true;
        }
        else if (std::isdigit(static_cast<unsigned char>(temp[i])))
        {
            hasDigit = true;
        }
        else
            return false;

        i++;
    }

    // precisa ter ponto E pelo menos 1 dígito
    return (decimal && hasDigit);
}

// precisa ter o ponto '.'
bool ScalarConverter::isDouble(const std::string &value)
{
    if (value.empty())
        return false;

    size_t i = 0;
    bool decimal = false;
    bool hasDigit = false;

    if (value[i] == '+' || value[i] == '-')
    {
        i++;
        if (i == value.size())
            return false;
    }

    while (i < value.size())
    {
        if (value[i] == '.')
        {
            if (decimal)
                return false;
            decimal = true;
        }
        else if (std::isdigit(static_cast<unsigned char>(value[i])))
        {
            hasDigit = true;
        }
        else
            return false;

        i++;
    }

    return (decimal && hasDigit);
}

bool ScalarConverter::isPseudoLiteral(const std::string &param) {
    return (param == "nan" || param == "nanf" || param == "+inff"
        || param == "+inff" || param == "-inf" || param == "+inf" ||
        param == "inff" || param == "inf");
}

t_types ScalarConverter::getType(const std::string &param){
    if (isChar(param)) return CHAR;
    else if (isInt(param)) return INT;
    else if (isFloat(param)) return FLOAT;
    else if (isDouble(param)) return DOUBLE;
    else if (&isPseudoLiteral) return PSEUDO_LITERAL;
    else return ERR;
}

//impressoes por tipo base
void ScalarConverter::convertChar(const std::string &param, char c) {
    (void)param;
    std::cout << "char: ";
    if (!std::isprint(static_cast<unsigned char>(c)))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << c << "'\n";
}

void ScalarConverter::convertInt(const std::string &param, int i) {
    (void)param;
    std::cout << "int: " << i << "\n";
}

void ScalarConverter::convertFloat(const std::string &param, float f) {
    (void)param;
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
}

void ScalarConverter::convertDouble(const std::string &param, double d) {
    (void)param;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << "\n";
}

// Checa overflow comparando o valor numérico do input com limites do tipo
bool ScalarConverter::isOverflow(const std::string &param, t_types type) {
    long double nbr = std::strtold(param.c_str(), NULL);

    switch (type) {
        case CHAR:
            return (nbr < std::numeric_limits<char>::min() ||
                    nbr > std::numeric_limits<char>::max());
        case INT:
            return (nbr < std::numeric_limits<int>::min() ||
                    nbr > std::numeric_limits<int>::max());
        case FLOAT:
            return (nbr < -std::numeric_limits<float>::max() ||
                    nbr >  std::numeric_limits<float>::max());
        case DOUBLE:
            return (nbr < -std::numeric_limits<double>::max() ||
                    nbr >  std::numeric_limits<double>::max());
        default:
            return true;
    }
}

// Impressão central: converte “um número base” para os 4 tipos
void ScalarConverter::convertData(const std::string &param, long double nbr) {
    // CHAR
    std::cout << "char: ";
    if (isOverflow(param, CHAR)) {
        std::cout << "impossible\n";
    } else {
        char c = static_cast<char>(nbr);
        if (!std::isprint(static_cast<unsigned char>(c)))
            std::cout << "Non displayable\n";
        else
            std::cout << "'" << c << "'\n";
    }

    // INT
    std::cout << "int: ";
    if (isOverflow(param, INT)) {
        std::cout << "impossible\n";
    } else {
        std::cout << static_cast<int>(nbr) << "\n";
    }

    // FLOAT
    std::cout << "float: ";
    if (isOverflow(param, FLOAT)) {
        std::cout << "impossible\n";
    } else {
        std::cout << std::fixed << std::setprecision(1)
                  << static_cast<float>(nbr) << "f\n";
    }

    // DOUBLE
    std::cout << "double: ";
    if (isOverflow(param, DOUBLE)) {
        std::cout << "impossible\n";
    } else {
        std::cout << std::fixed << std::setprecision(1)
                  << static_cast<double>(nbr) << "\n";
    }
}

// Pseudo literais: imprime direto os formatos de NaN/Inf
void ScalarConverter::printPseudoliteral(const std::string &param) {
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";

    if (param == "nan" || param == "nanf") {
        std::cout << "float: nanf\n";
        std::cout << "double: nan\n";
    } else {
        // "+inf / -inf" e "+inff / -inff"
        char sign = param[0]; // '+' ou '-'
        std::cout << "float: "  << sign << "inff\n";
        std::cout << "double: " << sign << "inf\n";
    }
}

// Input inválido
void ScalarConverter::printInvalidInput(const std::string &param) {
    (void)param;
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: impossible\n";
    std::cout << "double: impossible\n";
}

//  Função principal
void ScalarConverter::convert(const std::string &input) {
    switch (getType(input)) {
        case CHAR: {
            // ex.: "a"
            long double v = static_cast<unsigned char>(input[0]);
            convertData(input, v);
            return;
        }
        case INT: {
            // ex.: "42"
            long double v = static_cast<long double>(std::atoi(input.c_str()));
            convertData(input, v);
            return;
        }
        case FLOAT: {
            // ex.: "4.2f" → remove 'f' e usa atof
            std::string core = input.substr(0, input.size() - 1);
            long double v = static_cast<long double>(std::atof(core.c_str()));
            convertData(input, v);
            return;
        }
        case DOUBLE: {
            // ex.: "4.2"
            long double v = std::strtold(input.c_str(), 0);
            convertData(input, v);
            return;
        }
        case PSEUDO_LITERAL:
            printPseudoliteral(input);
            return;
        default:
            printInvalidInput(input);
            return;
    }
}