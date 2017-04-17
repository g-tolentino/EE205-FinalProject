//File Name: Adult-tama.h
//Class for Adult tamagotchi
#ifndef ADULT_TAMA_H
#define ADULT_TAMA_H

#include "Main-tama.h"

class Adult_tama : public Main_tama {

private:

public:
	Adult_tama(string n, string g, int a, int h, int ha, int d);
	//~Adult_tama() {}

	virtual void feed();
	virtual void rand_events();
	virtual void print_male();
	virtual void print_female();
	virtual void print_menu();
};
#endif // ADULT_TAMA_H