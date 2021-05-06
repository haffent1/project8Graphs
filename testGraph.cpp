#include <iostream>
#include "graph.h"

using namespace std;


void testGraphConstructors();
void testGet();
void testDFS();
void testCycle();
void testPrim();

int main(  void  )
{
    
  testGraphConstructors();
  testGet();
  testDFS();
  testCycle();
  testPrim();
  return 0;

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