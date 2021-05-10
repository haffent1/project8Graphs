//vertex.cpp
#include <sstream>

//===================
//
//    Constructors
//
//===================

//
//Default Constructor
//
Vertex :: Vertex(){
    value = 0;
    distFromRoot = 0;
    predecessor = NULL;
    key = 0;    
    color = -1;    
    discovery = 0;
    finish = 0;
}

//
//Default Constructor with value
//
Vertex :: Vertex(int value)
{
    value = value;
    distFromRoot = 0;
    predecessor = NULL;
    key = 0;    
    color = -1;    
    discovery = 0;
    finish = 0;
}

//
//Copy Constructor
//
Vertex::Vertex(const Vertex& v )
{
  this->copy(v);
}

//
//Deconstructor
//
Vertex::~Vertex()
{
  this->destroy();
}

//
//Assignment Operator
//
Vertex& Vertex::operator=(const Vertex& v)
{
    if (this != &v)
    {
        this->destroy();
        this->copy(v);
        return *this;
    }
    else
        throw CopyError{};

}
/*
bool Vertex :: operator<(const Vertex& w) const{
  if(key <  w.key){
    return true;                           
  }
  return false;                            
}
bool Vertex :: operator>(const Vertex& w) const{
  if(key > w.key){
    return true;                           
  }
  return false;                            
}
bool Vertex :: operator<=(const Vertex& w) const{
  if(key <= w.key){
    return true;                           
  }
  return false;                            
}
bool Vertex :: operator>=(const Vertex& w) const{
  if(key >=  w.key){
    return true;                           
  }
  return false;                            
}
bool Vertex :: operator==(const Vertex& w) const{
  if(key == w.key){
    return true;                           
  }
  return false;                            
}

bool Vertex :: operator!=(const Vertex& w) const{
  if(key != w.key){
    return true;                           
  }
  return false;                            
}

*/



//===================
//
//    Print Functions
//
//===================

//
//toString
//
string Vertex::toString() const
{
    stringstream s;
    s << value;
    return s.str();
}
//
//<< operator
//
std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
    stream<<vertex.toString();
    return stream;
}
//===================
//
//    Private Functions
//
//===================

//
//copy
//
void Vertex::copy(const Vertex& vertex)
{
    value = vertex.value;
    distFromRoot = vertex.distFromRoot;
    predecessor = vertex.predecessor;
    key = vertex.key;
    color = vertex.color;    
    discovery = vertex.discovery;
    finish = vertex.finish;

}
//
//destroy
//
void Vertex::destroy()
{
    value = 0;
    distFromRoot = 0;
    predecessor = NULL;
    key = 0;    
    color = -1;    
    discovery = 0;
    finish = 0;
}

//end of << overload
