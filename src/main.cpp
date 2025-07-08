#include "header.h"
using namespace std;

players player1; 

// Define the global player variable that header.cpp expects
players player;

void principalMenu(players& p);

int main() {
    showTitle(); // Translated function name

    int option;
    do {
        cout << "\n----- MENÚ PRINCIPAL -----\n";
        cout << "  1. Jugar\n";
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
                cout << "\n¡Gracias por jugar!  ¡Nos vemos la próxima vez, piloto!\n";
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
    cout << "  BIENVENIDO " << p.userName << " " << endl;
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

void multiplayer(players& p1, players& p2) {
    cout << "\n--- Multiplayer Race ---\n";

    cout << "\n" << p1.userName << " choose your track:\n";
    player = p1; // Set global player for player 1
    tracksF1();

    cout << "\n" << p2.userName << " choose your track:\n";
    player = p2; // Set global player for player 2
    tracksF1();

    cout << "\nBoth players bet:\n";
    cout << p1.userName << " places bet:\n";
    player = p1; // Set global player for player 1
    startBettingSystem();
    p1 = player; // Update player 1 with changes
    
    cout << p2.userName << " places bet:\n";
    player = p2; // Set global player for player 2
    startBettingSystem();
    p2 = player; // Update player 2 with changes

    cout << "\nSimulating race between " << p1.userName << " and " << p2.userName << "...\n";
    player = p1; // Simulate for player 1
    startF1Simulator();
    
    player = p2; // Simulate for player 2
    startF1Simulator();

    // then you can compare times and declare a winner
}

void postRaceMenu(players& p) {
    int option;
    
    do {
        cout << "\n🏁 RACE COMPLETED! 🏁\n";
        cout << "Current balance: $" << p.wallet << endl;
        cout << "\n--- What would you like to do next? ---\n";
        cout << "1. Race again (Choose track → Cars → Bet)\n";
        cout << "2. Choose different track\n";
        cout << "3. View cars\n";
        cout << "4. View history\n";
        cout << "5. Return to main menu\n";
        cout << "Select an option: ";
        cin >> option;
        if (!(cin >> option)) { //validacion para admitir solo numeros
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        cin.ignore();
        
        // Update global player
        player = p;
        
        switch (option) {
            case 1:
                // Complete race flow again
                cout << "\n=== NEW RACE - STEP 1: CHOOSE YOUR TRACK ===\n";
                tracksF1();
                
                cout << "\n=== NEW RACE - STEP 2: MEET THE DRIVERS ===\n";
                startF1Simulator();
                
                cout << "\n=== NEW RACE - STEP 3: PLACE YOUR BET ===\n";
                cout << "Your available balance: $" << player.wallet << endl;
                startBettingSystem();
                
                // Recursive call for another post-race menu
                p = player;
                postRaceMenu(p);
                return;
                
            case 2:
                cout << "\n=== CHOOSE NEW TRACK ===\n";
                tracksF1();
                break;
                
            case 3:
                cout << "\n=== VIEW CARS ===\n";
                startF1Simulator();
                break;
                
            case 4:
                cout << "\n=== YOUR HISTORY ===\n";
                showHistory();
                break;
                
            case 5:
                cout << "\nReturning to main menu...\n";
                break;
                
            default:
                cout << "Invalid option. Please try again.\n";
        }
        
        // Update local player with changes
        p = player;
        
    } while (option != 5);
}