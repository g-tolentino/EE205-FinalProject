//File Name: tamagotchi.cpp

#include "Main-tama.h"
#include "Baby-tama.h" // 0-2
#include "Child-tama.h" // 3-10
#include "Teen-tama.h" // 11-19
#include "Adult-tama.h" // 20+ 

#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <fstream>

#define EGG_WAIT 5

using namespace std;

int main() {
	string filename = "saved_tama.txt";
	string name;
	string gender;
	int age = 0;
	float weight;
	float hunger, happiness;
	int discipline;
	time_t born, now; 
	int save = 0;
	int easy_exit = 0;

	while(easy_exit != 2) {
	
		for(int i = 0; i < 50 ; i++) { cout << "\n "; }


		//Ask user if they would like to create a new tama or load a saved tama
		cout << "\n╔═══════════════════════════════════════════════╗"
			 << "\n║             Welcome to Tamagotchi!            ║"
			 << "\n╟═══════════════════════╦═══════════════════════╢"
			 << "\n║ 1. Create a new tama  ║  2. Load saved tama   ║"
			 << "\n╚═══════════════════════╩═══════════════════════╝"
			 << "\n What would you like to do? ";
		int user_choice;
		cin >> user_choice;

		//////////////////////////////////////////////////////////
		/////////////// Create a new tamagotchi //////////////////
		//////////////////////////////////////////////////////////

		if(user_choice == 1) {
			Main_tama egg;
			//Start as egg and wait 5 seconds 
			egg.main_menu();

			//Wait for egg to hatch
			born = time(&born);
			now = time(&now);
			int time_diff = 0;
			while(time_diff != EGG_WAIT) {
				now = time(&now);
				time_diff = difftime(now, born);
			}

			//Egg has hatched, decided gender and name
			//Figure out gender
			int rand_g = rand()%100;
			if(rand_g <= 50) { gender = "female"; }
			else { gender = "male"; }

			//Get name of tama
			cout << "\n Yay! you got a " << gender << " Tamagotchi!"
				 << "\n Please enter Tamagotchi's name: ";
			cin >> name;
			for(int i = 0; i < 50 ; i++) {
				cout << "\n ";
			}
			age = 1;
			hunger = 0;
			happiness = 3;
			discipline = 0;
			weight = rand()%10;
		}

		//////////////////////////////////////////////////////////
		////////////// load a existing tamagotchi ////////////////
		//////////////////////////////////////////////////////////
		else {
			string s;
			ifstream infile(filename.c_str());
			if (!infile.is_open()) {
				cout << " Error in opening input file\n";
				exit(EXIT_FAILURE);
			}
			infile >> s;
			name = s;
			infile >> s;
			gender = s;
			infile >> s;
			age = stoi(s);
			infile >> s;
			weight = stof(s);
			infile >> s;
			hunger = stof(s);
			infile >> s;
			happiness = stof(s);
			infile >> s;
			discipline = stoi(s);
			infile >> s;
			born = stoi(s);

			/*cout 
			 << "\n Name: " << name
			 << "\n Gender: " << gender 
			 << "\n Age: " << age
			 << "\n Weight: " << weight
			 << "\n Hunger: " << hunger
			 << "\n Happiness: " << happiness
			 << "\n Discipline: " << discipline
			 << "\n Time born: " << born;
			*/

			 infile.close();
		}
		save = 0;
		while(save < 7) {
			//////////////////////////////////////////////////////////
			/////////////// Create a BABY tamagotchi /////////////////
			//////////////////////////////////////////////////////////
			if(age >= 0 && age < 3) {
				Baby_tama b(name, gender, age, hunger, happiness, discipline, weight);
				born = time(&born); //HOLDS THE TIME WHEN TAMA WAS BORN
				while(age > 0 && age < 3 ) {
					age = b.get_age();
					hunger = b.get_hunger();
					happiness = b.get_happiness();
					discipline = b.get_discipline();
					weight = b.get_weight();
					
					save = b.run_through(born, filename);
					if(save == 7) { age = 100; easy_exit = 2;}
					if(save == 4) { age = -2; }
					if(save == 8) { age = 100; easy_exit = 2;}
				}
			}
			
			//////////////////////////////////////////////////////////
			/////////////// Create a CHILD tamagotchi ////////////////
			//////////////////////////////////////////////////////////
			if(age >= 3 && age < 10) {
				Child_tama c(name, gender, age, hunger, happiness, discipline, weight);
				cout << "\n╔═══════════════════════════════════════════════╗"
					 << "\n║       Your Tamagotchi is now a child!         ║"
					 << "\n╚═══════════════════════════════════════════════╝";
				while(age > 0 && age < 10) {
					age = c.get_age();
					hunger = c.get_hunger();
					happiness = c.get_happiness();
					discipline = c.get_discipline();
					weight = c.get_weight();
					
					save = c.run_through(born, filename);
					if(save == 7) { age = 100; easy_exit = 2;}
					if(save == 4) { age = -2; }
					if(save == 8) { age = 100; easy_exit = 2;}
				}
			}

			/////////////////////////////////////////////////////////
			/////////////// Create a TEEN tamagotchi ////////////////
			/////////////////////////////////////////////////////////
			if(age >= 10 && age < 19) {
				Teen_tama t(name, gender, age, hunger, happiness, discipline, weight);
				cout << "\n╔═══════════════════════════════════════════════╗"
					 << "\n║        Your Tamagotchi is now a teen!         ║"
					 << "\n╚═══════════════════════════════════════════════╝";
				while(age > 0 && age < 19) {
					age = t.get_age();
					hunger = t.get_hunger();
					happiness = t.get_happiness();
					discipline = t.get_discipline();
					weight = t.get_weight();

					save = t.run_through(born, filename);
					if(save == 7) { age = 100; easy_exit = 2;}
					if(save == 4) { age = -2; }
					if(save == 8) { age = 100; easy_exit = 2;}
				}
			}

			/////////////////////////////////////////////////////////
			/////////////// Create an ADULT tamagotchi //////////////
			/////////////////////////////////////////////////////////
			if(age >= 19 && age < 30) {
				Adult_tama a(name, gender, age, hunger, happiness, discipline, weight);
				cout << "\n╔═══════════════════════════════════════════════╗"
					 << "\n║       Your Tamagotchi is now an adult!        ║"
					 << "\n╚═══════════════════════════════════════════════╝";
				while(age > 0 && age < 30) {
					age = a.get_age();
					hunger = a.get_hunger();
					happiness = a.get_happiness();
					discipline = a.get_discipline();
					weight = a.get_weight();
					a.set_sick(true);
					save = a.run_through(born, filename);
					if(save == 7) { age = 100; easy_exit = 2;}
					if(save == 4) { age = -2; }
					if(save == 8) { age = 100; easy_exit = 2;}

					//Decides if the tama will leave
					int leave = rand()%100;
					if(age > 23 && leave < 45 && age != 100) { age = -1; }
							
				}
			}
			if(age >= 30 && age != 100) { age = -1; }

			/////////////////////////////////////////////////////////
			///////////////////// Tamagotchi Left ///////////////////
			/////////////////////////////////////////////////////////
			Main_tama gone;
			if(age < 0) {
				user_choice = gone.print_gone(age);
				//user wants to quit
				if(user_choice == 2) { save = 7; easy_exit = 2;}
				//user wants to restart
				else { save = 7; easy_exit = 0; }
			}
		} // End of while save < 7
	}// End of while easy_exit != 2

	cout << "\n╔═══════════════════════════════════════════════╗"
		 << "\n║                   Good Bye!                   ║"
		 << "\n╚═══════════════════════════════════════════════╝"
		 << "\n";
	return 0;
}
