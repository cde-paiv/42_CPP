#pragma once
#include <vector>
#include <cstddef>
#include <stdexcept>

class Span {
public:
    Span();
    explicit Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int x);
    int  shortestSpan() const;
    int  longestSpan()  const;

    template <typename It>
    void addRange(It first, It last) {
        for (; first != last; ++first) {
            if (_v.size() >= _cap)
                throw std::runtime_error("Span full in addRange");
            _v.push_back(*first);
        }
    }


    std::size_t   size()     const;
    unsigned int  capacity() const;

private:
    std::vector<int> _v;
    unsigned int     _cap;
};
