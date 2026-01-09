#ifndef ANGAJAT_H
#define ANGAJAT_H

#include<iostream>
#include<string>
#include<ctime>
#include<stdexcept>

#define salariu_baza 4000

using namespace std;

class angajat{
protected:
    const unsigned int ID;
    string nume;
    string prenume;
    string cnp;

public:

    struct data{
        int zi;
        int luna;
        int an;
    };

    data data_angajarii;
    string oras_domiciliu;

    static unsigned int next_id;   // generator ID unic

    angajat();
    angajat(int, const string&, const string&, const string&, const struct data&, const string&);
    angajat(const angajat&);
    angajat& operator=(const angajat&)=delete;
    virtual ~angajat()=default;

    void set_nume(const string&);
    void set_prenume(const string&);
    void set_oras(const string&);

    virtual void afisare(ostream&) const;
    virtual double calcul_salariu() const = 0;

    int calcul_vechime_ani() const;
    int calcul_varsta_ani(const string&) const;

    bool validare_cnp(const string&);
};

#endif
