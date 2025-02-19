/**
Autores:
Leonardo Velazquez Colin
Oscar Alejandro Rodriguez Gomez
Juan David Torres Chaparro

Descripcion:
Se creó un programa en C++ que simula una calculadora. Se generaron funciones para sumar, restar, multiplicar y dividir. 
El usuario debe seleccionar la operación que quiere ejecutar mediante un menú. Por facilidad, las operaciones se realizan con solo dos operandos.
*/

#include <iostream>

using namespace std;

// Se declararon los prototipos de las funciones
float suma (float a, float b);
float resta (float a, float b);
float multiplicacion (float a, float b);
float division (float n1, float n2);

int main()
{
    float n1, n2;
    int Operacion;
    int x = 1;
    
    while (x == 1) {
        // Se solicitaron los dos números al usuario
        cout << "Ingrese dos numeros" << endl;
        cin >> n1 >> n2;
        
        do {
            // Se muestra el menú de opciones
            cout << "¿Que operacion quiere hacer? " << endl;
            cout << "\t 1 = Suma" << endl;
            cout << "\t 2 = Resta" << endl;
            cout << "\t 3 = Multiplicacion" << endl;
            cout << "\t 4 = Division"  << endl;
            cin >> Operacion;
        } while (Operacion < 1 || Operacion > 4); 
        // Se verifica que la opción ingresada sea válida
        
        // Se ejecuta la operación correspondiente
        switch (Operacion) {
            case 1: suma (n1, n2);
                break;
            case 2: resta (n1, n2);
                break;
            case 3: multiplicacion (n1, n2);
                break;
            default: division (n1, n2);
        }
        
        // Se pregunta al usuario si quiere realizar otra operación
        cout << "¿Quiere hacer otra operacion? (1 = Si, 0 = No)" << endl;
        cin >> x;
    }
    
    // Se muestra un mensaje de despedida
    cout << "Gracias por usar nuestros servicios :)" << endl;
    return 0;
}

// Se definieron las funciones
float suma (float n1, float n2) {
    float c = n1 + n2; 
    cout << "El resultado de la suma es: " << c << endl; 
    return 0;
}

float resta (float n1, float n2) {
    float c = n1 - n2; 
    cout << "El resultado de la resta es: " << c << endl;
    return 0;
}

float multiplicacion (float n1, float n2) {
    float c = n1 * n2; 
    cout << "El resultado de la multiplicacion es: " << c << endl;
    return 0;
}

float division (float n1, float n2) {
    // Se verifica que el divisor no sea cero
    if (n2 == 0) {
        cout << "Error: No se puede dividir entre cero." << endl;
        return 0;
    }
    float c = n1 / n2; 
    cout << "El resultado de la division es: " << c << endl;
    return 0;
}
