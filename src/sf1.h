#ifndef SIMULADOR_F1_H
#define SIMULADOR_F1_H

#include <iostream>
#include <fstream>
#include <string>
#include "carros.h"
#include "validaciones.h"
using namespace std;

// Constantes del simulador
const int cuantosEquipos = 5;
const int pilotosPorEquipo = 2;

// Estructura para guardar datos de cada piloto
struct Piloto {
    string nombre;
    int id;
    string modeloCarro;
    string tipoModelo;      // Para saber si es Deportivo o Clasico
    string nombreEquipo;    // Para pilotos personalizados
};

// Estructura para guardar datos de cada equipo
struct Equipo {
    string nombreEquipo;
    Piloto pilotos[pilotosPorEquipo];
};

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

#endif // SIMULADOR_F1_H