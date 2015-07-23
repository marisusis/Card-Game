#include <string>
#include <time.h>
#include <cstdlib>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class game {

	//TODO add in exception catching
private:
	string name;
	int p1Score;
	int p2Score;
public:
	game() {

	}
	
	game(string myGame) {
		name = myGame;
	}
	
	void init() {
		
	}

	void checkScore(/*int pScore, int dScore*/) {
		if (p1Score > p2Score) {
			cout << endl << "Player wins!" << endl;
		}
		if (p2Score > p1Score) {
			cout << endl << "Dealer wins!" << endl;
		}
		if (p1Score == p2Score) {
			cout << endl << "Its a tie" << endl;
		}
	}
};