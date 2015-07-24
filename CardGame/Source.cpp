#include "game.h"

int main() {
	game gofish = game("Go Fish", "spacegeek224", true);
	gofish.init();
	//MUST ADD SHUFFLE
	gofish.deal(7);
	gofish.displayAll(7);
	gofish.sleep(3,2);
	cout << gofish.getP1Name << " press ENTER when you are ready to view your hand.";
	cin.get();
	gofish.displayp1();
	return 0;
}