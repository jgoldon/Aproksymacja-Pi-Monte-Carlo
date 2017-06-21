#include"sumator.h"

Sumator::Sumator(lista_przetwarzaczy_t & a_lista_przetwarzaczy)
: m_lista_przetwarzaczy(a_lista_przetwarzaczy)
{
}

Sumator::~Sumator()
{
    if(m_watek.joinable())
    {
        m_watek.join();
    }   
}

void Sumator::Sumuj()
{
    std::lock_guard<std::mutex> blokada(m_bariera);
    m_lacznie_w_kwadracie = 0;
    m_lacznie_w_kole = 0;
    for(auto & przetwarzacz : m_lista_przetwarzaczy)
    {
        m_lacznie_w_kwadracie += przetwarzacz.DajSumeWKwadracie();
        m_lacznie_w_kole += przetwarzacz.DajSumeWKole();
    }
}

Generator::liczba_t Sumator::DajLacznieWKwadracie()
{
    std::lock_guard<std::mutex> blokada(m_bariera);
    return m_lacznie_w_kwadracie;
}

Generator::liczba_t Sumator::DajLacznieWKole()
{
    std::lock_guard<std::mutex> blokada(m_bariera);
    return m_lacznie_w_kole;
}

Sumator::lista_przetwarzaczy_t & Sumator::DajListePrzetwarzaczy()
{
    return m_lista_przetwarzaczy;
}

void Sumator::Start()
{
    if(!m_watek.joinable())
    {
        m_watek = std::thread(&Sumator::GlownaPetla, this);
    }
}

void Sumator::Stop()
{
    m_aktywny = false;
}

void Sumator::GlownaPetla()
{
    while(m_aktywny)
    {
        Sumuj();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}