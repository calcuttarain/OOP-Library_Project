#include <iostream>
#include "carte.h"
using namespace std;


int Carte::contorIdCarte = 1000;

Carte::Carte():idCarte(contorIdCarte++)
{
    titlu = "Nu este cunoscut";
    autor = new char[strlen("Necunoscut")+1];
    strcpy(autor, "Necunoscut");
    anAparitie = NULL;
    status = false;
    idCititor = -1;
}

Carte::Carte(string titlu, char *autor, int anAparitie, bool status, int idCititor):idCarte(contorIdCarte++)
{
    this->titlu = titlu;
    this->autor = new char[strlen(autor)+1];
    strcpy(this->autor, autor);
    this->anAparitie = anAparitie;
    this->status = status;
    this->idCititor = idCititor;
}

Carte::Carte(string titlu, char *autor):idCarte(contorIdCarte++)
{
    this->titlu = titlu;
    this->autor = new char[strlen(autor)+1];
    strcpy(this->autor, autor);
    anAparitie = NULL;
    status = false;
    idCititor = -1;
}

Carte::Carte(string titlu, char *autor, int anAparitie):idCarte(contorIdCarte++)
{
    this->titlu = titlu;
    this->autor = new char[strlen(autor)+1];
    strcpy(this->autor, autor);
    this->anAparitie = anAparitie;
    status = false;
    idCititor = -1;
}

Carte::Carte(const Carte &Obj):idCarte(contorIdCarte++)
{
    this->titlu = Obj.titlu;
    this->autor = new char[strlen(Obj.autor)+1];
    strcpy(this->autor, Obj.autor);
    this->anAparitie = Obj.anAparitie;
    this->status = Obj.status;
    this->idCititor = Obj.idCititor;
}

Carte::~Carte()
{
    if(this->autor != NULL)
    {
        delete [] this->autor;
        this->autor = NULL;
    }
}

Carte& Carte::operator + (int idCititor)
{
    if(this->status == 0)
        throw runtime_error("Cartea este deja imprumutata.");
    else
    {
        this->status = false;
        this->idCititor = idCititor;
        return *this;
    }
}

Carte operator + (int idCititor, Carte &c)
{
    if(c.status == 0)
        throw runtime_error("Cartea este deja imprumutata.");
    else
    {
        c.status = false;
        c.idCititor = idCititor;
        return c;
    }
}

Carte& Carte::operator - (int a)
{
    this->anAparitie -= a;
    return *this;
}

Carte& Carte::operator -- ()
{
    if(this->status == 1)
        throw runtime_error("Cartea nu a fost imprumutata inca niciunui utilizator.");
    else
    {
        this->status = true;
        this->idCititor = -1;
        return *this;
    }
}

Carte Carte::operator -- (int)
{
    Carte aux(*this);
    if (this->status == 1)
        throw runtime_error("Cartea nu a fost imprumutata inca niciunui utilizator.");
    else
    {
        this->status = true;
        this->idCititor = -1;
        return aux;
    }
}

bool Carte::operator == (const Carte &c)
{
    if (this->anAparitie == c.anAparitie)
        return true;
    else return false;
}

bool Carte::operator < (const Carte &c)
{
    if (this->anAparitie < c.anAparitie)
        return true;
    else return false;
}

bool Carte::operator <= (const Carte &c)
{
    if (this->anAparitie <= c.anAparitie)
        return true;
    else return false;
}

bool Carte::operator > (const Carte &c)
{
    if (this->anAparitie > c.anAparitie)
        return true;
    else return false;
}

bool Carte::operator >= (const Carte &c)
{
    if (this->anAparitie >= c.anAparitie)
        return true;
    else return false;
}

Carte &Carte::operator = (const Carte &Obj)
{
    if(this != &Obj)
    {
        if(this->autor != NULL)
        {
            delete [] this->autor;
            this->autor = NULL;
        }
        this->titlu = Obj.titlu;
        this->autor = new char [strlen(Obj.autor)+1];
        strcpy(this->autor, Obj.autor);
        this->anAparitie = Obj.anAparitie;
        this->status = Obj.status;
        this->idCititor = Obj.idCititor;
    }
    return *this;
}

ostream &operator << (ostream &out, const Carte &c)
{
    out << "Codul numeric al cărții: " << c.idCarte << endl;
    out << "Titlul cărții: " << c.titlu << endl;
    out<< "Autorul: " << c.autor << endl;
    out << "Anul publicării: " << c.anAparitie << endl;
    if (c.status == 0) out << "Împrumutată de cititorul cu ID-ul ";
    else out << "Disponibilă" << endl;
    if (c.status == 0) out << c.idCititor << "." <<endl;
    return out;
}

istream &operator >> (istream &in, Carte &ca)
{
    in.get();
    cout << "Care este titlul cărții? ";
    //aloc spatiu random
    char aux1[100];
    //citesc sirul de caractere cu functia .getline() ca sa ia in considerare si spatiile
    in.getline(aux1, 100);
    ca.titlu = aux1;
    cout << "Cine este autorul? ";
    char aux2[100];
    in.getline(aux2, 100); //acelasi lucru ca la string
    if(ca.autor != NULL)
    {
        delete [] ca.autor;
        ca.autor = NULL;
    }
    ca.autor = new char [strlen(aux2)+1];
    strcpy(ca.autor, aux2);
    cout << "În ce an a fost publicată? ";
    in >> ca.anAparitie;
    cout << "Este disponibilă pentru împrumut?[0/1] ";
    in >> ca.status;
    if (ca.status == 0)
    {
        cout << "Introduceti ID-ul cititorului care a imprumutat-o: ";
        in >> ca.idCititor;
        
    }
    in.get(); //fac posibila urmatoarea citire pentru urmatorul obiect(citind enter-ul), in cazul unui vector de obiecte, altfel va considera tasta enter ca titlu pentru urmatoarea carte
    return in;
}

void Carte::setAutor(char *autor)
{
    if(this->autor != NULL)
    {
        delete [] this->autor;
        this->autor = NULL;
    }
    this->autor = new char[strlen(autor)+1];
    strcpy(this->autor, autor);
}

