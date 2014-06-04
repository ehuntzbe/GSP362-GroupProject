#include "Character.h"
#include "Commands.h"
#include "world.h"
#include "Room.h"
#include "ItemStructure.h"
#include "Combat.h"
#include "Save and Load.h"
#include "Interface.h"

int main()
{
	cout << " DDD      A      R R R  K   K   GGGGG U    U N      N \n"
		" D  D    A A     R   R  K  K    G     U    U N N    N \n"
		" D   D  A   A    R  R   K K     G     U    U N  N   N \n"
		" D   D A A A A   R R    K  K    G GGG U    U N   N  N \n"
		" D  D A       A  R   R  K   K   G   G U    U N    N N \n"
		" DDD A         A R    R K    K  GGGGG UUUUUU N     NN \n" << endl;

	int nKeyPress; // Holds the key pressed by the user
	bool bContinue = true;

	while ( bContinue )
	{
		// read a key here into nKeypress
		cout << " 1) New Game " << endl;
		cout << " 2) Load Game " << endl;
		cout << " 3) Credits " << endl;
		cout << " 4) Exit " << endl;
		cout << "\n What would you like to do? ";
		cin >> nKeyPress;
		cin.clear();

		switch ( nKeyPress )
		{
		case 1:
			{cout << "\n New game starting\n ";
			PC->GenderNamePrompt();
			Interface::GetInstance()->MainGame();}
			break;

		case 2:
			{cout << "\n Your game is loading\n ";}
			break;

		case 3:
			{cout << "\n Credits Screen \n ";}
			break;

		case 4:
			{cout << "\n To exit the game ";}
			break;

			//Other than 1, 2, 3, 4
		default : cout << "\n Invalid Selection ";
			// no break in the default case
		}
		cout << "\n";

		if( nKeyPress == 4)
		{
			return (0);
		}
	}
}