#include "tehnician.h"

tehnician::tehnician(): angajat(){
    nr_specializari = 0;
    specializari = nullptr;
}

tehnician::tehnician(const string& n1, const string& p1, const string& cnp1, const struct data& data1, const string& oras, int nrSpec, const pair<string,string>* listaSpec):
    angajat(n1,p1,cnp1,data1,oras){
    nr_specializari = nrSpec;

    if(nr_specializari > 0){
        specializari = new pair<string,string>[nr_specializari];
        for(int i = 0; i < nr_specializari; i++)
            specializari[i] = listaSpec[i];
    } 
    else{
        specializari = nullptr;
    }
}

tehnician::tehnician(const tehnician& tehn): angajat(tehn.nume,tehn.prenume,tehn.cnp,tehn.data_angajarii,tehn.oras_domiciliu){
    nr_specializari = tehn.nr_specializari;

    if(nr_specializari > 0){
        specializari = new pair<string,string>[nr_specializari];
        for(int i = 0; i < nr_specializari; i++)
            specializari[i] = tehn.specializari[i];
    }
    else{
        specializari = nullptr;
    }
}

/*tehnician& tehnician::operator=(const tehnician& tehn){
    ID=tehn.ID;
    nume=tehn.nume;
    prenume=tehn.prenume;
    cnp=tehn.cnp;
    data_angajarii=tehn.data_angajarii;
    oras_domiciliu=tehn.oras_domiciliu;
    if(nr_marci!=tehn.nr_marci && lista_marci!=tehn.lista_marci){
        nr_marci=tehn.nr_marci;
        delete [] lista_marci;
        lista_marci=new string [nr_marci];
        for(int i=0;i<nr_marci;i++)
            lista_marci[i]=tehn.lista_marci[i];
    }

    if(nr_tipuri!=tehn.nr_tipuri && lista_tipuri!=tehn.lista_tipuri){
        nr_tipuri=tehn.nr_tipuri;
        delete [] lista_tipuri;
        lista_tipuri=new string [nr_tipuri];
        for(int i=0;i<nr_tipuri;i++)
            lista_tipuri[i]=tehn.lista_tipuri[i];
    }

    return *this;
}*/

double tehnician::calcul_salariu() const{
    double salariu = salariu_baza;

    int vechime = calcul_vechime_ani();
    int bonusuri = vechime / 3;
    salariu += bonusuri * 0.05 * salariu_baza;

    if(oras_domiciliu != "Bucuresti")
        salariu += 400;

    // +2% din valoarea reparatiilor se va adăuga ulterior când ai mecanismul implementat
    return salariu;
}

void tehnician::afisare(ostream& out) const {
    angajat::afisare(out);

    out << "Specializari (tip, marca):\n";
    for(int i = 0; i < nr_specializari; i++)
        out << "  - " << specializari[i].first << " " << specializari[i].second << "\n";
}

bool tehnician::poateRepara(const string& tip, const string& marca) const {
    for(int i = 0; i < nr_specializari; i++)
        if(specializari[i].first == tip && specializari[i].second == marca)
            return true;
    return false;
}

tehnician::~tehnician() {
    delete[] specializari;
}