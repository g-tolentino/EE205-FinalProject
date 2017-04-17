//File Name: Main-tama.h
//This file is a generic Tamagotchi class
#ifndef MAIN_TAMA_H
#define MAIN_TAMA_H

#include <iostream>
#include <string>
using namespace std;

void clear_screen();

class Main_tama {

private:
	string name;
	string gender;
	int age;
	float weight;
	float hunger, happiness; //Max hearts = 4
	int discipline; //Max 10
	bool poop;
	bool sick;
	bool lights;
	bool sleep;

public:
	//Default constructor 
	Main_tama();
	//~Main_tama();
	
	//Age groups will have own feed function
	virtual void feed();
	void game();
	void clean(time_t time_pooped);
	void medicine();
	void light_controls();
	
	//Pretty Print functions
	void print_info();
	void print_egg();
	void main_menu();
	void print_blank();
	virtual void print_menu();
	virtual void print_male();
	virtual void print_female();

	//Age groups will have own list of random events
	virtual void rand_events();

	//Makes sure that happiness and hunger don't exceed 4
	void increase_happiness(float n);
	void increase_hunger(float n);
	
	//Functions that let tamagotchi do on own
	void sleeps(); //Turn light back on when it wakes up

	//Getters and setters
	set_name(string n);
	set_gender(string s);
	set_age(int a);
	set_weight(float w);
	set_hunger(float h);
	set_happiness(float h);
	set_discipline(int d);
	set_poop(bool p);
	set_sick(bool s);
	set_lights(bool l);
	set_sleep(bool s);

	string get_name();
	string get_gender();
	int get_age();
	float get_weight();
	float get_hunger();
	float get_happiness();
	int get_discipline();
	bool get_poop();
	bool get_sick();
	bool get_lights();
	bool get_sleep();
};

#endif // MAIN_TAMA_H

