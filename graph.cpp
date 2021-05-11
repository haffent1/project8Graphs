#include <sstream>
#include <fstream>
#include <string>

//================================================================
//    Constructors
//================================================================   
Graph :: Graph(string filename){
    readFile(filename); //I just wanted to make the constuctor pretty
}// end of default constructor 
     
     
     
Graph::Graph(const Graph& graph)
{
    this->copy(graph);
}//end of copy constructor
  
  
  
Graph::~Graph()
{
  this->destroy();
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

    int time = 0;
    int *timep = &time;  //made time a pointer so that it can be passed in

    for(int i = 0 ; i < size ; i++){
        vertiecesArray[i]->predecessor = NULL;
        vertiecesArray[i]->color = 0;
    }//end of
    for(int i = 0 ; i < size ; i++){
        if(vertiecesArray[i]->color == 0){
            List<Vertex> *vertexList = new List<Vertex>[size];
            vertexList->append(vertiecesArray[i]);
            dfsVisit(vertiecesArray[i], time, vertexList);
            cout << *vertexList;
        }
    }
    cout << endl;
}//end of dfs



void Graph::dfsVisit(Vertex* U, int& time, List<Vertex> *vertexList)
{
    U->color = 1;
    time = time + 1;
    U->discovery = time;
    //Use this to iterate through the Alist instead of using [] since that wasnt working when it as a pointer to a linked list
    for (int z = 0; z < Alist[U->value]->size(); z++)
    {
      if(Alist[U->value]->find(z)->color == 0)
      {
        Vertex *v = Alist[U->value]->find(z);
        vertexList->append(v);
        v->predecessor = U;
        dfsVisit(v, time, vertexList);
      }
    }
    U->color = 2;
    time++;
    U->finish = time;
}//end of dfsVisit



bool Graph :: cycle(){
    int time = 0;
    int *timep = &time;  //made time a pointer so that it can be passed in
    bool temp = false;

    for(int i = 0 ; i < size ; i++){
        vertiecesArray[i]->predecessor = NULL;
        vertiecesArray[i]->color = 0;
    }
    for(int i = 0 ; i < size ; i++){
        if(vertiecesArray[i]->color == 0){
            temp = cycleVisit(vertiecesArray[i],time);
            if (temp == true)
              return temp;
        }
    }
    return temp;
}//end of cycle

bool Graph::cycleVisit(Vertex* U, int& time)
{
    U->color = 1;
    time = time + 1;
    U->discovery = time;
    //Use this to iterate through the Alist instead of using [] since that wasnt working when it as a pointer to a linked list
    for (int z = 0; z < Alist[U->value]->size(); z++)
    {
      Vertex *v = Alist[U->value]->find(z);
      if(v->color == 0)
      {
        v->predecessor = U;
        cycleVisit(v, time);
      }
      else if (v->color == 2 || v->color == 1)
      {
        return true;
      }
    }
    U->color = 2;
    time++;
    U->finish = time;
    return false;
}






void Graph :: Prim(int root){
    //make a min priority queue                                                 
    MinPriorityQueue<int> primQueue; // note that this expects int pointers?

    //List<Vertex>** AlistCopy = Alist;

    Vertex* U; //this will be used as primary vertex
    Vertex* V; //this will be used as secondary vertex                                                    
    //cout<<"Prim"<<endl;                                                                            
    //cout<<"size:"<<size<<endl;
    for(int i = 0 ; i < size ; i++){ //size is the number of verties            
        //cout<<"prim"<<i<<endl;                                                                            
        U = vertiecesArray[i];
        U -> predecessor = NULL;                                  
        U -> key = 2147483647; // this is the largest value that an int in c++ can hold
        //primQueue->insert(vertiecesArray[i]);                                    
        primQueue.insert(&U->value);                                    
    }//end of for loop                                                          
    U = vertiecesArray[root];          
    U->key = 0;
                                                                                
    while(primQueue.empty() != true ){                                           
        //cout<<"Prim que empty while loop"<<endl;                                                                            
        U = vertiecesArray[*(primQueue.extractMin())]; // this syntex is kinda ugly
        //cout<<"U: "<<U->value <<endl;

        if (U->predecessor != NULL){ //this is the section that should handle the printing and just skip the first intera
            //cout << getWeight(U->value, U->predecessor->value) <<endl;             
            cout << U->predecessor->value<<"->"<<U->value <<endl;             
        }                                                                       

        for(int j = 0 ; j < Alist[U->value]->length ; j++){ //this is assuming that the linked pointed to in Alist have a 
            V = Alist[U->value]->find(j); //get the numaric value of the child 
            //cout<<"value of V: "<<V->value<<endl; //get the numaric value of the child 
            if(getWeight(U->value, V->value) < V->key){ //I think that this is comparing pinters right now
                vertiecesArray[V->value]->key = getWeight(U->value, V->value);      
                vertiecesArray[V->value]->predecessor = U;                          
            }// end of if weight is less than key                               
        } // end of for loop for adjacency list of U                            
    }// end of while loop for primQueue not empty                               
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
  //delete GraphWeights;
}//end of destroy 


