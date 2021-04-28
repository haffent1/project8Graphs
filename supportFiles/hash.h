#ifndef HASH_H
#define HASH_H

#include "List.h"

#include <iostream>
using namespace std;

template <class Element>
class HashTable;

template <class Element>
ostream& operator<<(ostream& stream, const HashTable<Element>& h);

template <class Element>
class HashTable  
{
  public:
    HashTable(int numSlots);
    HashTable(const HashTable<Element>& h);
    ~HashTable();
    
    Element* get(const Element& k) const;
    void insert(Element *k);
    void remove(const Element& k);
    
    HashTable<Element>& operator=(const HashTable<Element>& h);
    
    std::string toString(int slot) const;
    friend ostream& operator<< <Element>(ostream& stream, const HashTable<Element>& h);

    void distro(); //this function prints out the number of values in each linked list 
    
  protected:
    int slots;
    List<Element> *table;
    
    void copy(const HashTable<Element>& h);
    void destroy();
    
};

#include "hash.cpp"

#endif
