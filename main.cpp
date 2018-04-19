#include "dni.h"
#include "metodos.h"
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#define MIN 999999999
#define MAX 0
using namespace std;

int main(){
    srand (time(NULL));
    Metodos<DNI>* A;//en plantillas puntero por la derecha del tipo que pasamos
    Metodos<DNI>* B;
    int size,opcion = 10;
    int opc_mix = 10;
    int comparacion = 0;
    int numero_pruebas = 10;
    int modo =1;
    while(opc_mix != 0){
    
     cout << "------------ALGORITMO DE ORDENACION-----------------"<< endl; 
        cout << endl; 
        cout << "1-MODO DEMOSTRACIÓN" << endl;
        cout << endl;
        cout << "2-MODO ESTADÍSTICO" << endl;
        cout << endl;
        cout << "0-FIN DEL PROGRAMA" << endl;
        
        
        cout << "Seleccione: ";
        cin >> opcion; // Lectura de la opción introducida por el usuario.
        
    switch(opcion){
        case 1:{
    cout << "Introduzca el tamaño del vector" << endl;
    cin >> size;
    comparacion = 0;
    while(opcion > 0){
    cout << "Que metodo desea escoger" << endl;
    cout << "0-Salir" << endl;
    cout << "1-Inserccion" << endl;
    cout << "2-HeapShort" << endl;
    cout << "3-Shellsort" << endl;
    cout << "4-Quicksort" << endl;
    cout << "5-Mergesort" << endl;
    cout << endl << "Opcion: ";
    cin >> opcion;

    A = new Metodos<DNI>(opcion,size,comparacion,modo,comparacion,comparacion);

    }
break;
}
    
    
    case 2:{
    
    modo = 0;
    
    cout << endl << endl << "\t\t-----------Estadisticas Ejecucion--------------" << endl << endl;
    
    int comp = 0;
     int comparaciones_min = MIN; // Variable para almacenar el número mínimo de comparaciones.
    int comparaciones_max = MAX; // Variable para almacenar el número máximo de comparaciones.
     cout << "-------------------------- COMPARACIONES -------------------------- "<< endl;
                cout<<"      " <<  "Mínimo"  <<"       "<< "Medio"  <<"      "<< "Máximo" << endl;
    
        cout <<"introduce el numero de pruebas del algoritmo"<<endl;
        cin >> size;
    
    
         //------------------------------------------- INSERCIÓN -------------------------------------------
        B = new Metodos<DNI>(1,size,comparacion,modo,comparaciones_max,comparaciones_min);
         
                
         cout<<"Inserción:"<<comparaciones_min<<"  "<<comparacion / size <<"  "<<comparaciones_max<<endl;
                
         //------------------------------------------- HeapShort -------------------------------------------
           B = NULL;
                comparacion = 0;
                comparaciones_max = MAX;
                comparaciones_min = MIN;
         
       B = new Metodos<DNI>(2,size,comparacion,modo,comparaciones_max,comparaciones_min);
        
            
        cout<<"Inserción:"<<comparaciones_min<<"  "<<comparacion / size <<"  "<<comparaciones_max<<endl;
       
         //------------------------------------------- SHELLSORT -------------------------------------------
              
              B = NULL;
                comparacion = 0;
                comparaciones_max = MAX;
                comparaciones_min = MIN;
        B = new Metodos<DNI>(3,size,comparacion,modo,comparaciones_max,comparaciones_min);
       
         cout<<"Inserción:"<<comparaciones_min<<"  "<<comparacion / size <<"  "<<comparaciones_max<<endl;
         //------------------------------------------- QUICKSORT -------------------------------------------
               B = NULL;
                comparacion = 0;
                comparaciones_max = MAX;
                comparaciones_min = MIN;
        B = new Metodos<DNI>(4,size,comparacion,modo,comparaciones_max,comparaciones_min);
       
        cout<<"Inserción:"<<comparaciones_min<<"  "<<comparacion / size <<"  "<<comparaciones_max<<endl;
         //------------------------------------------- MERGESORT -------------------------------------------
              B = NULL;
                comparacion = 0;
                comparaciones_max = MAX;
                comparaciones_min = MIN;
        B = new Metodos<DNI>(5,size,comparacion,modo,comparaciones_max,comparaciones_min);
      
        cout<<"Inserción:"<<comparaciones_min<<"  "<<comparacion / size <<"  "<<comparaciones_max<<endl;
        
    }
        
    }//switch opc;
}//end opc main
 
}
