#include "iwatek.h"

IWatek::~IWatek()
{
    if(m_watek.joinable())
    {
        m_watek.join();
    }   
}

void IWatek::Stop()
{
    m_aktywny = false;
}