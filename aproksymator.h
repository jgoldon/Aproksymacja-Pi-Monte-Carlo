#ifndef _aproksymator_h_
#define _aproksymator_h_

#include"sumator.h"

class Aproksymator
{
public:
    Aproksymator(Sumator & a_sumator);
    void ObliczPi();
    double DajPi();
private:
    Sumator & m_sumator;
    double m_pi = 0;
};

#endif