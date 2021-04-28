//===========================================
//
//               Default Constructor
//
//============================================
template <class KeyType>
MinPriorityQueue<KeyType>::MinPriorityQueue() : MinHeap<KeyType>()
{ }

template <class KeyType>
MinPriorityQueue<KeyType>::MinPriorityQueue(int n) : MinHeap<KeyType>(n)
{ }

template <class KeyType>
MinPriorityQueue<KeyType>::MinPriorityQueue(const MinPriorityQueue<KeyType>& pq) : MinHeap<KeyType>(pq)
{ }

template <class KeyType>
MinPriorityQueue<KeyType>::MinPriorityQueue(const MinHeap<KeyType>& heap) : MinHeap<KeyType>(heap)
{ }


//===========================================
//
//               return min
//
//============================================
template <class KeyType>
KeyType* MinPriorityQueue<KeyType>::minimum() const
{
  return (A[0]);
}

//===========================================       
//                                                  
//               <<extract min                      
//                                                  
//============================================      
template <class KeyType>                                                        
KeyType* MinPriorityQueue<KeyType>::extractMin(){                               
    if (heapSize != 0)
    {
        KeyType* min = (A[0]);
        swap(0,heapSize-1);                                                         
        heapSize--;                                                                 
        heapify(0);                                                                 
        return min;                                                                 
    }
    return NULL;
                                                                                
}                                                                               
                                                                                

//===========================================       
//                                                  
//               <<decreaseKey                      
//                                                  
//============================================      
template <class KeyType>
void MinPriorityQueue<KeyType>::decreaseKey(int index, KeyType* key)
{
  //cout<<"decreaseKey ran"<<endl;
  if (heapSize <= 0){
   // cout<<"empty error"<<endl;
    throw EmptyError{};
  }
  else if (*(A[index]) < *(key)){
    throw KeyError{};
  }//

  A[index] = key;
  //cout<<"decreaseKey ran"<<endl;
  while(index>=0&& A[index] <A[parent(index)]){
    swap(index,parent(index));
    index=parent(index);
    }
  //this->buildHeap(); // we know for a fact build heap is the issue
  //cout<<"decraseKey ran"<<endl;
/*
  while (index > 0 && *(A[parent(index)]) > *A[index])
  {
    swap(index, parent(index));
    index = parent(index);
  }
  
*/

}



//===========================================                             
//                                                                        
//               <<insert                                                 
//                                                                        
//============================================                                                                                                
template <class KeyType>                                                  
void MinPriorityQueue<KeyType>::insert(KeyType* key){                     
    //cout<<"insert ran"<<endl;
   if (heapSize == capacity){                                             
       cout<<"capacity full"<<endl;
       FullError{};                                                   
       //this was going to be a way of making a new, larger array dynamically 
       /*                                                                 
       MinPriorityQueue<int> newPq(capacity*2);                           
       for (int i=0;i<heapSize;i++){                                      
            newPq.insert(A[i]);                                           
       }//end make new larger verson of pq                                
       // so how do we new change the pointer to the new array?           
       */                                                                 
    }
    //cout<<"insert ran, and key="<<*(key)<<endl;
    //cout<<"heapSize<capacity"<<endl;
    //cout << *key;
    A[heapSize] = key;  // this is the smallest value an int in c++ can hold, check mate
    heapSize++;  
    
    decreaseKey(heapSize - 1, key);                                                       
                                                                          
                                                                          
}// end of insert                                                         



//===========================================                             
//                                                                        
//               <<empty?                                               
//                                                                        
//============================================

template <class KeyType>
bool MinPriorityQueue<KeyType>::empty() const
{
  if (heapSize != 0)
    return false;
  else
    return true;
}


//===========================================    
//                                               
//               <<length                       
//                                               
//============================================   
template <class KeyType>                        
int MinPriorityQueue<KeyType>::length() const{        
    return heapSize;                            
                                                
}                                               


//===========================================
//
//               toString
//
//============================================
template <class KeyType>
std::string MinPriorityQueue<KeyType>::toString() const
{
	std::stringstream ss;
	
	if (heapSize == 0)
	{
		ss << "[ ]";
	}
	else
	{
		ss << "[";
		for (int index = 0; index < heapSize - 1; index++)
   {
			ss << *(A[index]) << ", ";
   }
		ss << *(A[heapSize - 1]) << "]";
	}
	return ss.str();
}

//===========================================
//
//               << operator
//
//============================================
template <class KeyType>
std::ostream& operator<<(std::ostream& stream, const MinPriorityQueue<KeyType>& pq)
{
	stream << pq.toString();
	
	return stream;
}

