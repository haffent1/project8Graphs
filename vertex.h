//vertex.h
#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
using namespace std;

class Vertex{
    public:
        Vertex(); 
        Vertex(int value); 
        Vertex(const Vertex& vertex); //copy constructor
        Vertex& operator = (const Vertex& vertex); 
        string toString() const;
        ~Vertex(); //destructor

    pivate:
        int value // this also acts like a name to my understaning
        int distFromRoot; //this is going to be used in breadth First Search
        vertex *predecessor;//used in BFS and Prim
        int key; //this is going to be used in Prim

        int color// this will be used in the BFS. 0==white,1==grey,2==black;
        int discovery; //used in BFS
        int finish; //used in BFS

        void copy(const Vertex& vertex);
        void Destroy();

        friend ostream& operator<<(std::ostream& stream, const Vertex& vertex);
};//end of vertex class

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex);
#endif




