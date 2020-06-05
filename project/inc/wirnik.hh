#ifndef WIRNIK_HH
#define WIRNIK_HH

#include "graniastoslup.hh"
#include "macierz3D.hh"

class Wirnik: public Graniastoslup{
    /**
     * Kat o jaki obrocil sie wirnik wzgledem ukladu lokalnego
     */
    int katZmianyUkladu = 0;
    /**
     * Wektor przesunienia ukladu globalengo wzgledem lokalnego
     */
    Wektor3D wektorPrzesunieciaUkladu;

    /**
     * Zbior wektorow zawierajacych nowy, zmienny uklad globalny.
     */
    std::vector <Wektor3D> _ukladGlobalny;
public:
    /**
     * Konstruktor wirnika
     */
    Wirnik():Graniastoslup(){}

    /**
     * Konstruktor wirnika ktory podczas tworzenia ma zostac przesuniety o wektor przemieszczenia
     * 
     * @param[in] - Wektro3D wektor przesuniecia wzgledem punktow podanych w pliku
     */
    Wirnik(Wektor3D& wekPrzesuniecia);
     /**
     * Przeciazenie operatora [], udostepniajace odczytanie pola wierzcholki.
     * 
     * @return Wektor3D
     */
    Wektor3D operator () (unsigned int i) const { return _ukladGlobalny[i]; }

    /**
     * Przeciazenie operatora [], udostepniajace zmiane pola wierzcholki.
     * 
     * @return Wektor3D
     */
    Wektor3D & operator () (unsigned int i) {return _ukladGlobalny[i];}

    /**
     * Przywraca ukladowi globalnemu wartosci podstawowego ukladu lokalnego.
     * Jest to wykorzystywane chociazby do minimalizacji bledow podczas obrotow wirnika.
     */
    void powrotDoUkladuLok();
    /**
     * Metoda umozliwiajaca winikiowi obracanie sie w okol wlasnej osi.
     * 
     * @param[in] - int wartosc obrotu wirnika w stopniach
     */
    void obracaj(const int& kat);
};

#endif