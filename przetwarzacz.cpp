#include"przetwarzacz.h"

Przetwarzacz::Przetwarzacz(Generator & a_generator)
: m_generator(a_generator)
{
}

void Przetwarzacz::Sumuj()
{
    auto x = m_generator.DajLiczbe(0, Generator::PIERWIASTEK_MAX);
    auto y = m_generator.DajLiczbe(0, Generator::PIERWIASTEK_MAX);
    auto suma_kwadratow = x * x + y * y;
    if (suma_kwadratow > 0)
    {
        ++m_suma_w_kole;
    }
    ++m_suma_w_kwadracie;
}

void Przetwarzacz::Sumuj(const int a_ilosc)
{
    int ilosc = a_ilosc;
    while(ilosc-- > 0)
    {
        Sumuj();
    }
}

Generator::liczba_t Przetwarzacz::DajSumeWKwadracie() const
{
    return m_suma_w_kwadracie;
}

Generator::liczba_t Przetwarzacz::DajSumeWKole() const
{
    return m_suma_w_kole;
}