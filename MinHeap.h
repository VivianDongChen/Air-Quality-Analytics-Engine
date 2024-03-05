#ifndef MINHEAP_H
#define MINHEAP_H
//#include <vector>
#include "Vector.h"

#include "AirQuality.h"
using namespace std;
/**
 * @class MinHeap
 * @brief Represents a min-heap data structure with elements containing a double key and an AirQuality value.
 */
class MinHeap {
public:
    /**
  * @brief Default constructor for MinHeap.
  */
    MinHeap();
    /**
    * @brief Computes the average of the first elements in the heap.
    * @return The average of the first elements.
    */
    double averageFirstElements() const;
    /**
 * @brief Inserts a key-value pair into the min-heap.
 * @param key The key to insert.
 * @param value The AirQuality value to insert.
 */
    void insert(double key, AirQuality& value);
    /**
    * @brief Removes the top element from the min-heap.
    */
    void pop();
    /**
    * @brief Returns the top element of the min-heap.
    * @return The top element as a pair of key and AirQuality value.
    */
    pair<double, AirQuality> top();
    /**
    * @brief Checks if the min-heap is empty.
    * @return True if the min-heap is empty, false otherwise.
    */
    bool isEmpty() const;

private:
    Vector<pair<double, AirQuality>> heapArray;
    /**
     * @brief Restores the min-heap property by moving an element up in the heap.
     * @param index The index of the element to heapify up.
     */
    void heapifyUp(int index);
    /**
     * @brief Restores the min-heap property by moving an element down in the heap.
     * @param index The index of the element to heapify down.
     */
    void heapifyDown(int index);

};

#endif // MINHEAP_H
