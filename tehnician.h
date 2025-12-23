#include "angajat.h"

class tehnician: public angajat{
    int nr_tipuri;
    int nr_marci;
    string* lista_tipuri;
    string* lista_marci;//trb sa modific

public:

    tehnician();
    tehnician(int, const string&, const string&, const string&, const struct data&, const string&, int, int, const string*, const string*);
    tehnician(const tehnician&);
    tehnician& operator=(const tehnician&)=delete;
    ~tehnician();

    virtual void afisare(ostream&) const override;
    virtual double calcul_salariu() const override; //mai trebuie sa implementez partea de 2% din valoarea reparatiilor efectuate
};