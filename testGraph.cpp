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
  testCycle();
  testPrim();
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
    cout<<"TEST: getWeight()"<<endl;
    Graph g4("exampleGraph.txt");
    //cout << "graph g4: " << g4 << endl;

    assert (g4.getWeight(4, 2) == 3);
    assert (g4.getWeight(0, 2) == 2);
    assert (g4.getWeight(4, 3) == 1);
    try{
      g4.getWeight(0, 0);
    }
    catch (class KeyError)
    {
      cout << "weight not present on edge (0,0)" << endl;
    }
    
    cout << "GETWEIGHT TEST COMPELTE" << endl << endl << endl;
    
}

void testDFS()
{ 
    cout<<"TEST: dfs()"<< endl;
    Graph testdfs("exampleGraph.txt");
    testdfs.dfs();
    assert(testdfs.vertiecesArray[0]->discovery < testdfs.vertiecesArray[1]->discovery);
    assert(testdfs.vertiecesArray[1]->discovery < testdfs.vertiecesArray[2]->discovery);
    assert(testdfs.vertiecesArray[2]->discovery < testdfs.vertiecesArray[4]->discovery);
    assert(testdfs.vertiecesArray[4]->discovery < testdfs.vertiecesArray[3]->discovery);
    
    
    Graph testDfsDisJointed("exampleGraphDisJointed.txt"); //test if the the print shows the disjointed
    testDfsDisJointed.dfs();
    assert(testDfsDisJointed.vertiecesArray[0]->discovery < testDfsDisJointed.vertiecesArray[1]->discovery);
    assert(testDfsDisJointed.vertiecesArray[1]->discovery < testDfsDisJointed.vertiecesArray[2]->discovery);
    assert(testDfsDisJointed.vertiecesArray[2]->discovery < testDfsDisJointed.vertiecesArray[4]->discovery);
    assert(testDfsDisJointed.vertiecesArray[4]->discovery < testDfsDisJointed.vertiecesArray[3]->discovery);
    assert(testDfsDisJointed.vertiecesArray[3]->discovery < testDfsDisJointed.vertiecesArray[5]->discovery);
    
    cout << "DFS TEST COMPELTE" << endl << endl << endl;
}

void testCycle()
{
    cout<<"TEST: cycle()"<< endl;
    Graph testCycleYes("exampleGraph.txt");
    assert (testCycleYes.cycle() == true);
    
    Graph testCycleNo("exampleGraphNone.txt");
    assert (testCycleNo.cycle() == false);
    
    cout << "CYCLE TEST COMPELTE" << endl << endl << endl;
}

void testPrim()
{
    //cout<<"test Prim"<<endl;
    Graph testPrimGraph("exampleGraph.txt");
    //cout<<"should be:"<<endl<<"0->1"<<endl<<"1->2"<<endl<<"1->3"<<endl<<"3->4"<<endl;
    //cout<<"real:"<<endl;
    testPrimGraph.Prim(0);
    //cout<<endl;
    assert(testPrimGraph.vertiecesArray[4]->predecessor->value == 3);  
    assert(testPrimGraph.vertiecesArray[3]->predecessor->value == 1);  
    assert(testPrimGraph.vertiecesArray[2]->predecessor->value == 1);  
    assert(testPrimGraph.vertiecesArray[1]->predecessor->value == 0);  
    cout << "PRIM TEST COMPELTE" << endl << endl << endl;


    

}//end of test prim










