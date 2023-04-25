#include <iostream>
#include <ctime>
#include "obiectDeImprumutat.h"
using namespace std;

int obiectDeImprumutat::contorObiect = 1000;

time_t dataCurenta = time(0);
tm *dc = localtime(&dataCurenta);

obiectDeImprumutat::obiectDeImprumutat():idObiect(contorObiect++)
{
    status = true;
    stare = nou;
    idUtilizatorCurent = 0;
    dataInregistrare.zi = dc->tm_mday;
    dataInregistrare.luna = 1 + dc->tm_mon;
    dataInregistrare.an = 1900 + dc->tm_year;
}

obiectDeImprumutat::obiectDeImprumutat(bool status, stari stare, int idUtilizatorCurent):idObiect(contorObiect++)
{
    this->status = status;
    this->stare = stare;
    this->idUtilizatorCurent = idUtilizatorCurent;
    this->dataInregistrare.zi = dc->tm_mday;
    this->dataInregistrare.luna = 1 + dc->tm_mon;
    this->dataInregistrare.an = 1900 + dc->tm_year;
}

obiectDeImprumutat::obiectDeImprumutat(const obiectDeImprumutat &ob):idObiect(contorObiect++)
{
    this->status = ob.status;
    this->stare = ob.stare;
    this->idUtilizatorCurent = ob.idUtilizatorCurent;
    this->dataInregistrare.zi = dc->tm_mday;
    this->dataInregistrare.luna = 1 + dc->tm_mon;
    this->dataInregistrare.an = 1900 + dc->tm_year;
}

obiectDeImprumutat& obiectDeImprumutat::operator = (const obiectDeImprumutat &ob)
{
    this->status = ob.status;
    this->stare = ob.stare;
    this->idUtilizatorCurent = ob.idUtilizatorCurent;
    return *this;
}

obiectDeImprumutat& obiectDeImprumutat::operator + (int idUtilizatorCurent)
{
    if(this->status == true)
    {
        this->status = false;
        this->idUtilizatorCurent = idUtilizatorCurent;
    }
    else cout << "Obiectul este deja imprumutat!";
    return *this;
}

obiectDeImprumutat& obiectDeImprumutat::operator -- ()
{
    if(this->status == false)
    {
        this->status = true;
        this->idUtilizatorCurent = 0;
    }
    return *this;
}
