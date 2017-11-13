#include "sygnal.hpp"

class Sygnal{
private:
	vector<Probka> dane;
public:
	Sygnal(void);
	Sygnal(vector<Probka> dane);



	vector<Probka> getDane() {
		return this->dane;
	}

	friend class AnalizatorSygnalu;
	friend class SygnalLoader;
};

Sygnal::Sygnal(void) {

}

Sygnal::Sygnal(vector<Probka> dane) {
	this->dane = dane;
}


