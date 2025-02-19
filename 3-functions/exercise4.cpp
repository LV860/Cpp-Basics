/*
Autores:
Leonardo Velazquez Colin
Oscar Alejandro Rodriguez Gomez
Juan David Torres Chaparro

Descripcion:
La empresa “La Esmeralda” ha tenido excelentes ganancias en el último año gracias a su exitosa política de exportación de productos agrícolas. 
Debido a los beneficios obtenidos, desea implementar una política de incrementos salariales basada en el desempeño de sus empleados.

Reglas:
• Salarios mayores a $5'000.000 reciben un aumento del 3%. 
• Salarios entre $2'000.000 y $5'000.000 reciben un aumento del 4%. 
• Salarios menores a $2'000.000 reciben un aumento del 5%. 
• Se entrega un subsidio adicional según el número de hijos:
    - $400.000 por el primer hijo, $200.000 por el segundo, $100.000 por el tercero, y así sucesivamente.

El área de análisis financiero debe determinar el nuevo salario y el costo adicional para la empresa.
*/

#include <iostream>

using namespace std;

// Prototipos de funciones
float calcularSubsidio(int hijos);
/*
    Funcion: calcularSubsidio
    Descripcion: Se encarga de calcular el subsidio que recibe un empleado basado en la cantidad de hijos.
    Parametros: (int hijos) - Número de hijos del empleado.
    Retorna: (float) - Monto del subsidio correspondiente.
*/

float calcularNuevoSalario(float salarioBase, float subsidio);
/*
    Funcion: calcularNuevoSalario
    Descripcion: Se encarga de calcular el nuevo salario del empleado, incluyendo aumentos y subsidios.
    Parametros: 
        (float salarioBase) - Salario actual del empleado.
        (float subsidio) - Monto del subsidio por hijos.
    Retorna: (float) - Nuevo salario del empleado.
*/

int main()
{
    bool continuar = true;
    int contadorEmpleados = 1;

    while (continuar) {
        cout << "\n--------------------- Empleado " << contadorEmpleados << " --------------------" << endl;
        cout << "Área de análisis financiero" << endl;

        // Solicitar cantidad de hijos
        int tieneHijos;
        int cantidadHijos = 0;
        do {
            cout << "\n¿Tiene hijos? (Si = 1, No = 0): ";
            cin >> tieneHijos;
        } while (tieneHijos != 0 && tieneHijos != 1);

        if (tieneHijos) {
            cout << "Ingrese la cantidad de hijos: ";
            cin >> cantidadHijos;
        }

        // Calcular subsidio
        float subsidio = calcularSubsidio(cantidadHijos);
        cout << "El subsidio por " << cantidadHijos << " hijo(s) es de: $" << subsidio << endl;

        // Solicitar salario actual
        float salarioBase;
        cout << "\nIngrese su salario mensual actual: ";
        cin >> salarioBase;

        // Calcular nuevo salario
        float nuevoSalario = calcularNuevoSalario(salarioBase, subsidio);
        cout << "Su nuevo salario será: $" << nuevoSalario << endl;

        // Preguntar si desea ingresar otro empleado
        cout << "\n¿Desea ingresar otro empleado? (Si = 1, No = 0): ";
        cin >> continuar;
        contadorEmpleados++;
    }

    cout << "Proceso finalizado." << endl;
    return 0;
}

// Implementación de funciones
float calcularSubsidio(int hijos) {
    float subsidioTotal = 0;
    float monto = 400000;

    for (int i = 1; i <= hijos; i++) {
        subsidioTotal += monto;
        monto /= 2; // La mitad del subsidio anterior para el siguiente hijo
    }

    return subsidioTotal;
}

float calcularNuevoSalario(float salarioBase, float subsidio) {
    float aumento = 0;

    if (salarioBase > 5000000) {
        aumento = salarioBase * 0.03;
    } else if (salarioBase >= 2000000) {
        aumento = salarioBase * 0.04;
    } else {
        aumento = salarioBase * 0.05;
    }

    return salarioBase + aumento + subsidio;
}
