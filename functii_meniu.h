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
            //case 4:
              //  afisare_lista_elec_fara_cereri();
                //break;
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

//functii pentru meniul de angajati

static int cauta_angajat_dupa_cnp(const string& cnp){
    for(int i = 0; i < (int)lista_angajati.size(); i++){
        if(lista_angajati[i]->get_cnp() == cnp)
            return i;
    }
    return -1;
}

void adaugare_angajat(){
    int tip;
    string nume, prenume, cnp, oras;
    angajat::data d;

    cout << "Tip angajat (1-receptioner, 2-tehnician, 3-supervizor): ";
    cin >> tip;

    cout << "Nume: ";
    cin >> nume;

    cout << "Prenume: ";
    cin >> prenume;

    cout << "CNP: ";
    cin >> cnp;

    cout << "Data angajarii (zi luna an): ";
    cin >> d.zi >> d.luna >> d.an;

    cout << "Oras domiciliu: ";
    cin >> oras;

    try{
        angajat* a = nullptr;

        if(tip == 1){
            a = new receptioner(0, nume, prenume, cnp, d, oras, 0, nullptr);
        }
        else if(tip == 2){
            int nr_spec;
            cout << "Numar specializari: ";
            cin >> nr_spec;

            pair<string,string>* spec = nullptr;

            if(nr_spec > 0){
                spec = new pair<string,string>[nr_spec];

                for(int i = 0; i < nr_spec; i++){
                    cout << "Specializare " << (i+1) << " tip: ";
                    cin >> spec[i].first;
                    cout << "Specializare " << (i+1) << " marca: ";
                    cin >> spec[i].second;
                }
            }

            a = new tehnician(0, nume, prenume, cnp, d, oras, nr_spec, spec);

            delete[] spec;
        }
        else if(tip == 3){
            a = new supervizor(0, nume, prenume, cnp, d, oras);
        }
        else{
            throw invalid_argument("Tip angajat invalid");
        }

        lista_angajati.push_back(a);
        cout << "Angajat adaugat.\n";
    }
    catch(const exception& e){
        cout << "Eroare: " << e.what() << "\n";
    }
}

void modificare_angajat(){
    string cnp;
    cout << "Introdu CNP: ";
    cin >> cnp;

    int poz = cauta_angajat_dupa_cnp(cnp);
    if(poz == -1){
        cout << "Nu exista angajat cu acest CNP.\n";
        return;
    }

    int opt;
    cout << "Ce modifici? (1-nume, 2-prenume, 3-oras): ";
    cin >> opt;

    if(opt == 1){
        string nume_nou;
        cout << "Nume nou: ";
        cin >> nume_nou;
        lista_angajati[poz]->set_nume(nume_nou);
        cout << "Modificare realizata.\n";
    }
    else if(opt == 2){
        string prenume_nou;
        cout << "Prenume nou: ";
        cin >> prenume_nou;
        lista_angajati[poz]->set_prenume(prenume_nou);
        cout << "Modificare realizata.\n";
    }
    else if(opt == 3){
        string oras_nou;
        cout << "Oras nou: ";
        cin >> oras_nou;
        lista_angajati[poz]->set_oras(oras_nou);
        cout << "Modificare realizata.\n";
    }
    else{
        cout << "Optiune invalida.\n";
    }
}

void stergere_angajat(){
    string cnp;
    cout << "Introdu CNP: ";
    cin >> cnp;

    int poz = cauta_angajat_dupa_cnp(cnp);
    if(poz == -1){
        cout << "Nu exista angajat cu acest CNP.\n";
        return;
    }

    delete lista_angajati[poz];
    lista_angajati.erase(lista_angajati.begin() + poz);

    cout << "Angajat sters.\n";
}

void afisare_lista_angajati(){
    if(lista_angajati.size() == 0){
        cout << "Nu exista angajati.\n";
        return;
    }

    for(int i = 0; i < (int)lista_angajati.size(); i++){
        lista_angajati[i]->afisare(cout);
        cout << "Salariu curent: " << lista_angajati[i]->calcul_salariu() << "\n";
        cout << "---------------------\n";
    }
}

void afisare_date_angajat(){
    string cnp;
    cout << "Introdu CNP: ";
    cin >> cnp;

    int poz = cauta_angajat_dupa_cnp(cnp);
    if(poz == -1){
        cout << "Nu exista angajat cu acest CNP.\n";
        return;
    }

    lista_angajati[poz]->afisare(cout);
    cout << "Salariu curent: " << lista_angajati[poz]->calcul_salariu() << "\n";
}

//functii pentru meniu electrocasnice

static int cauta_electrocasnic(const string& tip,
                               const string& marca,
                               const string& model)
{
    for(int i = 0; i < (int)lista_electrocasnice.size(); i++){
        if(lista_electrocasnice[i]->get_tip() == tip &&
           lista_electrocasnice[i]->get_marca() == marca &&
           lista_electrocasnice[i]->get_model() == model)
            return i;
    }
    return -1;
}

void adaugare_electrocasnic(){
    int tip;
    string marca, model;
    int an;
    double pret;

    cout << "Tip electrocasnic (1-TV, 2-Frigider, 3-MasinaSpalat): ";
    cin >> tip;

    cout << "Marca: ";
    cin >> marca;

    cout << "Model: ";
    cin >> model;

    cout << "An fabricatie: ";
    cin >> an;

    cout << "Pret catalog: ";
    cin >> pret;

    try{
        electrocasnic* e = nullptr;

        if(tip == 1){
            int diagonala;
            cout << "Diagonala TV: ";
            cin >> diagonala;

            e = new tv("TV", marca, model, an, pret, diagonala);
        }
        else if(tip == 2){
            int cong;
            cout << "Are congelator (1-da / 0-nu): ";
            cin >> cong;

            e = new frigider("Frigider", marca, model, an, pret, cong == 1);
        }
        else if(tip == 3){
            int capacitate;
            cout << "Capacitate (kg): ";
            cin >> capacitate;

            e = new masina_spalat("MasinaSpalat", marca, model, an, pret, capacitate);
        }
        else{
            throw invalid_argument("tip electrocasnic invalid");
        }

        lista_electrocasnice.push_back(e);
        cout << "Electrocasnic adaugat.\n";
    }
    catch(const exception& ex){
        cout << "Eroare: " << ex.what() << "\n";
    }
}

void stergere_electrocasnic(){
    string tip, marca, model;

    cout << "Tip: ";
    cin >> tip;
    cout << "Marca: ";
    cin >> marca;
    cout << "Model: ";
    cin >> model;

    int poz = cauta_electrocasnic(tip, marca, model);
    if(poz == -1){
        cout << "Electrocasnic inexistent.\n";
        return;
    }

    delete lista_electrocasnice[poz];
    lista_electrocasnice.erase(lista_electrocasnice.begin() + poz);

    cout << "Electrocasnic sters.\n";
}

void afisare_lista_electrocasnice(){
    if(lista_electrocasnice.size() == 0){
        cout << "Nu exista electrocasnice.\n";
        return;
    }

    for(int i = 0; i < (int)lista_electrocasnice.size(); i++){
        lista_electrocasnice[i]->afisare(cout);
        cout << "----------------------\n";
    }
}