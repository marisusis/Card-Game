#include "card.h"
#include <iostream>
#include <fstream>

void deckCardsOut();
card deckOfCards[52];
card playerHand[5];
card dealerHand[5];

int main() {
	#pragma execution_character_set("utf-8")
	//_setmode(_fileno(stdout), _O_U16TEXT);
    //wprintf(L"\u2660\u2666");
	/*wchar_t c3 = L'\u2660';   // OK
   wchar_t c4 = L'\u0642';
   u16string spade;
   cout << spade;
   cout << c3 << c4 << endl;*/
	for (int i=0; i<13; i++) {
		deckOfCards[i].value = i + 2;
		deckOfCards[i].suit = '\xE2\x99\xA0';
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
		deckOfCards[i + 39].suit = 'H';
	}

	for (int i=0; i<53; i++) {
		cout << deckOfCards[i];
	}
	shuffle(deckOfCards, 52);

	

	int topCard = 0;

	int pSize = 0;
	int dSize = 0;
	bool dealing = true;
	while (dealing)
    {
		int i = 0;
        playerHand[i] = deckOfCards[topCard];
        topCard++;
        pSize++;
 
        dealerHand[i] = deckOfCards[topCard];
        topCard++;
        dSize++;
		i++;
    }
 
 
    cout << "Player's Hand" << endl;
    for (int i = 0; i < dSize; i++)
    {
        cout << player1Hand[i].displayCard();
    }
    cout << endl << "Dealer's Hand" << endl;
    for (int i = 0; i < dSize; i++)
    {
        cout << player2Hand[i].displayCard();
    }
	int p1Score = 0;
    for (int i = 0; i < p1Size; i++)
    {
        p1Score += player1Hand[i].value;
    }
 
    int p2Score = 0;
    for (int i = 0; i < p2Size; i++)
    {
        p2Score += player2Hand[i].value;
    }
 
    if (p1Score > p2Score)
        cout << endl << "Player 1 wins!" << endl;
    if (p2Score > p1Score)
        cout << endl << "Player 2 wins!" << endl;
    if (p1Score == p2Score)
        cout << endl << "Its a tie" << endl;

	return 0;

}
void deckCardsOut() {
	for (int i=0; i<53; i++) {
		cout << deckOfCards[i].displayCard;
	}
}
