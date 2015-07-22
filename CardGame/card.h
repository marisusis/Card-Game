#include <string>
#include <time.h>
#include <cstdlib>

using namespace std;

class card {
	
public:
	//Varibles
	int value;
	char suit;

	//Constructors
	card() {
		value = 14;
		suit = 'S';
	}
	card(int v, char s) {
		value = v;
		suit = s;
	}
	string displayCard() {
		string displayValue = "[";
		if (value < 11) {
			displayValue += to_string(value);
		}
		if (value == 11) {
			displayValue += "J";
		}
		if (value == 12) {
			displayValue += "Q";
		}
		if (value == 13) {
			displayValue += "K";
		}
		if (value == 14) {
			displayValue += "A";
		}
		//displayValue += "-";
		displayValue += suit;
		displayValue += "]";

		return displayValue;
	}
};
void shuffle(card deck[], int len)
{
    srand((unsigned int)time(NULL));
	for (int i = 0; i < len; i++)
    {
        int r = rand() % (len - i) + i;
 
        card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}