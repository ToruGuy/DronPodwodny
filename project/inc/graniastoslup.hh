#ifndef GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH

#include "powierzchnia.hh"

/**
 * Klasa modelujaca pojecie graniastoslupu.
 */
class Graniastoslup:public Powierzchnia{

public:
    /**
     * Konstruktor graniastoslupu, podczas tworzenia pobiera dane
     * o nim z pliku przypisanym do stalej GRANIASTOSLUP.
     */
    Graniastoslup();

    /**
     * Konstruktor graniastoslupu ktory podczas tworzenia ma zostac przesuniety o wektor przemieszczenia
     * 
     * @param[in] - Wektro3D wektor przesuniecia wzgledem punktow podanych w pliku
     */
    Graniastoslup(Wektor3D& wekPrzesuniecia);
};
#endif