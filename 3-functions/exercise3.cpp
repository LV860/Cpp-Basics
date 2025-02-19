/*
Autores:
Leonardo Velazquez Colin
Oscar Alejandro Rodriguez Gomez
Juan David Torres Chaparro

Descripcion:
Programa que recibe un número cualquiera y devuelve como resultado la suma de sus dígitos. 
Ejemplo: si recibe 64392, debe retornar 24 (6+4+3+9+2). 
Nota: no se conoce el número de dígitos del número recibido.
*/

#include <iostream>

using namespace std;

// Prototipo
/*  
    Funcion: sumaDigitos --> Se encarga de calcular la suma de los dígitos de un número.
    Parametros: int numEntero, representa el número al cual se le sumarán sus dígitos.
    Return: Un entero con la suma de los dígitos del número.                     
*/
int sumaDigitos(int numEntero);

int main()
{
    int numEntero;

    // Se solicita al usuario que ingrese un número entero positivo.
    do {
        cout << "Ingrese un numero entero positivo: " << endl;
        cin >> numEntero;
    } while (numEntero <= 0); // Se valida que el número ingresado sea positivo.

    // Se llama la función que calcula la suma de los dígitos.
    int resultado = sumaDigitos(numEntero);

    // Se muestra el resultado al usuario.
    cout << "La suma de los digitos del numero es: " << resultado << endl;

    return 0;
}

// Definicion de la funcion sumaDigitos
int sumaDigitos(int numEntero) {
    int resultado = 0; 
    int digito = 0;

    // Se extraen los dígitos uno a uno y se suman.
    while (numEntero != 0) {
        digito = numEntero % 10; // Se obtiene el último dígito del número.
        numEntero /= 10; // Se elimina el último dígito del número original.
        resultado += digito; // Se acumula la suma de los dígitos.
    }

    // Se retorna la suma total de los dígitos.
    return resultado;
}
