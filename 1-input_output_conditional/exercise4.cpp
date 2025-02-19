/******************************************************************************
Autores:
Leonardo Velázquez Colin
Oscar Alejandro Rodríguez Gómez

Descripción:
Este programa calcula el costo neto de una póliza de seguro de vida según la edad del cliente
y el valor asegurado. Las condiciones son:

- El costo base de la póliza es el 1% del valor asegurado.
- Si el cliente tiene entre 18 y 40 años, recibe un descuento del 20%.
- Si el cliente tiene más de 65 años, se le aplica una sobretasa del 30%.
*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    // Sección de Declaración de variables
    string NombreUsuario;    // Almacena el nombre del cliente
    int EdadUsuario;         // Edad del cliente
    int ValorAsegurar;       // Monto que se desea asegurar
    int ValorPoliza;         // Costo base de la póliza (1% del valor asegurado)
    int ValorNeto;           // Costo final de la póliza después de aplicar descuentos o sobretasas

    // Se solicitan los datos al usuario
    cout << "Bienvenido" << endl;
    cout << "Ingrese su Nombre:" << endl;
    cin >> NombreUsuario;

    cout << "Ingrese su Edad:" << endl;
    cin >> EdadUsuario;

    cout << "Ingrese el Valor a Asegurar:" << endl;
    cin >> ValorAsegurar;

    // Se calcula el costo base de la póliza (1% del valor asegurado)
    ValorPoliza = ValorAsegurar * 0.01;
    ValorNeto = ValorPoliza; // Inicialmente, el valor neto es igual al valor base de la póliza

    // Se aplican los descuentos o sobretasas según la edad del usuario
    if (EdadUsuario >= 18 && EdadUsuario <= 40) {
        ValorNeto -= ValorPoliza * 0.2;  // Descuento del 20%
    } else if (EdadUsuario > 65) {
        ValorNeto += ValorPoliza * 0.3;  // Sobretasa del 30%
    }

    // Se muestra el costo neto de la póliza
    cout << "El costo neto de la póliza del seguro de vida es: " << ValorNeto << endl;

    return 0; // Fin del programa
}
