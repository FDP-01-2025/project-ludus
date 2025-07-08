#include "header.h"
using namespace std;

players player1, player2; //struct que se usa en todas las librerias

// Define the global player variable that header.cpp expects
players player;

void principalMenu(players& p);
void multiplayer(players& p1, players& p2);
void postRaceMenu(players& p);

int main() {
    showTitle(); // Translated function name

    int option;
    do {
        cout << "\n----- MAIN MENU -----\n";
        cout << "  1. Single player\n";
        cout << "  2. Multiplayer (2 players)\n";
        cout << "  3. Exit\n";
        cout << "Select an option: ";
        cin >> option;
        if (!(cin >> option)) { //validacion para admitir solo numeros
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        cin.ignore();

        switch (option) {
            case 1:
                validateNames(player1); // validates name and age
                player1.wallet = 1000000.00;
                player1.chosenRace = {"", "", "", 0};
                player = player1; // Set global player for functions to use
                principalMenu(player1); // main menu for single player
                break;

            case 2:
                cout << "\n=== PLAYER 1 ===\n";
                validateNames(player1);
                player1.wallet = 1000000.00;
                player1.chosenRace = {"", "", "", 0};

                cout << "\n=== PLAYER 2 ===\n";
                validateNames(player2);
                if (player2.userName == player1.userName) {
                    cout << "Los jugadores no pueden tener el mismo nombre. Elija otro por favor.\n"; // Volver a pedir nombre...
                    }
                player2.wallet = 1000000.00;
                player2.chosenRace = {"", "", "", 0};

                // Multiplayer function
                multiplayer(player1, player2);
                break;

            case 3:
                cout << "\nThanks for playing 🏁 See you next time, pilot!\n";
                break;

            default:
                cout << "Invalid option. Please try again.\n";
        }

    } while (option != 3);

    return 0;
}

void principalMenu(players& p){
    int opcion;
    
    // Welcome message
    cout << "\n*************************" << endl;
    cout << " 🏁🏁🏁 WELCOME " << p.userName << " 🏁🏁🏁" << endl;
    cout << "*************************" << endl;
    cout << "Your current balance: $" << p.wallet << endl;

    do {
        cout << "\n--- Game Flow ---\n";
        cout << "1. Choose track and start race\n";
        cout << "2. Show cars\n";
        cout << "3. Betting system\n";
        cout << "4. History\n";
        cout << "5. Exit to main menu\n";
        cout << "Select an option: ";
        cin >> opcion;
        if (!(cin >> option)) { //validacion para admitir solo numeros
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        cin.ignore();

        // Update global player before calling functions
        player = p;

        switch (opcion) {
            case 1:
                // Complete race flow: Track → Cars → Betting
                cout << "\n=== STEP 1: CHOOSE YOUR TRACK ===\n";
                tracksF1(); // choose track
                
                cout << "\n=== STEP 2: MEET THE DRIVERS ===\n";
                startF1Simulator(); // show cars
                
                cout << "\n=== STEP 3: PLACE YOUR BET ===\n";
                cout << "Your available balance: $" << player.wallet << endl;
                startBettingSystem(); // manage bets
                
                // After race, show post-race menu
                postRaceMenu(player);
                break;
            case 2:
                startF1Simulator(); // show cars only
                break;
            case 3:
                cout << "Your available balance: $" << player.wallet << endl;
                startBettingSystem(); // manage bets only
                break;
            case 4:
                showHistory(); // show previous actions
                break;
            case 5:
                cout << "\nReturning to main menu. See you later " << p.userName << "!\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }
        
        // Update local player with any changes from global
        p = player;
    } while (opcion != 5);
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

    cout << "\nHistory of " << p1.userName << " and " << p2.userName << "...\n"; 
    player = p1; // Show history for player 1
    showHistory();
    
    player = p2; // Show history for player 2
    showHistory();

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