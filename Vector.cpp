


#include "AirQuality.h"
#include "Vector.h"

const int ZERO = 0;
const int ONE = 1;
const int TWO = 2;




template <typename T>
Vector<T>::Vector() : data(nullptr), size(ZERO), capacity(ZERO) {}

template <typename T>
void Vector<T>::push_back(const T& value) {
    if (size == capacity) {
        resize();
    }
    data[size++] = value;
}

template <typename T>
T& Vector<T>::at(size_t index) {
    if (index < size) {
        return data[index];
    } else {
        throw std::out_of_range("Index out of range");
    }
}

template <typename T>
size_t Vector<T>::getSize() const {
    return size;
}

template <typename T>
void Vector<T>::resize() {
    capacity = (capacity == ZERO) ? ONE : capacity * TWO;
    T* newData = new T[capacity];

    simpleCopy(data, newData, size);

    delete[] data;
    data = newData;
}

template <typename T>
void Vector<T>::simpleCopy(const T* source, T* destination, size_t count) {
    for (size_t i = ZERO; i < count; ++i) {
        destination[i] = source[i];
    }
}

template <typename T>
T* Vector<T>::begin() const {
    return data;
}

template <typename T>
T* Vector<T>::end() const {
    return data + size;
}

template <typename T>
T& Vector<T>::operator[](std::size_t index) {
    if (index < size) {
        return data[index];
    } else {
        throw std::out_of_range("Index out of range");
    }
}

template <typename T>
const T& Vector<T>::operator[](std::size_t index) const {
    if (index < size) {
        return data[index];
    } else {
        throw std::out_of_range("Index out of range");
    }
}
template <typename T>
void Vector<T>::pop_back() {
    if (size > ZERO) {
        --size;
    } else {
        throw std::out_of_range("Vector is empty, cannot pop_back()");
    }
}

template <typename T>
T& Vector<T>::back() {
    if (size > ZERO) {
        return data[size -ONE];
    } else {
        throw std::out_of_range("Vector is empty, cannot access back()");
    }
}


template <typename T>
const T& Vector<T>::back() const {
    if (size > ZERO) {
        return data[size - ONE];
    } else {
        throw std::out_of_range("Vector is empty, cannot access back()");
    }
}
template <typename T>
bool Vector<T>::empty() const {
    return size == ZERO;
}

template class Vector<int>;
template class Vector<AirQuality>;
template class Vector<pair<double, AirQuality>>;


