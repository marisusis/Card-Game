#include "game.h"

int main() {
	game gofish = game("Go Fish");
	gofish.sleep('2', 4);
	return 0;
}
//this_thread::sleep_for(std::chrono::milliseconds(400));