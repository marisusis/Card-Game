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
	//gofish.player1Hand[0] = card(1, '\x03');
	//gofish.player2Hand[3] = card(1, '\x04');
	//gofish.displayAll(7);
	char key;
	bool playing = true;
	while (playing) {

		/* Give the user instructions */
		cout << "Press \"C\" to view your hand." << endl << "Press \"1-"<< gofish.plr1Size << "\" tochoose a card." << endl << "Press \"ESC\" to exit" << endl;
		//PLAYER 1 TURN
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
					switch (event.Event.KeyEvent.wVirtualKeyCode) {
					case 'C':
						counter++;
						gofish.displayp1();
						gofish.displayp2();
						break;
					case '1':
						gofish.clearScreen();
						if (gofish.plr1Size >= 1) {

							//cout << gofish.plr1Name << "> Do you have any " << gofish.player1Hand[0].value << "s?" << endl;

							gofish.displayp1();
							gofish.displayp2();
							bool cardFound = false;
							for (int i=0; i<gofish.plr2Size; i++) {
								cout << gofish.player1Hand[0].value << "|" << gofish.player2Hand[i].value << endl;
								if (gofish.player1Hand[0].value == gofish.player2Hand[i].value) {
									cardFound = true;
									cout << gofish.plr2Name << "> Yes, I have a/an" << gofish.player1Hand[0].value << " card." << endl;

									gofish.player1Hand[0] = card(NULL, NULL);
									gofish.player2Hand[i] = card(NULL, NULL);


									gofish.plr1Score++;
									gofish.displayp1();
									gofish.displayp2();

									break;
								} 
							}
							for (int j=0; j<gofish.plr1Size; j++) {

								if (gofish.player1Hand[j].value == NULL && gofish.player1Hand[j].suit == NULL) {
									gofish.player1Hand[j] = gofish.player1Hand[j+1];
									gofish.player1Hand[j+1] = card(NULL, NULL); 
									gofish.plr1Size--;

								}

							}
							for (int j=0; j<gofish.plr2Size; j++) {

								if (gofish.player2Hand[j].value == NULL && gofish.player2Hand[j].suit == NULL) {
									gofish.player2Hand[j] = gofish.player2Hand[j+1];
									gofish.player2Hand[j+1] = card(NULL, NULL);
									gofish.plr2Size--;

								}

							}
							if (!cardFound) {
								cout << gofish.plr2Name << "> No, I do not have any " << gofish.player1Hand[0].value << " cards. Go Fish!" << endl;
								gofish.player1Hand[gofish.plr1Size] = gofish.cardDeck[gofish.topCard];
								gofish.topCard++;
								gofish.plr1Size++;
								gofish.displayp1();
								gofish.displayp2();
								cin.get();
							}
						}
						break;
					case '2':
						gofish.clearScreen();
						if (gofish.plr1Size >= 3) {

							//cout << gofish.plr1Name << "> Do you have any " << gofish.player1Hand[0].value << "s?" << endl;

							gofish.displayp1();
							gofish.displayp2();
							bool cardFound = false;
							for (int i=0; i<gofish.plr2Size; i++) {
								cout << gofish.player1Hand[1].value << "|" << gofish.player2Hand[i].value << endl;
								if (gofish.player1Hand[1].value == gofish.player2Hand[i].value) {
									cardFound = true;
									cout << gofish.plr2Name << "> Yes, I have a/an" << gofish.player1Hand[1].value << " card." << endl;

									gofish.player1Hand[1] = card(NULL, NULL);
									gofish.player2Hand[i] = card(NULL, NULL);


									gofish.plr1Score++;
									gofish.displayp1();
									gofish.displayp2();

									break;
								} 
							}
							for (int j=0; j<gofish.plr1Size; j++) {

								if (gofish.player1Hand[j].value == NULL && gofish.player1Hand[j].suit == NULL) {
									gofish.player1Hand[j] = gofish.player1Hand[j+1];
									gofish.player1Hand[j+1] = card(NULL, NULL); 
									gofish.plr1Size--;

								}

							}
							for (int j=0; j<gofish.plr2Size; j++) {

								if (gofish.player2Hand[j].value == NULL && gofish.player2Hand[j].suit == NULL) {
									gofish.player2Hand[j] = gofish.player2Hand[j+1];
									gofish.player2Hand[j+1] = card(NULL, NULL);
									gofish.plr2Size--;

								}

							}
							if (!cardFound) {
								cout << gofish.plr2Name << "> No, I do not have any " << gofish.player1Hand[1].value << " cards. Go Fish!" << endl;
								gofish.player1Hand[gofish.plr1Size] = gofish.cardDeck[gofish.topCard];
								gofish.topCard++;
								gofish.plr1Size++;
								gofish.displayp1();
								gofish.displayp2();
								cin.get();
							}
						}
						break;
					case '3':
						gofish.clearScreen();
						if (gofish.plr1Size >= 4) {

							//cout << gofish.plr1Name << "> Do you have any " << gofish.player1Hand[0].value << "s?" << endl;

							gofish.displayp1();
							gofish.displayp2();
							bool cardFound = false;
							for (int i=0; i<gofish.plr2Size; i++) {
								cout << gofish.player1Hand[2].value << "|" << gofish.player2Hand[i].value << endl;
								if (gofish.player1Hand[2].value == gofish.player2Hand[i].value) {
									cardFound = true;
									cout << gofish.plr2Name << "> Yes, I have a/an" << gofish.player1Hand[2].value << " card." << endl;

									gofish.player1Hand[2] = card(NULL, NULL);
									gofish.player2Hand[i] = card(NULL, NULL);


									gofish.plr1Score++;
									gofish.displayp1();
									gofish.displayp2();

									break;
								} 
							}
							for (int j=0; j<gofish.plr1Size; j++) {

								if (gofish.player1Hand[j].value == NULL && gofish.player1Hand[j].suit == NULL) {
									gofish.player1Hand[j] = gofish.player1Hand[j+1];
									gofish.player1Hand[j+1] = card(NULL, NULL); 
									gofish.plr1Size--;

								}

							}
							for (int j=0; j<gofish.plr2Size; j++) {

								if (gofish.player2Hand[j].value == NULL && gofish.player2Hand[j].suit == NULL) {
									gofish.player2Hand[j] = gofish.player2Hand[j+1];
									gofish.player2Hand[j+1] = card(NULL, NULL);
									gofish.plr2Size--;

								}

							}
							if (!cardFound) {
								cout << gofish.plr2Name << "> No, I do not have any " << gofish.player1Hand[2].value << " cards. Go Fish!" << endl;
								gofish.player1Hand[gofish.plr1Size] = gofish.cardDeck[gofish.topCard];
								gofish.topCard++;
								gofish.plr1Size++;
								gofish.displayp1();
								gofish.displayp2();
								cin.get();
							}
						}
						break;
					case '4':
						gofish.clearScreen();
						if (gofish.plr1Size >= 5) {

							//cout << gofish.plr1Name << "> Do you have any " << gofish.player1Hand[0].value << "s?" << endl;

							gofish.displayp1();
							gofish.displayp2();
							bool cardFound = false;
							for (int i=0; i<gofish.plr2Size; i++) {
								cout << gofish.player1Hand[3].value << "|" << gofish.player2Hand[i].value << endl;
								if (gofish.player1Hand[3].value == gofish.player2Hand[i].value) {
									cardFound = true;
									cout << gofish.plr2Name << "> Yes, I have a/an" << gofish.player1Hand[3].value << " card." << endl;

									gofish.player1Hand[3] = card(NULL, NULL);
									gofish.player2Hand[i] = card(NULL, NULL);


									gofish.plr1Score++;
									gofish.displayp1();
									gofish.displayp2();

									break;
								} 
							}
							for (int j=0; j<gofish.plr1Size; j++) {

								if (gofish.player1Hand[j].value == NULL && gofish.player1Hand[j].suit == NULL) {
									gofish.player1Hand[j] = gofish.player1Hand[j+1];
									gofish.player1Hand[j+1] = card(NULL, NULL); 
									gofish.plr1Size--;

								}

							}
							for (int j=0; j<gofish.plr2Size; j++) {

								if (gofish.player2Hand[j].value == NULL && gofish.player2Hand[j].suit == NULL) {
									gofish.player2Hand[j] = gofish.player2Hand[j+1];
									gofish.player2Hand[j+1] = card(NULL, NULL);
									gofish.plr2Size--;

								}

							}
							if (!cardFound) {
								cout << gofish.plr2Name << "> No, I do not have any " << gofish.player1Hand[3].value << " cards. Go Fish!" << endl;
								gofish.player1Hand[gofish.plr1Size] = gofish.cardDeck[gofish.topCard];
								gofish.topCard++;
								gofish.plr1Size++;
								gofish.displayp1();
								gofish.displayp2();
								cin.get();
							}
						}
						break;
					case '5':
						gofish.clearScreen();
						if (gofish.plr1Size >= 6) {

							//cout << gofish.plr1Name << "> Do you have any " << gofish.player1Hand[0].value << "s?" << endl;

							gofish.displayp1();
							gofish.displayp2();
							bool cardFound = false;
							for (int i=0; i<gofish.plr2Size; i++) {
								cout << gofish.player1Hand[4].value << "|" << gofish.player2Hand[i].value << endl;
								if (gofish.player1Hand[4].value == gofish.player2Hand[i].value) {
									cardFound = true;
									cout << gofish.plr2Name << "> Yes, I have a/an" << gofish.player1Hand[0].value << " card." << endl;

									gofish.player1Hand[4] = card(NULL, NULL);
									gofish.player2Hand[i] = card(NULL, NULL);


									gofish.plr1Score++;
									gofish.displayp1();
									gofish.displayp2();

									break;
								} 
							}
							for (int j=0; j<gofish.plr1Size; j++) {

								if (gofish.player1Hand[j].value == NULL && gofish.player1Hand[j].suit == NULL) {
									gofish.player1Hand[j] = gofish.player1Hand[j+1];
									gofish.player1Hand[j+1] = card(NULL, NULL); 
									gofish.plr1Size--;

								}

							}
							for (int j=0; j<gofish.plr2Size; j++) {

								if (gofish.player2Hand[j].value == NULL && gofish.player2Hand[j].suit == NULL) {
									gofish.player2Hand[j] = gofish.player2Hand[j+1];
									gofish.player2Hand[j+1] = card(NULL, NULL);
									gofish.plr2Size--;

								}

							}
							if (!cardFound) {
								cout << gofish.plr2Name << "> No, I do not have any " << gofish.player1Hand[4].value << " cards. Go Fish!" << endl;
								gofish.player1Hand[gofish.plr1Size] = gofish.cardDeck[gofish.topCard];
								gofish.topCard++;
								gofish.plr1Size++;
								gofish.displayp1();
								gofish.displayp2();
								cin.get();
							}
						}
						break;
					case '6':
						gofish.clearScreen();
						if (gofish.plr1Size >= 7) {

							//cout << gofish.plr1Name << "> Do you have any " << gofish.player1Hand[0].value << "s?" << endl;

							gofish.displayp1();
							gofish.displayp2();
							bool cardFound = false;
							for (int i=0; i<gofish.plr2Size; i++) {
								cout << gofish.player1Hand[5].value << "|" << gofish.player2Hand[i].value << endl;
								if (gofish.player1Hand[5].value == gofish.player2Hand[i].value) {
									cardFound = true;
									cout << gofish.plr2Name << "> Yes, I have a/an" << gofish.player1Hand[5].value << " card." << endl;

									gofish.player1Hand[5] = card(NULL, NULL);
									gofish.player2Hand[i] = card(NULL, NULL);


									gofish.plr1Score++;
									gofish.displayp1();
									gofish.displayp2();

									break;
								} 
							}
							for (int j=0; j<gofish.plr1Size; j++) {

								if (gofish.player1Hand[j].value == NULL && gofish.player1Hand[j].suit == NULL) {
									gofish.player1Hand[j] = gofish.player1Hand[j+1];
									gofish.player1Hand[j+1] = card(NULL, NULL); 
									gofish.plr1Size--;

								}

							}
							for (int j=0; j<gofish.plr2Size; j++) {

								if (gofish.player2Hand[j].value == NULL && gofish.player2Hand[j].suit == NULL) {
									gofish.player2Hand[j] = gofish.player2Hand[j+1];
									gofish.player2Hand[j+1] = card(NULL, NULL);
									gofish.plr2Size--;

								}

							}
							if (!cardFound) {
								cout << gofish.plr2Name << "> No, I do not have any " << gofish.player1Hand[5].value << " cards. Go Fish!" << endl;
								gofish.player1Hand[gofish.plr1Size] = gofish.cardDeck[gofish.topCard];
								gofish.topCard++;
								gofish.plr1Size++;
								gofish.displayp1();
								gofish.displayp2();
								cin.get();
							}
						}
						break;
					case '7':gofish.clearScreen();
						if (gofish.plr1Size >= 8) {

							//cout << gofish.plr1Name << "> Do you have any " << gofish.player1Hand[0].value << "s?" << endl;

							gofish.displayp1();
							gofish.displayp2();
							bool cardFound = false;
							for (int i=0; i<gofish.plr2Size; i++) {
								cout << gofish.player1Hand[6].value << "|" << gofish.player2Hand[i].value << endl;
								if (gofish.player1Hand[6].value == gofish.player2Hand[i].value) {
									cardFound = true;
									cout << gofish.plr2Name << "> Yes, I have a/an" << gofish.player1Hand[6].value << " card." << endl;

									gofish.player1Hand[6] = card(NULL, NULL);
									gofish.player2Hand[i] = card(NULL, NULL);


									gofish.plr1Score++;
									gofish.displayp1();
									gofish.displayp2();

									break;
								} 
							}
							for (int j=0; j<gofish.plr1Size; j++) {

								if (gofish.player1Hand[j].value == NULL && gofish.player1Hand[j].suit == NULL) {
									gofish.player1Hand[j] = gofish.player1Hand[j+1];
									gofish.player1Hand[j+1] = card(NULL, NULL); 
									gofish.plr1Size--;

								}

							}
							for (int j=0; j<gofish.plr2Size; j++) {

								if (gofish.player2Hand[j].value == NULL && gofish.player2Hand[j].suit == NULL) {
									gofish.player2Hand[j] = gofish.player2Hand[j+1];
									gofish.player2Hand[j+1] = card(NULL, NULL);
									gofish.plr2Size--;

								}

							}
							if (!cardFound) {
								cout << gofish.plr2Name << "> No, I do not have any " << gofish.player1Hand[6].value << " cards. Go Fish!" << endl;
								gofish.player1Hand[gofish.plr1Size] = gofish.cardDeck[gofish.topCard];
								gofish.topCard++;
								gofish.plr1Size++;
								gofish.displayp1();
								gofish.displayp2();
								cin.get();
							}
						}
						break;
					case '8':
						gofish.clearScreen();
						if (gofish.plr1Size >= 9) {

							//cout << gofish.plr1Name << "> Do you have any " << gofish.player1Hand[0].value << "s?" << endl;

							gofish.displayp1();
							gofish.displayp2();
							bool cardFound = false;
							for (int i=0; i<gofish.plr2Size; i++) {
								cout << gofish.player1Hand[7].value << "|" << gofish.player2Hand[i].value << endl;
								if (gofish.player1Hand[7].value == gofish.player2Hand[i].value) {
									cardFound = true;
									cout << gofish.plr2Name << "> Yes, I have a/an" << gofish.player1Hand[7].value << " card." << endl;

									gofish.player1Hand[7] = card(NULL, NULL);
									gofish.player2Hand[i] = card(NULL, NULL);


									gofish.plr1Score++;
									gofish.displayp1();
									gofish.displayp2();

									break;
								} 
							}
							for (int j=0; j<gofish.plr1Size; j++) {

								if (gofish.player1Hand[j].value == NULL && gofish.player1Hand[j].suit == NULL) {
									gofish.player1Hand[j] = gofish.player1Hand[j+1];
									gofish.player1Hand[j+1] = card(NULL, NULL); 
									gofish.plr1Size--;

								}

							}
							for (int j=0; j<gofish.plr2Size; j++) {

								if (gofish.player2Hand[j].value == NULL && gofish.player2Hand[j].suit == NULL) {
									gofish.player2Hand[j] = gofish.player2Hand[j+1];
									gofish.player2Hand[j+1] = card(NULL, NULL);
									gofish.plr2Size--;

								}

							}
							if (!cardFound) {
								cout << gofish.plr2Name << "> No, I do not have any " << gofish.player1Hand[7].value << " cards. Go Fish!" << endl;
								gofish.player1Hand[gofish.plr1Size] = gofish.cardDeck[gofish.topCard];
								gofish.topCard++;
								gofish.plr1Size++;
								gofish.displayp1();
								gofish.displayp2();
								cin.get();
							}
						}
						break;
					case '9':
						gofish.clearScreen();
						if (gofish.plr1Size >= 10) {

							//cout << gofish.plr1Name << "> Do you have any " << gofish.player1Hand[0].value << "s?" << endl;

							gofish.displayp1();
							gofish.displayp2();
							bool cardFound = false;
							for (int i=0; i<gofish.plr2Size; i++) {
								cout << gofish.player1Hand[8].value << "|" << gofish.player2Hand[i].value << endl;
								if (gofish.player1Hand[8].value == gofish.player2Hand[i].value) {
									cardFound = true;
									cout << gofish.plr2Name << "> Yes, I have a/an" << gofish.player1Hand[8].value << " card." << endl;

									gofish.player1Hand[8] = card(NULL, NULL);
									gofish.player2Hand[i] = card(NULL, NULL);


									gofish.plr1Score++;
									gofish.displayp1();
									gofish.displayp2();

									break;
								} 
							}
							for (int j=0; j<gofish.plr1Size; j++) {

								if (gofish.player1Hand[j].value == NULL && gofish.player1Hand[j].suit == NULL) {
									gofish.player1Hand[j] = gofish.player1Hand[j+1];
									gofish.player1Hand[j+1] = card(NULL, NULL); 
									gofish.plr1Size--;

								}

							}
							for (int j=0; j<gofish.plr2Size; j++) {

								if (gofish.player2Hand[j].value == NULL && gofish.player2Hand[j].suit == NULL) {
									gofish.player2Hand[j] = gofish.player2Hand[j+1];
									gofish.player2Hand[j+1] = card(NULL, NULL);
									gofish.plr2Size--;

								}

							}
							if (!cardFound) {
								cout << gofish.plr2Name << "> No, I do not have any " << gofish.player1Hand[8].value << " cards. Go Fish!" << endl;
								gofish.player1Hand[gofish.plr1Size] = gofish.cardDeck[gofish.topCard];
								gofish.topCard++;
								gofish.plr1Size++;
								gofish.displayp1();
								gofish.displayp2();
								cin.get();
							}
						}
						break;
					case '10':
						gofish.clearScreen();
						if (gofish.plr1Size >= 11) {

							//cout << gofish.plr1Name << "> Do you have any " << gofish.player1Hand[0].value << "s?" << endl;

							gofish.displayp1();
							gofish.displayp2();
							bool cardFound = false;
							for (int i=0; i<gofish.plr2Size; i++) {
								cout << gofish.player1Hand[9].value << "|" << gofish.player2Hand[i].value << endl;
								if (gofish.player1Hand[9].value == gofish.player2Hand[i].value) {
									cardFound = true;
									cout << gofish.plr2Name << "> Yes, I have a/an" << gofish.player1Hand[0].value << " card." << endl;

									gofish.player1Hand[9] = card(NULL, NULL);
									gofish.player2Hand[i] = card(NULL, NULL);


									gofish.plr1Score++;
									gofish.displayp1();
									gofish.displayp2();

									break;
								} 
							}
							for (int j=0; j<gofish.plr1Size; j++) {

								if (gofish.player1Hand[j].value == NULL && gofish.player1Hand[j].suit == NULL) {
									gofish.player1Hand[j] = gofish.player1Hand[j+1];
									gofish.player1Hand[j+1] = card(NULL, NULL); 
									gofish.plr1Size--;

								}

							}
							for (int j=0; j<gofish.plr2Size; j++) {

								if (gofish.player2Hand[j].value == NULL && gofish.player2Hand[j].suit == NULL) {
									gofish.player2Hand[j] = gofish.player2Hand[j+1];
									gofish.player2Hand[j+1] = card(NULL, NULL);
									gofish.plr2Size--;

								}

							}
							if (!cardFound) {
								cout << gofish.plr2Name << "> No, I do not have any " << gofish.player1Hand[9].value << " cards. Go Fish!" << endl;
								gofish.player1Hand[gofish.plr1Size] = gofish.cardDeck[gofish.topCard];
								gofish.topCard++;
								gofish.plr1Size++;
								gofish.displayp1();
								gofish.displayp2();
								cin.get();
							}
						}
						break;
					case '11':
						gofish.clearScreen();
						if (gofish.plr1Size >= 12) {

							//cout << gofish.plr1Name << "> Do you have any " << gofish.player1Hand[0].value << "s?" << endl;

							gofish.displayp1();
							gofish.displayp2();
							bool cardFound = false;
							for (int i=0; i<gofish.plr2Size; i++) {
								cout << gofish.player1Hand[10].value << "|" << gofish.player2Hand[i].value << endl;
								if (gofish.player1Hand[10].value == gofish.player2Hand[i].value) {
									cardFound = true;
									cout << gofish.plr2Name << "> Yes, I have a/an" << gofish.player1Hand[10].value << " card." << endl;

									gofish.player1Hand[10] = card(NULL, NULL);
									gofish.player2Hand[i] = card(NULL, NULL);


									gofish.plr1Score++;
									gofish.displayp1();
									gofish.displayp2();

									break;
								} 
							}
							for (int j=0; j<gofish.plr1Size; j++) {

								if (gofish.player1Hand[j].value == NULL && gofish.player1Hand[j].suit == NULL) {
									gofish.player1Hand[j] = gofish.player1Hand[j+1];
									gofish.player1Hand[j+1] = card(NULL, NULL); 
									gofish.plr1Size--;

								}

							}
							for (int j=0; j<gofish.plr2Size; j++) {

								if (gofish.player2Hand[j].value == NULL && gofish.player2Hand[j].suit == NULL) {
									gofish.player2Hand[j] = gofish.player2Hand[j+1];
									gofish.player2Hand[j+1] = card(NULL, NULL);
									gofish.plr2Size--;

								}

							}
							if (!cardFound) {
								cout << gofish.plr2Name << "> No, I do not have any " << gofish.player1Hand[10].value << " cards. Go Fish!" << endl;
								gofish.player1Hand[gofish.plr1Size] = gofish.cardDeck[gofish.topCard];
								gofish.topCard++;
								gofish.plr1Size++;
								gofish.displayp1();
								gofish.displayp2();
								cin.get();
							}
						}
						break;
					case '12':
						gofish.clearScreen();
						if (gofish.plr1Size >= 13) {

							//cout << gofish.plr1Name << "> Do you have any " << gofish.player1Hand[0].value << "s?" << endl;

							gofish.displayp1();
							gofish.displayp2();
							bool cardFound = false;
							for (int i=0; i<gofish.plr2Size; i++) {
								cout << gofish.player1Hand[11].value << "|" << gofish.player2Hand[i].value << endl;
								if (gofish.player1Hand[11].value == gofish.player2Hand[i].value) {
									cardFound = true;
									cout << gofish.plr2Name << "> Yes, I have a/an" << gofish.player1Hand[11].value << " card." << endl;

									gofish.player1Hand[11] = card(NULL, NULL);
									gofish.player2Hand[i] = card(NULL, NULL);


									gofish.plr1Score++;
									gofish.displayp1();
									gofish.displayp2();

									break;
								} 
							}
							for (int j=0; j<gofish.plr1Size; j++) {

								if (gofish.player1Hand[j].value == NULL && gofish.player1Hand[j].suit == NULL) {
									gofish.player1Hand[j] = gofish.player1Hand[j+1];
									gofish.player1Hand[j+1] = card(NULL, NULL); 
									gofish.plr1Size--;

								}

							}
							for (int j=0; j<gofish.plr2Size; j++) {

								if (gofish.player2Hand[j].value == NULL && gofish.player2Hand[j].suit == NULL) {
									gofish.player2Hand[j] = gofish.player2Hand[j+1];
									gofish.player2Hand[j+1] = card(NULL, NULL);
									gofish.plr2Size--;

								}

							}
							if (!cardFound) {
								cout << gofish.plr2Name << "> No, I do not have any " << gofish.player1Hand[11].value << " cards. Go Fish!" << endl;
								gofish.player1Hand[gofish.plr1Size] = gofish.cardDeck[gofish.topCard];
								gofish.topCard++;
								gofish.plr1Size++;
								gofish.displayp1();
								gofish.displayp2();
								cin.get();
							}
						}
						break;
					case '13':
						gofish.clearScreen();
						if (gofish.plr1Size >= 14) {

							//cout << gofish.plr1Name << "> Do you have any " << gofish.player1Hand[0].value << "s?" << endl;

							gofish.displayp1();
							gofish.displayp2();
							bool cardFound = false;
							for (int i=0; i<gofish.plr2Size; i++) {
								cout << gofish.player1Hand[12].value << "|" << gofish.player2Hand[i].value << endl;
								if (gofish.player1Hand[12].value == gofish.player2Hand[i].value) {
									cardFound = true;
									cout << gofish.plr2Name << "> Yes, I have a/an" << gofish.player1Hand[12].value << " card." << endl;

									gofish.player1Hand[12] = card(NULL, NULL);
									gofish.player2Hand[i] = card(NULL, NULL);


									gofish.plr1Score++;
									gofish.displayp1();
									gofish.displayp2();

									break;
								} 
							}
							for (int j=0; j<gofish.plr1Size; j++) {

								if (gofish.player1Hand[j].value == NULL && gofish.player1Hand[j].suit == NULL) {
									gofish.player1Hand[j] = gofish.player1Hand[j+1];
									gofish.player1Hand[j+1] = card(NULL, NULL); 
									gofish.plr1Size--;

								}

							}
							for (int j=0; j<gofish.plr2Size; j++) {

								if (gofish.player2Hand[j].value == NULL && gofish.player2Hand[j].suit == NULL) {
									gofish.player2Hand[j] = gofish.player2Hand[j+1];
									gofish.player2Hand[j+1] = card(NULL, NULL);
									gofish.plr2Size--;

								}

							}
							if (!cardFound) {
								cout << gofish.plr2Name << "> No, I do not have any " << gofish.player1Hand[12].value << " cards. Go Fish!" << endl;
								gofish.player1Hand[gofish.plr1Size] = gofish.cardDeck[gofish.topCard];
								gofish.topCard++;
								gofish.plr1Size++;
								gofish.displayp1();
								gofish.displayp2();
								cin.get();
							}
						}
						break;

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
		//PLAYER 2 TURN
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
					switch (event.Event.KeyEvent.wVirtualKeyCode) {
					case 'C':
						counter++;
						gofish.displayp1();
						gofish.displayp2();
						break;
					case '1':
						gofish.clearScreen();
						if (gofish.plr2Size >= 1) {

							//cout << gofish.plr2Name << "> Do you have any " << gofish.player2Hand[0].value << "s?" << endl;

							gofish.displayp1();
							gofish.displayp2();
							bool cardFound = false;
							for (int i=0; i<gofish.plr1Size; i++) {
								cout << gofish.player2Hand[0].value << "|" << gofish.player1Hand[i].value << endl;
								if (gofish.player2Hand[0].value == gofish.player1Hand[i].value) {
									cardFound = true;
									cout << gofish.plr1Name << "> Yes, I have a/an" << gofish.player2Hand[0].value << " card." << endl;

									gofish.player2Hand[0] = card(NULL, NULL);
									gofish.player1Hand[i] = card(NULL, NULL);


									gofish.plr2Score++;
									gofish.displayp1();
									gofish.displayp2();

									break;
								} 
							}
							for (int j=0; j<gofish.plr2Size; j++) {

								if (gofish.player2Hand[j].value == NULL && gofish.player2Hand[j].suit == NULL) {
									gofish.player2Hand[j] = gofish.player2Hand[j+1];
									gofish.player2Hand[j+1] = card(NULL, NULL); 
									gofish.plr2Size--;

								}

							}
							for (int j=0; j<gofish.plr1Size; j++) {

								if (gofish.player1Hand[j].value == NULL && gofish.player1Hand[j].suit == NULL) {
									gofish.player1Hand[j] = gofish.player1Hand[j+1];
									gofish.player1Hand[j+1] = card(NULL, NULL);
									gofish.plr1Size--;

								}

							}
							if (!cardFound) {
								cout << gofish.plr1Name << "> No, I do not have any " << gofish.player2Hand[0].value << " cards. Go Fish!" << endl;
								gofish.player2Hand[gofish.plr2Size] = gofish.cardDeck[gofish.topCard];
								gofish.topCard++;
								gofish.plr2Size++;
								gofish.displayp1();
								gofish.displayp2();
								cin.get();
							}
						}
						break;
					case '2':
						gofish.clearScreen();
						if (gofish.plr2Size >= 3) {

							//cout << gofish.plr2Name << "> Do you have any " << gofish.player2Hand[0].value << "s?" << endl;

							gofish.displayp1();
							gofish.displayp2();
							bool cardFound = false;
							for (int i=0; i<gofish.plr1Size; i++) {
								cout << gofish.player2Hand[1].value << "|" << gofish.player1Hand[i].value << endl;
								if (gofish.player2Hand[1].value == gofish.player1Hand[i].value) {
									cardFound = true;
									cout << gofish.plr1Name << "> Yes, I have a/an" << gofish.player2Hand[1].value << " card." << endl;

									gofish.player2Hand[1] = card(NULL, NULL);
									gofish.player1Hand[i] = card(NULL, NULL);


									gofish.plr2Score++;
									gofish.displayp1();
									gofish.displayp2();

									break;
								} 
							}
							for (int j=0; j<gofish.plr2Size; j++) {

								if (gofish.player2Hand[j].value == NULL && gofish.player2Hand[j].suit == NULL) {
									gofish.player2Hand[j] = gofish.player2Hand[j+1];
									gofish.player2Hand[j+1] = card(NULL, NULL); 
									gofish.plr2Size--;

								}

							}
							for (int j=0; j<gofish.plr1Size; j++) {

								if (gofish.player1Hand[j].value == NULL && gofish.player1Hand[j].suit == NULL) {
									gofish.player1Hand[j] = gofish.player1Hand[j+1];
									gofish.player1Hand[j+1] = card(NULL, NULL);
									gofish.plr1Size--;

								}

							}
							if (!cardFound) {
								cout << gofish.plr1Name << "> No, I do not have any " << gofish.player2Hand[1].value << " cards. Go Fish!" << endl;
								gofish.player2Hand[gofish.plr2Size] = gofish.cardDeck[gofish.topCard];
								gofish.topCard++;
								gofish.plr2Size++;
								gofish.displayp1();
								gofish.displayp2();
								cin.get();
							}
						}
						break;
					case '3':
						gofish.clearScreen();
						if (gofish.plr2Size >= 4) {

							//cout << gofish.plr2Name << "> Do you have any " << gofish.player2Hand[0].value << "s?" << endl;

							gofish.displayp1();
							gofish.displayp2();
							bool cardFound = false;
							for (int i=0; i<gofish.plr1Size; i++) {
								cout << gofish.player2Hand[2].value << "|" << gofish.player1Hand[i].value << endl;
								if (gofish.player2Hand[2].value == gofish.player1Hand[i].value) {
									cardFound = true;
									cout << gofish.plr1Name << "> Yes, I have a/an" << gofish.player2Hand[2].value << " card." << endl;

									gofish.player2Hand[2] = card(NULL, NULL);
									gofish.player1Hand[i] = card(NULL, NULL);


									gofish.plr2Score++;
									gofish.displayp1();
									gofish.displayp2();

									break;
								} 
							}
							for (int j=0; j<gofish.plr2Size; j++) {

								if (gofish.player2Hand[j].value == NULL && gofish.player2Hand[j].suit == NULL) {
									gofish.player2Hand[j] = gofish.player2Hand[j+1];
									gofish.player2Hand[j+1] = card(NULL, NULL); 
									gofish.plr2Size--;

								}

							}
							for (int j=0; j<gofish.plr1Size; j++) {

								if (gofish.player1Hand[j].value == NULL && gofish.player1Hand[j].suit == NULL) {
									gofish.player1Hand[j] = gofish.player1Hand[j+1];
									gofish.player1Hand[j+1] = card(NULL, NULL);
									gofish.plr1Size--;

								}

							}
							if (!cardFound) {
								cout << gofish.plr1Name << "> No, I do not have any " << gofish.player2Hand[2].value << " cards. Go Fish!" << endl;
								gofish.player2Hand[gofish.plr2Size] = gofish.cardDeck[gofish.topCard];
								gofish.topCard++;
								gofish.plr2Size++;
								gofish.displayp1();
								gofish.displayp2();
								cin.get();
							}
						}
						break;
					case '4':
						gofish.clearScreen();
						if (gofish.plr2Size >= 5) {

							//cout << gofish.plr2Name << "> Do you have any " << gofish.player2Hand[0].value << "s?" << endl;

							gofish.displayp1();
							gofish.displayp2();
							bool cardFound = false;
							for (int i=0; i<gofish.plr1Size; i++) {
								cout << gofish.player2Hand[3].value << "|" << gofish.player1Hand[i].value << endl;
								if (gofish.player2Hand[3].value == gofish.player1Hand[i].value) {
									cardFound = true;
									cout << gofish.plr1Name << "> Yes, I have a/an" << gofish.player2Hand[3].value << " card." << endl;

									gofish.player2Hand[3] = card(NULL, NULL);
									gofish.player1Hand[i] = card(NULL, NULL);


									gofish.plr2Score++;
									gofish.displayp1();
									gofish.displayp2();

									break;
								} 
							}
							for (int j=0; j<gofish.plr2Size; j++) {

								if (gofish.player2Hand[j].value == NULL && gofish.player2Hand[j].suit == NULL) {
									gofish.player2Hand[j] = gofish.player2Hand[j+1];
									gofish.player2Hand[j+1] = card(NULL, NULL); 
									gofish.plr2Size--;

								}

							}
							for (int j=0; j<gofish.plr1Size; j++) {

								if (gofish.player1Hand[j].value == NULL && gofish.player1Hand[j].suit == NULL) {
									gofish.player1Hand[j] = gofish.player1Hand[j+1];
									gofish.player1Hand[j+1] = card(NULL, NULL);
									gofish.plr1Size--;

								}

							}
							if (!cardFound) {
								cout << gofish.plr1Name << "> No, I do not have any " << gofish.player2Hand[3].value << " cards. Go Fish!" << endl;
								gofish.player2Hand[gofish.plr2Size] = gofish.cardDeck[gofish.topCard];
								gofish.topCard++;
								gofish.plr2Size++;
								gofish.displayp1();
								gofish.displayp2();
								cin.get();
							}
						}
						break;
					case '5':
						gofish.clearScreen();
						if (gofish.plr2Size >= 6) {

							//cout << gofish.plr2Name << "> Do you have any " << gofish.player2Hand[0].value << "s?" << endl;

							gofish.displayp1();
							gofish.displayp2();
							bool cardFound = false;
							for (int i=0; i<gofish.plr1Size; i++) {
								cout << gofish.player2Hand[4].value << "|" << gofish.player1Hand[i].value << endl;
								if (gofish.player2Hand[4].value == gofish.player1Hand[i].value) {
									cardFound = true;
									cout << gofish.plr1Name << "> Yes, I have a/an" << gofish.player2Hand[0].value << " card." << endl;

									gofish.player2Hand[4] = card(NULL, NULL);
									gofish.player1Hand[i] = card(NULL, NULL);


									gofish.plr2Score++;
									gofish.displayp1();
									gofish.displayp2();

									break;
								} 
							}
							for (int j=0; j<gofish.plr2Size; j++) {

								if (gofish.player2Hand[j].value == NULL && gofish.player2Hand[j].suit == NULL) {
									gofish.player2Hand[j] = gofish.player2Hand[j+1];
									gofish.player2Hand[j+1] = card(NULL, NULL); 
									gofish.plr2Size--;

								}

							}
							for (int j=0; j<gofish.plr1Size; j++) {

								if (gofish.player1Hand[j].value == NULL && gofish.player1Hand[j].suit == NULL) {
									gofish.player1Hand[j] = gofish.player1Hand[j+1];
									gofish.player1Hand[j+1] = card(NULL, NULL);
									gofish.plr1Size--;

								}

							}
							if (!cardFound) {
								cout << gofish.plr1Name << "> No, I do not have any " << gofish.player2Hand[4].value << " cards. Go Fish!" << endl;
								gofish.player2Hand[gofish.plr2Size] = gofish.cardDeck[gofish.topCard];
								gofish.topCard++;
								gofish.plr2Size++;
								gofish.displayp1();
								gofish.displayp2();
								cin.get();
							}
						}
						break;
					case '6':
						gofish.clearScreen();
						if (gofish.plr2Size >= 7) {

							//cout << gofish.plr2Name << "> Do you have any " << gofish.player2Hand[0].value << "s?" << endl;

							gofish.displayp1();
							gofish.displayp2();
							bool cardFound = false;
							for (int i=0; i<gofish.plr1Size; i++) {
								cout << gofish.player2Hand[5].value << "|" << gofish.player1Hand[i].value << endl;
								if (gofish.player2Hand[5].value == gofish.player1Hand[i].value) {
									cardFound = true;
									cout << gofish.plr1Name << "> Yes, I have a/an" << gofish.player2Hand[5].value << " card." << endl;

									gofish.player2Hand[5] = card(NULL, NULL);
									gofish.player1Hand[i] = card(NULL, NULL);


									gofish.plr2Score++;
									gofish.displayp1();
									gofish.displayp2();

									break;
								} 
							}
							for (int j=0; j<gofish.plr2Size; j++) {

								if (gofish.player2Hand[j].value == NULL && gofish.player2Hand[j].suit == NULL) {
									gofish.player2Hand[j] = gofish.player2Hand[j+1];
									gofish.player2Hand[j+1] = card(NULL, NULL); 
									gofish.plr2Size--;

								}

							}
							for (int j=0; j<gofish.plr1Size; j++) {

								if (gofish.player1Hand[j].value == NULL && gofish.player1Hand[j].suit == NULL) {
									gofish.player1Hand[j] = gofish.player1Hand[j+1];
									gofish.player1Hand[j+1] = card(NULL, NULL);
									gofish.plr1Size--;

								}

							}
							if (!cardFound) {
								cout << gofish.plr1Name << "> No, I do not have any " << gofish.player2Hand[5].value << " cards. Go Fish!" << endl;
								gofish.player2Hand[gofish.plr2Size] = gofish.cardDeck[gofish.topCard];
								gofish.topCard++;
								gofish.plr2Size++;
								gofish.displayp1();
								gofish.displayp2();
								cin.get();
							}
						}
						break;
					case '7':gofish.clearScreen();
						if (gofish.plr2Size >= 8) {

							//cout << gofish.plr2Name << "> Do you have any " << gofish.player2Hand[0].value << "s?" << endl;

							gofish.displayp1();
							gofish.displayp2();
							bool cardFound = false;
							for (int i=0; i<gofish.plr1Size; i++) {
								cout << gofish.player2Hand[6].value << "|" << gofish.player1Hand[i].value << endl;
								if (gofish.player2Hand[6].value == gofish.player1Hand[i].value) {
									cardFound = true;
									cout << gofish.plr1Name << "> Yes, I have a/an" << gofish.player2Hand[6].value << " card." << endl;

									gofish.player2Hand[6] = card(NULL, NULL);
									gofish.player1Hand[i] = card(NULL, NULL);


									gofish.plr2Score++;
									gofish.displayp1();
									gofish.displayp2();

									break;
								} 
							}
							for (int j=0; j<gofish.plr2Size; j++) {

								if (gofish.player2Hand[j].value == NULL && gofish.player2Hand[j].suit == NULL) {
									gofish.player2Hand[j] = gofish.player2Hand[j+1];
									gofish.player2Hand[j+1] = card(NULL, NULL); 
									gofish.plr2Size--;

								}

							}
							for (int j=0; j<gofish.plr1Size; j++) {

								if (gofish.player1Hand[j].value == NULL && gofish.player1Hand[j].suit == NULL) {
									gofish.player1Hand[j] = gofish.player1Hand[j+1];
									gofish.player1Hand[j+1] = card(NULL, NULL);
									gofish.plr1Size--;

								}

							}
							if (!cardFound) {
								cout << gofish.plr1Name << "> No, I do not have any " << gofish.player2Hand[6].value << " cards. Go Fish!" << endl;
								gofish.player2Hand[gofish.plr2Size] = gofish.cardDeck[gofish.topCard];
								gofish.topCard++;
								gofish.plr2Size++;
								gofish.displayp1();
								gofish.displayp2();
								cin.get();
							}
						}
						break;
					case '8':
						gofish.clearScreen();
						if (gofish.plr2Size >= 9) {

							//cout << gofish.plr2Name << "> Do you have any " << gofish.player2Hand[0].value << "s?" << endl;

							gofish.displayp1();
							gofish.displayp2();
							bool cardFound = false;
							for (int i=0; i<gofish.plr1Size; i++) {
								cout << gofish.player2Hand[7].value << "|" << gofish.player1Hand[i].value << endl;
								if (gofish.player2Hand[7].value == gofish.player1Hand[i].value) {
									cardFound = true;
									cout << gofish.plr1Name << "> Yes, I have a/an" << gofish.player2Hand[7].value << " card." << endl;

									gofish.player2Hand[7] = card(NULL, NULL);
									gofish.player1Hand[i] = card(NULL, NULL);


									gofish.plr2Score++;
									gofish.displayp1();
									gofish.displayp2();

									break;
								} 
							}
							for (int j=0; j<gofish.plr2Size; j++) {

								if (gofish.player2Hand[j].value == NULL && gofish.player2Hand[j].suit == NULL) {
									gofish.player2Hand[j] = gofish.player2Hand[j+1];
									gofish.player2Hand[j+1] = card(NULL, NULL); 
									gofish.plr2Size--;

								}

							}
							for (int j=0; j<gofish.plr1Size; j++) {

								if (gofish.player1Hand[j].value == NULL && gofish.player1Hand[j].suit == NULL) {
									gofish.player1Hand[j] = gofish.player1Hand[j+1];
									gofish.player1Hand[j+1] = card(NULL, NULL);
									gofish.plr1Size--;

								}

							}
							if (!cardFound) {
								cout << gofish.plr1Name << "> No, I do not have any " << gofish.player2Hand[7].value << " cards. Go Fish!" << endl;
								gofish.player2Hand[gofish.plr2Size] = gofish.cardDeck[gofish.topCard];
								gofish.topCard++;
								gofish.plr2Size++;
								gofish.displayp1();
								gofish.displayp2();
								cin.get();
							}
						}
						break;
					case '9':
						gofish.clearScreen();
						if (gofish.plr2Size >= 10) {

							//cout << gofish.plr2Name << "> Do you have any " << gofish.player2Hand[0].value << "s?" << endl;

							gofish.displayp1();
							gofish.displayp2();
							bool cardFound = false;
							for (int i=0; i<gofish.plr1Size; i++) {
								cout << gofish.player2Hand[8].value << "|" << gofish.player1Hand[i].value << endl;
								if (gofish.player2Hand[8].value == gofish.player1Hand[i].value) {
									cardFound = true;
									cout << gofish.plr1Name << "> Yes, I have a/an" << gofish.player2Hand[8].value << " card." << endl;

									gofish.player2Hand[8] = card(NULL, NULL);
									gofish.player1Hand[i] = card(NULL, NULL);


									gofish.plr2Score++;
									gofish.displayp1();
									gofish.displayp2();

									break;
								} 
							}
							for (int j=0; j<gofish.plr2Size; j++) {

								if (gofish.player2Hand[j].value == NULL && gofish.player2Hand[j].suit == NULL) {
									gofish.player2Hand[j] = gofish.player2Hand[j+1];
									gofish.player2Hand[j+1] = card(NULL, NULL); 
									gofish.plr2Size--;

								}

							}
							for (int j=0; j<gofish.plr1Size; j++) {

								if (gofish.player1Hand[j].value == NULL && gofish.player1Hand[j].suit == NULL) {
									gofish.player1Hand[j] = gofish.player1Hand[j+1];
									gofish.player1Hand[j+1] = card(NULL, NULL);
									gofish.plr1Size--;

								}

							}
							if (!cardFound) {
								cout << gofish.plr1Name << "> No, I do not have any " << gofish.player2Hand[8].value << " cards. Go Fish!" << endl;
								gofish.player2Hand[gofish.plr2Size] = gofish.cardDeck[gofish.topCard];
								gofish.topCard++;
								gofish.plr2Size++;
								gofish.displayp1();
								gofish.displayp2();
								cin.get();
							}
						}
						break;
					case '10':
						gofish.clearScreen();
						if (gofish.plr2Size >= 11) {

							//cout << gofish.plr2Name << "> Do you have any " << gofish.player2Hand[0].value << "s?" << endl;

							gofish.displayp1();
							gofish.displayp2();
							bool cardFound = false;
							for (int i=0; i<gofish.plr1Size; i++) {
								cout << gofish.player2Hand[9].value << "|" << gofish.player1Hand[i].value << endl;
								if (gofish.player2Hand[9].value == gofish.player1Hand[i].value) {
									cardFound = true;
									cout << gofish.plr1Name << "> Yes, I have a/an" << gofish.player2Hand[0].value << " card." << endl;

									gofish.player2Hand[9] = card(NULL, NULL);
									gofish.player1Hand[i] = card(NULL, NULL);


									gofish.plr2Score++;
									gofish.displayp1();
									gofish.displayp2();

									break;
								} 
							}
							for (int j=0; j<gofish.plr2Size; j++) {

								if (gofish.player2Hand[j].value == NULL && gofish.player2Hand[j].suit == NULL) {
									gofish.player2Hand[j] = gofish.player2Hand[j+1];
									gofish.player2Hand[j+1] = card(NULL, NULL); 
									gofish.plr2Size--;

								}

							}
							for (int j=0; j<gofish.plr1Size; j++) {

								if (gofish.player1Hand[j].value == NULL && gofish.player1Hand[j].suit == NULL) {
									gofish.player1Hand[j] = gofish.player1Hand[j+1];
									gofish.player1Hand[j+1] = card(NULL, NULL);
									gofish.plr1Size--;

								}

							}
							if (!cardFound) {
								cout << gofish.plr1Name << "> No, I do not have any " << gofish.player2Hand[9].value << " cards. Go Fish!" << endl;
								gofish.player2Hand[gofish.plr2Size] = gofish.cardDeck[gofish.topCard];
								gofish.topCard++;
								gofish.plr2Size++;
								gofish.displayp1();
								gofish.displayp2();
								cin.get();
							}
						}
						break;
					case '11':
						gofish.clearScreen();
						if (gofish.plr2Size >= 12) {

							//cout << gofish.plr2Name << "> Do you have any " << gofish.player2Hand[0].value << "s?" << endl;

							gofish.displayp1();
							gofish.displayp2();
							bool cardFound = false;
							for (int i=0; i<gofish.plr1Size; i++) {
								cout << gofish.player2Hand[10].value << "|" << gofish.player1Hand[i].value << endl;
								if (gofish.player2Hand[10].value == gofish.player1Hand[i].value) {
									cardFound = true;
									cout << gofish.plr1Name << "> Yes, I have a/an" << gofish.player2Hand[10].value << " card." << endl;

									gofish.player2Hand[10] = card(NULL, NULL);
									gofish.player1Hand[i] = card(NULL, NULL);


									gofish.plr2Score++;
									gofish.displayp1();
									gofish.displayp2();

									break;
								} 
							}
							for (int j=0; j<gofish.plr2Size; j++) {

								if (gofish.player2Hand[j].value == NULL && gofish.player2Hand[j].suit == NULL) {
									gofish.player2Hand[j] = gofish.player2Hand[j+1];
									gofish.player2Hand[j+1] = card(NULL, NULL); 
									gofish.plr2Size--;

								}

							}
							for (int j=0; j<gofish.plr1Size; j++) {

								if (gofish.player1Hand[j].value == NULL && gofish.player1Hand[j].suit == NULL) {
									gofish.player1Hand[j] = gofish.player1Hand[j+1];
									gofish.player1Hand[j+1] = card(NULL, NULL);
									gofish.plr1Size--;

								}

							}
							if (!cardFound) {
								cout << gofish.plr1Name << "> No, I do not have any " << gofish.player2Hand[10].value << " cards. Go Fish!" << endl;
								gofish.player2Hand[gofish.plr2Size] = gofish.cardDeck[gofish.topCard];
								gofish.topCard++;
								gofish.plr2Size++;
								gofish.displayp1();
								gofish.displayp2();
								cin.get();
							}
						}
						break;
					case '12':
						gofish.clearScreen();
						if (gofish.plr2Size >= 13) {

							//cout << gofish.plr2Name << "> Do you have any " << gofish.player2Hand[0].value << "s?" << endl;

							gofish.displayp1();
							gofish.displayp2();
							bool cardFound = false;
							for (int i=0; i<gofish.plr1Size; i++) {
								cout << gofish.player2Hand[11].value << "|" << gofish.player1Hand[i].value << endl;
								if (gofish.player2Hand[11].value == gofish.player1Hand[i].value) {
									cardFound = true;
									cout << gofish.plr1Name << "> Yes, I have a/an" << gofish.player2Hand[11].value << " card." << endl;

									gofish.player2Hand[11] = card(NULL, NULL);
									gofish.player1Hand[i] = card(NULL, NULL);


									gofish.plr2Score++;
									gofish.displayp1();
									gofish.displayp2();

									break;
								} 
							}
							for (int j=0; j<gofish.plr2Size; j++) {

								if (gofish.player2Hand[j].value == NULL && gofish.player2Hand[j].suit == NULL) {
									gofish.player2Hand[j] = gofish.player2Hand[j+1];
									gofish.player2Hand[j+1] = card(NULL, NULL); 
									gofish.plr2Size--;

								}

							}
							for (int j=0; j<gofish.plr1Size; j++) {

								if (gofish.player1Hand[j].value == NULL && gofish.player1Hand[j].suit == NULL) {
									gofish.player1Hand[j] = gofish.player1Hand[j+1];
									gofish.player1Hand[j+1] = card(NULL, NULL);
									gofish.plr1Size--;

								}

							}
							if (!cardFound) {
								cout << gofish.plr1Name << "> No, I do not have any " << gofish.player2Hand[11].value << " cards. Go Fish!" << endl;
								gofish.player2Hand[gofish.plr2Size] = gofish.cardDeck[gofish.topCard];
								gofish.topCard++;
								gofish.plr2Size++;
								gofish.displayp1();
								gofish.displayp2();
								cin.get();
							}
						}
						break;
					case '13':
						gofish.clearScreen();
						if (gofish.plr2Size >= 14) {

							//cout << gofish.plr2Name << "> Do you have any " << gofish.player2Hand[0].value << "s?" << endl;

							gofish.displayp1();
							gofish.displayp2();
							bool cardFound = false;
							for (int i=0; i<gofish.plr1Size; i++) {
								cout << gofish.player2Hand[12].value << "|" << gofish.player1Hand[i].value << endl;
								if (gofish.player2Hand[12].value == gofish.player1Hand[i].value) {
									cardFound = true;
									cout << gofish.plr1Name << "> Yes, I have a/an" << gofish.player2Hand[12].value << " card." << endl;

									gofish.player2Hand[12] = card(NULL, NULL);
									gofish.player1Hand[i] = card(NULL, NULL);


									gofish.plr2Score++;
									gofish.displayp1();
									gofish.displayp2();

									break;
								} 
							}
							for (int j=0; j<gofish.plr2Size; j++) {

								if (gofish.player2Hand[j].value == NULL && gofish.player2Hand[j].suit == NULL) {
									gofish.player2Hand[j] = gofish.player2Hand[j+1];
									gofish.player2Hand[j+1] = card(NULL, NULL); 
									gofish.plr2Size--;

								}

							}
							for (int j=0; j<gofish.plr1Size; j++) {

								if (gofish.player1Hand[j].value == NULL && gofish.player1Hand[j].suit == NULL) {
									gofish.player1Hand[j] = gofish.player1Hand[j+1];
									gofish.player1Hand[j+1] = card(NULL, NULL);
									gofish.plr1Size--;

								}

							}
							if (!cardFound) {
								cout << gofish.plr1Name << "> No, I do not have any " << gofish.player2Hand[12].value << " cards. Go Fish!" << endl;
								gofish.player2Hand[gofish.plr2Size] = gofish.cardDeck[gofish.topCard];
								gofish.topCard++;
								gofish.plr2Size++;
								gofish.displayp1();
								gofish.displayp2();
								cin.get();
							}
						}
						break;

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