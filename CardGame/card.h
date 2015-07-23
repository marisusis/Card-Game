#include <string>
#include <time.h>
#include <cstdlib>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>

using namespace std;

class card {

public:
	//Varibles
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
void shuffle(card deck[], int len) {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < len; i++) {
		int r = rand() % (len - i) + i;

		card temp = deck[i];
		deck[i] = deck[r];
		deck[r] = temp;
	}
}

//Generate a deck
void loadDeck(card deck[52]) {
	for (int i=0; i<13; i++) {
		deck[i].value = i + 2;
		deck[i].suit = '\x03';
	}
	for (int i=0; i<13; i++) {
		deck[i + 13].value = i + 2;
		deck[i + 13].suit = '\x04';
	}
	for (int i=0; i<13; i++) {
		deck[i + 26].value = i + 2;
		deck[i + 26].suit = '\x05';
	}
	for (int i=0; i<13; i++) {
		deck[i + 39].value = i + 2;
		deck[i + 39].suit = '\x06';
	} 
}
void Deal(int cardsToDeal, card deck[52]) {
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

void checkScore(int pScore, int dScore) {
	if (pScore > dScore) {
		cout << endl << "Player wins!" << endl;
	}
	if (dScore > pScore) {
		cout << endl << "Dealer wins!" << endl;
	}
	if (pScore == dScore) {
		cout << endl << "Its a tie" << endl;
	}
}
void checkHand() {
    for (int i = 0; i < dSize; i++)
    {
        cout << playerHand[i].displayCard();
    }
}
