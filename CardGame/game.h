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
	string author;
	int p1Score;
	int p2Score;
	card playerHand[7];
	card dealerHand[7];
public:
	game() {

	}

	game(string gameName, string gameAuthor) {
		name = gameName;
		author = gameAuthor;
	}
	card cardDeck[52];
	void init() {
		cout << "Welcome to " << name << "!" << endl;
		sleep(3, 2);
		clearScreen
		cout << "This version of " << name << " was developed by " << author << "." << endl;
		loadDeck(cardDeck);
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
	void sleep(int unit, int time) {
		try {
			switch (unit) {
			case 1:
				this_thread::sleep_for(std::chrono::hours(time));
				break;
			case 2:
				this_thread::sleep_for(std::chrono::minutes(time));
				break;
			case 3:
				this_thread::sleep_for(std::chrono::seconds(time));
				break;
			case 4:
				this_thread::sleep_for(std::chrono::milliseconds(time));
				break;
			case 5:
				this_thread::sleep_for(std::chrono::microseconds(time));
				break;
			case 6:
				this_thread::sleep_for(std::chrono::nanoseconds(time));
				break;
			default:
				throw unit;
				break;
			}
		} catch (int unit) {
			cout << "Unknown value provided: " << unit << endl;
		}
	}
	void Deal(int cardsToDeal) {
		int topCard = 0;

		int pSize = 0;
		int dSize = 0;
		for (int i = 0; i < cardsToDeal; i++)
		{
			playerHand[i] = cardDeck[topCard];
			topCard++;
			pSize++;

			dealerHand[i] = cardDeck[topCard];
			topCard++;
			dSize++;
		}
	}

};