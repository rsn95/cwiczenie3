#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <vector>


using namespace std;



int main(int argc, char* argv[])
{
    if (argc !=2)
    {
        throw runtime_error("sygnal.csv");
        return -1;
    }
    cout << argv[1] << endl;
    string sygnal = argv[1];
    cout << "Odczytuje plik: " << sygnal << endl;


ifstream plik("sygnal.csv");


string linia;


while (getline(plik, linia))

{
cout << linia << endl;
}

stringstream ss(linia);
double x1, x2;
ss >> x1;
ss.ignore();
ss >> x2;

struct Probka
{
double t;
double x;
};
Probka probka1 = {};





vector<Probka> dane;

Probka probka1{};
dane.push_back(Probka);
dane.push_back(probka1(0.2, 0.3));
cout << dane[0].first << ", " << dane[0].second;
plik.close();
}











