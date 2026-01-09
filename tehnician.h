#pragma once
#include "angajat.h"
#include <utility>

class tehnician: public angajat{
    int nr_specializari;
    pair<string,string>* specializari;

public:

    tehnician();
    tehnician(int, const string&, const string&, const string&, const struct data&, const string&, int, const pair<string,string>*);
    tehnician(const tehnician&);
    tehnician& operator=(const tehnician&)=delete;
    ~tehnician();

    virtual void afisare(ostream&) const override;
    virtual double calcul_salariu() const override; //mai trebuie sa implementez partea de 2% din valoarea reparatiilor efectuate
    bool poateRepara(const string&, const string&) const;
};