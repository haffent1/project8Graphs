#include <sstream>
#include <fstream>
#include <string>

//================================================================
//    Constructors
//================================================================   
Graph :: Graph(string filename){
    readFile(filename); //I just wanted to make the constuctor pretty
}// end of default constructor 
     
     
     
Graph :: Graph(const Graph& graph)
{
    this->copy(graph);
}//end of copy constructor
  
  
  
Graph::~Graph()
{

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



string Graph::toString() const
{
  stringstream s;
  s << *GraphWeights;
  return s.str();
}

ostream& operator<<(ostream& stream, const Graph& g)
{
  stream << g.toString();
  return stream;
}                                                                       
//================================================================
//   Public Methods 
//================================================================



int Graph::getWeight(int head, int tail)
{
  weightedTuple* wt = new weightedTuple;
  wt->head = head;
  wt->tail = tail;
  return GraphWeights->get(*wt)->weight;
}//end of get  



void Graph :: dfs(){
//for colors 0==white, 1==grey, 2==black  
/* 
    int time = 0;                             
    int *timep = &time;                       
                                             
    for(int i = 0 ; i < size ; i++){          
        vertiecesArray[i]->predecessor = NULL;
        vertiecesArray[i]->color = 0;         
    }//end of                                 
    for(int i = 0 ; i < size ; i++){          
        if(vertiecesArray[i]->color == 0){    
            dfsVisit(i);                      
        }                                     
    }                                         
*/
}//end of dfs



void Graph :: dfsVisit(int i, int *timep)
{                                               

    /*int child;                                                                  
    Vertex *U = vertiecesArray[i];                                              
    Vertex *v;                                                                  
                                                                                
    U->color = 1; //1 == grey                                                   
    *(timep)++;                                                                 
    U->discovery = *(timep);                                                    
    for(int j = 0 ; j < Alist[U->value]->length ; j++){ //this is the most ugly syntex ive ever written, im sorry 
        v = Alist[U->value]->pop(); //get the numaric value of the child         
        if(v->color == 0){ //0 == white                                         
            v->predecessor = U; //the U and v might be swapped in this          
            dfsVisit(U->value,timep);                                           
        }//end of if white                                                      
    U->color = 2; //set color to black                                          
    *(timep)++;                                                                 
    U->finish = *(timep);                                                       
    cout<<U<<endl;// print the verties in the order that they are visited       
    }// end of for loop covering all children of                                
*/
}//end of dfsVisit                                                              



bool Graph :: cycle(){

}//end of cycle



/*void Graph :: print(){
    //there is no mention of a required print function in the project
}//end of print*/



void Graph :: Prim(int root){
    /*//make a min priority queue                                                 
    //check syntax                                                              
    MinPriorityQueue<int> primQueue = new MinPriorityQueue<int>(size); //size is an atrib of graph
    Vertex* U = new Vertex;                                                     
    int child;                                                                  
                                                                                
    for(int i = 0 ; i < size ; i++){ //size is the number of verties            
        vertiecesArray[i]->predecessor = NULL;                                  
        vertiecesArray[i]->key = 2147483647; // this is the largest value that an int in c++ can hold
        primQueue.insert(vertiecesArray[i]);                                    
    }//end of for loop                                                          
    vertiecesArray[root]->key =  0;                                             
                                                                                
    while(primQueue.empty() != true){                                           
        U = vertiecesArray[primQueue.extractMin()]; // this syntex is kinda ugly
        if (U->predecessor != NULL){ //this is the section that should handle the printing and just skip the first intera
            cout << GraphWeights(U->value, U->parent->value)<<endl;             
        }                                                                       
                                                                                
        for(int j = 0 ; j < Alist[U->value].length ; j++){ //this is assuming that the linked pointed to in Alist have a 
            child = Alist[U->value].pop()->value(); //get the numaric value of the child 
            if(GraphWeights(U->value, child) < v.key{                           
                vertiecesArray[child].key = GraphWeights(U->value, child);      
                vertiecesArray[child].predecessor = U;                          
            }// end of if weight is less than key                               
        } // end of for loop for adjacency list of U                            
    }// end of while loop for primQueue not empty             */                  
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

    int child;

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
           Vertex *v = new Vertex;
           v->value = i;
           vertiecesArray[i] = v;
        }
        
        GraphWeights = new Dict<weightedTuple>(numOfvertices);
        
        Alist = new List<Vertex>*[numOfvertices];
        for (int i = 0; i < numOfvertices; i++)
        {
           Alist[i] = new List<Vertex>;
        }
        
        for (int parent = 0; parent <= numOfvertices ; parent++){           
            getline(file, line);                                            
            //cout<<line<<endl;                                               
            istringstream ssLine(line);                                     
            child = 0; //reset the X                                        
            while(ssLine){                                                  
               ssLine >> stringEdgeWeight;                                 
               edgeWeight = stoi(stringEdgeWeight);    
                                   
               if(edgeWeight != 0 && child < numOfvertices)
               {                                        
                   //cout <<parent<<"->"<<child<<":"<< stringEdgeWeight << endl;
                   
                   //Fills the Alist with the proper values by linking it to the vertexes in vertiecesArray
                   Alist[parent]->append(vertiecesArray[child]);
                   
                   //Fills the GraphWeights hash with new vertexes
                   weightedTuple *w = new weightedTuple;
                   w->head = parent;
                   w->tail = child;
                   w->weight = edgeWeight;
                   GraphWeights->insert(w);
                   
                   //Fills the Alist with values
               }    
               child++;                                                                                                      
            }//end of line while loop 
        }//end of y axis traverals                                                
    }

}//end of readFile

void Graph::copy(const Graph& g)
{
    size = g.size;
    vertiecesArray = new Vertex*[size];
    Alist = new List<Vertex>*[size];
    
    for (int i = 0; i < size; i++)
    {
      vertiecesArray[i] = g.vertiecesArray[i];
      Alist[i] = g.Alist[i];
    }
    
    //GraphWeights = new Dict<weightedTuple>(g.size);
    GraphWeights = g.GraphWeights;  
}//end of copy

void Graph :: destroy()
{
  delete [] this->Alist;
  delete [] this->vertiecesArray;
  //GraphWeights.~HashTable();
}//end of destroy 


