#include "masina_spalat.h"

masina_spalat::masina_spalat(): electrocasnic(), capacitate(0){}

masina_spalat::masina_spalat(const string& t, const string& m, const string& mod,
                             int an, double pret, int cap):
    electrocasnic(t,m,mod,an,pret), capacitate(cap){}

masina_spalat::masina_spalat(const masina_spalat& ms): electrocasnic(ms){
    capacitate = ms.capacitate;
}

void masina_spalat::afisare(ostream& out) const{
    electrocasnic::afisare(out);
    out << "Capacitate: " << capacitate << " kg\n";
}
