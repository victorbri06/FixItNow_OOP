#include "angajat.h"

angajat::angajat(): ID(1234),nume(),prenume(),data_angajarii(),oras_domiciliu(){

}//de vazut ce fac cu id dupa ce pun intrebarea la curs

angajat::angajat( int id1, const string& n1, const string& p1, const string& cnp1, const struct data& data1, const string& oras):
    ID(id1), data_angajarii(data1), oras_domiciliu(oras){
    if(n1.size()>30 || n1.size()<3 || p1.size()>30 || p1.size()<3)
        throw invalid_argument("numele sau prenumele sunt prea lungi sau prea scurte");
    else{
        nume=n1;
        prenume=p1;
    }

    if(calcul_varsta_ani(cnp1)<16)
        throw invalid_argument("Varsta minima este 16 ani");

    if(validare_cnp(cnp1)==false)
        throw invalid_argument("CNP-ul nu este valid");
    else
        cnp=cnp1;
};

//constructor copiere, operator=,destructor

void angajat::afisare(ostream& out) const{
    out<<"ID: "<<ID<<endl;
    out<<"Nume: "<<nume<<" "<<prenume<<endl;
    out<<"CNP: "<<cnp<<endl;
    out<<"Data angajarii:  "<<data_angajarii.zi<<"/"<<data_angajarii.luna<<"/"<<data_angajarii.an<<endl;
    out<<"Oras domiciliu: "<<oras_domiciliu<<endl;
}

int angajat::calcul_vechime_ani() const{
    time_t t = std::time(nullptr);
    tm *now = std::localtime(&t);

    int ziC = now->tm_mday;
    int lunaC = now->tm_mon + 1;
    int anC = now->tm_year + 1900;

    int ziA = data_angajarii.zi;
    int lunaA = data_angajarii.luna;
    int anA = data_angajarii.an;

    angajat::data vechime;

    if (ziC < ziA) {
        static int zileLuna[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        ziC += zileLuna[(lunaC - 2 + 12) % 12];
        lunaC -= 1;
    }
    vechime.zi = ziC - ziA;

    if (lunaC < lunaA) {
        lunaC += 12;
        anC -= 1;
    }
    vechime.luna = lunaC - lunaA;
    vechime.an = anC - anA;

    return vechime.an;
}

int angajat::calcul_varsta_ani(const string& cnp) const{
    time_t t = std::time(nullptr);
    tm *now = std::localtime(&t);

    int ziC = now->tm_mday;
    int lunaC = now->tm_mon + 1;
    int anC = now->tm_year + 1900;

    int ziA = (cnp[5]-'0')*10 + (cnp[6]-'0');
    int lunaA = (cnp[3]-'0')*10 + (cnp[4]-'0');
    int anA=0;
    if(cnp[0]=='5' || cnp[0]=='6')
        anA = 2000 + (cnp[1]-'0')*10 + (cnp[2]-'0');
    if(cnp[0]=='1' || cnp[0]=='2')
        anA = 1900 + (cnp[1]-'0')*10 + (cnp[2]-'0');
    
    angajat::data varsta;

    if (ziC < ziA) {
        static int zileLuna[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        ziC += zileLuna[(lunaC - 2 + 12) % 12];
        lunaC -= 1;
    }
    varsta.zi = ziC - ziA;

    if (lunaC < lunaA) {
        lunaC += 12;
        anC -= 1;
    }
    varsta.luna = lunaC - lunaA;
    varsta.an = anC - anA;

    return varsta.an;
}

bool angajat::validare_cnp(const string& cnp){
    if (cnp.size() != 13) return false;

    static int control[] = {2,7,9,1,4,6,3,5,8,2,7,9};
    int sum = 0;
    for (int i = 0; i < 12; ++i)
        sum += (cnp[i] - '0') * control[i];
    int check = sum % 11;
    if (check == 10) check = 1;

    return check == (cnp[12] - '0');
}

void angajat::set_nume(const string& n){
    nume=n;
}

void angajat::set_prenume(const string& n){
    prenume=n;
}

void angajat::set_oras(const string& n){
    oras_domiciliu=n;
}