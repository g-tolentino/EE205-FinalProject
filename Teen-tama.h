//File Name: Teen-tama.h
//Holds the class for a Teen tamagotchi
#ifndef TEEN_TAMA_H
#define TEEN_TAMA_H

#include "Main-tama.h"

class Teen_tama : public Main_tama {

private:

public:
	Teen_tama(string n, string g, int a, int h, int ha, int d, float w);
	~Teen_tama() {}

	virtual void feed();
	virtual void rand_events();
	virtual void print_male(string s);
	virtual void print_female(string s);
	virtual void print_menu();
};
#endif // TEEN_TAMA_H