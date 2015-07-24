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
	int p1Size;
	int p2Size;

	bool useLogo;
	string p1Name;
	string p2Name;
	int p1Score;
	int p2Score;
	card player1Hand[26];
	card player2Hand[26];
public:
	game() {
		name = "CardGame";
		author = "spacegeek224";
		useLogo = true;
	}

	game(string gameName, string gameAuthor, bool l) {
		name = gameName;
		author = gameAuthor;
		useLogo = l;
	}
	card cardDeck[52];
	void init() {

		loadDeck(cardDeck);
		shuffle(cardDeck, 52);
		cout << "Welcome to..." << endl;
		sleep(3, 1);
		clearScreen();
		displayLogo();
		sleep(3, 1);
		clearScreen();
		cout << "This version of " << name << " was developed by " << author << "." << endl;
		sleep(3, 1);
		clearScreen();
		cout << "Player 1 enter your name: ";
		cin >> p1Name;
		cout << endl;
		clearScreen();
		cout << "Player 2 enter your name: ";
		cin >> p2Name;
		cout << endl;
		clearScreen();
	}
	//Logo file must be called logo.txt
	/*void setLogo() {
	ofstream logoFileOut("logo.txt");
	logoFile.open("logo.txt");
	logoFile 
	}*/

	//Logo file must be called logo.txt
	void displayLogo() {
		string line;
		ifstream logoFile("logo.txt");
		if (logoFile.is_open()) {
			while (getline(logoFile,line)) {
				cout << line << endl;
			}
			logoFile.close();
		}

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
	string getP1Name() {
		return p1Name;
	}
	string getP2Name() {
		return p2Name;
	}
	void setPlayer1Name(int pname) {
		p1Name = pname; 
	}
	void setPlayer2Name(int pname) {
		p2Name = pname;
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
	void deal(int cardsToDeal) {
		int topCard = 0;

		p1Size = 0;
		p2Size = 0;

		for (int i = 0; i < cardsToDeal; i++)
		{
			player1Hand[i] = cardDeck[topCard];
			topCard++;
			p1Size++;

			player2Hand[i] = cardDeck[topCard];
			topCard++;
			p2Size++;
		}
	}
	void displayAll(int cardsDealed) {
		cout << "Player 1's Hand" << endl;
		for (int i=0; i<cardsDealed; i++) {
			cout << player1Hand[i].displayCard() << endl;
		}
		cout << "Player 2's Hand" << endl;
		for (int i=0; i<cardsDealed; i++) {
			cout << player2Hand[i].displayCard() << endl;
		}
	}
	void displayp1(int cardsDealed) {
		cout << "Player 1's Hand" << endl;
		for (int i=0; i<cardsDealed; i++) {
			cout << player1Hand[i].displayCard() << endl;
		}
	}
	void displayp2(int cardsDealed) {
		cout << "Player 2's Hand" << endl;
		for (int i=0; i<cardsDealed; i++) {
			cout << player2Hand[i].displayCard() << endl;
		}
	}
	int sizeP1() {
		return p1Size;
	}
	int sizeP2() {
		return p2Size;
	}

};