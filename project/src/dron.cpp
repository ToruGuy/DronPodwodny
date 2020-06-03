#include "dron.hh"

Dron::Dron(){
    int licznik;
    Wektor3D tmp = Wektor3D(-5,0,-40);
    wirnikLewy = Wirnik(tmp);

    tmp = Wektor3D(5,0,-40);
    wirnikPrawy = Wirnik(tmp);

    licznik = prostopadloscian.ilosc();
    for(int i = 0; i < licznik; i++ ){
        //nawiasy [] odwołuja się do układu lokalnego prostopadloscianu
        _ukladGlobalny.push_back(prostopadloscian[i]);
    }
    
    for(int i = licznik; i < wirnikLewy.ilosc()+licznik; i++ ){
        //nawiasy () odwołuja się do układu globalnego wirnika Lewy
        _ukladGlobalny.push_back(wirnikLewy(i-licznik)); 
    }
    
    licznik += wirnikLewy.ilosc();
    for(int i = licznik; i < wirnikPrawy.ilosc()+licznik; i++ ){
        //nawiasy () odwołuja się do układu globalnego wirnika Prawy
        _ukladGlobalny.push_back(wirnikPrawy(i-licznik));
    }
}
void Dron::powrotDoUkladuLok(){
    int licznik = prostopadloscian.ilosc();
    for(int i = 0; i < licznik; i++ ){
        _ukladGlobalny[i] = prostopadloscian[i];
    }

    for(int i = licznik; i < wirnikLewy.ilosc()+licznik; i++ ){
        _ukladGlobalny[i] = wirnikLewy(i-licznik);
    }

    licznik += wirnikLewy.ilosc();
    for(int i = licznik; i < wirnikPrawy.ilosc()+licznik; i++ ){
        _ukladGlobalny[i] = wirnikPrawy(i-licznik);
    }
}

void Dron::aktualizujWirniki(){
    int licznik = prostopadloscian.ilosc();

    for(int i = licznik; i < wirnikLewy.ilosc()+licznik; i++ ){
        _ukladGlobalny[i] = wirnikLewy(i-licznik);
    }

    licznik += wirnikLewy.ilosc();
    for(int i = licznik; i < wirnikPrawy.ilosc()+licznik; i++ ){
        _ukladGlobalny[i] = wirnikPrawy(i-licznik);
    }

    double katRad = katZmianyUkladu;
    katRad *= M_PI / 180;
    Wektor3D wekDoMacierzy[3];
    wekDoMacierzy[0] = Wektor3D(cos(katRad), sin(katRad), 0);
    wekDoMacierzy[1] = Wektor3D(-sin(katRad), cos(katRad), 0);
    wekDoMacierzy[2] = Wektor3D(0, 0, 1);
    Macierz3D macierzZmian = Macierz3D(wekDoMacierzy[0], wekDoMacierzy[1], wekDoMacierzy[2]);

    licznik = prostopadloscian.ilosc();
    for(int i = licznik; i < wirnikPrawy.ilosc()+licznik+wirnikLewy.ilosc(); i++ ){
        _ukladGlobalny[i] = macierzZmian * _ukladGlobalny[i];
        _ukladGlobalny[i] = _ukladGlobalny[i] + wektorPrzesunieciaUkladu;
    }

}

void Dron::obrotWokolOZ(const double& kat){
    
    katZmianyUkladu += kat;
    double katRad = katZmianyUkladu;
    katRad *= M_PI / 180;
    Wektor3D wekDoMacierzy[3];
    wekDoMacierzy[0] = Wektor3D(cos(katRad), sin(katRad), 0);
    wekDoMacierzy[1] = Wektor3D(-sin(katRad), cos(katRad), 0);
    wekDoMacierzy[2] = Wektor3D(0, 0, 1);
    Macierz3D macierzZmian = Macierz3D(wekDoMacierzy[0], wekDoMacierzy[1], wekDoMacierzy[2]);

    
    (*this).powrotDoUkladuLok();
    for(Wektor3D& elem : _ukladGlobalny){
        elem = macierzZmian * elem;
        elem = elem + wektorPrzesunieciaUkladu;
    }

    wirnikPrawy.obracaj(20);
    wirnikLewy.obracaj(-20);
   
}

void Dron::ruchNaWprost(const double& katGoraDol, const double& odleglosc){

    double katPoziomRAD = katZmianyUkladu * M_PI / 180;
    double katPionRAD = katGoraDol * M_PI / 180;
    double katProsty = 90;
    katProsty *= M_PI / 180;

    Wektor3D tmp = Wektor3D(odleglosc*(-sin(katPoziomRAD))*sin(katProsty - katPionRAD), odleglosc*cos(katPoziomRAD)*sin(katProsty - katPionRAD), odleglosc*sin(katPionRAD));
    wektorPrzesunieciaUkladu = wektorPrzesunieciaUkladu + tmp;

    wirnikPrawy.obracaj(20);
    wirnikLewy.obracaj(-20);
    this->aktualizujWirniki();
    for(int i = 0; i < prostopadloscian.ilosc(); i++ ){
        _ukladGlobalny[i] = _ukladGlobalny[i] + tmp;
    }
    
    
    
}

bool Dron::wykrywanieKolizjiZDnem(){
    double poziomDrona = POZ_WODY + 1; 

    for(Wektor3D& elem : _ukladGlobalny){
        elem(2) < poziomDrona?poziomDrona = elem(2):0;
    }

    if(poziomDrona <= POZ_DNA){
        std::cerr<<"Uderzyles w dno!"<<std::endl<<std::endl;
        return true;
    }
    return false;
}

bool Dron::wykrywanieKolizjiZWoda(){
    double poziomDrona = POZ_DNA - 1;

    for(Wektor3D& elem : _ukladGlobalny){
        elem(2) > poziomDrona?poziomDrona = elem(2):0;
    }

    if(poziomDrona >= POZ_WODY){
        std::cerr<<"Jesteś na maksymalnie wynurzony!"<<std::endl<<std::endl;
        
        for(Wektor3D& elem : _ukladGlobalny){
            elem(2) -= JEDNOSTKOWA;
        }
        return true;
    }
    return false;
}

std::string Dron::generujDronaDoPliku(){
    int i = 0;
    _napis = "";
    std::ofstream Strm(DRON);
    if (Strm.fail()) std::cerr<<"Zapis Drona do pliku nie powiodl sie!"<<std::endl;

    for(Wektor3D& elem : _ukladGlobalny){
        i++;
        _napis += elem.napis();
        if(i % 4 == 0){
            _napis += "\n";
        }
        if(i == 20){
            _napis += "\n\n";
        }
        if(i == 48){
            _napis += "\n\n";
        }
    }
    
    Strm<<_napis;
    return _napis;
}