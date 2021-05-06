//#include "dict.h"
#include <sstream>

using namespace std;

class weightedTuple;

ostream& operator<<(ostream& stream, const weightedTuple& w);

class weightedTuple
{
    public:
      int head;
      int tail;
      int weight;

      weightedTuple();
      
      int hash(int slots);

      /*bool operator<(const weightedTuple& w) const;
      bool operator>(const weightedTuple& w) const;
      bool operator<=(const weightedTuple& w) const;
      bool operator>=(const weightedTuple& w) const;*/
      bool operator==(const weightedTuple& w) const;
      bool operator!=(const weightedTuple& w) const;

      //ostream& operator<<(ostream& os, const Movie& m);
      string toString() const;
      friend ostream& operator<<(ostream& stream, const weightedTuple& w);
};

weightedTuple::weightedTuple()
{
  head = 0;
  tail = 0; 
  weight = 0;
}

int weightedTuple::hash(int slots)
{
  int x = head + tail * 3.14;

  float A = .618;
  int B = (A * x);
  float C = (A * x) - B;
  int D = C * slots;
  
  return (D);
}

bool weightedTuple::operator==(const weightedTuple& w) const
{
  if((head == w.head) && (tail == w.tail))
    return true;
  return false;
}

bool weightedTuple::operator!=(const weightedTuple& w) const
{
  if((head != w.head) || (tail != w.tail))
    return true;
  return false;
}

string weightedTuple::toString() const
{
  stringstream s;
  s << "(" << head << ", " << tail << ")" << ": " << weight;
  return s.str();
}

ostream& operator<<(ostream& stream, const weightedTuple& w)
{
  stream << w.toString();
  return stream;
}