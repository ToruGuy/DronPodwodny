#ifndef SCIANA_HH
#define SCIANA_HH

#include "przeszkoda.hh"

/**
 * Klasa modelujaca pojecie przeszkody Sciana.
 */
class Sciana:public Przeszkoda{
public:
    /**
     * Konstruktor bloku podczas tworzenia pobiera dane
     * o nim z pliku przypisanym do stalej SCIANA.
     * 
     * @param[in] Wektor3D - wektor o jaki ma zostac
     *                       przesuniety Sciana wzgledem
     *                       danych podanych w pliku
     */
    Sciana(Wektor3D& wekPrzesuniecia);
};
#endif