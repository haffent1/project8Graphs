#include <iostream>
#include "weightedTuple.h"
#include "vertex.h"

using namespace std;

int main (  void  )
{
  weightedTuple wt;
  wt.head = 0;
  wt.tail = 1;
  wt.weight = 100;
  cout << wt << endl;
  
  Vertex v;
  cout << v << endl;
  return 0;
}