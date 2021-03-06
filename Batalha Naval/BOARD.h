#ifndef _BOARD
#define _BOARD
#include "STRUCTS.h"
#include <string>
#include <vector>
#include "SHIP.h"
#include "BOMB.h"

class Board
{ 
public:
	friend ostream &operator<<(ostream& out, const Board board);
	Board(const string &filename); // loads board from file 'filename'
	bool putShip(const Ship &s); // adds ship to the board, if possible 
	void moveShips(); // tries to randmonly move all the ships of the fleet
	bool attack(const Bomb &b);
	void display() const; // displays the colored board during the game
	void show() const; // shows the attributes of the board (for debugging)
	int getNumLines() const;
	int getShipStatus(int ind, int linha, int coluna);
	int getNumColumns() const;
	bool verifyFleet();
	int FleetArea();
	int BoardArea();
	Ship ReturnShip(size_t ind) const;
	int GetBoardPos(int lin, int col) const;
private:
	int numLines, numColumns; // redundant info �
	vector<Ship> ships; // ships that are placed on the board
	vector<vector<int>> board; // each element indicates
	// the index of a ship in the 'ships' vector
	// (in the range 0..ships.size()-1) ;
	// -1 is used to represent the sea
};
#endif