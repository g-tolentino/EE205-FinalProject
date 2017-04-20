all: test tamagotchi

test: Main-tama.cpp Baby-tama.cpp Child-tama.cpp Teen-tama.cpp Adult-tama.cpp test.cpp
	g++ -o test Main-tama.cpp Baby-tama.cpp Child-tama.cpp Teen-tama.cpp Adult-tama.cpp test.cpp

tamagotchi: Main-tama.cpp Baby-tama.cpp Child-tama.cpp Teen-tama.cpp Adult-tama.cpp tamagotchi.cpp
	g++ -o test Main-tama.cpp Baby-tama.cpp Child-tama.cpp Teen-tama.cpp Adult-tama.cpp tamagotchi.cpp
