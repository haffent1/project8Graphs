/*this is a throw-away file so that i can work on these while
mitch is working in graphs.cpp
*/

Prim(int root){
    //make a min priority queue
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
        if (U->predecessor != NULL){ //this is the section that should handle the printing and just skip the first interation
            cout << GraphWeights(U->value, U->parent->value)<<endl;
        }

        for(int j = 0 ; j < Alist[U->value].length ; j++){ //this is assuming that the linked pointed to in Alist have a length value 
            child = Alist[U->value].pop()->value(); //get the numaric value of the child 
            if(GraphWeights(U->value, child) < v.key{
                vertiecesArray[child].key = GraphWeights(U->value, child);
                vertiecesArray[child].predecessor = U; 
            }// end of if weight is less than key
        } // end of for loop for adjacency list of U
    }// end of while loop for primQueue not empty
}//end of prims



//==============================================================================
//DFS
//==============================================================================
void dfs(){
    //for colors 0==white, 1==grey, 2==black

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
}//end of dfs

void dfsVisit(int i, int *timep){ 
    int child;
    vertex *U = vertiecesArray[i];
    vertex *v; 

    U->color = 1; //1 == grey
    *(timep)++;
    U->discovery = *(timep);
    for(int j = 0 ; j < Alist[U->value].length ; j++){ //this is the most ugly syntex ive ever written, im sorry 
        v = Alist[U->value].pop(); //get the numaric value of the child 
        if(v->color == 0){ //0 == white
            v->predecessor = U; //the U and v might be swapped in this
            dfsVisit(U->value,timep);
        }//end of if white
    U->color = 2; //set color to black
    *(timep)++;
    U->finish = *(timep);
    cout<<U<<endl;// print the verties in the order that they are visited
    }// end of for loop covering all children of 
}//end of dfsVisit

bool cycle(){
    //there is a way to use the dfs to figure this out


}














