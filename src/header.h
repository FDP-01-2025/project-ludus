//wallet.h
#ifndef HEADER_H
#define HEADER_H 


// pretty colors for the cars
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
#include "header.h" //wallet library

using namespace std;
// Track Structure
 struct Rtracks {
        string name;
        string located;
        string difficulty_Level;
        float large_km;

    };

struct players {
    string userName;
    int age;
    float wallet;
    Rtracks chosenRace;
};
 extern players player; //this is in the main file globally 

// Structure to save bet data
struct Bet {
    string playerName;
    string betType;      // "Grand Total", "Grand Prix", "Sprint"
    string chosenPilot;
    int betAmount;
    bool won;
    int prize;
};
// Structure for race results
struct RaceResult {
    string pilotName;
    int pilotId;
    string team;
    int position;
    int raceTime;       // In simulated milliseconds
};
// Structure for bettor ranking
struct Bettor {
    string name;
    int totalMoney;
    int wonBets;
    int totalBets;
};

    // Structure to save data for each pilot
struct Pilot {
    string name;
    int id;
    string carModel;
    string modelType;      // To know if it's Sports or Classic
    string teamName;    // For custom pilots
};

// Structure to save data for each team
 // Simulator constants
const int howManyTeams = 5;
const int pilotsPerTeam = 2;

struct Team {
    string teamName;
    Pilot pilots[pilotsPerTeam];
};



/*Function Declarations*/ 
// Login and user functions
void showTitle();
void showMenu();
bool onlyLetters(const string& str);
void validateNames(players& p);


/**Validation Functions**/
//Function to validate that it's an integer within the specified range
int askNumber(int minimum, int maximum);
// Function to ask for a name (letters and spaces)
string askName(const string& message);

/*Wallet Functions*/
float winnerResult(float personalWallet, float winnBet);
float loserResult (float personalWallet, float winnBet);
void registerChange(const players& p);
void showHistory();
// This function shows me all the teams in a list
void showPilots(Team team);
// This one shows me the pilots of a specific team
void showTeams(Team teams[]);
// This function reads an extra pilot from a file
bool loadPilot(Pilot &p);
// This function saves a new pilot to a file
void createPilot();
// This function shows the available cars to choose from
void viewCars();
// Main function of the F1 simulator (equivalent to the original main)
void startF1Simulator();
// Function to get the car type of the custom pilot
string getCustomCarType();
// Function to show the pilot's car according to their number
void showPilotCar(int pilotId);
// Function to simulate how long each pilot takes
int simulateRaceTime();
// Function to show comments during the race
void showComment();
// Function to make the complete race
vector<RaceResult> simulateRace(vector<string> pilots, vector<int> ids, vector<string> teams);
// Function to show the podium at the end
void showPodium(const vector<RaceResult>& results);
// Function to show bet types (without balance)
void showBetTypes();
// Function to place a bet
void placeBet(const vector<string>& pilots, const vector<int>& ids, const vector<string>& teams);
// Function to update the bettor ranking
void updateBettorRanking(const string& name, bool won, int moneyWon);
// Function to show the bettor ranking
void showBettorRanking();
// Function to show betting history
void showBettingHistory();
// Function to load custom pilot if it exists
bool loadCustomPilot(string& name, int& id, string& team);
// Main function of the betting system
void startBettingSystem();

/*Track Functions*/
//This function helps us show the ascii of the vehicles
void showAsciiTrack(string nameArchive);
//Function to show tracks
void tracksF1();

/*Pilot Car Functions*/
// Max Verstappen's car
void drawCar1();
// Sergio Pérez's car
void drawCar2();
// Lewis Hamilton's car
void drawCar3();
// George Russell's car
void drawCar4();
// Charles Leclerc's car
void drawCar5();
// Carlos Sainz's car
void drawCar6();
// Lando Norris's car
void drawCar7(); 
// Oscar Piastri's car
void drawCar8();
// Fernando Alonso's car
void drawCar9();
// Lance Stroll's car
void drawCar10();
// Custom car 1 - Sports style
void drawCar11();
// Custom car 2 - Classic style
void drawCar12(); 
#endif