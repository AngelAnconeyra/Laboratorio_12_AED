#include<iostream>
#include<vector>
#include <stdlib.h>
#include "Grafo.h"
using namespace std;



int main(){
    Grafo<string,int> G;
    G.crearGrafo();
    G.insertarNodo("Arequipa");
    G.insertarNodo("Sullana");
    G.insertarNodo("Lima");
    G.insertarNodo("Huanuco");
    G.insertarNodo("Chiclayo");
    G.insertarArista(1881,"Chiclayo","Arequipa");
    G.insertarArista(310,"Sullana","Arequipa");
    G.insertarArista(8000,"Lima","Huanuco");
    //G.print();
   // G.borrarNodo("Arequipa");
   // G.print();
   vector<vector<int>> matrix = G.matrixAdyacencias();
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout << matrix[i][j] << " ";
        }
        cout<<endl;
    }
    cout<<endl;
    vector<int> indegree = G.CalcularIndegree(matrix);
    for(int i=0;i<5;i++){
        cout<<indegree[i] << endl;
    }
    cout<<endl;
    G.ordenTopologico(matrix,indegree);

    return 1;
}
