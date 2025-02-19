/******************************************************************************
Autores:
Leonardo Velazquez Colin

Descripcion:
Este programa permite al usuario ingresar números enteros y cuenta cuántos 
números ingresó antes de introducir un 0. El programa finaliza cuando se 
ingresa un 0 y muestra la cantidad total de números ingresados sin contar el 0.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int numero, Cantidad_numero = 0; // Se inicializa en 0 para contar correctamente los números ingresados.
    
    cout << "Bienvenido" << endl;

    do { // Se hace un bucle do-while para garantizar que se ingrese al menos un número.
        cout << "Ingrese un numero entero: ";
        cin >> numero;
        if (numero != 0) { // Se cuenta solo si el número no es 0.
            Cantidad_numero++;
        }
    } while (numero != 0); // Se repite hasta que el usuario ingrese 0.

    cout << "Usted ingreso " << Cantidad_numero << " numeros" << endl; // Se muestra la cantidad de números ingresados.

    return 0;
}
