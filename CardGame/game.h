#include <string>
#include <time.h>
#include <cstdlib>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include "card.h"


using namespace std;

class game {

	//TODO add in exception catching
private:
	string name;
	int p1Score;
	int p2Score;
	card playerHand[7];
	card dealerHand[7];
public:
	game() {

	}
	
	game(string myGame) {
		name = myGame;
	}
	card deck[52];
	void init() {
		
	}

	int checkWinner() {
		if (p1Score > p2Score) {
			return 1;
		}
		if (p2Score > p1Score) {
			return 2;
		}
		if (p1Score == p2Score) {
			return 0;
		}
	}
	int getPlayer1Score() {
		return p1Score;
	}
	int getPlayer2Score() {
		return p2Score;
	}
	void setPlayer1Score(int score) {
			p1Score = score; 
	}
	void setPlayer2Score(int score) {
		p2Score = score;
	}
	void clearScreen() {
		#ifdef _WIN32
		std::system ( "CLS" );
		#else
		// Assume POSIX
		std::system ( "clear" );
		#endif

	}
	void sleep(char unit, int time) {
		try {
			switch (unit) {
			case 'm':
				break;
			default:
				break;
			}
		} catch (bad_typeid) {
			cout << "Unknown value provided";
		}
	}
	void Deal(int cardsToDeal) {
		int topCard = 0;

		int pSize = 0;
		int dSize = 0;
		for (int i = 0; i < cardsToDeal; i++)
		{
			playerHand[i] = deck[topCard];
			topCard++;
			pSize++;

			dealerHand[i] = deck[topCard];
			topCard++;
			dSize++;
		}
	}

};