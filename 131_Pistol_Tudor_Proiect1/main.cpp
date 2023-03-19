#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Carte{
private:
    const int idCarte;
    static int contorIdCarte;
    string titlu;
    char *autor;
    int anAparitie;
    bool status;
    int idCititor;
public:
//constructors:
    Carte(); //constructorul fara parametri
    Carte(string titlu, char *autor, int anAparitie, bool status, int idCititor); //constructorul cu toti parametrii
    Carte(string titlu, char *autor);
    Carte(string titlu, char *autor, int anAparitie);
    Carte(const Carte &Obj); //copy-constructor
    ~Carte(); //destructor
//operatori
    Carte &operator + (int);
    friend Carte operator + (int idCititor, Carte &c);
    Carte &operator - (int);
    Carte &operator -- ();
    Carte operator -- (int);
    bool operator == (const Carte &c);
    bool operator < (const Carte &c);
    bool operator <= (const Carte &c);
    bool operator > (const Carte &c);
    bool operator >= (const Carte &c);
    operator string () {return this->titlu;}
    operator int () {return this->idCarte;}
    Carte &operator = (const Carte &Obj); //forma incarcata a operatorului de atribuire
    friend istream &operator >> (istream &in, Carte &c); //supraincarcarea operatorului de citire
    friend ostream &operator << (ostream &out, const Carte &ca); //supraincarcarea operatorului de afisare
//setters
    void setTitlu(string titlu) {this->titlu = titlu;}
    void setAutor(char *autor);
    void setAnAparitie(int anAparitie) {this->anAparitie = anAparitie;}
    void setStatus(bool status) {this->status = status;}
    void setIdCititor(int idCititor) {this->idCititor = idCititor;}
//getters
    const int getIdCarte() {return idCarte;}
    static int getContorIdCarte() {return contorIdCarte;}
    string getTitlu() {return titlu;}
    const char *getAutor() const {return autor;}
    int getAnAparitie() {return anAparitie;}
    bool getStatus() {return status;}
    int getIdCititor() {return idCititor;}
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
    int aniAbonare;
public:
//constructori
    Utilizator();
    Utilizator(char numeUtilizator[20], char prenumeUtilizator[20], char sexUtilizator[2], dataNasterii data_nasterii, char *numarTelefonic, int nrCartiImprumutate, int *idCartiImprumutate, int aniAbonare);
    Utilizator(char numeUtilizator[20], char prenumeUtilizator[20]);
    Utilizator(char numeUtilizator[20], char prenumeUtilizator[20], char sexUtilizator[2], dataNasterii data_nasterii, char *numarTelefonic);
    Utilizator(const Utilizator &obj); //copy-constructor
    ~Utilizator(); //destructor
//operatori
    Utilizator &operator = (const Utilizator &obj); //supraincarcare operator atribuire
    Utilizator &operator ++(); //preincrementare
    Utilizator operator ++(int); //postincrementare
    Utilizator &operator +(int); //adunare la dreapta la idCartiImprumutate
    Utilizator &operator -(int); //scadere la idCartiImprumutate
    friend Utilizator operator +(int a, Utilizator &u); //adunare la stanga la idCartiImprumutate
    int operator [] (int); //operator indexare
    operator int(); //cast explicit
    bool operator == (const Utilizator &u); //operator pt testare daca doi utilizatori au acelasi nume de familie
    //operatori pt compararea numarului de carti imprumutate
    bool operator > (const Utilizator &u);
    bool operator >= (const Utilizator &u);
    bool operator < (const Utilizator &u);
    bool operator <= (const Utilizator &u);
    friend istream &operator >> (istream &in, Utilizator &u); //supraincarcare operator citire
    friend ostream &operator << (ostream &out, const Utilizator &u); //supraincarcare operator afisare
//getteri
    const int getIdUtilizator() {return this->idUtilizator;}
    const char *getNumeUtilizator() const {return this->numeUtilizator;}
    const char *getPrenumeUtilizator() const {return this->prenumeUtilizator;}
    const char *getSexUtilizator() const {return this->sexUtilizator;}
    dataNasterii getDataNasterii() {return this->data_nasterii;}
    const char *getNumarTelefonic() const {return this->numarTelefonic;}
    int getNrCartiImprumutate() {return this->nrCartiImprumutate;}
    const int *getIdCartiImprumutate() const {return this->idCartiImprumutate;}
    int getAniAbonare() {return aniAbonare;}
//setteri
    void setNumeUtilizator(char numeUtilizator[30]) {strcpy(this->numeUtilizator, numeUtilizator);}
    void setPrenumeUtilizator(char prenumeUtilizator[30]) {strcpy(this->prenumeUtilizator, prenumeUtilizator);}
    void setSexUtilizator(char sexUtilizator[2]) {strcpy(this->sexUtilizator, sexUtilizator);}
    void setDataNasterii(dataNasterii data_nasterii);
    void setNumarTelelefonic(char *numarTelefonic);
    void setNrCartiImprumutate(int nrCartiImprumutate) {this->nrCartiImprumutate = nrCartiImprumutate;}
    void setIdCartiImprumutate(int *idCartiImprumutate);
    void setAniAbonare(int aniAbonare) {this->aniAbonare = aniAbonare;}
//metode

};

//corpul functiilor clasei Utilizator
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
    void setVarstaBibliotecar(int varstaBibliotecar) {this->varstaBibliotecar = varstaBibliotecar;}
    int getVarstaBibliotecar() {return this->varstaBibliotecar;}
    const char* getNumeBibliotecar() const {return numeBibliotecar;}
    const char* getPrenumeBibliotecar() const {return prenumeBibliotecar;}
    dataAngajarii getDataAngajarii () {return data_angajarii;}
//constructori
    Bibliotecar();
    Bibliotecar(char *numeBibliotecar, char *prenumeBibliotecar, int varstaBibliotecar, float venitLunar, dataAngajarii data_angajarii, int nrZileLucruSaptamanal, char programSaptamanal[7][50]);
    Bibliotecar(char *numeBibliotecar, char *prenumeBibliotecar);
    Bibliotecar(char *numeBibliotecar, char *prenumeBibliotecar, dataAngajarii data_angajarii);
    Bibliotecar(const Bibliotecar &obj); //copy-constructor
    ~Bibliotecar();
//operatori
    char const * operator [] (int); //operator indexare program
    Bibliotecar &operator ++ (); //operator preincrementare ani
    Bibliotecar operator ++ (int); //operator postincrementare ani
    Bibliotecar &operator + (double venit); //adunare la dreapta
    friend Bibliotecar operator + (double venit, Bibliotecar &b); //adunare la stanga
    Bibliotecar &operator - (double venit); //marire/micsorare venit
    operator float () {return venitLunar;} //cast explicit
    operator int () {return idBibliotecar;}
    bool operator == (const Bibliotecar &b);
    bool operator > (const Bibliotecar &b);
    bool operator >= (const Bibliotecar &b);
    bool operator < (const Bibliotecar &b);
    bool operator <= (const Bibliotecar &b);
    Bibliotecar &operator =(const Bibliotecar &obj); //operator atribuie
    friend istream &operator >> (istream &in, Bibliotecar &b); //operator citire
    friend ostream &operator << (ostream &out, const Bibliotecar &b); //operator afisare
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
    friend int operator + (const Sala s, const Utilizator u);
    friend int operator + (const Utilizator u, const Sala s); //adunare intre doua clase
    int getNrLocuriOcupate () {return nrLocuriOcupate;}
    int getNrSala () {return nrSala;}
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

int operator + (const Sala s, const Utilizator u) {int aux; aux = s.nrLocuriOcupate; return aux++;}

int operator + (const Utilizator u, const Sala s) {int aux; aux = s.nrLocuriOcupate; return aux++;}

int main()
{
    int ok = 1, cc = 0, cu = 0, cb = 0, cs = 0;
    Carte vectorCarti[100];
    Utilizator vectorUtilizatori[100];
    Bibliotecar vectorBibliotecari[100];
    Sala vectorSali[100];
    while (ok == 1)
    {
        int comanda;
        cout << "\t\t\tMeniu principal\n\n";
        cout << "\t1-Inregistrare carte noua" << endl;
        cout << "\t2-Inregistrare utilizator nou" << endl;
        cout << "\t3-Inregistrare bibliotecar nou" << endl;
        cout << "\t4-Inregistrare sala noua" << endl;
        cout << "\t5-Informatii carti" << endl;
        cout << "\t6-Informatii utilizatori" << endl;
        cout << "\t7-Informatii bibliotecari" << endl;
        cout << "\t8-Informatii sali" << endl;
        cout << "\t9-Meniu editare carti" << endl;
        cout << "\t10-Meniu editare utilizatori" << endl;
        cout << "\t11-Meniu editare bibliotecari" << endl;
        cout << "\t12-Meniu editare sali" << endl;
        cout << "\t13-Stergere carte" << endl;
        cout << "\t14-Stergere utilizator" << endl;
        cout << "\t15-Stergere bibliotecar" << endl;
        cout << "\t16-Stergere sala" << endl;
        cout << "\t17-Iesire" << endl;
        cin >> comanda;
        switch(comanda)
        {
            case 1:{
                Carte C;
                cin >> C;
                vectorCarti[cc] = C;
                cc++;
                system("cls");
                break;
            }
            case 2:{
                Utilizator U;
                cin >> U;
                vectorUtilizatori[cu] = U;
                cu++;
                system("cls");
                break;
            }
            case 3:{
                Bibliotecar B;
                cin >> B;
                vectorBibliotecari[cb] = B;
                cb++;
                system("cls");
                break;
            }
            case 4:{
                Sala S;
                cin >> S;
                vectorSali[cs] = S;
                cs++;
                system("cls");
                break;
            }
            case 5:{
                int ok1 = 1;
                while (ok1 == 1)
                {
                    cout << "\t\t\tInformatii carti\n\n";
                    cout << "\t1-Gasiti o carte dupa ID\n";
                    cout << "\t2-Gasiti o carte dupa titlu\n";
                    cout << "\t3-Vizualizati cartile disponibile pentru imprumut\n"; //functionalitate
                    cout << "\t4-Inapoi la meniul principal\n";
                    int comanda1;
                    cin >> comanda1;
                    switch (comanda1){
                        case 1:{
                            cout << "\nIntroduceti ID-ul cartii cautate: ";
                            int id;
                            cin >> id;
                            int k = 0;
                            for(int i = 0; i<cc; i++)
                                if(vectorCarti[i].getIdCarte() == id)
                                {
                                    cout << vectorCarti[i];
                                    k = 1;
                                    break;
                                }
                            if(k == 0) cout << "\nID invalid!";
                            system("cls");
                            break;
                        }
                        case 2:{
                            cout << "\nIntroduceti titlul cartii cautate: ";
                            string titlu;
                            cin >> titlu;
                            int k = 0;
                            for(int i = 0; i<cc; i++)
                                if(vectorCarti[i].getTitlu() == titlu)
                                {
                                    cout << vectorCarti[i];
                                    k = 1;
                                    break;
                                }
                            if(k == 0) cout << "\nAcest titlu nu exista!";
                            system("cls");
                            break;
                        }
                        case 3:{
                            int k = 0;
                            for(int i = 0; i<cc; i++)
                                if(vectorCarti[i].getStatus() == 1)
                                {
                                    cout << vectorCarti[i] << endl;
                                    k = 1;
                                }
                            if (k == 0) cout << "Nu exista carti disponibile!";
                            system("cls");
                            break;
                        }
                        case 4:{
                            ok1 = 0;
                            break;
                        }
                        default:{
                            cout << "Comanda nerecunoscuta!";
                            system("cls");
                            break;
                        }
                    }
                }
                system("cls");
                break;
            }
            case 6:{
                int ok2 = 1;
                while (ok2 != 0)
                {
                    cout << "\t\t\tInformatii utilizatori\n\n";
                    cout << "\t1-Cautati utilizator dupa ID\n";
                    cout << "\t2-Cautati utilizatori dupa numele de familie\n";
                    cout << "\t3-Cautati utilizatori dupa numele complet\n";
                    cout << "\t4-Verificati daca este la sala de lectura\n"; //functionalitate
                    cout << "\t5-Inapoi la meniul principal\n";
                    int comand2;
                    cin >> comand2;
                    switch (comand2){
                        case 1:{
                            int k = 0, id;
                            cout << "Introduceti ID-ul utilizatorului cautat: ";
                            cin >> id;
                            for(int i = 0; i<cu; i++)
                                if(vectorUtilizatori[i].getIdUtilizator() == id)
                                {
                                    cout << vectorUtilizatori[i];
                                    k = 1;
                                    break;
                                }
                            if (k == 0) cout << "ID invalid!\n";
                            system("cls");
                            break;
                        }
                        case 2:{
                            cin.get();
                            int k = 0;
                            char nume[20];
                            cout << "Introduceti numele de familie al utilizatorului cautat: ";
                            cin.getline(nume, 20);
                            for(int i = 0; i<cu; i++)
                                if(strcmp(vectorUtilizatori[i].getNumeUtilizator(), nume) == 0)
                                {
                                    cout << vectorUtilizatori[i];
                                    k = 1;
                                    break;
                                }
                            if (k == 0) cout << "Nume neinregistrat!\n";
                            system("cls");
                            break;
                        }
                        case 3:{
                            cin.get();
                            int k = 0;
                            char nume[20], prenume[20];
                            cout << "Introduceti numele de familie al utilizatorului cautat: " << endl;
                            cin.getline(nume, 20);
                            cout << "Introduceti prenumele utilizatorului cautat: " << endl;
                            cin.getline(prenume, 20);
                            for(int i = 0; i<cu; i++)
                                if(strcmp(vectorUtilizatori[i].getNumeUtilizator(), nume) == 0 && strcmp(vectorUtilizatori[i].getPrenumeUtilizator(), prenume) == 0)
                                {
                                    cout << vectorUtilizatori[i];
                                    k = 1;
                                    break;
                                }
                            if (k == 0) cout << "Utilizator neinregistrat!\n";
                            system("cls");
                            break;
                        }
                        case 4:{
                            cout << "Introduceti ID-ul utilizatorului: ";
                            int id, k = 0;
                            cin >> id;
                            for (int i = 0; i<cs; i++)
                                for(int j = 0; j<vectorSali[i].getNrLocuriOcupate(); j++)
                                    if (vectorSali[i][j] == id)
                                    {
                                        cout << "Utilizatorul se afla la sala numarul " << vectorSali[i].getNrSala();
                                        k = 1;
                                        break;
                                    }
                            if(k == 0) cout << "Utilizatorul nu se afla la sala de lectura";
                            system("cls");
                            break;
                        }
                        case 5:{
                            ok2 = 0;
                            break;
                        }
                        default:{
                            cout << "Comanda invalida!";
                        }
                    }
                }
                system("cls");
                break;
            }
            case 7:{
                int ok3 = 1;
                while (ok3 == 1)
                {
                    cout << "\t\t\tInformatii Bibliotecari\n\n";
                    cout << "\t1-Cautati un bibliotecar dupa ID\n";
                    cout << "\t2-Cautati un bibliotecar dupa numele complet\n";
                    cout << "\t3-Cautati bibliotecarii cu o anumita varsta\n"; //functionalitate
                    cout << "\t4-Cautati bibliotecarii angajati dupa o anumita data\n"; //functionalitate
                    cout << "\t5-Inapoi la meniul principal\n";
                    int command3;
                    cin >> command3;
                    switch (command3){
                        case 1:{
                            cout << "Introduceti ID-ul: ";
                            int id, k = 0;
                            cin >> id;
                            for(int i = 0; i<cb; i++)
                                if(int(vectorBibliotecari[i]) == id)
                                {
                                    cout << vectorBibliotecari[i];
                                    k = 1;
                                    break;
                                }
                            if (k == 0) cout << "ID inexistent\n";
                            system("cls");
                            break;
                        }
                        case 2:{
                            cin.get();
                            int k = 0;
                            char nume[20], prenume[20];
                            cout << "Introduceti numele de familie al bibliotecarului cautat: " << endl;
                            cin.getline(nume, 20);
                            cout << "Introduceti prenumele bibliotecarului cautat: " << endl;
                            cin.getline(prenume, 20);
                            for(int i = 0; i<cb; i++)
                                if(strcmp(vectorBibliotecari[i].getNumeBibliotecar(), nume) == 0 && strcmp(vectorBibliotecari[i].getPrenumeBibliotecar(), prenume) == 0)
                                {
                                    cout << vectorBibliotecari[i];
                                    k = 1;
                                    break;
                                }
                            if (k == 0) cout << "Bibliotecarul nu exista!\n";
                            system("cls");
                            break;
                        }
                        case 3:{
                            cout << "Introduceti numarul de ani: ";
                            int ani;
                            cin >> ani;
                            int k = 0;
                            for(int i = 0; i<cb; i++)
                                if(vectorBibliotecari[i].getVarstaBibliotecar() == ani)
                                {
                                    cout << vectorBibliotecari[i] << endl;
                                    k = 1;
                                }
                            if (k == 0) cout << "Nu exista bibliotecari care sa aiba aceasta varsta!\n";
                            system("cls");
                            break;
                        }
                        case 4:{
                            int zi, luna, an, k = 0;
                            cout << "Introduceti data[zz ll aaaa]: ";
                            cin >> zi >> luna >> an;
                            for(int i = 0; i<cb; i++)
                            {
                                if(vectorBibliotecari[i].getDataAngajarii().an > an)
                                {
                                    cout << vectorBibliotecari[i];
                                    k = 1;
                                }
                                else if(vectorBibliotecari[i].getDataAngajarii().an == an)
                                {
                                    if(vectorBibliotecari[i].getDataAngajarii().luna > luna)
                                    {
                                        cout << vectorBibliotecari[i];
                                        k = 1;
                                    }
                                    else if(vectorBibliotecari[i].getDataAngajarii().luna == luna)
                                        if(vectorBibliotecari[i].getDataAngajarii().zi >= zi)
                                        {
                                            cout << vectorBibliotecari[i];
                                            k = 1;
                                        }
                                }
                            }
                            if (k == 0) cout << "Nu exista bibliotecari angajati dupa data introdusa!\n";
                            system("cls");
                            break;
                        }
                        case 5:{
                            ok3 = 0;
                            system("cls");
                            break;
                        }
                        default:{
                            cout << "Comanda invalida!";
                        }
                    }
                }
                system("cls");
                break;
            }
            case 8:{
                int ok4 = 1;
                while(ok4 != 0)
                {
                    cout << "\t\t\tInformatii sali\n\n";
                    cout << "\t1-Cautati sala dupa numar\n";
                    cout << "\t2-Cautati numarul de locuri disponibile in fiecare sala\n"; //functionalitate
                    cout << "\t3-Vedeti utilizatorii dintr-o anumita sala\n"; //functionalitate
                    cout << "\t4-Inapoi la meniul principal\n";
                    int command4;
                    cin >> command4;
                    switch(command4){
                        case 1:{
                            cout << "Introduceti numarul salii: ";
                            int nr, k = 0;
                            cin >> nr;
                            for (int i = 0; i<cs; i++)
                                if(vectorSali[i].getNrSala() == nr)
                                {
                                    cout << vectorSali[i];
                                    k = 1;
                                    break;
                                }
                            if(k == 0) cout << "Sala nu exista!";
                            system("cls");
                            break;
                        }
                        case 2:{
                            for (int i = 0; i<cs; i++)
                                cout << "Sala numarul " << vectorSali[i].getNrSala() << " are " << int(vectorSali[i]) - vectorSali[i].getNrLocuriOcupate() << " locuri disponibile.\n";
                            system("cls");
                            break;
                        }
                        case 3:{
                            for(int i = 0; i<cs; i++)
                                for (int j = 0; j<vectorSali[i].getNrLocuriOcupate(); j++)
                                    for (int a = 0; a < cu; a++)
                                        if(int(vectorUtilizatori[a]) == vectorSali[i][j])
                                        {
                                            cout << vectorUtilizatori[a];
                                            break;
                                        }
                            system("cls");
                            break;
                        }
                        case 4:{
                            ok4 = 0;
                            system("cls");
                            break;
                        }
                        default:{
                            cout << "Comanda invalida!";
                        }
                    }
                }
                system("cls");
                break;
            }
            case 9:{
                int ok5 = 1;
                while (ok5 != 0)
                {
                    cout << "\t\t\tMeniu editare carti\n\n";
                    cout << "\t1-Imprumutati cartea unui cititor anume\n";
                    cout << "\t2-Inapoi la meniul principal\n";
                    int command5;
                    cin >> command5;
                    switch (command5){
                        case 1:{
                            cout << "Introduceti ID cititor: ";
                            int id;
                            cin >> id;
                            for (int i=0; i<cu; i++)
                                if(vectorUtilizatori[i].getIdUtilizator() == id)
                                {
                                    int id1 = -1;
                                    cout << "Introduceti ID carte: ";
                                    for (int j=0; j<cc; j++)
                                    {
                                        if(vectorCarti[j].getIdCarte() == id1)
                                        {
                                            vectorUtilizatori[i] = vectorUtilizatori[i] + vectorCarti[j].getIdCarte();
                                        }
                                    }
                                }
                            system("cls");
                            break;
                        }
                        case 2:{
                            ok5 = 0;
                            system("cls");
                            break;
                        }
                    }
                }
                system("cls");
                break;
            }
            case 10:{
                int ok6 = 1;
                while (ok6 != 0)
                {
                    cout << "\t\t\tMeniu editare utilizatori\n\n";
                    cout << "\t1-Returnati cartea\n";
                    cout << "\t2-Inapoi la meniul principal\n";
                    int command6;
                    cin >> command6;
                    switch(command6){
                        case 1:{
                            cout << "Introduceti ID utilizator: ";
                            int id;
                            cin >> id;
                            for (int i = 0; i<cu; i++)
                                if (vectorUtilizatori[i].getIdUtilizator() == id)
                                {
                                    cout << "Introduceti ID carte: ";
                                    int id1;
                                    cin >> id1;
                                    vectorUtilizatori[i] = vectorUtilizatori[i] - id1;
                                }
                            system("cls");
                            break;
                        }
                        case 2:{
                            ok6 = 0;
                            system("cls");
                            break;
                        }
                        default:{
                            cout << "Optiune inexistenta\n";
                        }
                    }
                }
                system("cls");
                break;
            }
            case 11:{
                int ok7 = 1;
                while(ok7 != 0)
                {
                    cout << "\t\t\tMeniu editare bibliotecari\n\n";
                    cout << "\t1-Modificati salariul unui bibliotecar\n";
                    cout << "\t2-Inapoi la meniul principal\n";
                    int command7;
                    cin >> command7;
                    switch(command7){
                        case 1:{
                            cout << "Introduceti ID bibliotecar";
                            int id;
                            cin >> id;
                            for (int i = 0; i<cb; i++)
                            {
                                if(int(vectorBibliotecari[i]) == id)
                                {
                                    cout << "Introduceti noul venit lunar: ";
                                    float venit;
                                    cin >> venit;
                                    vectorBibliotecari[i].setVenitLunar(venit);
                                }
                            }
                            system("cls");
                            break;
                        }
                        case 2:{
                            ok7 = 0;
                            system("cls");
                            break;
                        }
                    }
                }
                system("cls");
                break;
            }
            case 12:{
                int ok8 = 1;
                while (ok8 != 0)
                {
                    cout << "\t\t\tMeniu editare Sali\n\n";
                    cout << "\t1-Introduceti un cititor intr-o anumita sala\n";
                    cout << "\t2-Scoateti un cititor dintr-o anumita sala\n";
                    cout << "\t3-Inapoi la meniul principal\n";
                    int command8;
                    cin >> command8;
                    switch(command8){
                        case 1:{
                            cout << "Introduceti ID cititor: ";
                            int id, nr;
                            cin >> id;
                            cout << "\nIntroduceti numarul salii: ";
                            cin >> nr;
                            for (int i = 0; i<cs; i++)
                                if(vectorSali[i].getNrSala() == nr)
                                {
                                    vectorSali[i] = vectorSali[i] + id;
                                    break;
                                }
                            system("cls");
                            break;
                        }
                        case 2:{
                            cout << "Introduceti ID cititor: ";
                            int id, nr;
                            cin >> id;
                            cout << "\nIntroduceti numarul salii: ";
                            cin >> nr;
                            for (int i = 0; i<cs; i++)
                                if(vectorSali[i].getNrSala() == nr)
                                {
                                    vectorSali[i] = vectorSali[i] - id;
                                    break;
                                }
                            system("cls");
                            break;
                        }
                        case 3:{
                            ok8 = 0;
                            system("cls");
                            break;
                        }
                    }
                }
                system("cls");
                break;
            }
            case 13:{
                cout << "Introduceti ID-ul cartii: ";
                int id, k = 0;
                cin >> id;
                for (int i =0; i<cc; i++)
                    if (vectorCarti[i].getIdCarte() == id)
                    {
                        swap(vectorCarti[i], vectorCarti[cc]);
                        k = 1;
                        break;
                    }
                if(k == 0) cout << "Cartea nu exista!\n";
                else cc--; //
                system("cls");
                break;
            }
            case 14:{
                cout << "Introduceti ID-ul Utilizatorului: ";
                int id, k = 0;
                cin >> id;
                for (int i =0; i<cu; i++)
                    if (vectorUtilizatori[i].getIdUtilizator() == id)
                    {
                        swap(vectorUtilizatori[i], vectorUtilizatori[cu]);
                        k = 1;
                        break;
                    }
                if(k == 0) cout << "Utilizatorul nu exista!\n";
                else cu--; //
                system("cls");
                break;
            }
            case 15:{
                cout << "Introduceti ID-ul bibliotecarului: ";
                int id, k = 0;
                cin >> id;
                for (int i =0; i<cb; i++)
                    if (int(vectorBibliotecari[i]) == id)
                    {
                        swap(vectorBibliotecari[i], vectorBibliotecari[cb]);
                        k = 1;
                        break;
                    }
                if(k == 0) cout << "Bibliotecarul nu exista!\n";
                else cb--; //
                system("cls");
                break;
            }
            case 16:{
                cout << "Introduceti numarul salii: ";
                int id, k = 0;
                cin >> id;
                for (int i =0; i<cs; i++)
                    if (vectorSali[i].getNrSala() == id)
                    {
                        swap(vectorSali[i], vectorSali[cs]);
                        k = 1;
                        break;
                    }
                if(k == 0) cout << "Sala nu exista!\n";
                else cs--; //
                system("cls");
                break;
            }
            case 17:{
                ok = 0;
                break;
            }
            default:{
                cout << "Comanda invalida!";
                break;
            }
        }
    }
    return 0;
}
