#include "AVL.hpp"

int main(void){
    int N, nPruebas;
    cout << "\nIntroduzca tamaño del árbol: ";
    cin >> N;
    cout << "\nIntroduzca número de pruebas: ";
    cin >> nPruebas;
    vector<DNI> misDNI;
    for(int i = 0; i < 2*N; i++){
        DNI aux;
        cout << "\nIntroduciendo " << aux << " en banco de pruebas" << endl;
         misDNI.push_back(aux);
        //sleepcp(1000);
    }
    AVL<DNI>* miArbol = new AVL<DNI>();
    
    for(int i = 0; i < N; i++)
        miArbol->insertar(misDNI[i]);
    
    int minimo = INF;
    int maximo = -INF;
    int medio;
    int suma = 0;
    
    cout << "\nBuscando insertados..." << endl;
    for(int i = 0; i < nPruebas; i++){
         int cont = miArbol->buscar(misDNI[rand()%N]);

        suma += cont;
        if(cont > maximo) maximo = cont;
        if(cont < minimo) minimo = cont;
    }
    medio = suma/nPruebas;
    
    cout << "\n          N  P  Minimo Medio Maximo" << endl;
    cout << "Búsqueda  " << N << "  " << nPruebas << "    "<< minimo << "      " << medio << "     " << maximo << endl;
    /*
    minimo = INF;
    maximo = -INF;
    suma = 0;
    cout << "\nBuscando no insertados..." << endl;
    for(int i = 0; i < nPruebas; i++){
        int random = rand()%N+N;
        int cont = miArbol->buscar(misDNI[random]);
        
        suma += cont;
        if(cont > maximo) maximo = cont;
        if(cont < minimo) minimo = cont;
    }
    medio = suma/nPruebas;
    
    cout << "\n          N  P  Minimo Medio Maximo" << endl;
    cout << "Inserción " << N << "  " << nPruebas << "    "<< minimo << "      " << medio << "     " << maximo << endl;*/
}