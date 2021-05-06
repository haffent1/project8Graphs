//Graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include "./supportFiles/List.h"
#include "./supportFiles/dict.h"
#include "./supportFiles/hash.h"
#include "vertex.h"
#include "weightedTuple.h"

using namespace std;

class Graph;
                                               
std::ostream& operator<<(std::ostream& stream, const Graph& g);

class Graph //: public List<Vertex>
{
    public:
        //Constructors
        Graph(string fileName); //the constructor will take in a file
        //that looks like the following
        /*
        5        //number of vertex
        0 1 2 0 0
        1 0 1 1 0
        2 1 0 0 3
        0 1 0 0 1
        0 0 3 1 0
        */
        Graph(const Graph& graph); //copy-constructor
        ~Graph(); //destuctor
        
        //Operators
        Graph& operator = (const Graph& graph); //overload the = operator
        
        //Public Functions
        int getWeight(int head, int tail);//should return a weight

        //Iterative Functions
        void dfs(); //depth first search print vertices in order
        void dfsVisit(int i, int *timep); // recursive call of dfs
        bool cycle(); //indicates whether or not the graph contains a cycle
        //void print(); 
        void Prim(int root); //us Prims algorithm to construct a minimum
        
        //Cout functions
        string toString() const; 
        friend ostream& operator<<(ostream& stream, const Graph& g);


    public:
        void readFile(string filename);//read a file representing a graph
        void copy(const Graph& g); // copy one graph to another 
        void destroy();

        int size;
        Vertex **vertiecesArray; //an array of pointers to each vertex
        List<Vertex> **Alist;
        Dict<weightedTuple> *GraphWeights; //a dict that holds pointers to a class that holds the 
        //friend ostream& operator<<(std::ostream& stream, const Graph<Vertex>& graph);

    //using List<Vertex>::length;
};//end of Graph class

#include "graph.cpp"
#endif


