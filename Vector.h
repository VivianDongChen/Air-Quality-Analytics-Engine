
#ifndef FINALPROJECT_VECTOR_H
#define FINALPROJECT_VECTOR_H
#include <stdexcept>

/**
 * @brief A dynamic array implementation similar to C++ std::vector.
 * @tparam T Type of elements stored in the vector.
 */
template <typename T>
class Vector {

public:
    /**
     * @brief Default constructor.
     */
    Vector();
    /**
        * @brief Adds an element to the end of the vector.
        * @param value The value to be added.
        */
    void push_back(const T& value);
    /**
    * @brief Access element at the specified index with bounds checking.
    * @param index Index of the element to access.
    * @return Reference to the element at the specified index.
    * @throws std::out_of_range if the index is out of bounds.
    */
    T& at(size_t index);
    /**
        * @brief Returns the current size of the vector.
        * @return The number of elements in the vector.
        */
    size_t getSize() const;
/**
     * @brief Returns a pointer to the first element.
     * @return Pointer to the first element.
     */
    T* begin() const ;
    /**
     * @brief Returns a pointer to the past-the-end element.
     * @return Pointer to the past-the-end element.
     */
    T* end() const ;
    /**
     * @brief Overloaded subscript operator for element access.
     * @param index Index of the element to access.
     * @return Reference to the element at the specified index.
     */
    T& operator[](std::size_t index);
    /**
     * @brief Overloaded subscript operator for element access (const version).
     * @param index Index of the element to access.
     * @return Const reference to the element at the specified index.
     */
    const T& operator[](std::size_t index) const;
    /**
    * @brief Removes the last element.
    * @throws std::out_of_range if the vector is empty.
    */
    void pop_back();
    /**
    * @brief Access the last element.
    * @return Reference to the last element.
    * @throws std::out_of_range if the vector is empty.
    */
    T& back();
    /**
    * @brief Access the last element (const version).
    * @return Const reference to the last element.
    * @throws std::out_of_range if the vector is empty.
    */
    const T& back() const;
    /**
    * @brief Checks if the vector is empty.
    * @return True if the vector is empty, false otherwise.
    */
    bool empty() const;

private:
    T* data;
    size_t capacity;
    size_t size;
    /**
   * @brief Resize the allocated array if necessary.
   */
    void resize();

    /**
     * @brief Copy elements from source to destination.
     * @param source Pointer to the source array.
     * @param destination Pointer to the destination array.
     * @param count Number of elements to copy.
     */
    void simpleCopy(const T* source, T* destination, size_t count);
};


#endif //FINALPROJECT_VECTOR_H
