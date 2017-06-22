#include"generator.h"
#include <chrono>


Generator::Generator(const size_t a_rozmiar_listy)
: m_rozmiar_listy(a_rozmiar_listy)
{
}

void Generator::LadujKolejke()
{
    std::lock_guard<std::mutex> blokada(m_bariera);
    while(m_lista_liczb.size() < m_rozmiar_listy)
    {
        LadujLiczbe();
    }
}

Generator::liczba_t Generator::DajLiczbe()
{
    while(true)
    {
        std::lock_guard<std::mutex> blokada(m_bariera);
        if (!m_lista_liczb.empty())
        {
            auto liczba = m_lista_liczb.front();
            m_lista_liczb.pop();
            return liczba;   
        }
    }
}

Generator::liczba_t Generator::DajLiczbe(const liczba_t a_start, const liczba_t a_koniec)
{
    long double skala = static_cast<long double>(DajLiczbe()) - MIN;
    skala /= static_cast<long double>(MAX) - MIN;
    return skala * (a_koniec - a_start) + a_start;
}

size_t Generator::DajDlugoscKolejki()
{
    std::lock_guard<std::mutex> blokada(m_bariera);
    return m_lista_liczb.size();
}

void Generator::GlownaPetla()
{
    while(m_aktywny)
    {
        if (m_lista_liczb.empty())
        {
            LadujKolejke();
        }
    }
}

void Generator::Start()
{
    if(!m_watek.joinable())
    {
        m_watek = std::thread(&Generator::GlownaPetla, this);
    }
}

bool Generator::CzyJestLiczba()
{
    std::lock_guard<std::mutex> blokada(m_bariera);
    return !m_lista_liczb.empty();
}

void Generator::LadujBufor()
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

void Generator::LadujLiczbe()
{
    LadujBufor(); 
    m_lista_liczb.push(PobierzLiczbeZBufora());
}
