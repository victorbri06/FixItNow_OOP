#include "receptioner.h"

receptioner::receptioner():angajat(){
    nr_id=0;
    lista_ID=nullptr;
}

receptioner::receptioner(const int id1, const string& n1, const string& p1, const string& cnp1, const struct data& data1, const string& oras1, const int nr1, const int* id_list):
    angajat(id1,n1,p1,cnp1,data1,oras1){
    nr_id=nr1;
    lista_ID=new int [nr_id];

    for(int i=0;i<nr_id;i++)
        lista_ID[i]=id_list[i];
}

/*receptioner& receptioner::operator=(const receptioner& recept){
    ID=recept.ID;
    nume=recept.nume;
    prenume=recept.prenume;
    cnp=recept.cnp;
    data_angajarii=recept.data_angajarii;
    oras_domiciliu=recept.oras_domiciliu;
    if(nr_id!=recept.nr_id && lista_ID!=recept.lista_ID){
        nr_id=recept.nr_id;
        delete [] lista_ID;
        lista_ID=new int [nr_id];
        for(int i=0;i<nr_id;i++)
            lista_ID[i]=recept.lista_ID[i];
    }

    return *this;
}*/

receptioner::receptioner(const receptioner& recept): angajat(recept.ID,recept.nume,recept.prenume,recept.cnp,recept.data_angajarii,recept.oras_domiciliu){
    nr_id=recept.nr_id;
    lista_ID=new int [nr_id];
    for(int i=0;i<nr_id;i++)
        lista_ID[i]=recept.lista_ID[i];
}

void receptioner::afisare(ostream& out) const{
    angajat::afisare(out);
    out<<"Numar id-uri inregistrate: "<<nr_id<<endl;
    for(int i=0;i<nr_id;i++)
        out<<lista_ID[i]<<" ";
    out<<endl;
}

double receptioner::calcul_salariu() const{
    double salariu = salariu_baza;

    int vechime = calcul_vechime_ani();
    int bonusuri = vechime / 3;
    salariu += bonusuri * 0.05 * salariu_baza;

    if(oras_domiciliu!="Bucuresti")
        salariu += 400;

    return salariu;
}

receptioner::~receptioner(){
    delete [] lista_ID;
}

void receptioner::adauga_cerere(int n){
    nr_id++;
    int* cop=new int [nr_id];
    for(int i=0;i<nr_id-1;i++)
        cop[i]=lista_ID[i];
    cop[nr_id-1]=n;

    delete [] lista_ID;
    lista_ID=new int [nr_id];
    for(int i=0;i<nr_id;i++)
        lista_ID[i]=cop[i];
    
    delete [] cop;
}