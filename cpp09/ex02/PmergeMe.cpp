#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vecTime(0), _deqTime(0) {}

PmergeMe::PmergeMe(const PmergeMe &copy)
: _deque(copy._deque), _vector(copy._vector),
  _vecTime(copy._vecTime), _deqTime(copy._deqTime) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy) {
    if (this != &copy) {
        _deque = copy._deque;
        _vector = copy._vector;
        _vecTime = copy._vecTime;
        _deqTime = copy._deqTime;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

int PmergeMe::parsePositiveInt(const char* s) const {
    if (!s || !*s)
        throw std::runtime_error("Error");

    for (int i = 0; s[i]; ++i) {
        unsigned char c = static_cast<unsigned char>(s[i]);
        if (!std::isdigit(c))
            throw std::runtime_error("Error");
    }

    errno = 0;
    long v = std::strtol(s, NULL, 10);
    if (errno != 0 || v > INT_MAX || v <= 0)
        throw std::runtime_error("Error");

    return static_cast<int>(v);
}

// Find insertion position for value in sorted arr[left..right]
int PmergeMe::vecFindInsertPos(const std::vector<int>& arr, int left, int right, int value) const {
    int pos = left;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > value)
            right = mid - 1;
        else {
            pos = mid + 1;
            left = mid + 1;
        }
    }
    return pos;
}

void PmergeMe::vecMergeInsert(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> temp;
    temp.reserve(right - left + 1);

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else                  temp.push_back(arr[j++]);
    }
    while (i <= mid)  temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (size_t k = 0; k < temp.size(); ++k)
        arr[left + static_cast<int>(k)] = temp[k];
}

// VECTOR: recursive sort
void PmergeMe::vecFordJohnsonRecursive(std::vector<int>& arr, int left, int right) {
    // Small range: insertion sort with binary search for pos
    if (right - left <= 16) {
        for (int i = left + 1; i <= right; ++i) {
            int value = arr[i];
            int pos = vecFindInsertPos(arr, left, i - 1, value);

            for (int j = i; j > pos; --j)
                arr[j] = arr[j - 1];

            arr[pos] = value;
        }
        return;
    }

    int mid = left + (right - left) / 2;
    vecFordJohnsonRecursive(arr, left, mid);
    vecFordJohnsonRecursive(arr, mid + 1, right);
    vecMergeInsert(arr, left, mid, right);
}

void PmergeMe::vecFordJohnsonSort(std::vector<int>& arr) {
    if (arr.size() <= 1) return;
    vecFordJohnsonRecursive(arr, 0, static_cast<int>(arr.size()) - 1);
}

int PmergeMe::deqFindInsertPos(const std::deque<int>& arr, int left, int right, int value) const {
    int pos = left;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > value)
            right = mid - 1;
        else {
            pos = mid + 1;
            left = mid + 1;
        }
    }
    return pos;
}

void PmergeMe::deqMergeInsert(std::deque<int>& arr, int left, int mid, int right) {
    std::deque<int> temp;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else                  temp.push_back(arr[j++]);
    }
    while (i <= mid)  temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (size_t k = 0; k < temp.size(); ++k)
        arr[left + static_cast<int>(k)] = temp[k];
}

void PmergeMe::deqFordJohnsonRecursive(std::deque<int>& arr, int left, int right) {
    if (right - left <= 16) {
        for (int i = left + 1; i <= right; ++i) {
            int value = arr[i];
            int pos = deqFindInsertPos(arr, left, i - 1, value);

            for (int j = i; j > pos; --j)
                arr[j] = arr[j - 1];

            arr[pos] = value;
        }
        return;
    }

    int mid = left + (right - left) / 2;
    deqFordJohnsonRecursive(arr, left, mid);
    deqFordJohnsonRecursive(arr, mid + 1, right);
    deqMergeInsert(arr, left, mid, right);
}

void PmergeMe::deqFordJohnsonSort(std::deque<int>& arr) {
    if (arr.size() <= 1) return;
    deqFordJohnsonRecursive(arr, 0, static_cast<int>(arr.size()) - 1);
}

void PmergeMe::run(int ac, char** av) {
    _vector.clear();
    _deque.clear();

    for (int i = 1; i < ac; ++i) {
        int num = parsePositiveInt(av[i]);
        _vector.push_back(num);
        _deque.push_back(num);
    }
    if (_vector.empty())
        throw std::runtime_error("Error");

    // Print before
    std::cout << "Before:";
    for (size_t i = 0; i < _vector.size() && i < 5; ++i)
        std::cout << " " << _vector[i];
    if (_vector.size() > 5)
        std::cout << " [...]";
    std::cout << std::endl;

    // vector copy + sort
    clock_t start = clock();
    std::vector<int> vecCopy = _vector;
    vecFordJohnsonSort(vecCopy);
    clock_t end = clock();
    _vecTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000.0;

    // deque copy + sort
    start = clock();
    std::deque<int> deqCopy = _deque;
    deqFordJohnsonSort(deqCopy);
    end = clock();
    _deqTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000.0;

    // Print after
    std::cout << "After:";
    for (size_t i = 0; i < vecCopy.size() && i < 5; ++i)
        std::cout << " " << vecCopy[i];
    if (vecCopy.size() > 5)
        std::cout << " [...]";
    std::cout << std::endl;

    // Times
    std::cout << "Time to process a range of " << _vector.size()
              << " elements with std::vector : " << _vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size()
              << " elements with std::deque : " << _deqTime << " us" << std::endl;
}