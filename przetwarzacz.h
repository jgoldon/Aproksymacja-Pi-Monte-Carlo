#ifndef _przetwarzacz_h_
#define _przetwarzacz_h_

#include "generator.h"
#include <thread>
#include <mutex>

class Przetwarzacz
{
public:
    Przetwarzacz(Generator & a_generator);
    ~Przetwarzacz();
    Generator::liczba_t DajSumeWKwadracie();
    Generator::liczba_t DajSumeWKole();
    void Start();
    void Stop();
    void GlownaPetla();
private:
    Generator & m_generator;
    size_t m_suma_w_kwadracie = 0;
    size_t m_suma_w_kole = 0;
	void Sumuj();
    bool m_aktywny = true;
    std::thread m_watek;
    std::mutex m_bariera;
};

#endif