// Battleship program
// Written by Alex Jordan

// Note: you should only ever interact with battleship.* in this. The battleship class will handle everything else.

#include <iostream>
#include <cstdlib>
#include "battleship.h"
using namespace std;

int main()
{
	cout << "Initializing... \n";
	battleship battleship;
	cout << "Setting active player...\n";
	battleship.changeActivePlayer(1);
	cout << "Rendering...\n";
	battleship.render();
	cout << "Done. Unfortunately, nothing else can be done. Bye!";
	return 0;
}
