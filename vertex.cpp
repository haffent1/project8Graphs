//vertex.cpp



#include <sstream>

Vertex :: Vertex(int value){
    value = value;
    
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
}// end of copy

Vertex :: void Destroy(){
    value = NULL;
} //end of Destroy 


std::ostream& operator<<(std::ostream& stream, const Vertex& vertex){
    stream<<vertex.toString();
    return stream;
}//end of << overload
