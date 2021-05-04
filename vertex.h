//vertex.h

#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
using namespace std;


//I don't think that we need to have this as a typeclass
class Vertex{
    public:
        Vertex(int value); 
        Vertex(const Vertex& vertex); //copy constructor
        Vertex& operator = (const Vertex& vertex); 

        string toString() const;

        ~Vertex(); //destructor




    pivate:
        int value // this also acts like a name to my understaning
        void copy(const Vertex& vertex);
        void Destroy();

        friend ostream& operator<<(std::ostream& stream, const Vertex& vertex);
};//end of vertex class

class KeyError{};
class SizeError{};
class CopyError{};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex);

//dont need the incldue .cpp because this dose not need to be a typeclass?
#endif




