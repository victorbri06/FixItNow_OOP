#include "angajat.h"

unsigned int angajat::next_id = 1;

angajat::angajat() :
    ID(next_id++),
    nume(),
    prenume(),
    cnp(),
    data_angajarii{0,0,0},
    oras_domiciliu(""){
}

angajat::angajat(int id1, const string& n1, const string& p1,
                 const string& cnp1, const struct data& data1,
                 const string& oras):
    ID(id1),
    data_angajarii(data1),
    oras_domiciliu(oras)
{
    if(n1.size() < 3 || n1.size() > 30 || p1.size() < 3 || p1.size() > 30)
        throw invalid_argument("numele sau prenumele sunt prea lungi sau prea scurte");

    nume = n1;
    prenume = p1;

    if(!validare_cnp(cnp1))
        throw invalid_argument("CNP invalid");

    if(calcul_varsta_ani(cnp1) < 16)
        throw invalid_argument("Persoana are sub 16 ani");

    cnp = cnp1;
}

angajat::angajat(const angajat& a): ID(a.ID){
    nume = a.nume;
    prenume = a.prenume;
    cnp = a.cnp;
    data_angajarii = a.data_angajarii;
    oras_domiciliu = a.oras_domiciliu;
}

int angajat::calcul_vechime_ani() const{
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    int ani = now->tm_year + 1900 - data_angajarii.an;
    if(ani < 0) ani = 0;
    return ani;
}

int angajat::calcul_varsta_ani(const string& c) const{
    // presupunem format valid deja
    int an = stoi(c.substr(1,2));
    int luna = stoi(c.substr(3,2));
    int zi = stoi(c.substr(5,2));

    int secol = (c[0]=='1' || c[0]=='2') ? 1900 : 2000;
    an += secol;

    time_t t = time(nullptr);
    tm* now = localtime(&t);

    int age = now->tm_year + 1900 - an;
    return age;
}

bool angajat::validare_cnp(const string& c){
    if(c.size() != 13) return false;

    static int coef[] = {2,7,9,1,4,6,3,5,8,2,7,9};
    int sum = 0;

    for(int i = 0; i < 12; i++){
        if(!isdigit(c[i])) return false;
        sum += (c[i] - '0') * coef[i];
    }

    if(!isdigit(c[12])) return false;

    int check = sum % 11;
    if(check == 10) check = 1;

    return check == (c[12] - '0');
}

string angajat::get_cnp() const{
    return cnp;
}

void angajat::set_nume(const string& n){
    nume = n;
}

void angajat::set_prenume(const string& n){
    prenume = n;
}

void angajat::set_oras(const string& n){
    oras_domiciliu=n;
}

void angajat::afisare(ostream& out) const{
    out<<"ID: "<<ID<<" | "<<nume<<" "<<prenume<<" | CNP: "<<cnp<<" | Oras: "<<oras_domiciliu<<"\n";
}
