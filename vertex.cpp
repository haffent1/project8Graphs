//vertex.cpp
#include <sstream>

Vertex :: Vertex(){
    value = NULL;
    distFromRoot = NULL;
    predecessor = NULL;
    key = NULL;    
    color = NULL;    
    discovery = NULL;
    finish = NULL;
}//end of default constructor

Vertex :: Vertex(int value){
    value = value;
    distFromRoot = NUll;
    predecessor = NULL;
    key = NUll;    
    color = NULL;    
    discovery = NULL;
    finish = NULL;
}//end of default constructor

Vertex :: Vertex(const Vertex& vertex){
    this->copy(vertex);
}//end of copy constructor

Vertex :: Vertex& operator = (const Vertex& vertex){
    if (this != &vertex)
    {
        this->destroy();
        this->copy(vertex);
        return *this;
    }
    else
        throw CopyError{};

}//end of copy constructor

Vertex :: string toString() const{
    stringstream s;
    s << value;
    return s;
}//end of to string 



Vertex :: ~Vertex(){
    this->destroy();
}//end of destuctor


Vertex :: void copy(const Vertex& vertex){
    value = vertex.length;
    distFromRoot = vertex.distFromRoot;
    predecessor = vertex.predecessor;
    key = vertex.key;
    color = vertex.color;    
    discovery = vertex.discovery;
    finish = vertex.finish;

}// end of copy

Vertex :: void Destroy(){
    value = NULL;
    distFromRoot = NUll;
    predecessor = NULL;
    key = NULL;    
    color = NULL;    
    discovery = NULL:
    finish = NULL:
} //end of Destroy 


std::ostream& operator<<(std::ostream& stream, const Vertex& vertex){
    stream<<vertex.toString();
    return stream;
}//end of << overload
