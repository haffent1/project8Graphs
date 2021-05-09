#include <iostream>

#include "List.h"


using namespace std;

void testAppend(List<int> l1)
{
}

int main ()
{
  List<int> l1;
  
  cout << "================================================="<< endl << "Default and Append test:" << endl;
  
  cout << "l1 empty: " << l1.empty() << endl;
  int test1= 10;
  int *value1= &test1;
  l1.append(value1);
  
  int test2 = 5;
  value1 = &test2;
  l1.append(value1);

  int test3 = 20;
  value1 = &test3;
  l1.append(value1);
  
  cout << l1 << endl;
  
  cout << "l1 empty: " << l1.empty() << endl;
  cout << "l1 size: " << l1.size() << endl;

  cout << "=================================================" << endl << "Copy and Deconstructor test: " << endl;

  List<int> l2(l1);
  cout << l2 << endl;
  
  int test4 = 11;
  value1 = &test4;
  l1.append(value1);
  
  int test5 = 3;
  value1 = &test5;
  l2.append(value1);
  
  cout << "l1: " << l1 << endl;
  cout << "l2: " << l2 << endl;
  
  l2.~List();
  cout << "l2: " << l2 << endl;
  
  cout << "================================================="<< endl << "Index test:" << endl;
  
  cout << "l1 (5) index: " << l1.index(5) << endl;
  cout << "l1 (11) index: " << l1.index(11) << endl;
  cout << "l1 (20) index: " << l1.index(20) << endl;
  cout << "l1 (10) index: " << l1.index(10) << endl;
  
  //cout << "l1 (27) index: " << l1.index(27) << endl;*/
  
  cout << "=================================================" << endl << "Insert test:" << endl;
  
  value1 = &test5;
  l2.insert(0, value1);
  
  //cout << *l2.pop(0) << endl;
  
  //cout << l2.size() << endl;
  int test6 = 7;
  value1 = &test6;
  l2.insert(1, value1);
  
  value1 = &test4;
  l2.insert(2, value1);
  
  cout << l2.size() << endl;
  value1 = &test3;
  l2.insert(0, value1);
  
  cout << l2 << endl;
  List<int> l3 = l2;
  List<int> l4 = l3;
  
  cout << "=================================================" << endl << "Pop test:" << endl;
  
  cout << "Pop (3): " << *l2.find(3) << endl;
  cout << "Pop (2): " << *l2.find(2) << endl;
  cout << "Pop (1): " << *l2.find(1) << endl;
  cout << "Pop (0): " << *l2.find(0) << endl;
  
  cout << l2 << endl;
  
  cout << "=================================================" << endl << "Remove test:" << endl;
  
  cout << l3 << endl;
  //l3.remove(15);
  //cout << "Remove (15): " << l3 << endl;
  l3.remove(11);
  cout << "Remove (11): " << l3 << endl;
  l3.remove(3);
  cout << "Remove (3): " << l3 << endl;
  l3.remove(7);
  cout << "Remove (7): " << l3 << endl;
  l3.remove(20);
  cout << "Remove (20): " << l3 << endl;
  cout << l3 << endl;
  
  cout << "=================================================" << endl << "Contains & get test:" << endl;
  
  cout << l4 << endl;
  cout << "Contains (3): " << l4.contains(3) << endl;
  cout << "Contains (2): " << l4.contains(20) << endl;
  cout << "Contains (10): " << l4.contains(10) << endl;
  cout << "Contains (0): " << l4.contains(0) << endl;
  
  int test10 = 3;
  value1 = &test10;
  cout << "get (3): " << *l4.get(value1) << endl;
  //cout << "get (2): " << l4.get(20) << endl;
  
  return 0;
}