//List.h


#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

template <class Element>
class Node
{
	public:
		Element* value;
		Node<Element> *next;

		Node(Element *item)
		{
			value = item;
			next = NULL;
		}
};


template <class Element>
class List;

template <class Element>
ostream& operator<<(ostream& stream, const List<Element>& l);

template <class Element>
class List
{
  public:
    List();
    List(const List<Element>& l);
    ~List();
    
    void append(Element *x);
    int index(const Element& item) const;
    void insert(int index, Element *item);
    Element* pop(int index);
    Element* get(const Element *item);
    void remove(const Element& item);
    
    bool contains(const Element& item) const;
    bool empty() const;
    int size() const;

	List<Element>& operator=(const List<Element>& l);         
    
    string toString() const;
    friend ostream& operator<< <Element>(ostream& stream, const List<Element>& l);
  
  protected:
    Node<Element> *head;
    int length;
    
    void copy(const List<Element>& l); 
		                                    
		void destroy();
  
};

class KeyError{};
class SizeError{};
class CopyError{};

#include "List.cpp"
#endif
