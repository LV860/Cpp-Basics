/******************************************************************************
Autores:
Leonardo Velázquez Colin
Oscar Rodríguez Gómez

Descripción:
Este programa calcula el valor de un pedido considerando la cantidad y el valor 
unitario de un artículo. Aplica la siguiente política de descuento:
- Si el valor bruto de la compra supera $500,000, se aplica un 5% de descuento.
- Independientemente del descuento, se cobra un IVA del 20% sobre el valor bruto.
- Se muestra el valor neto final a pagar.
*******************************************************************************/

#include <iostream> // Biblioteca para entrada y salida estándar

using namespace std; // Permite usar cout y cin sin prefijo std::

int main() {
    // Variables para almacenar los valores ingresados por el usuario
    int Valor_articulo1, cantidad_articulo1;
    float Valor_Bruto, Valor_Neto, Valor_descuento = 0.0; // Se inicializa el descuento en 0

    cout << "Bienvenido" << endl;

    // Se  solicita al usuario el precio unitario del artículo
    cout << "Ingrese el valor del artículo deseado: " << endl;
    cin >> Valor_articulo1;

    // se solicita al usuario la cantidad de artículos a comprar
    cout << "Ingrese la cantidad del artículo deseado: " << endl;
    cin >> cantidad_articulo1;

    //  Se calcula el valor bruto de la compra (precio unitario * cantidad)
    Valor_Bruto = Valor_articulo1 * cantidad_articulo1;

    // Se aplica el descuento si el valor bruto es mayor a $500,000
    if (Valor_Bruto > 500000) {
        Valor_descuento = Valor_Bruto * 0.05; // 5% de descuento
    }

    // se calcula el valor neto: (Valor Bruto - Descuento) + IVA del 20%
    Valor_Neto = (Valor_Bruto - Valor_descuento) * 1.2;

    // Se muestra el valor final del pedido
    cout << "El valor del pedido es: " << Valor_Neto << endl;

    return 0; 
}
