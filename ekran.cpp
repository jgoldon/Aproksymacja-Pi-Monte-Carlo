#include"ekran.h"

Ekran::Ekran(Generator & a_generator, Sumator & a_sumator, Aproksymator a_aproksymator)
: m_generator(a_generator)
, m_sumator(a_sumator)
, m_aproksymator(a_aproksymator)
{
    initscr();
}

Ekran::~Ekran()
{
    endwin();
}

void Ekran::Wyswietl()
{
    clear();
    printw("liczba pi: %f\n", m_aproksymator.DajPi());
    printw("dlugosc kolejki: %d\n", m_generator.DajDlugoscKolejki());
    printw("lacznie w kwadracie: %llu\n", m_sumator.DajLacznieWKwadracie());
    printw("lacznie w kole: %llu\n", m_sumator.DajLacznieWKole());

    auto wiersze_max = 10;
    auto i = 0;
    Sumator::lista_przetwarzaczy_t lista_przetwarzaczy = m_sumator.DajListePrzetwarzaczy();
    for (const auto & przetwarzacz : m_sumator.DajListePrzetwarzaczy())
    {
        printw("suma %d w kwadracie: %llu\n", i, przetwarzacz.DajSumeWKwadracie());
        printw("suma %d w kole: %llu\n", i, przetwarzacz.DajSumeWKole());
        if (++i > wiersze_max)
        {
            break;
        }         
    }
    getch();
}
