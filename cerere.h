#pragma once
#include <iostream>
#include <string>
#include "electrocasnic.h"

using namespace std;

class cerere{
public:
    struct timestamp{
        int zi;
        int luna;
        int an;
        int ora;
        int minut;
        int secunda;
    };

private:
    const unsigned int ID;
    static unsigned int next_id;

    string tip;
    string marca;
    string model;

    const electrocasnic* aparat;

    timestamp t;

    int complexitate;
    int durata_estimata;
    double pret_reparatie;

public:
    cerere();
    cerere(const string&, const string&, const string&, const timestamp&, int, const electrocasnic*);
    cerere(const cerere&);
    cerere& operator=(const cerere&) = delete;
    ~cerere() = default;

    unsigned int get_id() const;
    timestamp get_timestamp() const;

    string get_tip() const;
    string get_marca() const;
    string get_model() const;

    int get_complexitate() const;
    int get_durata() const;
    double get_pret() const;

    bool este_reparabila() const;

    void afisare(ostream&) const;
};