#include"aproksymator.h"
#include"ekran.h"

int main()
{
    Generator generator = Generator(2000);

    Sumator::lista_przetwarzaczy_t lista_przetwarzaczy;
    lista_przetwarzaczy.push_back(Przetwarzacz(generator));
    lista_przetwarzaczy.push_back(Przetwarzacz(generator));
    for(auto & przetwarzacz : lista_przetwarzaczy)
    {
        przetwarzacz.Sumuj(250);
    }

    Sumator sumator = Sumator(lista_przetwarzaczy);
    sumator.Sumuj();

    Aproksymator aproksymator = Aproksymator(sumator);
    aproksymator.ObliczPi();

    Ekran ekran(generator, sumator, aproksymator);
    ekran.Wyswietl();
    //getch();
    return 0;
}