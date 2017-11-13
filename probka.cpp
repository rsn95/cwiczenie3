#include "probka.hpp"

class Probka {
private:
	double t, x;
public:
	Probka(void);
	Probka(double x, double t);

	double getX() {
		return this->x;
	}

	double getT() {
		return this->t;
	}
};

Probka::Probka(void) {
	x = 0;
	t = 0;
}

Probka::Probka(double x, double t) {
	this->x = x;
	this->t = t;
}

