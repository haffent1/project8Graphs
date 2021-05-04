//vertex.cpp
#include <sstream>

Vertex::Vertex()
{
    value = 0;
    key = 0;
    pred = NULL;
}//end of default constructor

bool Vertex::operator==(const Vertex& v) const
{
  if(value == v.value)
    return true;
  return false;
}

bool Vertex::operator!=(const Vertex& v) const
{
  if((value != v.value))
    return true;
  return false;
}

string Vertex::toString() const
{
    stringstream s;
    s << value;
    return s.str();
}//end of to string 

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
    stream << vertex.toString();
    return stream;
}//end of << overload
