#include<iostream>

using namespace std;

//meniul principal
void afis_meniu_principal(){
    cout<<"-------------MENIU PRINCIPAL------------"<<endl<<endl;
    cout<<"Apasati tasta aferenta submeniului pe care doriti sa il accesati"<<endl<<endl;
    cout<<"1. Meniu angajati"<<endl<<"2. Meniu electrocasnice"<<endl;
    cout<<"3. Meniu cereri"<<endl<<"4. Meniu raportari"<<endl<<endl;
    cout<<"Apasati tasta 0 daca doriti sa parasiti meniul";
}

//functii pentru submeniuri:
void meniu_angajati(){
    int opt;

    while(true){
        afisare_meniu_angajati();
        cin >> opt;

        switch(opt){
            case 1:
                adaugare_angajat();
                break;
            case 2:
                modificare_angajat();
                break;
            case 3:
                stergere_angajat();
                break;
            case 4:
                afisare_lista_angajati();
                break;
            case 5:
                afisare_date_angajat();
                break;
            case 0:
                return;
        }
    }
}

void meniu_electrocasnice(){
    int opt;

    while(true){
        afisare_meniu_electrocasnice();
        cin>>opt;

        switch(opt){
            case 1:
                adaugare_electrocasnic();
                break;
            case 2:
                stergere_electrocasnic();
                break;
            case 3:
                afisare_lista_electrocasnice();
                break;
            case 4:
                afisare_lista_elec_fara_cereri();
                break;
            case 0:
                return;
        }
    }
}

void meniu_cereri(){

}

void meniu_raportari(){

}

//functii pentru fiecare submeniu

void afisare_meniu_angajati(){
    cout<<"MENIU ANGAJATI"<<endl<<endl;
    cout<<"1. Adaugare angajat"<<endl;
    cout<<"2. Modificare date angajat"<<endl;
    cout<<"3. Stergere angajat"<<endl;
    cout<<"4. Afisare lista angajati"<<endl;
    cout<<"5. Afisare date angajat(dupa CNP)"<<endl<<endl;
    cout<<"pentru a te intoarce inapoi, apasa tasta 0";
}

void afisare_meniu_electrocasnice(){
    cout<<"MENIU ELECTROCASNICE"<<endl<<endl;
    cout<<"1. Adaugare electrocasnic(marca/model) din lista"<<endl;
    cout<<"2. Stergere electrocasnic din lista"<<endl;
    cout<<"3. Afisare lista electrocasnice cu detalii"<<endl;
    cout<<"4. Afisare modele care nu au aparut in cereri"<<endl<<endl;
    cout<<"pentru a te intoarce inapoi, apasa tasta 0";
}