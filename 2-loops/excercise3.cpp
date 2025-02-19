/****
Autores:
Leonardo Velazquez Colin
Oscar Alejandro Rodriguez Gomez

Descripción: 
Simulación de la población de hormigas en la Isla del Edén, considerando su tasa de crecimiento 
y la depredación de un oso hormiguero que se alimenta al final de cada mes.

Reglas del experimento:
- Las hormigas se reproducen a una tasa del 40% mensual.
- Si la población supera las 28,000 hormigas, la tasa de crecimiento baja al 31%.
- Al final de cada mes, un oso hormiguero se come 7,000 hormigas (o todas si hay menos de esa cantidad).
- Si la población llega a 0 antes de los meses indicados, el programa finaliza con un mensaje.

Entrada:
- Número inicial de hormigas en la isla.
- Número de meses que durará el experimento.

Salida:
- Población de hormigas al final de cada mes.
***/

#include <iostream>

using namespace std;

int main()
{
    int Numero_Hormigas;  // Número inicial de hormigas en la isla
    int Numero_Meses;     // Duración del experimento en meses
    int Nuevas_Hormigas;  // Número de hormigas que nacen cada mes

    // Se solicita los datos al usuario
    cout << "Bienvenido al experimento de la Isla del Edén" << endl;

    cout << "Digite el numero inicial de hormigas: ";
    cin >> Numero_Hormigas;

    cout << "Digite el numero de meses del experimento: ";
    cin >> Numero_Meses;

    // Simulación mensual del crecimiento y depredación
    for (int x = 1; x <= Numero_Meses; x++) {
        // Se determinan la tasa de crecimiento según la población
        if (Numero_Hormigas > 28000) {
            Nuevas_Hormigas = Numero_Hormigas * 0.31;  // Crecimiento reducido al 31%
        } else {
            Nuevas_Hormigas = Numero_Hormigas * 0.4;   // Crecimiento normal del 40%
        }

        // Se actualiza la población después del crecimiento y la depredación
        Numero_Hormigas = (Numero_Hormigas + Nuevas_Hormigas) - 7000;

        // Se verifica si la población se ha extinguido
        if (Numero_Hormigas <= 0) {
            cout << "La cantidad de hormigas despues del mes " << x << " es: 0" << endl;
            cout << "La isla se quedo sin hormigas." << endl;
            break;  // Se termina el experimento
        }

        // Se muestra la cantidad de hormigas después de cada mes
        cout << "La cantidad de hormigas despues del mes " << x << " es: " << Numero_Hormigas << endl;
    }

    return 0;
}
