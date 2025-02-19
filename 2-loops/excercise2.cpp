/**************************
Autores:
Leonardo Velazquez Colin
Oscar Alejandro Rodriguez Gomez

Descripción: 
Programa en C++ que calcula el factorial de un número entero ingresado por el usuario.

***************************/

#include <iostream>  // Biblioteca estándar para entrada y salida

using namespace std;  // Permite el uso de nombres estándar sin el prefijo "std::"

int main() 
{
    int n, n_factorial = 1;  // Declaración de variables: 'n' para el número ingresado, 'n_factorial' para almacenar el resultado

    cout << "Bienvenido" << endl; 
    
    // Se solicita al usuario un número entero para calcular su factorial
    cout << "Ingrese un numero entero, para mostrarle su factorial: " << endl;
    cin >> n;  // Entrada del usuario
    
    // Bucle para calcular el factorial de 'n'
    for (int i = 0; i < n; i++) {
        n_factorial = n_factorial * (n - i);  // Se multiplica el resultado acumulado por (n - i)
    }
    
    // Se muestra el resultado en pantalla
    cout << "El factorial de " << n << " es: " << n_factorial << endl;

    return 0;  // Fin del programa
}
