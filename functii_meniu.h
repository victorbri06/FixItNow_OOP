#include<iostream>
#include <vector>
#include <string>

#include "angajat.h"
#include "electrocasnic.h"
#include "cerere.h"

using namespace std;

void adaugare_angajat();
void modificare_angajat();
void stergere_angajat();
void afisare_lista_angajati();
void afisare_date_angajat();

void afisare_meniu_angajati();
void meniu_angajati();
void afis_meniu_principal();
void afisare_meniu_electrocasnice();
void meniu_electrocasnice();
void adaugare_electrocasnic();
void stergere_electrocasnic();
void afisare_lista_electrocasnice();
void afisare_lista_elec_fara_cereri();

void afisare_meniu_cereri();
void meniu_cereri();
void afisare_lista_cereri_valide();
void afisare_lista_cereri_invalide();

extern vector<angajat*> lista_angajati;
extern vector<electrocasnic*> lista_electrocasnice;
extern vector<cerere*> lista_cereri;
extern vector<string> lista_cereri_invalide;