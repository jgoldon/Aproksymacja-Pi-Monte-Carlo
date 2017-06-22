#ifndef _aproksymator_h_
#define _aproksymator_h_

#include"iwatek.h"
#include"sumator.h"

class Aproksymator : public IWatek
{
public:
    Aproksymator(Sumator & a_sumator);
    void ObliczPi();
    double DajPi();
    void Start();
    void GlownaPetla();
private:
    Sumator & m_sumator;
    double m_pi = 0;
};

#endif