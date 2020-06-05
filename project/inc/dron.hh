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
class Dron {
    /**
     * Pole modelujace czesc graficzna z ktorej sklada sie dron
     */
    Prostopadloscian prostopadloscian;
    
    /**
     * Pole modelujace czesc graficzna z ktorej sklada sie dron
     */
    Wirnik wirnikLewy;

    /**
     * Pole modelujace czesc graficzna z ktorej sklada sie dron
     */
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

    /**
     * Pole napis, zawiera dane o wierzcholkach powierzchni w formie gotowej do wypisania.
     */
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
     * Przywraca ukladowi globalnemu wartosci podstawowego ukladu lokalnego.
     * Jest to wykorzystywane chociazby do minimalizacji bledow podczas obrotow drona.
     */
    void powrotDoUkladuLok();

    /**
     * Metoda aktualizuje wirniki do ich aktualnej pozycji.
     * Wirniki obracaja sie wokol swojego ukladu lokalnego w okol osi OY.
     */
    void aktualizujWirniki();

    /**
     * Wykonuje ruch drona wokol osi OZ.
     * 
     * @param[in] - double kat o jaki ma obrocic sie dron
     */
    void obrotWokolOZ(const double& kat);

    /**
     * Wykonuje ruch drona na wprost oraz pod zadanym katem wznoszenia/opadania.
     * 
     * @param[in] - double kat gora dol o jaki ma sie poruszac dron
     * @param[in] - double odleglosc o jaka ma sie przemiescic dron
     */
    void ruchNaWprost(const double& katGoraDol, const double& odleglosc);

    /**
     * Metoda sprawdza czy dron koliduje z obiektem statycznym o zakresie
     * zPoczatek, zKoniec
     * 
     * @param[in] - Wektor3D zPoczatekOb wektor poczatku obiektu
     * @param[in] - Wektor3D zKoniecOb wektor konca obiektu
     * 
     * @return bool - jesli dron koliduje z obiektem zwraca true
     */
    bool kolizjaObiekt(Wektor3D& zPoczatekOb, Wektor3D& zKoniecOb);

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