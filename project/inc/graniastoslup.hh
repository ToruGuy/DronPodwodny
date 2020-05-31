#ifndef GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH

#include "powierzchnia.hh"

/**
 * Klasa jest figura geometryczna a dokladniej prostopadloscianem.
 */
class Graniastoslup:public Powierzchnia{

public:
    /**
     * Kreator prostopadloscianu, podczas tworzenia pobiera dane
     * o nim z pliku przypisanym do stalej PROSTOPADLOSCIAN.
     */
    Graniastoslup();

    Graniastoslup(Wektor3D& wekPrzesuniecia);
};
#endif