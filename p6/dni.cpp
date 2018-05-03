#include "dni.hpp"
using namespace std;

DNI::DNI(){
    dni_.resize(8);
    for(int i = 0; i < 8; i++)
        dni_[i] = '0' + rand()%10;
    letra = 'A' + rand() % 24;
}

DNI::~DNI(){
    dni_.resize(0);
}

DNI DNI::operator= (const DNI a){
    dni_ = a.dni_;
    letra = a.letra;
    return *this;
}

ostream& operator<<(ostream &o,DNI &dato){
    o <<dato.letra<<"-"<< dato.dni_;
    return o;
}

bool DNI::operator< (const DNI a){
    int dummy = atoi(dni_.c_str()) + atoi(letra.c_str());
    int dummy2 = atoi(a.dni_.c_str()) + atoi(a.letra.c_str());
    return dummy < dummy2;
}

bool DNI::operator> (const DNI a){
    int dummy = atoi(dni_.c_str()) + atoi(letra.c_str());
    int dummy2 = atoi(a.dni_.c_str()) + atoi(a.letra.c_str());
    return dummy > dummy2;
}

bool DNI::operator ==(DNI a){
     int dummy = atoi(dni_.c_str()) + atoi(letra.c_str());
    int dummy2 = atoi(a.dni_.c_str()) + atoi(a.letra.c_str());
    return dummy == dummy2;
 
}

