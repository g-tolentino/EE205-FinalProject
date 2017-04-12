//File Name: Adult-tama.h
//Class for Adult tamagotchi
#ifndef ADULT_TAMA_H
#define ADULT_TAMA_H

#include "Main-tama.h"

class Adult_tama : public Main_tama {

private:

public:
	Adult_tama() : Main_tama() { }
	Adult_tama(string n, string g, int a, int h, int ha, int d);

	virtual void feed();
	virtual void print_info();
	virtual void rand_events();
};
#endif // ADULT_TAMA_H