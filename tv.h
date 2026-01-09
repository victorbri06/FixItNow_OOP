#pragma once
#include "electrocasnic.h"

class tv: public electrocasnic{
    int diagonala;

public:
    tv();
    tv(const string&, const string&, const string&, int, double, int);
    tv(const tv&);
    tv& operator=(const tv&) = delete;
    ~tv() override = default;

    void afisare(ostream&) const override;
};