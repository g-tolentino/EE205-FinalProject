//File Name: Baby-tama.h
//This file holds an inherited class from Main-tama
//Class for baby Tamagotchi
#ifndef BABY_TAMA_H
#define BABY_TAMA_H
#include "Main-tama.h"
#include <string>
#include <iostream>

class Baby_tama : public Main_tama {

private:

public:
	Baby_tama(string n, string g, int a, float h, float ha, int d, float w);
	~Baby_tama() {}

	virtual void feed();
	virtual void rand_events();
	virtual void print_male(string s);
	virtual void print_female(string s);
	virtual void print_menu();
};

#endif // BABY_TAMA_H