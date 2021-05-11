#include <iostream>
#include "graph.h"
#include "./supportFiles/List.h"

using namespace std;

void testGraphConstructors();
void testGetWeight();
void testDFS();
void testCycle();
void testPrim();

int main(void)
{
  testGraphConstructors();
  testGetWeight();
  testDFS();
  //testCycle();
  //testPrim();
  return 0;

}

void testGraphConstructors()
{
    //also test reading in a wrong file name
    //also test reading in a larger graph
    //also test reading in a graph with double digit weights
    cout<<"test base constructor"<<endl;
    //Correct constructor test
    Graph g1("exampleGraph.txt");
    cout << "graph g1: " << g1 << endl;
    
    cout<<"test base constructor for multi digit"<<endl;
    Graph gMultiDigit("exampleGraph2Digit.txt");
    cout << "graph MultiDigit: " << gMultiDigit << endl;

    cout<<"test copy constructor"<<endl;
    Graph g2(g1);
    cout << "graph g2: " << g2 << endl;
    
    cout<<"test = overload constructor"<<endl;
    Graph g3 = g1;
    cout << "graph g3: " << g3 << endl;
    cout<<endl;
    
    //g1.~Graph();
}//end of constructors

void testGetWeight()
{
    //test getting weights that dont exist 
    cout<<"test getWeight"<<endl;
    Graph g4("exampleGraph.txt");
    //cout << "graph g4: " << g4 << endl;

    cout << "getWeight g4 (4,2) : " << g4.getWeight(4, 2) << endl;
    cout << "getWeight g4 (0,2) : " << g4.getWeight(0, 2) << endl;
    cout << "getWeight g4 (4,3) : " << g4.getWeight(4, 3) << endl;
    //cout << "getWeight g3 (0,0) : " << g3.getWeight(0, 0) << endl;
    cout<<endl;
    
}

void testDFS()
{ 
    cout<<"test dfs"<<endl;
    Graph testdfs("exampleGraph.txt");
    testdfs.dfs();
    Graph testDfsDisJointed("exampleGraphDisJointed.txt"); //test if the the print shows the disjointed
    testDfsDisJointed.dfs();
}

void testCycle()
{
    cout<<"test Cycle"<<endl;
    Graph testCycleYes("exampleGraph.txt");
    bool cycle = testCycleYes.cycle();
    if(cycle == true){
        cout<<"cycle found in graph with cycle"<<endl;
    }


}

void testPrim()
{
    cout<<"test Prim"<<endl;
    Graph testPrimGraph("exampleGraph.txt");
    cout<<"should be:"<<endl<<"0->1"<<endl<<"1->2"<<endl<<"1->3"<<endl<<"3->4"<<endl;
    cout<<"real:"<<endl;
    testPrimGraph.Prim(0);
    cout<<endl;
    

}//end of test prim










