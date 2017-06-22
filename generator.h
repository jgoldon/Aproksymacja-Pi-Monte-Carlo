#ifndef _generator_h_
#define _generator_h_

#include <queue>
#include <fstream>
#include <climits>
#include <cmath>
#include "iwatek.h"

class Generator : public IWatek
{
public:
    typedef long long liczba_t;
    static const liczba_t MIN = LLONG_MIN;
    static const liczba_t MAX = LLONG_MAX;
    static constexpr liczba_t PIERWIASTEK_MAX = static_cast<liczba_t>(std::sqrt(static_cast<long double>(MAX)));

    Generator(const size_t a_rozmiar_listy);
    liczba_t DajLiczbe();
    liczba_t DajLiczbe(const liczba_t a_start, const liczba_t a_koniec);
    bool CzyJestLiczba();
    size_t DajDlugoscKolejki();
    void GlownaPetla();
    void Start();
    void LadujKolejke();
 private:
    void LadujBufor();
    liczba_t PobierzLiczbeZBufora() const;
    void LadujLiczbe();
    static const size_t m_rozmiar_liczby = sizeof(liczba_t);
    char m_bufor[m_rozmiar_liczby];
    size_t m_rozmiar_listy = 0;
    std::queue<liczba_t> m_lista_liczb;
};

#endif