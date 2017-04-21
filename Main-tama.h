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
	bool sleepy;

	time_t start_t;
	time_t last_event;
	time_t last_sleep; //set = to start when changes
	time_t current_t;
	int sleeping;

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
	void save_tama();
	
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
	void set_name(string n);
	void set_gender(string s);
	void set_age(int a);
	void set_weight(float w);
	void set_hunger(float h);
	void set_happiness(float h);
	void set_discipline(int d);
	void set_poop(bool p);
	void set_sick(bool s);
	void set_lights(bool l);
	void set_sleep(bool s);
	void set_sleepy(bool y);

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
	bool get_sleepy();
};

#endif // MAIN_TAMA_H

