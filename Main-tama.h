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
	float weight;
	float hunger, happiness; //Max hearts = 4
	int discipline; //Max 10

	bool sleep = false;
	bool poop = false;
	bool sick = false;
	bool lights = true;

	//time_t time_pooped = 0;

	string shout = " just shouted at you. Would you like to scold them?";
	string not_eating = " doesn't want to eat. Would you like to scold them?";

public:
	//Default constructor 
	Main_tama();
	//~Main_tama();
	
	//Age groups will have own feed function
	virtual void feed();
	void game();
	void clean();
	int medicine();
	void light_controls();
	void save_tama(string filename, time_t born);
	
	//Pretty Print functions
	void print_info();
	void print_egg();
	void main_menu();
	void print_blank();
	int print_gone(int a);
	virtual void print_menu();
	virtual void print_male(string s);
	virtual void print_female(string s);

	//Age groups will have own list of random events
	virtual void rand_events();

	//Based on the user's choice, perform the specific function
	int operation_selected(int user_choice, string filename, time_t born);
	int run_through(time_t born, string filename);

	//Makes sure that happiness and hunger don't exceed 4
	void increase_happiness(float n);
	void increase_hunger(float n);
	void increase_age(int t_diff);
	void increase_discipline(int n);
	
	//Functions that let tamagotchi do on own
	void tama_discipline(string m);

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
	void set_time_pooped(time_t tp);

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
	time_t get_time_pooped();

	string get_shout();
	string get_not_eating();

protected:
	time_t start_t;
	time_t last_event;
	time_t last_sleep; //set = to start when changes
	time_t current_t;
	time_t time_pooped;
	int sleeping;
	bool sleepy = false;
};

#endif // MAIN_TAMA_H

