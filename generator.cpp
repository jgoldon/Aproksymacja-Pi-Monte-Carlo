#include"generator.h"

Generator::Generator(const size_t a_rozmiar_listy)
: m_rozmiar_listy(a_rozmiar_listy)
{
    PobierzLiczby();
}

void Generator::PobierzLiczby()
{
    while(m_lista_liczb.size() < m_rozmiar_listy)
    {
        PobierzLiczbe();
    }
}

Generator::liczba_t Generator::DajLiczbe()
{
    if (!CzyJestLiczba())
    {
        PobierzLiczbe();
    }
    auto liczba = m_lista_liczb.front();
    m_lista_liczb.pop();
    return liczba;
}

Generator::liczba_t Generator::DajLiczbe(const liczba_t a_start, const liczba_t a_koniec)
{
    long double skala = static_cast<long double>(DajLiczbe()) - MIN;
    skala /= static_cast<long double>(MAX) - MIN;
    return skala * (a_koniec - a_start) + a_start;
}

size_t Generator::DajDlugoscKolejki() const
{
    return m_lista_liczb.size();
}

bool Generator::CzyJestLiczba() const
{
    return !m_lista_liczb.empty();
}

void Generator::PobierzBufor()
{
    std::ifstream is;
    is.open("/dev/urandom", std::ios::binary);
    is.read(m_bufor, m_rozmiar_liczby);
    is.close();
}

Generator::liczba_t Generator::PobierzLiczbeZBufora() const
{
    liczba_t liczba = 0;
    for(size_t i = 0; i < m_rozmiar_liczby; ++i)
    {
        liczba += static_cast<liczba_t>(m_bufor[i]) << i * 8;
    }
    return liczba;
}

void Generator::PobierzLiczbe()
{
    PobierzBufor(); 
    m_lista_liczb.push(PobierzLiczbeZBufora());
}
