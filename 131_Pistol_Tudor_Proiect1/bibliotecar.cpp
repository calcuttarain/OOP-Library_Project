//
//  bibliotecar.cpp
//  131_Pistol_Tudor_Proiect1
//
//  Created by Tudor Pistol on 20.04.2023.
//

#include <iostream>
#include "bibliotecar.h"
using namespace std;

int Bibliotecar::contorIdBibliotecar = 100;

Bibliotecar::Bibliotecar():idBibliotecar(contorIdBibliotecar++)
{
    this->numeBibliotecar = new char[strlen("Necunoscut")+1];
    strcpy(this->numeBibliotecar, "Necunoscut");
    this->prenumeBibliotecar = new char[strlen("Necunoscut")+1];
    strcpy(this->prenumeBibliotecar, "Necunoscut");
    this->varstaBibliotecar = 0;
    this->venitLunar = 0;
    this->data_angajarii.zi = 0;
    this->data_angajarii.luna = 0;
    this->data_angajarii.an = 0;
    this->nrZileLucruSaptamanal = 0;
    strcpy(this->programSaptamanal[0], "Nu are program.");
}

Bibliotecar::Bibliotecar(char *numeBibliotecar, char *prenumeBibliotecar, int varstaBibliotecar, float venitLunar, dataAngajarii data_angajarii, int nrZileLucruSaptamanal, char programSaptamanal[7][50]):idBibliotecar(contorIdBibliotecar++)
{
    this->numeBibliotecar = new char[strlen(numeBibliotecar)+1];
    strcpy(this->numeBibliotecar, numeBibliotecar);
    this->prenumeBibliotecar = new char[strlen(prenumeBibliotecar)+1];
    strcpy(this->prenumeBibliotecar, prenumeBibliotecar);
    this->varstaBibliotecar = varstaBibliotecar;
    this->venitLunar = venitLunar;
    this->data_angajarii.zi = data_angajarii.zi;
    this->data_angajarii.luna = data_angajarii.luna;
    this->data_angajarii.an = data_angajarii.an;
    this->nrZileLucruSaptamanal = nrZileLucruSaptamanal;
    for (int i = 0; i<this->nrZileLucruSaptamanal; i++)
        strcpy(this->programSaptamanal[i], programSaptamanal[i]);
}

Bibliotecar::Bibliotecar(char *numeBibliotecar, char *prenumeBibliotecar):idBibliotecar(contorIdBibliotecar++)
{
    this->numeBibliotecar = new char[strlen(numeBibliotecar)+1];
    strcpy(this->numeBibliotecar, numeBibliotecar);
    this->prenumeBibliotecar = new char[strlen(prenumeBibliotecar)+1];
    strcpy(this->prenumeBibliotecar, prenumeBibliotecar);
    this->varstaBibliotecar = 0;
    this->venitLunar = 0;
    this->data_angajarii.zi = 0;
    this->data_angajarii.luna = 0;
    this->data_angajarii.an = 0;
    this->nrZileLucruSaptamanal = 0;
    strcpy(this->programSaptamanal[0], "Necunoscut");
}

Bibliotecar::Bibliotecar(char *numeBibliotecar, char *prenumeBibliotecar, dataAngajarii data_angajarii):idBibliotecar(contorIdBibliotecar++)
{
    this->numeBibliotecar = new char[strlen(numeBibliotecar)+1];
    strcpy(this->numeBibliotecar, numeBibliotecar);
    this->prenumeBibliotecar = new char[strlen(prenumeBibliotecar)+1];
    strcpy(this->prenumeBibliotecar, prenumeBibliotecar);
    this->varstaBibliotecar = 0;
    this->venitLunar = 0;
    this->data_angajarii.zi = data_angajarii.zi;
    this->data_angajarii.luna = data_angajarii.luna;
    this->data_angajarii.an = data_angajarii.an;
    this->nrZileLucruSaptamanal = 0;
    strcpy(this->programSaptamanal[0], "Necunoscut");
}

Bibliotecar::Bibliotecar(const Bibliotecar &obj):idBibliotecar(contorIdBibliotecar++)
{
    this->numeBibliotecar = new char[strlen(obj.numeBibliotecar)+1];
    strcpy(this->numeBibliotecar, obj.numeBibliotecar);
    this->prenumeBibliotecar = new char[strlen(obj.prenumeBibliotecar)+1];
    strcpy(this->prenumeBibliotecar, obj.prenumeBibliotecar);
    this->varstaBibliotecar = obj.varstaBibliotecar;
    this->venitLunar = obj.venitLunar;
    this->data_angajarii.zi = obj.data_angajarii.zi;
    this->data_angajarii.luna = obj.data_angajarii.luna;
    this->data_angajarii.an = obj.data_angajarii.an;
    this->nrZileLucruSaptamanal = obj.nrZileLucruSaptamanal;
    for (int i = 0; i<this->nrZileLucruSaptamanal; i++)
        strcpy(this->programSaptamanal[i], obj.programSaptamanal[i]);
}

Bibliotecar::~Bibliotecar()
{
    if(this->numeBibliotecar != NULL)
    {
        delete [] this->numeBibliotecar;
        this->numeBibliotecar = NULL;
    }
    if(this->prenumeBibliotecar != NULL)
    {
        delete [] this->prenumeBibliotecar;
        this->prenumeBibliotecar = NULL;
    }
}

char const * Bibliotecar::operator [] (int a)
{
    if(a<0 || a>nrZileLucruSaptamanal)
        throw runtime_error("Index invalid.");
    else return this->programSaptamanal[a];
}

Bibliotecar& Bibliotecar::operator ++ ()
{
    this->varstaBibliotecar++;
    return *this;
}

Bibliotecar Bibliotecar::operator ++ (int a)
{
    Bibliotecar aux(*this);
    this->varstaBibliotecar++;
    return aux;
}

Bibliotecar& Bibliotecar::operator + (double venit)
{
    this->venitLunar += venit;
    return *this;
}

Bibliotecar operator + (double venit, Bibliotecar &b)
{
    b.venitLunar += venit;
    return b;
}

Bibliotecar& Bibliotecar::operator - (double venit)
{
    this->venitLunar -= venit;
    return *this;
}

bool Bibliotecar::operator == (const Bibliotecar &b)
{
    if(this->venitLunar == b.venitLunar)
        return true;
    else return false;
}

bool Bibliotecar::operator < (const Bibliotecar &b)
{
    if(this->venitLunar < b.venitLunar)
        return true;
    else return false;
}

bool Bibliotecar::operator <= (const Bibliotecar &b)
{
    if(this->venitLunar <= b.venitLunar)
        return true;
    else return false;
}

bool Bibliotecar::operator > (const Bibliotecar &b)
{
    if(this->venitLunar == b.venitLunar)
        return true;
    else return false;
}

bool Bibliotecar::operator >= (const Bibliotecar &b)
{
    if(this->venitLunar == b.venitLunar)
        return true;
    else return false;
}

Bibliotecar &Bibliotecar::operator =(const Bibliotecar &obj)
{
    this->numeBibliotecar = new char[strlen(obj.numeBibliotecar)+1];
    strcpy(this->numeBibliotecar, obj.numeBibliotecar);
    this->prenumeBibliotecar = new char[strlen(obj.prenumeBibliotecar)+1];
    strcpy(this->prenumeBibliotecar, obj.prenumeBibliotecar);
    this->varstaBibliotecar = obj.varstaBibliotecar;
    this->venitLunar = obj.venitLunar;
    this->data_angajarii.zi = obj.data_angajarii.zi;
    this->data_angajarii.luna = obj.data_angajarii.luna;
    this->data_angajarii.an = obj.data_angajarii.an;
    this->nrZileLucruSaptamanal = obj.nrZileLucruSaptamanal;
    for (int i = 0; i<this->nrZileLucruSaptamanal; i++)
        strcpy(this->programSaptamanal[i], obj.programSaptamanal[i]);
    return *this;
}

istream &operator >> (istream &in, Bibliotecar &b)
{
    in.get();
    cout << "Introduceti numele bibliotecarului: ";
    char auxb1[20];
    in.getline(auxb1, 20);
    delete [] b.numeBibliotecar;
    b.numeBibliotecar = new char[strlen(auxb1)+1];
    strcpy(b.numeBibliotecar, auxb1);
    cout << "Introduceti prenumele bibliotecarului: ";
    char auxb2[20];
    in.getline(auxb2, 20);
    delete [] b.prenumeBibliotecar;
    b.prenumeBibliotecar = new char[strlen(auxb2)+1];
    strcpy(b.prenumeBibliotecar, auxb2);
    cout << "Introduceti varsta bibliotecarului: ";
    in >> b.varstaBibliotecar;
    cout << "Introduceti venitul lunar: ";
    in >> b.venitLunar;
    cout << "Introduceti data angajarii[zi luna an]: ";
    in >> b.data_angajarii.zi >> b.data_angajarii.luna >> b.data_angajarii.an;
    cout << "Introduceti numarul de zile lucratoare pe saptamana: ";
    in >> b.nrZileLucruSaptamanal;
    cout << "Introduceti, pe rand, ziua din saptamana alaturi de programul orar averent[zi->hh:mm-hh:mm]: ";
    for (int i = 0; i<b.nrZileLucruSaptamanal; i++)
        in >> b.programSaptamanal[i];
    in.get();
    return in;
    
}

ostream &operator << (ostream &out, const Bibliotecar &b)
{
    out << "ID-ul Bibliotecarului: " << b.idBibliotecar << endl;
    out << "Numele bibliotecarului: " << b.numeBibliotecar << endl;
    out << "Prenumele bibliotecarului: " << b.prenumeBibliotecar << endl;
    out << "Varsta: " << b.varstaBibliotecar << " ani" << endl;
    out << "Venitul lunar: " << b.venitLunar << " RON" << endl;
    out << "Data angajarii: " << b.data_angajarii.zi << "." << b.data_angajarii.luna << "." << b.data_angajarii.an << endl;
    out << b.prenumeBibliotecar << " " << b.numeBibliotecar << " lucreaza " << b.nrZileLucruSaptamanal << " zile pe saptamana, iar programul  saptamanal este urmatorul: " << endl;
    for (int i = 0; i<b.nrZileLucruSaptamanal; i++)
        out << "\t" << b.programSaptamanal[i] << endl;
    return out;
}
