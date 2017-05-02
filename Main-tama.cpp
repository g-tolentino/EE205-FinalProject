//File Name: Main-tama.cpp
//This file is functions for generic Tamagotchi class

#include "Main-tama.h"
#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
using namespace std;

Main_tama::Main_tama() {
	name = gender = ' ';
	age = weight = hunger = happiness = discipline = 0;
	poop = sick = sleep = false;
	lights = true;
}

void Main_tama::feed() {cout << "\n";}

//Plays game with tamagotchi
void Main_tama::game() {
	int rounds = 0;
	int wins = 0;

	if(sleep == true) { return; }
	if(lights == false) { return; }

	//Directions
	cout << "\n╔═══════════════════════════════════════════════╗"
		 << "\n║         Welcome to the guessing game!         ║"
		 << "\n║ Directions:                                   ║"
		 << "\n║ Guess the direction your tamagotchi is facing.║"
		 << "\n║ Ready. Set. GO!                               ║"
		 << "\n╚═══════════════════════════════════════════════╝";
	
	while(rounds != 5) {
		
		//Randomly choose left or right 
		int tama_choice = rand()%100;
		
		//Ask user for their choice
		int user_choice;
		cout << "\n";
		cout << "\n ----------- Round #" << rounds + 1 << " ------------";
		cout << "\n Choose either (1)Left or (2)Right: ";
		cin >> user_choice;
		
		//Decide if they won or not
		if(tama_choice <= 50 && user_choice == 1) { //Both Left
			cout << "\n\t You got it correct!";
			wins++;
		}
		else if(tama_choice > 50 && user_choice == 2) { //Both Right
			cout << "\n\t You got it correct!";
			wins++;
		}
		else { //Lossed
			cout << "\n\t You got it wrong!";
		}
		rounds++;
	}
	for(int i = 0; i < 50 ; i++) { cout << "\n "; }
	cout << "\n╔═══════════════════════════════════════════════╗"
		 << "\n║              You won " << wins << " times(s)!              ║"
		 << "\n╚═══════════════════════════════════════════════╝";
	
	//Increase happiness if user won 3 or more
	if(wins >= 3) { increase_happiness(0.5); }
	return;
}

//Cleans the tamagotchi's poop
void Main_tama::clean() {
	if(sleep == true) { return; }
	if(poop == false) { return; }
	if(lights == false) { return; }

	//Get time now and calculate time diff
	time_t now = time(&now);
	int time_diff = difftime(time_pooped, now);
	
	//User cleaned up poop in time
	if(time_diff <= 20) { 
		poop = false;
		increase_happiness(0.5); 
		return;
	}
	//User did not clean up in time
	else { 
		cout << "\n╔═══════════════════════════════════════════════╗"
			 << "\n║      You did not clean the poop in time.      ║"
			 << "\n╚═══════════════════════════════════════════════╝";
		sick = true; 
		return;
	} 
}

//Gives medicine to tamagotchi
int Main_tama::medicine() {
	if(sleep == true) { return 0; }
	if(lights == false) { return 0; }
	
	int injections = 0;
	int user_choice;
	int need = rand()%3 + 1;
	
	//Tamagotchi isn't sick
	if(sick == false) { 
		cout << "\n╔═══════════════════════════════════════════════╗"
			 << "\n║       Tamagotchi does not need medicine.      ║"
			 << "\n╚═══════════════════════════════════════════════╝";
		return 0;
	}
	else {
		//Tamgotchi is sick
		cout << " " << name << " needs " << need << " medication(s).\n";
		while(injections != need) {
			cout << "\n Would you like to give it medicine? (1)Yes (2)No: ";
			cin >> user_choice;
			if(user_choice == 1) {
				injections++;
				cout << " Giving medicine #" << injections << "\n";
			}
			else {
				return 0;
			}
		}
		//Tamas don't like getting injections
		increase_happiness(-1);
		sick = false;
		
		//If the medicines did not work
		int sick_leave = rand()%100;
		if(sick_leave < 10) {
			cout << "\n╔═══════════════════════════════════════════════╗"
				 << "\n║         The medication did not work.          ║"
				 << "\n╚═══════════════════════════════════════════════╝";
			sick = true; 
			return 4; 
		}
		else { return 0; } 
	}
}

//Controls the lights 
void Main_tama::light_controls() {
	int user_choice;
	cout << "\n Would you like to turn the lights (1)ON or (2)OFF?: ";
	cin >> user_choice;
	
	//Tamagotchi is sleeping
	if(sleep == true) { 
		//Turn off lights
		if(user_choice == 2) { 
			increase_happiness(1);
			lights = false; 
			return;
		}
		//Turn on lights
		else { lights = true; return;}
	}
	
	//Tamagotchi is not sleeping
	else {
		//Turn off lights
		if(user_choice == 2) {
			cout << "\n╔═══════════════════════════════════════════════╗"
				 << "\n║ Tamagotchi can't see, please turn on lights.  ║"
				 << "\n╚═══════════════════════════════════════════════╝";
			lights = false;
			return;
		}
		//Turn on lights
		else { lights = true; return;}
	}

	return;
}

void Main_tama::save_tama(string filename, time_t born) {
	cout << "\n╔═══════════════════════════════════════════════╗"
		 << "\n║           Saving your Tamagotchi...           ║"
		 << "\n╚═══════════════════════════════════════════════╝";

		ofstream outfile(filename);
		if(outfile.is_open()) {
			outfile << name;
			outfile << "\n" << gender;
			outfile << "\n" << age;
			outfile << "\n" << weight;
			outfile << "\n" << hunger;
			outfile << "\n" << happiness;
			outfile << "\n" << discipline;
			outfile << "\n" << born;
			outfile.close();
		}
		else { cout << "\n Unable to open file" << filename; return;}
		
	cout << "\n╔═══════════════════════════════════════════════╗"
		 << "\n║               Save successful!                ║"
		 << "\n╚═══════════════════════════════════════════════╝";
}

///////////////////////////////////////////////
//////////// Pretty Print functions ///////////
///////////////////////////////////////////////

//NEED TO ACCOUNT FOR 1/2 Hearts
void Main_tama::print_info() {
	cout << "\n╔═══════════════════════════════════════════════╗"
		 << "\n║            Tamagotchi Information:            ║"
		 << "\n╚═══════════════════════════════════════════════╝"
		 << "\n Name: " << name
		 << "\n Gender: " << gender 
		 << "\n Age: " << age
		 << "\n Weight: " << weight
		 << "\n Hunger: " << hunger;
	if(hunger == 4) { cout << ", Full!"; }
	cout << "\n Happiness: " << happiness;
	if(happiness == 4) { cout << ", Full!"; }
	cout << "\n Discipline: " << discipline; 
	if(discipline == 13) { cout << ", Full!"; }
	return;
}

void Main_tama::print_egg() {
	cout << "\n╔═══════════════════════════════════════════════╗ "
	 	 << "\n║                                               ║ "
	 	 << "\n║                    _________                  ║ "
		 << "\n║                   /         \\                 ║ "
	 	 << "\n║                  |           |                ║ "
	 	 << "\n║                  |   ❤ ❤ ❤   |                ║ "
	 	 << "\n║                  |           |                ║ "
	 	 << "\n║                   \\_________/                 ║ "
		 << "\n║                                               ║ "
	 	 << "\n║                                               ║ ";
	return;
}

void Main_tama::print_blank() {
	cout << "\n╔═══════════════════════════════════════════════╗ "
	 	 << "\n║                                               ║ "
	 	 << "\n║                                               ║ "
		 << "\n║                                               ║ "
	 	 << "\n║                                               ║ "
	 	 << "\n║                                               ║ "
	 	 << "\n║                                               ║ "
	 	 << "\n║                                               ║ "
		 << "\n║                                               ║ "
	 	 << "\n║                                               ║ ";
	return;
}

void Main_tama::main_menu() {
	if(age == 0) { print_egg(); }
	cout << "\n╟═══════════════════════════════════════════════╢"
		 << "\n║                    Message:                   ║";

	if(age == 0) {
		cout << "\n║       -Status: Waiting for egg to hatch       ║";
	}
	
	if(lights == false) {
		cout << "\n║       -Lights are currently off               ║";
	}		

	if(sleepy == true) {
		cout << "\n║       -Tamagotchi is getting sleepy           ║";
	}

	if(sleep == true) {
		cout << "\n║       -Tamagotchi is sleeping                 ║";
	} 

	if(poop == true) {
		cout << "\n║       -Health Status: Tamagotchi pooped       ║";
	}

	if(sick == true) { 
		cout << "\n║       -Health Status: Tamagotchi is sick      ║";
	}
		
	cout << "\n╟═══════════════════════════════════════════════╢ "
		 << "\n║                     Menu:                     ║ "
		 << "\n╟═══════════════╦═══════════════╦═══════════════╢ "
		 << "\n║    1. Game    ║    2. Feed    ║   3. Clean    ║ "
		 << "\n╟───────────────╫───────────────╫───────────────╢ "
		 << "\n║  4. Medicine  ║   5. Lights   ║   6. Info     ║ "
		 << "\n╟═══════════════╩═══════╦═══════╩═══════════════╢ "
		 << "\n║  7. Save Tamagotchi   ║        8. Quit        ║ "
		 << "\n╚═══════════════════════╩═══════════════════════╝ "
		 << "\n";
	return;
}

int Main_tama::print_gone(int a) {
	int user_choice = 0;
	//Left because of old age
	if(a == -1) {
		print_blank();
		cout << "\n╟═══════════════════════════════════════════════╢ "
		 	 << "\n║                    Message:                   ║ "
		 	 << "\n║       -Status: Your tamagotchi left           ║ "
		 	 << "\n║                because of old age.            ║ "
		 	 << "\n╟═══════════════════════════════════════════════╢ "
			 << "\n║                     Menu:                     ║ "
			 << "\n╟═══════════════════════╦═══════════════════════╢ "
			 << "\n║      1. Restart       ║        2. Exit        ║ "
			 << "\n╚═══════════════════════╩═══════════════════════╝ "
			 << "\n What would you like to do?: ";
		cin >> user_choice;
		return user_choice;
	}
	//Left because it was too sick
	else if(a == -2) {
		print_blank();
		cout << "\n╟═══════════════════════════════════════════════╢ "
		 	 << "\n║                    Message:                   ║ "
		 	 << "\n║       -Status: Your tamagotchi left           ║ "
		 	 << "\n║                because it was too sick.       ║ "
		 	 << "\n╟═══════════════════════════════════════════════╢ "
			 << "\n║                     Menu:                     ║ "
			 << "\n╟═══════════════════════╦═══════════════════════╢ "
			 << "\n║      1. Restart       ║        2. Exit        ║ "
			 << "\n╚═══════════════════════╩═══════════════════════╝ "
			 << "\n What would you like to do?: ";
		cin >> user_choice;
		return user_choice;
	}
}

void Main_tama::print_menu() {cout << "\n";}
void Main_tama::print_male(string s) {cout << "\n";}
void Main_tama::print_female(string s) {cout << "\n";}

///////////////////////////////////////////////
/////////////// Other Functions ///////////////
///////////////////////////////////////////////

//Happens when tamagotchi is sleeping
void Main_tama::rand_events() {cout << "\n";}

int Main_tama::operation_selected(int user_choice, string filename, time_t born) {
	time_t now;
	switch(user_choice) {
		case 1: {
			game();
			return 1; 
		}
		case 2: {
			feed();
			return 1; 
		}
		case 3: {
			clean();
			return 1;
		}
		case 4: {
			int sick_leave = medicine();
			if(sick_leave == 4) { return 4; }
			else { return 1; }
		}
		case 5: {
			light_controls();
			 return 1; 
		}
		case 6: {
			print_info();
			 return 1; 
		}
		case 7: {
			save_tama(filename, born);
			return 7;
		}
		default: {
			cout << " Sorry, that is not an option.\n";
			return 1; 
		}
	}
}

int Main_tama::run_through(time_t born, string filename) {
	int user_choice = 0;
	rand_events();
	print_menu();
	cout << "\n What would you like to do?: ";
	cin >> user_choice;
	for(int i = 0; i < 50; i++) {
		cout << " \n";
	}
	int op;
	if(user_choice == 8) { return 8; }
	else { op = operation_selected(user_choice, filename, born); }
			
	//increase age of tamagotchi
	time_t now = time(&now);
	increase_age(difftime(now, born));
	return op;
}

void Main_tama::increase_happiness(float n) {
	happiness = happiness + n;
	if(happiness > 4) { happiness = 4; return;}
	if(happiness < 0) { happiness = 0; return;}
}

void Main_tama::increase_hunger(float n) {
	hunger = hunger + n;
	if(hunger > 4) { hunger = 4; return;}
	if(hunger < 0) { hunger = 0; return;}
}

void Main_tama::increase_discipline(int n) {
	discipline = discipline + n;
	if(discipline > 13) { discipline = 13; return; }
	if(discipline < 0 ) { discipline = 0; return; }
}

void Main_tama::increase_age(int t_diff) {
	//Baby
	if(t_diff >= 30 && t_diff < 60) {
		age = 2;
	}
	else if(t_diff >= 60 && t_diff < 120) {
		age = 3;
	}

	//Child
	else if(t_diff >= 120 && t_diff < 140) {
		age = 4;
	}
	else if(t_diff >= 140 && t_diff < 180) {
		age = 5;
	}
	else if(t_diff >= 180 && t_diff < 200) {
		age = 6;
	}
	else if(t_diff >= 200 && t_diff < 220) {
		age = 7;
	}
	else if(t_diff >= 220 && t_diff < 240) {
		age = 8;
	}
	else if(t_diff >= 280 && t_diff < 300) {
		age = 9;
	}
	else if(t_diff >= 300 && t_diff < 320) {
		age = 10;
	}

	//Teen
	else if(t_diff >= 320 && t_diff < 340) {
		age = 11;
	}
	else if(t_diff >= 340 && t_diff < 360) {
		age = 12;
	}
	else if(t_diff >= 360 && t_diff < 380) {
		age = 13;
	}
	else if(t_diff >= 380 && t_diff < 400) {
		age = 14;
	}
	else if(t_diff >= 400 && t_diff < 420) {
		age = 15;
	}
	else if(t_diff >= 420 && t_diff < 440) {
		age = 16;
	}
	else if(t_diff >= 440 && t_diff < 460) {
		age = 17;
	}
	else if(t_diff >= 460 && t_diff < 480) {
		age = 18;
	}
	else if(t_diff >= 480 && t_diff < 500) {
		age = 19;
	}

	//Adult
	else if(t_diff >= 500 && t_diff < 520) {
		age = 20;
	}
	else if(t_diff >= 520 && t_diff < 540) {
		age = 21;
	}
	else if(t_diff >= 540 && t_diff < 560) {
		age = 22;
	}
	else if(t_diff >= 560 && t_diff < 580) {
		age = 23;
	}
	else if(t_diff >= 580 && t_diff < 600) {
		age = 25;
	}
	else if(t_diff >= 600 && t_diff < 620) {
		age = 26;
	}
	else if(t_diff >= 620 && t_diff < 640) {
		age = 27;
	}
	else if(t_diff >= 640 && t_diff < 660) {
		age = 28;
	}
	else if(t_diff >= 660 && t_diff < 680) {
		age = 29;
	}
	else if(t_diff >= 680 && t_diff < 700) {
		age = 30;
	}
}

void Main_tama::tama_discipline(string m) {
	int user_choice = 0;
	int shout = rand()%100;
	if(discipline >= 0 && discipline < 4) {
		for(int i = 0; i < 5; i++) { cout << "\a"; }
		cout << "\n " << name << m;
		cout << "\n (1) Yes or (2) No: ";
		cin >> user_choice;
		if(user_choice == 1) {
			cout << "\n You just scolded " << name << ".";
			increase_discipline(2);
			increase_happiness(-0.5);
		}
	}
	else if(discipline >= 4 && discipline < 8) {
		if(shout <= 40) {
			for(int i = 0; i < 5; i++) { cout << "\a"; }
			cout << "\n " << name << m;
			cout << "\n (1) Yes or (2) No: ";
			cin >> user_choice;
			if(user_choice == 1) {
				cout << "\n You just scolded " << name << ".";
				increase_discipline(2);
				increase_happiness(-0.5);
			}
		}
	}
	else if(discipline >= 8 && discipline <= 13) {
		if(shout <= 25) {
			for(int i = 0; i < 5; i++) { cout << "\a"; }
			cout << "\n " << name << m;
			cout << "\n (1) Yes or (2) No: ";
			cin >> user_choice;
			if(user_choice == 1) {
				cout << "\n You just scolded " << name << ".";
				increase_discipline(2);
				increase_happiness(-0.5);
			}
		}
	}
}

///////////////////////////////////////////////
///////////// Getters and setters /////////////
///////////////////////////////////////////////

void Main_tama::set_name(string n) { name = n; }
void Main_tama::set_gender(string s) { gender = s; }
void Main_tama::set_age(int a) { age = a; }
void Main_tama::set_weight(float w) { weight = w; }
void Main_tama::set_hunger(float h) { hunger = h; }
void Main_tama::set_happiness(float h) { happiness = h; }
void Main_tama::set_discipline(int d) { discipline = d; }
void Main_tama::set_poop(bool p) { poop = p; }
void Main_tama::set_sick(bool s) { sick = s; }
void Main_tama::set_lights(bool l) { lights = l; }
void Main_tama::set_sleep(bool s) { sleep = s; }
void Main_tama::set_sleepy(bool y) { sleepy = y; }
void Main_tama::set_time_pooped(time_t tp) { time_pooped = tp; }

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
bool Main_tama::get_sleepy() { return sleepy; }
time_t Main_tama::get_time_pooped() { return time_pooped;}

string Main_tama::get_shout() { return shout; }
string Main_tama::get_not_eating() { return not_eating; }
