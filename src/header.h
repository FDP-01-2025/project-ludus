#ifndef HEADER_H
#define HEADER_H 

// Pretty colors for the cars
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

using namespace std;
// Track Structure
struct Rtracks {
    string name;
    string located;
    string difficulty_Level;
    float large_km;
};

// Player Structure
struct players {
    string userName;
    int age;
    float wallet;
    Rtracks chosenRace;
};

// External global player variable (declared in main.cpp)
extern players player; 

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

// Simulator constants
const int howManyTeams = 5;
const int pilotsPerTeam = 2;

// Structure to save data for each team
struct Team {
    string teamName;
    Pilot pilots[pilotsPerTeam];
};



// ========== FUNCTION DECLARATIONS ==========

// Login and user functions
void showTitle();
void showMenu();
bool onlyLetters(const string& str);
void validateNames(players& p);

// Validation Functions
int askNumber(int minimum, int maximum);
string askName(const string& message);

// Wallet Functions
float winnerResult(float personalWallet, float winnBet);
float loserResult(float personalWallet, float winnBet);

// Track Functions
void showAsciiTrack(string nameArchive);
void tracksF1();

// Pilot Car Functions
void drawCar1();   // Max Verstappen's car
void drawCar2();   // Sergio Pérez's car
void drawCar3();   // Lewis Hamilton's car
void drawCar4();   // George Russell's car
void drawCar5();   // Charles Leclerc's car
void drawCar6();   // Carlos Sainz's car
void drawCar7();   // Lando Norris's car
void drawCar8();   // Oscar Piastri's car
void drawCar9();   // Fernando Alonso's car
void drawCar10();  // Lance Stroll's car
void drawCar11();  // Custom car 1 - Sports style
void drawCar12();  // Custom car 2 - Classic style

// Simulator Functions
void showTeams(Team teams[]);
void showPilots(Team team);
bool loadPilot(Pilot &p);
void createPilot();
void viewCars();
void startF1Simulator();

// Betting Functions
string getCustomCarType();
void showPilotCar(int pilotId);
int simulateRaceTime();
void showComment();
vector<RaceResult> simulateRace(vector<string> pilots, vector<int> ids, vector<string> teams);
void showPodium(const vector<RaceResult>& results);
void showBetTypes();
void placeBet(const vector<string>& pilots, const vector<int>& ids, const vector<string>& teams);
void updateBettorRanking(const string& name, bool won, int moneyWon);
void showBettorRanking();
void showBettingHistory();
bool loadCustomPilot(string& name, int& id, string& team);
void startBettingSystem();

// Game Flow Functions
void postRaceMenu(players& p);

#endif