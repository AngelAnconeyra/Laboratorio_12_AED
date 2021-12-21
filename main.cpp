#include<iostream>
#include<vector>
#include <stdlib.h>
#include "Grafo.h"
using namespace std;



int main(){
    Grafo<string,int> G;
    G.crearGrafo();
    G.insertarNodo("Razonamiento Logico Matematico");
    G.insertarNodo("Metodologia");
    G.insertarNodo("Arte computacional");
    G.insertarNodo("Ingles I");
    G.insertarNodo("Fundamentos de la computacion");
    G.insertarNodo("Estructura Discretas I");
    G.insertarNodo("Liderazgo y oratoria");

    G.insertarNodo("Estructura discretas II");
    G.insertarNodo("Ciencia de la computacion I");
    G.insertarNodo("Calculo en una variable");
    G.insertarNodo("Ingles II");
    G.insertarNodo("Comunicacion Integral");
    G.insertarNodo("Realida nacional");

    G.insertarNodo("Arquitetura de computadoras");
    G.insertarNodo("Ciencia de la computacion II");
    G.insertarNodo("Desarrollo de plataformas");
    G.insertarNodo("Trabajo Interdiciplinar");
    G.insertarNodo("Calculo en varias Variables");
    G.insertarNodo("Ingles III");
    G.insertarNodo("Ciudadania");

    G.insertarNodo("AED");
    G.insertarNodo("Teoria de la computacion");
    G.insertarNodo("Base de datos I");
    G.insertarNodo("Algebra Lineal");
    G.insertarNodo("Estadistica y probalidiades");
    G.insertarNodo("Ecologia");

    G.insertarArista(1,"Estructura discretas I","Estructura Discretas II");
    G.insertarArista(1,"Fundamentos de la computacion","Estructura Discretas II");
    G.insertarArista(1,"Fundamentos de la computacion","Ciencia de la computacion I");
    G.insertarArista(1,"Ingles I","Ingles II");

    G.insertarArista(1,"Estructura Discretas II","Arquitetura de computadoras");
    G.insertarArista(1,"Ciencia de la computacion I","Ciencia de la computacion II");
    G.insertarArista(1,"Ciencia de la computacion I","Desarrollo de plataformas");
    G.insertarArista(1,"Ciencia de la computacion I","Trabajo Interdiciplinar");
    G.insertarArista(1,"Calculo en una variable","Calculo en varias Variables");
    G.insertarArista(1,"Ingles II","Ingles III");

    G.insertarArista(1,"Ciencia de la computacion II","AED");
    G.insertarArista(1,"Estructura Discretas II","Teoria de la computacion");
    G.insertarArista(1,"Estructura Discretas II","Base de datos I");
    G.insertarArista(1,"Ciencia de la computacion I","Base de datos I");
    G.insertarArista(1,"Calculo en una variable","Algebra Lineal");
    G.insertarArista(1,"Calculo en varias Variables","Estadistica y probalidiades");
    G.print();
    vector<vector<int>> matrix = G.matrixAdyacencias();
    vector<int> indegree = G.CalcularIndegree(matrix);
    cout<<"\n\n\tOrden Topologico \n\n";
    G.ordenTopologico(matrix,indegree);

    return 1;
}
