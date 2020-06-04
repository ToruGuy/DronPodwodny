#ifndef DRON_HH
#define DRON_HH

#include "prostopadloscian.hh"
#include "wirnik.hh"
#include "graniastoslup.hh"
#include "macierz3D.hh"
#include <cmath>

/**
 * Klasa modeluje pojecie drona, jako prostopadloscianu,
 * poruszajacego sie w ukladzie wspolrzednych.
 */
class Dron:public Prostopadloscian{
    Prostopadloscian prostopadloscian;

    Wirnik wirnikLewy;

    Wirnik wirnikPrawy;
    /**
     * Kat pomiedzy ukladem lokalnym stalym a globalnym zmiennym.
     */
    double katZmianyUkladu = 0;

    /**
     * Wektor przesuniecia ukladu globalnego wzgledem lokalnego stalego.
     */
    Wektor3D wektorPrzesunieciaUkladu;

    /**
     * Zbior wektorow zawierajacych nowy, zmienny uklad globalny.
     */
    std::vector <Wektor3D> _ukladGlobalny;

    std::string _napis = "";
public:
    /**
     * Konstruktor bezparametryczny klasy dron.
     * Przypisuje _ukladGlobly wartosci ukladu lokalnego.
     */
    Dron();

    /**
     * Przeciazenie operatora umozliwiajace wyswietlanie wartosci ukladu globalnego.
     * 
     * @return Wektor3D
     */
    Wektor3D operator[](unsigned int i) const {return _ukladGlobalny[i];}

    /**
     * Zmienia wartosci ukladu globalnego na lokalne.
     */
    void powrotDoUkladuLok();

    void aktualizujWirniki();

    /**
     * Wykonuje ruch drona wokol osi OZ.
     */
    void obrotWokolOZ(const double& kat);

    /**
     * Wykonuje ruch drona na wprost oraz pod zadanym katem wznoszenia/opadania.
     */
    void ruchNaWprost(const double& katGoraDol, const double& odleglosc);

    void kolizjaObiekt(Wektor3D& zPoczatekOb, Wektor3D& zKoniecOb);

    /**
     * Wykrywa kolizje z dnem, jesli takowa nastapi zwraca true.
     * 
     * @return bool
     */
    bool wykrywanieKolizjiZDnem();
    
    /**
     * Wykrywa doplyniecie do powierzchni wody, jesli takowa nastapi zwraca true.
     * 
     * @return bool
     */
    bool wykrywanieKolizjiZWoda();

    Wektor3D zakresPoczatku();
    
    Wektor3D zakresKonca();

    /**
     * Generuje dane o dronie do pliku.
     * Sciezka do pliku znajduje sie pod nazwa DRON
     * 
     * @return std::string
     */
    std::string generujDronaDoPliku();

    /**
     * Daje mozliwosc zwrocenia pola _napis.
     * 
     * @return std::string
     */
    std::string napis() const {return _napis;}
};
#endif