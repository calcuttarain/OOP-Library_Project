//
//  bibliotecar.h
//  131_Pistol_Tudor_Proiect1
//
//  Created by Tudor Pistol on 20.04.2023.
//

#ifndef bibliotecar_h
#define bibliotecar_h
using namespace std;

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


#endif /* bibliotecar_h */
