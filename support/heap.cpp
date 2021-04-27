// heap.cpp
#include <cassert>
#include <sstream>
//#include "heap.h"
using namespace std;

// Implement heap methods here.

// Use the following toString() for testing purposes.



//do I need the template?
template <class KeyType>
MinHeap<KeyType>::MinHeap(int n) //default constructor             
{                                                     
    /* this functions pre conditions are: a size that the heap will be.
     *
     * this functions post conditions are:  this function will return an instance of class heap of input size n with all values being 0
     *
     */
     A= new KeyType*[n]; //
     heapSize=0;
     capacity=n;
     //buildHeap();
    
    
}//MinHeap                                                     

template <class KeyType>
MinHeap<KeyType>::MinHeap(KeyType* initA[], int n){        // construct heap from array      
    /* this functions pre conditions are: a populated array of size n and the input size n
     *
     * this functions post conditions are: a instance of a class heap containing the same values as the input array.
     *
     */
    heapSize=0;
    capacity=n;
    A= new KeyType*[n];    
    for (int i = 0; i < n; i++)
    {
      (A[i]) = &initA[i]; // I derefrenced A as it was throwing an error when I did not 
         
    }//end of for loop
    buildHeap();
}//end of MinHeap from array



template <class KeyType>
MinHeap<KeyType>::MinHeap(const MinHeap<KeyType>& heap){  // copy constructor               
    /* this functions pre conditions are: an instance of a class heap
     *
     * this functions post conditions are:  an instance of a copy of the input instance of class heap
     *
     */
    //dont need to call heapSort on this?
    copy(heap); //changed per comment from this->copy(heap)
}//end of MinHeap copy





template <class KeyType>
MinHeap<KeyType>::~MinHeap(){                             // destructor                     
    /* this functions pre conditions are: an instance of a class heap
     *
     * this functions post conditions are:  ? nothing
     *
     */

     destroy(); //changed from this->destroy()
}//end of destructor
/*
template <class KeyType>// this is used to  test the build heap and heapify function, this is just the array construct but it dose not call heapify by defalut 
MinHeap<KeyType>::MinHeap(KeyType initA[], int n,int q){
    heapSize=n;
    capacity=n;
    A= new KeyType*[n];    
    for (int i=0;i<heapSize;i++){
        A[i]=initA[i];
         
    }//end of for loop
    
}// end of MinNonHeap

*/
template <class KeyType>
void MinHeap<KeyType>::heapSort(KeyType *sorted[]){ // this function is acessing information that it should not, figure out why.
    /* this functions pre conditions are: an instance of a class heap for this to be called as a method and an 
     * array that has been alocated at least the same size as the heap that is to be sorted
     *
     * this functions post conditions are:  an array sorted in assenting order containing the same values of the heap used as an input
     *
     */
   //this->buildHeap(); //this is prob a redundent call but it cant hurt
   for (int i=heapSize-1,j=0; i>=0 ; i--,j++){
    sorted[j]=A[0];
    //cout<<"A[i] is equal to"<<A[i]<<endl;
    //cout<<"A[0] is equal to"<<A[0]<<endl;
    //cout<<toString()<<endl;
    swap(0,i);
    heapSize--;
    this->heapify(0);
    }
}//end of heapsort


template <class KeyType>
void MinHeap<KeyType>::heapify(int index){        // heapify subheap rooted at index
    /* this functions pre conditions are: an index of a node of which the trees of the children already forfill the min heap property
     *
     * this functions post conditions are:  the node at index i will forfill the heap property  after the function call.
     *
     */
    //cout<<"heapify has been called"<<endl;
    int smallest; //this will hold the index of the smallest value 
    int left=leftChild(index);
    int right=rightChild(index);
   //it is < heapsize because this is zero based indexing 

    if (left < heapSize && *(A[left]) < *(A[index])){                                        
        smallest = left;                                                        
    }//end of if  
    
    else{                                                                    
            smallest = index;                                                       
    }//end of else  
    
    if (right < heapSize &&  *(A[right]) < *(A[smallest])){                          
            smallest=rightChild(index);                                                     
    }//end of if 
    
    if( smallest != index){                                                       
            swap(index,smallest);                  //(this whole section is 2n/3)?    
    heapify(smallest);                                                   
    }//end of if 

   
}//end of hepify



template <class KeyType>
void MinHeap<KeyType>::buildHeap(){                 // build heap
    /* this functions pre conditions are:
     *
     * this functions post conditions are: 
     *
     */
   heapSize=capacity; //added in per comment
   for (int i = heapSize/2-1 ; i >= 0;i--){
      heapify(i); //removed this->
      //cout<<"buildheap ran"<<endl;
   }
}//end of buildHeap



template <class KeyType>
void MinHeap<KeyType>::heapifyR(int index){                 // recursive heapify              

    /* this functions pre conditions are: an index of a node of which the trees of the children already forfill the min heap property.
     *
     * this functions post conditions are:  the node at index i will forfill the heap property  after the function call.
     *
     */
    this->heapify(); //the heapify function is alreayd recursive
}//end of hepifyR



template <class KeyType>
void MinHeap<KeyType>::heapifyI(int index){                 // iterative heapify // untested
    /* this functions pre conditions are: an index of a node of which the trees of the children already forfill the min heap property
     *
     * this functions post conditions are:  the node at index i will forfill the heap property  after the function call.
     *
     */
    int smallest=-1; //this will hold the index of the smallest value, and added -1 as per comment
    while(smallest != index){ // changed from index < heapSize/2-1
    
        if (leftChild(index) <= heapSize && A[leftChild(index)] < A[index]){                                        
            smallest = leftChild(index);                                                        
        }//end of if  
        
        else{                                                                    
                smallest = index;                                                       
        }//end of else  
        
        if (rightChild(index) <= heapSize &&  A[rightChild(index)] < A[smallest]){                          
                smallest=rightChild(index);                                                     
        }//end of if 
        
        if( smallest != index){                                                       
                swap(index,smallest);                  //(this whole section is 2n/3)?    
        index=smallest;                                                   
        }//end of if 
    }//end of while loop
}//end of iterative heapify



template <class KeyType>
void MinHeap<KeyType>::swap(int index1, int index2){        // swap elements in A             
    /* this functions pre conditions are: an instance of a heap
     *
     * this functions post conditions are:  the same instance of a heap, but the value that was stored at index1 is swaped with the value that was stored at index2
     *
     */
    KeyType* swap=A[index1];
    A[index1]=A[index2];
    A[index2]=swap;
}//end of swap elements 



template <class KeyType>
void MinHeap<KeyType>::copy(const MinHeap<KeyType>& heap){  // copy heap to this heap         
    /* this functions pre conditions are:
     *
     * this functions post conditions are: 
     *
     */
    heapSize=heap.heapSize;
    capacity=heap.capacity;
    A=new KeyType*[capacity];
    for (int i=0; i<capacity; i++){ //changed to capacity from heapSize
        A[i] = heap.A[i];
    }//end of for loop

}//end of copy

template <class KeyType>
void MinHeap<KeyType>::destroy(){                           // deallocate heap                
    /* this functions pre conditions are:
     *
     * this functions post conditions are: 
     *
     */
    if (capacity != 0){
    heapSize=0;
    capacity=0;
    }
    delete [] this->A; //we need the [] because because if we dont we will just remove the pointer
}//end of destroy






template <class KeyType>
 MinHeap<KeyType>& MinHeap<KeyType>::operator=(const MinHeap<KeyType>& heap){
    //make sure that we are not asigning a heap to itself (make sure not equal to &heap)
    destroy(); //we need to destory so we dont have a memory leak
    copy(heap);  //copy is returning

}




template <class KeyType>
std::string MinHeap<KeyType>::toString() const
{
        std::stringstream ss;

        if (capacity == 0)
                ss << "[ ]";
        else
        {
                ss << "[";
                if (heapSize > 0)
                {
                        for (int index = 0; index < heapSize - 1; index++)
                                ss << *(A[index]) << ", ";
                        ss << *(A[heapSize - 1]);
                }
                ss << " | ";
                if (capacity > heapSize)
                {
                        for (int index = heapSize; index < capacity - 1; index++)
                                ss << *(A[index]) << ", ";
                        ss << *(A[capacity - 1]);
                }
                ss << "]";
        }
        return ss.str();
}

template <class KeyType>
std::ostream& operator<<(std::ostream& stream, const MinHeap<KeyType>& heap)
{
        return stream << heap.toString();
}

