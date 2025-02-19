/**
Autores:
Leonardo Velazquez Colin
Oscar Alejandro Rodriguez Gomez
Juan David Torres Chaparro

Descripcion:
Programa que permite ingresar un año y determinar si es año bisiesto o no.
*/

#include <iostream>

using namespace std;

// Prototipo
/*  Funcion: A_bisiesto --> se encarga de determinar si un año es bisiesto o no.
    Parametros: int ano, representa el año a evaluar.
    Return: Un booleano que indica si el año es bisiesto (true) o no (false).                    
*/
bool A_bisiesto(int ano);

int main()
{
    int ano, continuar = 1; 
    
    cout << "Bienvenido" << endl;
    cout << "Ejercicio 2" << endl;
    
    while (continuar == 1) {
        cout << "Ingrese el ano que desea evaluar:" << endl; 
        cin >> ano;
        
        // Se verifica si el año es bisiesto y se muestra el resultado al usuario
        if (A_bisiesto(ano)) { 
            cout << "El ano es bisiesto" << endl; 
        } else {
            cout << "El ano no es bisiesto" << endl; 
        }
        
        cout << "Desea ingresar otro ano? (Si = 1, No = 0)" << endl; 
        cin >> continuar; // Se pregunta si se quiere evaluar otro año
    }
    
    cout << "Gracias por utilizar nuestros servicios" << endl;
    return 0;
}

// Definición de la función A_bisiesto
bool A_bisiesto(int ano) {
    /*
    Se determina si un año es bisiesto aplicando las siguientes reglas:
    - Un año es bisiesto si es divisible por 4.
    - Pero si también es divisible por 100, deja de ser bisiesto.
    - Sin embargo, si es divisible por 400, entonces sí es bisiesto.
    */
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        return true; // Se retorna true si el año es bisiesto
    } else {
        return false; // Se retorna false si el año no es bisiesto
    }
}
