//
// Created by Mackem Meya on 16.02.2022.
//

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

#include "Exceptions/MemoryNotAllocatedException.h"
#include "Exceptions/InvalidArgumentException.h"

template<typename T>
class Array {
private:
    T *m_data;
    size_t m_size{ };

public:
    Array() = default;

    explicit Array(size_t size, T initialValue) : m_size{ size }, m_data{ new T[size] } {
        if (m_data == nullptr) {
            throw MemoryNotAllocatedException{ "Failed to allocate memory for Array" };
        }

        fill(initialValue);
    }

    Array(T *data, size_t size) : m_data{ new T[size] }, m_size{ size } {
        if (m_data == nullptr) {
            throw MemoryNotAllocatedException{ "Failed to allocate memory for Array" };
        }

        for (size_t i{ 0 }; i < size; ++i) {
            (*this)(i) = data[i];
        }
    }

    Array(const Array &other) : m_size{ other.m_size }, m_data{ new T[other.m_size] } {
        if (m_data == nullptr) {
            throw MemoryNotAllocatedException{ "Failed to allocate memory for Array" };
        }

        for (size_t i{ 0 }; i < m_size; ++i) {
            (*this)(i) = other(i);
        }
    }

    Array(Array &&other) noexcept: m_size{ other.m_size }, m_data{ other.m_data } {
        other.m_size = 0;
        other.m_data = nullptr;
    }

    ~Array() {
        delete[] m_data;
    }

    size_t getSize() const;

    void print() const;

    void fill(T value);

    T &operator()(size_t index);

    const T &operator()(size_t index) const;

    T *operator*();

    Array<T> &operator=(const Array<T> &other);

    Array<T> &operator=(Array<T> &&x) noexcept;

    template<typename t>
    friend std::ostream &operator<<(std::ostream &out, const Array<t> &array);

};

template<typename T>
size_t Array<T>::getSize() const {
    return m_size;
}

template<typename T>
void Array<T>::print() const {
    std::cout << *this << std::endl;
}

template<typename T>
void Array<T>::fill(T value) {
    for (size_t i{ 0 }; i < m_size; ++i) {
        (*this)(i) = value;
    }
}

template<typename T>
T &Array<T>::operator()(size_t index) {
    if (index >= m_size) {
        throw InvalidArgumentException{ "Invalid index. The value must be between 0 and (size - 1)" };
    }

    return m_data[index];
}

template<typename T>
const T &Array<T>::operator()(size_t index) const {
    if (index >= m_size) {
        throw InvalidArgumentException{ "Invalid index. The value must be between 0 and (size - 1)" };
    }

    return m_data[index];
}

template<typename T>
T *Array<T>::operator*() {
    return m_data;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &other) {
    if (this == &other) {
        return *this;
    }

    if (m_size != other.m_size) {
        delete[] m_data;
        m_size = other.m_size;
        m_data = new T[m_size];

        if (m_data == nullptr) {
            throw MemoryNotAllocatedException{ "Failed to allocate memory for Array" };
        }

    }

    for (size_t i{ 0 }; i < m_size; ++i) {
        (*this)(i) = other(i);
    }

    return *this;
}

template<typename T>
Array<T> &Array<T>::operator=(Array<T> &&other) noexcept {
    if (&other == this) {
        return *this;
    }

    delete[] m_data;

    m_size = other.m_size;
    m_data = other.m_data;
    other.m_size = 0;
    other.m_data = nullptr;

    return *this;
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &array) {
    out << "( ";
    for (size_t i{ 0 }; i < array.m_size; ++i) {
        out << array(i) << " ";
    }
    out << ")[" << array.m_size << "]";
    return out;
}

#endif //ARRAY_H
