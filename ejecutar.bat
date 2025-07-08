@echo off
echo Compilando proyecto F1...
g++ -o main.exe src/main.cpp src/header.cpp
if %errorlevel% == 0 (
    echo Compilacion exitosa!
    echo Ejecutando juego...
    main.exe
) else (
    echo Error en la compilacion!
    pause
)



