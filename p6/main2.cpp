#include "ABB.hpp"

int main(void){
    // ABB<Matricula>* miArbol;
    // miArbol = new ABB<Matricula>();
    ABB<int>* miArbol;
    miArbol = new ABB<int>();
    
    int opc;
    do{
        cout << "\n0) Salir\n1) Insertar\n2) Eliminar\n3) Mostrar árbol" << endl;
        cin >> opc;
        int numeros;
        string letras;
        switch(opc){
            case 0: break;
            case 1:{ int num;
                    cout << "\nNúmero: ";
                    cin >> num;
                    miArbol->insercion(num);
                    //Matricula miMatricula;
                    //cout << "\nInsertando " << miMatricula << " en nivel: " << miArbol->insercion(miMatricula) << endl;
                    break;
                    }
            case 2:{ cout << "\nNúmero: ";
                    cin >> numeros;
                    // cout << "\nLetras: ";
                    // cin >> letras;
                    //Matricula miMatricula2(numeros, letras);
                    if(miArbol->get_raiz()->get_dato() == numeros){
                        int i = miArbol->eliminacion(numeros);
                        if(i == -1) miArbol->reset_raiz();
                    }
                    else miArbol->eliminacion(numeros);
                    break;
                    }
            case 3: miArbol->mostrar_arbol(); break;
            default: cout << "\nERROR.Opción incorrecta" << endl;
        }
    }while(opc != 0);
    return 0;
}






