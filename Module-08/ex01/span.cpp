#include "span.hpp"
#include <unistd.h>

Span::Span() : n(0), _span(0)
{
}
Span::Span(unsigned int n) : n(n), _span(0)
{
}
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

const char *Span::SpanFullException::what() const throw()
{
	return "Span is already full";
}
const char *Span::NoSpanException::what() const throw()
{
	return "No span can be found [empty or has one element]";
}

void Span::addNumber(int nbr)
{
	if (this->_span.size() >= this->n)
		throw Span::SpanFullException();
	this->_span.push_back(nbr);
}
unsigned int Span::shortestSpan()
{
	if (this->_span.size() < 2)
		throw Span::NoSpanException();

	// Copy and sort the vector to find the minimum span
	std::vector<int> sorted = this->_span;
	std::sort(sorted.begin(), sorted.end());

	// Initialize the minimum span with the first two elements
	unsigned int minSpan = static_cast<unsigned int>(sorted[1] - sorted[0]);

	// Traverse the sorted vector to find the smallest span
	for (size_t i = 1; i < sorted.size() - 1; ++i)
	{
		unsigned int span = static_cast<unsigned int>(sorted[i + 1] - sorted[i]);
		if (span < minSpan)
		{
			minSpan = span;
		}
	}

	return minSpan;
}

unsigned int Span::longestSpan()
{
	if (this->_span.size() < 2)
		throw Span::NoSpanException();
	return (*std::max_element(this->_span.begin(), this->_span.end()) - *std::min_element(this->_span.begin(), this->_span.end()));
}


void Span::fill(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (begin > end) // for invalid range
		throw Span::SpanFullException();
	
	std::vector<int>	vec(begin, end);
	if (vec.size() + this->_span.size() > this->n)
		throw Span::SpanFullException();
	_span.insert(_span.end(), vec.begin(), vec.end());
	
}
