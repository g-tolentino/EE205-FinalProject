//File Name: Main-tama.h
//This file is a generic Tamagotchi class
#ifndef MAIN_TAMA_H
#define MAIN_TAMA_H

#include <iostream>
#include <string>
using namespace std;

class Main_tama {

private:
	string name;
	string gender;
	int age;
	int weight;
	int hunger, happiness; //Max hearts = 4
	int discipline;
	bool poop;
	bool sick;

public:
	//Default constructor 
	Main_tama() {
		name = gender = ' ';
		age = weight = hunger = happiness = discipline = 0;
		poop = sick = false;
	}
	//Age groups will have own feed function
	virtual feed();
	void game();
	void clean(int time_pooped);
	void medicine();
	void lights();
	void print_info();
	//Makes sure that happiness and hunger don't exceed 4
	void increase_happiness();
	void increase_hunger();

	//Getters and setters
	set_name(string n);
	set_gender(string s);
	set_age(int a);
	set_weight(int w);
	set_hunger(int h);
	set_happiness(int h);
	set_discipline(int d);
	set_poop(bool p);
	set_sick(bool s);

	string get_name();
	string get_gender();
	int get_age();
	int get_weight();
	int get_hunger();
	int get_happiness();
	int get_discipline();
	bool get_poop();
	bool get_sick();
};

#endif // MAIN_TAMA_H