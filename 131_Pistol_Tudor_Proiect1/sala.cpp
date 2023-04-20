//
//  sala.cpp
//  131_Pistol_Tudor_Proiect1
//
//  Created by Tudor Pistol on 20.04.2023.
//

#include <iostream>
#include "sala.h"
using namespace std;

int Sala::contorSala = 0;

const void Sala::setDimensiuneSala(dimensiune dimensiuneSala)
{
    this->dimensiuneSala.lungime = dimensiuneSala.lungime;
    this->dimensiuneSala.latime = dimensiuneSala.latime;
}

Sala::Sala():nrSala(++contorSala)
{
    nrLocuriSala = 0;
    nrLocuriOcupate = 0;
    idCititori = NULL;
    dimensiuneSala.lungime = 0;
    dimensiuneSala.latime = 0;
}

Sala::Sala(int nrLocuriSala, int nrLocuriOcupate, int *idCititori, dimensiune dimensiuneSala):nrSala(++contorSala)
{
    this->nrLocuriSala = nrLocuriSala;
    this->nrLocuriOcupate = nrLocuriOcupate;
    this->idCititori = new int[this->nrLocuriOcupate];
    for(int i = 0; i<nrLocuriOcupate; i++)
        this->idCititori[i] = idCititori[i];
    this->dimensiuneSala.lungime = dimensiuneSala.lungime;
    this->dimensiuneSala.latime = dimensiuneSala.latime;
}

Sala::Sala(int nrLocuriSala, dimensiune dimensiuneSala):nrSala(++contorSala)
{
    this->nrLocuriSala = nrLocuriSala;
    nrLocuriOcupate = 0;
    idCititori = NULL;
    this->dimensiuneSala.lungime = dimensiuneSala.lungime;
    this->dimensiuneSala.latime = dimensiuneSala.lungime;
}

Sala::Sala(int nrLocuriSala, int nrLocuriOcupate):nrSala(++contorSala)
{
    this->nrLocuriSala = nrLocuriSala;
    this->nrLocuriOcupate = nrLocuriOcupate;
    idCititori = NULL;
    dimensiuneSala.lungime = 0;
    dimensiuneSala.latime = 0;
}

Sala::Sala(const Sala &obj):nrSala(++contorSala)
{
    this->nrLocuriSala = obj.nrLocuriSala;
    this->nrLocuriOcupate = obj.nrLocuriOcupate;
    this->idCititori = new int[obj.nrLocuriOcupate];
    for(int i = 0; i<obj.nrLocuriOcupate; i++)
        this->idCititori[i] = obj.idCititori[i];
    this->dimensiuneSala.lungime = obj.dimensiuneSala.lungime;
    this->dimensiuneSala.latime = obj.dimensiuneSala.latime;
}

Sala::~Sala()
{
    if(idCititori != NULL)
    {
        delete [] idCititori;
        idCititori = NULL;
    }
}

Sala &Sala::operator =(const Sala &s)
{
    
    this->nrLocuriSala = s.nrLocuriSala;
    this->nrLocuriOcupate = s.nrLocuriOcupate;
    this->idCititori = new int[s.nrLocuriOcupate];
    for(int i = 0; i<s.nrLocuriOcupate; i++)
        this->idCititori[i] = s.idCititori[i];
    this->dimensiuneSala.lungime = s.dimensiuneSala.lungime;
    this->dimensiuneSala.latime = s.dimensiuneSala.latime;
    return *this;
}

Sala& Sala::operator + (int idCititor)
{
    if(this->nrLocuriOcupate + 1 > this->nrLocuriSala)
        throw runtime_error("Sala este deja folosita la capacitate maxima.");
    else
    {
        this->nrLocuriOcupate++;
        int *aux;
        aux = new int[this->nrLocuriOcupate];
        for(int i = 0; i<this->nrLocuriOcupate-1; i++)
            aux[i] = this->idCititori[i];
        aux[this->nrLocuriOcupate-1] = idCititor;
        delete [] this->idCititori;
        this->idCititori = new int[this->nrLocuriOcupate];
        for(int i = 0; i<this->nrLocuriOcupate; i++)
            this->idCititori[i] = aux[i];
        delete [] aux;
        aux = NULL;
        return *this;
    }
}

Sala operator + (int idCititor, Sala &s)
{
    if(s.nrLocuriOcupate + 1 > s.nrLocuriSala)
        throw runtime_error("Sala este deja folosita la capacitate maxima.");
    else
    {
        s.nrLocuriOcupate++;
        int *aux;
        aux = new int[s.nrLocuriOcupate];
        for(int i = 0; i<s.nrLocuriOcupate-1; i++)
            aux[i] = s.idCititori[i];
        aux[s.nrLocuriOcupate-1] = idCititor;
        delete [] s.idCititori;
        s.idCititori = new int[s.nrLocuriOcupate];
        for(int i = 0; i<s.nrLocuriOcupate; i++)
            s.idCititori[i] = aux[i];
        delete [] aux;
        aux = NULL;
        return s;
    }
    
}

Sala& Sala::operator - (int idCititor)
{
    if(this->nrLocuriOcupate == 0)
        throw runtime_error("Sala nu are niciun cititor.");
    else
    {
        for (int i = 0; i<this->nrLocuriOcupate; i++)
            if(idCititor == this->idCititori[i])
            {
                swap(this->idCititori[i], this->idCititori[this->nrLocuriOcupate-1]);
                break;
            }
        this->nrLocuriOcupate--;
        int *aux;
        aux = new int[this->nrLocuriOcupate];
        for(int i = 0; i<this->nrLocuriOcupate; i++)
            aux[i] = this->idCititori[i];
        delete [] this->idCititori;
        this->idCititori = new int[this->nrLocuriOcupate];
        for(int i = 0; i<this->nrLocuriOcupate; i++)
            this->idCititori[i] = aux[i];
        delete [] aux;
        aux = NULL;
        return *this;
    }
}

Sala& Sala::operator ++ ()
{
    this->nrLocuriSala++;
    return *this;
}

Sala Sala::operator ++ (int)
{
    Sala aux(*this);
    this->nrLocuriSala++;
    return aux;
}

Sala& Sala::operator -- ()
{
    this->nrLocuriSala--;
    return *this;
}

Sala Sala::operator -- (int)
{
    Sala aux(*this);
    this->nrLocuriSala--;
    return aux;
}

int Sala::operator [] (int index)
{
    return this->idCititori[index-1];
}

bool Sala::operator == (Sala &s)
{
    if(this->nrLocuriOcupate == s.nrLocuriOcupate)
        return true;
    else return false;
}

bool Sala::operator < (Sala &s)
{
    if(this->nrLocuriOcupate < s.nrLocuriOcupate)
        return true;
    else return false;
}

bool Sala::operator <= (Sala &s)
{
    if(this->nrLocuriOcupate <= s.nrLocuriOcupate)
        return true;
    else return false;
}

bool Sala::operator > (Sala &s)
{
    if(this->nrLocuriOcupate > s.nrLocuriOcupate)
        return true;
    else return false;
}

bool Sala::operator >= (Sala &s)
{
    if(this->nrLocuriOcupate >= s.nrLocuriOcupate)
        return true;
    else return false;
}

istream &operator >> (istream &in, Sala &s)
{
    in.get();
    cout << "Introduceti numarul de locuri al salii: ";
    in >> s.nrLocuriSala;
    cout << "Cate locuri sunt ocupate acum? ";
    in >> s.nrLocuriOcupate;
    if (s.nrLocuriOcupate != 0)
    {
        cout << "Care sunt ID-urile cititorilor din sala? ";
        if (s.idCititori != NULL)
        {
            delete [] s.idCititori;
            s.idCititori = NULL;
        }
        s.idCititori = new int[s.nrLocuriOcupate];
        for (int i=0; i<s.nrLocuriOcupate; i++)
            in >> s.idCititori[i];
    }
    cout << "Care este dimensiunea salii[lungime latime]? ";
    in >> s.dimensiuneSala.lungime >> s.dimensiuneSala.latime;
    return in;
}

ostream &operator << (ostream &out, const Sala &s)
{
    out << "Sala numarul " << s.nrSala << "." << endl;
    out << "Capacitatea salii este de " << s.nrLocuriSala << " locuri, iar dimensiunea ei este de " << s.dimensiuneSala.lungime << "X" << s.dimensiuneSala.latime << " metri." << endl;
    out << "Numarul de locuri libere: " << s.nrLocuriSala - s.nrLocuriOcupate << endl;
    if(s.nrLocuriOcupate != 0)
    {
        out << "Locurile sunt ocupate de cititorii cu ID-ul: ";
        for (int i = 0; i<s.nrLocuriOcupate-1; i++)
            out << s.idCititori[i] << ", ";
        out << s.idCititori[s.nrLocuriOcupate-1] << "." << endl;
    }
    return out;
}


