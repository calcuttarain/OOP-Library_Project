#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "obiectDeImprumutat.h"
#include "carte.h"
#include "utilizator.h"
#include "bibliotecar.h"
#include "sala.h"
#include "film.h"
#include "revistaCuFilm.h"
using namespace std;

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
                break;
            }
            case 2:{
                Utilizator U;
                cin >> U;
                vectorUtilizatori[cu] = U;
                cu++;
                break;
            }
            case 3:{
                Bibliotecar B;
                cin >> B;
                vectorBibliotecari[cb] = B;
                cb++;
                break;
            }
            case 4:{
                Sala S;
                cin >> S;
                vectorSali[cs] = S;
                cs++;
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
                            break;
                        }
                        case 4:{
                            ok1 = 0;
                            break;
                        }
                        default:{
                            cout << "Comanda nerecunoscuta!";
                            break;
                        }
                    }
                }
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
                            break;
                        }
                        case 5:{
                            ok3 = 0;
                            break;
                        }
                        default:{
                            cout << "Comanda invalida!";
                        }
                    }
                }
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
                            break;
                        }
                        case 2:{
                            for (int i = 0; i<cs; i++)
                                cout << "Sala numarul " << vectorSali[i].getNrSala() << " are " << int(vectorSali[i]) - vectorSali[i].getNrLocuriOcupate() << " locuri disponibile.\n";
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
                            break;
                        }
                        case 4:{
                            ok4 = 0;
                            break;
                        }
                        default:{
                            cout << "Comanda invalida!";
                        }
                    }
                }
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
                            break;
                        }
                        case 2:{
                            ok5 = 0;
                            break;
                        }
                    }
                }
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
                            break;
                        }
                        case 2:{
                            ok6 = 0;
                            break;
                        }
                        default:{
                            cout << "Optiune inexistenta\n";
                        }
                    }
                }
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
                            break;
                        }
                        case 2:{
                            ok7 = 0;
                            break;
                        }
                    }
                }
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
                            break;
                        }
                        case 3:{
                            ok8 = 0;
                            break;
                        }
                    }
                }
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
