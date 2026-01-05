#include "electrocasnic.h"

class masina_spalat: public electrocasnic{
    int capacitate;

public:
    masina_spalat();
    masina_spalat(const string&, const string&, const string&, int, double, int);
    masina_spalat(const masina_spalat&);
    masina_spalat& operator=(const masina_spalat&) = delete;
    ~masina_spalat() override = default;

    void afisare(ostream&) const override;
};