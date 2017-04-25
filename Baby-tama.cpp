//File Name: Baby-tama.cpp
//This file is functions for generic Tamagotchi class

#include "Baby-tama.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

Baby_tama::Baby_tama(string n, string g, int a, float h, float ha, int d) {
	set_name(n);
	set_gender(g);
	set_age(a);
	//Weight of baby, between 1-10
	float w = rand()%10;
	set_weight(w);
	set_hunger(h);
	set_happiness(ha);
	set_discipline(d);
}

//Meal = milk, snack = cookie
void Baby_tama::feed() {
	if(get_sleep() == true) { return; }

	//Tamagotchi is full, does not need to eat
	if(get_hunger() == 4) {
		cout << get_name() << " is full\n";
	}
	
	//Tamagotchi is hungry 
	else {
		int user_choice;
		//Ask what they would like to feed
		cout << "Please choose the type of food.\n"
			 << "(1) Meal: Milk\n"
			 << "(2) Snack: Cookie\n"
			 << "Food Number: ";
		cin >> user_choice;

		//Based on their choice, adjust weight and hunger
		if(user_choice == 1) { //MEAL
			increase_hunger(2);
			set_weight(get_weight() + 1);
			return;
		}
		else { //SNACK
			increase_hunger(1);
			set_weight(get_weight() + 0.5);
			increase_happiness(1);
			return;
		}
	}
	return;
}

void Baby_tama::print_female() {
	cout << "\n╔═══════════════════════════════════════════════╗"
		 << "\n║                                               ║"
		 << "\n║                                               ║"
		 << "\n║                   _∩______∩_                  ║"
		 << "\n║                  |          |                 ║"
		 << "\n║                  |  ^  o  ^ |                 ║"
		 << "\n║                  |__________|                 ║"
		 << "\n║                                               ║"
		 << "\n║                                               ║"
		 << "\n║                                               ║";
}

void Baby_tama::print_male() {
	cout << "\n╔═══════════════════════════════════════════════╗"
		 << "\n║                                               ║"
		 << "\n║                                               ║"
		 << "\n║                   _∩______∩_                  ║"
		 << "\n║                  |          |                 ║"
		 << "\n║                  | .  +  .  |                 ║"
		 << "\n║                  |__________|                 ║"
		 << "\n║                                               ║"
		 << "\n║                                               ║"
		 << "\n║                                               ║";
}

void Baby_tama::print_menu() {
	if(get_lights() == false) {
		print_blank();
	}
	else {
		if(get_gender() == "male") {
			Baby_tama::print_male();
		}
		else {
			Baby_tama::print_female();
		}
	}
	main_menu();
	return;
}

void Baby_tama::rand_events() {
	time_t tired_t;
	time_t sleep_t;
	time(&current_t);
	int x;
	x = difftime(current_t,last_event) / 5;
	increase_hunger(-x*0.5);
	//hungerdrops += x; //for every 2 hunger drops, Tama will poop
	for ( ; get_hunger() < 1; increase_hunger(-2)) {
		set_poop(true);
	}
	x = x / 2;
	increase_happiness(-x*0.5);
	if (difftime(current_t,last_sleep) >= 20 && sleepy == false){
		sleepy = true;
		time(&tired_t);
	}
	if (sleepy == true && difftime(current_t,tired_t) >=10){
		set_sleep(true);
		time(&sleep_t);
		sleeping = rand()%10 + 10; //set random sleep time
	}
	if (get_sleep() == true && difftime(current_t,sleep_t) >= sleeping){
		set_sleep(false);
		sleepy = false;
		if (get_lights() == false){
			set_lights(true);//Tama automatically turns on light when wakes up
		}
	}
	last_event = current_t;
}
