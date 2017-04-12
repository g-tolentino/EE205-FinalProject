#include "Adult-tama.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

#define MAX_WEIGHT 33
#define MIN_WEIGHT 30

Adult_tama::Adult_tama(string n, string g, int a, int h, int ha, int d) {
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

//Meal = Pasta, snack = Cheesecake
void Adult_tama::feed() {
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
			 << "(1) Meal: Pasta\n"
			 << "(2) Snack: Cheesecake\n"
			 << "\n";
		cin >> user_choice;

		//Based on their choice, adjust weight and hunger
		if(user_choice == 1) { //MEAL
			increase_hunger(1.5);
			set_weight(get_weight() + 1);
		}
		else { //SNACK
			increase_hunger(1);
			set_weight(get_weight() + 1);
			increase_happiness(1);
		}
	}
}

void Adult_tama::print_info() {
	cout << "Stage in life: Adult\n";
	Main_tama::print_info();
}

void rand_events() {

}