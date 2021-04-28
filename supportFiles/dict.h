#ifndef DICT_H
#define DICT_H

#include <iostream>
#include "hash.h"
#include "List.h"

template <class Element>
class Dict : public HashTable<Element>

{
  public:  
    Dict(int numSlots);        //Default Constructor
    Dict(const Dict<Element>& d);      //Copy Constructor 
    //~Dict();        //destructor
    
    Element* get(const Element& k) const;
    void insert(Element *k);
    void remove(const Element& k);

    //using HashTable<Element>::~HashTable() //our understanding is that the destructor

    //using HashTable<Element>::distro;

    using HashTable<Element>::table;
    using HashTable<Element>::slots;
  
};

#include "dict.cpp"

#endif
