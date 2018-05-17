#include "dni.hpp"

template<class T>
class nodoAVL{
    private:
        T dato;
        nodoAVL<T>* izquierdo;
        nodoAVL<T>* derecho;
        int bal;
        
    public:
        nodoAVL();
        nodoAVL(T dato_);
        nodoAVL(nodoAVL<T>* nodo);
        ~nodoAVL();
        
        T get_dato();
        void set_dato(T dato_);
        int get_bal();
        void set_bal(int bal_);
        nodoAVL<T>* get_izquierdo();
        nodoAVL<T>* get_derecho();
        void set_izquierdo(nodoAVL<T>* nodo);
        void set_izquierdo_clave(T clave);
        void set_derecho(nodoAVL<T>* nodo);
        void set_derecho_clave(T clave);
        
        void mostrar_dato();
};

template<class T>
nodoAVL<T>::nodoAVL(){}

template<class T>
nodoAVL<T>::nodoAVL(T dato_){
    izquierdo = NULL;
    derecho = NULL;
    dato = dato_;
    bal = 0;
}

template<class T>
nodoAVL<T>::nodoAVL(nodoAVL<T>* nodo){
    dato = nodo->get_dato();
    izquierdo = nodo->get_izquierdo();
    derecho = nodo->get_derecho();
}

template<class T>
nodoAVL<T>::~nodoAVL(){}

template<class T>
T nodoAVL<T>::get_dato(){
    return dato;
}

template<class T>
void nodoAVL<T>::set_dato(T dato_){
    dato = dato_;
}

template<class T>
int nodoAVL<T>::get_bal(){
    return bal;
}

template<class T>
void nodoAVL<T>::set_bal(int bal_){
    bal = bal_;
}

template<class T>
nodoAVL<T>* nodoAVL<T>::get_izquierdo(){
    return izquierdo;
}

template<class T>
nodoAVL<T>* nodoAVL<T>::get_derecho(){
    return derecho;
}

template<class T>
void nodoAVL<T>::set_izquierdo(nodoAVL<T>* nodo){
    izquierdo = nodo;
}

template<class T>
void nodoAVL<T>::set_izquierdo_clave(T clave){
    izquierdo = new nodoAVL<T>(clave);
}

template<class T>
void nodoAVL<T>::set_derecho(nodoAVL<T>* nodo){
    derecho = nodo;
}

template<class T>
void nodoAVL<T>::set_derecho_clave(T clave){
    derecho = new nodoAVL<T>(clave);
}

template<class T>
void nodoAVL<T>::mostrar_dato(){
    cout << dato;
}