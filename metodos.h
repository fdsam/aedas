#include <stdlib.h>
#include <stdio.h>
#include <iostream>


typedef long CLAVE;
using namespace std;

//PLANTILLA
#ifndef METODOS_H
#define METODOS_H

template <class T>

class Metodos{

private:
     int size_;
     T* vector_;

public:
     //Constructor y Destructor
    Metodos();
    Metodos(int opcion,int size,int &comparacion,int modo,int &max,int &min);
    ~Metodos();

    
    T get_v();
   // void set_v(int x);
    
    //Metodos de ordenacion
    void Inserccion(T *vector,int &comparar,int modo,int &max,int &min);

    void HeapShort(T *vector,int n,int &comparar,int modo,int &max,int &min);
    
    void baja( int i , T *vector, int n,int comparar,int modo);

    void MergeSort(T *vector, int ini, int fin,int &comparar,int modo,int &max,int &min);
    
    void Mezcla(T *vector, int ini, int cen, int fin);

    void ShellSort(T *vector,int &comparar,int modo,int &max,int &min);
    
    void Deltasort(T *vector, int del, int size_);

    void QuickSort(T *vector, int ini, int fin,int &comparar,int modo,int &max,int &min);

    //Menu()
    void Menu(int opcion, T *vector,int &compara,int modo,int &max,int &min);
};

#endif // METODOS_H

//     .cpp

template <class T>

T Metodos<T>::get_v(){
    return vector_;
}



template <class T>
Metodos<T>::Metodos(){

    size_=0;
    vector_=NULL;
}

template <class T>
Metodos<T>::Metodos(int opcion,int size,int &comparacion,int modo,int &max,int &min){

    int opcion1=opcion;
    size_= size;
    T vector[size_];

 
    
    max = 0;
    min = 999999;
    comparacion = 0;
    Menu(opcion1,vector,comparacion,modo,max,min);
}

template <class T>Metodos<T>::~Metodos(){
    size_=0;
    delete [] vector_;
    vector_=NULL;
}

template <class T>
void Metodos<T>::Menu(int opcion, T *vector,int &compara,int modo,int &max,int &min){

    if(opcion==0)
        return;
    if (modo == 2){

    cout<<endl <<"------VECTOR SIN ORDENAR------"<<endl;
    for(int i=0;i<size_;i++){
        cout<< vector[i]<<" , ";
    }
}
    if(opcion==1){
        cout<<endl<<endl <<"------ INSERCCION------"<<endl;
        Inserccion(vector,compara,modo,max,min);
    }
    if(opcion==2){
        cout<<endl<<endl <<"------ HeapShort------"<<endl;
        HeapShort(vector,size_,compara,modo,max,min);
    }
    if(opcion==3){
         cout<<endl<<endl <<"------ SHELLSORT------"<<endl;
        ShellSort(vector,compara,modo,max,min);
    }
    if(opcion==4){
        cout<<endl<<endl <<"------ QUICKSORT------"<<endl;
        QuickSort(vector,0,size_,compara,modo,max,min);
    }
    if(opcion==5){
        cout<<endl<<endl <<"------ MERGESORT------"<<endl;
        MergeSort(vector,0,size_,compara,modo,max,min);
    }

}
/*--------------------------------------------------------------------------*/
template <class T>
void Metodos<T>::baja( int i , T *vector , int n,int comparar,int modo){
    int h =0;
     T x;
     x = vector[i];
    while ( 2*i <= n ){ 
     int h1 = 2*i ;
    int h2 = h1 + 1 ;
             if (h1 == n)
         h = h1;
    else if (vector[h1] > vector[h2])
         h = h1;
    else
       h = h2;
    if (vector[h] < x)
    break ;
    else{
        vector[i] = vector[h];
    vector[h] = x ;
    i = h ;
    }
}

    comparar ++;
    if(modo == 1){
 for(int j=0;j<size_;j++){
            cout << vector[j] <<" , ";
        }
        cout<<endl;
    }  
}
 
template <class T>
void Metodos<T>::HeapShort(T *vector,int n,int &comparar,int modo,int &max,int &min){
    T x;
    int total;
  for (int i = n/2; i > 0; i--){
    baja(i, vector, n,comparar,modo);
    //comparar ++;
    total++;
    for (int i = n; i > 1; i--){ 
        x = vector[1];
    vector[1] = vector[i];
    vector[i] = x;
    baja(1,vector,i-1,comparar,modo);
    //comparar ++;
    total ++;
    } 
  }
    if (total < min) 
        min = total;
	if (total > max) 
		max = total;
		comparar += total;
	
}

template <class T>
void Metodos<T>::Inserccion(T *vector,int &comparar,int modo,int &max,int &min){

    T aux;
    int total; //contador
         int j;
   for (int i = 1; i < size_; i++){
       aux = vector[i];
       j = i-1;

       while (j >= 0 && vector[j] > aux){
           vector[j+1] = vector[j];
           j = j-1;
           total++;
       }
       vector[j+1] = aux;
   

        if(modo == 1){
            
        for(int i=0;i<size_;i++){
            cout<< vector[i]<<" , ";
        }
        cout<<endl;
        
    cout<<endl;
        }
    }
    
         if (total < min) 
        min = total;
	if (total > max) 
		max = total;
		comparar += total;
        
}

template <class T>
void Metodos<T>::MergeSort(T *vector, int ini, int fin,int &comparar,int modo,int &max,int &min){
    int total;
    if (ini<fin){
        int cen=((ini+fin)/2);
        MergeSort(vector,ini,cen,comparar,modo,max,min);
        total ++;
        MergeSort(vector,cen+1,fin,comparar,modo,max,min);
        total ++;
        Mezcla(vector,ini,cen,fin);

        //comparar ++;
        if(modo == 1){
        for(int j=0;j<size_;j++){
            cout << vector[j] <<" , ";
        }
        cout<<endl;
        }
    }
 if (total < min) 
        min = total;
	if (total > max) 
		max = total;
		comparar += total;
}

template <class T>
void Metodos<T>::Mezcla(T* vector,int ini,int cen,int fin){
    int i = ini ;
    int j = cen + 1 ;
    int k = ini;
    T aux[size_];
    while((i<=cen) && (j<=fin)){
        if (vector[i] < vector[j]){
            aux[k] = vector[i];
            i++;
        }
        else{
            aux[k] = vector[j];
            j++;
        }
        k++;
    }
    if( i>cen)
        while (j<=fin){
            aux[k] = vector[j];
            j++;
            k++;
        }
    else
        while (i<=cen){
            aux[k] = vector[i];
            i++;
            k++;
        }
    for (int g=ini;g<=fin;g++){
        vector[g]=aux[g];
    }
    cout << endl;
}

template <class T>
void Metodos<T>::ShellSort(T *vector,int &comparar,int modo,int &max,int &min){
    int del;
    int total;
    del = size_;
    while (del > 1){
        del=del/2;
        Deltasort(vector,del,size_);
      //comparar++;
      total++;
      if(modo == 1){
        for(int j=0;j<size_;j++){
            cout << vector[j] <<" , ";
        }
        cout << endl;
     }
    }
    if (total < min) 
        min = total;
	if (total > max) 
		max = total;
		comparar += total;

}

template <class T>
void Metodos<T>::Deltasort(T* vector,int del, int size_){
    int j;
    T aux;
    for(int i= del + 1; i <= size_; i++){
        aux = vector[i];
        j=i;

        while((j > del)&&( aux < vector[j - del])){
            vector[j]=vector[j - del];
            j = j - del;
        }
        vector[j] = aux;
    }
}

template <class T>
void Metodos<T>::QuickSort(T *vector, int ini, int fin,int &comparar,int modo,int &max,int &min){
    T aux;
    int total;
    int i=ini;
    int f=fin;
    T p=vector[(i+f)/2];

    while(i<f){
        while(vector[i]<p){
            i++;
            //comparar ++;
        }
        while(vector[f]>p){
            f--;
            //comparar ++;
        }
        if (i<=f){
            aux= vector[i];
            vector[i]=vector[f];
            vector[f]=aux;
            i++;
            f--;
        }
    }
  if(modo == 1){
    for(int j=0;j<size_;j++){
        cout << vector[j] <<" , ";
    }
    cout << endl;
}
    if (ini < f){
        QuickSort(vector,ini,f,comparar,modo,max,min);
    if (i< fin)
        QuickSort(vector,i,fin,comparar,modo,max,min);
    }
      if (min == -1) 
        min = total;
		if (total > max) 
		max = total;
		comparar += total;
		if (total < min) min = total;
}
