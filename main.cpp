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
Probka probka1 = {0.1, 0.2};



vector<Probka> dane;
Probka probka1(0.1, 0.2);
dane.push_back(probka1);
cout << dane[0.1].first << ", "  << dane[0.2].second;


for (int i = 0; i < wektor.size(); ++i)
{
cout << wektor[i] << endl;
}

}










