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

using namespace std;

class card {

public:
	//Varibles
	/*card playerHand[];
	card dealerHand[];*/
	int value;
	char suit;
	
	//Constructors
	card() {
		value = 14;
		suit = 'S';
	}
	card(int v, char s) {
		value = v;
		suit = s;
	}
	string displayCard() {
		string displayValue = "[";
		if (value < 11) {
			displayValue += to_string(value);
		}
		if (value == 11) {
			displayValue += "J";
		}
		if (value == 12) {
			displayValue += "Q";
		}
		if (value == 13) {
			displayValue += "K";
		}
		if (value == 14) {
			displayValue += "A";
		}
		//displayValue += "-";
		displayValue += suit;
		displayValue += "]";

		return displayValue;
	}


};
//Shuffle a deck


//Generate a deck

/*void Deal(int cardsToDeal, card deck[52]) {
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
}*/


