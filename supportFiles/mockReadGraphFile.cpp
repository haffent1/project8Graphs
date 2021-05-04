#include <sstream>
#include <fstream>
#include <string> 
#include <iostream>
using namespace std;

void readFile(string fileName);

int main(){
    cout<<"main ran"<<endl;
    string file = "exampleGraph.txt";
    readFile(file);
}//end of main

void readFile(string fileName){
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

            //this secion gets the rest of the file
            for (int yAxis = 0 ; yAxis < numOfvertices ; yAxis++){
                getline(file, line);
                cout<<line<<endl;
                int j;
                int xAxis;
                for ( j = 0, xAxis = 0  ; j < numOfvertices*2 ; j+=2, xAxis++){ //will the *2 always work?
                    stringEdgeWeight = line[j];
                    edgeWeight = stoi(stringEdgeWeight);
                    
                    if(edgeWeight != 0){
                        cout<<yAxis<<"->"<<xAxis<<": "<<edgeWeight<<endl;
                    }
                }// end of go through line
                cout<<endl;
            }//end of of interating through vertically

            //Graph<Element> *Alist = new List<Element>[int(line)] //fix python     
        }                                                                           

}//end of readFile
