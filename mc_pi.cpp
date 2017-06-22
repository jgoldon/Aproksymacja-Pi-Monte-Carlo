#include<memory>
#include"aproksymator.h"
#include"ekran.h"

#include<iostream>

int main(int argc, char** argv)
{

    if (argc != 3)
    {
        std::cout << "uzyj:" << std::endl;
        std::cout << argv[0] << " dlugosc_bufora liczba_watkow" << std::endl;
        return 0;
    }

    size_t dlugosc_kolejki = std::stoi(argv[1]);
    size_t ilosc_watkow_przetwarzacza = std::stoi(argv[2]);

    // Budujemy zależności
    Generator generator(dlugosc_kolejki);
    Sumator::lista_przetwarzaczy_t lista_przetwarzaczy;
    for (auto i = 0u; i < ilosc_watkow_przetwarzacza; ++i)
    {
        lista_przetwarzaczy.push_back(std::move(std::make_unique<Przetwarzacz>(generator)));
    }
    Sumator sumator(lista_przetwarzaczy);
    Aproksymator aproksymator(sumator);

    // Główny wątek programu
    Ekran ekran(generator, sumator, aproksymator);
    ekran.Start();

    // Uruchamiamy wątki
    generator.Start();
    for (auto & przetwarzacz : lista_przetwarzaczy)
    {
        przetwarzacz->Start();
    }
    sumator.Start();
    aproksymator.Start();

    // Czekamy na zamknięcie głównego wątku
    ekran.Join();

    // Zatrzymujemy pozostałe wątki
    generator.Stop();
    for (auto & przetwarzacz : lista_przetwarzaczy)
    {
        przetwarzacz->Stop();
    }
    sumator.Stop();
    aproksymator.Stop();

    return 0;
}