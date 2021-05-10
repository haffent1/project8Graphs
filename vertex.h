//vertex.h
#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
using namespace std;

class Vertex;

ostream& operator<<(ostream& stream, const Vertex& v);

class Vertex{
    public:
    
        //Constructors 
        Vertex();                                                 //default
        Vertex(int value);                                        //default with value
        Vertex(const Vertex& v);                                  //copy
        ~Vertex();                                                //Deconstructor

        Vertex& operator=(const Vertex& v);                       //assignment operator
        bool operator<(const Vertex& w) const;  
        bool operator>(const Vertex& w) const;    
        bool operator<=(const Vertex& w) const;   
        bool operator>=(const Vertex& w) const;
        bool operator==(const Vertex& w) const;
        bool operator!=(const Vertex& w) const;   
 
        
        //Vertex Node Values
        int value;               // this also acts like a name to my understaning
        int distFromRoot;        //this is going to be used in breadth First Search
        Vertex *predecessor;     //used in BFS and Prim
        int key;                 //this is going to be used in Prim

        int color;               // this will be used in the BFS. 0==white,1==grey,2==black;
        int discovery;           //used in BFS
        int finish;              //used in BFS
        
        
        //Print functions
          string toString() const;
          friend ostream& operator<<(ostream& stream, const Vertex& v);
        
        private:
          void copy(const Vertex& vertex);
          void destroy();


};//end of vertex class

//class CopyError{};

#include "vertex.cpp"
#endif




