#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH
#include <fstream>

#include "powierzchnia.hh"

/**
 * Klasa jest figura geometryczna a dokladniej prostopadloscianem.
 */
class Prostopadloscian:public Powierzchnia{

public:
    /**
     * Kreator prostopadloscianu, podczas tworzenia pobiera dane
     * o nim z pliku przypisanym do stalej PROSTOPADLOSCIAN.
     */
    Prostopadloscian();
};
#endif