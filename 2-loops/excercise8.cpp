/**************************
Autores:
Leonardo Velazquez Colin
Oscar Alejandro Rodriguez Gomez
Juan David Torres Chaparro

Descripcion:
Se hace la impresión de cuatro figuras con asteriscos (*).  
Cada figura sigue un patrón específico de alineación y cantidad de caracteres.  

Figura 1: Triángulo rectángulo alineado a la izquierda.  
Figura 2: Triángulo rectángulo invertido.  
Figura 3: Triángulo rectángulo alineado a la derecha, invertido.  
Figura 4: Triángulo rectángulo alineado a la derecha.  

***************************/

#include <iostream>

using namespace std;

int main()
{
    cout << "Bienvenido" << endl;

    // Figura 1: Triángulo rectángulo alineado a la izquierda.
    for (int i = 0; i < 10; i++) { // Se hace un bucle de 10 filas.
        for (int j = 1; j <= (i + 1); j++) { // Se hace un bucle que imprime '*' según el número de la fila.
            cout << "*";
        }
        cout << endl; // Se hace un salto de línea después de cada fila.
    }
    cout << endl; // Espacio entre figuras.

    // Figura 2: Triángulo rectángulo invertido.
    for (int i = 0; i < 10; i++) { // Se hace un bucle de 10 filas.
        for (int j = 9; j > (i - 1); j--) { // Se hace un bucle que imprime '*' disminuyendo en cada fila.
            cout << "*";
        }
        cout << endl; // Se hace un salto de línea después de cada fila.
    }
    cout << endl; // Espacio entre figuras.

    // Figura 3: Triángulo rectángulo alineado a la derecha, invertido.
    for (int i = 0; i < 10; i++) { // Se hace un bucle de 10 filas.
        for (int j = 0; j < i; j++) { // Se imprimen espacios antes de los '*'.
            cout << " ";
        }
        for (int x = i; x < 10; x++) { // Se imprimen '*' después de los espacios.
            cout << "*";
        }
        cout << endl; // Se hace un salto de línea después de cada fila.
    }
    cout << endl; // Espacio entre figuras.

    // Figura 4: Triángulo rectángulo alineado a la derecha.
    for (int i = 0; i < 10; i++) { // Se hace un bucle de 10 filas.
        for (int x = (i + 1); x < 10; x++) { // Se imprimen espacios antes de los '*'.
            cout << " ";
        }
        for (int j = 0; j < (i + 1); j++) { // Se imprimen '*' después de los espacios.
            cout << "*";
        }
        cout << endl; // Se hace un salto de línea después de cada fila.
    }

    return 0;
}
