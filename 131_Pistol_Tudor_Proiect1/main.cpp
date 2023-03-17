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
    Carte &operator ++ ();
    Carte operator ++ (int);
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
    Carte b1, b2, b3;
    cin>> b1;
    cout << b1;
    //cout << 500.6 +b1 ;
    //b1-10.0;
    //cout << b1;

    
//    U-2003;
//    cout << U;
//    //carti
//    char c0[] = "Thomas Mann";
//    char c1[] = "Franz Kafka";
//    char c2[] = "Albert Camus";
//    char c3[] = "Fernando Pessoa";
//    char c4[] = "Gabriel Garcia Marquez";
//    char c5[] = "F. M. Dostoievski";
//    char c6[] = "Nikolai Gogol";
//    char c7[] = "Max L. Blecher";
//    char c8[] = "Liviu Rebreanu";
//    char c9[] = "Nichita Stanescu";
//    Carte C0("Moarte la Venetia", c0, 1912, 1);
//    Carte C1("Procesul", c1, 1925, 1);
//    Carte C2("Ciuma", c2, 1947, 1);
//    Carte C3("Cartea nelinistirii", c3, 1982, 1);
//    Carte C4("Un veac de singuratate", c4, 1967, 1);
//    Carte C5("Fratii Karamazov", c5, 1880, 1);
//    Carte C6("Povestiri din Petersburg", c6, 1842, 1);
//    Carte C7("Inimi cicatricate", c7, 1937, 1);
//    Carte C8("Ciuleandra", c8, 1927, 1);
//    Carte C9("Opera Magna", c9, 1965, 1);
//    Utilizator U0("Pistol", "Tudor", "M", {31, "mai", 2003}, "+40756927417");
//    Utilizator U1("Obada", "Iustina", "F", {7, "decembrie", 2003}, "+4073411319");
//    Utilizator U2("Pistol", "David", "M", {27, "iunie", 2007}, "+40756927233");
//    Utilizator U3("Raspopa", "Monica", "F", {2, "februarie", 1980}, "+40756925674");
}
