#include "tehnician.h"

tehnician::tehnician(): angajat(){
    nr_tipuri=0;
    nr_marci=0;
    lista_tipuri=nullptr;
    lista_marci=nullptr;
}

tehnician::tehnician(int id1, const string& n1, const string& p1, const string& cnp1, const struct data& data1, const string& oras, int nr1, int nr2, const string* tipuri, const string* marci):
    angajat(id1,n1,p1,cnp1,data1,oras){
    nr_tipuri=nr1;
    nr_marci=nr2;
    lista_tipuri=new string [nr_tipuri];
    lista_marci=new string [nr_marci];

    for(int i=0;i<nr_tipuri;i++)
        lista_tipuri[i]=tipuri[i];
    for(int i=0;i<nr_marci;i++)
        lista_marci[i]=marci[i];
}

tehnician::tehnician(const tehnician& tehn): angajat(tehn.ID,tehn.nume,tehn.prenume,tehn.cnp,tehn.data_angajarii,tehn.oras_domiciliu){
    nr_tipuri=tehn.nr_tipuri;
    nr_marci=tehn.nr_marci;
    lista_tipuri=new string [nr_tipuri];
    lista_marci=new string [nr_marci];
    for(int i=0;i<nr_tipuri;i++)
        lista_tipuri[i]=tehn.lista_tipuri[i];
    for(int i=0;i<nr_marci;i++)
        lista_marci[i]=tehn.lista_marci[i];
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

void tehnician::afisare(ostream& out) const{
    angajat::afisare(out);
    out<<"Firme din portofoliu: ";
    for(int i=0;i<nr_marci;i++)
        out<<lista_marci[i]<<" ";
    
    out<<"Tipuri de electrocasnice din portofoiu: ";
    for(int i=0;i<nr_tipuri;i++)
        out<<lista_tipuri[i];
}

double tehnician::calcul_salariu() const{
    double salariu;
    salariu=salariu_baza+((angajat::calcul_salariu())/3)*0.05*salariu_baza;
    if(oras_domiciliu!="Bucuresti")
        salariu+=400;

    return salariu;  //+partea de 2% din valoarea reparatiilor
}

tehnician::~tehnician(){
    delete [] lista_marci;
    delete [] lista_tipuri;
}