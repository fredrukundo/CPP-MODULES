#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	switch (ac)
	{
		case 1:
			std::cerr << "Error: Couldn't open file." << std::endl;
			break ;
		case 2:
			try
			{
				std::string	file(av[1]);
				BitcoinExchange::putPrices(file);
			}
			catch (std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
			break ;
		default:
			std::cerr << "Error: Too many arguments." << std::endl;
	}
}