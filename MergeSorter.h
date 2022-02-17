//
// Created by Mackem Meya on 08.02.2022.
//

#ifndef MERGESORTER_H
#define MERGESORTER_H

#include <iostream>

#include "Array.h"
#include "Exceptions/MemoryNotAllocatedException.h"

template<typename T>
class MergeSorter {
private:
    void merge(T *array, size_t size, std::function<bool(T, T)> isCorrectOrder);

public:
    void sort(T *array, size_t size, std::function<bool(T, T)> isCorrectOrder);
};

template<typename T>
void MergeSorter<T>::merge(T *array, size_t size, std::function<bool(T, T)> isCorrectOrder) {
    size_t leftArraySize{ size / 2 };
    size_t rightArraySize{ size - leftArraySize };

    T *arrayCopy{ new T[size] };
    if (arrayCopy == nullptr) {
        throw MemoryNotAllocatedException{ "Failed to allocate memory during merge" };
    }

    for (size_t i{ 0 }; i < size; ++i) {
        arrayCopy[i] = array[i];
    }

    size_t leftArrayIndex{ 0 };
    size_t rightArrayIndex{ 0 };
    size_t mainArrayIndex{ 0 };

    while (leftArrayIndex < leftArraySize && rightArrayIndex < rightArraySize) {
        if (isCorrectOrder(arrayCopy[leftArrayIndex], arrayCopy[leftArraySize + rightArrayIndex])) {
            array[mainArrayIndex] = arrayCopy[leftArrayIndex];
            ++leftArrayIndex;
        } else {
            array[mainArrayIndex] = arrayCopy[leftArraySize + rightArrayIndex];
            ++rightArrayIndex;
        }
        ++mainArrayIndex;
    }

    while (leftArrayIndex < leftArraySize) {
        array[mainArrayIndex] = arrayCopy[leftArrayIndex];
        ++leftArrayIndex;
        ++mainArrayIndex;
    }

    while (rightArrayIndex < rightArraySize) {
        array[mainArrayIndex] = arrayCopy[leftArraySize + rightArrayIndex];
        ++rightArrayIndex;
        ++mainArrayIndex;
    }

    delete[] arrayCopy;
}

template<typename T>
void MergeSorter<T>::sort(T *array, size_t size, std::function<bool(T, T)> isCorrectOrder) {
    if (size == 0 || size == 1) {
        return;
    }

    size_t halfSize{ size / 2 };

    sort(array, halfSize, isCorrectOrder);
    sort(array + halfSize, size - halfSize, isCorrectOrder);
    merge(array, size, isCorrectOrder);
}

#endif //MERGESORTER_H
