#include "nodoAVL.hpp"

template<class T>
class AVL{
    private:
        nodoAVL<T>* nodo_raiz;
        //bool eliminar_raiz;
    public:
        AVL();
        ~AVL();
        
        nodoAVL<T>* get_raiz();
        void reset_raiz();
        
        int buscar(T clave);
        int busqueda(T clave, nodoAVL<T>* nodo);
        int insertar(T clave);
        int insercion(T clave, nodoAVL<T>* nodo, bool& crece);
      
        void mostrar_arbol();
        bool cola_null(queue< nodoAVL<T>* > miCola);
        
        //AVL
        int altura(nodoAVL<T>* nodo);
        
        bool balanceado();
        bool BalanceRama(nodoAVL<T>* nodo);
        void rotacion_II(nodoAVL<T>* nodo);
        void rotacion_DD(nodoAVL<T>* nodo);
        void rotacion_ID(nodoAVL<T>* nodo);
        void rotacion_DI(nodoAVL<T>* nodo);
        
        void insert_re_balancea_izda(nodoAVL<T>* nodo, bool& crece);
        void insert_re_balancea_dcha(nodoAVL<T>* nodo, bool& crece);
       
};

template<class T>
AVL<T>::AVL(){
    nodo_raiz = NULL;

}

template<class T>
AVL<T>::~AVL(){
    nodo_raiz = NULL;
}

template<class T>
nodoAVL<T>* AVL<T>::get_raiz(){
    return nodo_raiz;
}

template<class T>
void AVL<T>::reset_raiz(){
    nodo_raiz = NULL;
}

template<class T>
int AVL<T>::buscar(T clave){
    if(nodo_raiz == NULL) cout << "\nNo encontrado" << endl;
    else return busqueda(clave, nodo_raiz);
    return -1;
}

template<class T>
int AVL<T>::busqueda(T clave, nodoAVL<T>* nodo){
    if(nodo == NULL) return -INF;
    else{
        if(nodo->get_dato() == clave) return 1;
        else{
            if(clave < nodo->get_dato())
                return busqueda(clave, nodo->get_izquierdo())+1;
            else return busqueda(clave, nodo->get_derecho())+1;
        }
    }
}

template<class T>
int AVL<T>::insertar(T clave){
    bool crece = false;
    if(nodo_raiz == NULL)
        nodo_raiz = new nodoAVL<T>(clave);
    else{
        int cont = insercion(clave, nodo_raiz, crece)+1;
        // if(crece){
        //     if(clave < nodo_raiz->get_dato()) insert_re_balancea_izda(nodo_raiz->get_izquierdo(), crece);
        //     else insert_re_balancea_dcha(nodo_raiz->get_derecho(), crece);
        // }
        return cont;
    }
    return 1;   //si inserto en raiz devuelvo 1
}

template<class T>
int AVL<T>::insercion(T clave, nodoAVL<T>* nodo, bool& crece){
    if(clave < nodo->get_dato()){
        if(nodo->get_izquierdo() != NULL){
            int cont = insercion(clave, nodo->get_izquierdo(), crece)+1;
            //if(crece) insert_re_balancea_izda(nodo->get_izquierdo(), crece);
            return cont;
        }
        else{
            nodo->set_izquierdo_clave(clave);
            crece = true;
        }
        return 1;
    }
    else{
        if(nodo->get_derecho() != NULL){
            int cont = insercion(clave, nodo->get_derecho(), crece)+1;
            //if(crece) insert_re_balancea_dcha(nodo->get_derecho(), crece);
            return cont;
        }
        else{
            nodo->set_derecho_clave(clave);
            crece = true;
        }
        return 1;
    }
}

// void ArbolAVL::elimina_rama( nodoAVL* &nodo, int ClaveDada, bool& decrece) {
//     if (nodo == NULL) return;
//     if (clave_dada < nodo->clave) {
//         elimina_rama(nodo->izdo,clave_dada,decrece);
//         if (decrece)
//         eliminar_re_balancea_izda(nodo,decrece);
//     }
//     else{ 
//         if (clave_dada > nodo->clave) {
//             elimina_rama(nodo->dcho,clave_dada,decrece);
//             if (decrece) eliminar_re_balancea_dcha(nodo,decrece);
//         }
    
//         else { // nodo->clave == clave_dada(encontrado)
//             NodoAVL* Eliminado = nodo;
//             if(nodo->izdo == NULL){
//                 nodo = nodo->dcho;
//                 decrece = true;
//             }
//             else{ 
//                 if(nodo->dcho == NULL){
//                     nodo = nodo->izdo;
//                     decrece = true;
//                 }
//                 else{
//                     sustituye(Eliminado,nodo->izdo,decrece);
//                     if(decrece) eliminar_re_balancea_izda(nodo,decrece);
//                 }
//             }
//             delete Eliminado;
//         }
//     }
// }

// void ArbolAVL::sustituye(nodoAVL* &eliminado, nodoAVL* &sust, bool &decrece) {
//     if(sust->dcho != NULL){
//         sustituye(eliminado, sust->dcho, decrece);
//         if (decrece) eliminar_re_balancea_dcha(sust, decrece);
//     }
//     else{
//         eliminado->Info = sust->Info;
//         eliminado->Clave = sust->Clave;
//         eliminado = sust;
//         sust = sust->izdo;
//         decrece = true;
//     }
// }

template<class T>
void AVL<T>::mostrar_arbol(){
    cout << "\nÁrbol actual:" << endl;
    queue< nodoAVL<T>* > miCola;
    nodoAVL<T>* aux;
    
    if(nodo_raiz == NULL) cout << "\nVacío" << endl;
    else{
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
                aux = new nodoAVL<T>(miCola.front());
                aux->mostrar_dato();
            }
            else cout << "[.] ";
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
            else{
                miCola.push(NULL);
                miCola.push(NULL);
            }
            miCola.pop();
            if(cola_null(miCola)) break;
        }
        //altura
        cout << "\nAltura: " << altura(nodo_raiz) << endl;
        //balanceado?
        cout << "\nBalanceado: " << balanceado() << endl;
        //rotaDD
        // rotacion_DD(nodo_raiz);
        // rotacion_II(nodo_raiz);
        //rotacion_DI(nodo_raiz);
         //rotacion_ID(nodo_raiz);
    }
}

template<class T>
bool AVL<T>::cola_null(queue< nodoAVL<T>* > miCola){
    while(!miCola.empty()){
        if(miCola.front() != NULL) return false;
        miCola.pop();
    }
    return true;
}

template<class T>
int AVL<T>::altura(nodoAVL<T>* nodo){
    if(nodo->get_izquierdo() == NULL){
        if(nodo->get_derecho() == NULL) return 1;
        else return altura(nodo->get_derecho())+1;
    }
    else{
        if(nodo->get_derecho() == NULL) return altura(nodo->get_izquierdo())+1;
        else{
            if(altura(nodo->get_izquierdo()) > altura(nodo->get_derecho())) return altura(nodo->get_izquierdo())+1;
            else return altura(nodo->get_derecho())+1;
        }
    }
}

template<class T>
bool AVL<T>::balanceado(){
    return BalanceRama(nodo_raiz);
}

template<class T>
bool AVL<T>::BalanceRama(nodoAVL<T>* nodo) {
    if(nodo == NULL) return true;
    
    int altura_i, altura_d;
    if(nodo->get_izquierdo() == NULL) altura_i = 0;
    else altura_i = altura(nodo->get_izquierdo());
    if(nodo->get_derecho() == NULL) altura_d = 0;
    else altura_d = altura(nodo->get_derecho());
    int balance = altura_i - altura_d;
    
    switch(balance){
        case -1:
        case 0:
        case 1: return BalanceRama(nodo->get_izquierdo()) && BalanceRama(nodo->get_derecho());
        default: return false ;
    }
}

template<class T>
void AVL<T>::rotacion_II(nodoAVL<T>* nodo){
    cout << "rot_II: " << endl;
    nodoAVL<T>* nodo1 = nodo->get_izquierdo();
    nodo->set_izquierdo(nodo1->get_derecho());
    nodo1->set_derecho(nodo);
    if(nodo1->get_bal() == 1) {
        nodo->set_bal(0);
        nodo1->set_bal(0);
    }
    else { // nodo1->bal == 0
        nodo->set_bal(1);
        nodo1->set_bal(-1);
    }
    nodo = nodo1;
}

template<class T>
void AVL<T>::rotacion_DD(nodoAVL<T>* nodo){
    cout << "rot_DD: " << endl;
    nodoAVL<T>* nodo1 = nodo->get_derecho();
    nodo->set_derecho(nodo1->get_izquierdo());
    nodo1->set_izquierdo(nodo);
    if(nodo1->get_bal() == -1) {
        nodo->set_bal(0);
        nodo1->set_bal(0);
    }
    else { // nodo1->bal == 0
        nodo->set_bal(-1);
        nodo1->set_bal(1);
    }
    nodo = nodo1;
}

template<class T>
void AVL<T>::rotacion_ID(nodoAVL<T>* nodo){
    cout << "rot_ID: " << nodo->get_izquierdo()->get_dato() << endl;
    nodoAVL<T>* nodo1 = nodo->get_izquierdo();
    nodoAVL<T>* nodo2 = nodo1->get_derecho();
    if(nodo2 != NULL){
        nodo->set_izquierdo(nodo2->get_derecho());  //error aqui
        nodo2->set_derecho(nodo);
    
        nodo1->set_derecho(nodo2->get_izquierdo());
        nodo2->set_izquierdo(nodo1);
    
        cout << "\nwefsd" << endl;
        
        if(nodo2->get_bal() == -1) nodo1->set_bal(1);
        else nodo1->set_bal(0);
        
        if(nodo2->get_bal() == 1) nodo->set_bal(-1);
        else nodo->set_bal(0);
        
        nodo2->set_bal(0);
        nodo = nodo2;
    }
}

template<class T>
void AVL<T>::rotacion_DI(nodoAVL<T>* nodo){
    cout << "rot_DI: " << endl;
    nodoAVL<T>* nodo1 = nodo->get_derecho();
    nodoAVL<T>* nodo2 = nodo1->get_izquierdo();

    if(nodo2 != NULL){
        nodo->set_derecho(nodo2->get_izquierdo());
        nodo2->set_izquierdo(nodo);
        nodo1->set_izquierdo(nodo2->get_derecho());
        nodo2->set_derecho(nodo1);
        cout << "\ndentro" << endl;
        if(nodo2->get_bal() == 1) nodo1->set_bal(-1);
        else nodo1->set_bal(0);
        
        if(nodo2->get_bal() == -1) nodo->set_bal(1);
        else nodo->set_bal(0);
        
        nodo2->set_bal(0);
        nodo = nodo2;
    }
}

template<class T>
void AVL<T>::insert_re_balancea_izda(nodoAVL<T>* nodo, bool& crece){
    cout << "\ninsert iz"<< endl;
    cout << "nodo->bal: " << nodo->get_bal() << endl;
    switch(nodo->get_bal()){
        case -1: nodo->set_bal(0);
                 crece = false;
                 break;
        case 0: nodo->set_bal(1);
                break;
        case 1: if(nodo->get_izquierdo()->get_bal() == 1)
                    rotacion_II(nodo);
                else rotacion_ID(nodo);
                crece = false;
    }
    cout << "\nFin insert iz" << endl;
}

template<class T>
void AVL<T>::insert_re_balancea_dcha(nodoAVL<T>* nodo, bool& crece){
    cout << "\ninsert dc"<< endl;
    cout << "nodo->bal: " << nodo->get_bal() << endl;
    switch(nodo->get_bal()){
        case 1: nodo->set_bal(0);
                 crece = false;
                 break;
        case 0: nodo->set_bal(-1);
                break;
        case -1: if(nodo->get_derecho()->get_bal() == -1)
                    rotacion_DD(nodo);
                else rotacion_DI(nodo);
                crece = false;
    }
    cout << "\nFin insert dc" << endl;
}
