#ifndef carte_h
#define carte_h
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

#endif 
