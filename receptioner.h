#pragma once
#include "angajat.h"

class receptioner: public angajat{
    int nr_id;
    int* lista_ID;

public:

    receptioner();
    receptioner(const int, const string&, const string&, const string&, const struct data&, const string&, const int, const int*);
    receptioner(const receptioner&);
    receptioner& operator=(const receptioner&)=delete;
    ~receptioner();

    void adauga_cerere(int);

    void afisare(ostream&) const override;
    double calcul_salariu() const override;
};