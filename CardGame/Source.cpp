#include "card.h"
#include <iostream>


int main() {

	card deckOfCards[52];

	for (int i=0; i<13; i++) {
		deckOfCards[i].value = i + 2;
		deckOfCards[i].suit = 'S';
	}
	for (int i=0; i<13; i++) {
		deckOfCards[i + 13].value = i + 2;
		deckOfCards[i + 13].suit = 'D';
	}
	for (int i=0; i<13; i++) {
		deckOfCards[i + 26].value = i + 2;
		deckOfCards[i + 26].suit = 'C';
	}
	for (int i=0; i<13; i++) {
		deckOfCards[i + 39].value = i + 2;
		deckOfCards[i + 39].suit = 'C';
	}

	card player1Hand[5];
	card player2Hand[5];

	int topCard = 0;

	int p1Size = 0;
	int p2Size = 0;

	return 0;

}