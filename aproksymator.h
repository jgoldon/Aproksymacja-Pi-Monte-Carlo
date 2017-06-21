#ifndef _aproksymator_h_
#define _aproksymator_h_

#include"sumator.h"

class Aproksymator
{
public:
    Aproksymator(Sumator & a_sumator);
    ~Aproksymator();
    void ObliczPi();
    double DajPi();
    void Start();
    void Stop();
    void GlownaPetla();
private:
    Sumator & m_sumator;
    double m_pi = 0;
    bool m_aktywny = true;
    std::thread m_watek;
    std::mutex m_bariera;
};

#endif