#include <iostream>
#include <string.h>
#include "film.h"
using namespace std;

Film::Film():obiectDeImprumutat()
{
    nume = "Necunoscut";
    regizor = "Necunoscut";
    actori.push_back("Necunoscuți");
    an = -1;
}

Film::Film(string nume, string regizor, vector <string> actori, int an, bool status, stari stare, int idUtilizatorCurent):obiectDeImprumutat(status, stare, idUtilizatorCurent)
{
    this->nume = nume;
    this->regizor = regizor;
    for(auto i = actori.rbegin(); i != actori.rend(); i++)
        this->actori.push_back(*i);
    this->an = an;
}

Film::Film(const Film &f):obiectDeImprumutat(f)
{
    this->nume = f.nume;
    this->regizor = f.regizor;
    for(auto i = f.actori.rbegin(); i != f.actori.rend(); i++)
        this->actori.push_back(*i);
    this->an = f.an;
}

Film& Film::operator = (const Film &f)
{
    if(this != &f)
    {
        obiectDeImprumutat::operator=(f);
        this->nume = f.nume;
        this->regizor = f.regizor;
        for(auto i = f.actori.rbegin(); i != f.actori.rend(); i++)
            this->actori.push_back(*i);
        this->an = f.an;
    }
    return *this;
}

istream& Film::inregistrare(istream& in)
{
    cout << "Introduceți numele filmului: ";
    getline(in, nume);
    cout << "Cine l-a regizat? ";
    getline(in, regizor);
    cout << "Câți actori trebuie menționați? ";
    int nr;
    in >> nr;
    in.get();
    cout << "Introduceți numele actorilor separate prin tasta enter: ";
    if(!actori.empty())
        actori.clear();
    for (int i = 0; i<nr; i++)
    {
        string s;
        getline(in, s);
        actori.push_back(s);
    }
    cout << "În ce an a avut loc premiera filmului? ";
    in >> an;
    cout << "În ce stare se află filmul?[nou/folosit/uzat]";
    string aux;
    in >> aux;
    cout << endl;
    if (aux == "nou") stare = nou;
    else if (aux == "folosit") stare = folosit;
    else if (aux == "uzat") stare = uzat;
    cout << "Este disponibil pentru împrumut?[0/1] ";
    in >> status;
    if (status == 0)
    {
        cout << "Introduceti ID-ul utilizatorului care a imprumutat-o: ";
        in >> idUtilizatorCurent;
    }
    return in;
}

ostream& Film::afisare(ostream& out) const
{
    out << "Nume film: " << nume << endl;
    out << "Regizor: " << regizor << endl;
    out << "Actori: ";
    if(actori.size() > 1)
        for(int i = 0; i < actori.size()-1; i++)
            out << actori [i] << ", ";
    out << actori[actori.size()-1] << "." << endl;
    out << "Anul premierei: " << an << endl << endl;
    if (status == 0) out << "Împrumutat de utilizatorul cu ID-ul ";
    else out << "Disponibil" << endl;
    if (status == 0) out << idUtilizatorCurent << "." <<endl;
    out << "Înregistrat la data de: " << dataInregistrare.zi << "." << dataInregistrare.luna << "." << dataInregistrare.an << endl;
    return out;
}

istream &operator >> (istream& in, Film &f)
{
    cout << "Introduceți numele filmului: ";
    getline(in, f.nume);
    cout << "Cine l-a regizat? ";
    getline(in, f.regizor);
    cout << "Câți actori trebuie menționați? ";
    int nr;
    in >> nr;
    in.get();
    cout << "Introduceți numele actorilor separate prin tasta enter: ";
    if(!f.actori.empty())
        f.actori.clear();
    for (int i = 0; i<nr; i++)
    {
        string s;
        getline(in, s);
        f.actori.push_back(s);
    }
    cout << "În ce an a avut loc premiera filmului? ";
    in >> f.an;
    cout << "În ce stare se află filmul?[nou/folosit/uzat]";
    string aux;
    in >> aux;
    if (aux == "nou") f.stare = nou;
    else if (aux == "folosit") f.stare = folosit;
    else if (aux == "uzat") f.stare = uzat;
    cout << "Este disponibil pentru împrumut?[0/1] ";
    in >> f.status;
    if (f.status == 0)
    {
        cout << "Introduceti ID-ul cititorului care a imprumutat-o: ";
        in >> f.idUtilizatorCurent;
    }
    return in;
}

ostream &operator << (ostream& out, Film &f)
{
    out << "Nume film: " << f.nume << endl;
    out << "Regizor: " << f.regizor << endl;
    out << "Actori: ";
    if(f.actori.size() > 1)
        for(int i = 0; i < f.actori.size()-1; i++)
            out << f.actori [i] << ", ";
    out << f.actori[f.actori.size()-1] << "." << endl;
    out << "Anul premierei: " << f.an << endl;
    if (f.status == 0) out << "Împrumutată de utilizatorul cu ID-ul ";
    else out << "Disponibilă" << endl;
    if (f.status == 0) out << f.idUtilizatorCurent << "." << endl;
    out << "Înregistrată la data de: " << f.dataInregistrare.zi << "." << f.dataInregistrare.luna << "." << f.dataInregistrare.an << endl;
    return out;
}
