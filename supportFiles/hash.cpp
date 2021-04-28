#include <iostream>
#include <sstream>

//
//Default Constructor
//
template <class Element>
HashTable<Element>::HashTable(int numSlots)
{
  //This function takes in an int that determins the size of the array that will be used as the has table
  //
  table = new List<Element>[numSlots];
  slots = numSlots;
}

//
//Copy Constructor
//
template <class Element>
HashTable<Element>::HashTable(const HashTable<Element>& h)
{
  this->copy(h);
}

//
//Deconstructor
//
template <class Element>
HashTable<Element>::~HashTable()
{
  this->destroy();
}

//
//get
//
template <class Element>
Element* HashTable<Element>::get(const Element& k) const
{
  int x = k.hash(slots);
  return(table[x].get(&k));
}

//
//insert 
//
template <class Element>
void HashTable<Element>::insert(Element *k)
{
  int x = k->hash(slots);
  table[x].insert(0, k);
}

//
//remove 
//
template <class Element>
void HashTable<Element>::remove(const Element& k)
{

  int x = k.hash(slots);
  table[x].remove(k);
}

//
//Assignment Operator 
//
template <class Element>
HashTable<Element>& HashTable<Element>::operator=(const HashTable<Element>& h)
{
  if (this != &h)
  {
    this->destroy();
    this->copy(h);
    return *this;
  }
  else
    throw CopyError{};
  
}

//
//toString 
//
template <class Element>
string HashTable<Element>::toString(int slot) const
{
  stringstream s;
  s << table[slot];
  return s.str();
}

//
//copy 
//
template <class Element>
void HashTable<Element>::copy(const HashTable<Element>& h)
{
  table = new List<Element>[h.slots];   
  slots = h.slots; 
  for (int i = 0 ; i < h.slots; i++)
  {
    table[i] = h.table[i];
  }
}

template <class Element>
void HashTable<Element>::distro(){
    for(int i = 0; i < slots; i++){
        cout<<table[i].size()<<endl;
        
    }
}// end of distro



//
//destroy 
//
template <class Element>
void HashTable<Element>::destroy()
{
  for (int i = 0; i < slots; i ++)
  {
    table[i].~List(); 
  }
  delete [] this->table;
}

//
//<< overload 
//
template <class Element>
ostream& operator<<(ostream& stream, const HashTable<Element>& h)
{
  if(h.slots == 0)
  {
    stream<<"[]";
    return stream;
  }
  else
  {
   stream << "[";
   for (int i = 0; i < h.slots - 1; i++)
   {
     stream << h.toString(i) << ", ";
   }
   stream << h.toString(h.slots - 1) << "]";
   return stream; 
  }
}
