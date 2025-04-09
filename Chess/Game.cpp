#include "Game.h"


Auxiliary::Auxiliary()
{
	piece = EMPTY;
	color = NONE;
	alphabet = ZERO;
}

void Auxiliary::setSpace(Auxiliary* space)
{
	color = space->getColor();
	piece = space->getPiece();
}

void Auxiliary::setEmpty()
{
	color = NONE;
	piece = EMPTY;
	alphabet = ZERO;
}

Piece Auxiliary::getPiece()
{
	return piece;
}

Color Auxiliary::getColor()
{
	return color;
}

void Auxiliary::setPieceAndColor(Piece p, Color c)
{
	piece = p;
	color = c;
}

void Game::Guide() {

	using std::cout;

	cout << "wT = White Tower.\n";
	cout << "wH = White Horse.\n";
	cout << "wB = White Bishop.\n";
	cout << "wQ = White Queen.\n";
	cout << "wK = White King.\n";
	cout << "wP = White Pawn.\n\n";

	cout << "bT = Black Tower.\n";
	cout << "bH = Black Horse.\n";
	cout << "bB = Black Bishop.\n";
	cout << "bQ = Black Queen.\n";
	cout << "bK = Black King.\n";
	cout << "bP = Black Pawn.\n\n";


	cout << "1. Select the piece you want to play with (X, Y).\n";
	cout << "2. Choose where the selected piece should move (X, Y). \n";
	cout << "3. The other player's move.\n";
	cout << "4. Game ends with mat or pat.\n\n";

	cout << "Press any key for return to menu.\n";
	_getch();

	system("cls");
	Menu();

}


void Game::Menu() {

	int choice;
	bool newgame = true;
	std::string s;

	std::cout << "1. GAME \n";
	std::cout << "2. GUIDE \n";
	std::cout << "3. EXIT \n\n";

	std::cin >> choice;
	switch (choice) {
	case 1:
		system("cls");
		while (newgame) {
			setBoard();
			while (playGame());
			std::cout << "Do you want to play again? (y for yes, anything else for no) ";
			std::cin >> s;
			if (s != "y")
				newgame = false;
		}
		break;
	case 2:
		system("cls");
		Guide();
	case 3:
		std::cout << "GOODBYE! \n";
		break;
	default:
		std::cout << "Wrong choice. Choose again.\n";
		std::cin >> choice;
	}
}

bool Game::playGame()
{
	system("cls");
	GameBoard();
	return Move();

}

void Game::setBoard()
{
	Board[0][0].setPieceAndColor(TOWER, WHITE);
	Board[1][0].setPieceAndColor(HORSE, WHITE);
	Board[2][0].setPieceAndColor(BISHOP, WHITE);
	Board[3][0].setPieceAndColor(QUEEN, WHITE);
	Board[4][0].setPieceAndColor(KING, WHITE);
	Board[5][0].setPieceAndColor(BISHOP, WHITE);
	Board[6][0].setPieceAndColor(HORSE, WHITE);
	Board[7][0].setPieceAndColor(TOWER, WHITE);

	Board[0][7].setPieceAndColor(TOWER, BLACK);
	Board[1][7].setPieceAndColor(HORSE, BLACK);
	Board[2][7].setPieceAndColor(BISHOP, BLACK);
	Board[3][7].setPieceAndColor(QUEEN, BLACK);
	Board[4][7].setPieceAndColor(KING, BLACK);
	Board[5][7].setPieceAndColor(BISHOP, BLACK);
	Board[6][7].setPieceAndColor(HORSE, BLACK);
	Board[7][7].setPieceAndColor(TOWER, BLACK);



	for (int i = 0; i < 8; i++)
	{
		Board[i][1].setPieceAndColor(PAWN, WHITE);
		Board[i][6].setPieceAndColor(PAWN, BLACK);

	}

	for (int i = 2; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
			Board[j][i].setPieceAndColor(EMPTY, NONE);

	}
	
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			Board[i][j].setX(i);
			Board[i][j].setY(j);
		}
	
}

void Game::GameBoard()
{
	system("cls");
	using std::cout;
	using std::cin;
	using std::endl;
	
	cout << "     A    B    C    D    E    F    G    H ";

	for (int i = 0; i < 8; i++) {
		cout << "\n   ----------------------------------------\n";
		cout << i+1  << " ";

		for (int j = 0; j < 8; j++) {
	
			Piece p = Board[j][i].getPiece();
			Color c = Board[j][i].getColor();

			cout << "|";

			switch (p)
			{
			case KING: (c == WHITE) ? cout << " wK " : cout << " bK ";
				break;
			case QUEEN: (c == WHITE) ? cout << " wQ " : cout << " bQ ";
				break;
			case BISHOP:(c == WHITE) ? cout << " wB " : cout << " bB ";
				break;
			case HORSE:(c == WHITE) ? cout << " wH " : cout << " bH ";
				break;
			case TOWER: (c == WHITE) ? cout << " wT " : cout << " bT ";
				break;
			case PAWN: (c == WHITE) ? cout << " wP " : cout << " bP ";
				break;
			case EMPTY: cout <<  "    " ;
				break;
			default: cout << "XXX";
				break;
			}
		}
		cout << "|";
	}
	cout << "\n   ----------------------------------------" << "\n";
	cout << "     A    B    C    D    E    F    G    H \n";

}


bool Game::Move()
{
	using std::cout;
	using std::cin;
	using std::endl;

	char sx1, sx2;
	int x1, x2, y1, y2;
	bool stop = false;

	while (!stop)
	{
		(turn == WHITE) ? cout << "\nWhite's turn" << endl : cout << "\nBlack's turn" << endl;

		cout << "Enter coordinates of chesspiece you wanted move.\n";
		cout << "X (A-H): \n";
		cin >> sx1;

		while (!stop)
		{
			if (sx1 == 'A' || sx1 == 'a')
			{
				x1 = 0;
				break;
			}
			else if (sx1 == 'B' || sx1 == 'b')
			{
				x1 = 1;
				break;
			}
			else if (sx1 == 'C' || sx1 == 'c')
			{
				x1 = 2;
				break;
			}
			else if (sx1 == 'D' || sx1 == 'd')
			{
				x1 = 3;
				break;
			}
			else if (sx1 == 'E' || sx1 == 'e')
			{
				x1 = 4;
				break;
			}
			else if (sx1 == 'F' || sx1 == 'f')
			{
				x1 = 5;
				break;
			}
			else if (sx1 == 'G' || sx1 == 'g')
			{
				x1 = 6;
				break;
			}
			else if (sx1 == 'H' || sx1 == 'h')
			{
				x1 = 7;
				break;
			}
			else
			{
				cout << "Wrong input.\n";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Enter coordinates of chesspiece you wanted move.\n";
				cout << "X (A-H): \n";
				cin >> sx1;
			}
		}

		while (!stop)
		{
			cout << "Y (1-8): \n";
			cin >> y1;

			while (cin.fail())
			{
				cout << "Wrong input.\n";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Y (1-8): \n";
				cin >> y1;
			}

			if (y1 > 0 || y1 <= 8)
			{
				y1--;
				break;
			}
			else
			{
				cout << "Wrong input.\n";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Y (1-8): \n";
				cin >> y1;
				break;
			}
		}

		cout << "Enter coordinates, where you wanted chesspiece move.\n";
		cout << "X (A-H): \n";
		cin >> sx2;

		while (!stop)
		{
			if (sx2 == 'A' || sx2 == 'a')
			{
				x2 = 0;
				break;
			}
			else if (sx2 == 'B' || sx2 == 'b')
			{
				x2 = 1;
				break;
			}
			else if (sx2 == 'C' || sx2 == 'c')
			{
				x2 = 2;
				break;
			}
			else if (sx2 == 'D' || sx2 == 'd')
			{
				x2 = 3;
				break;
			}
			else if (sx2 == 'E' || sx2 == 'e')
			{
				x2 = 4;
				break;
			}
			else if (sx2 == 'F' || sx2 == 'f')
			{
				x2 = 5;
				break;
			}
			else if (sx2 == 'G' || sx2 == 'g')
			{
				x2 = 6;
				break;
			}
			else if (sx2 == 'H' || sx2 == 'h')
			{
				x2 = 7;
				break;
			}
			else
			{
				cout << "Wrong input.\n";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Enter coordinates, where you wanted chesspice move.\n";
				cout << "X (A-H): \n";
				cin >> sx2;
			}
		}

		while (!stop)
		{
			cout << "Y (1-8): \n";
			cin >> y2;

			while (cin.fail())
			{
				cout << "Wrong input.\n";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Y (1-8): \n";
				cin >> y2;
			}

			if (y2 > 0 || y2 <= 8)
			{
				y2--;
				break;
			}
			else
			{
				cout << "Wrong input.\n";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Y (1-8): \n";
				cin >> y2;
				break;
			}
		}

		if (getAuxiliary(x1, y1)->getColor() == turn)  // overuje farbu figurky - turnu
		{

			if (makeMove(x1, y1, x2, y2) == false)
			{
				cout << "Invalid move, try again." << endl;
			}
			else
				stop = true;
		}
		else
			cout << "That's not your piece. Try again." << endl;
	}

	if (turn == BLACK)
		turn = WHITE;
	else
		turn = BLACK;

	return true;
}

bool Game::moveKing(Auxiliary* thisKing, Auxiliary* thatSpace) {

	if ((abs(thatSpace->getX() - thisKing->getX()) == 1) || (abs(thatSpace->getY() - thisKing->getY()) == 1)) {
		if ((abs(thatSpace->getX() - thisKing->getX()) == 1) || (abs(thatSpace->getY() - thisKing->getY()) == 1))
		{
			thatSpace->setSpace(thisKing);
			thisKing->setEmpty();

			return true;
		}
		else return false;
	}
	else return false;
}

bool Game::moveQueen(Auxiliary* thisQueen, Auxiliary* thatSpace) {

	int queenX = thisQueen->getX();
	int queenY = thisQueen->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();

	int yIncrement;
	int xIncrement;

	bool invalid = false;
	if (queenX != thatX || queenY != thatY)
	{
		if (queenX == thatX)
		{
			yIncrement = (thatY - queenY) / (abs(thatY - queenY));
			for (int i = queenY + yIncrement; i != thatY; i += yIncrement)
			{
				if (Board[thatX][i].getColor() != NONE)
					return false;
			}
		}
		else
			if (queenY == thatY)
			{

				xIncrement = (thatX - queenX) / (abs(thatX - queenX));
				for (int i = queenX + xIncrement; i != thatX; i += xIncrement)
				{
					if (Board[i][thatY].getColor() != NONE)
						return false;
				}
			}
			else
				if (abs(queenX - thatX) == abs(queenY - thatY))
				{
					xIncrement = (thatX - queenX) / (abs(thatX - queenX));
					yIncrement = (thatY - queenY) / (abs(thatY - queenY));

					for (int i = 1; i < abs(queenX - thatX); i++)
					{
						if (Board[queenX + xIncrement * i][queenY + yIncrement * i].getColor() != NONE)
							return false;

					}
				}
				else
					return false;
	}


	if (invalid == false)
	{
		thatSpace->setSpace(thisQueen);
		thisQueen->setEmpty();
		return true;
	}
	else
	{
		return false;
	}
}

bool Game::moveBishop(Auxiliary* thisBishop, Auxiliary* thatSpace) {

	int bishopX = thisBishop->getX();
	int bishopY = thisBishop->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();
	bool invalid = false;
//	Auxiliary* s;
	if (abs(bishopX - thatX) == abs(bishopY - thatY))
	{
		int xIncrement = (thatX - bishopX) / (abs(thatX - bishopX));
		int yIncrement = (thatY - bishopY) / (abs(thatY - bishopY));

		for (int i = 1; i < abs(bishopX - thatX); i++)
		{
			if (Board[bishopX + xIncrement * i][bishopY + yIncrement * i].getColor() != NONE)
				return false;
		}
	}
	else
		return false;

	if (invalid == false)
	{
		thatSpace->setSpace(thisBishop);
		thisBishop->setEmpty();
		return true;
	}
	else
	{
		return false;
	}
}

bool Game::moveHorse(Auxiliary* thisHorse, Auxiliary* thatSpace)
{

	int horseX = thisHorse->getX();
	int horseY = thisHorse->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();

	if ((abs(horseX - thatX) == 2 && abs(horseY - thatY) == 1) || (abs(horseX - thatX) == 1 && abs(horseY - thatY) == 2))
	{
		thatSpace->setSpace(thisHorse);
		thisHorse->setEmpty();
		return true;
	}
	else
	{
		return false;
	}
}

bool Game::moveTower(Auxiliary* thisTower, Auxiliary* thatSpace)
{
	int towerX = thisTower->getX();
	int towerY = thisTower->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();
	bool invalid = false;
	if (towerX != thatX || towerY != thatY)
	{
		if (towerX == thatX)
		{
			int yIncrement = (thatY - towerY) / (abs(thatY - towerY));
			for (int i = towerY + yIncrement; i != thatY; i += yIncrement)
			{

				if (Board[thatX][i].getColor() != NONE)
					return false;
			}
		}
		else
			if (towerY == thatY)
			{

				int xIncrement = (thatX - towerX) / (abs(thatX - towerX));
				for (int i = towerX + xIncrement; i != thatX; i += xIncrement)
				{
					if (Board[i][thatY].getColor() != NONE)
						return false;
				}
			}
			else
				return false;
	}
	if (invalid == false)
	{
		thatSpace->setSpace(thisTower);
		thisTower->setEmpty();
		return true;
	}
	else
	{
		return false;
	}
}

bool Game::movePawn(Auxiliary* thisPawn, Auxiliary* thatSpace) {

	bool invalid = false;

	int pawnX = thisPawn->getX();
	int pawnY = thisPawn->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();


	if (thisPawn->getColor() == WHITE)
	{
		if (pawnY == 1 && pawnX == thatX && thatY == pawnY + 2 && thatSpace->getColor() == NONE)
		{
			thatSpace->setSpace(thisPawn);
			thisPawn->setEmpty();
			return true;
		}
		else if (pawnX == thatX && thatY == pawnY + 1 && thatSpace->getColor() == NONE)
		{
			thatSpace->setSpace(thisPawn);
			thisPawn->setEmpty();
			return true;
		}
		else if ((pawnX + 1 == thatX || pawnX - 1 == thatX) && pawnY + 1 == thatY && thatSpace->getColor() == BLACK)
			{
				thatSpace->setSpace(thisPawn);
				thisPawn->setEmpty();
				return true;
			}
			else
				return false;
	}
	else
		if (thisPawn->getColor() == BLACK)
		{
			if (pawnY == 6 && pawnX == thatX && thatY == pawnY - 2 && thatSpace->getColor() == NONE)
			{
				thatSpace->setSpace(thisPawn);
				thisPawn->setEmpty();
				return true;
			}
			else if (pawnX == thatX && thatY == pawnY - 1 && thatSpace->getColor() == NONE)
			{
				thatSpace->setSpace(thisPawn);
				thisPawn->setEmpty();
				return true;
			}
			else
				if ((pawnX + 1 == thatX || pawnX - 1 == thatX) && pawnY - 1 == thatY && thatSpace->getColor() == WHITE)
				{
					thatSpace->setSpace(thisPawn);
					thisPawn->setEmpty();
					return true;
				}
				else
					return false;
		}
		else
			return false;
}


bool Game::makeMove(int x1, int y1, int x2, int y2) {
	/*
	// prva podmienka
	if (x1 < 0 || x1 > 7 || y1 < 0 || y1 > 7 || x2 < 0 || x2 > 7 || y2 < 0 || y2 > 8)
	{
		std::cout << "One of your inputs was our of bounds" << std::endl;
		return false;
	}
	*/
	Auxiliary* src = getAuxiliary(x1, y1);
	Auxiliary* dest = getAuxiliary(x2, y2);

	// druha podmienka
	if (src->getColor() == dest->getColor() && dest->getColor() != NONE)
	{
		std::cout << "Invalid move: cannot land on your own piece.\n" << std::endl;
		return false;
	}


	switch (src->getPiece())
	{
	case KING: return moveKing(src, dest);
		break;
	case QUEEN: return moveQueen(src, dest);
		break;
	case BISHOP: return moveBishop(src, dest);
		break;
	case HORSE: return moveHorse(src, dest);
		break;
	case TOWER: return moveTower(src, dest);
		break;
	case PAWN: return movePawn(src, dest);
		break;
	case EMPTY: std::cout << "You do not have a piece there.\n" << std::endl;  
		return false;
		break;
	default: std::cerr << "Something went wrong in the switch statement in makeMove()" << std::endl;
		break;
	}
	return false;
}
