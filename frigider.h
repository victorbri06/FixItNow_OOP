#include "electrocasnic.h"

class frigider: public electrocasnic{
    bool are_congelator;

public:
    frigider();
    frigider(const string&, const string&, const string&, int, double, bool);
    frigider(const frigider&);
    frigider& operator=(const frigider&) = delete;
    ~frigider() override = default;

    void afisare(ostream&) const override;
};