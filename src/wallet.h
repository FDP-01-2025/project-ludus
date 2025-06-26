//wallet.h
#include <iostream>
#include <fstream>
using namespace std;
#ifndef WALLET_H
#define WALLET_H

struct players {
    string userName;
    float wallet;
    char race[50];
};

    float winnerResult(float personalWallet, float winnBet);
    float loserResult (float personalWallet, float winnBet);
    void registerChange(const players& p);
    void showHistorial();


#endif 

