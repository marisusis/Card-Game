#include "card.h"
#include <iostream>
//#include <fstream>

//void deckCardsOut();
card deckOfCards[52];
card playerHand[26];
card dealerHand[26];
//void pCardsOut();
//void dCardsOut();
int dNumCards;
int pNumCards;
void loadDeck() {
	for (int i=0; i<13; i++) {
		deckOfCards[i].value = i + 2;
		deckOfCards[i].suit = '\x03';
	}
	for (int i=0; i<13; i++) {
		deckOfCards[i + 13].value = i + 2;
		deckOfCards[i + 13].suit = '\x04';
	}
	for (int i=0; i<13; i++) {
		deckOfCards[i + 26].value = i + 2;
		deckOfCards[i + 26].suit = '\x05';
	}
	for (int i=0; i<13; i++) {
		deckOfCards[i + 39].value = i + 2;
	deckOfCards[i + 39].suit = '\x06';
	} 
}
void deckCardsOut() {
	for (int i=0; i<52; i++) {
		cout << deckOfCards[i].displayCard() << endl;
	}
}
void dCardsOut() {
	for (int i=0; i<dNumCards; i++) {
		cout << dealerHand[i].displayCard() << endl;
	}
}

void pCardsOut() {
	for (int i=0; i<pNumCards; i++) {
		cout << playerHand[i].displayCard() << endl;
	}
}
int main() {
	//#pragma execution_character_set("utf-8")
	//_setmode(_fileno(stdout), _O_U16TEXT);
    //wprintf(L"\u2660\u2666");
	//*wchar_t c3 = L'\u2660';   // OK
   /*wchar_t c4 = L'\u0642';
   u16string spade;
   cardsOut(desk
   cout << spade;
   cout << c3 << c4 << endl;*/
	void loadDeck()
	{
		for (int i=0; i<13; i++) {
			deckOfCards[i].value = i + 2;
			deckOfCards[i].suit = '\x03';
		}
		for (int i=0; i<13; i++) {
			deckOfCards[i + 13].value = i + 2;
			deckOfCards[i + 13].suit = '\x04';
		}
		for (int i=0; i<13; i++) {
			deckOfCards[i + 26].value = i + 2;
			deckOfCards[i + 26].suit = '\x05';
		}
		for (int i=0; i<13; i++) {
			deckOfCards[i + 39].value = i + 2;
			deckOfCards[i + 39].suit = '\x06';
		} 
	}

	shuffle(deckOfCards, 52);

	

	int topCard = 0;

	int pSize = 0;
	int dSize = 0;
	bool dealing = true;
	int numdeal = 0;
	while (dealing)
    {
		
        playerHand[numdeal] = deckOfCards[topCard];
        topCard++;
        pSize++;
 
        dealerHand[numdeal] = deckOfCards[topCard];
        topCard++;
        dSize++;
		numdeal++;
    }
 
 
    cout << "Player's Hand" << endl;
    for (int i = 0; i < dSize; i++)
    {
        cout << playerHand[i].displayCard();
    }
    cout << "Dealer's Hand" << endl;
    for (int i = 0; i < dSize; i++)
    {
        cout << dealerHand[i].displayCard();
    }
	int pScore = 0;
    for (int i = 0; i < pSize; i++)
    {
        pScore += playerHand[i].value;
    }
 
    int dScore = 0;
    for (int i = 0; i < dSize; i++)
    {
        dScore += dealerHand[i].value;
    }
 
    if (pScore > dScore)
        cout << endl << "Player wins!" << endl;
    if (dScore > pScore)
        cout << endl << "Dealer wins!" << endl;
    if (pScore == dScore)
        cout << endl << "Its a tie" << endl;

	return 0;

}

