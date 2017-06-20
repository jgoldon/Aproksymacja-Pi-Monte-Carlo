#include"aproksymator.h"

Aproksymator::Aproksymator(Sumator & a_sumator)
: m_sumator(a_sumator)
{
}

void Aproksymator::ObliczPi()
{
    m_pi = 4.0 * m_sumator.DajLacznieWKole() / m_sumator.DajLacznieWKwadracie();
}

double Aproksymator::DajPi()
{
    return m_pi;
}