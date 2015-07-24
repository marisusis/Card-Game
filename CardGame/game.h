#include <string>
#include <Windows.h>
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

	card player1Hand[52];
	card player2Hand[52];
	string name;
	string author;


	bool useLogo;
	string plr1Name;
	string plr2Name;
	card cardDeck[52];
	int topCard;
	int plr1Size;
	int plr2Size;
	int plr1Score;
	int plr2Score;
	void init() {
		for (int i=0; i<52; i++) {
			//cout << player1Hand[i].displayCard() << endl;
			player1Hand[i] = card(NULL, NULL);
			//cout << player2Hand[i].displayCard() << endl;
			player2Hand[i] = card(NULL, NULL);
		}
		plr1Score = 0;
		plr2Score = 0;
		plr1Size = 7;
		plr2Size = 7;
		loadDeck(cardDeck);
		shuffle(cardDeck, 52);
		cout << "Welcome to..." << endl;
		sleep(3, 2);
		clearScreen();
		displayLogo();
		cout << "This version of " << name << " was developed by " << author << "." << endl;
		sleep(3, 1);
		clearScreen();
		cout << "Player 1 enter your name: ";
		getline(cin, plr1Name);
		cout << endl;
		clearScreen();
		//cin.get();
		cout << "Player 2 enter your name: ";
		getline(cin, plr2Name);
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
		/*sleep(3,2);
		int numline = 1;
		ifstream logoFile2("logo2.txt");
		if (logoFile2.is_open()) {
			while (getline(logoFile2,line)) {
				if (numline == 14 || numline == 27 || numline ==39) {
					sleep(3,2);
					clearScreen();
				}
				cout << line << endl;
				numline++;
			}
			logoFile2.close();
		}*/

	}

	int checkWinner() {
		if (plr1Score > plr2Score) {
			return 1;
		}
		if (plr2Score > plr1Score) {
			return 2;
		}
		if (plr1Score == plr2Score) {
			return 0;
		}
	}
	void setPlayer1Score(int score) {
		plr1Score = score; 
	}
	void setPlayer2Score(int score) {
		plr2Score = score;
	}
	void setPlayer1Name(int pname) {
		plr1Name = pname; 
	}
	void setPlayer2Name(int pname) {
		plr2Name = pname;
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
		topCard = 0;

		plr1Size = 0;
		plr2Size = 0;

		for (int i = 0; i < cardsToDeal; i++)
		{
			player1Hand[i] = cardDeck[topCard];
			topCard++;
			plr1Size++;

			player2Hand[i] = cardDeck[topCard];
			topCard++;
			plr2Size++;
		}
	}
	void displayAll(int cardsDealed) {
		cout << "Player 1's Hand - Score: " << plr1Score << endl;
		for (int i=0; i<cardsDealed; i++) {
			cout << player1Hand[i].displayCard() << endl;
		}
		cout << "Player 2's Hand - Score: " << plr2Score << endl;
		for (int i=0; i<cardsDealed; i++) {
			cout << player2Hand[i].displayCard() << endl;
		}
	}
	void displayp1(/*int cardsDealed*/) {
		cout << "Player 1's Hand | Score: " << plr1Score << endl;
		for (int i=0; i<plr1Size; i++) {
			if (!(player1Hand[i].value == NULL && player1Hand[i].suit == NULL) || !(player1Hand[i].value == NULL || player1Hand[i].suit == NULL)) {
				cout << player1Hand[i].displayCard() << endl;
			}
		}
	}
	void displayp2(/*int cardsDealed*/) {
		cout << "Player 2's Hand | Score: " << plr2Score << endl;
		for (int i=0; i<plr2Size; i++) {
			if (!(player1Hand[i].value == NULL && player1Hand[i].suit == NULL) || !(player1Hand[i].value == NULL || player1Hand[i].suit == NULL)) {
				cout << player2Hand[i].displayCard() << endl;
			}
		}
	}

};
bool keyPress(char keyPressed) {
	if ( GetAsyncKeyState( keyPressed ) & 0x8000 ) {
		return true;
	}
}
