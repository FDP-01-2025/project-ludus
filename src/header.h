//wallet.h
#ifndef HEADER_H
#define HEADER_H


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

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include "header.h" //libreria de la billetera

using namespace std;



struct players {
    string userName;
    float wallet;
    string race;
};
 extern players player; //esta en el archivo main de manera global 

// Estructura para guardar datos de una apuesta
struct Apuesta {
    string nombreJugador;
    string tipoApuesta;      // "Grand Total", "Grand Prix", "Sprint"
    string pilotoElegido;
    int montoApostado;
    bool gano;
    int premio;
};
// Estructura para el resultado de una carrera
struct ResultadoCarrera {
    string nombrePiloto;
    int idPiloto;
    string equipo;
    int posicion;
    int tiempoCarrera;       // En milisegundos simulados
};
// Estructura para el ranking de apostadores
struct Apostador {
    string nombre;
    int dineroTotal;
    int apuestasGanadas;
    int apuestasTotal;
};
// Estructura de las Pistas
 struct Rtracks {
        string name;
        string located;
        string difficulty_Level;
        float large_km;

    };
    // Estructura para guardar datos de cada piloto
struct Piloto {
    string nombre;
    int id;
    string modeloCarro;
    string tipoModelo;      // Para saber si es Deportivo o Clasico
    string nombreEquipo;    // Para pilotos personalizados
};

// Estructura para guardar datos de cada equipo
 // Constantes del simulador
const int cuantosEquipos = 5;
const int pilotosPorEquipo = 2;

struct Equipo {
    string nombreEquipo;
    Piloto pilotos[pilotosPorEquipo];
};



/*Declaraciones de funciones*/ 

/**Funciones de Validacion**/
//Funcion para validar que sea un numero entero dentro del rango especificado
int pedirNumero(int minimo, int maximo);
// Funcion para pedir un nombre (letras y espacios)
string pedirNombre(const string& mensaje);

/*Funciones de la Billetera*/
float winnerResult(float personalWallet, float winnBet);
float loserResult (float personalWallet, float winnBet);
void registerChange(const players& p);
void showHistorial()
;
// Esta funcion me enseña todos los equipos en una lista
void mostrarPilotos(Equipo equipo);
// Esta me muestra los pilotos de un equipo especifico
void mostrarEquipos(Equipo equipos[]);
// Esta funcion lee un piloto extra desde un archivo
bool cargarPiloto(Piloto &p);
// Esta funcion guarda un piloto nuevo en un archivo
void crearPiloto();
// Esta funcion muestra los carros disponibles para elegir
void verCarros();
// Función principal del simulador F1 (equivalente al main original)
void iniciarSimuladorF1();
// Función para obtener el tipo de carro del piloto personalizado
string obtenerTipoCarroPersonalizado();
// Función para mostrar el carro del piloto segun su numero
void mostrarCarroPiloto(int idPiloto);
// Funcion para simular cuanto tarda cada piloto
int simularTiempoCarrera();
// Función para mostrar comentarios durante la carrera
void mostrarComentario();
// Funcion para hacer la carrera completa
vector<ResultadoCarrera> simularCarrera(vector<string> pilotos, vector<int> ids, vector<string> equipos);
// Funcion para mostrar el podio al final
void mostrarPodio(const vector<ResultadoCarrera>& resultados);
// Función para mostrar tipos de apuesta (sin saldo)
void mostrarTiposApuesta();
// Función para realizar una apuesta
void realizarApuesta(const vector<string>& pilotos, const vector<int>& ids, const vector<string>& equipos);
// Función para actualizar el ranking de apostadores
void actualizarRankingApostador(const string& nombre, bool gano, int dineroGanado);
// Función para mostrar el ranking de apostadores
void mostrarRankingApostadores();
// Función para mostrar historial de apuestas
void mostrarHistorialApuestas();
// Función para cargar piloto personalizado si existe
bool cargarPilotoPersonalizado(string& nombre, int& id, string& equipo);
// Función principal del sistema de apuestas
void iniciarSistemaApuestas();

/*Funciones De las pistas*/
//Esta funcion nos ayuda a mostrar los ascii de los vehiculos
void Show_asciiTrack (string namearchive);
//Funcion para mostrar pistas
void Tracks_f1 ();

/*Funciones de los carros de los pilotos*/
// Carro de Max Verstappen
void drawCar1();
// Carro de Sergio Pérez
void drawCar2();
// Carro de Lewis Hamilton
void drawCar3();
// Carro de George Russell
void drawCar4();
// Carro de Charles Leclerc
void drawCar5();
// Carro de Carlos Sainz
void drawCar6();
// Carro de Lando Norris
void drawCar7(); 
// Carro de Oscar Piastri
void drawCar8();
// Carro de Fernando Alonso
void drawCar9();
// Carro de Lance Stroll
void drawCar10();
// Carro personalizado 1 - Estilo deportivo
void drawCar11();
// Carro personalizado 2 - Estilo clasico
void drawCar12(); 
#endif