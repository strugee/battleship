// Battleship class structure
// Written by Alex Jordan

//#include <iostream>
//#include <cstdlib>

// header guard - so compilers don't throw errors if this is #included more than once
#ifndef __BATTLESHIP_H_INCLUDED__
#define __BATTLESHIP_H_INCLUDED__

#include <iostream>
#include <cstdlib>

class board {
	public:
		void updateinternalboard(int coordinate1, int coordinate2, int value) {
			board[coordinate1][coordinate2] = value;
		}
	private:
		int getCoordinateValue(int coordinate1, int coordinate2) {
			return board[coordinate1][coordinate2];
		}
		int board[9][9];
}

class player {
	public:
	
	private:
		board ships; // this board holds the ships of the player.
		board shots; // this board tracks the player's shots at the other player's ships
}

class battleship {
	public:
		void changeActivePlayer(int input) {
			if (input == 0) {
				if (activePlayer == 1) {
					activePlayer = 2;
				}
				if (activePlayer == 2) {
					activePlayer = 1;
				}
			}
			if (input == 1) {
				activePlayer = 1;
			}
			if (input == 2) {
				activePlayer = 2;
			}
		}
		
		void render() {
			if (activePlayer == 1) {
				for (int coordinate1 = 0; coordinate1 <= 10; coordinate1++) {
					cout << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----";
					for (int coordinate2; coordinate2 <= 10; coordinate2++) {
						cout << "| " << coordinate2 << " ";
						if (coordinate2 == 10) {
							cout << "|"
						}
					}
				}
				cout << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----";
			}
		}
		
		void updateboard(int coordinate1, int coordinate2, int boardID, int value) {
			if (boardID == 1) {
				// if it's player 1's board with player 1's ships
				player1.ships.updateinternalboard(coordinate1, coordinate2, value);
			}
			if (boardID == 2) {
				// if it's player 1's board tracking player 1's shots
				player1.shots.updateinternalboard(coordinate1, coordinate2, value);
			}
			if (boardID == 3) {
				// if it's player 2's board with player 2's ships
				player2.ships.updateinternalboard(coordinate1, coordinate2, value);
			}
			if (boardID == 4) {
				// if it's player 2's board tracking player 2's shots
				player2.ships.updateinternalboard(coordinate1, coordinate2, value);
			}
		}
		
	private:
		int activePlayer = 1;
		player player1;
		player player2;
}

// end header guard
#endif
