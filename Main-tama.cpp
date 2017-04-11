//File Name: Main-tama.cpp
//This file is functions for generic Tamagotchi class

#include "Main-tama.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

void Main_tama::increase_happiness() {
	happiness++;
	if(happiness > 4) { happiness = 4; }
}
void Main_tama::increase_hunger() {
	hunger++;
	if(hunger > 4) { hunger = 4; }
}

//Age groups will have own feed function
void Main_tama::game() {
	int rounds = 0;
	int wins = 0;
	
	while(rounds != 5) {
		
		//Randomly choose left or right 
		int tama_choice = rand()%100;
		
		//Ask user for their choice
		int user_choice;
		cout << "---------- Round #" << rounds + 1 << " ----------\n";
		cout << "Choose either (1)Left, (2)Right, or (3)Quit: ";
		cin >> user_choice;
		
		//Decide if they won or not
		if(user_choice == 3) { return; } //Quit
		if(tama_choice <= 50 && user_choice == 1) { //Both Left
			cout << "You got it correct!\n";
			wins++;
		}
		else if(tama_choice > 50 && user_choice == 2) { //Both Right
			cout << "You got it correct!\n";
			wins++;
		}
		else { //Lossed
			cout << "You got it wrong!\n";
		}
	}
	
	//Increase happiness if user won 3 or more
	if(wins >= 3) { increase_happiness(); }
}

void Main_tama::clean(time_t time_pooped) {
	//Get time now and calculate time diff
	time_t now = time(&now);
	int time_diff = difftime(time_pooped, now);
	//User cleaned up poop in time
	
}

void Main_tama::medicine() {

}

void Main_tama::lights() {

}

void Main_tama::print_info() {
	cout << "\nName: " << name
		 << "\nGender: " << gender 
		 << "\nAge / Weight: " << age << " / " << weight;
	cout << "Hunger: ";
	for(int h = 0; h < hunger; h++) {
		cout << "+";
	}
	cout << "Happiness: ";
	for(int h = 0; h < happiness; h++) {
		cout << "+";
	}
	cout << "Discipline: ";
	for(int h = 0; h < discipline; h++) {
		cout << "+";
	}
}


//Getters and setters
Main_tama::set_name(string n) { name = n; }
Main_tama::set_gender(string s) { gender = s; }
Main_tama::set_age(int a) { age = a; }
Main_tama::set_weight(int w) { weight = w; }
Main_tama::set_hunger(int h) { hunger = h; }
Main_tama::set_happiness(int h) { happiness = h; }
Main_tama::set_discipline(int d) { discipline = d; }
Main_tama::set_poop(bool p) { poop = p; }
Main_tama::set_sick(bool s) { sick = s; }

string Main_tama::get_name() { return name; }
string Main_tama::get_gender() { return gender; }
int Main_tama::get_age() { return age; }
int Main_tama::get_weight() { return weight; }
int Main_tama::get_hunger() { return hunger; }
int Main_tama::get_happiness() { return happiness; }
int Main_tama::get_discipline() { return discipline; }
bool Main_tama::get_poop() { return poop; }
bool Main_tama::get_sick() { return sick; }