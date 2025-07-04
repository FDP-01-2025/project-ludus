#include "wallet.h"
#include <iostream>
#include <fstream>
using namespace std;
#include <string> 


struct players {
    string userName;
    float wallet;
    string race;
};

extern players player; //esta en el archivo main de manera global

//Funciones de Log in y usuario 


//Funciones de pistas de carreras


//Funciones de carros


//Funciones de simulador 


//Funciones de apuestas 


//validaciones de lo anterior


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
            archivo << p.race << endl;
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


