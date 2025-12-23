#include "angajat.h"

class supervizor: public angajat{

public:

    supervizor();
    supervizor(int, const string&, const string&, const string&, const struct data&, const string&);
    supervizor(const supervizor&);
    supervizor& operator=(const supervizor&)=delete;
    ~supervizor()=default;

    void afisare(ostream&) const override;
    double calcul_salariu() const override;
};