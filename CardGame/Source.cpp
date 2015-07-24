#include "game.h"

int main() {
	game gofish = game("Go Fish", "spacegeek224", true);
	gofish.init();
	//MUST ADD SHUFFLE
	gofish.deal(7);
	gofish.displayAll(7);
	gofish.sleep(3,2);
	return 0;
}