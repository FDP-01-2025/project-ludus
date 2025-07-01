#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <iostream>
#include <string>
using namespace std;

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

#endif // VALIDACIONES_H