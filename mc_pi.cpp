#include <memory>
#include "aproksymator.h"
#include "ekran.h"

int main()
{
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);

    const size_t dlugosc_kolejki = 1000;
    const size_t ilosc_watkow_przetwarzacza = 10;

    // Budujemy zależności
    Generator generator(dlugosc_kolejki);
    Sumator::lista_przetwarzaczy_t lista_przetwarzaczy;
    for (auto i = 0u; i < ilosc_watkow_przetwarzacza; ++i)
    {
        lista_przetwarzaczy.push_back(std::move(std::make_unique<Przetwarzacz>(generator)));
    }
    Sumator sumator(lista_przetwarzaczy);
    Aproksymator aproksymator(sumator);

    // Uruchamiamy wątki
    generator.Start();
    for (auto & przetwarzacz : lista_przetwarzaczy)
    {
        przetwarzacz->Start();
    }
    sumator.Start();
    aproksymator.Start();

    // Główny wątek programu
    {
        Ekran ekran(generator, sumator, aproksymator);
        ekran.Start();
    }

    // Zatrzymujemy pozostałe wątki
    generator.Stop();
    for (auto & przetwarzacz : lista_przetwarzaczy)
    {
        przetwarzacz->Stop();
    }
    sumator.Stop();
    aproksymator.Stop();

    endwin();
    return 0;
}