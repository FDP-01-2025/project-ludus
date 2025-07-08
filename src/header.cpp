#include "header.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <cstring>
#include <string> 
#include <cstdlib>
#include <thread>
#include <chrono>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;
extern players player; //this is declared in main.cpp globally

// Cross-platform sleep function
void sleepMs(int milliseconds) {
    #ifdef _WIN32
        Sleep(milliseconds);
    #else
        this_thread::sleep_for(chrono::milliseconds(milliseconds));
    #endif
}

//Login and user functions 

void showTitle() {
    system("cls");

    cout << R"(
].----------------.   .----------------. 
| .--------------. | | .--------------. |
| |  _________   | | | |     __       | |
| | |_   ___  |  | | | |    /  |      | |
| |   | |_  \_|  | | | |    `| |      | |
| |   |  _|      | | | |     | |      | |
| |  _| |_       | | | |    _| |_     | |
| | |_____|      | | | |   |_____|    | |
| |              | | | |              | |
| '--------------' | | '--------------' |
 '----------------'   '----------------'

)" << endl;
    cout << " 🚗💨 WELCOME TO THE 🚦 Random Racing Luck GAME " << endl;
}

bool onlyLetters(const string& str) {
for (char c : str) {
if (!isalpha(c) && c != ' ') {
            return false;
        }
    }
    return !str.empty(); // Make sure it's not empty
}

//login principal

void validateNames(players& p) {
    cout << "*************************" << endl;
    cout << " WELCOME TO THE GAME" << endl;
    cout << "*************************" << endl;

    do {
        cout << "Player name (only letters allowed): ";
        getline(cin, p.userName);
        p.userName.erase(0, p.userName.find_first_not_of(" "));
        p.userName.erase(p.userName.find_last_not_of(" ") + 1);

        if (!onlyLetters(p.userName)) {
            cout << "Error: The name must only contain letters and spaces. Please try again.\n";
        }
    } while (!onlyLetters(p.userName));

    cout << "Age: ";
    cin >> p.age;
    cin.ignore();
}


//Race track functions
 
//this function helps us show the ascii of the tracks
void showAsciiTrack(string nameArchive) {
    ifstream Archive(nameArchive);
    if (!Archive) {
        cout << "Could not open the file: " << nameArchive << endl;
        return;
    }

    string line;
    while (getline(Archive, line)) {
        cout << line << endl;
    }

    Archive.close();
}

//we create the tracks function
void tracksF1() {
    Rtracks tracks [5]{
        {" SilverStone", " Reino Unido", " Alta", 5.896 },
        {" Monza"," Italia" ," Media", 5.793},
        {" Suzuka"," Japón", " Alta", 5.807},
        {" Interlagos", " Brasil", " Alta", 5.470},
        {" Monaco", " Mónaco", " Baja", 3.330}

    };
 //Here with the for loop we show the name of each track
    cout << "\n=== PISTAS DISPONIBLES ===\n";
    for(int i=0;i<5;i++){
        cout<< i+1<< "." << tracks[i].name<<endl;
    };

    int option;

    cout<<"\n¡Selecciona una pista! (1-5): ";
    cin>> option;
    cin.ignore(); // Limpiar buffer

    if (option <1 ||option >5){
        cout<<"Opción inválida"<<endl;
        return;
    }

    Rtracks Selection = tracks [option-1];
    cout<< "\n=== INFORMACIÓN DE LA PISTA ===\n";
    cout<<"Nombre: "<<Selection.name<<endl;
    cout<<"Ubicación: "<<Selection.located<<endl;
    cout<<"Dificultad: "<<Selection.difficulty_Level<<endl;
    cout<<"Longitud: "<<Selection.large_km<<" km"<<endl;

    string namesTrack_Archive[5] = {
        //files
        "sliverstone.txt",
        "monza.txt",
        "suzuka.txt",
        "interlagos.txt",
        "monaco.txt",
    };

    cout << "\n=== VISTA DE LA PISTA ===\n";
    showAsciiTrack(namesTrack_Archive[option - 1]);
    
    cout << "\nPresiona ENTER para continuar...";
    cin.get();
}

//Car functions

// Max Verstappen's car
void drawCar1() {
    cout << YELLOW << "          *   \n";
    cout << YELLOW << "         / \\\n";
    cout << ORANGE << "        / _ \\\n";
    cout << WHITE << "    (O)-| | |-(o)\n";
    cout << YELLOW << "       | |_| |\n";
    cout << BLUE << "       /_\\ /_\\\n";
    cout << RED << "      |---|---|\n";
    cout << BLUE << "       \\_/ \\_/\n";
    cout << WHITE << "  (o)---/\\_/\\---(o)\n";
    cout << RED << "        |___|\n";
    cout << YELLOW << "         \\_/\n";
    cout << WHITE << "          | \n";
    cout << ORANGE << "      ]-------[\n";
}

// Sergio Pérez's car
void drawCar2() {
    cout << YELLOW << "        __\n";
    cout << YELLOW << "       |  |\n";
    cout << RED << "       |  | \n";
    cout << WHITE << "  (O)-||__||-(O)\n";
    cout << BLUE << "     | |  | |\n";
    cout << BLACK << "     / \\  / \\\n";
    cout << BLACK << "     \\ /  \\ / \n";
    cout << BLUE << "      |    |\n";
    cout << WHITE << "(O)--|______|--(O)\n";
    cout << YELLOW << "      __\\/__\n";
    cout << ORANGE << "     | |  | | \n";
    cout << RED << "     / \\  / \\ \n";
    cout << RED << "     ***  *** \n";
}

// Lewis Hamilton's car
void drawCar3() {
    cout << YELLOW << "         _   \n";
    cout << YELLOW << "        / \\\n";
    cout << ORANGE << "       | _ |\n";
    cout << WHITE << "   (O)-| | |-(o)\n";
    cout << YELLOW << "      _| | |_\n";
    cout << BLUE << "      /_\\ /_\\\n";
    cout << RED << "     )|-----|(\n";
    cout << BLUE << "      \\_/ \\_/\n";
    cout << WHITE << " (o)---/\\_/\\---(o)\n";
    cout << RED  << "       |___|\n";
    cout << YELLOW << "        \\_/\n";
    cout << WHITE << "         | \n";
    cout << ORANGE << "     ]*******[\n";
}

// George Russell's car
void drawCar4() {
    cout << CYAN << "         ___   \n";
    cout << MAGENTA << "        |   |\n";
    cout << WHITE << "        | o |\n";
    cout << BLUE << "    (O)-|___|-(O)\n";
    cout << CYAN << "       /|   |\\\n";
    cout << GREEN << "      / |___| \\\n";
    cout << YELLOW << "     |  |---|  |\n";
    cout << RED << "      \\ |   | /\n";
    cout << WHITE << "  (o)--\\|___|/--(o)\n";
    cout << MAGENTA << "       /|   |\\\n";
    cout << CYAN << "        |___|\n";
    cout << BLUE << "         |_|\n";
    cout << GREEN << "     [=========]\n";
}

// Charles Leclerc's car
void drawCar5() {
    cout << RED << "         /^\\\n";
    cout << RED << "        |   |\n";
    cout << YELLOW << "        | F |\n";
    cout << WHITE << "    (O)-|___|-(O)\n";
    cout << RED << "       /|   |\\\n";
    cout << BLACK << "      / |___| \\\n";
    cout << RED << "     |   ---   |\n";
    cout << YELLOW << "      \\ |   | /\n";
    cout << WHITE << "  (o)--\\|___|/--(o)\n";
    cout << RED << "       ||   ||\n";
    cout << BLACK << "        |___|\n";
    cout << RED << "         |*|\n";
    cout << YELLOW << "     [*Ferrari*]\n";
}

// Carlos Sainz's car
void drawCar6() {
    cout << RED << "        ^^^^^\n";
    cout << YELLOW << "       |     |\n";
    cout << RED << "       | 06  |\n";
    cout << WHITE << "   (O)-|_____|-(O)\n";
    cout << BLACK << "      /|     |\\\n";
    cout << RED << "     / |_____| \\\n";
    cout << YELLOW << "    |  ||---||  |\n";
    cout << RED << "     \\ |     | /\n";
    cout << WHITE << "(o)---\\|_____|/---(o)\n";
    cout << BLACK << "      ||     ||\n";
    cout << RED << "       |_____|\n";
    cout << YELLOW << "        |___|\n";
    cout << RED << "    [***SAINZ***]\n";
}

// Lando Norris's car
void drawCar7() {
    cout << ORANGE << "         /~\\\n";
    cout << BLUE << "        |   |\n";
    cout << ORANGE << "        | 7 |\n";
    cout << WHITE << "    (O)-|___|-(O)\n";
    cout << BLUE << "       /|   |\\\n";
    cout << ORANGE << "      / |___| \\\n";
    cout << BLACK << "     |  |***|  |\n";
    cout << BLUE << "      \\ |   | /\n";
    cout << WHITE << "  (o)--\\|___|/--(o)\n";
    cout << ORANGE << "       /|   |\\\n";
    cout << BLUE << "        |___|\n";
    cout << ORANGE << "         |_|\n";
    cout << BLACK << "     [McLAREN]\n";
}

// Oscar Piastri's car
void drawCar8() {
    cout << ORANGE << "        /==\\\n";
    cout << BLACK << "       |    |\n";
    cout << ORANGE << "       | 08 |\n";
    cout << WHITE << "   (O)-|____|-(O)\n";
    cout << BLUE << "      /|    |\\\n";
    cout << ORANGE << "     / |____| \\\n";
    cout << BLACK << "    |  |****|  |\n";
    cout << ORANGE << "     \\ |    | /\n";
    cout << WHITE << "(o)---\\|____|/---(o)\n";
    cout << BLUE << "      /|    |\\\n";
    cout << ORANGE << "       |____|\n";
    cout << BLACK << "        |**|\n";
    cout << ORANGE << "    [*PIASTRI*]\n";
}

// Fernando Alonso's car
void drawCar9() {
    cout << GREEN << "         /^\\\n"; 
    cout << BLACK << "        |   |\n";
    cout << GREEN << "        |09 |\n";
    cout << WHITE << "    (O)-|___|-(O)\n";
    cout << BLACK << "       /|   |\\\n";
    cout << GREEN << "      / |___| \\\n";
    cout << BLACK << "     |  |###|  |\n";
    cout << GREEN << "      \\ |   | /\n";
    cout << WHITE << "  (o)--\\|___|/--(o)\n";
    cout << BLACK << "       ||   ||\n";
    cout << GREEN << "        |___|\n";
    cout << BLACK << "         |#|\n";
    cout << GREEN << "     [ALONSO]\n";
}

// Lance Stroll's car
void drawCar10() {
    cout << GREEN << "        /-\\\n";
    cout << BLACK << "       |   |\n";
    cout << GREEN << "       |10 |\n";
    cout << WHITE << "   (O)-|___|-(O)\n";
    cout << GREEN << "      /|   |\\\n";
    cout << BLACK << "     / |___| \\\n";
    cout << GREEN << "    |  |&&&|  |\n";
    cout << BLACK << "     \\ |   | /\n";
    cout << WHITE << "(o)---\\|___|/---(o)\n";
    cout << GREEN << "      /|   |\\\n";
    cout << BLACK << "       |___|\n";
    cout << GREEN << "        |&|\n";
    cout << BLACK << "    [STROLL]\n";
}

// Custom car 1 - Sports style
void drawCar11() {
    cout << MAGENTA << "        /***\\\n";
    cout << CYAN << "       |     |\n";
    cout << MAGENTA << "       | ??? |\n";
    cout << WHITE << "   (O)-|_____|-(O)\n";
    cout << CYAN << "      /|     |\\\n";
    cout << MAGENTA << "     / |_____| \\\n";
    cout << YELLOW << "    |  |+++++|  |\n";
    cout << CYAN << "     \\ |     | /\n";
    cout << WHITE << "(o)---\\|_____|/---(o)\n";
    cout << MAGENTA << "      /|     |\\\n";
    cout << CYAN << "       |_____|\n";
    cout << MAGENTA << "        |+++|\n";
    cout << YELLOW << "    [*SPORT*]\n";
}

// Custom car 2 - Classic style
void drawCar12() {
    cout << BLUE << "         ====\n";
    cout << WHITE << "        |    |\n";
    cout << BLUE << "        | ## |\n";
    cout << WHITE << "    (O)-|____|-(O)\n";
    cout << YELLOW << "       /|    |\\\n";
    cout << BLUE << "      / |____| \\\n";
    cout << WHITE << "     |  |@@@@|  |\n";
    cout << YELLOW << "      \\ |    | /\n";
    cout << WHITE << "  (o)--\\|____|/--(o)\n";
    cout << BLUE << "       ||    ||\n";
    cout << WHITE << "        |____|\n";
    cout << BLUE << "         |@@|\n";
    cout << YELLOW << "     [SPECIAL]\n";
}


//Simulator functions 

// This function shows me all the teams in a list
void showTeams(Team teams[]) {
    cout << "\n=== LISTA DE EQUIPOS ===\n";
    for (int i = 0; i < howManyTeams; i++) {
        cout << i + 1 << ". " << teams[i].teamName << endl;
    }
}

// This one shows me the pilots of a specific team
void showPilots(Team team) {
    cout << "\n=== PILOTOS DE " << team.teamName << " ===\n";
    for (int i = 0; i < pilotsPerTeam; i++) {
        cout << i + 1 << ". " << team.pilots[i].name << " (ID: " << team.pilots[i].id << ")\n";
    }
}

// This function reads an extra pilot from a file
bool loadPilot(Pilot &p) {
    ifstream archivo("piloto_extra.txt");
    if (!archivo.is_open()) return false;  // In case the file can't be opened

    getline(archivo, p.name);
    archivo >> p.id;
    archivo.ignore();
    getline(archivo, p.carModel);     // This is the plate 
    getline(archivo, p.modelType);      // Sports or Classic
    getline(archivo, p.teamName);   // Custom team name
    archivo.close();
    return true;
}

// This function saves a new pilot to a file
void createPilot() {
    ofstream archivo("piloto_extra.txt");
    if (!archivo.is_open()) {
        cout << "Error: No se pudo crear el archivo.\n";
        archivo.close();
        return;
    }

    string pilotName, carType, teamName, carPlate;
    int pilotId;
    
    // Pilot name validation (letters and spaces)
    pilotName = askName("¿Cuál es el nombre de tu piloto?: ");
    
    // Pilot ID validation
    cout << "¿Qué ID le damos? (1-999): ";
    pilotId = askNumber(1, 999);
    
    // Team name validation (letters and spaces)
    teamName = askName("¿Cuál es el nombre de tu equipo?: ");
    
    // Car model validation
    cout << "\n=== ¿QUÉ AUTO QUIERES? ===\n";
    cout << "1. Auto Deportivo\n";
    cout << "2. Auto Clásico\n";
    cout << "¿Cuál te gusta más? (1-2): ";
    
    int carOption = askNumber(1, 2);
    
    // Assign plate automatically according to car type
    if (carOption == 1) {
        carPlate = "SPORT-" + to_string(pilotId);
        carType = "Sports";
    } else {
        carPlate = "CLASSIC-" + to_string(pilotId);
        carType = "Classic";
    }
    
    // Show a preview of the chosen car
    cout << "\n=== ASÍ SE VE TU AUTO ===\n";
    if (carOption == 1) {
        drawCar11();
    } else {
        drawCar12();
    }

    // Save: name, id, car plate, car model, team name
    archivo << pilotName << "\n" << pilotId << "\n" << carPlate << "\n" << carType << "\n" << teamName << endl;
    archivo.close();
    cout << GREEN << "\n¡Genial! Tu piloto está guardado\n" << RESET;
    
    // Now show the complete information of the created pilot
    cout << "\n=== AQUÍ ESTÁ TU PILOTO ===\n";
    cout << "Nombre: " << pilotName << endl;
    cout << "ID: " << pilotId << endl;
    cout << "Placa del auto: " << carPlate << endl;
    cout << "Equipo: " << teamName << endl;
    
    cout << "\n=== TU AUTO F1 ===\n";
    // Draw the car according to the chosen type
    if (carType == "Sports") {
        drawCar11();
    } else {
        drawCar12();
    }
}

// This function shows the available cars to choose from
void viewCars() {
    cout << "\n-- CAR 1: SPORTS --\n";
    drawCar11();
    cout << "\n-- CAR 2: CLASSIC --\n";
    drawCar12();
}

// Main function of the F1 simulator (equivalent to the original main)
void startF1Simulator() {
    // Here are all the teams with their pilots
    
    Team teams[howManyTeams] = {
        {"Red Bull", {
            {"Max Verstappen", 1, "RB20", "", ""},
            {"Sergio Perez", 2, "RB18", "", ""}
        }},
        {"Mercedes", {
            {"Lewis Hamilton", 3, "W15", "", ""},
            {"George Russell", 4, "W12", "", ""}
        }},
        {"Ferrari", {
            {"Charles Leclerc", 5, "SF-27", "", ""},
            {"Carlos Sainz", 6, "SF-24", "", ""}
        }},
        {"McLaren", {
            {"Lando Norris", 7, "MCL38", "", ""},
            {"Oscar Piastri", 8, "MCL32", "", ""}
        }},
        {"Aston Martin", {
            {"Fernando Alonso", 9, "AMR24", "", ""},
            {"Lance Stroll", 10, "AMR23", "", ""}
        }}
    };

    // Try to read if there's an extra pilot saved
    Pilot extraPilot;
    bool hasExtraPilot = loadPilot(extraPilot);

    // Ask the user what they want to do
    int whatToDo;
    cout << "\n=== BIENVENIDO A LA SIMULACIÓN F1 ===\n";
    cout << "1. Ver pilotos y elegir uno\n";
    cout << "2. Crear tu propio piloto con auto personalizado\n";
    cout << "¿Qué quieres hacer?: ";
    whatToDo = askNumber(1, 2);

    // If they want to add a new pilot
    if (whatToDo == 2) {
        cout << "\n=== CREADOR DE PILOTO PERSONALIZADO ===\n";
        viewCars();
        createPilot();
        cout << "\nPresiona ENTER para continuar...";
        cin.ignore();
        cin.get();
        return;
    }

    int chosenTeam, chosenPilot;

    // Show the teams to choose from
    showTeams(teams);
    cout << "\n¿Qué equipo te gusta? (1-" << howManyTeams << "): ";
    chosenTeam = askNumber(1, howManyTeams);

    // Show the pilots of the chosen team
    showPilots(teams[chosenTeam - 1]);

    cout << "\n¿Qué piloto eliges? (1-" << pilotsPerTeam;
    if (hasExtraPilot) cout << " o 3 para piloto extra";
    cout << "): ";
    chosenPilot = askNumber(1, hasExtraPilot ? 3 : 2);

    Pilot myPilot;

    // Decide which pilot to use
    if (chosenPilot == 3 && hasExtraPilot) {
        myPilot = extraPilot;  // Use the extra pilot
    } else {
        myPilot = teams[chosenTeam - 1].pilots[chosenPilot - 1];  // Use a normal pilot
    }

    // Show the chosen pilot's information
    cout << "\n=== INFORMACIÓN DEL PILOTO ===\n";
    cout << "Nombre: " << myPilot.name << endl;
    cout << "ID: " << myPilot.id << endl;
    cout << "Auto: " << myPilot.carModel << endl;
    cout << "Equipo: ";
    if (chosenPilot == 3 && hasExtraPilot)
        cout << myPilot.teamName << endl;  // Show the custom team
    else
        cout << teams[chosenTeam - 1].teamName << endl;

    cout << "\n=== AUTO F1 ===\n";

    // Draw the car according to the pilot's ID
    switch (myPilot.id) {
        case 1: drawCar1(); break;
        case 2: drawCar2(); break;
        case 3: drawCar3(); break;
        case 4: drawCar4(); break;
        case 5: drawCar5(); break;
        case 6: drawCar6(); break;
        case 7: drawCar7(); break;
        case 8: drawCar8(); break;
        case 9: drawCar9(); break;
        case 10: drawCar10(); break;
        default:
            // For custom pilots, look at the model type
            if (myPilot.modelType == "Sports") {
                drawCar11();
            } else if (myPilot.modelType == "Classic") {
                drawCar12();
            } else {
                cout << RED << "No hay auto disponible para este piloto.\n" << RESET;
            }
            break;
    }
    
    cout << "\nPresiona ENTER para continuar...";
    cin.ignore();
    cin.get();
}

//Betting functions

// Global variables for the betting system
vector<Bet> bettingHistory;
vector<Bettor> bettorRanking;

// Comentarios de los comentaristas durante las carreras
vector<string> raceComments = {
    "¡Qué arranque increíble! ¡Los motores están rugiendo!",
    "¡Adelantamiento asombroso en la curva 3! ¡La multitud está enloquecida!",
    "¡Está ganando terreno rápido! ¡Mira esa aceleración!",
    "¡Oh no! ¡Problemas técnicos para el líder!",
    "¡Qué maniobra defensiva! ¡Conducción magistral!",
    "¡Está escalando posiciones como un rayo!",
    "¡Los neumáticos empiezan a mostrar desgaste!",
    "¡Esa fue una maniobra extremadamente arriesgada!",
    "¡Esta carrera es absolutamente emocionante!",
    "¡Los espectadores están de pie!",
    "¡Frenado perfecto en la chicane!",
    "¡Qué batalla por el segundo lugar!",
    "¡Las condiciones climáticas son perfectas para correr!",
    "¡Está marcando un ritmo abrasador!",
    "¡Trabajo en equipo fantástico en esa parada en boxes!",
    "¡El líder del campeonato está bajo presión!",
    "¡Qué precisión en las curvas!",
    "¡La brecha se está cerrando rápidamente!",
    "¡Estrategia brillante desde el muro de boxes!",
    "¡Las últimas vueltas van a ser decisivas!",
    "¡Ha encontrado la línea de carrera perfecta!",
    "¡Qué demostración increíble de habilidad!",
    "¡La zona DRS está siendo crucial!",
    "¡Esa fue una maniobra de adelantamiento de manual!",
    "¡La tensión está aumentando para el tramo final!"
};

// Mensajes de felicitación
vector<string> congratulationMessages = {
    "¡FELICITACIONES! ¡Acertaste!",
    "¡GENIAL! ¡Tu piloto sí ganó!",
    "¡PERFECTO! ¡Elegiste bien!",
    "¡EXCELENTE! ¡Sabía que él ganaría!",
    "¡INCREÍBLE! ¡Qué suerte tienes!",
    "¡PERFECTO! ¡Eres bueno en esto!"
};

// Función para obtener el tipo de carro del piloto personalizado
string getCustomCarType() {
    ifstream archivo("piloto_extra.txt");
    if (!archivo.is_open()) return "Sports"; // Si no hay archivo, asume deportivo
    
    string nombre, placa, tipoModelo, equipo;
    int id;
    getline(archivo, nombre);
    archivo >> id;
    archivo.ignore();
    getline(archivo, placa);
    getline(archivo, tipoModelo);
    archivo.close();
    return tipoModelo;
}

// Función para mostrar el carro del piloto según su número
void showPilotCar(int pilotId) {
    switch (pilotId) {
        case 1: drawCar1(); break;
        case 2: drawCar2(); break;
        case 3: drawCar3(); break;
        case 4: drawCar4(); break;
        case 5: drawCar5(); break;
        case 6: drawCar6(); break;
        case 7: drawCar7(); break;
        case 8: drawCar8(); break;
        case 9: drawCar9(); break;
        case 10: drawCar10(); break;
        default: 
            // For user-created pilots
            string tipoCarro = getCustomCarType();
            if (tipoCarro == "Sports") {
                drawCar11();
            } else {
                drawCar12();
            }
            break;
    }
}

// Función para mostrar comentarios durante la carrera
void showComment() {
    static int lastIndex = -1;
    static int consecutiveCount = 0;
    static int commentVariety = 0;
    int indice;
    
    // Avoid repeating the same comment twice in a row
    do {
        indice = rand() % raceComments.size();
    } while (indice == lastIndex && raceComments.size() > 1);
    
    // Reset consecutive count if we changed comment
    if (indice != lastIndex) {
        consecutiveCount = 0;
    }
    
    lastIndex = indice;
    consecutiveCount++;
    commentVariety = (commentVariety + 1) % 5;
    
    // Add variety to the display format
    string prefix;
    switch (commentVariety) {
        case 0: prefix = "🎤 COMMENTATOR: "; break;
        case 1: prefix = "📻 RADIO: "; break;
        case 2: prefix = "🎬 TRACK REPORTER: "; break;
        case 3: prefix = "🏁 RACE CONTROL: "; break;
        default: prefix = "📺 BROADCAST: "; break;
    }
    
    cout << YELLOW << prefix << raceComments[indice] << RESET << endl;
}

// Función para mostrar comentarios específicos de vuelta
void showLapComment(int lapNumber) {
    vector<string> lapSpecificComments;
    
    switch (lapNumber) {
        case 1:
            lapSpecificComments = {
                "What a fantastic start to the race!",
                "The drivers are finding their rhythm!",
                "Early positioning will be crucial!",
                "The track conditions are perfect!",
                "Everyone's looking for the best racing line!"
            };
            break;
        case 2:
            lapSpecificComments = {
                "We're seeing some exciting battles mid-race!",
                "Strategy is starting to play a role!",
                "The pace is really picking up!",
                "Some drivers are making their move!",
                "The championship fight is heating up!"
            };
            break;
        case 3:
            lapSpecificComments = {
                "This is where champions are made!",
                "The final push is underway!",
                "Every position matters now!",
                "The tension is at its peak!",
                "What a thrilling finish we're witnessing!"
            };
            break;
        default:
            showComment();
            return;
    }
    
    int indice = rand() % lapSpecificComments.size();
    cout << CYAN << "🏁 LAP " << lapNumber << " UPDATE: " << lapSpecificComments[indice] << RESET << endl;
}

// Función para hacer la carrera completa
vector<RaceResult> simulateRace(vector<string> pilots, vector<int> ids, vector<string> teams) {
    vector<RaceResult> resultados;
    
    cout << GREEN << "\n🏁 THE RACE IS STARTING! 🏁\n" << RESET;
    cout << "===================================\n\n";
    
    // Initialize random seed with current time and additional entropy
    srand(time(0) + rand() + clock());
    
    // Give each pilot a truly random time
    for (size_t i = 0; i < pilots.size(); i++) {
        RaceResult resultado;
        resultado.pilotName = pilots[i];
        resultado.pilotId = ids[i];
        resultado.team = teams[i];
        
        // Base time (around 1:25-1:30)
        int tiempoBase = 85000 + (rand() % 5000);
        
        // Large random variation (up to 30 seconds difference)
        int variacionGrande = rand() % 30000;
        
        // Small random adjustments for fine-tuning
        int ajusteFino = (rand() % 10000) - 5000;
        
        // Additional randomness based on pilot position (but not deterministic)
        int factorPosicion = (rand() % 8000) - 4000;
        
        resultado.raceTime = tiempoBase + variacionGrande + ajusteFino + factorPosicion;
        
        // Ensure realistic times (between 1:20 and 2:00)
        if (resultado.raceTime < 80000) resultado.raceTime = 80000 + rand() % 5000;
        if (resultado.raceTime > 120000) resultado.raceTime = 115000 + rand() % 5000;
        
        resultados.push_back(resultado);
    }
    
    // Shuffle multiple times for maximum randomness
    for (int shuffle = 0; shuffle < 5; shuffle++) {
        random_shuffle(resultados.begin(), resultados.end());
    }
    
    // Sort by time (fastest wins)
    sort(resultados.begin(), resultados.end(), 
         [](const RaceResult& a, const RaceResult& b) {
             return a.raceTime < b.raceTime;
         });
    
    // Give them their position
    for (size_t i = 0; i < resultados.size(); i++) {
        resultados[i].position = i + 1;
    }
    
    // Show the race with dynamic car display
    cout << CYAN << "🏎️  The cars are positioning on the grid...\n" << RESET;
    
    // Show starting grid
    cout << "\n" << MAGENTA << "=== STARTING GRID ===\n" << RESET;
    for (size_t i = 0; i < pilots.size() && i < 5; i++) {
        cout << WHITE << "Position " << (i+1) << ": " << pilots[i] << " (" << teams[i] << ")\n" << RESET;
    }
    
    // Add realistic delay
    cout << "\n" << YELLOW << "⏱️  Warming up engines...\n" << RESET;
    sleepMs(1500);
    
    // Simulate race laps with varied display
    for (int lap = 1; lap <= 3; lap++) {
        cout << "\n" << MAGENTA << "🏁 === LAP " << lap << " === 🏁\n" << RESET;
        
        // Show different cars each lap (not always the same ones)
        vector<int> displayIndices;
        for (int i = 0; i < (int)resultados.size(); i++) {
            displayIndices.push_back(i);
        }
        random_shuffle(displayIndices.begin(), displayIndices.end());
        
        // Show 3-4 random cars during the lap
        int carsToShow = min(4, (int)resultados.size());
        for (int i = 0; i < carsToShow; i++) {
            int idx = displayIndices[i];
            cout << WHITE << "🏎️  Car: " << resultados[idx].pilotName 
                 << " (" << resultados[idx].team << ")\n" << RESET;
            showPilotCar(resultados[idx].pilotId);
            cout << "\n";
            sleepMs(800); // Visual pause between cars
        }
        
        // Show two different comments per lap
        showLapComment(lap);
        sleepMs(1000);
        showComment();
        
        cout << "\n" << CYAN << "⏱️  Processing lap " << lap << "...\n" << RESET;
        sleepMs(1200); // Pause between laps
    }
    
    // Final stretch simulation
    cout << "\n" << RED << "🔥 FINAL STRETCH! 🔥\n" << RESET;
    cout << "The leaders are giving everything they've got!\n";
    sleepMs(1000);
    
    // Show final positions battle
    cout << "\n" << YELLOW << "🏆 FINAL POSITIONS: 🏆\n" << RESET;
    for (int i = 0; i < 3 && i < (int)resultados.size(); i++) {
        cout << WHITE << (i+1) << ". " << resultados[i].pilotName 
             << " (" << resultados[i].team << ")\n" << RESET;
        sleepMs(500);
    }
    
    sleepMs(1000);
    cout << RED << "\n🏁 RACE FINISHED! 🏁\n" << RESET;
    cout << "===================\n";
    
    return resultados;
}

// Función para mostrar el podio al final
void showPodium(const vector<RaceResult>& results) {
    cout << "\n" << YELLOW << "🏆 ========== PODIUM ========== 🏆\n" << RESET;
    
    sleepMs(1000);
    
    for (int i = 0; i < 5 && i < (int)results.size(); i++) {
        string medal;
        string color;
        string emoji;
        
        switch (i) {
            case 0: medal = "🥇 1st"; color = YELLOW; emoji = "🎉"; break;
            case 1: medal = "🥈 2nd"; color = WHITE; emoji = "👏"; break;
            case 2: medal = "🥉 3rd"; color = ORANGE; emoji = "👍"; break;
            case 3: medal = "🏁 4th"; color = BLUE; emoji = "💪"; break;
            case 4: medal = "🏁 5th"; color = GREEN; emoji = "⭐"; break;
        }
        
        int minutes = results[i].raceTime / 60000;
        int seconds = (results[i].raceTime % 60000) / 1000;
        int milliseconds = results[i].raceTime % 1000;
        
        cout << color << medal << " place: " << emoji << " "
             << results[i].pilotName << " (" << results[i].team << ")\n";
        cout << "   ⏱️  Time: " << minutes << ":" << setfill('0') << setw(2) << seconds 
             << "." << setw(3) << milliseconds << RESET << "\n";
             
        sleepMs(800); // Pause between each position announcement
        cout << "\n";
    }
    
    // Show the winner's car with fanfare
    cout << YELLOW << "🏆 CHAMPION'S CAR 🏆\n" << RESET;
    sleepMs(500);
    showPilotCar(results[0].pilotId);
    cout << "\n" << YELLOW << "🎊 ¡FELICITACIONES AL GANADOR! 🎊\n" << RESET;
}

// Función para mostrar tipos de apuesta (sin saldo)
void showBetTypes() {
    cout << "\n" << CYAN << "=== BET TYPES ===\n" << RESET;
    cout << "1. GRAND TOTAL (2 races - Prize x3)\n";
    cout << "2. GRAND PRIX (1 race - Prize x2)\n";
    cout << "3. SPRINT (1 race - Prize x1.5)\n";
}

// Función para hacer una apuesta
void placeBet(const vector<string>& pilots, const vector<int>& ids, const vector<string>& teams) {
    // Show pre-race excitement
    showPreRaceExcitement();
    
    // Show race statistics
    showRaceStatistics(pilots, teams);
    
    showBetTypes();
    
    cout << "\n¿Qué tipo de apuesta quieres hacer? (1-3): ";
    int betType = askNumber(1, 3);
    
    string typeName;
    float multiplier;
    int numRaces;
    
    switch (betType) {
        case 1: 
            typeName = "Grand Total"; 
            multiplier = 3.0f; 
            numRaces = 2;
            break;
        case 2: 
            typeName = "Grand Prix"; 
            multiplier = 2.0f; 
            numRaces = 1;
            break;
        case 3: 
            typeName = "Sprint"; 
            multiplier = 1.5f; 
            numRaces = 1;
            break;
    }
    
    cout << "\n" << YELLOW << "Has elegido: " << typeName << RESET;
    if (numRaces == 2) {
        cout << ORANGE << " (¡Debes ganar ambas carreras!)" << RESET;
    }
    cout << "\n";
    
    // Show available pilots with enhanced display
    cout << "\n" << CYAN << "🏎️  AVAILABLE PILOTS 🏎️\n" << RESET;
    cout << "=============================\n";
    for (size_t i = 0; i < pilots.size(); i++) {
        cout << (i + 1) << ". " << WHITE << pilots[i] << RESET 
             << " (" << MAGENTA << teams[i] << RESET << ")\n";
    }
    cout << "=============================\n";
    
    cout << "\n¿En qué piloto quieres apostar? (1-" << pilots.size() << "): ";
    int chosenPilot = askNumber(1, (int)pilots.size()) - 1;
    
    cout << "\n" << CYAN << "💰 Saldo Actual: $" << player.wallet << RESET;
    cout << "\n¿Cuánto dinero quieres apostar?: $";
    int betAmount;
    cin >> betAmount;
    
    // Validate bet amount
    if (betAmount > player.wallet) {
        cout << RED << "¡No tienes suficiente dinero!" << RESET << endl;
        return;
    }
    
    cout << "\n" << GREEN << "🎯 RESUMEN DE APUESTA:\n" << RESET;
    cout << "================================\n";
    cout << "Tipo: " << YELLOW << typeName << RESET << "\n";
    cout << "Piloto: " << WHITE << pilots[chosenPilot] << RESET << "\n";
    cout << "Equipo: " << MAGENTA << teams[chosenPilot] << RESET << "\n";
    cout << "Cantidad: " << CYAN << "$" << betAmount << RESET << "\n";
    cout << "Premio potencial: " << GREEN << "$" << (int)(betAmount * multiplier) << RESET << "\n";
    cout << "================================\n\n";
    
    cout << RED << "🏁 Presiona ENTER para comenzar la carrera..." << RESET;
    cin.ignore();
    cin.get();
    
    // Simulate race(s) with improved fairness
    bool wonBet = true;
    int totalPrize = 0;
    
    for (int race = 1; race <= numRaces; race++) {
        if (numRaces > 1) {
            cout << "\n" << MAGENTA << "🏁 === RACE " << race << " OF " << numRaces << " === 🏁\n" << RESET;
        }
        
        vector<RaceResult> resultados = simulateRace(pilots, ids, teams);
        showPodium(resultados);
        
        // Check if won this race
        bool wonThisRace = (resultados[0].pilotName == pilots[chosenPilot]);
        
        if (wonThisRace) {
            cout << "\n" << GREEN;
            int indice = rand() % congratulationMessages.size();
            cout << "🎉 " << congratulationMessages[indice] << "\n" << RESET;
            cout << GREEN << "🏆 ¡" << pilots[chosenPilot] << " ganó la carrera " << race << "! 🏆\n" << RESET;
        } else {
            cout << "\n" << RED << "❌ " << pilots[chosenPilot] << " no ganó esta carrera.\n" << RESET;
            cout << "Ganador: " << YELLOW << resultados[0].pilotName << RESET << " (" << resultados[0].team << ")\n";
            wonBet = false;
            if (numRaces > 1) {
                cout << RED << "Necesitas ganar TODAS las carreras en el Gran Total.\n" << RESET;
                break;
            }
        }
        
        if (race < numRaces) {
            cout << "\n🏁 Presiona ENTER para la siguiente carrera...";
            cin.get();
        }
    }
    
    // Calculate final prize with dramatic reveal
    cout << "\n" << CYAN << "🎰 CALCULANDO RESULTADOS..." << RESET;
    sleepMs(1500);
    
    if (wonBet) {
        totalPrize = (int)(betAmount * multiplier);
        player.wallet = winnerResult(player.wallet, totalPrize);

        cout << "\n" << YELLOW << "🎊 ¡FELICITACIONES! ¡GANASTE TU APUESTA! 🎊\n" << RESET;
        cout << "Premio ganado: " << GREEN << "$" << totalPrize << RESET << "\n";
        cout << "Nuevo saldo: " << GREEN << "$" << player.wallet << RESET << "\n";
    } else {
        player.wallet = loserResult(player.wallet, betAmount);
        cout << "\n" << RED << "😔 Lo siento, perdiste tu apuesta.\n" << RESET;
        cout << "Cantidad perdida: " << RED << "$" << betAmount << RESET << "\n";
        cout << "Saldo restante: " << CYAN << "$" << player.wallet << RESET << "\n";
    }
    
    // Save in history
    Bet newBet;
    newBet.playerName = "Player";
    newBet.betType = typeName;
    newBet.chosenPilot = pilots[chosenPilot];
    newBet.betAmount = betAmount;
    newBet.won = wonBet;
    newBet.prize = wonBet ? totalPrize : 0;
    
    bettingHistory.push_back(newBet);
    updateBettorRanking("Player", wonBet, wonBet ? totalPrize : -betAmount);
    
    cout << "\n" << MAGENTA << "Presiona ENTER para continuar..." << RESET;
    cin.get();
>>>>>>> 5d9baad35495d9871277a40bac11a795273a3679
}

// Función para actualizar el ranking de apostadores
void updateBettorRanking(const string& name, bool won, int moneyWon) {
    // Search if the bettor already exists
    for (auto& apostador : bettorRanking) {
        if (apostador.name == name) {
            apostador.totalMoney += moneyWon;
            apostador.totalBets++;
            if (won) apostador.wonBets++;
            return;
        }
    }
    
    // If it doesn't exist, create new bettor
    Bettor nuevoApostador;
    nuevoApostador.name = name;
    nuevoApostador.totalMoney = moneyWon;
    nuevoApostador.totalBets = 1;
    nuevoApostador.wonBets = won ? 1 : 0;
    
    bettorRanking.push_back(nuevoApostador);
}

// Función para mostrar el ranking de apostadores
void showBettorRanking() {
    if (bettorRanking.empty()) {
        cout << RED << "No hay apostadores registrados aún.\n" << RESET;
        return;
    }
    
    // Sort by total money (descending)
    sort(bettorRanking.begin(), bettorRanking.end(),
         [](const Bettor& a, const Bettor& b) {
             return a.totalMoney > b.totalMoney;
         });
    
    cout << "\n" << YELLOW << "===== BETTORS RANKING =====\n" << RESET;
    cout << "Pos | Name       | Money     | Won     | % Success\n";
    cout << "----+------------+-----------+---------+-----------\n";
    
    for (size_t i = 0; i < bettorRanking.size() && i < 10; i++) {
        const auto& bettor = bettorRanking[i];
        float percentage = bettor.totalBets > 0 ? 
                          (float)bettor.wonBets / bettor.totalBets * 100 : 0;
        
        string moneyColor = bettor.totalMoney >= 0 ? GREEN : RED;
        
        cout << setw(3) << (i + 1) << " | " 
             << setw(10) << bettor.name << " | " 
             << moneyColor << "$" << setw(8) << bettor.totalMoney << RESET << " | "
             << setw(3) << bettor.wonBets << "/" << setw(3) << bettor.totalBets << " | "
             << setw(6) << fixed << setprecision(1) << percentage << "%\n";
    }
    
    if (!bettorRanking.empty()) {
        cout << "\n" << YELLOW << bettorRanking[0].name 
             << " está dominando las apuestas con $" << bettorRanking[0].totalMoney << "!\n" << RESET;
    }
}

// Función para mostrar el historial de apuestas
void showBettingHistory() {
    if (bettingHistory.empty()) {
        cout << RED << "No tienes apuestas anteriores.\n" << RESET;
        return;
    }
    
    cout << "\n" << CYAN << "=== BETTING HISTORY ===\n" << RESET;
    
    for (size_t i = 0; i < bettingHistory.size(); i++) {
        const auto& bet = bettingHistory[i];
        string result = bet.won ? string(GREEN) + "WON" : string(RED) + "LOST";
        
        cout << "\nBet #" << (i + 1) << ":\n";
        cout << "   Type: " << bet.betType << "\n";
        cout << "   Pilot: " << bet.chosenPilot << "\n";
        cout << "   Bet: $" << bet.betAmount << "\n";
        cout << "   Result: " << result << RESET << "\n";
        if (bet.won) {
            cout << "   Prize: " << GREEN << "$" << bet.prize << RESET << "\n";
        }
    }
    
    // General statistics
    int wonBets = 0;
    int moneyWon = 0, moneyLost = 0;
    
    for (const auto& bet : bettingHistory) {
        if (bet.won) {
            wonBets++;
            moneyWon += bet.prize;
        } else {
            moneyLost += bet.betAmount;
        }
    }
    
    float successPercentage = bettingHistory.size() > 0 ? 
                              (float)wonBets / bettingHistory.size() * 100 : 0;
    
    cout << "\n" << YELLOW << "GENERAL STATISTICS:\n" << RESET;
    cout << "Total bets: " << bettingHistory.size() << "\n";
    cout << "Won bets: " << GREEN << wonBets << RESET << "\n";
    cout << "Success percentage: " << (successPercentage >= 50 ? GREEN : RED) 
         << fixed << setprecision(1) << successPercentage << "%" << RESET << "\n";
    cout << "Money won: " << GREEN << "$" << moneyWon << RESET << "\n";
    cout << "Money lost: " << RED << "$" << moneyLost << RESET << "\n";
    cout << "Net balance: " << (moneyWon - moneyLost >= 0 ? GREEN : RED) 
         << "$" << (moneyWon - moneyLost) << RESET << "\n";
}

// Función para cargar piloto personalizado si existe
bool loadCustomPilot(string& name, int& id, string& team) {
    ifstream archivo("piloto_extra.txt");
    if (!archivo.is_open()) return false;
    
    string placa, tipoModelo;
    getline(archivo, name);
    archivo >> id;
    archivo.ignore();
    getline(archivo, placa);       // Car plate
    getline(archivo, tipoModelo);  // Sports or Classic
    getline(archivo, team);      // Team name
    archivo.close();
    return true;
}

// Main function of the betting system
void startBettingSystem() {
    // Pilot data (integrated with your existing system)
    vector<string> pilots = {
        "Max Verstappen", "Sergio Perez", "Lewis Hamilton", "George Russell",
        "Charles Leclerc", "Carlos Sainz", "Lando Norris", "Oscar Piastri",
        "Fernando Alonso", "Lance Stroll"
    };
    
    vector<int> ids = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    vector<string> teams = {
        "Red Bull", "Red Bull", "Mercedes", "Mercedes",
        "Ferrari", "Ferrari", "McLaren", "McLaren",
        "Aston Martin", "Aston Martin"
    };
    
    // Try to load custom pilot if it exists
    string customPilotName;
    int customPilotId;
    string customTeam;
    
    if (loadCustomPilot(customPilotName, customPilotId, customTeam)) {
        pilots.push_back(customPilotName);
        ids.push_back(customPilotId);
        teams.push_back(customTeam);
        
        cout << GREEN << "Custom pilot detected: " << customPilotName 
             << " (" << customTeam << ")!\n" << RESET;
        cout << YELLOW << "Now you can bet on your custom pilot.\n" << RESET;
    }
    
    int option;
    
    do {
        cout << "\n" << MAGENTA << "====== F1 BETTING SYSTEM ======\n" << RESET;
        cout << "1. Hacer nueva apuesta\n";
        cout << "2. Ver historial de apuestas\n";
        cout << "3. Ver ranking de apostadores\n";
        cout << "4. Regresar al menú principal\n";
        cout << "\nElige una opción (1-4): ";
        
        option = askNumber(1, 4);
        
        switch (option) {
            case 1:
                placeBet(pilots, ids, teams);
                break;
            case 2:
                showBettingHistory();
                break;
            case 3:
                showBettorRanking();
                break;
            case 4:
                cout << GREEN << "¡Gracias por apostar!\n" << RESET;
                break;
        }
        
        if (option != 4) {
            cout << "\nPresiona ENTER para continuar...";
            cin.ignore();
            cin.get();
        }
        
    } while (option != 4);
}


//Post-race menu function
    void postRaceMenu(players& p) {
        int option;
        
        do {
            cout << "\n🏁 ¡CARRERA COMPLETADA! 🏁\n";
            cout << "Saldo actual: $" << p.wallet << endl;
            cout << "\n--- ¿Qué te gustaría hacer ahora? ---\n";
            cout << "1. Correr de nuevo\n";
            cout << "2. Ver ranking de apuestas\n";
            cout << "3. Ver historial de apuestas\n";
            cout << "4. Volver al menú principal\n";
            cout << "Selecciona una opción: ";
            cin >> option;
            cin.ignore();
            
            // Update global player
            player = p;
            
            switch (option) {
                case 1:
                    // Simplemente volver al menú principal para nueva carrera
                    cout << "\n¡Listo para una nueva carrera!\n";
                    return;
                    
                case 2:
                    cout << "\n=== RANKING DE APOSTADORES ===\n";
                    showBettorRanking();
                    cout << "\nPresiona ENTER para continuar...";
                    cin.get();
                    break;
                    
                case 3:
                    cout << "\n=== HISTORIAL DE APUESTAS ===\n";
                    showBettingHistory();
                    cout << "\nPresiona ENTER para continuar...";
                    cin.get();
                    break;
                    
                case 4:
                    cout << "\nRegresando al menú principal...\n";
                    break;
                    
                default:
                    cout << "Opción inválida. Por favor, intenta de nuevo.\n";
            }
            
            // Update local player with changes
            p = player;
            
        } while (option != 4);
    }

//Validation functions

// Función para validar que sea un entero dentro del rango especificado
int askNumber(int minimum, int maximum) {
    int chosenNumber;
    while (true) {
        if (cin >> chosenNumber) {
            if (chosenNumber >= minimum && chosenNumber <= maximum) {
                cin.ignore(10000, '\n'); // Clean buffer after valid input
                return chosenNumber;
            } else {
                cout << RED << "That number is not in the range (" << minimum << "-" << maximum << ").\n Try another: " << RESET;
                cin.ignore(10000, '\n'); // Clean buffer after invalid input
            }
        } else {
            cout << RED << "That's not a valid number buddy.\n Just numbers please. Try again: " << RESET;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

// Función para pedir un nombre (letras y espacios)
string askName(const string& message) {
    string userName;
    while (true) {
        cout << message;
        getline(cin, userName);
        
        // Check that it's not empty or only spaces

        bool onlySpaces = true;
        for (char letter : userName) {
            if (letter != ' ' && letter != '\t') {
                onlySpaces = false;
                break;
            }
        }
        
        if (userName.empty() || onlySpaces) {
            cout << RED << "Hey, you can't leave this empty.\n Please write something.\n" << RESET;
            continue;
        }
        
        // Check that it only contains letters and spaces (no numbers or symbols)
        for (char letter : userName) {
            if (!((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z') || letter == ' ')) {
                cout << RED << "Only letters and spaces buddy. No numbers or weird symbols.\n Try again.\n" << RESET;
                goto tryAgain;
            }
        }
        
        return userName;
        tryAgain:;
    }
}

//Wallet functions
 //function to add won money to wallet
    float winnerResult(float personalWallet, float winnBet){
        float resultWallet;
        resultWallet = personalWallet + winnBet;
        if (resultWallet < 0){
            resultWallet = 0;
        }
        return resultWallet;

    }

    //function to subtract money from wallet
    float loserResult(float personalWallet, float winnBet){
        float minusWallet;
        minusWallet = personalWallet - winnBet;
        if (minusWallet < 0){
            minusWallet = 0;
        }
        return minusWallet;

    }

// Función para mostrar estadísticas de carrera e información de pilotos
void showRaceStatistics(const vector<string>& pilots, const vector<string>& teams) {
    cout << "\n" << CYAN << "📊 RACE STATISTICS & PILOT INFO 📊\n" << RESET;
    cout << "==========================================\n";
    
    // Show each pilot with enhanced information
    for (size_t i = 0; i < pilots.size(); i++) {
        cout << "\n" << WHITE << "🏎️  " << pilots[i] << RESET;
        cout << " (" << MAGENTA << teams[i] << RESET << ")\n";
        
        // Generate pseudo-random stats for each pilot
        int careerWins = 5 + (rand() % 15);
        int podiums = careerWins + (rand() % 20);
        int races = podiums + (rand() % 30) + 20;
        float winRate = ((float)careerWins / races) * 100;
        
        cout << "   Career Wins: " << GREEN << careerWins << RESET;
        cout << " | Podiums: " << YELLOW << podiums << RESET;
        cout << " | Races: " << BLUE << races << RESET;
        cout << " | Win Rate: " << (winRate > 15 ? GREEN : (winRate > 8 ? YELLOW : RED)) 
             << fixed << setprecision(1) << winRate << "%" << RESET << "\n";
    }
    
    cout << "\n" << YELLOW << "💡 TIP: Any pilot can win on race day! Form and luck matter most!" << RESET << "\n";
    cout << "==========================================\n";
}

// Función para mostrar emoción pre-carrera
void showPreRaceExcitement() {
    vector<string> preRaceComments = {
        "¡La atmósfera está eléctrica hoy aquí!",
        "¡Todos los pilotos están listos para dar lo mejor!",
        "¡Esta podría ser la carrera de cualquiera!",
        "¡La multitud se está volviendo más ruidosa por minuto!",
        "¡Las condiciones climáticas son perfectas para correr!",
        "¡La batalla por el campeonato continúa hoy!",
        "¡Cada posición será peleada duramente!",
        "¡Los conductores están calentando sus motores!",
        "¡Los equipos de boxes están haciendo ajustes finales!",
        "¡Esto es de lo que se trata la Fórmula 1!"
    };
    
    cout << "\n" << MAGENTA << "🎪 PRE-RACE ATMOSPHERE 🎪\n" << RESET;
    cout << YELLOW << "🎤 COMENTARISTA: " << preRaceComments[rand() % preRaceComments.size()] << RESET << "\n";
    sleepMs(1000);
    cout << YELLOW << "📻 RADIO: " << preRaceComments[rand() % preRaceComments.size()] << RESET << "\n\n";
}




