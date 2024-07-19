#include "Converter.hpp"

ScalarConverter::ScalarConverter()
{}
ScalarConverter::ScalarConverter(const ScalarConverter& )
{
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& )
{
    return *this;
}
ScalarConverter::~ScalarConverter(){}

bool isPseudoLiterals(const std::string &str)
{
    if (str == "+inff" || str == "-inff" || str == "nanf" || str == "nan" || str == "+inf" || str == "-inf")
        return true;
    return false;
}

bool isFloatPoint(const std::string &str)
{
    std::istringstream isso(str);
    double val;
    isso >> val;
    if (isso.fail() || !isso.eof())
    {
        if (str[str.size() - 1] == 'f')
        {
            std::istringstream isso(str.substr(0, str.size() - 1));
            double val;
            isso >> val;
            if (isso.fail() || !isso.eof())
                return false;
            return true;
        }
        return false;
    }
    return true;
}

void determineValueType(const std::string &str, double *val, std::string *val_str, e_type *type)
{
    if (isPseudoLiterals(str))
    {
        *val_str = str;
        *type = STRING;
        return;
    }
    if (str.length() == 1 && !isdigit(str[0]))
    {
        *val = static_cast<double>(str[0]);
        *type = DOUBLE;
        return;
    }
    if (!isFloatPoint(str))
    {
        *val_str = str;
        *type = STRING;
        return;
    }
    *val = std::stod(str);
    *type = DOUBLE;
}

void toChar(const e_type type, const double val)
{
    char c;
    if (type == STRING)
    {
        std::cout << "impossible";
        return;
    }
    c = static_cast<char>(val);
    if (!(c >= ' ' && c < 127))
    {
        std::cout << "Non Displayable";
        return;
    }
    std::cout << "'" << c << "'";
}

void toInt(const e_type type, const double val)
{
    int i;
    if (type == STRING)
    {
        std::cout << "impossible";
        return;
    }
    if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::lowest())
    {
        std::cout << "impossible";
        return;
    }
    i = static_cast<int>(val);
    std::cout << i;
}

bool hasZeroFractionalPart(const std::string &str)
{
    int i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] && str[i] != '.' && str[i] != 'f')
        i++;
    if (!str[i] || str[i] == 'f')
        return true;
    i++;
    while (str[i] == '0')
        i++;
    if (!str[i] || str[i] == 'f')
        return true;
    return false;
}

void toFloat(const std::string str, const e_type type, const double val, const std::string &val_str)
{
    float flt;
    if (type == STRING )
    {
        if (val_str == "+inf")
            std::cout << "+inff";
        else if (val_str == "-inf")
            std::cout << "-inff";
        else if (val_str == "nan")
            std::cout << "nanf";
        else if (val_str == "nanf" || val_str == "+inff" || val_str == "-inff")
            std::cout << val_str;
        else
            std::cout << "impossible";
        return;
        
    }
    if (val > std::numeric_limits<float>::max() || val < std::numeric_limits<float>::lowest())
    {
        std::cout << "impossible";
        return ;
    }
    flt = static_cast<float>(val);
    std::cout << flt;
    if (hasZeroFractionalPart(str))
        std::cout << ".0f";
    else
        std::cout << "f";
}

void	toDouble(const std::string str, const e_type type, const double val, const std::string val_str)
{
	if (type == STRING)
	{
		if (val_str == "-inff")
			std::cout << "-inf";
		else if (val_str == "+inff")
			std::cout << "+inf";
		else if (val_str == "nanf")
			std::cout << "nan";
		else if (val_str == "nan" || val_str == "+inf" || val_str == "-inf")
			std::cout << val_str;
		else
			std::cout << "impossible";
		return ;
	}
	std::cout << val;
	if (hasZeroFractionalPart(str))
		std::cout << ".0";
}

void ScalarConverter::convert(std::string &str)
{
    double val;
    std::string val_str;
    e_type type;

    determineValueType(str, &val, &val_str, &type);
    std::cout << "char: "; toChar(type, val); std::cout << std::endl;
    std::cout << "int: "; toInt(type, val); std::cout << std::endl;
    std::cout << "float: "; toFloat(str, type, val, val_str); std::cout << std::endl;
    std::cout << "double: "; toDouble(str, type, val, val_str); std::cout << std::endl;
}