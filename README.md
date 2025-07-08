# Proyecto de C++ - Random Racing Luck

## Descripción del Proyecto

Este proyecto consiste en un videojuego por consola donde varios jugadores pueden participar en un sistema de apuestas basado en carreras de Fórmula 1. Cada jugador puede apostar por un piloto, y luego se simula la carrera de forma aleatoria. Según el resultado, el jugador puede ganar o perder dinero virtual.
El objetivo principal es poner en práctica los temas aprendidos en clase (If, Else-if, Switch, For, While, Arrays, archivos, funciones) de forma divertida y funcional. 

## Equipo

- **Nombre del equipo:** Ludus

### Integrantes del equipo

1. **Nombre completo:** Rachel Alejandra Oviedo Castellanos  
   **Carnet:** 00033125

2. **Nombre completo:** Carlos Enmanuel Marcos Palma   
   **Carnet:** 00208225

3. **Nombre completo:** Angelica Michelle Mendoza Chicas   
   **Carnet:** 00059725

4. **Nombre completo:** Norberto René Revelo Burgos  
   **Carnet:** 00034425



## Instrucciones de Ejecución
1. Compilar el programa

Asegúrate de tener un compilador de C++  Desde consola, ejecuta:
g++ main.cpp -o (nombre que queresmos colocar)

2. Ejecutar el programa

En la consola, ejecuta el archivo compilado
* En el menú principal, elige la opción para realizar apuestas, ver ranking o salir
* Tras cada carrera, puedes ver resultados, podio, y continuar apostando o salir.


## 🏁Temática y ambientación🏁 :

El juego está inspirado en el mundo de la Fórmula 1, uno de los deportes de motor más populares y competitivos a nivel mundial.
La ambientación busca recrear la sensación de estar en un gran premio de Fórmula 1, con pilotos destacados, estadísticas y resultados sorprendentes en cada carrera. Aunque se juega desde la consola, la interfaz está diseñada para transmitir dinamismo y emoción, manteniendo al jugador atento a cada momento de la carrera.


## Mecánica principal

La mecánica principal del juego se centra en el sistema de apuestas virtuales sobre carreras de Fórmula 1. Los jugadores comienzan con un saldo inicial de dinero ficticio y pueden apostar la cantidad que deseen en cada carrera.

--Funciones 
1) loserResult
Propósito: Actualizar saldo tras perder una apuesta.
Qué hace:
Resta la pérdida del saldo.
Asegura que saldo no sea negativo (mínimo 0)

2) startBettingSystem
Propósito: Controlar el menú principal del sistema de apuestas.
Qué hace:
Muestra el menú para apostar, ver historial, ver ranking o salir.
Llama a las funciones correspondientes según la opción elegida.

3) postRaceMenu
Propósito: Menú que aparece después de una carrera.
Permite repetir o terminar.

4) system("cls")
 Esto ayuda a crear la sensación de "pantalla nueva" cuando muestras una nueva etapa del juego, como pasar de menú a carrera
Que hace:
limpia la consola

5) cin.ignore() y cin.get()
¿Qué hacen?
cin.ignore() limpia el buffer de entrada. Muy útil cuando mezclas cin >> variable y getline()
cin.get()  espera a que el usuario presione Enter.

## Idea general de la jugabilidad

La interacción se basa principalmente en menús y opciones, lo que permite navegar de forma sencilla. 
En cada carrera, el jugador podrá:
=Visualiza y selecciona tu equipo y piloto
=Ver la lista de pilotos disponibles.
-Escoge entre cinco circuitos mundialmente famosos, cada uno con su nivel de dificultad y longitud diferente
-Admira el diseño detallado de cada vehículo en ASCII art, con colores únicos que representan a cada piloto.
-Selecciona uno de los equipos oficiales (Red Bull, Ferrari, Mercedes, McLaren, Aston Martin)

## Aplicación de los temas vistos (uno por uno con ejemplos)

 * Aleatoriedad:
Uso de rand() para generar tiempos y eventos variables en la carrera, simulando incertidumbre y realismo.
Ejemplo:
cpp
Copiar
Editar
int tiempoBase = 85000 + (rand() % 5000);

* Manejo de archivos:
Para cargar piloto personalizado desde archivo externo.
Ejemplo:

cpp
Copiar
Editar
ifstream archivo("piloto_extra.txt");

* Vectores (std::vector):
Manejo dinámico de listas como pilotos, resultados y historial de apuestas.
Ejemplo:

cpp
Copiar
Editar
vector <string> pilots = {"Max Verstappen", "Lewis Hamilton", ...};

* Manejo de cadenas y formato:
Para mostrar nombres, equipos, y resultados con colores y emojis en consola.
Ejemplo:

cpp
Copiar
Editar
cout << GREEN << "🏆 ¡" << pilots[chosenPilot] << " ganó la carrera!" << RESET << endl;

* Entrada y validación:
Uso de ciclos y condiciones para garantizar que el usuario ingrese datos válidos, evitando errores en ejecución.
Ejemplo:

cpp
Copiar
Editar
int askNumber(int minimum, int maximum);

## Consideraciones técnicas del desarrollo

* El proyecto está desarrollado en C++ 
* Para la simulación de tiempos y eventos, se usa la función rand() con semillas variadas para mayora eatoriedad.
* El código utiliza códigos de color ANSI y emojis UTF-8 para mejorar la experiencia visual en consola

## Imágenes o mockups del juego

  🎨
"
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
 '----------------'   '----------------' "

  🚗💨 WELCOME TO THE 🚦 Random Racing Luck GAME
          WELCOME TO THE GAME
           ¿QUÉ AUTO QUIERES?
        1. Auto Deportivo
        2. Auto Clásico
   
    ¿Cuál te gusta más?

1. Clona este repositorio en tu máquina local:
   ```bash
   git clone [https://github.com/FDP-01-2025/project-ludus.git]
