#ifndef PRET_HH
#define PRET_HH

#include "przeszkoda.hh"

/**
 * Klasa modelujaca pojecie przeszkody Pret.
 */
class Pret:public Przeszkoda{
public:
    /**
     * Konstruktor bloku podczas tworzenia pobiera dane
     * o nim z pliku przypisanym do stalej PRET.
     * 
     * @param[in] Wektor3D - wektor o jaki ma zostac
     *                       przesuniety Pret wzgledem
     *                       danych podanych w pliku
     */
    Pret(Wektor3D& wekPrzesuniecia);
};
#endif