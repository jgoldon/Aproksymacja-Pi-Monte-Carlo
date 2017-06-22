#ifndef _przetwarzacz_h_
#define _przetwarzacz_h_

#include"iwatek.h"
#include"generator.h"

class Przetwarzacz : public IWatek
{
public:
    Przetwarzacz(Generator & a_generator);
    Generator::liczba_t DajSumeWKwadracie();
    Generator::liczba_t DajSumeWKole();
    void Start();
    void GlownaPetla();
private:
    void Sumuj();
    Generator & m_generator;
    size_t m_suma_w_kwadracie = 0;
    size_t m_suma_w_kole = 0;
};

#endif