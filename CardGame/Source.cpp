#include "game.h"
#include <windows.h>

int main() {
	game gofish = game("Go Fish", "spacegeek224", true);
	gofish.init();
	//MUST ADD SHUFFLE
	gofish.deal(7);
	gofish.displayAll(7);
	gofish.sleep(3,2);
	cout << gofish.p1Name() << " when you are ready to view your hand." << endl;
	bool loop = true;
	while (true) {
		//loop = true;
		if( GetAsyncKeyState( VK_RETURN ) & 0x8000 )
		{
			
			gofish.displayp1(gofish.sizeP1());
			while ( GetAsyncKeyState( VK_RETURN ) & 0x8000
			}
		} 
		if ( GetAsyncKeyState( 'E' ) & 0x8000 ) {
			//loop = false;
			break;
		}
	}
	gofish.clearScreen();


	return 0;
}