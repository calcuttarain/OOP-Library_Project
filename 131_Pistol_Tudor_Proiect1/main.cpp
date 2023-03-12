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
    if (ca.autor != NULL)
    {
        delete [] ca.autor;
        ca.autor = NULL;
    }
    cout << "Care este titlul cărții? ";
    //aloc spatiu random
    char aux1[100];
    //citesc sirul de caractere cu functia .get() ca sa ia in considerare si spatiile
    in.get(aux1, 100);
    ca.titlu = aux1;
    //eliberez stream bufferul
    in.clear();
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //?
    cout << "Cine este autorul? ";
    //acelasi lucru ca la string
    char aux2[100];
    in.get(aux2, 100);
    ca.autor = new char [strlen(aux2)+1];
    strcpy(ca.autor, aux2);
    in.clear();
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "În ce an a fost publicată? ";
    in >> ca.anAparitie;
    cout << "Este disponibilă pentru împrumut? ";
    in >> ca.status;
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
    ~Utilizator();
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

int main()
{
    int a[] = {123, 13};
    char b[] = "0756927417";
    Utilizator U;
    U.setNrCartiImprumutate(2);
    U.setIdCartiImprumutate(a);
    U.setNumarTelelefonic(b);
    char nume[] = "pistol";
    char prenume[] = "tudor";
    char sex[] = "M";
    char nr[] = "0756927417";
    Utilizator c(nume, prenume, sex, {31, "mai", 2003}, nr, 2, a);
    cout<<c.getNumeUtilizator()<<endl<<c.getPrenumeUtilizator()<<endl<<c.getSexUtilizator()<<endl<<c.getDataNasterii().zi<<endl<<c.getDataNasterii().luna<<endl<<c.getDataNasterii().an<<endl<<c.getNumarTelefonic()<<endl<<c.getNrCartiImprumutate()<<endl;
    for(int i = 0; i<c.getNrCartiImprumutate();i++)
        cout<<c.getIdCartiImprumutate()[i]<<endl;
    Utilizator c1("pistol", "tudor", "M", {3, "mai", 2003});
    cout<<c1.getNumeUtilizator()<<endl<<c.getPrenumeUtilizator()<<endl<<c1.getSexUtilizator()<<endl<<c1.getDataNasterii().zi<<endl<<c1.getDataNasterii().luna<<endl<<c1.getDataNasterii().an<<endl<<c1.getNumarTelefonic()<<endl<<c1.getNrCartiImprumutate()<<endl;
    for(int i = 0; i<c1.getNrCartiImprumutate();i++)
        cout<<c1.getIdCartiImprumutate()[i]<<endl;
}
