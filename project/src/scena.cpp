#include "scena.hh"
void Scena::aktualizujScene(Wektor3D& zakresP, Wektor3D& zakresK){
    zakresP = (*dron)[0]; zakresK = (*dron)[0];
    zakresP(0) -= 70; zakresP(1) -= 70;
    zakresK(0) += 70; zakresK(1) += 70;
    woda = new Woda(zakresP, zakresK);
    dno = new Dno(zakresP, zakresK);

    this->generujSceneDoPliku();

    delete woda;
    delete dno;
}

void Scena::ruchDronaNaWprost( int& katGoraDol, int& odleglosc){

    (*dron).ruchNaWprost(katGoraDol, odleglosc);
    (*dron).generujDronaDoPliku();    
    
    //podczas kontatku z dnem program konczy dzialanie 
    if((*dron).wykrywanieKolizjiZDnem()){
        odleglosc = 1;
        katGoraDol < 0 ? katGoraDol = 90:0;
    }

    //podczas kontaktu z powierzchnia wody dron ma uniemozliwione dalsze wznoszenie sie
    if((*dron).wykrywanieKolizjiZWoda()){
        katGoraDol == 90 ? odleglosc = 0:0;
        katGoraDol>0 ? katGoraDol = 0:0;
    }
}

void Scena::obrotDrona(const double& obrot){
    
    (*dron).obrotWokolOZ(obrot);
    (*dron).generujDronaDoPliku();
    this->generujSceneDoPliku();
}

std::string Scena::generujSceneDoPliku(){    
    std::ofstream Strm(PLIKGNU);
    if (Strm.fail()) std::cerr<<"Zapis Sceny do pliku się nie powiodl!"<<std::endl;
    
    //czysci napis
    _napis = "";

    _napis += (*this).woda->napis();
    _napis += "#\n\n";
    _napis += (*this).dno->napis();
    _napis += "#\n\n";
    _napis += (*this).dron->napis();
    _napis += "#\n\n";

    Strm<<_napis;
    return _napis;
}