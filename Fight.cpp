//
// Created by USUARIO on 5/10/2019.
//

#include "Fight.h"
#include <fstream>
#include <iostream>

Arena::Arena(string filename) {
    load_fights(filename);
}

Arena::~Arena() {
}

void Arena::run(Fighter a, Fighter b) {
    if ((a.defence()-b.attack()) > (b.defence()-a.attack()))
        cout << "The winner is " << a.get_identificador();
    else
        cout << "The winner is " << b.get_identificador();
}



void Arena::load_fights(string filename) {
    ifstream ArchivoALeer;
    ArchivoALeer.open(filename);
    if(!ArchivoALeer.is_open()) {cout << "No se pudo abrir";}
    string Peleador;
    string Defensa1; string Defensa2; string Defensa3;
    string Ataque1; string Ataque2; string Ataque3;
    vector <string> Defences;
    vector <string> Attacks;
    string Peleador1;
    string Defensa4; string Defensa5; string Defensa6;
    string Ataque4; string Ataque5; string Ataque6;
    vector <string> Defences1;
    vector <string> Attacks1;

    while(ArchivoALeer.good()) {
        getline(ArchivoALeer, Peleador, '\n');
        getline(ArchivoALeer, Defensa1, ',');
        getline(ArchivoALeer, Defensa2, ',');
        getline(ArchivoALeer, Defensa3, '\n');
        getline(ArchivoALeer, Ataque1, ',');
        getline(ArchivoALeer, Ataque2, ',');
        getline(ArchivoALeer, Ataque3, '\n');
        Defences.push_back(Defensa1);
        Defences.push_back(Defensa2);
        Defences.push_back(Defensa3);
        Attacks.push_back(Ataque1);
        Attacks.push_back(Ataque2);
        Attacks.push_back(Ataque3);

        getline(ArchivoALeer, Peleador1, '\n');
        getline(ArchivoALeer, Defensa4, ',');
        getline(ArchivoALeer, Defensa5, ',');
        getline(ArchivoALeer, Defensa6, '\n');
        getline(ArchivoALeer, Ataque4, ',');
        getline(ArchivoALeer, Ataque5, ',');
        getline(ArchivoALeer, Ataque6, '\n');
        Defences1.push_back(Defensa4);
        Defences1.push_back(Defensa5);
        Defences1.push_back(Defensa6);
        Attacks1.push_back(Ataque4);
        Attacks1.push_back(Ataque5);
        Attacks1.push_back(Ataque6);

        Fighter* f1;
        if(Peleador == "BL")
            f1 = new BruceLee(Attacks, Defences);
        else if (Peleador == "CN")
            f1 = new ChuckNorris(Attacks,Defences);
        else
            f1 = new JasonStatham(Attacks,Defences);

        Fighter* f2;
        if(Peleador == "BL")
            f2 = new BruceLee(Attacks, Defences);
        else if (Peleador == "CN")
            f2 = new ChuckNorris(Attacks,Defences);
        else
            f2 = new JasonStatham(Attacks,Defences);

        Fight fi1(f1, f2);
        Fights.push_back(fi1);
    }

}

void Arena::run_all() {
    for (int i = 0; i < Fights.size(); i++ ) {
        Fights[i].winner = ((Fights[i].a->defence() - Fights[i].b->attack()) > (Fights[i].b->defence() - Fights[i].a->attack())) ? Fights[i].a : Fights[i].b;
        cout << "The winner of fight " << i << " is " << Fights[i].winner->get_identificador();
    }
}

int Fighter::attack() {
    int SumAttacks = 0;
    for (int i = 0; i < 3; i++)
        SumAttacks += attacks[i].attack();
    return SumAttacks;
}

int Fighter::defence() {
    int SumDefence = 0;
    for (int i = 0; i < 3; i++)
        SumDefence += defences[i].defence();
    return 0;
}

Fighter::Fighter(vector <string> _attacks, vector <string> _defences) {
    for (int i = 0; i < attacks.size(); i++) {
        if (_attacks[i] == "P") {
            Punch a;
            attacks.push_back(a);
        } else if (_attacks[i] == "S") {
            Saber a;
            attacks.push_back(a);
        }
        else {
            Firearm a;
            attacks.push_back(a);
        }
    }
    for (int i = 0; i < _defences.size(); i++) {
        if (_defences[i] == "E") {
            Elude a;
            defences.push_back(a);
        } else if (_defences[i] == "S") {
            Shield a;
            defences.push_back(a);
        }
        else {
            Armor a;
            defences.push_back(a);
        }
    }
}

Fight::Fight(Fighter* _a, Fighter* _b) {
    a = _a;
    b = _b;
}

Fight::~Fight() {
    delete a;
    delete b;
    delete winner;
}
