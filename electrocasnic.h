#pragma once
#include<iostream>
#include<string>

using namespace std;

class electrocasnic{
protected:
    string tip;
    string marca;
    string model;
    int an_fabricatie;
    double pret_catalog;

public:
    electrocasnic();
    electrocasnic(const string&, const string&, const string&, int, double);
    electrocasnic(const electrocasnic&);
    electrocasnic& operator=(const electrocasnic&) = delete;
    virtual ~electrocasnic() = default;

    string get_tip() const;
    string get_marca() const;
    string get_model() const;
    int get_an() const;
    double get_pret() const;

    virtual void afisare(ostream&) const;
};
