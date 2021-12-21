#ifndef _NODE_H_
#define _NODE_H_
template <class T, class A>
class Grafo;

template <class T, class A>
class Node{
private:
    A ValArista;
    T dato;
    friend class Grafo<T,A>;
public:
    Node(T,A);
    Node(T);
    ~Node();
};

template <class T, class A>
Node<T,A>::Node(T dato, A valAr){
    this->dato = dato;
    this->ValArista = valAr;
}

template <class T, class A>
Node<T,A>::Node(T dato){
    this->dato = dato;
}

template <class T, class A>
Node<T,A>::~Node()
{
}

#endif
