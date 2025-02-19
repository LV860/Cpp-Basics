/******************************************************************************
Autores:
Leonardo Velázquez Colin
Oscar Alejandro Rodríguez Gómez

Descripción:
Este programa calcula la tarifa mensual de un plan de celular según el consumo 
en minutos, aplicando los siguientes criterios:

- Tarifa básica: $50,000
- Los primeros 500 minutos cuestan $100 cada uno.
- A partir del minuto 501, cada minuto tiene un 40% de descuento, es decir, 
  cuesta $60 en lugar de $100.

El programa solicita al usuario la cantidad de minutos consumidos y calcula 
la tarifa mensual correspondiente.
*******************************************************************************/

#include <iostream> // Biblioteca estándar para entrada y salida

using namespace std; // Permite usar cout y cin sin prefijo std::

int main() {
    
    const int TarifaBasica = 50000;  // Tarifa mensual base
    const int CostoMinuto = 100;     // Costo por minuto estándar
    const float Descuento = 0.40;    // 40% de descuento después de los 500 min
    
    int ConsumoMinutos;              // Minutos consumidos por el usuario
    int TarifaMensual;               // Tarifa total a pagar

    
    cout << "Bienvenido" << endl;
    cout << "Ingrese la cantidad de minutos que ha consumido en el mes:" << endl; // Se solicita la cantidad de minutos consumidos
    cin >> ConsumoMinutos;

    //  Se calcula la tarifa mensual según el consumo
    if (ConsumoMinutos <= 500) {
        // Si el usuario consume 500 minutos o menos, el costo es tarifa básica + minutos usados
        TarifaMensual = TarifaBasica + (ConsumoMinutos * CostoMinuto);
    } else {
        // Si el usuario supera los 500 minutos:
        int MinutosAdicionales = ConsumoMinutos - 500; // Minutos que exceden los 500 iniciales
        int CostoMinutosNormales = 500 * CostoMinuto; // Costo de los primeros 500 minutos
        int CostoMinutosAdicionales = MinutosAdicionales * (CostoMinuto * (1 - Descuento)); // Con descuento
        
        // Tarifa final = tarifa base + costo de los primeros 500 min + costo de los minutos adicionales
        TarifaMensual = TarifaBasica + CostoMinutosNormales + CostoMinutosAdicionales;
    }

    // Se muestra el resultado al usuario
    cout << "La tarifa mensual a pagar del celular es de: $" << TarifaMensual << endl;

    return 0; // Fin del programa
}
