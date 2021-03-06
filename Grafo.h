#ifndef _GRAFO_H_
#define _GRAFO_H_
#include <bits/stdc++.h>
#include "Nodo.h"
using namespace std;
template<class T, class A>
class Grafo{
    private:
        int nvertices=0;
        vector<list<Node<T,A>>> vertices;
    public:
        void crearGrafo();
        void insertarNodo(T dato);
        void insertarArista(A valor, T n1, T n2);
        void borrarNodo(T dato);
        void borrarArista(T n1, T n2);
        bool existeNodo(T);
        bool existeArista(T,T);
        A val_Arista(T,T);
        int index_vert(T nombre);
        vector<vector<int>> matrixAdyacencias();
        vector<int> CalcularIndegree(vector<vector<int>>);
        int EncuentraI0(vector<int>);
        void DecrementaIndigree(vector<vector<int>>,vector<int> &,int);
        void ordenTopologico(vector<vector<int>>,vector<int>&);
        T dist_minima(map<T,bool>, map<T,int>);
        void dijkstra(T);
        void dijkstra(map<T,bool> &visitados, map<T,int> &distancias, T src);
        void print(string);
        void print(ofstream &);
};

template<class T, class A>
void Grafo<T,A>::crearGrafo(){
    nvertices = 0;
    for(list<Node<T,A>> &a: vertices){
        a.clear();
    }
    vertices.clear();
}

template<class T, class A>
void Grafo<T,A>::insertarNodo(T dato){
    Node<T,A> nuevo(dato);
    list<Node<T,A>> aux;
    aux.push_back(nuevo);
    if(existeNodo(dato)==false){
        vertices.push_back(aux);
        nvertices++;    
    }
    return;
}

template<class T, class A>
void Grafo<T,A>::insertarArista(A valor, T n1, T n2){
    for(list<Node<T,A>> &a : vertices){
        if((*a.begin()).dato == n1){
            Node<T,A> conex(n2,valor); /*Nuevo nodo conectado con el valor y el peso de la arista*/
            a.push_back(conex);
            return;      /*Se inserta a la lista*/
        }
    }
}

template<class T, class A>
void Grafo<T,A>::borrarNodo(T dato){
    for(list<Node<T,A>> &a: vertices){
        for(typename list<Node<T,A>>::iterator i = ++a.begin(); i!=a.end();++i){
            if( (*i).dato == dato){
                a.erase(i);
                break;
            }
        }
    }

    for (typename vector<list<Node<T,A>>>::iterator i = vertices.begin(); i != vertices.end(); i++){
        if( ( *( (i)->begin() ) ).dato == dato ){
            vertices.erase(i);
            nvertices--;
            break;
        }
    }

    return;
}

template<class T, class A>
void Grafo<T,A>::borrarArista(T n1, T n2){
    for(list<Node<T,A>> &a : vertices){
        if((*a.begin()).dato == n1){
            for(typename list<Node<T,A>>::iterator i = a.begin(); i!=a.end();++i){
                if((*i).dato == n2){
                    a.erase(i);
                    break;
                }
            }
            break;
        }
    }
}

template<class T, class A>
bool Grafo<T,A>::existeNodo(T dat){
    for(list<Node<T,A>> a : vertices){
        if((*a.begin()).dato == dat)
            return true;
    }
    return false;
}

template<class T, class A>
bool Grafo<T,A>::existeArista(T dat1, T dat2){
    for(list<Node<T,A>> &a: vertices){
        if( (*a.begin()).dato == dat1){
            for(typename list<Node<T,A>>::iterator i = ++a.begin(); i!=a.end();++i){
                if( (*i).dato == dat2){
                    return true;
                }
            }
        }
    }
    return false;
}

template<class T, class A>
A Grafo<T,A>::val_Arista(T dat1, T dat2){
    for(list<Node<T,A>> &a: vertices){
        if( (*a.begin()).dato == dat1){
            for(typename list<Node<T,A>>::iterator i = ++a.begin(); i!=a.end();++i){
                if( (*i).dato == dat2){
                    return (*i).ValArista;
                }
            }
        }
    }
    return 0;
}

template<class T, class A>
int Grafo<T,A>::index_vert(T nombre){
    int index = 0;
    for(list<Node<T,A>> a : vertices){
        if (nombre == (*a.begin()).dato){
            return index;
        }
        index++;
    }
    return 0;
}

template<class T, class A>
vector<vector<int>> Grafo<T,A>::matrixAdyacencias(){
    int tamanho = vertices.size();
    int fil=0;
    int col=0, peso;
    vector<vector<int>> matrix(tamanho, vector<int>(tamanho, 0));
    for(list<Node<T,A>> a : vertices){
        for(Node<T,A> nodo : a){
            if((*a.begin()).dato != nodo.dato){
                col = index_vert(nodo.dato);
                peso = nodo.ValArista;
                matrix[fil][col]= peso;
            }
        }
        fil++;
    }
    return matrix;
}

template<class T, class A>
vector<int> Grafo<T,A>::CalcularIndegree(vector<vector<int>>  matrix){
    int tamanho = vertices.size();
    int i=0;
    vector<int>  indegree(tamanho, 0);
    for(list<Node<T,A>> a : vertices){
        int cont=0;
        for(int j=0;j<tamanho;j++){
            if(matrix[j][i] != 0){
                cont++;
            }
        }
        indegree[i]= cont;
        i++;
    }
    return indegree;
}

template<class T, class A>
int Grafo<T,A>::EncuentraI0(vector<int> indegree){
    int tamanho = vertices.size();
    bool encontrado = false;
    for(int n=0;n<tamanho;n++){
        if(indegree[n]==0){
            encontrado = true;
            return n;
        }
    }
    if(!encontrado){
        return -1;
    }
    return -1;
}

template<class T, class A>
void Grafo<T,A>::DecrementaIndigree(vector<vector<int>> matrix,vector<int>& indegree, int pNodo){
    indegree[pNodo] = -1;
    for(int i=0;i< vertices.size();i++){
        if(matrix[pNodo][i] == 1){
            indegree[i]--;
        }
    }
}

template<class T, class A>
void Grafo<T,A>::ordenTopologico(vector<vector<int>> matrix,vector<int> & indegree){
    int nodo = 0;
    do{
        nodo = EncuentraI0(indegree);
        if(nodo != -1){
            int i= 0;
            for(list<Node<T,A>> a : vertices){
                if(i == nodo){
                    cout<< (*a.begin()).dato << "-> ";
                    break;
                }
                i++;
            }
            DecrementaIndigree(matrix,indegree,nodo);
        }
    }while(nodo != -1);
}

string space(string a){
    string ans = a;
    for(int i=0;i<a.size();++i){
        if(a[i]==' ') ans[i] = '_';
    }
    return ans;
}

template<class T, class A>
T Grafo<T,A>::dist_minima(map<T,bool> visitados, map<T,int>distancias){
    int mini = INT_MAX;
    T ans;
    for (typename vector<list<Node<T,A>>>::iterator it = vertices.begin(); it!= vertices.end(); it++) {
        if(visitados[(*((it)->begin())).dato]==false && distancias[(*((it)->begin())).dato] <= mini){
            mini = distancias[(*((it)->begin())).dato];
            ans = (*((it)->begin())).dato ; 
        }
    }
    return ans;
}

template<class T, class A>
void Grafo<T,A>::dijkstra(map<T,bool> &visitados, map<T,int> &distancias, T src){
    for (typename vector<list<Node<T,A>>>::iterator it = vertices.begin(); it!= vertices.end(); it++) {
        distancias[(*((it)->begin())).dato] = INT_MAX;
        visitados[(*((it)->begin())).dato]  = false;
    }
    distancias[src] = 0;
    for (typename vector<list<Node<T,A>>>::iterator it2 = vertices.begin(); it2 != vertices.end(); it2++) {
        T val = dist_minima(visitados, distancias);
        
        visitados[val] = true;
        for (typename vector<list<Node<T,A>>>::iterator it2 = vertices.begin(); it2 != vertices.end(); it2++){
            if(!visitados[(*((it2)->begin())).dato] && existeArista((*((it2)->begin())).dato,val) && distancias[val]!=INT_MAX && distancias[val] + val_Arista((*((it2)->begin())).dato,val) < distancias[(*((it2)->begin())).dato])
            {
                distancias[(*((it2)->begin())).dato] = distancias[val] + val_Arista((*((it2)->begin())).dato, val);
            }
        }
    }

    cout << "Nodo: " << "\t\t\t\t\t\t\t\t\t\t" << "Distancia Minima: \n";
    for (typename vector<list<Node<T,A>>>::iterator it = vertices.begin(); it!= vertices.end(); it++){
        cout << (*((it)->begin())).dato << "\t\t\t\t\t\t\t\t\t"; distancias[(*((it)->begin())).dato]!=INT_MAX ? cout << distancias[(*((it)->begin())).dato] << "\n" : cout << "0" << "\n";
    }
    return;
}

template<class T, class A>
void Grafo<T,A>::dijkstra(T src){
    map<T, bool> visitados;
    map<T, int>  distancias;
    dijkstra(visitados, distancias, src); 
}   

template<class T, class A>
void Grafo<T,A>::print(ofstream &os) {
    for(list<Node<T,A>> a : vertices)
        os << (*a.begin()).dato << ";\n";
    for(list<Node<T,A>> a : vertices){
        for(Node<T,A> nodo : a){
            if( nodo.dato != (*a.begin()).dato ) 
                os << (*a.begin()).dato << "->" << nodo.dato << " [ label = " << nodo.ValArista << "];\n";
        }
    }
}


template<class T, class A>
void Grafo<T,A>::print(string file){
    ofstream os(file.c_str());
    os << "digraph G{\n";
    os << "label = Grafo;\n";
    os << "node [shape=circle color = black];\n";
    print(os);
    os << "}\n";
    os.close();
    system("dot Grafo.dot -o Grafo.png -Tpng");
    system("Grafo.png");
}
#endif
