#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <mmsystem.h> //libreria de sonido
using namespace std;

players player; //struct que se usa en todas las librerias

int main() {
    mostrar_titulo();
    system("timeout /t 2 >nul");
    system("cls");

    int opcion = 0;
    int jugador_seleccionado = 0;

    do {
        mostrar_menu();
        cin >> opcion;

        switch(opcion) {
            case 1:
                jugador_seleccionado = seleccionar_jugador();
                iniciar_partida(jugador_seleccionado);
                break;

            case 2:
                cout << "Saliendo del programa......." << endl;
                system("pause");
                break;

            default:
                cout << "Opcion no valida, intente otra vez." << endl;
                system("pause");
                system("cls");
        }

    } while (opcion != 2);

    return 0;
}
