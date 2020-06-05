#ifndef BLOK_HH
#define BLOK_HH

#include "przeszkoda.hh"

/**
 * Klasa modelujaca pojecie przeszkody Blok.
 */
class Blok:public Przeszkoda{
public:
    /**
     * Konstruktor bloku podczas tworzenia pobiera dane
     * o nim z pliku przypisanym do stalej BLOK.
     * 
     * @param[in] Wektor3D - wektor o jaki ma zostac
     *                       przesuniety Blok wzgledem
     *                       danych podanych w pliku
     */
    Blok(Wektor3D& wekPrzesuniecia);
};
#endif