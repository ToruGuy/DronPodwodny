# Dron Podwodny - Underwater Drone

The program gives you ability to steer underwater drone!

Program written in C++, graphical interpretation uses GNUplot.
More information about GNUplot:
http://www.gnuplot.info/

To transfer data from C++ to gnuplot, it uses “Łącze do GNUplota”:
https://kcir.pwr.edu.pl/~kreczmer/kpo/materialy/dodatki/lacze_do_gnuplota/doc/doxygen/index.html

# Installation
Clone the repository locally and navigate there:
```sh
$ git clone https://github.com/browner342/DronPodwodny.git
```
Navigate to program directory:
```sh
$ cd project
```
Build a program with make command:
```
$ make
```
If there are no other issues you could run it:
```
$ ./dron-podwodny
```

# Usage

```
$ ./dron-podwodny
```
After executing:
```sh
Twoj wybor, m - menu >
```
Choose m to see the options:
```sh
Twoj wybor, m - menu > m
r - zadaj ruch na wprost        // move forward plus angle up or down
o - zadaj zmiane orientacji     // turning around, you give the angle
m - wyswietl menu               // show menu

k - koniec dzialania programu   // end of program
```

If 'r' was given:
```sh
Podaj kat wznoszenia/opadania w stopniach.  // Set angle up or down.
Wartosc kata> 30                                  

Podaj wartosc przemieszczenia drona.        // Set displacement.
Wartosc odleglosci > 10

Aktualna ilosc obiektow Wektor3D> 1725      // Amount of created Vectors now
Laczna ilosc obiektow> 59902                // Amount of created Vectors all
```

If 'o' was given:
```sh
Twoj wybor, m - menu > o

Podaj wartosc kata obrotu w stopniach.      // Set turning angle
Podaj kat obrotu: 30

Aktualna ilosc obiektow Wektor3D > 1725     // Amount of created Vectors now
Laczna ilosc obiektow > 169382              // Amount of created Vectors all
```
