#include<iostream>
#include<vector>
#include <stdlib.h>
#include "Grafo.h"
using namespace std;

string grafo = "Grafo.dot";
string caminoMinimo = "Camino.dot";

int main(){
    // Grafo<string,int> G;
    // G.crearGrafo();
    // G.insertarNodo("Razonamiento Logico Matematico");
    // G.insertarNodo("Metodologia");
    // G.insertarNodo("Arte computacional");
    // G.insertarNodo("Ingles I");
    // G.insertarNodo("Fundamentos de la computacion");
    // G.insertarNodo("Estructura Discretas I");
    // G.insertarNodo("Liderazgo y oratoria");

    // G.insertarNodo("Estructura discretas II");
    // G.insertarNodo("Ciencia de la computacion I");
    // G.insertarNodo("Calculo en una variable");
    // G.insertarNodo("Ingles II");
    // G.insertarNodo("Comunicacion Integral");
    // G.insertarNodo("Realida nacional");

    // G.insertarNodo("Arquitetura de computadoras");
    // G.insertarNodo("Ciencia de la computacion II");
    // G.insertarNodo("Desarrollo de plataformas");
    // G.insertarNodo("Trabajo Interdiciplinar");
    // G.insertarNodo("Calculo en varias Variables");
    // G.insertarNodo("Ingles III");
    // G.insertarNodo("Ciudadania");

    // G.insertarNodo("AED");
    // G.insertarNodo("Teoria de la computacion");
    // G.insertarNodo("Base de datos I");
    // G.insertarNodo("Algebra Lineal");
    // G.insertarNodo("Estadistica y probalidiades");
    // G.insertarNodo("Ecologia");

    // G.insertarNodo("Base de datos II");
    // G.insertarNodo("Analisis y disenho de algoritmos");
    // G.insertarNodo("Ingenieria de software I");
    // G.insertarNodo("Compiladores");
    // G.insertarNodo("Analisis exploratorio de datos espaciales");
    // G.insertarNodo("Ecuaciones diferenciales");
    
    // G.insertarNodo("Programacion competitiva");
    // G.insertarNodo("Ingenieria de software");
    // G.insertarNodo("Estructura de datos avanzados");
    // G.insertarNodo("Sistemas operativos");
    // G.insertarNodo("Trabajo interdisciplinar II");
    // G.insertarNodo("Matematica aplicada a la computacion");

    // G.insertarArista(1,"Estructura discretas I","Estructura Discretas II");
    // G.insertarArista(1,"Fundamentos de la computacion","Estructura Discretas II");
    // G.insertarArista(1,"Fundamentos de la computacion","Ciencia de la computacion I");
    // G.insertarArista(1,"Ingles I","Ingles II");

    // G.insertarArista(1,"Estructura Discretas II","Arquitetura de computadoras");
    // G.insertarArista(1,"Ciencia de la computacion I","Ciencia de la computacion II");
    // G.insertarArista(1,"Ciencia de la computacion I","Desarrollo de plataformas");
    // G.insertarArista(1,"Ciencia de la computacion I","Trabajo Interdiciplinar");
    // G.insertarArista(1,"Calculo en una variable","Calculo en varias Variables");
    // G.insertarArista(1,"Ingles II","Ingles III");

    // G.insertarArista(1,"Ciencia de la computacion II","AED");
    // G.insertarArista(1,"Estructura Discretas II","Teoria de la computacion");
    // G.insertarArista(1,"Estructura Discretas II","Base de datos I");
    // G.insertarArista(1,"Ciencia de la computacion I","Base de datos I");
    // G.insertarArista(1,"Calculo en una variable","Algebra Lineal");
    // G.insertarArista(1,"Calculo en varias Variables","Estadistica y probalidiades");

    // G.insertarArista(1,"Base de datos I","Base de datos II");
    // G.insertarArista(1,"AED","Analisis y disenho de algoritmos");
    // G.insertarArista(1,"Ciencia de la computacion II","Ingenieria de software I");
    // G.insertarArista(1,"Base de datos I","Ingenieria de software I");
    // G.insertarArista(1,"Teoria de la computacion","Compiladores");
    // G.insertarArista(1,"Estadistica y probalidiades","Analisis exploratorio de datos espaciales");
    // G.insertarArista(1,"AED","Analisis exploratorio de datos espaciales");
    // G.insertarArista(1,"Calculo en varias Variables","Ecuaciones diferenciales");
    // G.insertarArista(1,"Algebra Lineal","Ecuaciones diferenciales");

    // G.insertarArista(1,"Analisis y disenho de algoritmos","Programacion competitiva");
    // G.insertarArista(1,"Ingenieria de software I","Ingenieria de software");
    // G.insertarArista(1,"Analisis y disenho de algoritmos","Estructura de datos avanzados");
    // G.insertarArista(1,"Arquitetura de computadoras","Sistemas operativos");
    // G.insertarArista(1,"Trabajo Interdiciplinar","Trabajo interdisciplinar II");
    // G.insertarArista(1,"Ecuaciones diferenciales","Matematica aplicada a la computacion");
    // G.print(grafo);
    // vector<vector<int>> matrix = G.matrixAdyacencias();
    // vector<int> indegree = G.CalcularIndegree(matrix);
    // cout<<"\n\n\tOrden Topologico \n\n";
    // G.ordenTopologico(matrix,indegree);

    Grafo<int, int> A;
    for(int i = 0; i< 6 ;i++){
        A.insertarNodo(i);
    }
    A.insertarArista(4,2,0);
    A.insertarArista(1,0,1);
    A.insertarArista(10,1,4);
    A.insertarArista(2,0,3);
    A.insertarArista(2,3,2);
    A.insertarArista(5,2,5);
    A.insertarArista(1,6,5);
    A.insertarArista(4,3,6);
    A.insertarArista(2,3,4);
    A.insertarArista(3,1,3);
    A.insertarArista(8,3,5);
    A.print(grafo);
    A.dijkstra(4);
    return 1;
}
