#include "span.hpp"

int main(void)
{
	Span sp = Span(5);

	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::srand(static_cast<unsigned int>(std::time(NULL)));
	
	Span sp1 = Span(10000);
	std::vector<int> vec;
	for (size_t i = 0; i < 10000; i++)
	{
		vec.push_back(std::rand());
	}
	
	try
	{
		sp1.fill(vec.begin(), vec.end());		
		std::cout << "Shortest Span: " << sp1.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp1.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
		
	}
	return (0);
}
