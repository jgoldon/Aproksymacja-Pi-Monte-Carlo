#ifndef _ekran_h_
#define _ekran_h_
#include<ncurses.h>
#include"aproksymator.h"

class Ekran
{
public:
    Ekran(Generator & a_generator, Sumator & a_sumator, Aproksymator a_aproksymator);
    ~Ekran();
    void Wyswietl();
private:
    Generator & m_generator;
    Sumator & m_sumator;
    Aproksymator & m_aproksymator;
};

#endif