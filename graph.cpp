#include <sstream>
#include <fstream>
#include <string>




//================================================================
//
//    Constructors
//
//================================================================
template <class Element>      
Graph<Element> :: Graph(string filename){
    readFile(filename); //I just wanted to make the constuctor pretty
}// end of default constructor 


template <class Element>      
Graph<Element> :: Graph(const Graph<Element>& graph){
}//end of copy constructor

template <class Element>      
Graph<Element> :: ~Graph(){
}//destructor


//================================================================
//                                                                
//    Operators                                                   
//                                                                
//================================================================

template<class Element>
Graph<Element>& Graph<Element> :: operator=(const Graph<Element>& graph){
}//end of = overload

//not that << is a non memeber overload
template <class Element>                                                      
ostream& operator<<(ostream& stream, const Graph<Element>& graph)                  
{                                                                             
  int root = 0;  
  stream << graph.print(int root);                                                     
  return stream;                                                              
}                                                                             




//================================================================
//                                                                
//   Public Methods 
//                                                                
//================================================================

template<class Element>
Element* Graph<Element> :: get(const Element *vertex){

}//end of dfs

template<class Element>
void Graph<Element> :: dfs(){

}//end of dfs

template<class Element>
bool Graph<Element> :: cycle(){

}//end of cycle


template<class Element>
void Graph<Element> :: copy(const Graph<Element>& graph){
}//end of copy


template<class Element>
void Graph<Element> :: print(int root){
}//end of print


//================================================================
//                                                                
//   Private Methods 
//                                                                
//================================================================

template<class Element>
void Graph<Element> :: readFile(string filename){

string line;


//read in files
ifstream file("linuxDict.txt");
    if (file.tellg() == 1)
    {
        throw "ERROR: file is empty";
    }
    if (file.is_open())
    {
        //the first line of the file will always have the number of vertices
        getline(file, line)
        //Graph<Element> *Alist = new List<Element>[int(line)] //fix python
    }



}//end of readFile

template<class Element>
void Graph<Element> :: destroy(){
}//end of destroy 


