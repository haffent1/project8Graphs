//Graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include "/supportFiles/List.h"
#include "/supportFiles/List.h"

using namespace std;

template <class Element>
class Graph{
    public:
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
        Graph(const Graph<Element>& graph); //copy-constructor
        ~Graph(); //destuctor
        Graph<Element>& operator = (const Graph<Element>& graph);

        Element* get(int vetexName); 
        //we might need a get weight method

        void dfs(); //depth first search print vertices in order
        bool cycle(); //indicates whether or not the graph contains a cycle
        void print(int root); 
        void Prim(int root); //us Prims algorithm to construct a minimum
        // spanning tree of an undrected weighted grpah, starting from the vertex 
        // root. the method should simply print the edges in the MST.
        // you will need to use your previously written minimum priority que class


    private:
        void copy(const Graph<Element>& graph); // copy one graph to another 
        void readFile(string filename);//read a file representing a graph
        void destroy();

        int size;
        Element *vertiecesArray; //an array of pointers to each vertex
        List<Element> *Alist; //adjacency list of the value nodes and their neighbors using a Linked list
        Dict<Edge> *GraphWeights; //a dict that holds pointers to a class that holds the 
        friend ostream& operator<<(std::ostream& stream, const Graph<Element>& graph);

}//end of Graph class

template <class Element>                                                        
std::ostream& operator<<(std::ostream& stream, const Graph<Element>& graph);


class KeyError{};
class SizeError{};
class CopyError{};

#include "Graph.cpp"
#endif


