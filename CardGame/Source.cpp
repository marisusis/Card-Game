#include "game.h"

int main() {
	game gofish = game("Go Fish", "spacegeek224", true);
	gofish.init();
	gofish.deal(7);
	gofish.displayAll(7);
	return 0;
}