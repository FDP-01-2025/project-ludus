
@echo off
cd /d "%~dp0"
echo Compilando proyecto F1...
echo Directorio actual: %cd%
if exist "src\main.cpp" (
    echo Archivos encontrados, compilando...
    g++ -o main.exe src\main.cpp src\header.cpp -std=c++11 -static-libgcc -static-libstdc++
    if %errorlevel% == 0 (
        echo Compilacion exitosa!
        echo Ejecutando juego...
        main.exe
    ) else (
        echo Error en la compilacion!
        echo Presiona cualquier tecla para ver mas detalles...
        pause
    )
) else (
    echo Error: No se encontraron los archivos fuente!
    echo Buscando en: %cd%\src\
    dir src\
    pause
)



