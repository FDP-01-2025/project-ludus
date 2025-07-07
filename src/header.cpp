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

using namespace std;
players player; //esta en el archivo main de manera global

//Funciones de Log in y usuario 

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



bool soloLetras(const string& str) {
for (char c : str) {
if (!isalpha(c) && c != ' ') {
            return false;
        }
    }
    return !str.empty(); // Asegurarse que no esté vacío
}

//login principal

void validateNames(players& p) {
    cout << "*************************" << endl;
    cout << " BIENVENID@ AL JUEGO" << endl;
    cout << "*************************" << endl;

    do {
        cout << "Nombre del jugador (solo se permite letras): ";
        getline(cin, p.userName);
        p.userName.erase(0, p.userName.find_first_not_of(" "));
        p.userName.erase(p.userName.find_last_not_of(" ") + 1);

        if (!soloLetras(p.userName)) {
            cout << "Error: El nombre solo debe contener letras y espacios. Intente nuevamente.\n";
        }
    } while (!soloLetras(p.userName));

    cout << "Edad: ";
    cin >> p.age;
    cin.ignore();
}


//Funciones de pistas de carreras
 
//esta funcion nos ayuda a mostrar los ascii de las pistas
void Show_asciiTrack (string namearchive) {
    ifstream Archive (namearchive);
    if (!Archive) {
        cout << "No se pudo abrir el archivo: " << namearchive << endl;
        return;
    }

    string line;
    while (getline(Archive, line)) {
        cout << line << endl;
    }

    Archive.close();
}

//creamos la fucnion de las pistas
void Tracks_f1 (){
    Rtracks pistas [5]{
        {" SilverStone", " Reino Unido", " Alto", 5.896 },
        {" Monza","Italia" ," Media", 5.793},
        {" Suzuka"," Japon", " Alta", 5.807},
        {" Interlagos", " Brasil", " Alta", 5.470},
        {" Monaco", " Italia", " Baja", 3.330}

    };
 //Aca con el for lo que se hace es mostrar el nombre dde cada pista
    for(int i=0;i<5;i++){
        cout<< i+1<< pistas[i].name<<endl;
    };

    int option;

    cout<<"Selecciona una pista! (1-5):"<<" ";
    cout<<"";
    cin>> option;

    if (option <1 ||option >5){
        cout<<"Opcion invalida"<<endl;
        return;
    }

    Rtracks Selecction = pistas [option-1];
    cout<< "Sobre..."<<endl;
    cout<<"";
    cout<<"Nombre:"<<""<<Selecction.name<<endl;
    cout<<"Localidad:"<<""<<Selecction.located<<endl;
    cout<<"Dificultad:"<<""<<Selecction.difficulty_Level<<endl;
    cout<<"Longitud:"<<""<<Selecction.large_km<<"km"<<endl;

    string namesTrack_Archive[5] = {
        //archivos
        "silverstone.txt",
        "monza.txt",
        "suzuka.txt",
        "interlagos.txt",
        "monaco.txt",
    };

    Show_asciiTrack(namesTrack_Archive[option - 1]);
}





//Funciones de carros
 // colores bonitos para los carros
#define BLACK "\x1B[30m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1B[37m"
#define ORANGE "\x1B[38;2;255;128;0m"
#define RESET "\x1b[0m"

// Carro de Max Verstappen
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

// Carro de Sergio Pérez
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

// Carro de Lewis Hamilton
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

// Carro de George Russell
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

// Carro de Charles Leclerc
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

// Carro de Carlos Sainz
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

// Carro de Lando Norris
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

// Carro de Oscar Piastri
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

// Carro de Fernando Alonso
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

// Carro de Lance Stroll
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

// Carro personalizado 1 - Estilo deportivo
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

// Carro personalizado 2 - Estilo clasico
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


//Funciones de simulador 


// Declaraciones de funciones
void mostrarEquipos(Equipo equipos[]);
void mostrarPilotos(Equipo equipo);
bool cargarPiloto(Piloto &p);
void crearPiloto();
void verCarros();
void iniciarSimuladorF1();

// Esta funcion me enseña todos los equipos en una lista
void mostrarEquipos(Equipo equipos[]) {
    cout << "--- LISTA DE EQUIPOS ---\n";
    for (int i = 0; i < cuantosEquipos; i++) {
        cout << i + 1 << ". " << equipos[i].nombreEquipo << endl;
    }
}

// Esta me muestra los pilotos de un equipo especifico
void mostrarPilotos(Equipo equipo) {
    cout << "\n-- PILOTOS DE " << equipo.nombreEquipo << " --\n";
    for (int i = 0; i < pilotosPorEquipo; i++) {
        cout << i + 1 << ". " << equipo.pilotos[i].nombre << " (ID: " << equipo.pilotos[i].id << ")\n";
    }
}

// Esta funcion lee un piloto extra desde un archivo
bool cargarPiloto(Piloto &p) {
    ifstream archivo("piloto_extra.txt");
    if (!archivo.is_open()) return false;  // Por si no se puede abrir el archivo

    getline(archivo, p.nombre);
    archivo >> p.id;
    archivo.ignore();
    getline(archivo, p.modeloCarro);     // Esta es la placa 
    getline(archivo, p.tipoModelo);      // Deportivo o Clasico
    getline(archivo, p.nombreEquipo);   // Nombre del equipo personalizado
    archivo.close();
    return true;
}

// Esta funcion guarda un piloto nuevo en un archivo
void crearPiloto() {
    ofstream archivo("piloto_extra.txt");
    if (!archivo.is_open()) {
        cout << "Ups, no pude crear el archivo.\n";
        archivo.close();
        return;
    }

    string nombreDelPiloto, tipoDelCarro, nombreDelEquipo, placaDelCarro;
    int idDelPiloto;
    
    // Validacion del nombre del piloto (letras y espacios)
    nombreDelPiloto = pedirNombre("Como se llama tu piloto: ");
    
    // Validacion del ID del piloto
    cout << "Que ID le ponemos (1-999): ";
    idDelPiloto = pedirNumero(1, 999);
    
    // Validacion del nombre del equipo (letras y espacios)
    nombreDelEquipo = pedirNombre("Como se llama tu equipo: ");
    
    // Validacion del modelo de carro
    cout << "\n--- QUE CARRO QUIERES ---\n";
    cout << "1. Carro Deportivo\n";
    cout << "2. Carro Clasico\n";
    cout << "Cual te gusta mas (1-2): ";
    
    int opcionCarro = pedirNumero(1, 2);
    
    // Asignar placa automaticamente segun el tipo de carro
    if (opcionCarro == 1) {
        placaDelCarro = "SPORT-" + to_string(idDelPiloto);
        tipoDelCarro = "Deportivo";
    } else {
        placaDelCarro = "CLASSIC-" + to_string(idDelPiloto);
        tipoDelCarro = "Clasico";
    }
    
    // Muestro una vista previa del carro elegido
    cout << "\n--- ASI SE VE TU CARRO ---\n";
    if (opcionCarro == 1) {
        drawCar11();
    } else {
        drawCar12();
    }

    // Guardo: nombre, id, placa del carro, modelo del carro, nombre del equipo
    archivo << nombreDelPiloto << "\n" << idDelPiloto << "\n" << placaDelCarro << "\n" << tipoDelCarro << "\n" << nombreDelEquipo << endl;
    archivo.close();
    cout << GREEN << "\nGenial! Tu piloto esta guardado\n" << RESET;
    
    // Ahora muestro la informacion completa del piloto creado
    cout << "\n--- AQUI ESTA TU PILOTO ---\n";
    cout << "Nombre: " << nombreDelPiloto << endl;
    cout << "ID: " << idDelPiloto << endl;
    cout << "Placa del carro: " << placaDelCarro << endl;
    cout << "Equipo: " << nombreDelEquipo << endl;
    
    cout << "\n--- TU CARRO DE F1 ---\n";
    // Dibujo el carro segun el tipo elegido
    if (tipoDelCarro == "Deportivo") {
        drawCar11();
    } else {
        drawCar12();
    }
}

// Esta funcion muestra los carros disponibles para elegir
void verCarros() {
    cout << "\n-- CARRO 1: DEPORTIVO --\n";
    drawCar11();
    cout << "\n-- CARRO 2: CLASICO --\n";
    drawCar12();
}

// Función principal del simulador F1 (equivalente al main original)
void iniciarSimuladorF1() {
    // Aca estan todos los equipos con sus pilotos
    
    Equipo equipos[cuantosEquipos] = {
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

    // Intento leer si hay un piloto extra guardado
    Piloto pilotoExtra;
    bool hayPilotoExtra = cargarPiloto(pilotoExtra);

    // Le pregunto al usuario que quiere hacer
    int queQuiereHacer;
    cout << "--- BIENVENIDO A LA SIMULACION DE F1 ---\n";
    cout << "1. Ver pilotos y elegir uno\n";
    cout << "2. Crear tu propio piloto con carro personalizado\n";
    cout << "Que quieres hacer: ";
    queQuiereHacer = pedirNumero(1, 2);

    // Si quiere agregar un piloto nuevo
    if (queQuiereHacer == 2) {
        cout << "\n-- CREADOR DE PILOTO PERSONALIZADO --\n";
        verCarros();
        crearPiloto();
        return;
    }

    int equipoElegido, pilotoElegido;

    // Muestro los equipos para que elija
    mostrarEquipos(equipos);
    cout << "\nQue equipo te gusta (1-" << cuantosEquipos << "): ";
    equipoElegido = pedirNumero(1, cuantosEquipos);

    // Muestro los pilotos del equipo elegido
    mostrarPilotos(equipos[equipoElegido - 1]);

    cout << "\nQue piloto eliges (1-" << pilotosPorEquipo;
    if (hayPilotoExtra) cout << " o 3 para piloto extra";
    cout << "): ";
    pilotoElegido = pedirNumero(1, hayPilotoExtra ? 3 : 2);

    Piloto miPiloto;

    // Decido cual piloto usar
    if (pilotoElegido == 3 && hayPilotoExtra) {
        miPiloto = pilotoExtra;  // Uso el piloto extra
    } else {
        miPiloto = equipos[equipoElegido - 1].pilotos[pilotoElegido - 1];  // Uso un piloto normal
    }

    // Muestro la informacion del piloto elegido
    cout << "\n--- INFORMACION DEL PILOTO ---\n";
    cout << "Nombre: " << miPiloto.nombre << endl;
    cout << "ID: " << miPiloto.id << endl;
    cout << "Carro: " << miPiloto.modeloCarro << endl;
    cout << "Equipo: ";
    if (pilotoElegido == 3 && hayPilotoExtra)
        cout << miPiloto.nombreEquipo << endl;  // Muestra el equipo personalizado
    else
        cout << equipos[equipoElegido - 1].nombreEquipo << endl;

    cout << "\n--- CARRO DE F1 ---\n";

    // Dibujo del carro segun el ID del piloto
    switch (miPiloto.id) {
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
            // Para pilotos personalizados, miro el tipo de modelo
            if (miPiloto.tipoModelo == "Deportivo") {
                drawCar11();
            } else if (miPiloto.tipoModelo == "Clasico") {
                drawCar12();
            } else {
                cout << RED << "No hay carro para este piloto.\n" << RESET;
            }
            break;
    }
}

//Funciones de apuestas 



// Variables globales para el sistema de apuestas
vector<Apuesta> historialApuestas;
vector<Apostador> rankingApostadores;

// Declaraciones de funciones
string obtenerTipoCarroPersonalizado();
bool cargarPilotoPersonalizado(string& nombre, int& id, string& equipo);
void mostrarCarroPiloto(int idPiloto);
int simularTiempoCarrera();
void mostrarComentario();
vector<ResultadoCarrera> simularCarrera(vector<string> pilotos, vector<int> ids, vector<string> equipos);
void mostrarPodio(const vector<ResultadoCarrera>& resultados);
void mostrarTiposApuesta();
void realizarApuesta(const vector<string>& pilotos, const vector<int>& ids, const vector<string>& equipos);
void actualizarRankingApostador(const string& nombre, bool gano, int dineroGanado);
void mostrarRankingApostadores();
void mostrarHistorialApuestas();
void iniciarSistemaApuestas();

// Comentarios de los comentaristas durante las carreras
vector<string> comentariosCarrera = {
    "Oye, que buen arranque!",
    "Eso estuvo increible!",
    "Se esta acercando rapido!",
    "Ay no, creo que tiene problemas!",
    "Que buena defensa ahi!",
    "Va subiendo como loco!",
    "Las llantas ya no dan mas!",
    "Eso fue muy arriesgado!",
    "Esta carrera esta buenisima!",
    "La gente no para de gritar!"
};

// Mensajes de felicitación
vector<string> mensajesFelicitacion = {
    "FELICIDADES! Le atinaste!",
    "GENIAL! Tu piloto si gano!",
    "QUE BUENO! Elegiste bien!",
    "EXCELENTE! Sabia que ganaria!",
    "INCREIBLE! Que suerte tienes!",
    "PERFECTO! Eres bueno para esto!"
};

// Función para obtener el tipo de carro del piloto personalizado
string obtenerTipoCarroPersonalizado() {
    ifstream archivo("piloto_extra.txt");
    if (!archivo.is_open()) return "Deportivo"; // Si no hay archivo, asumimos deportivo
    
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

// Función para mostrar el carro del piloto segun su numero
void mostrarCarroPiloto(int idPiloto) {
    switch (idPiloto) {
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
            // Para los pilotos que crea el usuario
            string tipoCarro = obtenerTipoCarroPersonalizado();
            if (tipoCarro == "Deportivo") {
                drawCar11();
            } else {
                drawCar12();
            }
            break;
    }
}

// Funcion para simular cuanto tarda cada piloto
int simularTiempoCarrera() {
    static bool seedInitialized = false;
    static int contador = 0;
    
    if (!seedInitialized) {
        srand(time(0)); 
        seedInitialized = true;
    }
    
    contador++;
    
    // Tiempo base + algo aleatorio + factor para que sea diferente
    int tiempoBase = 85000; // Como 1 minuto 25 segundos
    int variacionAleatoria = rand() % 25000; // Hasta 25 segundos mas o menos
    int factorUnico = contador * 300; // Para que cada uno sea diferente
    
    return tiempoBase + variacionAleatoria + factorUnico;
}

// Función para mostrar comentarios durante la carrera
void mostrarComentario() {
    static int lastIndex = -1;
    int indice;
    do {
        indice = rand() % comentariosCarrera.size();
    } while (indice == lastIndex && comentariosCarrera.size() > 1);
    lastIndex = indice;
    cout << YELLOW << "COMENTARISTA: " << comentariosCarrera[indice] << RESET << endl;
}

// Funcion para hacer la carrera completa
vector<ResultadoCarrera> simularCarrera(vector<string> pilotos, vector<int> ids, vector<string> equipos) {
    vector<ResultadoCarrera> resultados;
    
    cout << GREEN << "\nLA CARRERA ESTA COMENZANDO!\n" << RESET;
    cout << "===================================\n\n";
    
    // Le damos un tiempo a cada piloto
    for (size_t i = 0; i < pilotos.size(); i++) {
        ResultadoCarrera resultado;
        resultado.nombrePiloto = pilotos[i];
        resultado.idPiloto = ids[i];
        resultado.equipo = equipos[i];
        
        // Calculamos el tiempo de cada piloto
        int tiempoBase = 85000; // Tiempo base como 1:25
        int variacion = rand() % 20000; // Hasta 20 segundos de diferencia
        int factorPiloto = i * 500; // Para que cada uno sea diferente
        
        resultado.tiempoCarrera = tiempoBase + variacion + factorPiloto;
        
        // Le agregamos un poco mas de aleatoriedad
        resultado.tiempoCarrera += (rand() % 5000) - 2500;
        
        // Nos aseguramos que el tiempo sea realista
        if (resultado.tiempoCarrera < 80000) resultado.tiempoCarrera = 80000 + rand() % 10000;
        
        resultados.push_back(resultado);
    }
    
    // Mezclamos los resultados para que sea mas aleatorio
    random_shuffle(resultados.begin(), resultados.end());
    
    // Ordenamos por tiempo (el mas rapido gana)
    sort(resultados.begin(), resultados.end(), 
         [](const ResultadoCarrera& a, const ResultadoCarrera& b) {
             return a.tiempoCarrera < b.tiempoCarrera;
         });
    
    // Les damos su posicion
    for (size_t i = 0; i < resultados.size(); i++) {
        resultados[i].posicion = i + 1;
    }
    
    // Mostramos la carrera con los carros
    cout << CYAN << "Los carros estan arrancando...\n" << RESET;
    
    for (int vuelta = 1; vuelta <= 3; vuelta++) {
        cout << "\n" << MAGENTA << "=== VUELTA " << vuelta << " ===\n" << RESET;
        
        // Mostramos algunos carros corriendo
        for (int i = 0; i < 3 && i < (int)resultados.size(); i++) {
            cout << WHITE << "Carro: " << resultados[i].nombrePiloto << " (" << resultados[i].equipo << ")\n" << RESET;
            mostrarCarroPiloto(resultados[i].idPiloto);
            cout << "\n";
        }
        
        mostrarComentario();
        cout << "\n";
        
        // Esperamos un poco
        cout << "Procesando vuelta...\n";
        for (int j = 0; j < 100000000; j++); // Pausa para simular tiempo
    }
    
    cout << RED << "\nCARRERA TERMINADA!\n" << RESET;
    cout << "===================\n";
    
    return resultados;
}

// Funcion para mostrar el podio al final
void mostrarPodio(const vector<ResultadoCarrera>& resultados) {
    cout << "\n" << YELLOW << "========== PODIO ==========\n" << RESET;
    
    for (int i = 0; i < 5 && i < (int)resultados.size(); i++) {
        string medalla;
        string color;
        
        switch (i) {
            case 0: medalla = "1er"; color = YELLOW; break;
            case 1: medalla = "2do"; color = WHITE; break;
            case 2: medalla = "3er"; color = ORANGE; break;
            case 3: medalla = "4to"; color = BLUE; break;
            case 4: medalla = "5to"; color = GREEN; break;
        }
        
        int minutos = resultados[i].tiempoCarrera / 60000;
        int segundos = (resultados[i].tiempoCarrera % 60000) / 1000;
        int milisegundos = resultados[i].tiempoCarrera % 1000;
        
        cout << color << medalla << " lugar: " 
             << resultados[i].nombrePiloto << " (" << resultados[i].equipo << ")\n";
        cout << "   Tiempo: " << minutos << ":" << setfill('0') << setw(2) << segundos 
             << "." << setw(3) << milisegundos << RESET << "\n\n";
    }
    
    // Mostramos el carro del que gano
    cout << YELLOW << "CARRO DEL CAMPEON\n" << RESET;
    mostrarCarroPiloto(resultados[0].idPiloto);
}

// Función para mostrar tipos de apuesta (sin saldo)
void mostrarTiposApuesta() {
    cout << "\n" << CYAN << "=== TIPOS DE APUESTA ===\n" << RESET;
    cout << "1. GRAND TOTAL (2 carreras - Premio x3)\n";
    cout << "2. GRAND PRIX (1 carrera - Premio x2)\n";
    cout << "3. SPRINT (1 carrera - Premio x1.5)\n";
}

// Función para realizar una apuesta
void realizarApuesta(const vector<string>& pilotos, const vector<int>& ids, const vector<string>& equipos) {
    mostrarTiposApuesta();
    
    cout << "\nQue tipo de apuesta quieres hacer? (1-3): ";
    int tipoApuesta = pedirNumero(1, 3);
    
    string nombreTipo;
    float multiplicador;
    int numCarreras;
    
    switch (tipoApuesta) {
        case 1: 
            nombreTipo = "Grand Total"; 
            multiplicador = 3.0f; 
            numCarreras = 2;
            break;
        case 2: 
            nombreTipo = "Grand Prix"; 
            multiplicador = 2.0f; 
            numCarreras = 1;
            break;
        case 3: 
            nombreTipo = "Sprint"; 
            multiplicador = 1.5f; 
            numCarreras = 1;
            break;
    }
    
    cout << "\n" << YELLOW << "Has elegido: " << nombreTipo << RESET;
    if (numCarreras == 2) {
        cout << ORANGE << " (Debes ganar ambas carreras!)" << RESET;
    }
    cout << "\n";
    
    // Mostrar pilotos disponibles
    cout << "\n" << CYAN << "PILOTOS DISPONIBLES:\n" << RESET;
    for (size_t i = 0; i < pilotos.size(); i++) {
        cout << (i + 1) << ". " << pilotos[i] << " (" << equipos[i] << ")\n";
    }
    
    cout << "\nPor que piloto quieres apostar? (1-" << pilotos.size() << "): ";
    int pilotoElegido = pedirNumero(1, (int)pilotos.size()) - 1;
    
    cout << "\nCuanto dinero quieres apostar?: $";
    int montoApuesta;
    cin >> montoApuesta;
    
    cout << "\n" << GREEN << "Apuesta realizada:\n" << RESET;
    cout << "Tipo: " << nombreTipo << "\n";
    cout << "Piloto: " << pilotos[pilotoElegido] << "\n";
    cout << "Monto: $" << montoApuesta << "\n";
    cout << "Premio potencial: $" << (int)(montoApuesta * multiplicador) << "\n\n";
    
    cout << RED << "Presiona ENTER para comenzar la carrera..." << RESET;
    cin.ignore();
    cin.get();
    
    // Simular carrera(s)
    bool ganoApuesta = true;
    int premioTotal = 0;
    
    for (int carrera = 1; carrera <= numCarreras; carrera++) {
        if (numCarreras > 1) {
            cout << "\n" << MAGENTA << "=== CARRERA " << carrera << " DE " << numCarreras << " ===\n" << RESET;
        }
        
        vector<ResultadoCarrera> resultados = simularCarrera(pilotos, ids, equipos);
        mostrarPodio(resultados);
        
        // Verificar si ganó esta carrera
        bool ganoEstaCarrera = (resultados[0].nombrePiloto == pilotos[pilotoElegido]);
        
        if (ganoEstaCarrera) {
            cout << "\n" << GREEN;
            int indice = rand() % mensajesFelicitacion.size();
            cout << mensajesFelicitacion[indice] << "\n" << RESET;
            cout << GREEN << pilotos[pilotoElegido] << " gano la carrera " << carrera << "!\n" << RESET;
        } else {
            cout << "\n" << RED << pilotos[pilotoElegido] << " no gano esta carrera.\n" << RESET;
            ganoApuesta = false;
            if (numCarreras > 1) {
                cout << RED << "Necesitas ganar TODAS las carreras en Grand Total.\n" << RESET;
                break;
            }
        }
        
        if (carrera < numCarreras) {
            cout << "\nPresiona ENTER para la siguiente carrera...";
            cin.get();
        }
    }
    
    // Calcular premio final
    if (ganoApuesta) {
        premioTotal = (int)(montoApuesta * multiplicador);
        player.wallet = winnerResult(player.wallet, premioTotal); //funcion suma de wallet.h
        registerChange(player); //guardar en historial

        cout << "\n" << YELLOW << "FELICIDADES! GANASTE TU APUESTA!\n" << RESET;
        cout << "Premio ganado: " << GREEN << "$" << premioTotal << RESET << "\n";
    } else {
        player.wallet = loserResult(player.wallet, montoApuesta); //funcion resta de wallet.h
        registerChange(player); //guardar en historial 
        cout << "\n" << RED << "Lo siento, perdiste tu apuesta.\n" << RESET;
    }
    
    // Guardar en historial
    Apuesta nuevaApuesta;
    nuevaApuesta.nombreJugador = "Jugador";
    nuevaApuesta.tipoApuesta = nombreTipo;
    nuevaApuesta.pilotoElegido = pilotos[pilotoElegido];
    nuevaApuesta.montoApostado = montoApuesta;
    nuevaApuesta.gano = ganoApuesta;
    nuevaApuesta.premio = ganoApuesta ? premioTotal : 0;
    
    historialApuestas.push_back(nuevaApuesta);
    actualizarRankingApostador("Jugador", ganoApuesta, ganoApuesta ? premioTotal : -montoApuesta);
}

// Función para actualizar el ranking de apostadores
void actualizarRankingApostador(const string& nombre, bool gano, int dineroGanado) {
    // Buscar si el apostador ya existe
    for (auto& apostador : rankingApostadores) {
        if (apostador.nombre == nombre) {
            apostador.dineroTotal += dineroGanado;
            apostador.apuestasTotal++;
            if (gano) apostador.apuestasGanadas++;
            return;
        }
    }
    
    // Si no existe, crear nuevo apostador
    Apostador nuevoApostador;
    nuevoApostador.nombre = nombre;
    nuevoApostador.dineroTotal = dineroGanado;
    nuevoApostador.apuestasTotal = 1;
    nuevoApostador.apuestasGanadas = gano ? 1 : 0;
    
    rankingApostadores.push_back(nuevoApostador);
}

// Función para mostrar el ranking de apostadores
void mostrarRankingApostadores() {
    if (rankingApostadores.empty()) {
        cout << RED << "No hay apostadores registrados aun.\n" << RESET;
        return;
    }
    
    // Ordenar por dinero total (descendente)
    sort(rankingApostadores.begin(), rankingApostadores.end(),
         [](const Apostador& a, const Apostador& b) {
             return a.dineroTotal > b.dineroTotal;
         });
    
    cout << "\n" << YELLOW << "===== RANKING DE APOSTADORES =====\n" << RESET;
    cout << "Pos | Nombre     | Dinero    | Ganadas | % Aciertos\n";
    cout << "----+------------+-----------+---------+-----------\n";
    
    for (size_t i = 0; i < rankingApostadores.size() && i < 10; i++) {
        const auto& apostador = rankingApostadores[i];
        float porcentaje = apostador.apuestasTotal > 0 ? 
                          (float)apostador.apuestasGanadas / apostador.apuestasTotal * 100 : 0;
        
        string colorDinero = apostador.dineroTotal >= 0 ? GREEN : RED;
        
        cout << setw(3) << (i + 1) << " | " 
             << setw(10) << apostador.nombre << " | " 
             << colorDinero << "$" << setw(8) << apostador.dineroTotal << RESET << " | "
             << setw(3) << apostador.apuestasGanadas << "/" << setw(3) << apostador.apuestasTotal << " | "
             << setw(6) << fixed << setprecision(1) << porcentaje << "%\n";
    }
    
    if (!rankingApostadores.empty()) {
        cout << "\n" << YELLOW << rankingApostadores[0].nombre 
             << " esta dominando las apuestas con $" << rankingApostadores[0].dineroTotal << "!\n" << RESET;
    }
}

// Función para mostrar historial de apuestas
void mostrarHistorialApuestas() {
    if (historialApuestas.empty()) {
        cout << RED << "No tienes apuestas anteriores.\n" << RESET;
        return;
    }
    
    cout << "\n" << CYAN << "=== HISTORIAL DE APUESTAS ===\n" << RESET;
    
    for (size_t i = 0; i < historialApuestas.size(); i++) {
        const auto& apuesta = historialApuestas[i];
        string resultado = apuesta.gano ? string(GREEN) + "GANO" : string(RED) + "PERDIO";
        
        cout << "\nApuesta #" << (i + 1) << ":\n";
        cout << "   Tipo: " << apuesta.tipoApuesta << "\n";
        cout << "   Piloto: " << apuesta.pilotoElegido << "\n";
        cout << "   Apostado: $" << apuesta.montoApostado << "\n";
        cout << "   Resultado: " << resultado << RESET << "\n";
        if (apuesta.gano) {
            cout << "   Premio: " << GREEN << "$" << apuesta.premio << RESET << "\n";
        }
    }
    
    // Estadísticas generales
    int apuestasGanadas = 0;
    int dineroGanado = 0, dineroPerdido = 0;
    
    for (const auto& apuesta : historialApuestas) {
        if (apuesta.gano) {
            apuestasGanadas++;
            dineroGanado += apuesta.premio;
        } else {
            dineroPerdido += apuesta.montoApostado;
        }
    }
    
    float porcentajeAciertos = historialApuestas.size() > 0 ? 
                              (float)apuestasGanadas / historialApuestas.size() * 100 : 0;
    
    cout << "\n" << YELLOW << "ESTADISTICAS GENERALES:\n" << RESET;
    cout << "Apuestas totales: " << historialApuestas.size() << "\n";
    cout << "Apuestas ganadas: " << GREEN << apuestasGanadas << RESET << "\n";
    cout << "Porcentaje de aciertos: " << (porcentajeAciertos >= 50 ? GREEN : RED) 
         << fixed << setprecision(1) << porcentajeAciertos << "%" << RESET << "\n";
    cout << "Dinero ganado: " << GREEN << "$" << dineroGanado << RESET << "\n";
    cout << "Dinero perdido: " << RED << "$" << dineroPerdido << RESET << "\n";
    cout << "Balance neto: " << (dineroGanado - dineroPerdido >= 0 ? GREEN : RED) 
         << "$" << (dineroGanado - dineroPerdido) << RESET << "\n";
}

// Función para cargar piloto personalizado si existe
bool cargarPilotoPersonalizado(string& nombre, int& id, string& equipo) {
    ifstream archivo("piloto_extra.txt");
    if (!archivo.is_open()) return false;
    
    string placa, tipoModelo;
    getline(archivo, nombre);
    archivo >> id;
    archivo.ignore();
    getline(archivo, placa);       // Placa del carro
    getline(archivo, tipoModelo);  // Deportivo o Clasico
    getline(archivo, equipo);      // Nombre del equipo
    archivo.close();
    return true;
}

// Función principal del sistema de apuestas
void iniciarSistemaApuestas() {
    // Datos de pilotos (integrado con tu sistema existente)
    vector<string> pilotos = {
        "Max Verstappen", "Sergio Perez", "Lewis Hamilton", "George Russell",
        "Charles Leclerc", "Carlos Sainz", "Lando Norris", "Oscar Piastri",
        "Fernando Alonso", "Lance Stroll"
    };
    
    vector<int> ids = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    vector<string> equipos = {
        "Red Bull", "Red Bull", "Mercedes", "Mercedes",
        "Ferrari", "Ferrari", "McLaren", "McLaren",
        "Aston Martin", "Aston Martin"
    };
    
    // Intentar cargar piloto personalizado si existe
    string nombrePersonalizado;
    int idPersonalizado;
    string equipoPersonalizado;
    
    if (cargarPilotoPersonalizado(nombrePersonalizado, idPersonalizado, equipoPersonalizado)) {
        pilotos.push_back(nombrePersonalizado);
        ids.push_back(idPersonalizado);
        equipos.push_back(equipoPersonalizado);
        
        cout << GREEN << "¡Piloto personalizado detectado: " << nombrePersonalizado 
             << " (" << equipoPersonalizado << ")!\n" << RESET;
        cout << YELLOW << "Ahora puedes apostar por tu piloto personalizado.\n" << RESET;
    }
    
    int opcion;
    
    do {
        cout << "\n" << MAGENTA << "====== SISTEMA DE APUESTAS F1 ======\n" << RESET;
        cout << "1. Realizar nueva apuesta\n";
        cout << "2. Ver historial de apuestas\n";
        cout << "3. Ver ranking de apostadores\n";
        cout << "4. Volver al menu principal\n";
        cout << "\nElige una opcion (1-4): ";
        
        opcion = pedirNumero(1, 4);
        
        switch (opcion) {
            case 1:
                realizarApuesta(pilotos, ids, equipos);
                break;
            case 2:
                mostrarHistorialApuestas();
                break;
            case 3:
                mostrarRankingApostadores();
                break;
            case 4:
                cout << GREEN << "Gracias por apostar!\n" << RESET;
                break;
        }
        
        if (opcion != 4) {
            cout << "\nPresiona ENTER para continuar...";
            cin.ignore();
            cin.get();
        }
        
    } while (opcion != 4);
}


//validaciones de lo anterior
 // colores para mensajes de error (solo si no están definidos)
#ifndef RED
#define RED "\x1b[31m"
#endif
#ifndef RESET
#define RESET "\x1b[0m"
#endif

// Funcion para validar que sea un numero entero dentro del rango especificado
int pedirNumero(int minimo, int maximo) {
    int numeroElegido;
    while (true) {
        if (cin >> numeroElegido) {
            if (numeroElegido >= minimo && numeroElegido <= maximo) {
                cin.ignore(10000, '\n'); // Limpiar buffer despues de entrada valida
                return numeroElegido;
            } else {
                cout << RED << "Ese numero no esta en el rango (" << minimo << "-" << maximo << ").\n Prueba otro: " << RESET;
                cin.ignore(10000, '\n'); // Limpiar buffer despues de entrada invalida
            }
        } else {
            cout << RED << "Eso no es un numero valido amigo.\n Solo numeros porfa. Intentalo otra vez: " << RESET;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

// Funcion para pedir un nombre (letras y espacios)
string pedirNombre(const string& mensaje) {
    string nombreUsuario;
    while (true) {
        cout << mensaje;
        getline(cin, nombreUsuario);
        
        // Verificar que no este vacio o solo con espacios
        bool soloEspacios = true;
        for (char letra : nombreUsuario) {
            if (letra != ' ' && letra != '\t') {
                soloEspacios = false;
                break;
            }
        }
        
        if (nombreUsuario.empty() || soloEspacios) {
            cout << RED << "Oye, no puedes dejar esto vacio.\n Escribeme algo porfa.\n" << RESET;
            continue;
        }
        
        // Verificar que solo contenga letras y espacios (sin numeros ni simbolos)
        for (char letra : nombreUsuario) {
            if (!((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z') || letra == ' ')) {
                cout << RED << "Solo letras y espacios amigo. Nada de numeros o simbolos raros.\n Intentalo de nuevo.\n" << RESET;
                goto intentarOtraVez;
            }
        }
        
        return nombreUsuario;
        intentarOtraVez:;
    }
}

//Funciones de la billetera
 //funcion para sumar dinero ganado a billetera
    float winnerResult(float personalWallet, float winnBet){
        float resultWallet;
        resultWallet = personalWallet + winnBet;
        if (resultWallet < 0){
            resultWallet = 0;
        }
        return resultWallet;

    }

    //funcion para restar dinero a la billetera
    float loserResult(float personalWallet, float winnBet){
        float minusWallet;
        minusWallet = personalWallet - winnBet;
        if (minusWallet < 0){
            minusWallet = 0;
        }
        return minusWallet;

    }

    //funcion para crear el historial de la billetera
    void registerChange(const players& p){
        ofstream archivo("historial_wallet.txt", ios::app); //ios::app para agregar y no sobreescribir
        if (archivo.is_open()) {
            archivo << "------Registro de billetera------\n" << endl;
            archivo << p.userName << endl;
            archivo << p.wallet << endl;
            archivo << p.chosenRace.name << endl;
            archivo << "---------------------------------\n" << endl;
            archivo.close();
    } else {
        cout << "No se pudo guardar historial.\n";
    }
    }


    //funcion para mostrar el historial de la billetera
    void showHistorial(){
        ifstream archivo("historial_wallet.txt");
        if (archivo.is_open()) {
            string line;
            cout << "\n=====Historial de billetera=====\n"<< endl;
            while(getline(archivo, line)){
                cout << line << endl;
            }
            archivo.close();
        } else {
        cout << "Error: no se pudo abrir el historial.\n";
    }
    } 


