#include<iostream>
#include <string>
#include <stdlib.h>
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

    int operator %(int operando); // Sobrecarga del operador % para realizar operaciones de módulo.
    bool operator ==(DNI& operando); // Sobrecarga del operador == para realizar comparaciones entre DNI.
    bool operator ==(int operando); // Sobrecarga del operador == para comparar DNI con enteros.
    DNI operator= ( DNI a);
    bool operator< (const DNI a);
    bool operator> (const DNI a);
    friend ostream& operator<< (ostream &o,DNI &dato);
    //sobrecargar operadores
    //y tambien entrada salida
};

#endif // DNI_H
