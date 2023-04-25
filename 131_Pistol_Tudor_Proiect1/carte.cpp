#include <iostream>
#include "carte.h"
#include "obiectDeImprumutat.h"
using namespace std;


Carte::Carte():obiectDeImprumutat()
{
    titlu = "Nu este cunoscut";
    autor = new char[strlen("Necunoscut")+1];
    strcpy(autor, "Necunoscut");
    anAparitie = NULL;
}

Carte::Carte(string titlu, char *autor, int anAparitie, bool status, stari stare, int idUtilizatorCurent):obiectDeImprumutat(status, stare, idUtilizatorCurent)
{
    this->titlu = titlu;
    this->autor = new char[strlen(autor)+1];
    strcpy(this->autor, autor);
    this->anAparitie = anAparitie;
}

Carte::Carte(const Carte &ob):obiectDeImprumutat(ob)
{
    this->titlu = ob.titlu;
    this->autor = new char[strlen(ob.autor)+1];
    strcpy(this->autor, ob.autor);
    this->anAparitie = ob.anAparitie;
}

Carte::~Carte()
{
    if(this->autor != NULL)
    {
        delete [] this->autor;
        this->autor = NULL;
    }
}

bool Carte::operator == (const Carte &c)
{
    if (this->idUtilizatorCurent == c.idUtilizatorCurent)
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
        obiectDeImprumutat::operator = (Obj);
        this->titlu = Obj.titlu;
        this->autor = new char [strlen(Obj.autor)+1];
        strcpy(this->autor, Obj.autor);
        this->anAparitie = Obj.anAparitie;
    }
    return *this;
}

ostream &operator << (ostream &out, const Carte &c)
{
    out << "Codul numeric al cărții: " << c.idObiect << endl;
    out << "Titlul cărții: " << c.titlu << endl;
    out<< "Autorul: " << c.autor << endl;
    out << "Anul publicării: " << c.anAparitie << endl;
    out << "Starea cărții: ";
    if (c.stare == nou) cout << "nouă" << endl;
    else if (c.stare == folosit) cout << "folosită" << endl;
    else cout << "uzată" << endl;;
    if (c.status == 0) out << "Împrumutată de cititorul cu ID-ul ";
    else out << "Disponibilă" << endl;
    if (c.status == 0) out << c.idUtilizatorCurent << "." <<endl;
    cout << "Înregistrată la data de: " << c.dataInregistrare.zi << "." << c.dataInregistrare.luna << "." << c.dataInregistrare.an << endl;
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
    cout << "În ce stare se află cartea?[nou/folosit/uzat]";
    string aux;
    in >> aux;
    if (aux == "nou") ca.stare = nou;
    else if (aux == "folosit") ca.stare = folosit;
    else if (aux == "uzat") ca.stare = uzat;
    cout << "Este disponibilă pentru împrumut?[0/1] ";
    in >> ca.status;
    if (ca.status == 0)
    {
        cout << "Introduceti ID-ul cititorului care a imprumutat-o: ";
        in >> ca.idUtilizatorCurent;
        
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

istream& Carte::inregistrare(istream& in)
{
    in.get();
    cout << "Care este titlul cărții? ";
    //aloc spatiu random
    char aux1[100];
    //citesc sirul de caractere cu functia .getline() ca sa ia in considerare si spatiile
    in.getline(aux1, 100);
    this->titlu = aux1;
    cout << "Cine este autorul? ";
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
    cout << "În ce stare se află cartea?[nou/folosit/uzat]";
    string aux;
    in >> aux;
    if (aux == "nou") this->stare = nou;
    else if (aux == "folosit") this->stare = folosit;
    else if (aux == "uzat") this->stare = uzat;
    cout << "Este disponibilă pentru împrumut?[0/1] ";
    in >> this->status;
    if (this->status == 0)
    {
        cout << "Introduceti ID-ul cititorului care a imprumutat-o: ";
        in >> this->idUtilizatorCurent;
        
    }
    in.get(); //fac posibila urmatoarea citire pentru urmatorul obiect(citind enter-ul), in cazul unui vector de obiecte, altfel va considera tasta enter ca titlu pentru urmatoarea carte
    return in;
}

ostream& Carte::afisare(ostream& out) const
{
    out << "Codul numeric al cărții: " << this->idObiect << endl;
    out << "Titlul cărții: " << this->titlu << endl;
    out<< "Autorul: " << this->autor << endl;
    out << "Anul publicării: " << this->anAparitie << endl;
    if (this->status == 0) out << "Împrumutată de cititorul cu ID-ul ";
    else out << "Disponibilă" << endl;
    if (this->status == 0) out << this->idUtilizatorCurent << "." <<endl;
    cout << "Înregistrată la data de: " << this->dataInregistrare.zi << "." << this->dataInregistrare.luna << "." << this->dataInregistrare.an << endl;
    return out;
}
