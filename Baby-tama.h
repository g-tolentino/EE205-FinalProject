//File Name: Baby-tama.h
//This file holds an inherited class from Main-tama
//Class for baby Tamagotchi
#ifndef BABY_TAMA_H
#define BABY_TAMA_H
#include "Main-tama.h"

class Baby_tama : public Main_tama {

private:

public:
	Baby_tama() : Main_tama() { }
	Baby_tama(string n, string g, int a, int h, int ha, int d);

	virtual void feed();
	virtual void print_info();
	virtual void rand_events();
};

#endif // BABY_TAMA_H