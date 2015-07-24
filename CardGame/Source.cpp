#include "game.h"
#include <windows.h>



int main() {
	card *player2Hand[52];
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
	//gofish.player1Hand[0] = card(1, '\x03');
	//gofish.player2Hand[3] = card(1, '\x04');
	//gofish.displayAll(7);
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
						gofish.displayp1();
						//gofish.displayp2();
						break;
					case '1':
						gofish.clearScreen();
						if (gofish.plr1Size >= 1) {

							cout << gofish.p1Name() << "> Do you have any " << gofish.player1Hand[0].value << "s?" << endl;

							gofish.displayp1();
							gofish.displayp2();
							for (int i=0; i<gofish.plr2Size; i++) {
								cout << gofish.player1Hand[0].value << "|" << gofish.player2Hand[4].value << endl;
								if (gofish.player1Hand[0].value == gofish.player2Hand[i].value) {

									cout << gofish.p2Name() << "> Yes, I have a/an" << gofish.player1Hand[0].value << " card." << endl;

									gofish.player1Hand[0] = card(NULL, NULL);
									gofish.player2Hand[i] = card(NULL, NULL);

									for (int j=0; j<gofish.sizep1(); j++) {

										if (gofish.player1Hand[j].value == NULL && gofish.player1Hand[j].suit == NULL) {
											gofish.player1Hand[j] = gofish.player1Hand[j+1];
											gofish.player1Hand[j+1] = card(NULL, NULL); 

										}

									}
									for (int j=0; j<gofish.sizep2(); j++) {

										if (gofish.player2Hand[j].value == NULL && gofish.player2Hand[j].suit == NULL) {
											gofish.player2Hand[j] = gofish.player2Hand[j+1];
											gofish.player2Hand[j+1] = card(NULL, NULL);

										}

									}
									gofish.plr1Score++;
									gofish.displayp1();
									gofish.displayp2();
								} else {
									cout << gofish.p2Name() << "> No, I do not have any " << gofish.player1Hand[0].value << " cards. Go Fish!" << endl;
									gofish.player1Hand[gofish.sizep1() + 1] = gofish.cardDeck[gofish.topCard];
									gofish.topCard++;
									gofish.plr1Size++;
									gofish.displayp1();
									gofish.displayp2();
									cin.get();
								}
							}
						}
						break;
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
					case '10':
					case '11':
					case '12':
					case '13':

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