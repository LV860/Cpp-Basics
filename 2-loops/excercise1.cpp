/******************************************************************************
Autores:
Leonardo Velázquez Colin
Oscar Alejandro Rodríguez Gómez

Descripción:
Este programa simula una multi-calculadora que realiza operaciones aritméticas
básicas con números enteros, basándose en reglas específicas según los múltiplos.

Reglas de operación:
1. Si el acumulado actual es cero, el número entrante se convierte en el nuevo acumulado.
2. Si el acumulado actual es diferente de cero, el número entrante se opera según:
   a. Si es múltiplo de 2, se suma al acumulado.
   b. Si es múltiplo de 3, se resta del acumulado.
   c. Si es múltiplo de 5, se multiplica con el acumulado.
   d. Si es múltiplo de 7, divide al acumulado.
*******************************************************************************/

#include <iostream>

using namespace std;

int main() {
    // Sección de declaración de variables
    int Numero_Entrante, Numero_Acumulado;
    bool Continua;

    // Mensaje de bienvenida e instrucciones de uso
    cout << "Bienvenido a la Multicalculadora" << endl << endl;
    cout << "¿Cómo usarla?" << endl;
    cout << "1. Si el acumulado es cero, el número ingresado se convierte en el acumulado." << endl;
    cout << "2. Si el acumulado es diferente de cero, el número ingresado se opera según estas reglas:" << endl;
    cout << "   - Si es múltiplo de 2, se suma al acumulado." << endl;
    cout << "   - Si es múltiplo de 3, se resta del acumulado." << endl;
    cout << "   - Si es múltiplo de 5, se multiplica con el acumulado." << endl;
    cout << "   - Si es múltiplo de 7, divide al acumulado." << endl << endl;
    cout << "¡Empecemos!" << endl;

    // Primera entrada del usuario
    cout << "Ingrese un número entero: ";
    cin >> Numero_Entrante;

    // Se pregunta si desea continuar ingresando números
    cout << "¿Quiere seguir ingresando números? (Sí: 1 / No: 0): ";
    cin >> Continua;

    // Inicialización del acumulado con el primer número ingresado
    Numero_Acumulado = Numero_Entrante;

    // Bucle para procesar múltiples números según las reglas establecidas
    while (Continua) {
        cout << "Ingrese un número entero: ";
        cin >> Numero_Entrante;

        // Se aplican las reglas según los múltiplos
        if (Numero_Entrante % 2 == 0) {
            Numero_Acumulado += Numero_Entrante; // Sumar si es múltiplo de 2
        }
        if (Numero_Entrante % 3 == 0) {
            Numero_Acumulado -= Numero_Entrante; // Restar si es múltiplo de 3
        }
        if (Numero_Entrante % 5 == 0) {
            Numero_Acumulado *= Numero_Entrante; // Multiplicar si es múltiplo de 5
        }
        if (Numero_Entrante % 7 == 0) {
            if (Numero_Entrante != 0) {
                Numero_Acumulado /= Numero_Entrante; // Dividir si es múltiplo de 7 (evitando división por cero)
            } else {
                cout << "Error: No se puede dividir por cero." << endl;
            }
        }

        // Se pregunta si desea continuar
        cout << "¿Quiere seguir ingresando números? (Sí: 1 / No: 0): ";
        cin >> Continua;
    }

    // Se muestra el resultado final
    cout << "El resultado final es: " << Numero_Acumulado << endl;

    return 0;
}
