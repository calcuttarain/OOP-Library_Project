#ifndef obiectDeImprumutat_h
#define obiectDeImprumutat_h
using namespace std;

enum stari {nou, folosit, uzat};

class obiectDeImprumutat{
protected:
    const int idObiect;
    static int contorObiect;
    bool status;
    stari stare;
    struct data{
        int zi;
        int luna;
        int an;
    } dataInregistrare;
    int idUtilizatorCurent;
public:
    obiectDeImprumutat();
    obiectDeImprumutat(bool status, stari stare, int idUtilizatorCurent);
    obiectDeImprumutat(const obiectDeImprumutat &);
    obiectDeImprumutat &operator = (const obiectDeImprumutat &);
    obiectDeImprumutat &operator + (int idUtilizatorCurent);
    obiectDeImprumutat &operator -- ();
    operator int () {return this->idObiect;}
    ~obiectDeImprumutat() {}
    virtual istream& inregistrare(istream&) = 0;
    virtual ostream& afisare(ostream&) const = 0;
    virtual void obiect () {cout << "";}
    stari getStare() {return stare;}
    void setStare(stari stare) {this->stare = stare;}
    bool getStatus() {return status;}
    void setStatus(bool status) {this->status = status;}
    int getIdUtilizatorCurent() {return idUtilizatorCurent;}
    void setIdUtilizatorCurent(int idUtilizatorCurent) {this->idUtilizatorCurent = idUtilizatorCurent;}
};


#endif
