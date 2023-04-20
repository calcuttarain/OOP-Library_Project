//
//  utilizator.cpp
//  131_Pistol_Tudor_Proiect1
//
//  Created by Tudor Pistol on 20.04.2023.
//

#include <iostream>
#include "utilizator.h"
using namespace std;

int Utilizator::contorIdUtilizator = 10000;
Utilizator::Utilizator():idUtilizator(contorIdUtilizator++)
{
    strcpy(numeUtilizator, "Necunoscut");
    strcpy(prenumeUtilizator, "Necunoscut");
    strcpy(sexUtilizator, "X");
    data_nasterii.zi = 0;
    data_nasterii.luna = "0";
    data_nasterii.an = 0;
    numarTelefonic = new char [strlen("Necunoscut")+1];
    strcpy(numarTelefonic, "Necunoscut");
    nrCartiImprumutate = 0;
    idCartiImprumutate = NULL;
    aniAbonare = 0;
}

Utilizator::Utilizator(char numeUtilizator[20], char prenumeUtilizator[20], char sexUtilizator[2], dataNasterii data_nasterii, char *numarTelefonic, int nrCartiImprumutate, int *idCartiImprumutate, int aniAbonare):idUtilizator(contorIdUtilizator++)
{
    strcpy(this->numeUtilizator, numeUtilizator);
    strcpy(this->prenumeUtilizator, prenumeUtilizator);
    strcpy(this->sexUtilizator, sexUtilizator);
    this->data_nasterii.zi = data_nasterii.zi;
    this->data_nasterii.luna = data_nasterii.luna;
    this->data_nasterii.an = data_nasterii.an;
    this->numarTelefonic = new char [strlen(numarTelefonic)+1];
    strcpy(this->numarTelefonic, numarTelefonic);
    this->nrCartiImprumutate = nrCartiImprumutate;
    this->idCartiImprumutate = new int[nrCartiImprumutate];
    for (int i = 0; i<nrCartiImprumutate; i++)
        this->idCartiImprumutate[i] = idCartiImprumutate[i];
    this->aniAbonare = aniAbonare;
}

Utilizator::Utilizator(char numeUtilizator[20], char prenumeUtilizator[20]):idUtilizator(contorIdUtilizator++)
{
    strcpy(this->numeUtilizator, numeUtilizator);
    strcpy(this->prenumeUtilizator, prenumeUtilizator);
    strcpy(sexUtilizator, "X");
    data_nasterii.zi = 0;
    data_nasterii.luna = "0";
    data_nasterii.an = 0;
    numarTelefonic = new char [strlen("Necunoscut")+1];
    strcpy(numarTelefonic, "Necunoscut");
    nrCartiImprumutate = 0;
    idCartiImprumutate = NULL;
    aniAbonare = 0;
}

Utilizator::Utilizator(char numeUtilizator[20], char prenumeUtilizator[20], char sexUtilizator[2], dataNasterii data_nasterii, char *numarTelefonic):idUtilizator(contorIdUtilizator++)
{
    strcpy(this->numeUtilizator, numeUtilizator);
    strcpy(this->prenumeUtilizator, prenumeUtilizator);
    strcpy(this->sexUtilizator, sexUtilizator);
    this->data_nasterii.zi = data_nasterii.zi;
    this->data_nasterii.luna = data_nasterii.luna;
    this->data_nasterii.an = data_nasterii.an;
    this->numarTelefonic = new char [strlen(numarTelefonic)+1];
    strcpy(this->numarTelefonic, numarTelefonic);
    nrCartiImprumutate = 0;
    idCartiImprumutate = NULL;
    aniAbonare = 0;
}

Utilizator::Utilizator(const Utilizator &obj):idUtilizator(contorIdUtilizator++)
{
    strcpy(this->numeUtilizator, obj.numeUtilizator);
    strcpy(this->prenumeUtilizator, obj.prenumeUtilizator);
    strcpy(this->sexUtilizator, obj.sexUtilizator);
    this->data_nasterii.zi = obj.data_nasterii.zi;
    this->data_nasterii.luna = obj.data_nasterii.luna;
    this->data_nasterii.an = obj.data_nasterii.an;
    this->numarTelefonic = new char [strlen(obj.numarTelefonic)+1];
    strcpy(this->numarTelefonic, obj.numarTelefonic);
    this->nrCartiImprumutate = obj.nrCartiImprumutate;
    this->idCartiImprumutate = new int[obj.nrCartiImprumutate];
    for (int i = 0; i<obj.nrCartiImprumutate; i++)
        this->idCartiImprumutate[i] = obj.idCartiImprumutate[i];
    this->aniAbonare = obj.aniAbonare;
}

Utilizator::~Utilizator()
{
    if(this->numarTelefonic != NULL)
    {
        delete [] this->numarTelefonic;
        this->numarTelefonic = NULL;
    }
    if(this->idCartiImprumutate != NULL)
    {
        delete [] this->idCartiImprumutate;
        this->idCartiImprumutate = NULL;
    }
}

Utilizator &Utilizator::operator = (const Utilizator &obj)
{
    if(this->numarTelefonic != NULL)
    {
        delete [] this->numarTelefonic;
        this->numarTelefonic = NULL;
    }
    if(this->idCartiImprumutate != NULL)
    {
        delete [] this->idCartiImprumutate;
        this->idCartiImprumutate = NULL;
    }
    strcpy(this->numeUtilizator, obj.numeUtilizator);
    strcpy(this->prenumeUtilizator, obj.prenumeUtilizator);
    strcpy(this->sexUtilizator, obj.sexUtilizator);
    this->data_nasterii.zi = obj.data_nasterii.zi;
    this->data_nasterii.luna = obj.data_nasterii.luna;
    this->data_nasterii.an = obj.data_nasterii.an;
    this->numarTelefonic = new char [strlen(obj.numarTelefonic)+1];
    strcpy(this->numarTelefonic, obj.numarTelefonic);
    this->nrCartiImprumutate = obj.nrCartiImprumutate;
    this->idCartiImprumutate = new int[obj.nrCartiImprumutate];
    for (int i = 0; i<obj.nrCartiImprumutate; i++)
        this->idCartiImprumutate[i] = obj.idCartiImprumutate[i];
    this->aniAbonare = obj.aniAbonare;
    return *this;
}

istream &operator >> (istream &in, Utilizator &u)
{
    in.get();
    cout  << "Nume utilizator: ";
    in.getline(u.numeUtilizator, 20);
    cout  << "Prenume utilizator: ";
    in.getline(u.prenumeUtilizator, 20);
    cout  << "Sex utilizator: ";
    in >> u.sexUtilizator;
    cout  << "Data de naștere [zi luna an]: ";
    in >> u.data_nasterii.zi >> u.data_nasterii.luna >> u.data_nasterii.an;
    delete [] u.numarTelefonic;
    char aux3[20];
    cout << "Numărul de telefon: ";
    in >> aux3;
    u.numarTelefonic = new char[strlen(aux3)+1];
    strcpy(u.numarTelefonic, aux3);
    cout << "Numărul de cărți împrumutate: ";
    in >> u.nrCartiImprumutate;
    delete [] u.idCartiImprumutate;
    u.idCartiImprumutate = new int[u.nrCartiImprumutate];
    if(u.nrCartiImprumutate != 0)
    {
        cout << "Introduceți, pe rând, ID-ul fiecărei cărți împrumutate: ";
        for (int i = 0; i < u.nrCartiImprumutate; i++)
            in >> u.idCartiImprumutate[i];
    }
    cout << "Cati ani are de cand utilizatorul este abonat la biblioteca? ";
    in >> u.aniAbonare;
    in.get();
    return in;
}

ostream &operator << (ostream &out, const Utilizator &u)
{
    out << "ID-ul utilizatorului: " << u.idUtilizator << endl;
    out << "Nume utilizator: " << u.numeUtilizator<<endl;
    out << "Prenume utilizator: " << u.prenumeUtilizator<<endl;
    out << "Sex utilizator: "<<u.sexUtilizator<<endl;
    out << "Data de naștere: " << u.data_nasterii.zi << " " << u.data_nasterii.luna << " " << u.data_nasterii.an << endl;
    out << "Numărul de telefon: " << u.numarTelefonic << endl;
    out << "Numărul de cărți împrumutate: " <<u.nrCartiImprumutate << endl;
    for(int i = 0; i<u.nrCartiImprumutate; i++)
    {
        out << "* Cartea numarul " << i+1 << ":" << u.idCartiImprumutate[i] << endl;
    }
    cout << u.numeUtilizator << " " << u.prenumeUtilizator << " este inregistrat la aceasta biblioteca de " << u.aniAbonare << " ani.";
    return out;
}

void Utilizator::setDataNasterii(dataNasterii data_nasterii)
{
    this->data_nasterii.zi = data_nasterii.zi;
    this->data_nasterii.luna = data_nasterii.luna;
    this->data_nasterii.an = data_nasterii.an;
}

void Utilizator::setNumarTelelefonic(char *numarTelefonic)
{
    if(this->numarTelefonic != NULL)
    {
        delete [] this->numarTelefonic;
        this->numarTelefonic = NULL;
    }
    this->numarTelefonic = new char[strlen(numarTelefonic)+1];
    strcpy(this->numarTelefonic, numarTelefonic);
}

void Utilizator::setIdCartiImprumutate(int *idCartiImprumutate)
{
    if(this->idCartiImprumutate != NULL)
    {
        delete [] this->idCartiImprumutate;
        this->idCartiImprumutate = NULL;
    }
    this->idCartiImprumutate = new int[nrCartiImprumutate];
    for (int i = 0; i<nrCartiImprumutate; i++)
        this->idCartiImprumutate[i] = idCartiImprumutate[i];
}

Utilizator &Utilizator::operator -(int idCarte)
{
    if(this->idCartiImprumutate == NULL)
     throw runtime_error("Utilizatorul nu are carti imprumutate.");
    else
    {
        for (int i = 0; i<this->nrCartiImprumutate; i++)
        {
            if(this->idCartiImprumutate[i] == idCarte)
            {
                swap(this->idCartiImprumutate[i], this->idCartiImprumutate[this->nrCartiImprumutate-1]);
                break;
            }
        }
        this->nrCartiImprumutate--;
        int *aux;
        aux = new int[this->nrCartiImprumutate];
        for(int i = 0; i<this->nrCartiImprumutate; i++)
            aux[i] = this->idCartiImprumutate[i];
        delete [] this->idCartiImprumutate;
        this->idCartiImprumutate = new int[this->nrCartiImprumutate];
        for(int i = 0; i<this->nrCartiImprumutate; i++)
            this->idCartiImprumutate[i] = aux[i];
        delete [] aux;
        aux = NULL;
        return *this;
    }
}

Utilizator& Utilizator::operator ++()
{
    this->aniAbonare++;
    return *this;
}

Utilizator Utilizator::operator ++(int)
{
    Utilizator aux(*this);
    this->aniAbonare++;
    return aux;
}

Utilizator &Utilizator::operator +(int idCarte)
{
    this->nrCartiImprumutate++;
    int *aux;
    aux = new int[this->nrCartiImprumutate];
    for(int i = 0; i<this->nrCartiImprumutate-1; i++)
        aux[i] = this->idCartiImprumutate[i];
    aux[this->nrCartiImprumutate-1] = idCarte;
    delete [] this->idCartiImprumutate;
    this->idCartiImprumutate = new int[this->nrCartiImprumutate];
    for(int i = 0; i<this->nrCartiImprumutate; i++)
        this->idCartiImprumutate[i] = aux[i];
    delete [] aux;
    aux = NULL;
    return *this;
}

Utilizator operator +(int a, Utilizator &u)
{
    u.nrCartiImprumutate++;
    int *aux;
    aux = new int[u.nrCartiImprumutate];
    for (int i = 0; i<u.nrCartiImprumutate-1; i++)
        aux[i] = u.idCartiImprumutate[i];
    delete [] u.idCartiImprumutate;
    u.idCartiImprumutate = new int[u.nrCartiImprumutate];
    aux[u.nrCartiImprumutate-1] = a;
    for (int i = 0; i<u.nrCartiImprumutate; i++)
        u.idCartiImprumutate[i] = aux[i];
    delete[] aux;
    aux = NULL;
    return u;
}

int Utilizator::operator [](int a)
{
    if(this->nrCartiImprumutate == 0)
        throw runtime_error("Utilizatorul nu are carti imprumutate.");
    else if(a<0 || a>this->nrCartiImprumutate)
        throw runtime_error("Index invalid!");
    else
        return this->idCartiImprumutate[a];
}

Utilizator::operator int()
{
    return this->idUtilizator;
}

bool Utilizator::operator == (const Utilizator &u)
{
    return this->nrCartiImprumutate == u.nrCartiImprumutate;
}

bool Utilizator::operator > (const Utilizator &u)
{
    if (this->nrCartiImprumutate > u.nrCartiImprumutate)
        return true;
    else return false;
}

bool Utilizator::operator >= (const Utilizator &u)
{
    if (this->nrCartiImprumutate >= u.nrCartiImprumutate)
        return true;
    else return false;
}

bool Utilizator::operator < (const Utilizator &u)
{
    if (this->nrCartiImprumutate < u.nrCartiImprumutate)
        return true;
    else return false;
}

bool Utilizator::operator <= (const Utilizator &u)
{
    if (this->nrCartiImprumutate <= u.nrCartiImprumutate)
        return true;
    else return false;
}
