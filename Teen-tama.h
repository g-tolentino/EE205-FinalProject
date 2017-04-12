//File Name: Teen-tama.h
//Holds the class for a Teen tamagotchi
#ifndef TEEN_TAMA_H
#define TEEN_TAMA_H

#include "Main-tama.h"

class Teen_tama : public Main_tama {

private:

public:
	Teen_tama() : Main_tama() { }
	Teen_tama(string n, string g, int a, int h, int ha, int d);

	virtual void feed();
	virtual void print_info();
	virtual void rand_events();
};
#endif // TEEN_TAMA_H