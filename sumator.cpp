#include"sumator.h"

Sumator::Sumator(lista_przetwarzaczy_t & a_lista_przetwarzaczy)
: m_lista_przetwarzaczy(a_lista_przetwarzaczy)
{
}

void Sumator::Sumuj()
{
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
    return m_lacznie_w_kwadracie;
}

Generator::liczba_t Sumator::DajLacznieWKole()
{
    return m_lacznie_w_kole;
}

Sumator::lista_przetwarzaczy_t & Sumator::DajListePrzetwarzaczy()
{
    return m_lista_przetwarzaczy;
}
