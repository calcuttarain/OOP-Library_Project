#include <iostream>
#include "revistaCuFilm.h"
using namespace std;

revistaCuFilm::revistaCuFilm():Carte(),Film()
{
    numarRevista = -1;
    numeRevista = " ";
}

revistaCuFilm::revistaCuFilm(int numarRevista, string numeRevista, string titlu, char *autor, int anAparitie, string nume, string regizor, vector <string> actori, int an, bool status, stari stare, int idUtilizatorCurent) : obiectDeImprumutat(status, stare, idUtilizatorCurent), Carte(titlu, autor, anAparitie, status, stare, idUtilizatorCurent), Film(nume, regizor, actori, an, status, stare, idUtilizatorCurent)
{
    this->numarRevista = numarRevista;
    this->numeRevista = numeRevista;
}

revistaCuFilm::revistaCuFilm(revistaCuFilm &r):obiectDeImprumutat(r), Carte(r), Film(r)
{
    numarRevista = r.numarRevista;
    numeRevista = r.numeRevista;
}

istream& revistaCuFilm:: inregistrare (istream &in)
{
    cout << "Introduceți datele revistei" << endl << "Numele revistei: ";
    getline(in, numeRevista);
    cout << "Numărul revistei: ";
    in >> numarRevista;
    in.get();
    cout << "Care este titlul acestui număr? ";
    //aloc spatiu random
    char aux1[100];
    //citesc sirul de caractere cu functia .getline() ca sa ia in considerare si spatiile
    in.getline(aux1, 100);
    this->titlu = aux1;
    cout << "Cine este redactorul? ";
    char aux2[100];
    in.getline(aux2, 100); //acelasi lucru ca la string
    if(this->autor != NULL)
    {
        delete [] this->autor;
        this->autor = NULL;
    }
    this->autor = new char [strlen(aux2)+1];
    strcpy(this->autor, aux2);
    cout << "În ce an a fost publicată? ";
    in >> this->anAparitie;
    cout << endl;
    cout << "Introduceți datele filmului" << endl;
    in.get();
    Film::inregistrare(in);
    return in;
}

ostream& revistaCuFilm::afisare(ostream &out) const
{
    out << "Codul numeric al revistei cu film: " << this->idObiect << endl;
    out << "Datele revistei: " << endl << "Nume revista: " << numeRevista << endl;
    out << "Numărul revistei: " << numarRevista << endl;
    out << "Titlul numărului: " << this->titlu << endl;
    out << "Redactorul: " << this->autor << endl;
    out << "Anul publicării: " << this->anAparitie << endl << endl;
    out << "Datele filmului: " << endl;
    Film::afisare(out);
    return out;
}
