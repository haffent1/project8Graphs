#include <iostream>
#include "graph.h"

using namespace std;


void testGraphConstructor();
void testGraphCopy();

int main(  void  )
{
    
  testGraphConstructor();
  return 0;

}


void testGraphConstructor()
{
    Graph g1("exampleGraph.txt");
    Graph g2(g1);
    
    g2 = g1;
    
    cout << g1 << endl;
    
    cout << g2 << endl;
    
    g1.~Graph();
    
}


void testGraphCopy(){
}

