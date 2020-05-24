#include "wektor3D.hh"
#include <iostream>

int Wektor3D::iloscWszystkie = 0;
int Wektor3D::iloscZniszczone = 0;

std::string Wektor3D::napis() const{
    std::string tmp = "";
    for(int i = 0; i < 3; i++){
        tmp += std::to_string((*this)(i));
        tmp += " ";
    }
    tmp += "\n";

    return tmp;
}

