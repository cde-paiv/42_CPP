#pragma once
#include <cstddef>
#include <stdexcept>

template <typename T>
class Array {
public:
    Array() : _data(0), _n(0) {}

    explicit Array(unsigned int n) : _data(0), _n(n) {
        _data = (n ? new T[n]() : 0);
    }

    Array(const Array& other) : _data(0), _n(other._n) {
        if (_n) {
            _data = new T[_n]();
            for (size_t i = 0; i < _n; ++i) _data[i] = other._data[i];
        }
    }

    ~Array() { delete[] _data; }

    Array& operator=(const Array& other) {
        if (this != &other) {
            T* newData = (other._n ? new T[other._n]() : 0);
            for (size_t i = 0; i < other._n; ++i) newData[i] = other._data[i];
            delete[] _data;
            _data = newData;
            _n = other._n;
        }
        return *this;
    }

    T& operator[](size_t idx) {
        if (idx >= _n) throw std::out_of_range("Array index out of range");
        return _data[idx];
    }

    const T& operator[](size_t idx) const {
        if (idx >= _n) throw std::out_of_range("Array index out of range");
        return _data[idx];
    }

    size_t size() const { return _n; }

private:
    T*     _data;
    size_t _n;
};
