//File Name: Main-tama.cpp
//This file is functions for generic Tamagotchi class

#include "Main-tama.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

Main_tama::Main_tama() {
	name = gender = ' ';
	age = weight = hunger = happiness = discipline = 0;
	poop = sick = sleep = false;
}

void Main_tama::increase_happiness(float n) {
	happiness = happiness + n;
	if(happiness > 4) { happiness = 4; }
	if(happiness < 0) { happiness = 0; }
}
void Main_tama::increase_hunger(float n) {
	hunger = hunger + n;
	if(hunger > 4) { hunger = 4; }
	if(hunger < 0) { hunger = 0; }
}

//Plays game with tamagotchi
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
	if(wins >= 3) { increase_happiness(0.5); }
}

//Cleans the tamagotchi's poop
void Main_tama::clean(time_t time_pooped) {
	//Get time now and calculate time diff
	time_t now = time(&now);
	int time_diff = difftime(time_pooped, now);
	
	//User cleaned up poop in time
	if(time_diff <= 20) { increase_happiness(0.5); }
	//User did not clean up in time
	else { sick = true; } 
}

//Gives medicine to tamagotchi
void Main_tama::medicine() {
	int injections = 0;
	int user_choice;
	int need = rand()%3;
	
	//Tamagotchi isn't sick
	if(sick == false) { 
		cout << name << " does not need medicine\n"; 
		return; 
	}
	
	//Tamgotchi is sick
	cout << name << " needs " << need << " injection(s).\n";
	while(injections != need) {
		cout << "Would you like to give it medicine? (1)Yes (2)No\n";
		cin >> user_choice;
		if(user_choice == 1) {
			injections++;
			cout << "Giving medicine #" << injections << "\n";
		}
		else {
			return;
		}
	}
	//Tamas don't like getting injections
	increase_happiness(-1);
	sick = false;
}

//Controls the lights 
void Main_tama::light_controls() {
	int user_choice;
	cout << "Would you like to turn the lights (1)ON or (2)OFF?\n";
	
	//Tamagotchi is sleeping
	if(sleep == true) { 
		//Turn off lights
		if(user_choice == 2) { lights = false; }
		//Turn on lights
		else { lights = true; }
	}
	
	//Tamagotchi is not sleeping
	else {
		//Turn off lights
		if(user_choice == 2) {
			cout << name << " can't see anything, please turn on light.\n";
			lights == false;
		}
		//Turn on lights
		else { lights = true; }
	}
}

//NEED TO ACCOUNT FOR 1/2 Hearts
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

void Main_tama::print_menu() {
	cout << "\n";
	if(poop == true) {
		cout << name << " just pooped!\n";
	}
	if(sick == true) { 
		cout << name << " is sick!\n";
	}
	cout << "\n";
	cout << "----------- Menu -----------\n"
		 << "(1) Play a Game\n"
		 << "(2) Feed\n"
		 << "(3) Clean\n"
		 << "(4) Give Medicine\n"
		 << "(5) Lights\n"
		 << "(6) Check Health/Info\n";
	cout << "\n";
}

//Happens when tamagotchi is sleeping
void Main_tama::sleeps() {
	//Randomly determine how long to sleep

	//Sleep for that amount of time

	//Should we ask if they would like to turn off lights?

	//When done sleeping automatically turn lights on
}


//Getters and setters
Main_tama::set_name(string n) { name = n; }
Main_tama::set_gender(string s) { gender = s; }
Main_tama::set_age(int a) { age = a; }
Main_tama::set_weight(float w) { weight = w; }
Main_tama::set_hunger(float h) { hunger = h; }
Main_tama::set_happiness(float h) { happiness = h; }
Main_tama::set_discipline(int d) { discipline = d; }
Main_tama::set_poop(bool p) { poop = p; }
Main_tama::set_sick(bool s) { sick = s; }
Main_tama::set_lights(bool l) { lights = l; }
Main_tama::set_sleep(bool s) { lights = s; }

string Main_tama::get_name() { return name; }
string Main_tama::get_gender() { return gender; }
int Main_tama::get_age() { return age; }
float Main_tama::get_weight() { return weight; }
float Main_tama::get_hunger() { return hunger; }
float Main_tama::get_happiness() { return happiness; }
int Main_tama::get_discipline() { return discipline; }
bool Main_tama::get_poop() { return poop; }
bool Main_tama::get_sick() { return sick; }
bool Main_tama::get_lights() { return lights; }
bool Main_tama::get_sleep() { return sleep; }