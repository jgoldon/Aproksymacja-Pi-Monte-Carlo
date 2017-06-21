#include "przetwarzacz.h"

Przetwarzacz::Przetwarzacz(Generator & a_generator)
: m_generator(a_generator)
, m_watek()
{
}

Przetwarzacz::~Przetwarzacz()
{
    if(m_watek.joinable())
    {
        m_watek.join();
    }  
}

void Przetwarzacz::Sumuj()
{
    std::lock_guard<std::mutex> blokada(m_bariera);
    auto x = m_generator.DajLiczbe(0, Generator::PIERWIASTEK_MAX);
    auto y = m_generator.DajLiczbe(0, Generator::PIERWIASTEK_MAX);
    auto suma_kwadratow = x * x + y * y;
    if (suma_kwadratow > 0)
    {
        ++m_suma_w_kole;
    }
    ++m_suma_w_kwadracie;
}

Generator::liczba_t Przetwarzacz::DajSumeWKwadracie()
{
    std::lock_guard<std::mutex> blokada(m_bariera);
    return m_suma_w_kwadracie;
}

Generator::liczba_t Przetwarzacz::DajSumeWKole()
{
    std::lock_guard<std::mutex> blokada(m_bariera);
    return m_suma_w_kole;
}

void Przetwarzacz::Start()
{
    if(!m_watek.joinable())
    {
        m_watek = std::thread(&Przetwarzacz::GlownaPetla, this);
    }
}

void Przetwarzacz::Stop()
{
    m_aktywny = false;
}

void Przetwarzacz::GlownaPetla()
{
    while(m_aktywny)
    {
        Sumuj();
    }
}