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
Element* Dict<Element>::get(const Element& k) const
{
  int x = k.hash(slots);
  return(table[x].get(&k)); 
}

template <class Element>
void Dict<Element>::insert(Element *k)
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

