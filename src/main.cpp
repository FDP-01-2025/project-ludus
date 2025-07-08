#include "header.h"
using namespace std;

// Define the global player variable that header.cpp expects
players player;

void principalMenu(players& p);

int main() {
    showTitle();

    int option;
    do {
        cout << "\n----- MENU PRINCIPAL -----\n";
        cout << "  1. Jugar\n";
        cout << "  2. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> option;
        cin.ignore();

        switch (option) {
            case 1:
                validateNames(player); // validates name and age
                player.wallet = 1000;
                player.chosenRace = {"", "", "", 0};
                principalMenu(player); // main menu for single player
                break;

            case 2:
                cout << "\nGracias por jugar! Nos vemos la proxima vez, piloto!\n";
                break;

            default:
                cout << "Opcion invalida. Por favor, intenta de nuevo.\n";
        }

    } while (option != 2);

    return 0;
}

void principalMenu(players& p){
    int opcion;
    
    // Welcome message
    cout << "\n*************************" << endl;
    cout << "  BIENVENIDO " << p.userName << " " << endl;
    cout << "*************************" << endl;
    cout << "Tu saldo actual: $" << p.wallet << endl;

    do {
        cout << "\n--- Que quieres hacer? ---\n";
        cout << "1. JUGAR CARRERA COMPLETA (Pista -> Piloto -> Apuesta -> Carrera)\n";
        cout << "2. Ver autos y pilotos\n";
        cout << "3. Solo apostar\n";
        cout << "4. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;
        cin.ignore();

        // Update global player before calling functions
        player = p;

        switch (opcion) {
            case 1:
                cout << "\nEMPEZAMOS LA EXPERIENCIA COMPLETA!\n";
                
                cout << "\n=== PASO 1: ELIGE TU PISTA ===\n";
                tracksF1();
                
                cout << "\n=== PASO 2: ELIGE TU PILOTO ===\n";
                startF1Simulator();
                
                cout << "\n=== PASO 3: HAZ TU APUESTA ===\n";
                cout << "Tu saldo disponible: $" << player.wallet << endl;
                startBettingSystem();
                
                p = player;
                break;
            case 2:
                cout << "\nMOSTRANDO AUTOS Y PILOTOS\n";
                startF1Simulator();
                break;
            case 3:
                cout << "\nSISTEMA DE APUESTAS\n";
                cout << "Tu saldo disponible: $" << player.wallet << endl;
                startBettingSystem();
                p = player;
                break;
            case 4:
                cout << "\nHasta luego " << p.userName << "! Gracias por jugar!\n";
                break;
            default:
                cout << "Opcion invalida. Por favor, intenta de nuevo.\n";
        }
        
        // Update local player with any changes from global
        p = player;
    } while (opcion != 4);
}