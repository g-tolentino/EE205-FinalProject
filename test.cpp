//File Name: test.cpp
#include "Main-tama.h"
#include "Baby-tama.h"
#include "Child-tama.h"
#include "Teen-tama.h"
#include "Adult-tama.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

int main() {

	//Ask if user would like to create a new tama or load a saved tama
		
		Main_tama *egg = new Main_tama;
		egg->main_menu();
		//New tama. Start as egg, wait  10 seconds 
		cout << "\nStatus: Waiting for egg to hatch...";
		time_t now = time(&now);
		time_t now1 = time(&now1);
		int time_diff;
		while(time_diff != 10) {
			now1 = time(&now1);
			time_diff = difftime(now1, now);
		}
		
		//Egg hatched, now its baby
		string tama_name; 
		string gender;
		//Decide gender
		int rand_g = rand()%100;
		if(rand_g <= 50) { gender = "female"; }
		else { gender = "male"; }
		//Get name of tama
		cout << "\nYay! You got a " << gender << " Tamagotchi!\n"
			 << "Please enter Tamagotchi's name: ";
		cin >> tama_name;
		//Create a baby tama (name, gender, age, hunger, happy, discipline)
		Baby_tama *b = new Baby_tama(tama_name, gender, 1, 2, 3, 0);
		b->print_menu();
		
		Child_tama *c = new Child_tama(tama_name, gender, 1, 2, 3, 0);
		c->print_menu();
		
		Teen_tama *t = new Teen_tama(tama_name, gender, 1, 2, 3, 0);
		t->print_menu();
		
		Adult_tama *a = new Adult_tama(tama_name, gender, 1, 2, 3, 0);
		a->set_poop(true);
		a->set_sick(true);
		a->print_menu();
		a->print_info();
		
		int user_choice;
		cout << "\nWhat would you like to do? ";
		cin >> user_choice;
		int count = 0;
		while(count != 7) {
			
			count++;
			switch(user_choice) {
				case 1:
					a->game();
					clear_screen();
					a->print_menu();
					break;
				case 2:
					a->feed();
					clear_screen();
					a->print_menu();
					break;
				case 3:
					a->clean(time(&now));
					clear_screen();
					a->print_menu();
					break;
				case 4:
					a->medicine();
					clear_screen();
					a->print_menu();
					break;
				case 5:
					a->light_controls();
					clear_screen();
					a->print_menu();
					break;
				case 6:
					a->print_info();
					clear_screen();
					a->print_menu();
					break;
				default: 
					cout << "That is not an option.\n";
			}
			cout << "\nWhat would you like to do? ";
			cin >> user_choice;
		}


	return 0;	
}