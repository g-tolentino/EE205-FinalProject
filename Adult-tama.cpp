#include "Adult-tama.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

Adult_tama::Adult_tama(string n, string g, int a, int h, int ha, int d, float w) {
	set_name(n);
	set_gender(g);
	set_age(a);
	set_weight(w);
	set_hunger(h);
	set_happiness(ha);
	set_discipline(d);
	set_sleep(false);
	set_poop(false);
	set_sick(false);
	set_lights(true);
}

//Meal = Pasta, snack = Cheesecake
void Adult_tama::feed() {
	if(get_sleep() == true) { return; }
	if(get_lights() == false) { return; }
	int scold = rand()%100;

	//Tamagotchi is full, does not need to eat
	if(get_hunger() == 4) {
		cout << "\n╔═══════════════════════════════════════════════╗"
			 << "\n║              Tamagotchi is full.              ║"
			 << "\n╚═══════════════════════════════════════════════╝";
		return;
	}

	//Figures out if tama doesnt want to eat
	else if(scold <= 10) {
		tama_discipline(get_not_eating());
	}
	
	//Tamagotchi is hungry 
	else {
		int user_choice;
		//Ask what they would like to feed
		cout << "\n╔═══════════════════════════════════════════════╗"
			 << "\n║ Please choose the type of food.               ║"
			 << "\n║ (1) Meal: Pasta                               ║"
			 << "\n║ (2) Snack: Cheesecake                         ║"
			 << "\n╚═══════════════════════════════════════════════╝"
			 << "\n Food Number: ";
		cin >> user_choice;

		//Based on their choice, adjust weight and hunger
		if(user_choice == 1) { //MEAL
			increase_hunger(1.5);
			set_weight(get_weight() + 1);
			return;
		}
		else { //SNACK
			increase_hunger(1);
			set_weight(get_weight() + 1);
			increase_happiness(1);
			return;
		}
	}
}

void Adult_tama::print_female(string s) {
	if(s == "awake") {
		cout << "\n╔═══════════════════════════════════════════════╗"
			 << "\n║                     ︵   ︵                   ║"
			 << "\n║                    | |  | |                   ║"
			 << "\n║                   _| |__| |_                  ║"
			 << "\n║                  |          |                 ║"
			 << "\n║                  |  ό    ό  |                 ║"
			 << "\n║                  | ੭  ᗜ     |੭                ║"
			 << "\n║                  |__________|                 ║"
			 << "\n║                                               ║"
			 << "\n║                                               ║";
	}

	else {
		cout << "\n╔═══════════════════════════════════════════════╗"
			 << "\n║                     ︵   ︵                   ║"
			 << "\n║                    | |  | |         Z         ║"
			 << "\n║                   _| |__| |_      z           ║"
			 << "\n║                  |          |   Z             ║"
			 << "\n║                  |  -    -  |                 ║"
			 << "\n║                  | ੭  ᗜ     |੭                ║"
			 << "\n║                  |__________|                 ║"
			 << "\n║                                               ║"
			 << "\n║                                               ║";
	}
}

void Adult_tama::print_male(string s) {
	if(s == "awake") {
		cout << "\n╔═══════════════════════════════════════════════╗"
			 << "\n║                     ︵   ︵                   ║"
			 << "\n║                    | |  | |                   ║"
			 << "\n║                   _| |__| |_                  ║"
			 << "\n║                  |          |                 ║"
			 << "\n║                  |   ಠ   ಠ  |                 ║"
			 << "\n║                 ┗|    -     |┛                ║"
			 << "\n║                  |__________|                 ║"
			 << "\n║                                               ║"
			 << "\n║                                               ║";
	}

	else {
		cout << "\n╔═══════════════════════════════════════════════╗"
			 << "\n║                     ︵   ︵                   ║"
			 << "\n║                    | |  | |         Z         ║"
			 << "\n║                   _| |__| |_      z           ║"
			 << "\n║                  |          |   Z             ║"
			 << "\n║                  |   -   -  |                 ║"
			 << "\n║                 ┗|    -     |┛                ║"
			 << "\n║                  |__________|                 ║"
			 << "\n║                                               ║"
			 << "\n║                                               ║";
	}
}

void Adult_tama::print_menu() {
	if(get_lights() == false) { print_blank(); }
	
	else if(get_sleep() == true) {
		if(get_gender() == "male") {
			Adult_tama::print_male("sleep");
		}
		else {
			Adult_tama::print_female("sleep");
		}
	}

	else {
		if(get_gender() == "male") {
			Adult_tama::print_male("awake");
		}
		else {
			Adult_tama::print_female("awake");
		}
	}
	main_menu();
	return;
}

void Adult_tama::rand_events() {
	//Decides if the tama will shout at you
		int shouting = rand()%100;
		if(shouting < 20 && get_discipline() < 10 && get_sleep() == false) {
			tama_discipline(get_shout());
		}

		//Tama pooped
		int fate = rand()%100;
		if(fate < 10 && get_sleep() == false) { 
			set_poop(true); 
			time_pooped = time(&time_pooped);
		}

		//Decrease hunger
		fate = rand()%100;
		if(fate < 10) { increase_hunger(-0.5); }

		//Tama gets sick
		fate = rand()%100;
		if(fate < 10 && get_sleep() == false) { set_sick(true); }

		//Decides if tama will start getting sleepy
		if(sleepy == false && get_sleep() == false) {
			fate = rand()%100;
			if(fate < 10) { 
				cout << "\n╔═══════════════════════════════════════════════╗"
					 << "\n║         Tamagotchi is feeling sleepy!         ║"
					 << "\n╚═══════════════════════════════════════════════╝";
				sleepy = true;
				//Time it started getting sleepy
				start_t = time(&start_t);
			}
			else { return; }
		}
		
		if(get_sleep() == false) {
			//Check time difference
			current_t = time(&current_t);
			int ready_to_sleep = difftime(current_t, start_t);
			if(ready_to_sleep >= 10) {
				//tama is now sleeping
				cout << "\n╔═══════════════════════════════════════════════╗"
					 << "\n║            Tamagotchi fell asleep!            ║"
					 << "\n╚═══════════════════════════════════════════════╝";
				set_sleep(true);
				sleepy = false;
				last_sleep = time(&last_sleep);
			}
			else { return; }
		}

		//figures out if its time for tama to wake up
		else {
			//Check time difference
			current_t = time(&current_t);
			int check_if_awake = difftime(current_t, last_sleep);
			if(check_if_awake >= 30) {
				//tama wakes up
				cout << "\n╔═══════════════════════════════════════════════╗"
					 << "\n║              Tamagotchi woke up!              ║"
					 << "\n╚═══════════════════════════════════════════════╝";
				set_sleep(false);
				set_lights(true);
			}
			else { return; }
		}
}

