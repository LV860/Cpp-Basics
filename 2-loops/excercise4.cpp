/**********
Autores:
    Oscar Alejandro Rodriguez Gomez
    Leonardo Velazquez Colin
	
Descripción:
Se simula el crecimiento de dos poblaciones de hormigas en la Isla del Edén.

Reglas del experimento:
- Se tiene una población de hormigas rojas (A) y una de hormigas enanas (B).
- Se asegura que la población A es menor que la población B.
- Se hace que la población A crezca más rápido que la población B.
- Se reduce la tasa de crecimiento a la mitad cuando una población supera las 20,000 hormigas.
- Se calcula cuántos meses se necesitan para que la población A supere o iguale a la población B.

Entrada:
- Se pide la población inicial de hormigas rojas y enanas.
- Se solicita la tasa de crecimiento mensual de cada población.

Salida:
- Se muestra el número de meses en los que la población A supera o iguala a la B.
- Se imprimen las cantidades finales de hormigas en cada población.
*********/

#include <iostream>

using namespace std;

int main()
{
    int Hormigas_Rojas, Hormigas_Enanas;  // Se declaran las poblaciones iniciales.
    float Tasa_Crecimiento_HR, Tasa_Crecimiento_HE;  // Se definen las tasas de crecimiento.
    int meses = 0;  // Se inicializa el contador de meses.

    cout << "Bienvenido al simulador de crecimiento de hormigas" << endl;

    // Se solicita la población de hormigas rojas.
    cout << "Ingrese la poblacion inicial de hormigas rojas: ";
    cin >> Hormigas_Rojas;

    // Se solicita la tasa de crecimiento de las hormigas rojas.
    cout << "Ingrese la tasa de crecimiento mensual de las hormigas rojas (como porcentaje, sin el símbolo %): ";
    cin >> Tasa_Crecimiento_HR;

    // Se solicita la población de hormigas enanas y se valida que sea mayor que la de hormigas rojas.
    do {
        cout << "Ingrese la poblacion inicial de hormigas enanas (debe ser mayor que la de hormigas rojas): ";
        cin >> Hormigas_Enanas;
        if (Hormigas_Enanas < Hormigas_Rojas) {
            cout << "Error: La población de hormigas enanas debe ser mayor que la de hormigas rojas." << endl;
        }
    } while (Hormigas_Enanas < Hormigas_Rojas);

    // Se solicita la tasa de crecimiento de las hormigas enanas y se valida que sea menor que la de hormigas rojas.
    do {
        cout << "Ingrese la tasa de crecimiento mensual de las hormigas enanas (menor que la de hormigas rojas, sin %): ";
        cin >> Tasa_Crecimiento_HE;
        if (Tasa_Crecimiento_HE > Tasa_Crecimiento_HR) {
            cout << "Error: La tasa de crecimiento de las hormigas enanas debe ser menor que la de hormigas rojas." << endl;
        }
    } while (Tasa_Crecimiento_HE > Tasa_Crecimiento_HR);

    // Se convierten las tasas de porcentaje a valores decimales.
    Tasa_Crecimiento_HR /= 100;
    Tasa_Crecimiento_HE /= 100;

    // Se simula el crecimiento de las hormigas mes a mes.
    while (Hormigas_Rojas < Hormigas_Enanas) {
        meses++;

        // Se ajusta la tasa de crecimiento si la población supera los 20,000.
        float Tasa_Roja_Ajustada = (Hormigas_Rojas > 20000) ? Tasa_Crecimiento_HR * 0.5 : Tasa_Crecimiento_HR;
        float Tasa_Enana_Ajustada = (Hormigas_Enanas > 20000) ? Tasa_Crecimiento_HE * 0.5 : Tasa_Crecimiento_HE;

        // Se incrementan las poblaciones según la tasa de crecimiento ajustada.
        Hormigas_Rojas += Hormigas_Rojas * Tasa_Roja_Ajustada;
        Hormigas_Enanas += Hormigas_Enanas * Tasa_Enana_Ajustada;
    }

    // Se imprimen los resultados finales.
    cout << "La poblacion de hormigas rojas supero o igualo a la poblacion de hormigas enanas en " << meses << " meses." << endl;
    cout << "Despues de " << meses << " meses, el numero final de hormigas rojas es: " << Hormigas_Rojas << endl;
    cout << "Despues de " << meses << " meses, el numero final de hormigas enanas es: " << Hormigas_Enanas << endl;

    return 0;
}
