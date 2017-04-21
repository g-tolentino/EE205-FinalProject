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
			 << "Food Number: ";
		cin >> user_choice;

		//Based on their choice, adjust weight and hunger
		if(user_choice == 1) { //MEAL
			increase_hunger(2);
			set_weight(get_weight() + 1);
			return;
		}
		else { //SNACK
			increase_hunger(0.5);
			set_weight(get_weight() + 0.5);
			increase_happiness(1.5);
			return;
		}
	}
}

void Child_tama::print_female() {
	cout << "\n╔═══════════════════════════════════════════════╗"
		 << "\n║                                               ║"
		 << "\n║                                               ║"
		 << "\n║                   __へ__へ__                  ║"
		 << "\n║                  |          |                 ║"
		 << "\n║                  | ᗒ      ᗕ |                 ║"
		 << "\n║                  | ੭   ³    |੭                ║"
		 << "\n║                  |__________|                 ║"
		 << "\n║                                               ║"
		 << "\n║                                               ║";
}

void Child_tama::print_male() {
	cout << "\n╔═══════════════════════════════════════════════╗"
		 << "\n║                                               ║"
		 << "\n║                                               ║"
		 << "\n║                   __へへへ__                  ║"
		 << "\n║                  |          |                 ║"
		 << "\n║                  |  •    •  |                 ║"
		 << "\n║                  | っ   ×   |っ               ║"
		 << "\n║                  |__________|                 ║"
		 << "\n║                                               ║"
		 << "\n║                                               ║";
}

void Child_tama::print_menu() {
	if(get_lights() == false) {
		print_blank();
	}
	else {
		if(get_gender() == "male") {
			Child_tama::print_male();
		}
		else {
			Child_tama::print_female();
		}
	}
	main_menu();
}

void Child_tama::rand_events() {
	time(&current_t);
	int x;
	x = diff(current_t,last_event) / 20;
        increase_hunger(-x*0.5);
        hungerdrops += x; //for every 2 hunger drops, Tama will poop
        for (hungerdrops < 1){
                hungerdrops -= 2;
                poop = true;
        }
        increase_happiness(-x*0.5);
        if (diff(current_t,last_sleep) >= 120 && sleepy == false){
                sleepy=true;
                time(&tired_t);
        }
        if (sleepy == true && diff(current_t,tired_t) >=10){
                sleep = true;
                time(&sleep_t);
                sleeping = rand()%10 + 10; //set random sleep time
        }
        if (sleep == true && diff(current_t,sleep_t) >= sleeping){
                sleep = false;
                sleepy = false;
		if(light == false){
			light = true;
		}
        }
        last_event = current_t;
	//Children like to play more
	//If neglected a lot then happiness goes down
}
