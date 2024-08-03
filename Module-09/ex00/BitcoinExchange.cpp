#include "BitcoinExchange.hpp"

#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &) {}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &) { return *this; }

BitcoinExchange::~BitcoinExchange() {}

const char*	BitcoinExchange::DBFormatException::what() const throw()
{
	return "Database not formatted correctly!";
}

const char*	BitcoinExchange::DBEmptyException::what() const throw()
{
	return "Database is empty!";
}

int	isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int	daysInMonth(int year, int month)
{
	static const int daysPerMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 1 && isLeapYear(year))
		return 29;
	return daysPerMonth[month];
}

bool	BitcoinExchange::checkDate(const std::string &dateStr)
{
	std::tm tm = {};
	std::istringstream	ss(dateStr);

	ss >> std::get_time(&tm, "%Y-%m-%d");

	if (ss.fail() || !ss.eof())
		return false;
	if (tm.tm_year < 0 || tm.tm_mon < 0 || tm.tm_mon > 11 || tm.tm_mday < 1 || tm.tm_mday > 31)
		return false;
	if (tm.tm_mday > daysInMonth(tm.tm_year + 1900, tm.tm_mon))
		return false;
	return true;
}

bool	BitcoinExchange::checkValue(const std::string &valueStr)
{
	std::istringstream	ss(valueStr);
	double				value;

	ss >> value;
	if (ss.fail() || !ss.eof() || value < 0)
		return false;
	return true;
}

void	BitcoinExchange::parseDB()
{
	std::ifstream	dataFile("data.csv");
	std::string		line;
	std::string		date;
	std::string		value;

	if (!dataFile.is_open())
		throw std::runtime_error("Error: Couldn't open file.");
	std::getline(dataFile, line);
	while (std::getline(dataFile, line))
	{
		date = line.substr(0, line.find(',', 0));
		value = line.substr(line.find(',', 0) + 1, line.size());
		if (!checkDate(date) || !checkValue(value))
		{
			dataFile.close();
			throw BitcoinExchange::DBFormatException();
		}
		this->data[date] = std::stod(value, 0);
	}
	dataFile.close();
	if (this->data.empty())
		throw BitcoinExchange::DBEmptyException();
}

void	BitcoinExchange::putPrice(std::string const &date, double const value)
{
	std::map<std::string, double>::iterator it;
	double 									price;

	it = this->data.lower_bound(date);
	if (it != this->data.end() && it->first == date)
		price = value * it->second;
	else if (it == this->data.begin())
	{
		std::cerr << "Error: Date less than the first date in the database." << std::endl;
		return ;
	}
	else
		price = value * (--it)->second;
	std::cout << date << " => " << value << " = " << price << std::endl;
}

void	BitcoinExchange::parseInput(std::string const &fileName)
{
	std::ifstream	inputFile(fileName);
	std::string		line;
	std::string		date;
	std::string		value;
	double			value_nb;

	if (!inputFile.is_open())
		throw std::runtime_error("Error: Couldn't open file.");
	std::getline(inputFile, line);
	while (std::getline(inputFile, line))
	{
		size_t	pos = line.find(" | ", 0);
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input ==> " << line << std::endl;
			continue ;
		}
		date = line.substr(0, pos);
		if (!checkDate(date))
		{
			std::cerr << "Error: bad input ==> " << date << std::endl;
			continue ;
		}
		value = line.substr(pos + 3, line.size());
		if (!checkValue(value))
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue ;
		}
		value_nb = std::stod(value);
		if (value_nb > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue ;
		}
		this->putPrice(date, value_nb);
	}
	inputFile.close();
}

void	BitcoinExchange::putPrices(std::string const &fileName)
{
	BitcoinExchange	btc;

	try
	{
		btc.parseDB();
		btc.parseInput(fileName);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
