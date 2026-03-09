#pragma once

#include <iostream>
#include <deque>
#include <vector>
#include <ctime>
#include <cctype>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <stdexcept>
#include <string>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe &copy);
    PmergeMe &operator=(const PmergeMe &copy);
    ~PmergeMe();

    void run(int ac, char **av);

private:
    std::deque<int>  _deque;
    std::vector<int> _vector;

    double _vecTime;
    double _deqTime;

    // parsing
    int parsePositiveInt(const char* s) const;

    // VECTOR sort
    void vecFordJohnsonSort(std::vector<int>& arr);
    void vecFordJohnsonRecursive(std::vector<int>& arr, int left, int right);
    void vecMergeInsert(std::vector<int>& arr, int left, int mid, int right);
    int  vecFindInsertPos(const std::vector<int>& arr, int left, int right, int value) const;

    // DEQUE sort
    void deqFordJohnsonSort(std::deque<int>& arr);
    void deqFordJohnsonRecursive(std::deque<int>& arr, int left, int right);
    void deqMergeInsert(std::deque<int>& arr, int left, int mid, int right);
    int  deqFindInsertPos(const std::deque<int>& arr, int left, int right, int value) const;
};