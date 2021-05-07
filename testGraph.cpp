#include <iostream>
#include "graph.h"
#include "./supportFiles/List.h"

using namespace std;


void testGraphConstructors();
void testGet();
void testDFS();
void testCycle();
void testPrim();
void testList();

int main(  void  )
{
  //testList();
  testGraphConstructors();
  //testGet();
  //testDFS();
  //testCycle();
  //testPrim();
  return 0;

}

void testList()
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
  
  cout << "l1 [0]: " << *l1[0] << endl;
  cout << "l1 [1]: " << *l1[1] << endl;
  cout << "l1 [2]: " << *l1[2] << endl;
  cout << "=================================================" << endl << "Copy and Deconstructor test: " << endl;
}

void testGraphConstructors()
{
    //Correct constructor test
    Graph g1("exampleGraph.txt");
    
    Graph g2(g1);
    
    Graph g3 = g1;
    
    cout << "graph g1: " << g1 << endl;
    
    cout << "graph g2: " << g2 << endl;
    
    cout << "graph g3: " << g3 << endl;
    
    //g1.~Graph();
}


void testGet()
{
    Graph g4("exampleGraph.txt");
    cout << "graph g4: " << g4 << endl;
    cout << "getWeight g4 (4,2) : " << g4.getWeight(4, 2) << endl;
    cout << "getWeight g4 (0,2) : " << g4.getWeight(0, 2) << endl;
    cout << "getWeight g4 (4,3) : " << g4.getWeight(4, 3) << endl;
    //cout << "getWeight g3 (0,0) : " << g3.getWeight(0, 0) << endl;
}

void testDFS()
{

}

void testCycle()
{

}

void testPrim()
{

}