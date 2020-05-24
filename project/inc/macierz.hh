#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "wektor.hh"
#include <cassert>

/**
 * Plik zawiera definicje klasy Macierz, metod tej klasy,
 * oraz przeciazenia operatorow, rowniez dotyczacych macierzy. 
 */

template <typename STyp, int SWymiar>
class Macierz {
  Wektor<STyp,SWymiar> _kolumna[SWymiar];     /*! Pole reprezentujace kolumny macierzy.*/
  
  public:
    /**
     * Konstruktor Macierzy, tworzy macierz na podstawie konstruktora Wektora 
     */
    Macierz(){for(Wektor<STyp,SWymiar>& elem : _kolumna) elem = Wektor<STyp,SWymiar>();}

    /**
     * Konstruktor kopiujący Macierzy, tworzy macierz na podstawie innego już istniejącego wektora 
     */
    Macierz(const Macierz<STyp,SWymiar> &m){for(int i = 0; i < SWymiar; i++) _kolumna[i] = m._kolumna[i];}

    /**
     * Przeciążenie operatora pozwalające na czytanie wartosci
     * kolumn.
     * 
     * @return Wektor
     */
    const Wektor<STyp,SWymiar>& operator[] (int unsigned kol) const {return _kolumna[kol];}

    /**
     * Przeciążenie operatora pozwalające na zmienianie wartosci
     * kolumn.
     * 
     * @return Wektor
     */
          Wektor<STyp,SWymiar>& operator[] (int unsigned kol)       {return _kolumna[kol];}

    /**
     * Przeciążenie operatora pozwalające na czytanie wartosci
     * wspolczynnikow kolumn macierzy.
     * 
     * @return TYP ,wspolczynnik kolumny
     */
    const STyp operator() (int unsigned wi, int unsigned ko) const {return _kolumna[ko](wi);}

    /**
     * Przeciążenie operatora pozwalające na zmiane wartosci
     * wspolczynnikow kolumn macierzy.
     * 
     * @return TYP ,wspolczynnik kolumny
     */
         STyp& operator() (int unsigned wi, int unsigned ko)       {return _kolumna[ko](wi);}
    
    /**
     * Przeciążenie operatora mnożenia pozwalające na przemnożenie
     * macierzy przez wektor.
     * 
     * @param[in] wek - wektor przez ktory ma zostac przemnozona macierz
     * @return TYP ,wspolczynnik kolumny
     */
    Wektor<STyp,SWymiar> operator * (const Wektor<STyp,SWymiar>& wek) const;
    /**
     * Metoda pozwalająca wyliczenie wyznacznika macierzy
     * metoda Gaussa. Program korzysta z kopii macierzy nie wplywajac na jej wyglad,
     * jednak zapisuje wynik w polu wyznacznik.
     * 
     * @return TYP ,wyznacznik.
     */
    STyp WyznacznikMGaussa();

    /**
     * Metoda zamienia kolumne w macierzy na dany wektor.
     * Podana wartosc kolumny, nie moze byc wieksza niz ROZMIAR macierzy.
     * 
     * @param[in] kol - bez znakowa przedstawiajaca kolumne.
     * @param[in] wektor - wektor na ktory ma zostac zamieniona kolumna.
     */
    void ZamianaKolumnyNaWektor(unsigned int kol, Wektor<STyp,SWymiar>&  wektor);
};

template <typename STyp, int SWymiar>
Wektor<STyp,SWymiar> Macierz<STyp,SWymiar>::operator * (const Wektor<STyp,SWymiar>& wek) const{
    Wektor<STyp,SWymiar> tmp;
    Macierz<STyp,SWymiar> mac(*this);

    for(int i = 0; i < SWymiar; i++){
        for(int j = 0; j < SWymiar; j++){
            tmp(i) = tmp(i) + mac[j](i) * wek(j);
        }
    }
    return tmp;
}

template <typename STyp, int SWymiar>
STyp Macierz<STyp,SWymiar>::WyznacznikMGaussa(){
    STyp dzielnik;
    STyp wyznacznik;
    Macierz<STyp,SWymiar> tmp(*this);

    for(int i = 0; i < SWymiar - 1; i++){
        for(int j = i + 1; j < SWymiar; j++){
            if(tmp[i](i) != 0){
                dzielnik = tmp[j](i) / tmp[i](i);
                tmp[j] = tmp[j] - tmp[i] * dzielnik;
            }
        }
    }
    wyznacznik = tmp[0](0);
    for(int i = 1; i < SWymiar; i++) wyznacznik = wyznacznik * tmp[i](i);

    return wyznacznik;
}

template <typename STyp, int SWymiar>
void Macierz<STyp,SWymiar>::ZamianaKolumnyNaWektor(unsigned int kol, Wektor<STyp,SWymiar>& wektor){
    assert(kol < SWymiar);
    
    _kolumna[kol] = wektor;
}

/**
 * Pozwala operatorowi przesuniecia bitowego w lewo wczytywac Macierz.
 * Akcjeptuje jedynie format zgodny z wczytywaniem formatu Wektor.
 * W przypadku niepoprawności zwraca bład. wczytuje macierz 
 * w postaci transponowanej.
 * 
 * @param[in] strm - strumien wczytywania
 * @param[in] mac - macierz wczytywana
 * @return Strumien do wczytania
 */
template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &strm, Macierz<STyp,SWymiar> &mac){
    for(int i = 0; i < SWymiar; i++){
        strm >> mac[i];

        if(strm.fail()){return strm;}
    }
    return strm;
}

/**
 * Pozwala operatorowi przesuniecia bitowego w prawo wypisac wektor.
 * 
 * @param[in] strm - strumien wypisania
 * @param[in] mac - macierz wczytywana
 * @return Strumien do wypisania
 */
template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &strm, const Macierz<STyp,SWymiar> &mac){
    for(int i = 0; i < SWymiar; i++){
        strm << mac[i];
        strm << std::endl;
    }
    
    return strm;
}
#endif
