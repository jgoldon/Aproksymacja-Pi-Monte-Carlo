#include"ekran.h"
#include <thread>
#include <chrono>
#include<ncurses.h>

Ekran::Ekran(Generator & a_generator, Sumator & a_sumator, Aproksymator & a_aproksymator)
: m_generator(a_generator)
, m_sumator(a_sumator)
, m_aproksymator(a_aproksymator)
{
}

void Ekran::Inicjuj()
{
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
}

Ekran::~Ekran()
{
    if(m_watek.joinable())
    {
        m_watek.join();
    }
    endwin();
}

void Ekran::Wyswietl()
{
    Inicjuj();
    clear();
    printw("liczba pi: %f\n", m_aproksymator.DajPi());
    printw("dlugosc kolejki: %d\n", m_generator.DajDlugoscKolejki());
    printw("lacznie w kwadracie: %llu\n", m_sumator.DajLacznieWKwadracie());
    printw("lacznie w kole: %llu\n", m_sumator.DajLacznieWKole());

    auto wiersze_max = 10;
    auto i = 1;
    for (const auto & przetwarzacz : m_sumator.DajListePrzetwarzaczy())
    {
        printw("===== %d\n", i);
        printw("suma w kwadracie: %llu\n", przetwarzacz->DajSumeWKwadracie());
        printw("suma w kole: %llu\n", przetwarzacz->DajSumeWKole());
        if (++i > wiersze_max)
        {
            break;
        }         
    }
    refresh();
    m_aktywny = getch() == ERR;
}

void Ekran::GlownaPetla()
{
    do
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        Wyswietl();
    } while(m_aktywny);
}

void Ekran::Start()
{
    if(!m_watek.joinable())
    {
        m_watek = std::thread(&Ekran::GlownaPetla, this);
    }
}

void Ekran::Join()
{
    if(m_watek.joinable())
    {
        m_watek.join();
    }
}