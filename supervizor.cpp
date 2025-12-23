#include "supervizor.h"

supervizor::supervizor(): angajat(){}

supervizor::supervizor(int id1, const string& n1, const string& p1, const string& cnp1, const struct data& data1, const string& oras): angajat(id1,n1,p1,cnp1,data1,oras){}

supervizor::supervizor(const supervizor& sup): angajat(sup){}

/*supervizor& supervizor::operator=(const supervizor& sup){
    angajat::operator=(sup);
    return *this;
}*/

void supervizor::afisare(ostream& out) const{
    angajat::afisare(out);
}

double supervizor::calcul_salariu() const{
    double salariu = salariu_baza;

    int vechime = calcul_vechime_ani();
    salariu += (vechime / 3) * 0.05 * salariu_baza;

    salariu += 0.2 * salariu_baza;

    if(oras_domiciliu!="Bucuresti")
        salariu += 400;

    return salariu;
}
