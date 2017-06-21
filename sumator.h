#ifndef _sumator_h_
#define _sumator_h_

#include<vector>
#include"przetwarzacz.h"

class Sumator
{
public:
    typedef std::vector<std::unique_ptr<Przetwarzacz>> lista_przetwarzaczy_t;
    Sumator(lista_przetwarzaczy_t & a_lista_przetwarzaczy);
    ~Sumator();
    Generator::liczba_t DajLacznieWKwadracie();
    Generator::liczba_t DajLacznieWKole();
    lista_przetwarzaczy_t & DajListePrzetwarzaczy();
    void Start();
    void Stop();
    void GlownaPetla();
private:
    lista_przetwarzaczy_t & m_lista_przetwarzaczy;
    Generator::liczba_t m_lacznie_w_kwadracie = 0;
    Generator::liczba_t m_lacznie_w_kole = 0;
    void Sumuj();
    bool m_aktywny = true;
    std::thread m_watek;
    std::mutex m_bariera;
};

#endif