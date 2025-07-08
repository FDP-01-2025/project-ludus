#include "header.h"
using namespace std;

players player1; //struct que se usa en todas las librerias

// Define the global player variable that header.cpp expects
players player;

void principalMenu(players& p);

int main() {
    showTitle(); // Translated function name

    int option;
    do {
        cout << "\n----- MENÚ PRINCIPAL -----\n";
        cout << "  1. Un jugador\n";
        cout << "  2. Salir\n";
        cout << "Selecciona una opción: ";
        cin >> option;
        cin.ignore();

        switch (option) {
            case 1:
                validateNames(player1); // validates name and age
                player1.wallet = 1000;
                player1.chosenRace = {"", "", "", 0};
                player = player1; // Set global player for functions to use
                principalMenu(player1); // main menu for single player
                break;

            case 2:
                cout << "\n¡Gracias por jugar! 🏁 ¡Nos vemos la próxima vez, piloto!\n";
                break;

            default:
                cout << "Opción inválida. Por favor, intenta de nuevo.\n";
        }

    } while (option != 2);

    return 0;
}

void principalMenu(players& p){
    int opcion;
    
    // Welcome message
    cout << "\n*************************" << endl;
    cout << " 🏁🏁🏁 BIENVENIDO " << p.userName << " 🏁🏁🏁" << endl;
    cout << "*************************" << endl;
    cout << "Tu saldo actual: $" << p.wallet << endl;

    do {
        cout << "\n--- Flujo del Juego ---\n";
        cout << "1. Elegir pista y empezar carrera\n";
        cout << "2. Mostrar autos\n";
        cout << "3. Sistema de apuestas\n";
        cout << "4. Salir al menú principal\n";
        cout << "Selecciona una opción: ";
        cin >> opcion;
        cin.ignore();

        // Update global player before calling functions
        player = p;

        switch (opcion) {
            case 1:
                // Complete race flow: Track → Cars → Betting
                cout << "\n=== PASO 1: ELIGE TU PISTA ===\n";
                tracksF1(); // choose track
                
                cout << "\n=== PASO 2: CONOCE A LOS PILOTOS ===\n";
                startF1Simulator(); // show cars
                
                cout << "\n=== PASO 3: HAZ TU APUESTA ===\n";
                cout << "Tu saldo disponible: $" << player.wallet << endl;
                startBettingSystem(); // manage bets
                
                // After race, show post-race menu
                postRaceMenu(player);
                break;
            case 2:
                startF1Simulator(); // show cars only
                break;
            case 3:
                cout << "Tu saldo disponible: $" << player.wallet << endl;
                startBettingSystem(); // manage bets only
                break;
            case 4:
                cout << "\nRegresando al menú principal. ¡Hasta luego " << p.userName << "!\n";
                break;
            default:
                cout << "Opción inválida. Por favor, intenta de nuevo.\n";
        }
        
        // Update local player with any changes from global
        p = player;
    } while (opcion != 4);
}