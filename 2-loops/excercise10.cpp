/**************************
Autores:
Leonardo Velazquez Colin  
Oscar Alejandro Rodriguez Gomez  
Juan David Torres Chaparro  

Descripción:  
Este programa simula un juego de cartas entre hasta 20 jugadores.  
Cada jugador recibe dos cartas, cada una con un número (1-10) y una figura  
(corazón (C), diamante (D), pica (P) o trébol (T)).  

Reglas:  
- Si las dos cartas tienen el mismo número, el jugador recibe 21 puntos.  
- En caso contrario, el puntaje es la suma de los valores de las cartas.  
- Si hay empate, se desempata con el valor de las figuras:  
    * Corazón (C) = 10 puntos  
    * Diamante (D) = 5 puntos  
    * Pica (P) = 3 puntos  
    * Trébol (T) = 1 punto  
- Al final, se muestra el nombre del jugador ganador.  

***************************/

#include <iostream>

int main() {
    int carta_1 = 0, carta_2 = 0, figura_1 = 0, figura_2 = 0;
    int jugadores = 0, valorFigura1, valorFigura2;
    int sumaFiguras = 0, sumaCartas = 0, cartasGanador = 0, figuraGanador = 0;
    std::string nombre, nombre_ganador;

    // Validación del número de jugadores
    while (jugadores == 0) {
        std::cout << "Ingrese la cantidad de jugadores (máximo 20): ";
        std::cin >> jugadores;
        if (jugadores < 1 || jugadores > 20) {
            std::cout << "Ingrese un número válido.\n";
            jugadores = 0;
        }
    }

    // Inicio del juego
    for (int i = 1; i <= jugadores; i++) {
        std::cout << "Turno del jugador " << i << "\nIngrese su nombre: ";
        std::cin >> nombre;

        // Ingreso de las cartas
        while (carta_1 == 0) {
            std::cout << "Ingrese el número de la carta 1 [1-10]: ";
            std::cin >> carta_1;
            if (carta_1 < 1 || carta_1 > 10) {
                std::cout << "Número inválido, intente nuevamente.\n";
                carta_1 = 0;
            }
        }

        while (carta_2 == 0) {
            std::cout << "Ingrese el número de la carta 2 [1-10]: ";
            std::cin >> carta_2;
            if (carta_2 < 1 || carta_2 > 10) {
                std::cout << "Número inválido, intente nuevamente.\n";
                carta_2 = 0;
            }
        }

        // Ingreso de las figuras
        while (figura_1 == 0) {
            std::cout << "Ingrese la figura de la carta 1 (1 = C, 2 = D, 3 = P, 4 = T): ";
            std::cin >> figura_1;
            if (figura_1 < 1 || figura_1 > 4) {
                std::cout << "Valor inválido, intente nuevamente.\n";
                figura_1 = 0;
            }
        }

        while (figura_2 == 0) {
            std::cout << "Ingrese la figura de la carta 2 (1 = C, 2 = D, 3 = P, 4 = T): ";
            std::cin >> figura_2;
            if (figura_2 < 1 || figura_2 > 4) {
                std::cout << "Valor inválido, intente nuevamente.\n";
                figura_2 = 0;
            }
        }

        // Asignación de valores a las figuras
        switch (figura_1) {
            case 1: valorFigura1 = 10; break;
            case 2: valorFigura1 = 5; break;
            case 3: valorFigura1 = 3; break;
            default: valorFigura1 = 1;
        }

        switch (figura_2) {
            case 1: valorFigura2 = 10; break;
            case 2: valorFigura2 = 5; break;
            case 3: valorFigura2 = 3; break;
            default: valorFigura2 = 1;
        }

        // Cálculo del puntaje
        sumaFiguras = valorFigura1 + valorFigura2;
        sumaCartas = (carta_1 == carta_2) ? 21 : (carta_1 + carta_2);

        // Determinar el ganador
        if (sumaCartas > cartasGanador) {
            cartasGanador = sumaCartas;
            figuraGanador = sumaFiguras;
            nombre_ganador = nombre;
        } else if (sumaCartas == cartasGanador && sumaFiguras > figuraGanador) {
            figuraGanador = sumaFiguras;
            nombre_ganador = nombre;
        }

        // Reiniciar valores para el próximo jugador
        carta_1 = carta_2 = figura_1 = figura_2 = 0;
    }

    std::cout << "El jugador ganador es: " << nombre_ganador << std::endl;

    return 0;
}
