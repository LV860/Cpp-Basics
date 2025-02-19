/******************************************************************************
Autores:
Leonardo Velazquez Colin

Descripcion:
Este programa muestra la suma de los números pares del 1 al 20.  
Además, imprime la serie de suma paso a paso en pantalla.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int suma = 0; // Se inicializa la variable para almacenar la suma de los pares.

    cout << "Bienvenido" << endl;
    for (int i = 1; i <= 20; i++) { // Se hace un bucle del 1 al 20.
        if (i % 2 == 0) { // Se verifica si el número es par.
            cout << i; // Se muestra el número en pantalla.

            if (i < 20) { // Se imprime el signo "+" excepto en el último número.
                cout << " + ";
            }

            suma = suma + i; // Se acumula la suma de los números pares.
        }
    }

    cout << " = " << suma << endl; // Se muestra el resultado final.

    return 0;
}
