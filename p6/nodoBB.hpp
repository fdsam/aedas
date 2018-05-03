#include "dni.hpp"

template<class T>
class nodoBB{
    private:
        T dato;
        nodoBB<T>* izquierdo;
        nodoBB<T>* derecho;
        
        static vector< vector<T> > arbol_mostrar;
    public:
        nodoBB(T dato_);
        nodoBB(nodoBB<T>* nodo);
        ~nodoBB();
        
        T get_dato();
        void set_dato(T dato_);
        nodoBB<T>* get_izquierdo();
        nodoBB<T>* get_derecho();
        void set_izquierdo(nodoBB<T>* nodo);
        void set_derecho(nodoBB<T>* nodo);
        nodoBB<T>* get_ultimo_izq(bool lado);
        nodoBB<T>* get_ultimo_dcha(bool lado);
        
        int buscar(T dato_);
        int insertar(T dato_);
        int eliminar(T dato_);
        int eliminar_0(bool lado);
        int eliminar_1(bool lado);
        int eliminar_2(bool lado);
        
        void mostrar_dato();
};

template<class T>
nodoBB<T>::nodoBB(T dato_){
    izquierdo = NULL;
    derecho = NULL;
    dato = dato_;
}

template<class T>
nodoBB<T>::nodoBB(nodoBB<T>* nodo){
    dato = nodo->dato;
    izquierdo = nodo->izquierdo;
    derecho = nodo->derecho;
}

template<class T>
nodoBB<T>::~nodoBB(){
    
}

template<class T>
T nodoBB<T>::get_dato(){
    return dato;
}

template<class T>
void nodoBB<T>::set_dato(T dato_){
    dato = dato_;
}

template<class T>
nodoBB<T>* nodoBB<T>::get_izquierdo(){
    return izquierdo;
}

template<class T>
nodoBB<T>* nodoBB<T>::get_derecho(){
    return derecho;
}

template<class T>
void nodoBB<T>::set_izquierdo(nodoBB<T>* nodo){
    izquierdo = nodo;
}

template<class T>
void nodoBB<T>::set_derecho(nodoBB<T>* nodo){
    derecho = nodo;
}

template<class T>
nodoBB<T>* nodoBB<T>::get_ultimo_izq(bool lado){
    nodoBB<T>* aux;
    aux = get_ultimo_dcha(lado);
    while(aux->get_izquierdo() != NULL)
        aux = aux->get_izquierdo();
    return aux;
}

template<class T>
nodoBB<T>* nodoBB<T>::get_ultimo_dcha(bool lado){
    nodoBB<T>* aux;
    nodoBB<T>* penultimo;
    if(lado == false){
        aux = izquierdo->get_izquierdo();
        if(aux->get_derecho() == NULL) izquierdo->set_izquierdo(NULL);
    }
    else{
        aux = derecho->get_izquierdo();
        if(aux->get_derecho() == NULL) derecho->set_izquierdo(NULL);
    }
    
    while(aux->get_derecho() != NULL){
        if(aux->get_derecho()->get_derecho() == NULL) penultimo = aux;
        aux = aux->get_derecho();
    }
    penultimo->set_derecho(NULL);
    return aux;
}

template<class T>
int nodoBB<T>::buscar(T dato_){
    if(dato == dato_) return 1;
    else{
        if(dato_ < dato){
            if(izquierdo == NULL) return 1;
            else return izquierdo->buscar(dato_)+1;
        }
        else{
            if(derecho == NULL) return 1;
            else return derecho->buscar(dato_)+1;
        }
    }
}

template<class T>
int nodoBB<T>::insertar(T dato_){
    if(dato_ < dato){
        if(izquierdo == NULL){
            izquierdo = new nodoBB<T>(dato_);
            return 1;
        }
        else return izquierdo->insertar(dato_)+1;
    }
    else{
        if(derecho == NULL){
            derecho = new nodoBB<T>(dato_);
            return 1;
        }
        else{
            return derecho->insertar(dato_)+1;
        }
    }
}

template<class T>
int nodoBB<T>::eliminar(T dato_){
    if(dato > dato_){ //vamos por la izquierda
        if(izquierdo == NULL) cout << " No encontrado" << endl;
        else{
            T aux = izquierdo->get_dato();
            if(aux == dato_) eliminar_0(0);
            else izquierdo->eliminar(dato_);
        }
    }
    else{
        if(derecho == NULL) cout << " No encontrado" << endl;
        else{
            T aux = derecho->get_dato();
            if(aux == dato_) eliminar_0(1);
            else derecho->eliminar(dato_);
        }
    }
}

template<class T>
int nodoBB<T>::eliminar_0(bool lado){
    if(lado == false){  //lado izquierdo
        if((izquierdo->get_izquierdo() == NULL) && (izquierdo->get_derecho() == NULL))
            izquierdo = NULL;
        else eliminar_1(lado);
    }
    else{  //lado derecho
        if((derecho->get_izquierdo() == NULL) && (derecho->get_derecho() == NULL))
            derecho = NULL;
        else eliminar_1(lado);
    }
}

template<class T>
int nodoBB<T>::eliminar_1(bool lado){
    if(lado == false){
        if(izquierdo->get_izquierdo() == NULL)
            izquierdo = izquierdo->get_derecho();
        else{
            if(izquierdo->get_derecho() == NULL)
                izquierdo = izquierdo->get_izquierdo();
            else eliminar_2(lado);
        }
    }
    else{
        if(derecho->get_izquierdo() == NULL)
            derecho = derecho->get_derecho();
        else{
            if(derecho->get_derecho() == NULL)
                derecho = derecho->get_izquierdo();
            else eliminar_2(lado);
        }
    }
}

template<class T>
int nodoBB<T>::eliminar_2(bool lado){
    nodoBB<T>* ultimo_dcha;
    nodoBB<T>* ultimo_izq;
    nodoBB<T>* aux;
    
    ultimo_dcha = get_ultimo_dcha(lado);
    ultimo_izq = get_ultimo_izq(lado);
    if(lado == false){
        ultimo_dcha->set_derecho(izquierdo->get_derecho());
        aux = izquierdo->get_izquierdo();
    }
    else{
        ultimo_dcha->set_derecho(derecho->get_derecho());
        aux = derecho->get_izquierdo();
    }
    izquierdo = ultimo_dcha;
    if(ultimo_izq != aux)
        ultimo_izq->set_izquierdo(aux);
}

template<class T>
void nodoBB<T>::mostrar_dato(){
    cout << dato;
}