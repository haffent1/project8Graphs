//vertex.h

#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
using namespace std;


//I don't think that we need to have this as a typeclass
class Vertex{
    public:
        Vertex();
        Vertex(const Vertex& vertex);
        Vertex& operator = (const Vertex& vertex);

        ~Vertex();




    pivate:
        int value // i think vertex need values

        void copy(const Vertex& vertex);
        void Destroy();


}

class KeyError{};
class SizeError{};
class CopyError{};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex);

//dont need the incldue .cpp because this dose not need to be a typeclass?
#endif




