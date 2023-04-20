#ifndef utilizator_h
#define utilizator_h
using namespace std;

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

#endif
