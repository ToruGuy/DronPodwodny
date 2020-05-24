#include "dron.hh"

Dron::Dron(){
    for(Wektor3D& elem : _wierzcholki){
        _ukladGlobalny.push_back(elem);
    }
}
void Dron::powrotDoUkladuLok(){
    int i = 0;
    for(Wektor3D& elem : _wierzcholki){
        _ukladGlobalny[i] = elem;
        i++;
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

    
    //wraca do poczatkowego ukladu wspolzednych
    (*this).powrotDoUkladuLok();
    for(Wektor3D& elem : _ukladGlobalny){
        elem = macierzZmian * elem;
        elem = elem + wektorPrzesunieciaUkladu;
    }
}

void Dron::ruchNaWprost(const double& katGoraDol, const double& odleglosc){
    double katPoziomRAD = katZmianyUkladu * M_PI / 180;
    double katPionRAD = katGoraDol * M_PI / 180;
    double katProsty = 90;
    katProsty *= M_PI / 180;

    Wektor3D tmp = Wektor3D(odleglosc*(-sin(katPoziomRAD))*sin(katProsty - katPionRAD), odleglosc*cos(katPoziomRAD)*sin(katProsty - katPionRAD), odleglosc*sin(katPionRAD));
    wektorPrzesunieciaUkladu = wektorPrzesunieciaUkladu + tmp;

    for(Wektor3D& elem : _ukladGlobalny){
        elem = elem + tmp;
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

void Dron::dronPozaMapa(Wektor3D& po, Wektor3D& ko){
    //dron doplywa do max X planszy
    if(_ukladGlobalny[0](0) > ko(0) - 4 * KROK_SIATKI){
        ko(0) += 6 * KROK_SIATKI;
        po(0) += 6 * KROK_SIATKI;
    }

    //dron doplywa do min X planszy
    if(_ukladGlobalny[0](0) < po(0) + 4 * KROK_SIATKI){
        ko(0) -= 6 * KROK_SIATKI;
        po(0) -= 6 * KROK_SIATKI;
    }

    //dron doplywa do max Y planszy
    if(_ukladGlobalny[0](1) > ko(1) - 4 * KROK_SIATKI){
        ko(1) += 6 * KROK_SIATKI;
        po(1) += 6 * KROK_SIATKI;
    }

    //dron doplywa do min Y planszy
    if(_ukladGlobalny[0](1) < po(1) + 4 * KROK_SIATKI){
        ko(1) -= 6 * KROK_SIATKI;
        po(1) -= 6 * KROK_SIATKI;
    }
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
    }_napis += "#\n\n";

    Strm<<_napis;
    return _napis;
}