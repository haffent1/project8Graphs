#include <sstream>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;




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
Element* Graph<Element> :: get(int vertex){
    return vertieces[vertex];
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
void Graph<Element> :: Prim(int root){
/*
     for each u in V:                                   
         u.pred = nill                                  
         u.key = infinity                               
         r.key = 0                                      
                                                        
         pq = min priority queue containing vertes in V.
                                                        
         while pq is not empty:                         
             u = pq.extractMin();                       
             for each vertex in U.adjacency{            
                     if w(u,v) < v.key{                 
                             v.key = w(u,v);            
                             v.pred = u;                
                     }//end of if                       
             }//end of for each vertex                  
*/
}//end of Prim

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

    string line; //line from file                                               
    string stringEdgeWeight; //intermediate value so we can use string to int   
                                                                                
    int numOfvertices;                                                          
    int edgeWeight;                                                             
                                                                                
    ifstream file(fileName);                                                    
        if (file.tellg() == 1)                                                  
        {                                                                       
            throw "ERROR: file is empty";                                       
        }                                                                       
        if (file.is_open())                                                     
        {                                                                       
            //the first line of the file will always have the number of vertices
            getline(file, line);                                                
            numOfvertices = stoi(line);                                         

            //I think that we then need to initiate vertices objects here

            //dealing with graph attributes
            size = numOfvertices;                                                                


            vertieces = new vertex[size]; //this is just an array of vertieces

            Alist = new List<Element>[size]; //adjacency list of the value nodes and their neighbors

            GraphWeights = new Dict(size-1); //a dict that when given two vertices gives back the weight of the edge
             //size-1 becuase that is the maximum number of edges possible

                                                                                
            //this secion gets the rest of the file                             
            for (int yAxis = 0 ; yAxis < numOfvertices ; yAxis++){              
                getline(file, line);                                            
                int j;                                                          
                int xAxis;                                                      
                for ( j = 0, xAxis = 0  ; j < numOfvertices*2 ; j+=2, xAxis++){ //will the *2 always work?
                    stringEdgeWeight = line[j];                                 
                    edgeWeight = stoi(stringEdgeWeight);                        
                                                                                
                    if(edgeWeight != 0){                                        
                        cout<<yAxis<<"->"<<xAxis<<": "<<edgeWeight<<endl;       

                        //Alist[yAxis].insert(xAxis);  //push xAxis onto the link list of 
                        //GraphWeights
                    }                                                           
                }// end of go through line                                      
                cout<<endl;                                                     
            }//end of of interating through vertically                          
        }                                                                       
}//end of readFile                                                              


template<class Element>
void Graph<Element> :: destroy(){
}//end of destroy 


