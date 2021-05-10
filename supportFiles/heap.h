// heap.h
// a binary min heap

#ifndef HEAP_H
#define HEAP_H

#include <iostream>

const int DEFAULT_SIZE = 100;

template <class KeyType> class MinHeap;

template <class KeyType> class MinPriorityQueue;


template <class KeyType>
bool isSorted(KeyType A[],int n);
template <class KeyType>
bool isHeap( MinHeap<KeyType>& heap);



template <class KeyType>
class MinHeap
{
  public:
    MinHeap(int n = DEFAULT_SIZE);          // default constructor
    MinHeap(KeyType* initA[], int n);        // construct heap from array
    MinHeap(const MinHeap<KeyType>& heap);  // copy constructor
    ~MinHeap();                             // destructor

    //this is used to test heapify
    //MinHeap(KeyType *initA[], int n,int q);          // this constuctor is used to test the heapify and build heap functions

    void heapSort(KeyType* sorted[]);  // heapsort, return result in sorted

    MinHeap<KeyType>& operator=(const MinHeap<KeyType>& heap);  // assignment operator
    std::string toString() const;     // return string representation


  private:
    KeyType **A;     // array containing the heap is now a pointer to a pointer 
    int heapSize;   // size of the heap
    int capacity;   // size of A

    void buildHeap();                 // build heap

    void heapify(int index);          // heapify subheap rooted at index, this is temp moved into public
    int leftChild(int index) { return 2 * index + 1; }  // return index of left child
    int rightChild(int index) { return 2 * index + 2; } // return index of right child
    int parent(int index) { return (index - 1) / 2; }   // return index of parent

    void heapifyR(int index);                 // recursive heapify
    void heapifyI(int index);                 // iterative heapify
    void swap(int index1, int index2);        // swap elements in A
    void copy(const MinHeap<KeyType>& heap);  // copy heap to this heap
    void destroy();                           // deallocate heap

    friend class MinPriorityQueue<KeyType>; //this is the same formate for the isSroted and isHeap
    friend void test_baseConstructor();
    friend void test_arrayConstructor();
    friend void test_copyConstructor();
    friend void test_destructor();

    friend void test_buildHeap();
    friend void test_heapify();
    friend void test_heapifyR();
    friend void test_heapifyI();
    friend void test_swap();
    friend void test_copy();
    friend void test_equals();
    friend void test_destory();
    friend void test_heapSort();
    friend bool isSorted<KeyType>(KeyType A[],int n);
    friend bool isHeap<KeyType>( MinHeap<KeyType>& heap);

};

template <class KeyType>
std::ostream& operator<<(std::ostream& stream, const MinHeap<KeyType>& heap);

#include "heap.cpp"

#endif
