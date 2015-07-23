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
	card mycards = new card();
	shuffle(my, 52);

	
	card asdf[123];
	mycards.shuffle(asdf[], 123);
	


 
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
 
   

	return 0;

}

