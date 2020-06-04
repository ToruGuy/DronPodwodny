#ifndef SCENA_HH
#define SCENA_HH
#include "woda.hh"
#include "dno.hh"
#include "dron.hh"
#include "sciana.hh"
#include "pret.hh"
#include "blok.hh"
#include <memory>
#include <string>
#include <fstream>
#include <cstdlib>
#include <list>

/**
 * Klasa laczy obiekty graficzne otaczajace drona.
 */
class Scena{
    /**
     * Pole zawierajace wskaznik na element graficzny dna.
     */
    Dno *dno;

    /**
     * Pole zawierajace wskaznik na element graficzny wody.
     */
    Woda *woda;

    Dron dron;

    std::list<Przeszkoda> przeszkody;
    /**
     * Pole zawierajace string utworzonej sceny.
     */
    std::string _napis = "";
public:
    /**
     * Konstruktor Sceny, tworzy scene o zakresach od zakresP do zakresZ,
     * ktore sa danymi punktami
     * 
     * @param[in] poczatek - wektorowy poczatek zakresu
     * @param[in] koniec - wektorowy koniec zakresu 
     */
    Scena(Wektor3D& zakresP, Wektor3D& zakresK);
    
    /**
     * Destruktor sceny
     */
    ~Scena(){delete woda; delete dno; }

    Dron& droN(){return dron;}

    std::list<Przeszkoda>& listaPrzeszkod(){return przeszkody;}

    void aktualizujScene(Wektor3D& zakresP, Wektor3D& zakresK);

    /**
     * Funkcja generujuje wartosci dna oraz wody, po czym zwraca je do pliku
     * 
     * @param[in] nazwaPliku
     */
    std::string generujSceneDoPliku();

    /**
     * Funkcja zwracajaca napis sceny.
     * 
     * @return string.
     */
    std::string napis() const {return _napis;}
};

#endif