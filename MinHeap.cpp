#include "MinHeap.h"
#include <string>

using namespace std;
const int ZERO = 0;
const int FIRST_INDEX = 0;
const int INT_ONE = 1;
const int INT_TWO = 2;
const int EMPTY_VALUE =200;



// Constructor
MinHeap::MinHeap() {
}

double MinHeap::averageFirstElements() const {
    if (isEmpty()) {
        throw out_of_range("Heap is empty");
    }

    double sum = 0.0;
    int count = 0; // Counter for valid elements

    for (const auto& element : heapArray) {
        if (element.first != EMPTY_VALUE) { // Check if the element is not -200
            sum += element.first; // Sum the value if it's valid
            count++; // Increment count for valid elements
        }
    }

    if (count == 0) {
        // Handle case when all elements are -200 or heap is empty
        throw out_of_range("No valid data to calculate average");
    }

    return sum / count; // Calculate the average based on valid elements
}



// Insert operation
void MinHeap::insert(double key, AirQuality& value) {
    // Insert the new element at the end of the heap
    heapArray.push_back(make_pair(key, value));

    // Maintain the heap property by performing heapifyUp operation
    heapifyUp(heapArray.getSize() - INT_ONE);
}

// Pop the top element from the heap
void MinHeap::pop() {
    if (isEmpty()) {
        throw out_of_range("Heap is empty");
    }

    // Swap the top element with the last element
    swap(heapArray[FIRST_INDEX], heapArray.back());

    // Remove the last element
    heapArray.pop_back();

    // Maintain the heap property by performing heapifyDown operation
    heapifyDown(FIRST_INDEX);
}

// Get the top element of the heap
pair<double, AirQuality> MinHeap::top() {
    if (isEmpty()) {
        throw out_of_range("Heap is empty");
    }
    return heapArray[FIRST_INDEX];
}

// Check if the heap is empty
bool MinHeap::isEmpty() const {
    return heapArray.getSize() == ZERO;

}

// Maintain the min-heap property by comparing and swapping elements upwards
void MinHeap::heapifyUp(int index) {
    while (index > FIRST_INDEX && heapArray[index].first < heapArray[(index - INT_ONE) / INT_TWO].first) {
        swap(heapArray[index], heapArray[(index - INT_ONE) / INT_TWO]);
        index = (index - INT_ONE) / INT_TWO;
    }
}

// Maintain the min-heap property by comparing and swapping elements downwards
void MinHeap::heapifyDown(int index) {
    int smallest = index;
    int leftChild = INT_TWO * index + INT_ONE;
    int rightChild = INT_TWO * index + INT_TWO;

    // Check the left child
    if (leftChild < heapArray.getSize() && heapArray[leftChild].first < heapArray[smallest].first) {
        smallest = leftChild;
    }

    // Check the right child
    if (rightChild < heapArray.getSize()  && heapArray[rightChild].first < heapArray[smallest].first) {
        smallest = rightChild;
    }

    // If the smallest value is not the current node, swap and recursively call heapifyDown
    if (smallest != index) {
        swap(heapArray[index], heapArray[smallest]);
        heapifyDown(smallest);
    }
}


