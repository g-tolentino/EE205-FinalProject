//File Name: Child-tama.h
//This file holds an inherited class from Main-tama
//Holds the class for a child tamagotchi
#ifndef CHILD_TAMA_H
#define CHILD_TAMA_H

#include "Main-tama.h"

class Child_tama : public Main_tama {

private:

public:
	Child_tama() : Main_tama() { }
	Child_tama(string n, string g, int a, int h, int ha, int d);

	virtual void feed();
	virtual void print_info();
	virtual void rand_events();
};
#endif // CHILD_TAMA_H