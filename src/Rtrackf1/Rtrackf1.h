#include <iostream>
#include <cstring>
#include <ctime>
#include <fstream>
using namespace std;

 struct Rtracks {
        string name;
        string located;
        string difficulty_Level;
        float large_km;

    };
void Show_asciiTrack (string namearchive) {
    ifstream Archive (namearchive);
    if (!Archive) {
        cout << "No se pudo abrir el archivo: " << namearchive << endl;
        return;
    }

    string line;
    while (getline(Archive, line)) {
        cout << line << endl;
    }

    Archive.close();
}

void Tracks_f1 (){
    Rtracks pistas [5]{
        {" SilverStone", " United Kindom", " High", 5.896 },
        {" Monza","Italy" ," Medium", 5.793},
        {" Suzuka"," Japan", " High", 5.807},
        {" Interlagos", " Brasil", " High", 5.470},
        {" Monaco", " Italy", " Low", 3.330}

    };

    for(int i=0;i<5;i++){
        cout<< i+1<< pistas[i].name<<endl;
    };

    int opcion;

    cout<<"Select a Track! (1-5):"<<" ";
    cout<<"";
    cin>> opcion;

    if (opcion <1 ||opcion >5){
        cout<<"invalid opcion"<<endl;
        return;
    }
   
    Rtracks Selecction = pistas [opcion-1];
    cout<< "About..."<<endl;
    cout<<"";
    cout<<"Name:"<<""<<Selecction.name<<endl;
    cout<<"Located:"<<""<<Selecction.located<<endl;
    cout<<"Difficulty:"<<""<<Selecction.difficulty_Level<<endl;
    cout<<"Distance:"<<""<<Selecction.large_km<<"km"<<endl;


}