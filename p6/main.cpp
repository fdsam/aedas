#include "ABB.hpp"

int main(void){
    int N ,nPruebas;
     cout << "\nIntroduzca tamaño del árbol: ";
    cin >> N;
    cout << "\nIntroduzca número de pruebas: ";
    cin >> nPruebas;
    vector<DNI> Misdni;
    for(int i = 0; i < 2*N; i++){
        DNI aux;
        cout << "\nIntroduciendo " << aux << " en banco de pruebas" << endl;
        Misdni.push_back(aux);
    }
    
      ABB<DNI>* Arboles;
   Arboles = new ABB<DNI>();
   
    for(int j=0;j<N;j++){
        Arboles -> insercion(Misdni[j]);
    }
    
    int maximo = -INF;
    int minimo = INF;
    int medio;
    int suma = 0;
    
    cout << "\nBuscando insertados..." << endl;
    for(int i=0;i<nPruebas;i++){
        int cont = Arboles -> busqueda(Misdni[rand() % N]);
          suma += cont;
        if(cont > maximo) maximo = cont;
        if(cont < minimo) minimo = cont;
    }
    
    medio = suma/nPruebas;
    cout << "\n          N  P  Minimo Medio Maximo" << endl;
    cout << "Búsqueda  " << N << "  " << nPruebas << "    "<< minimo << "      " << medio << "     " << maximo << endl;
    
    minimo = INF;
    maximo = -INF;
    suma = 0;

    for(int i = 0; i < nPruebas; i++){
        int random = rand()%N+N;
        int cont = Arboles->busqueda(Misdni[random]);
        suma += cont;
        if(cont > maximo) maximo = cont;
        if(cont < minimo) minimo = cont;
    }
    medio = suma/nPruebas;
    
    cout << "\n          N  P  Minimo Medio Maximo" << endl;
    cout << "Inserción " << N << "  " << nPruebas << "    "<< minimo << "      " << medio << "     " << maximo << endl;
}