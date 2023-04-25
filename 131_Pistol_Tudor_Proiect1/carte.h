#ifndef carte_h
#define carte_h
#include "obiectDeImprumutat.h"
using namespace std;

class Carte : virtual public obiectDeImprumutat{
protected:
    string titlu;
    char *autor;
    int anAparitie;
public:
//constructors:
    Carte(); //constructorul fara parametri
    Carte(string titlu, char *autor, int anAparitie, bool status, stari stare, int idUtilizatorCurent); //constructorul cu toti parametrii
    Carte(const Carte &ob); //copy-constructor
    ~Carte(); //destructor
//operatori
    bool operator == (const Carte &c);
    bool operator < (const Carte &c);
    bool operator <= (const Carte &c);
    bool operator > (const Carte &c);
    bool operator >= (const Carte &c);
    operator string () {return this->titlu;}
    Carte &operator = (const Carte &ob); //forma incarcata a operatorului de atribuire
    friend istream &operator >> (istream &in, Carte &c); //supraincarcarea operatorului de citire
    friend ostream &operator << (ostream &out, const Carte &ca); //supraincarcarea operatorului de afisare
//setters
    void setTitlu(string titlu) {this->titlu = titlu;}
    void setAutor(char *autor);
    void setAnAparitie(int anAparitie) {this->anAparitie = anAparitie;}
//getters
    const int getIdCarte() {return idObiect;}
    string getTitlu() {return titlu;}
    const char *getAutor() const {return autor;}
    int getAnAparitie() {return anAparitie;}
    virtual istream& inregistrare(istream& in);
    virtual ostream& afisare(ostream& out) const;
    virtual void obiect () {cout << "Categoria: Carte" << endl;}
};

#endif 
