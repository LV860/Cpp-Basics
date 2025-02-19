/******************************************************************************
Autores:
Leonardo Velázquez Colin
Oscar Rodriguez Gomez

Este programa solicita al usuario su nombre, apellido y edad. Luego, calcula su edad dentro de 10 años 
y muestra un mensaje con esta información. Es una aplicación sencilla que demuestra el uso de 
entrada y salida de datos en C++
*******************************************************************************/



#include <iostream>  // Biblioteca para entrada y salida estándar (cout y cin)
#include <string>    // Biblioteca para manejar cadenas de texto (string)

using namespace std; // Permite usar cout, cin y endl sin el prefijo std::

int main() {
    int edad;               
    string nombre, apellido;

    
    cout << "Programa Bono 1" << endl;
    cout << "Bienvenido" << endl;

    
    cout << "Ingrese su nombre y apellido:" << endl; // Se solicita al usuario su nombre y apellido
    cout << "(1°Ingrese su primer nombre y presione enter, 2°Ingrese su primer apellido y presione enter)" << endl;
    cin >> nombre >> apellido; // Se captura solo una palabra para cada variable

   
    cout << "Ingrese su edad: (Ingrese su edad y presione enter)" << endl;  // Se solicita la edad del usuario
    cin >> edad; // Se captura la edad ingresada 

    
    edad += 10;

    
    cout << apellido << " " << nombre << " tiene la edad de " << edad << endl; // Se muestra el mensaje con el nombre, apellido y la nueva edad

    return 0; 
}

