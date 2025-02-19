/**************************

Autores:
Leonardo Velazquez Colin
Oscar Alejandro Rodriguez Gomez
Juan David Torres Chaparro

Descripcion:
Escriba un programa que permita calcular la factura de los clientes de la compañía de cable local (De antemano, NO se sabe cuál es el número de clientes). Hay dos tipos de clientes: residenciales y de negocios. Hay dos tarifas para calcular una factura de cable: una para clientes residenciales y la otra para clientes de negocios.
Para clientes residenciales se aplican las tarifas siguientes: 
∙ Cargo por procesamiento de la factura: $4.50 
∙ Cargo por servicio básico: $20.50 
∙ Canales Premium: $7.50 por canal

Para clientes de negocios se aplican las tarifas siguientes:
∙ Cargo por procesamiento de la factura: $15.00 
∙ Cargo por servicio básico: $75.00 por las primeras 10 conexiones; $5.00 por cada conexión adicional 
∙ Canales Premium: $50.00 por canal para cualquier número de conexiones

El programa debe pedirle al usuario un número de cuenta (un entero) y un tipo de cliente. Suponga que R o r denota cliente residencial y N o n denota cliente de negocios. 
Entrada: ingrese en el programa el número de cuenta del cliente, su tipo y el número de canales Premium a los cuales está suscrito, y, en el caso de clientes de negocios, el número de conexiones de servicio básico.
Salida: el número de cuenta del cliente y el importe de facturación.

***************************/

#include <iostream>

using namespace std;

int main() {
    // Seccion de declaracion de variables
    int NumeroCuenta, TipoCuenta, NumeroCanalesP, NumeroConexiones;
    double TarifaBasicaR = 20.50, ValorCanalesR = 7.50, CargoFactR = 4.50;
    double TarifaBasicaN = 75.00, TarifaAdicionalN = 0.0, ValorCanalesN = 50.00, CargoFactN = 15.00;
    double TarifaPago;
    char continuar = 'S'; // Variable para control de repeticion

    cout << "Este programa calcula la factura de cable" << endl;

    while (continuar == 'S' || continuar == 's') {
        cout << "\nIngrese el numero de cuenta: ";
        cin >> NumeroCuenta;

        cout << "Ingrese el tipo de cliente (1 = Residencial, 2 = Negocios): ";
        cin >> TipoCuenta;

        if (TipoCuenta == 1) { // Cliente Residencial
            cout << "Ingrese el numero de canales premium: ";
            cin >> NumeroCanalesP;

            // Calculo de la tarifa total para cliente residencial
            TarifaPago = CargoFactR + TarifaBasicaR + (ValorCanalesR * NumeroCanalesP);
        
        } else if (TipoCuenta == 2) { // Cliente de Negocios
            cout << "Ingrese el numero de conexiones de servicio basico: ";
            cin >> NumeroConexiones;

            cout << "Ingrese el numero de canales premium: ";
            cin >> NumeroCanalesP;

            // Calculo de tarifa adicional solo si hay mas de 10 conexiones
            if (NumeroConexiones > 10) {
                TarifaAdicionalN = (NumeroConexiones - 10) * 5.00;
            } else {
                TarifaAdicionalN = 0.0;
            }

            // Calculo de la tarifa total para cliente de negocios
            TarifaPago = CargoFactN + TarifaBasicaN + TarifaAdicionalN + (ValorCanalesN * NumeroCanalesP);
        
        } else {
            cout << "Tipo de cliente invalido. Intente nuevamente.\n";
            continue; // Reinicia el loop sin mostrar tarifa
        }

        // Mostrar resultado
        cout << "Para el numero de cuenta " << NumeroCuenta << ", la tarifa a pagar es de: $" << TarifaPago << endl;

        // Preguntar si desea continuar con otra consulta
        cout << "\u00bfQuiere consultar otra cuenta? (S = Si, N = No): ";
        cin >> continuar;
    }

    cout << "Gracias por usar el sistema de facturacion." << endl;

    return 0;
}
