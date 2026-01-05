#include "electrocasnic.h"

electrocasnic::electrocasnic():
    tip(), marca(), model(), an_fabricatie(0), pret_catalog(0){}

electrocasnic::electrocasnic(const string& t, const string& m,
                             const string& mod, int an, double pret):
    tip(t), marca(m), model(mod), an_fabricatie(an), pret_catalog(pret){}

electrocasnic::electrocasnic(const electrocasnic& e){
    tip = e.tip;
    marca = e.marca;
    model = e.model;
    an_fabricatie = e.an_fabricatie;
    pret_catalog = e.pret_catalog;
}

string electrocasnic::get_tip() const{
    return tip;
}

string electrocasnic::get_marca() const{
    return marca;
}

string electrocasnic::get_model() const{
    return model;
}

int electrocasnic::get_an() const{
    return an_fabricatie;
}

double electrocasnic::get_pret() const{
    return pret_catalog;
}

void electrocasnic::afisare(ostream& out) const{
    out << tip << " " << marca << " " << model
        << " | an: " << an_fabricatie
        << " | pret: " << pret_catalog << "\n";
}
