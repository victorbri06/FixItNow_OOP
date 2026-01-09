#include "receptioner.h"
#include "supervizor.h"
#include "tehnician.h"
#include "frigider.h"
#include "masina_spalat.h"
#include "tv.h"
#include "functii_meniu.h"

#include <vector>
#include <fstream>


//variabile globale
vector<angajat*> lista_angajati;
vector<electrocasnic*> lista_electrocasnice;


//functie de impartire a liniilor in elemente de tip vector<string>
vector<string> split(const string& linie, char delim){
    vector<string> rez;
    string aux;

    for(int i = 0; i < (int)linie.size(); i++){
        if(linie[i] == delim){
            rez.push_back(aux);
            aux.clear();
        } else {
            aux.push_back(linie[i]);
        }
    }
    rez.push_back(aux);
    return rez;
}

int main(){
    //incarcare date din fisiere (cu verificari de erori)
    // ===================== CITIRE ANGAJATI =====================
    ifstream fin_ang("tests/angajati_in.csv");
    string linie;
    int nr_linie = 0;

    while(getline(fin_ang, linie)){
        nr_linie++;
        if(linie.size() == 0)
            continue;

        try{
            vector<string> c = split(linie, ',');

            string tip = c[0];
            string nume = c[1];
            string prenume = c[2];
            string cnp = c[3];
            angajat::data d;
            d.zi = stoi(c[4]);
            d.luna = stoi(c[5]);
            d.an = stoi(c[6]);
            string oras = c[7];
            string extra = c[8];

            angajat* a = nullptr;

            if(tip == "receptioner"){
                a = new receptioner(0, nume, prenume, cnp, d, oras, 0, nullptr);
            }
            else if(tip == "supervizor"){
                a = new supervizor(0, nume, prenume, cnp, d, oras);
            }
            else if(tip == "tehnician"){
                vector<pair<string,string>> spec;

                if(extra != "-"){
                    vector<string> p = split(extra, '|');
                    for(int i = 0; i < (int)p.size(); i++){
                        vector<string> kv = split(p[i], ':');
                        spec.push_back(make_pair(kv[0], kv[1]));
                    }
                }

                a = new tehnician(0, nume, prenume, cnp, d, oras,
                                  spec.size(), spec.data());
            }
            else{
                throw invalid_argument("tip angajat necunoscut");
            }

            lista_angajati.push_back(a);
        }
        catch(const exception& e){
            cout << "Eroare angajat linia " << nr_linie
                 << ": " << e.what() << "\n";
        }
    }

    fin_ang.close();

    // ===================== CITIRE ELECTROCASNICE =====================
    ifstream fin_el("tests/electrocasnice.csv");
    nr_linie = 0;

    while(getline(fin_el, linie)){
        nr_linie++;
        if(linie.size() == 0)
            continue;

        try{
            vector<string> c = split(linie, ',');

            string tip = c[0];
            string marca = c[1];
            string model = c[2];
            int an = stoi(c[3]);
            double pret = stod(c[4]);
            string extra = c[5];

            electrocasnic* e = nullptr;

            if(tip == "TV"){
                int diag = stoi(extra);
                e = new tv(tip, marca, model, an, pret, diag);
            }
            else if(tip == "Frigider"){
                bool cong = (extra == "1");
                e = new frigider(tip, marca, model, an, pret, cong);
            }
            else if(tip == "MasinaSpalat"){
                int cap = stoi(extra);
                e = new masina_spalat(tip, marca, model, an, pret, cap);
            }
            else{
                throw invalid_argument("tip electrocasnic necunoscut");
            }

            lista_electrocasnice.push_back(e);
        }
        catch(const exception& e){
            cout << "Eroare electrocasnic linia " << nr_linie
                 << ": " << e.what() << "\n";
        }
    }

    fin_el.close();


    //meniu
    int opt;
    while(true){
    afis_meniu_principal();
    cin >> opt;

    switch(opt){
        case 1:
            meniu_angajati();
            break;
        case 2:
            meniu_electrocasnice();
            break;
        case 3:
            meniu_cereri();
            break;
        case 4:
            meniu_raportari();
            break;
        case 0:
            return;
    }
    }
}