#ifndef SISTEMA_APUESTAS_H
#define SISTEMA_APUESTAS_H

#include <string>
#include <vector>
using namespace std;

// Funciones del sistema de apuestas
void mostrarTiposApuesta();
void realizarApuesta(const vector<string>& pilotos, const vector<int>& ids, const vector<string>& equipos);
void actualizarRankingApostador(const string& nombre, bool gano, int dineroGanado);
void mostrarRankingApostadores();
void mostrarHistorialApuestas();
void iniciarSistemaApuestas();

#endif // SISTEMA_APUESTAS_H
