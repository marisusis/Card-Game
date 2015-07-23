#include "game.h"

int main() {
	game blackjack = game("Blackjack");
	blackjack.setPlayer1Score(4);
	cout << blackjack.getPlayer1Score() << endl;
	return 10000;
}