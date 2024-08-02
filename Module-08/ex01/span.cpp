#include "span.hpp"
#include <unistd.h>

Span::Span() : n(0), _span(0)
{}
Span::Span(unsigned int n) : n(n), _span(0)
{}
Span::Span(Span const &cpy)
{
    *this = cpy;
}
Span &Span::operator=(Span const &src)
{
    this->n = src.n;
    this->_span = src._span;
    return *this;
}
Span::~Span() {};

const char* Span::SpanFullException::what() const throw()
{
    return "Span is already full";
}
const char* Span::NoSpanException::what() const throw()
{
    return "No span can be found [empty or has one element]";
}

void    Span::addNumber(int nbr)
{
    if (this->_span.size() >= this->n)
        throw Span::SpanFullException();
    this->_span.push_back(nbr);
}
unsigned int		Span::shortestSpan()
{
	if (this->_span.size() < 2)
		throw Span::NoSpanException();
	std::vector<int>copy = this->_span;
	std::sort(copy.begin(), copy.end(), std::less<int>());
	return *(copy.begin());
}

unsigned int		Span::longestSpan()
{
	if (this->_span.size() < 2)
		throw Span::NoSpanException();
	std::vector<int>copy = this->_span;
	std::sort(copy.begin(), copy.end(), std::greater<int>());
	return *(copy.begin());
}

static	int	randomInt(size_t size)
{
	int i;

	srand((unsigned)time(0));
	i = (rand() % size) + 1;
	return (i);
}

void    Span::fill(void)
{
	size_t	start;

	start = _span.size();
	while (start < n)
	{
		usleep(50);
		_span.push_back(randomInt(n));
		start++;
	}
}
