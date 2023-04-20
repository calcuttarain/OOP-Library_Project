//
//  sala.h
//  131_Pistol_Tudor_Proiect1
//
//  Created by Tudor Pistol on 20.04.2023.
//

#ifndef sala_h
#define sala_h
using namespace std;

class Sala{
private:
    const int nrSala;
    static int contorSala;
    int nrLocuriSala;
    int nrLocuriOcupate;
    int *idCititori;
    struct dimensiune{
        double lungime;
        double latime;
    }dimensiuneSala;
public:
    dimensiune getDimensiuneSala() {return this->dimensiuneSala;}
    const void setDimensiuneSala(dimensiune dimensiuneSala);
//constructori
    Sala();
    Sala(int nrLocuriSala, int nrLocuriOcupate, int *idCititori, dimensiune dimensiuneSala);
    Sala(int nrLocuriSala, dimensiune dimensiuneSala);
    Sala(int nrLocuriSala, int nrLocuriOcupate);
    Sala(const Sala &obj); //copy-constructor
    ~Sala();
//operatori
    Sala &operator =(const Sala &s);
    Sala &operator + (int);
    friend Sala operator + (int idCititor, Sala &s);
    Sala &operator - (int);
    Sala &operator ++ ();
    Sala operator ++ (int);
    Sala &operator -- ();
    Sala operator -- (int);
    int operator [] (int);
    operator int() {return this->nrLocuriSala;}
    bool operator == (Sala &s);
    bool operator > (Sala &s);
    bool operator >= (Sala &s);
    bool operator <= (Sala &s);
    bool operator < (Sala &s);
    friend istream &operator >> (istream &in, Sala &s);
    friend ostream &operator << (ostream &out, const Sala &s);
    int getNrLocuriOcupate () {return nrLocuriOcupate;}
    int getNrSala () {return nrSala;}
};


#endif
