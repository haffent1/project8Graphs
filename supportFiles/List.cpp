#include <sstream>

//================================================================
//
//    Constructors
//
//================================================================

//
//Default Constructor
//
template <class Element>
List<Element>::List()
{
  head = NULL;
  length = 0;
}

//
//Copy Constructor
//
template <class Element>
List<Element>::List(const List<Element>& l)
{
  this->copy(l);
}

//
//deconstructor Constructor
//
template <class Element>
List<Element>::~List()
{
  this->destroy();
}

//================================================================
//
//    Public Functions
//
//================================================================

//
//append
//
template <class Element>
void List<Element>::append(Element *x)
{
  Node<Element>* newNode = new Node<Element>(x);
  if (head == NULL)
    head = newNode;
  else
  {
    Node<Element>* ptr = head;
    Node<Element>* qtr = ptr->next;
    while (qtr != NULL)
    {
      ptr = qtr;
      qtr = qtr->next;
    }
  ptr->next = newNode;
  }
  length++;
}

//
//index
//
template <class Element>
int List<Element>::index(const Element& item) const
{
  if (head == NULL && length == 0)
    throw SizeError();
  Node<Element> *ptr = head;
  int i = 0;
  while (ptr != NULL)
  {
    if (*(ptr->value) == item)
      return i;
    ptr = ptr->next;
    i++;
  }
 throw KeyError{};
}

//
//insert
//
template <class Element>
void List<Element>::insert(int index, Element *item)
{
  if (index > length)
    throw SizeError();
  else if (index == length)
    append(item);
  else if (index == 0)
  {
    Node<Element>* newNode = new Node<Element>(item);
    newNode->next = head;
    head = newNode;
    length++;
  }
  else
  {
    Node<Element>* newNode = new Node<Element>(item);
    Node<Element>* ptr = head;
    for (int i = 0; i < index - 1; i++)
      ptr = ptr->next;
    newNode->next = ptr->next;
    ptr->next = newNode;
    length++;
  }
}

//
//pop
//
template <class Element>
Element* List<Element>::pop(int index)
{
  if (length == 0 || index > length)
    throw SizeError();
  Node<Element> *ptr = head;
  Element* x;
  if (index == 0)
  {
    x = ptr->value;
    head = head->next;
    delete ptr;
  }
  else
  {
    Node<Element> *qtr = ptr->next;
    Node<Element> *str = ptr;
    int count = 0;
    while (qtr != NULL && count < index)
    { 
      str = ptr;
      ptr = qtr;
      qtr = qtr->next;
      count++;
    } 
    x = ptr->value;
    str->next = qtr;
    delete ptr;  
  }
  length--;
  return(x);
}

//
//get
//
template <class Element>
Element* List<Element>::get(const Element *item)
//Element* List<Element>::get(Element *item)
{
  if (length == 0)
    throw SizeError();
  Node<Element> *ptr = head;
  while ((ptr != nullptr) && (*ptr->value != *item))
    ptr = ptr->next;
  if ((ptr != nullptr && *ptr->value == *item))
  {
    Element *x = ptr->value;
    return x; 
  }
  else
    throw KeyError();
}

//
//find
//
template <class Element>
Element* List<Element>::find(int index)
{
  if ((index < 0) || index >= length)
    throw KeyError();
  
  Node<Element> *ptr = head;
  for (int i = 0; i < index; i++)
    ptr = ptr->next;
  return(ptr->value);
}

//
//remove
//
template <class Element>
void List<Element>::remove(const Element& item)
{
  if (length == 0)
    throw SizeError();
  Node<Element> *ptr = head;
  if (item == *ptr->value)
  {
    head = ptr->next;
    delete ptr;
    length--;
  }
  else
  {
    Node<Element> *qtr = ptr->next;
    Node<Element> *str = ptr;
    while (qtr != NULL && *ptr->value != item)
    {
      str = ptr;
      ptr = qtr;
      qtr = qtr->next;
    }
    if (*ptr->value == item)
    {
      str->next = qtr;
      delete ptr;
      length--;
    }
    else
      throw KeyError();
  }
}

//
//contains
//
template <class Element>
bool List<Element>::contains(const Element& item) const
{
  if (length == 0)
    return false;
  Node<Element> *ptr = head;
  while ((ptr != nullptr) && (*ptr->value != item))
    ptr = ptr->next;
  if ((ptr != nullptr && *ptr->value == item))
    return true;
  else
    return false;
}

//
//empty
//
template <class Element>
bool List<Element>::empty() const
{
  return (length == 0);
}

//
//size
//
template <class Element>
int List<Element>::size() const
{
  return length;
}

//================================================================
//
//    Operators
//
//================================================================

//
//Assignment operator
//
template <class Element>
List<Element>& List<Element>::operator=(const List<Element>& l)
{
  if (this != &l)
  {
    this->destroy();
    this->copy(l);
    return *this;
  }
  else
    throw CopyError();
}

//
//[] operator
//
template <class Element>
Element* List<Element>::operator[](int index) const
{
  if ((index < 0) || index >= length)
    throw KeyError();
  
  Node<Element> *ptr = head;
  int count = 0;
  while (ptr != NULL && count < index){
    ptr = ptr->next;
    count++;
  }
  return(ptr->value);
  
}

//
//toSting
//
template <class Element>
string List<Element>::toString() const
{
  stringstream s;
  if (length == 0)
  {
    s << "[]";
  }
  else
  {
    s << "[";
    Node<Element> *ptr = head;
    while (ptr->next != nullptr)
    {
      s << *(ptr->value) << ", ";
      ptr = ptr->next;
    }
    s << *(ptr->value) << "] ";
  }
  return s.str();
}

//
//<< operator
//
template <class Element>
ostream& operator<<(ostream& stream, const List<Element>& l)
{
  stream << l.toString();
  return stream;
}

//================================================================
//
//    Private Functions
//
//================================================================

//
//copy
//
template <class Element>
void List<Element>::copy(const List<Element>& l)
{
  if (l.head == NULL)
    head = NULL;
  else
  {
    Node<Element>* newNode = new Node<Element>(l.head->value);
    head = newNode;
    Node<Element>* ptr = head;
    Node<Element>* sptr = l.head->next;
    while (sptr)
    {
      Node<Element>* newNode = new Node<Element>(sptr->value);
      length++;
      ptr->next = newNode;
      sptr = sptr->next;
      ptr = ptr->next;
    }
    ptr->next = NULL;
  }
  length = l.length;
}

//
//destroy
//
template <class Element>
void List<Element>::destroy()
{
  Node<Element> *ptr = head;
  Node<Element> *qtr;
  while (ptr != NULL)
  {
    qtr = ptr->next;
    delete ptr;
    ptr = qtr;
  }
  head = NULL;
  length = 0;
}
