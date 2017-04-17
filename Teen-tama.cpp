//File Name: Teen-tama.cpp
//This file is functions for generic Tamagotchi class

#include "Teen-tama.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

#define MAX_WEIGHT 30
#define MIN_WEIGHT 20

Teen_tama::Teen_tama(string n, string g, int a, int h, int ha, int d) {
	set_name(n);
	set_gender(g);
	set_age(a);
	//Weight of teen
	int w = rand()%(MAX_WEIGHT-MIN_WEIGHT)+MIN_WEIGHT;
	set_weight(w);
	set_hunger(h);
	set_happiness(ha);
	set_discipline(d);
}

//Meal = Omelet, snack = Sundae
void Teen_tama::feed() {
	//Tamagotchi is full, does not need to eat
	if(get_hunger() == 4) {
		cout << get_name() << " is full\n";
		return;
	}
	
	//Tamagotchi is hungry 
	else {
		int user_choice;
		//Ask what they would like to feed
		cout << "Please choose the type of food.\n"
			 << "(1) Meal: Omelet\n"
			 << "(2) Snack: Sundae\n"
			 << "Food Number: ";
		cin >> user_choice;

		//Based on their choice, adjust weight and hunger
		if(user_choice == 1) { //MEAL
			increase_hunger(1.5);
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
}

void Teen_tama::print_female() {
	cout << "\n╔═══════════════════════════════════════════════╗"
		 << "\n║                                               ║"
		 << "\n║                     ︵   ︵                   ║"
		 << "\n║                   _| |__| |_                  ║"
		 << "\n║                  |          |                 ║"
		 << "\n║                  |  ○    ○  |                 ║"
		 << "\n║                  | ੭   w    |੭                ║"
		 << "\n║                  |__________|                 ║"
		 << "\n║                                               ║"
		 << "\n║                                               ║";
}

void Teen_tama::print_male() {
	cout << "\n╔═══════════════════════════════════════════════╗"
		 << "\n║                                               ║"
		 << "\n║                     ︵   ︵                   ║"
		 << "\n║                   _| |__| |_                  ║"
		 << "\n║                  |          |                 ║"
		 << "\n║                  |  ○`  ´○  |                 ║"
		 << "\n║                  | っ   ౪   |っ               ║"
		 << "\n║                  |__________|                 ║"
		 << "\n║                                               ║"
		 << "\n║                                               ║";
}

void Teen_tama::print_menu() {
	if(get_lights() == false) {
		print_blank();
	}
	else {
		if(get_gender() == "male") {
			Teen_tama::print_male();
		}
		else {
			Teen_tama::print_female();
		}
	}
	main_menu();
}

void Teen_tama::rand_events() {

}