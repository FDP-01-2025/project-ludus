#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <mmsystem.h> //libreria de sonido
using namespace std;
void mostrar_titulo() {
system("cls");
    cout << R"(
 .----------------.  .----------------. 
| .--------------. || .--------------. |
| |  _________   | || |     __       | |
| | |_   ___  |  | || |    /  |      | |
| |   | |_  \_|  | || |    `| |      | |
| |   |  _|      | || |     | |      | |
| |  _| |_       | || |    _| |_     | |
| | |_____|      | || |   |_____|    | |
| |              | || |              | |
| '--------------' || '--------------' |
 '----------------'  '----------------  

)" << endl;


    cout << "****************" << endl;
    cout << "MENU DEL JUEGO" << endl;
    cout << "****************" << endl;
}

void mostrar_menu() 
{
    cout << "1 - Jugar" << endl;
    cout << "2 - Salir" << endl;
    cout << "Ingrese opcion: ";
}

int seleccionar_jugador() 
{
    system("cls");
    cout << "Jugadores disponibles:" << endl;
    cout << "1. Yuki Tsunoda" << endl;
    cout << "2. Oscar Piastri" << endl;
    cout << "3. Andrea Kimi" << endl;
    cout << "4. Franco Colapinto" << endl;
    cout << "5. Oliver Bearman" << endl;
    cout << "Seleccione jugador (1-5): ";

    int eleccion;
    cin >> eleccion;
    while (eleccion < 1 || eleccion > 5) {
        cout << "opcion invalida, intente otra vez: ";
        cin >> eleccion;
    }
    system("cls");
    return eleccion;
}

void mostrar_jugador_elegido (int jugador) {
    cout << "Has elegido a ";

    switch (jugador)
     {
        case 1: cout << "Yuki Tsunoda."; break;
        case 2: cout << "Oscar Piastri."; break;
        case 3: cout << "Andrea Kimi."; break;
        case 4: cout << "Franco Colapinto."; break;
        case 5: cout << "Oliver Bearman."; break;
        default: cout << "Nadie."; break;
    }
    cout << endl;
}

void iniciar_partida(int jugador) {
    system("cls");
    mostrar_jugador_elegido(jugador);
    cout << "¡Partida iniciada!" << endl;
    system("pause");
    system("cls");
}

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