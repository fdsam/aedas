#include "nodoBB.hpp"

template<class T>
class ABB{
    private:
        nodoBB<T>* nodo_raiz;
    public:
        ABB();
        ~ABB();
        
        nodoBB<T>* get_raiz();
        void reset_raiz();
        
        nodoBB<T>* get_ultimo_izq();
        nodoBB<T>* get_ultimo_dcha();
        
        int busqueda(T clave);
        int insercion(T clave);
        int eliminacion(T clave);
        int eliminar_0();
        int eliminar_1();
        int eliminar_2();
        void mostrar_arbol();
};

template<class T>
ABB<T>::ABB(){
    nodo_raiz = NULL;
}

template<class T>
ABB<T>::~ABB(){
    nodo_raiz = NULL;
}

template<class T>
nodoBB<T>* ABB<T>::get_raiz(){
    return nodo_raiz;
}

template<class T>
void ABB<T>::reset_raiz(){
    nodo_raiz = NULL;
}

// template<class T>
// nodoBB<T>* ABB<T>::get_ultimo_izq(){
//     nodoBB<T>* aux;
//     aux = get_ultimo_dcha(lado);
//     while(aux->get_izquierdo() != NULL)
//         aux = aux->get_izquierdo();
//     return aux;
// }

// template<class T>
// nodoBB<T>* ABB<T>::get_ultimo_dcha(){
//     nodoBB<T>* aux;
//     nodoBB<T>* penultimo;
    
//     aux = izquierdo->get_izquierdo();
//     if(aux->get_derecho() == NULL) izquierdo->set_izquierdo(NULL);

//     aux = derecho->get_izquierdo();
//     if(aux->get_derecho() == NULL) derecho->set_izquierdo(NULL);
    
//     while(aux->get_derecho() != NULL){
//         if(aux->get_derecho()->get_derecho() == NULL) penultimo = aux;
//         aux = aux->get_derecho();
//     }
//     penultimo->set_derecho(NULL);
//     return aux;
// }

template<class T>
int ABB<T>::busqueda(T clave){
    if(nodo_raiz != NULL)
        return nodo_raiz->buscar(clave);
    else
        return 0;
}

template<class T>
int ABB<T>::insercion(T clave){
    if(nodo_raiz == NULL){
        nodo_raiz = new nodoBB<T>(clave);
        return 1;
    }
    else return nodo_raiz->insertar(clave)+1;
}

template<class T>
int ABB<T>::eliminacion(T clave){
    if(nodo_raiz == NULL) cout << "\nNo encontrado" << endl;
    else{
        if(nodo_raiz->get_dato() != clave){
            T dato = nodo_raiz->get_dato();
            if(dato == clave){
                nodo_raiz->eliminar(clave);
            }
            nodo_raiz->eliminar(clave);
        }
        else{
            eliminar_0();
        }
    }
}

template<class T>
int ABB<T>::eliminar_0(){
    if((nodo_raiz->get_izquierdo() == NULL) && (nodo_raiz->get_derecho() == NULL))
        return -1;
    else eliminar_1();
}

template<class T>
int ABB<T>::eliminar_1(){
    if(nodo_raiz->get_izquierdo() == NULL) //derecho tiene que tener dato
        nodo_raiz = nodo_raiz->get_derecho();

    else{
        if(nodo_raiz->get_derecho() == NULL)
            nodo_raiz = nodo_raiz->get_izquierdo();
        // else
        //     eliminar_2();
    }
}

// template<class T>
// int ABB<T>::eliminar_2(){
//     nodoBB<T>* ultimo_dcha;
//     nodoBB<T>* ultimo_izq;
//     nodoBB<T>* aux;
    
//     ultimo_dcha = get_ultimo_dcha(lado);
//     ultimo_izq = get_ultimo_izq(lado);
//     if(lado == false){
//         ultimo_dcha->set_derecho(izquierdo->get_derecho());
//         aux = izquierdo->get_izquierdo();
//     }
//     else{
//         ultimo_dcha->set_derecho(derecho->get_derecho());
//         aux = derecho->get_izquierdo();
//     }
//     izquierdo = ultimo_dcha;
//     if(ultimo_izq != aux)
//         ultimo_izq->set_izquierdo(aux);
// }

template<class T>
void ABB<T>::mostrar_arbol(){
    queue< nodoBB<T>* > miCola;
    nodoBB<T>* aux;
    
    miCola.push(nodo_raiz);
    int cont = 0;
    int multiplo = 1;
    bool cambia = true;
    int i = 1;
    while(!miCola.empty()){
        if(cambia)
            cout << "\nNivel " << i << ":       ";
        cambia = false;
        if(miCola.front() != NULL){
            aux = new nodoBB<T>(miCola.front());
            aux->mostrar_dato(); 
        }
        else cout << "    [.]     ";
        cout << " ";
        cont++;
        if(cont == multiplo){
            multiplo = multiplo*2;
            cambia = true;
            i++;
            cont = 0;
        }
        if(miCola.front() != NULL){
            if(aux->get_izquierdo() != NULL)
                miCola.push(aux->get_izquierdo());
            else miCola.push(NULL);
            
            if(aux->get_derecho() != NULL)
                miCola.push(aux->get_derecho());
            else miCola.push(NULL);
        }
        miCola.pop();
    }
}