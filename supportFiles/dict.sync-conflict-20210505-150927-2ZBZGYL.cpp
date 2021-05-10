#include <sstream>

using namespace std;

template <class Element>
Dict<Element>::Dict(int numSlots) : HashTable<Element>(numSlots) 
{ }

template<class Element>
Dict<Element>::Dict(const Dict<Element>& d) : HashTable<Element>(d)
{ }

//template<class Element>
//Dict<Element>::~Dict() : ~HashTable<Element>()
//{ }
//template<class Element>
//void :: Dict() : HashTable<Element>::distro(){}







template <class Element>
Element* Dict<Element>::get(int head, int tail) const
{
    int sumOfKeys = head + tail;
    Element temp = new Element(sumOfKeys);

  int x = temp.hash(size);
  return(table[x].get(&k)); 
}


template <class Element>
void Dict<Element>::insert(int head, int tail, Element *k)
{
  int x = k->hash(slots);
  if (!table[x].contains(*k))
    table[x].insert(0, k);
}

template <class Element>
void Dict<Element>::remove(const Element& k)
{
  int x = k.hash(slots);
  table[x].remove(k);
}

