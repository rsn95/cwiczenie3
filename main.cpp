#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>


using namespace std;



int main(int argc, char* argv[])
{
    if (argc !=2)
    {
        return -1;
    }
    cout << argv[1] << endl;
    string sygnal = argv[1];
    cout << "Odczytuje plik: " << sygnal << endl;
}

ifstream plik("sygnal.csv");

string linia;
while (getline(sygnal, linia))
{
cout << linia << endl;
}
plik.close();









