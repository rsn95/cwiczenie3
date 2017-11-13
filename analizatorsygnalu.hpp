#infdef sygnalloader_hpp
#define sygnalloader_hpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <vector>

using namespace std;

double obliczDlugosc(Sygnal & s);
void wypisz(Sygnal & s);
double obliczMin(Sygnal & s);
double obliczMax(Sygnal & s);
double obliczSrednia(Sygnal & s);
double calkuj(Sygnal & s);

#endif
