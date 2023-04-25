#ifndef revistaCuFilm_h
#define revistaCuFilm_h
#include "film.h"
#include "carte.h"
using namespace std;

class revistaCuFilm : public Carte, public Film{
    int numarRevista;
    string numeRevista;
public:
    revistaCuFilm();
    revistaCuFilm(int numarRevista, string numeRevista, string titlu, char *autor, int anAparitie, string nume, string regizor, vector <string> actori, int an, bool status, stari stare, int idUtilizatorCurent);
    revistaCuFilm(revistaCuFilm &r);
    ~revistaCuFilm() {}
    
    friend istream &operator >> (istream &, revistaCuFilm &);
    friend ostream &operator << (ostream &, revistaCuFilm&);
    virtual istream& inregistrare (istream&);
    virtual ostream& afisare (ostream&) const;
    virtual void obiect () {cout << "Categoria: Revistă cu film" << endl; }
};

#endif 
