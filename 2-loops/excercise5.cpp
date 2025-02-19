/**************************
Autores:
    Leonardo Velazquez Colin
    Oscar Alejandro Rodriguez Gomez

Descripción:
Se desarrolla un programa para ayudar al supervisor del peaje de La Mesa a cuadrar caja manualmente durante 5 días mientras se arregla la registradora.
Se registra el dinero total entregado por Anita y los tiquetes vendidos en el día para verificar si el cierre de caja es exitoso.
Se calcula el total vendido por cada tipo de tiquete, el mayor descuadre y su día, el total del descuadre en los 5 días y el porcentaje de venta por tipo de tiquete.
***************************/

#include <iostream>

using namespace std;

int main()
{
    // Se declaran variables para almacenar los datos del peaje
    float DineroEntregado, cont_tiquetes_A = 0, cont_tiquetes_B = 0, cont_tiquetes_C = 0;
    float valor_total_tiquetes = 0, valor_tiquete_A, valor_tiquete_B, valor_tiquete_C;
    float valor_total_tiquete_A = 0, valor_total_tiquete_B = 0, valor_total_tiquete_C = 0;
    int Suma_valor_tiquete, descuadre, Mayor_descuadre = 0, dd = 0, dia_descuadre, total_descuadre = 0;
    float porcentajeT_tiquete_A, porcentajeT_tiquete_B, porcentajeT_tiquete_C;
    bool continua = true;
    char tiquetes;

    cout << "Bienvenido al sistema de cuadre de caja del peaje La Mesa" << endl;

    // Se repite el proceso por 5 días
    for (int i = 0; i < 5; i++) {
        continua = true;
        cout << "Ingrese el valor recaudado en el día " << i + 1 << ": ";
        cin >> DineroEntregado;

        // Se reinician los contadores de tiquetes al iniciar un nuevo día
        if (i != 0) {
            cont_tiquetes_A = 0;
            cont_tiquetes_B = 0;
            cont_tiquetes_C = 0;
        }

        // Se registran los tiquetes vendidos hasta que el supervisor ingrese 'D'
        while (continua) {
            cout << "Ingrese el tipo de tiquete vendido en el día (A, B, C). Ingrese 'D' para finalizar: ";
            cin >> tiquetes;

            if (tiquetes == 'D' || tiquetes == 'd') {
                continua = false;
            } else if (tiquetes == 'A' || tiquetes == 'a') {
                cont_tiquetes_A++;
            } else if (tiquetes == 'B' || tiquetes == 'b') {
                cont_tiquetes_B++;
            } else if (tiquetes == 'C' || tiquetes == 'c') {
                cont_tiquetes_C++;
            }
        }

        // Se calculan los valores totales por tipo de tiquete para el día
        valor_tiquete_A = cont_tiquetes_A * 5000;
        valor_tiquete_B = cont_tiquetes_B * 7500;
        valor_tiquete_C = cont_tiquetes_C * 18000;

        // Se acumulan los valores de los tiquetes en los 5 días
        valor_total_tiquete_A += valor_tiquete_A;
        valor_total_tiquete_B += valor_tiquete_B;
        valor_total_tiquete_C += valor_tiquete_C;

        // Se calcula el total del día y se verifica si el cierre es exitoso
        Suma_valor_tiquete = valor_tiquete_A + valor_tiquete_B + valor_tiquete_C;

        if (Suma_valor_tiquete == DineroEntregado) {
            cout << "Hoy fue un cierre exitoso." << endl;
        } else {
            descuadre = DineroEntregado - Suma_valor_tiquete;
            cout << "Hoy no fue un cierre exitoso." << endl;
            cout << "El descuadre fue de: $" << descuadre << endl;

            // Se registra el descuadre total y se identifica el mayor descuadre
            total_descuadre += descuadre;
            dd++;

            if (descuadre > Mayor_descuadre) {
                Mayor_descuadre = descuadre;
                dia_descuadre = i + 1;
            }
        }
    }

    // Se muestra el resumen de los 5 días
    cout << "\nResumen de los 5 días:" << endl;
    cout << "El valor total de tiquetes tipo A vendidos: $" << valor_total_tiquete_A << endl;
    cout << "El valor total de tiquetes tipo B vendidos: $" << valor_total_tiquete_B << endl;
    cout << "El valor total de tiquetes tipo C vendidos: $" << valor_total_tiquete_C << endl;
    cout << "El mayor descuadre fue de: $" << Mayor_descuadre << " en el día " << dia_descuadre << endl;
    cout << "El total del descuadre en los 5 días es de: $" << total_descuadre << endl;

    // Se calculan los porcentajes de ventas por tipo de tiquete
    valor_total_tiquetes = valor_total_tiquete_A + valor_total_tiquete_B + valor_total_tiquete_C;
    porcentajeT_tiquete_A = (valor_total_tiquete_A / valor_total_tiquetes) * 100;
    porcentajeT_tiquete_B = (valor_total_tiquete_B / valor_total_tiquetes) * 100;
    porcentajeT_tiquete_C = (valor_total_tiquete_C / valor_total_tiquetes) * 100;

    cout << "El porcentaje vendido del tiquete tipo A en 5 días es: " << porcentajeT_tiquete_A << "%" << endl;
    cout << "El porcentaje vendido del tiquete tipo B en 5 días es: " << porcentajeT_tiquete_B << "%" << endl;
    cout << "El porcentaje vendido del tiquete tipo C en 5 días es: " << porcentajeT_tiquete_C << "%" << endl;

    return 0;
}
