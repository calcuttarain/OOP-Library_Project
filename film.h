#ifndef film_h
#define film_h
#include <iostream>
#include <string>
#include <vector>
#include "obiectDeImprumutat.h"

class Film : virtual public obiectDeImprumutat{
protected:
    string nume;
    string regizor;
    vector <string> actori;
    int an;
public:
    Film();
    Film(string nume, string regizor, vector <string> actori, int an, bool status, stari stare, int idUtilizatorCurent);
    Film(const Film &f);
    ~Film() {}
    
    Film &operator = (const Film &);
    friend istream &operator >> (istream&, Film &);
    friend ostream &operator << (ostream&, Film &);
    virtual istream& inregistrare(istream&);
    virtual ostream& afisare (ostream&) const;
    virtual void obiect () {cout << "Categoria: Film" << endl;}
};

#endif /* film_h */
