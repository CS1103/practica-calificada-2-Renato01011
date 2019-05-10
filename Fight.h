//
// Created by USUARIO on 5/10/2019.
//

#ifndef EXAMEN2_FIGHT_H
#define EXAMEN2_FIGHT_H
#include <vector>
#include <string>

using namespace std;

class Defence {
protected:
    int level;
    char identificador;
public:
    int defence() {return level;}
};

class Attack {
protected:
    int power;
    char identificador;
public:
    int attack() {return power;}
};

class Fighter {
protected:
    vector <Attack> attacks;
    vector <Defence> defences;
    string identificador;
public:
    Fighter(vector <string> _attacks, vector <string> _defences);
    string get_identificador() {return identificador;}
    int attack();
    int defence();
};

class Fight {
public:
    Fight(Fighter* _a, Fighter* _b);
    ~Fight();
    Fighter* a;
    Fighter* b;
    Fighter* winner;
    int score;
};

class Arena {
    vector <Fight> Fights;
public:
    Arena(string filename);
    ~Arena();
    void run(Fighter a, Fighter b);
    vector <Fight> get_fights() {return Fights;}
    void load_fights(string filename);
    void run_all();
};

class BruceLee: public Fighter {
public:
    BruceLee(vector <string> _attacks, vector <string> _defences): Fighter(_attacks,_defences) {
        identificador = "BL";
    }
};

class ChuckNorris: public Fighter {
public:
    ChuckNorris(vector <string> _attacks, vector <string> _defences): Fighter(_attacks,_defences) {
        identificador = "CN";
    }
};

class JasonStatham: public Fighter {
public:
    JasonStatham(vector <string> _attacks, vector <string> _defences): Fighter(_attacks,_defences) {
        identificador = "JS";
    }
};

class Elude: public Defence {
public:
    Elude():Defence() {
        level = 1;
        identificador = 'E';
    }
};

class Shield: public Defence {
public:
    Shield():Defence() {
        level = 4;
        identificador = 'S';
    }
};

class Armor: public Defence {
public:
    Armor():Defence() {
        level = 8;
        identificador = 'A';
    }
};

class Punch: public Attack {
public:
    Punch():Attack() {
        power = 1;
        identificador = 'P';
    }
};

class Saber: public Attack {
public:
    Saber():Attack() {
        power = 5;
        identificador = 'S';
    }
};

class Firearm: public Attack {
public:
    Firearm():Attack() {
        power = 10;
        identificador = 'F';
    }

};
#endif //EXAMEN2_FIGHT_H
