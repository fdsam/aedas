#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

#define INF 999999
#ifndef DNI_H
#define DNI_H
typedef long CLAVE;

using namespace std;

class DNI{
   
private:
   string dni_;
   string letra;
   char x;
public:
    DNI();
    ~DNI();
    string get_dni();
    string get_letra();

    int operator %(int operando); // Sobrecarga del operador % para realizar operaciones de módulo.
    //bool operator ==(DNI& operando); // Sobrecarga del operador == para realizar comparaciones entre DNI.
    bool operator ==(DNI a); // Sobrecarga del operador == para comparar DNI con enteros.
    //friend bool operator ==(DNI &DNI_, DNI &DNI_2);
    DNI operator= (DNI a);
    bool operator< (const DNI a);
    bool operator> (const DNI a);
    friend ostream& operator<< (ostream &o,DNI &dato);
    //sobrecargar operadores
    //y tambien entrada salida
};

#endif // DNI_H
