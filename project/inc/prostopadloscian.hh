#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include "powierzchnia.hh"

/**
 * Klasa modelujaca pojecie prostopadloscianu.
 */
class Prostopadloscian:public Powierzchnia{

public:
    /**
     * Konstruktor prostopadloscianu, podczas tworzenia pobiera dane
     * o nim z pliku przypisanym do stalej PROSTOPADLOSCIAN.
     */
    Prostopadloscian();
};
#endif