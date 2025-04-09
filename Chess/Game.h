#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <string>
#include <stdlib.h> 
#include <conio.h>

enum Piece { KING, QUEEN, BISHOP, HORSE, TOWER, PAWN, EMPTY };
enum Color { WHITE, BLACK, NONE };
enum Alphabet { A, B, C, D, E, F, G, H, ZERO };



class Auxiliary
{
private:
	Piece piece;
	Color color;
	Alphabet alphabet;
	int x, y;
	

public:
	Auxiliary();    
	~Auxiliary() {}
	void setSpace(Auxiliary*);
	void setEmpty();
	void setPieceAndColor(Piece, Color);
	Piece getPiece();
	Color getColor();
	void setX(int ex) { x = ex; }
	void setY(int why) { y = why; }
	int getX() { return x; }
	int getY() { return y; }


};

class Game
{
private:
	Auxiliary Board[8][8];
	Color turn = WHITE;

	bool moveKing(Auxiliary* thisKing, Auxiliary* thatSpace);
	bool moveQueen(Auxiliary* thisQueen, Auxiliary* thatSpace);
	bool moveBishop(Auxiliary* thisBishop, Auxiliary* thatSpace);
	bool moveHorse(Auxiliary* thisHorse, Auxiliary* thatSpace);
	bool moveTower(Auxiliary* thisTower, Auxiliary* thatSpace);
	bool movePawn(Auxiliary* thisPawn, Auxiliary* thatSpace);
	bool makeMove(int x1, int y1, int x2, int y2);

	void GameBoard();


public:
	void Guide();
	void Menu();
	void setBoard();

	Auxiliary* getAuxiliary(int x, int y)
	{
		return &Board[x][y];
	}

	bool Move();
	bool playGame();
};
#endif
