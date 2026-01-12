#include "cerere.h"
#include <stdexcept>

unsigned int cerere::next_id = 1;

cerere::cerere(): ID(next_id++), tip(), marca(), model(), aparat(nullptr), t{0,0,0,0,0,0}, complexitate(0), durata_estimata(0), pret_reparatie(0){}

void validare_timestamp(const cerere::timestamp& ts){
    if(ts.an <= 0) throw invalid_argument("timestamp invalid");
    if(ts.luna < 1 || ts.luna > 12) throw invalid_argument("timestamp invalid");
    if(ts.zi < 1 || ts.zi > 31) throw invalid_argument("timestamp invalid");
    if(ts.ora < 0 || ts.ora > 23) throw invalid_argument("timestamp invalid");
    if(ts.minut < 0 || ts.minut > 59) throw invalid_argument("timestamp invalid");
    if(ts.secunda < 0 || ts.secunda > 59) throw invalid_argument("timestamp invalid");
}

cerere::cerere(const string& tip1, const string& marca1, const string& model1, const timestamp& ts, int comp, const electrocasnic* ap):
    ID(next_id++), tip(tip1), marca(marca1), model(model1), aparat(ap), t(ts), complexitate(comp), durata_estimata(0), pret_reparatie(0)
{
    validare_timestamp(t);

    if(tip.size() == 0 || marca.size() == 0 || model.size() == 0)
        throw invalid_argument("campuri lipsa");

    if(comp < 0 || comp > 5)
        throw invalid_argument("complexitate invalida");

    if(aparat == nullptr){
        complexitate = 0;
        durata_estimata = 0;
        pret_reparatie = 0;
    } else {
        if(complexitate == 0)
            throw invalid_argument("complexitate 0 pentru cerere reparabila");

        int vechime = t.an - aparat->get_an();
        if(vechime < 0) vechime = 0;

        durata_estimata = vechime * complexitate;
        pret_reparatie = aparat->get_pret() * durata_estimata;
    }
}

cerere::cerere(const cerere& c):
    ID(c.ID)
{
    tip = c.tip;
    marca = c.marca;
    model = c.model;
    aparat = c.aparat;
    t = c.t;
    complexitate = c.complexitate;
    durata_estimata = c.durata_estimata;
    pret_reparatie = c.pret_reparatie;
}

unsigned int cerere::get_id() const{
    return ID;
}

cerere::timestamp cerere::get_timestamp() const{
    return t;
}

string cerere::get_tip() const{
    return tip;
}

string cerere::get_marca() const{
    return marca;
}

string cerere::get_model() const{
    return model;
}

int cerere::get_complexitate() const{
    return complexitate;
}

int cerere::get_durata() const{
    return durata_estimata;
}

double cerere::get_pret() const{
    return pret_reparatie;
}

bool cerere::este_reparabila() const{
    return aparat != nullptr;
}

void cerere::afisare(ostream& out) const{
    out << "Cerere ID: " << ID << "\n";
    out << "Timestamp: " << t.zi << "." << t.luna << "." << t.an
        << " " << t.ora << ":" << t.minut << ":" << t.secunda << "\n";
    out << "Aparat: " << tip << " " << marca << " " << model << "\n";

    if(aparat != nullptr){
        aparat->afisare(out);
        out << "Complexitate: " << complexitate << "\n";
        out << "Durata estimata: " << durata_estimata << "\n";
        out << "Pret estimat: " << pret_reparatie << "\n";
    } else {
        out << "Nereparabil\n";
        out << "Complexitate: 0\n";
        out << "Durata estimata: 0\n";
        out << "Pret estimat: 0\n";
    }
}
