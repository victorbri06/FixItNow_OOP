#include "frigider.h"

frigider::frigider(): electrocasnic(), are_congelator(false){}

frigider::frigider(const string& t, const string& m, const string& mod,
                   int an, double pret, bool cong):
    electrocasnic(t,m,mod,an,pret), are_congelator(cong){}

frigider::frigider(const frigider& f): electrocasnic(f){
    are_congelator = f.are_congelator;
}

void frigider::afisare(ostream& out) const{
    electrocasnic::afisare(out);
    out << "Congelator: " << (are_congelator ? "DA" : "NU") << "\n";
}
