#include "tv.h"

tv::tv(): electrocasnic(), diagonala(0){}

tv::tv(const string& t, const string& m, const string& mod,
       int an, double pret, int diag):
    electrocasnic(t,m,mod,an,pret), diagonala(diag){}

tv::tv(const tv& t1): electrocasnic(t1){
    diagonala = t1.diagonala;
}

void tv::afisare(ostream& out) const{
    electrocasnic::afisare(out);
    out << "Diagonala: " << diagonala << "\n";
}
