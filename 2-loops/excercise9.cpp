/**************************
Autores:
Leonardo Velazquez Colin
Oscar Alejandro Rodriguez Gomez
Juan David Torres Chaparro

Descripcion:
Este programa imprime una figura en forma de diamante con asteriscos (*).
Se construye primero la parte superior del diamante y luego la parte inferior,
usando bucles anidados para controlar los espacios y los asteriscos en cada línea.

***************************/

#include <iostream>

using namespace std;

int main()
{
    int i = 0, x = 0;
    cout << "Bienvenido" << endl;

    // Parte superior del diamante
    while (x <= 4) {
        // Imprime espacios
        while (i <= (5 - x)) {
            cout << " ";
            i++;
        }
        i = 0;

        // Imprime asteriscos
        while (i <= (x * 2)) {
            cout << "*";
            i++;
        }
        i = 0;

        cout << endl; // Salto de línea para la siguiente fila
        x++;
    }

    /*
    Construcción de la parte superior del diamante:

    1. Se inicia con x = 0.
    2. Mientras x sea menor o igual a 4:
        - Se imprimen espacios (5 - x).
        - Se imprimen asteriscos (*), la cantidad es (x * 2) + 1.
        - Se incrementa x en 1 para la siguiente línea.
    3. Se repite el ciclo hasta completar la parte superior del diamante.
    */

    x = 3; // Iniciamos desde el segundo nivel para la parte inferior

    // Parte inferior del diamante
    while (x >= 0) {
        // Imprime espacios
        while (i <= (5 - x)) {
            cout << " ";
            i++;
        }
        i = 0;

        // Imprime asteriscos
        while (i <= (x * 2)) {
            cout << "*";
            i++;
        }
        i = 0;

        cout << endl; // Salto de línea para la siguiente fila
        x--;
    }

    /*
    Construcción de la parte inferior del diamante:

    1. Se inicia con x = 3.
    2. Mientras x sea mayor o igual a 0:
        - Se imprimen espacios (5 - x).
        - Se imprimen asteriscos (*), la cantidad es (x * 2) + 1.
        - Se disminuye x en 1 para la siguiente línea.
    3. Se repite el ciclo hasta completar la parte inferior del diamante.
    */

    return 0;
}
