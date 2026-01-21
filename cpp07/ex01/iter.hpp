#pragma once
#include <cstddef>

template <typename T, typename F>
void iter(T* array, std::size_t length, F func) {
    if (!array) return;
    for (std::size_t i = 0; i < length; ++i)
        func(array[i]);
}

template <typename T, typename F>
void iter(T const* array, std::size_t lenght, F func) {
    if (!array) return;
    for (std::size_t i = 0; i < lenght; ++i)
        func(array[i]);
}