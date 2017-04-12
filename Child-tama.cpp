//File Name: Child-tama.cpp
//This file is functions for generic Tamagotchi class

#include "Child-tama.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

#define MAX_WEIGHT 20
#define MIN_WEIGHT 10

Child_tama::Child_tama(string n, string g, int a, int h, int ha, int d) {
	set_name(n);
	set_gender(g);
	set_age(a);
	//Weight of child
	int w = rand()%(MAX_WEIGHT-MIN_WEIGHT)+MIN_WEIGHT;
	set_weight(w);
	set_hunger(h);
	set_happiness(ha);
	set_discipline(d);
}

//Meal = Sandwich, snack = chocolate
void Child_tama::feed() {
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
			 << "(1) Meal: Sandwich\n"
			 << "(2) Snack: Chocolate\n"
			 << "\n";
		cin >> user_choice;

		//Based on their choice, adjust weight and hunger
		if(user_choice == 1) { //MEAL
			increase_hunger(2);
			set_weight(get_weight() + 1);
		}
		else { //SNACK
			increase_hunger(0.5);
			set_weight(get_weight() + 0.5);
			increase_happiness(1.5);
		}
	}
}

void Child_tama::print_info() {
	cout << "Stage in life: Child\n";
	Main_tama::print_info();
}

void rand_events() {
	//Children like to play more
	//If neglected a lot then happiness goes down
}