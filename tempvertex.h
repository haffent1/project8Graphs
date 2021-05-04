//vertex.h

#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
using namespace std;

class Vertex;

ostream& operator<<(ostream& stream, const Vertex& v);

class Vertex{
    public:
        int value;
        int key;
        Vertex* pred;
        
        Vertex();
        
        bool operator==(const Vertex& v) const;
        bool operator!=(const Vertex& v) const;
      
        string toString() const;
        friend ostream& operator<<(ostream& stream, const Vertex& v);
        
};//end of vertex class

//dont need the incldue .cpp because this dose not need to be a typeclass?
#include "vertex.cpp"
#endif




