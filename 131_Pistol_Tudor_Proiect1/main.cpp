#include <iostream>
#include <string.h>

using namespace std;

class Carte{
private:
    const int idCarte;
    static int contorIdCarte;
    string titlu;
    char *autor;
    int anAparitie;
    bool status;
public:
//constructors:
    Carte(); //constructorul fara parametri
    Carte(string titlu, char *autor, int anAparitie, bool status); //constructorul cu toti parametrii
    Carte(string titlu, char *autor);
    Carte(string titlu, char *autor, int anAparitie);
    Carte(const Carte &Obj); //copy-constructor
    ~Carte(); //destructor
//operatori
    Carte &operator = (const Carte &Obj); //forma incarcata a operatorului de atribuire
    friend istream &operator >> (istream &in, Carte &c); //supraincarcarea operatorului de citire
    friend ostream &operator << (ostream &out, const Carte &ca); //supraincarcarea operatorului de afisare
//setters
    void setTitlu(string titlu) {this->titlu = titlu;}
    void setAutor(char *autor);
    void setAnAparitie(int anAparitie) {this->anAparitie = anAparitie;}
    void setStatus(bool status) {this->status = status;}
//getters
    const int getIdCarte() {return idCarte;}
    static int getContorIdCarte() {return contorIdCarte;}
    string getTitlu() {return this->titlu;}
    char *getAutor() {return this->autor;}
    int getAnAparitie() {return this->anAparitie;}
    bool getStatus() {return this->status;}
};

//corpul functiilor clasei Carte
int Carte::contorIdCarte = 1000;

Carte::Carte():idCarte(contorIdCarte++)
{
    titlu = "Nu este cunoscut";
    autor = new char[strlen("Necunoscut")+1];
    strcpy(autor, "Necunoscut");
    anAparitie = NULL;
    status = false;
}

Carte::Carte(string titlu, char *autor, int anAparitie, bool status):idCarte(contorIdCarte++)
{
    this->titlu = titlu;
    this->autor = new char[strlen(autor)+1];
    strcpy(this->autor, autor);
    this->anAparitie = anAparitie;
    this->status = status;
}

Carte::Carte(string titlu, char *autor):idCarte(contorIdCarte++)
{
    this->titlu = titlu;
    this->autor = new char[strlen(autor)+1];
    strcpy(this->autor, autor);
    anAparitie = NULL;
    status = false;
}

Carte::Carte(string titlu, char *autor, int anAparitie):idCarte(contorIdCarte++)
{
    this->titlu = titlu;
    this->autor = new char[strlen(autor)+1];
    strcpy(this->autor, autor);
    this->anAparitie = anAparitie;
    status = false;
}

Carte::Carte(const Carte &Obj):idCarte(contorIdCarte++)
{
    this->titlu = Obj.titlu;
    this->autor = new char[strlen(Obj.autor)+1];
    strcpy(this->autor, Obj.autor);
    this->anAparitie = Obj.anAparitie;
    this->status = Obj.status;
}

Carte::~Carte()
{
    if(this->autor != NULL)
    {
        delete [] this->autor;
        this->autor = NULL;
    }
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
    }
    return *this;
}

ostream &operator << (ostream &out, const Carte &c)
{
    out << "Codul numeric al cărții: " << c.idCarte << endl;
    out << "Titlul cărții: " << c.titlu << endl;
    out<< "Autorul: " << c.autor << endl;
    out << "Anul publicării: " << c.anAparitie << endl;
    if (c.status == 0) out << "Împrumutată" << endl;
    else out << "Disponibilă" << endl;
    return out;
}

istream &operator >> (istream &in, Carte &ca)
{
    cout << "Care este titlul cărții? ";
    //aloc spatiu random
    char aux1[100];
    //citesc sirul de caractere cu functia .getline() ca sa ia in considerare si spatiile
    in.getline(aux1, 100);
    ca.titlu = aux1;
    cout << "Cine este autorul? ";
    char aux2[100];
    in.getline(aux2, 100); //acelasi lucru ca la string
    delete [] ca.autor;
    ca.autor = new char [strlen(aux2)+1];
    strcpy(ca.autor, aux2);
    cout << "În ce an a fost publicată? ";
    in >> ca.anAparitie;
    cout << "Este disponibilă pentru împrumut?[0/1] ";
    in >> ca.status;
    in.get(); //fac posibila urmatoarea citire pentru urmatorul obiect(citind enter-ul), in cazul unui vector de obiecte, altfel va considera tasta enter ca titlu pentru urmatoarea carte
    return in;
}

void Carte::setAutor(char *autor)
{
    this->autor = new char[strlen(autor)+1];
    strcpy(this->autor, autor);
}

class Utilizator{
private:
    const int idUtilizator;
    static int contorIdUtilizator;
    char numeUtilizator[20];
    char prenumeUtilizator[20];
    char sexUtilizator[2];
    struct dataNasterii{
        int zi;
        string luna;
        int an;
    }data_nasterii;
    char *numarTelefonic;
    int nrCartiImprumutate;
    int *idCartiImprumutate;
public:
//constructori
    Utilizator();
    Utilizator(char numeUtilizator[20], char prenumeUtilizator[20], char sexUtilizator[2], dataNasterii data_nasterii, char *numarTelefonic, int nrCartiImprumutate, int *idCartiImprumutate);
    Utilizator(char numeUtilizator[20], char prenumeUtilizator[20]);
    Utilizator(char numeUtilizator[20], char prenumeUtilizator[20], char sexUtilizator[2], dataNasterii data_nasterii);
    Utilizator(const Utilizator &obj); //copy-constructor
    ~Utilizator(); //destructor
//operatori
    Utilizator &operator = (const Utilizator &obj); //supraincarcare operator atribuire
    friend istream &operator >> (istream &in, Utilizator &u); //supraincarcare operator citire
    friend ostream &operator << (ostream &out, const Utilizator &u); //supraincarcare operator afisare
//getteri
    const int getIdUtilizator() {return this->idUtilizator;}
    char *getNumeUtilizator() {return this->numeUtilizator;}
    char *getPrenumeUtilizator() {return this->prenumeUtilizator;}
    char *getSexUtilizator() {return this->sexUtilizator;}
    dataNasterii getDataNasterii() {return this->data_nasterii;}
    char *getNumarTelefonic() {return this->numarTelefonic;}
    int getNrCartiImprumutate() {return this->nrCartiImprumutate;}
    int *getIdCartiImprumutate() {return this->idCartiImprumutate;}
//setteri
    void setNumeUtilizator(char numeUtilizator[30]) {strcpy(this->numeUtilizator, numeUtilizator);}
    void setPrenumeUtilizator(char prenumeUtilizator[30]) {strcpy(this->prenumeUtilizator, prenumeUtilizator);}
    void setSexUtilizator(char sexUtilizator[2]) {strcpy(this->sexUtilizator, sexUtilizator);}
    void setDataNasterii(dataNasterii data_nasterii);
    void setNumarTelelefonic(char *numarTelefonic);
    void setNrCartiImprumutate(int nrCartiImprumutate) {this->nrCartiImprumutate = nrCartiImprumutate;}
    void setIdCartiImprumutate(int *idCartiImprumutate);
};

//corpul functiilor clasei Utilizator
int Utilizator::contorIdUtilizator = 10000;
Utilizator::Utilizator():idUtilizator(contorIdUtilizator++)
{
    strcpy(this->numeUtilizator, "Necunoscut");
    strcpy(this->prenumeUtilizator, "Necunoscut");
    strcpy(this->sexUtilizator, "X");
    this->data_nasterii.zi = 0;
    this->data_nasterii.luna = "0";
    this->data_nasterii.an = 0;
    this->numarTelefonic = new char [strlen("Necunoscut")+1];
    strcpy(this->numarTelefonic, "Necunoscut");
    this->nrCartiImprumutate = 0;
    this->idCartiImprumutate = NULL;
}

Utilizator::Utilizator(char numeUtilizator[20], char prenumeUtilizator[20], char sexUtilizator[2], dataNasterii data_nasterii, char *numarTelefonic, int nrCartiImprumutate, int *idCartiImprumutate):idUtilizator(contorIdUtilizator++)
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
}

Utilizator::Utilizator(char numeUtilizator[20], char prenumeUtilizator[20]):idUtilizator(contorIdUtilizator++)
{
    strcpy(this->numeUtilizator, numeUtilizator);
    strcpy(this->prenumeUtilizator, prenumeUtilizator);
    strcpy(this->sexUtilizator, "X");
    this->data_nasterii.zi = 0;
    this->data_nasterii.luna = "0";
    this->data_nasterii.an = 0;
    this->numarTelefonic = new char [strlen("Necunoscut")+1];
    strcpy(this->numarTelefonic, "Necunoscut");
    this->nrCartiImprumutate = 0;
    this->idCartiImprumutate = NULL;
}

Utilizator::Utilizator(char numeUtilizator[20], char prenumeUtilizator[20], char sexUtilizator[2], dataNasterii data_nasterii):idUtilizator(contorIdUtilizator++)
{
    strcpy(this->numeUtilizator, numeUtilizator);
    strcpy(this->prenumeUtilizator, prenumeUtilizator);
    strcpy(this->sexUtilizator, sexUtilizator);
    this->data_nasterii.zi = data_nasterii.zi;
    this->data_nasterii.luna = data_nasterii.luna;
    this->data_nasterii.an = data_nasterii.an;
    this->numarTelefonic = new char [strlen("Necunoscut")+1];
    strcpy(this->numarTelefonic, "Necunoscut");
    this->nrCartiImprumutate = 0;
    this->idCartiImprumutate = NULL;
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
    return *this;
}

istream &operator >> (istream &in, Utilizator &u)
{
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
    cout << "Introduceți, pe rând, ID-ul fiecărei cărți împrumutate: ";
    for (int i = 0; i < u.nrCartiImprumutate; i++)
        in >> u.idCartiImprumutate[i];
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

class Bibliotecar{
private:
    const int idBibliotecar;
    static int contorIdBibliotecar;
    char *numeBibliotecar;
    char *prenumeBibliotecar;
    int varstaBibliotecar;
    float venitLunar;
    struct dataAngajarii{
        int zi;
        int luna;
        int an;
    }data_angajarii;
    int nrZileLucruSaptamanal;
    char programSaptamanal[7][50];
public:
    float getVenitLunar() {return this->venitLunar;}
    void setVenitLunar(float venitLunar) {this->venitLunar = venitLunar;}
//constructori
    Bibliotecar();
    Bibliotecar(char *numeBibliotecar, char *prenumeBibliotecar, int varstaBibliotecar, float venitLunar, dataAngajarii data_angajarii, int nrZileLucruSaptamanal, char programSaptamanal[7][50]);
    Bibliotecar(char *numeBibliotecar, char *prenumeBibliotecar);
    Bibliotecar(char *numeBibliotecar, char *prenumeBibliotecar, dataAngajarii data_angajarii);
    Bibliotecar(const Bibliotecar &obj); //copy-constructor
    ~Bibliotecar();
//operatori
    Bibliotecar &operator =(const Bibliotecar &obj);
    friend istream &operator >> (istream &in, Bibliotecar &b);
    friend ostream &operator << (ostream &out, const Bibliotecar &b);
};

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
    strcpy(this->programSaptamanal[0], "Necunoscut");
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

class Sala{
private:
    const int nrSala;
    static int contorSala;
    int nrLocuriSala;
    int nrLocuriOcupate;
    int locuriOcupate[50];
    struct dimensiune{
        double lungime;
        double latime;
    }dimensiuneSala;
public:
    dimensiune getDimensiuneSala() {return this->dimensiuneSala;}
    const void setDimensiuneSala(dimensiune dimensiuneSala);
//constructori
    Sala();
    Sala(int nrLocuriSala, int nrLocuriOcupate, int locuriOcupate[50], dimensiune dimensiuneSala);
    Sala(int nrLocuriSala, dimensiune dimensiuneSala);
    Sala(int nrLocuriSala, int nrLocuriOcupate);
    Sala(const Sala &obj); //copy-constructor
    ~Sala() {}
//operatori
    Sala &operator =(const Sala &s);
//    Sala &operator --(); //vezi locuriOcupate
//    Sala &operator ++(int loc) {this->nrLocuriOcupate += 1; this->locuriOcupate[this->nrLocuriOcupate] = loc; return *this;}
    friend istream &operator >> (istream &in, Sala &s);
    friend ostream &operator << (ostream &out, const Sala &s);
};

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
    locuriOcupate[0] = NULL;
    dimensiuneSala.lungime = 0;
    dimensiuneSala.latime = 0;
}

Sala::Sala(int nrLocuriSala, int nrLocuriOcupate, int *locuriOcupate, dimensiune dimensiuneSala):nrSala(++contorSala)
{
    this->nrLocuriSala = nrLocuriSala;
    this->nrLocuriOcupate = nrLocuriOcupate;
//    this->locuriOcupate = new int[nrLocuriOcupate];
    for(int i = 0; i<nrLocuriOcupate; i++)
        this->locuriOcupate[i] = locuriOcupate[i];
    this->dimensiuneSala.lungime = dimensiuneSala.lungime;
    this->dimensiuneSala.latime = dimensiuneSala.latime;
}

Sala::Sala(int nrLocuriSala, dimensiune dimensiuneSala):nrSala(++contorSala)
{
    this->nrLocuriSala = nrLocuriSala;
    nrLocuriOcupate = 0;
    locuriOcupate[0] = NULL;
    this->dimensiuneSala.lungime = dimensiuneSala.lungime;
    this->dimensiuneSala.latime = dimensiuneSala.lungime;
}

Sala::Sala(int nrLocuriSala, int nrLocuriOcupate):nrSala(++contorSala)
{
    this->nrLocuriSala = nrLocuriSala;
    this->nrLocuriOcupate = nrLocuriOcupate;
    locuriOcupate[0] = NULL;
    dimensiuneSala.lungime = 0;
    dimensiuneSala.latime = 0;
}

Sala::Sala(const Sala &obj):nrSala(++contorSala)
{
    this->nrLocuriSala = obj.nrLocuriSala;
    this->nrLocuriOcupate = obj.nrLocuriOcupate;
//    locuriOcupate = new int[obj.nrLocuriOcupate];
    for(int i = 0; i<obj.nrLocuriOcupate; i++)
        this->locuriOcupate[i] = obj.locuriOcupate[i];
    this->dimensiuneSala.lungime = obj.dimensiuneSala.lungime;
    this->dimensiuneSala.latime = obj.dimensiuneSala.latime;
}

Sala &Sala::operator =(const Sala &s)
{
    
    this->nrLocuriSala = s.nrLocuriSala;
    this->nrLocuriOcupate = s.nrLocuriOcupate;
//    locuriOcupate = new int[s.nrLocuriOcupate];
    for(int i = 0; i<s.nrLocuriOcupate; i++)
        this->locuriOcupate[i] = s.locuriOcupate[i];
    this->dimensiuneSala.lungime = s.dimensiuneSala.lungime;
    this->dimensiuneSala.latime = s.dimensiuneSala.latime;
    return *this;
}

//Sala &Sala::operator --()
//{
//    delete &this->locuriOcupate[this->nrLocuriOcupate];
//    this->nrLocuriOcupate -= 1;
//    return *this;
//}

istream &operator >> (istream &in, Sala &s)
{
    cout << "Introduceti numarul de locuri al salii: ";
    in >> s.nrLocuriSala;
    cout << "Cate locuri sunt ocupate acum? ";
    in >> s.nrLocuriOcupate;
    if (s.nrLocuriOcupate != 0)
    {
        cout << "Care locuri sunt ocupate? ";
//        if (s.locuriOcupate != NULL)
//        {
//            delete [] s.locuriOcupate;
//            s.locuriOcupate = NULL;
//        }
//        s.locuriOcupate = new int[s.nrLocuriOcupate];
        for (int i=0; i<s.nrLocuriOcupate; i++)
            in >> s.locuriOcupate[i];
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
        out << "Locurile ocupate sunt: ";
        for (int i = 0; i<s.nrLocuriOcupate-1; i++)
            out << s.locuriOcupate[i] << ", ";
        out << s.locuriOcupate[s.nrLocuriOcupate-1] << "." << endl;
    }
    return out;
}

int main()
{
//teste
//    Carte C[100];
//    for (int i = 0; i<= 2; i++)
//    {
//        cin >> C[i];
//        cout << endl;
//    }
//
//    Utilizator U[100];
//    for (int i = 0; i<= 2; i++)
//    {
//        cin >> U[i];
//        cout << endl;
//    }
//
//    Bibliotecar B[100];
//    for (int i = 0; i<= 2; i++)
//    {
//        cin >> B[i];
//        cout << endl;
//    }
//    Sala S[100];
//    for (int i = 0; i<= 2; i++)
//    {
//        cin >> S[i];
//        cout << endl;
//    }
//    cout << "Cartile: " << endl;
//    for (int i = 0; i<= 2; i++)
//    {
//        cout << C[i];
//        cout << endl;
//    }
//    cout << "Utilizatorii:" << endl;
//    for (int i = 0; i<= 2; i++)
//    {
//        cout << U[i];
//        cout << endl;
//    }
//    cout << "Bibliotecarii: " << endl;
//    for (int i = 0; i<= 2; i++)
//    {
//        cout << B[i];
//        cout << endl;
//    }
//    cout << "Salile: " << endl;
//    for (int i = 0; i<= 2; i++)
//    {
//        cout << S[i];
//        cout << endl;
//    }

//    Sala B;

//    cout << B;
//cout << B;
//    int a[] = {123, 13};
//    char b[] = "0756927417";
//    Utilizator U;
//    U.setNrCartiImprumutate(2);
//    U.setIdCartiImprumutate(a);
//    U.setNumarTelelefonic(b);
//    char nume[] = "pistol";
//    char prenume[] = "tudor";
//    char sex[] = "M";
//    char nr[] = "0756927417";
//    Utilizator c(nume, prenume, sex, {31, "mai", 2003}, nr, 2, a);
//    Utilizator U;
//    cin >> U;
//    cout << U;
//    cout<<c.getNumeUtilizator()<<endl<<c.getPrenumeUtilizator()<<endl<<c.getSexUtilizator()<<endl<<c.getDataNasterii().zi<<endl<<c.getDataNasterii().luna<<endl<<c.getDataNasterii().an<<endl<<c.getNumarTelefonic()<<endl<<c.getNrCartiImprumutate()<<endl;
//    cout<<c3.getNumeUtilizator()<<endl<<c3.getPrenumeUtilizator()<<endl<<c3.getSexUtilizator()<<endl<<c3.getDataNasterii().zi<<endl<<c3.getDataNasterii().luna<<endl<<c.getDataNasterii().an<<endl<<c3.getNumarTelefonic()<<endl<<c3.getNrCartiImprumutate()<<endl;
//    for(int i = 0; i<c3.getNrCartiImprumutate();i++)
//        cout<<c3.getIdCartiImprumutate()[i]<<endl;
//
//    cout<<c1.getNumeUtilizator()<<endl<<c.getPrenumeUtilizator()<<endl<<c1.getSexUtilizator()<<endl<<c1.getDataNasterii().zi<<endl<<c1.getDataNasterii().luna<<endl<<c1.getDataNasterii().an<<endl<<c1.getNumarTelefonic()<<endl<<c1.getNrCartiImprumutate()<<endl;
//    for(int i = 0; i<c1.getNrCartiImprumutate();i++)
//        cout<<c1.getIdCartiImprumutate()[i]<<endl;
}
