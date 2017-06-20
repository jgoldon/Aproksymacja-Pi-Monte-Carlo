#ifndef _przetwarzacz_h_
#define _przetwarzacz_h_

#include"generator.h"

class Przetwarzacz
{
public:
    Przetwarzacz(Generator & a_generator);
    void Sumuj();
    void Sumuj(const int a_ilosc);
    Generator::liczba_t DajSumeWKwadracie() const;
    Generator::liczba_t DajSumeWKole() const;
private:
    Generator & m_generator;
    size_t m_suma_w_kwadracie = 0;
    size_t m_suma_w_kole = 0;
};

#endif