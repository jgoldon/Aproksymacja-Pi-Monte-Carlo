#include"aproksymator.h"

Aproksymator::Aproksymator(Sumator & a_sumator)
: m_sumator(a_sumator)
{
}

void Aproksymator::ObliczPi()
{
    std::lock_guard<std::mutex> blokada(m_bariera);
    m_pi = 4.0 * m_sumator.DajLacznieWKole() / m_sumator.DajLacznieWKwadracie();
}

double Aproksymator::DajPi()
{
    std::lock_guard<std::mutex> blokada(m_bariera);
    return m_pi;
}

void Aproksymator::Start()
{
    if(!m_watek.joinable())
    {
        m_watek = std::thread(&Aproksymator::GlownaPetla, this);
    }
}

void Aproksymator::GlownaPetla()
{
    while(m_aktywny)
    {
        ObliczPi();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}