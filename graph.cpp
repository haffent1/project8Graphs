#include <sstream>
#include <fstream>
#include <string>

//================================================================
//    Constructors
//================================================================   
Graph :: Graph(string filename){
    readFile(filename); //I just wanted to make the constuctor pretty
}// end of default constructor 
     
Graph :: Graph(const Graph& graph){
    this->copy(graph);
}//end of copy constructor
  
Graph :: ~Graph(){
}//destructor

//================================================================
//    Operators                                                   
//================================================================

Graph& Graph :: operator=(const Graph& graph){
    if (this != &graph)      
    {                    
        this->destroy();   
        this->copy(graph);     
        return *this;      
    }                    
    else                 
        throw CopyError{}; 
}//end of = overload

//not that << is a non memeber overload                                                  
std :: ostream& operator<<(ostream& stream, const Graph& graph)                  
{                                                                             
   /*
  int root = 0;  
  stream << graph.print(int root);                                                     
  return stream;                                                              
  */
}                                                                             
//================================================================
//   Public Methods 
//================================================================

Vertex* Graph :: get(int vertexName){
    return vertiecesArray[vertexName];
}//end of get  


void Graph :: dfs(){
    /*for( each v in V){
        v.dist = inf;
        v.pred;
    }*/

}//end of dfs


bool Graph :: cycle(){

}//end of cycle



void Graph :: copy(const Graph& graph){
}//end of copy



void Graph :: print(int root){
}//end of print


//================================================================
//                                                                
//   Private Methods 
//                                                                
//================================================================


void Graph::readFile(string filename){
//read in files
ifstream file(filename);
    string line; //line from file 
    string stringEdgeWeight; //intermediate value so we can use string to int 

    int numOfvertices;
    int edgeWeight; 
                                            
    if (file.tellg() == 1)                                                      
    {                                                                           
        throw "ERROR: file is empty";                                           
    }                                                                           
    if (file.is_open())                                                         
    {                                                                           
        //the first line of the file will always have the number of vertices    
        getline(file, line); 
        numOfvertices = stoi(line);
        size = numOfvertices;
        
        vertiecesArray = new Vertex*[numOfvertices];
        for (int i = 0; i < numOfvertices; i++)
        {
           vertiecesArray[i] = new Vertex();
        }
        
        //this secion gets the rest of the file
        for (int yAxis = 0 ; yAxis < numOfvertices ; yAxis++){
            getline(file, line);
            cout<<line<<endl;
            int j;
            int xAxis;
            int nodeCount = 0;
            for ( j = 0, xAxis = 0  ; j < numOfvertices*2 ; j+=2, xAxis++){ //will the *2 always work?
                stringEdgeWeight = line[j];
                edgeWeight = stoi(stringEdgeWeight);
                
                if(edgeWeight != 0){
                    cout<<yAxis<<"->"<<xAxis<<": "<<edgeWeight<<endl;
                }
                vertiecesArray[yAxis]->value = yAxis; //this adds values to vertex nodes, not sure if proper values at this point in time
                
            }// end of go through line
            cout<<endl;
        }//end of of interating through vertically

        //Graph *Alist = new List[int(line)] //fix python     
    }                                                                           

}//end of readFile


void Graph :: destroy(){
}//end of destroy 


