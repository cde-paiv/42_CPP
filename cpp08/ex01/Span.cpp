#include "Span.hpp"
#include <algorithm>

Span::Span() : _v(), _cap(0) {}

Span::Span(unsigned int N) : _v(), _cap(N) {}

Span::Span(const Span& other) : _v(other._v), _cap(other._cap) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _v   = other._v;
        _cap = other._cap;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int x) {
    if (_v.size() >= _cap)
        throw std::runtime_error("Span full");
    _v.push_back(x);
}

int Span::shortestSpan() const {
    if (_v.size() < 2)
        throw std::runtime_error("Not enough numbers");
    std::vector<int> tmp(_v);
    std::sort(tmp.begin(), tmp.end());
    int best = tmp[1] - tmp[0];
    for (std::size_t i = 1; i + 1 < tmp.size(); ++i) {
        int d = tmp[i + 1] - tmp[i];
        if (d < best) best = d;
    }
    return best;
}

int Span::longestSpan() const {
    if (_v.size() < 2) throw std::runtime_error("Not enough numbers");
    std::vector<int>::const_iterator min = std::min_element(_v.begin(), _v.end());
    std::vector<int>::const_iterator max = std::max_element(_v.begin(), _v.end());
    return *max - *min;
}

std::size_t Span::size() const { return _v.size(); }
unsigned int Span::capacity() const { return _cap; }
