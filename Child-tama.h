//File Name: Child-tama.h
//This file holds an inherited class from Main-tama
//Holds the class for a child tamagotchi
#ifndef CHILD_TAMA_H
#define CHILD_TAMA_H

#include "Main-tama.h"

class Child_tama : public Main_tama {

private:

public:
	Child_tama(string n, string g, int a, int h, int ha, int d, float w);
	~Child_tama() {}

	virtual void feed();
	virtual void rand_events();
	virtual void print_male(string s);
	virtual void print_female(string s);
	virtual void print_menu();
};
#endif // CHILD_TAMA_H