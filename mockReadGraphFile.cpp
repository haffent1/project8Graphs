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
    string tempNumber;
    string stringEdgeWeight; //intermediate value so we can use string to int 
    
    int child;

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
            for (int parent = 0 ; parent < numOfvertices ; parent++){
                getline(file, line);
                cout<<line<<endl;
                istringstream ssLine(line); 
                child = 0; //reset the X
                while(ssLine){
                    ssLine >> stringEdgeWeight;
                    edgeWeight = stoi(stringEdgeWeight);
                    if(edgeWeight != 0){
                        cout <<parent<<"->"<<child<<":"<< stringEdgeWeight << endl;
                    }
                    child++;
                } 
            }


            //Graph<Element> *Alist = new List<Element>[int(line)] //fix python     
        }                                                                           

}//end of readFile
