#ifndef MENU_HH
#define MENU_HH

#include <unistd.h>
#include <time.h>
#include "dron.hh"
#include "scena.hh"
#include "lacze_do_gnuplota.hh"

/**
 * Fuknkcja wypisuje na std out dostepne w menu opcje.
 */
void wypiszOpcje();

/**
 * Fukcja obsugi menu, obsluguje uzytkownika oraz pelni fukcje wykonawcza.
 * 
 * Opcje menu:
 *  r - zadaj ruch na wprost wraz z katem wznoszenia/opadania;
 *  o - zadaj zmiane orientacji w poziomie;
 *  m - wyswietl menu;
 *  k - konczy dzialanie programu;
 * 
 * @return bool - w momencie powodzenia true
 */
bool otworzMenu(PzG::LaczeDoGNUPlota  Lacze);

/**
 * Fuknkcja generuje dane o dronie oraz scenie do pliku.
 * 
 * Plik znajduje sie w stalych, nazwa PLIKGNU.
 */
void generujPlikGNU(const Dron& dron, const Scena& scena);

/**
 * Fuknkcja obsluguje lacze do gnuplota. W szczegolnosci ustawia zakres
 * widziany przez uzytkownika na podstawie wektorow zakresu.
 */
void obslugaGNUplota(const Wektor3D& wektorP, const Wektor3D& wektorK, PzG::LaczeDoGNUPlota  Lacze);


#endif