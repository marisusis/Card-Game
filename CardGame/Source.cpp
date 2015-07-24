#include "game.h"
#include <windows.h>



int main() {
	DWORD        mode;          /* Preserved console mode */
	INPUT_RECORD event;         /* Input event */
	BOOL         done = FALSE;  /* Program termination flag */
	unsigned int counter = 0;   /* The number of times 'Esc' is pressed */

	/* Get the console input handle */
	HANDLE hstdin = GetStdHandle( STD_INPUT_HANDLE );

	/* Preserve the original console mode */
	GetConsoleMode( hstdin, &mode );

	/* Set to no line-buffering, no echo, no special-key-processing */
	SetConsoleMode( hstdin, 0 );
	game gofish = game("Go Fish", "spacegeek224", true);
	gofish.init();
	//MUST ADD SHUFFLE
	gofish.deal(7);
	//gofish.displayAll(7);
	gofish.sleep(3,2);
	char key;
	bool playing = true;
	while (playing) {

		/* Give the user instructions */
		cout << "Press \"C\" to view your hand." << endl << "Press \"1-"<< gofish.sizep1() << "\" tochoose a card." << endl << "Press \"ESC\" to exit" << endl;
		while (!done)
		{
			if (WaitForSingleObject( hstdin, 0 ) == WAIT_OBJECT_0)  /* if kbhit */
			{
				DWORD count;  /* ignored */

				/* Get the input event */
				ReadConsoleInput( hstdin, &event, 1, &count );

				/* Only respond to key release events */
				if ((event.EventType == KEY_EVENT)
					&&  event.Event.KeyEvent.bKeyDown)
					switch (event.Event.KeyEvent.wVirtualKeyCode)
				{
					case 'C':
						counter++;
						gofish.displayp1(gofish.sizep1());
						break;
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':

					case VK_ESCAPE:
						counter++;
						done = true;
						break;
					default:
						cout << "Unknown key command" << endl;
				}
			}
		}
		break;
	}
	gofish.clearScreen();


	return 0;
}