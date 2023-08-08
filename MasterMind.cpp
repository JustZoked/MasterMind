// MasterMind.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Librerias
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

bool esNumero(char c) {
    return (c >= '1' && c <= '6');
}

int main()
{
    // Arrays
    int numerosBase[4];
    int numerosUsuario[4];
    int correctas = 0;
    bool ganaste = false;

    // Seed para que el random sea totalmente random en base al tiempo
    srand((int)time(0));

    // Genera 4 numeros aleatorios
    for (int i = 0; i < 4; i++)
    {
        numerosBase[i] = rand() % 6 + 1;

        // Verifica que ningun numero se repita
        for (int j = 0; j < i; ++j)
        {
            // Si el numero en la posicion "i" es igual al de la posicion "j", se hace un random.
            // Asi hasta que no queden numeros iguales.

            if (numerosBase[i] == numerosBase[j])
            {
                numerosBase[i] = 1 + rand() % 6;
            }
        }
    }

    // Introduccion al juego
    cout << "Bienvenido al juego MasterMind\n";
    cout << "Debes introducir 4 digitos del 1-6 y adivinar la combinacion\n";

    // Método para verificar si los 4 dígitos base son iguales a los introducidos por el jugador
    for (int intentos = 1; intentos <= 10 && !ganaste; ++intentos)
    {
        correctas = 0; // Reiniciamos el contador de dígitos correctos para cada intento
        cout << "Intento " << intentos << ": \n";
        //Ingresar numero
        for (int i = 0; i < 4; i++) {
            char input;
            do {
                cout << "Ingrese el numero " << 1 + i << " (1-6) ==>";
                cin >> input;

                // Validar si el caracter ingresado es un número
                if (!esNumero(input)) {
                    cout << "Caracter no valido. Ingrese un numero del 1 al 6." << endl;
                }
            } while (!esNumero(input));

            // Convertir el caracter a un número entero
            numerosUsuario[i] = input - '0';
        }
        //Verificar numeros
        for (int j = 0; j < 4; j++) {
            if (numerosUsuario[j] == numerosBase[j]) {
                cout << "|C|";
                correctas++;
                if (correctas == 4) {
                    cout << "\nGanaste\n";
                    ganaste = true; // Cambiamos la variable ganaste a verdadero para salir del bucle
                    break; // Salimos del bucle for porque ya adivinó la clave
                }
            }
            else if (numerosUsuario[j] == numerosBase[0] || numerosUsuario[j] == numerosBase[1] || numerosUsuario[j] == numerosBase[2] || numerosUsuario[j] == numerosBase[3])
            {
                cout << "|F|";
            }
            else {
                cout << "|X|";
            }
        }
        cout << endl; // Agregamos una nueva línea después de imprimir cada intento
    }

    if (!ganaste) {
        cout << "Perdiste. El patrón oculto era: ";
        for (int i = 0; i < 4; ++i) {
            cout << numerosBase[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
