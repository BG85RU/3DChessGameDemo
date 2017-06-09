// 3DChessGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>

//The pieces are described as constant integer values to allow the changing of their original values, if required
const int pawn = 100;
const int bishop = 305;
const int knight = 300;
const int rook = 500;
const int queen = 900;
const int king = 2000;

//Below is the defining and creation of the actual Chess Board, a standard 8x8 board on which the game will be played
// Board setup [Vertical: 1-8][Horizontal: A-H]
int board[8][8];

//This will contain the starting positions for all chess games, using a negative variant of the piece to differentiate
//the black and white pieces, as well as actually setup the starting position
const int startup[8][8] = { rook, knight, bishop, queen, king, bishop, knight, rook, pawn, pawn,pawn,pawn,pawn,pawn,pawn, pawn, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn, -rook, -knight, -bishop, -queen, -king, -bishop, -knight, -rook };

void setup(void) {
	int i, j;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			board[i][j] = startup[i][j];
		}
	}

}


//The below piece of code will copy the starting positions to the actual board, as well as print to the screen a text version of the game.
//Each piece will be represented by an initial, the black pieces being in a lowercase, which are as follows:
void printb(void) {
	using namespace std;
	int a, b;
	string piece;
	for (a = 7; a > -1; a--) { 
		cout << endl;
		for (b = 0; b < 8; b++) {
			switch (board[a][b]) {
			case 0:
				piece = "-";
				break;
			case pawn:
				piece = "P";
				break;
			case knight:
				piece = "N";
				break;
			case bishop:
				piece = "B";
				break;
			case rook:
				piece = "R";
				break;
			case queen:
				piece = "Q";
				break;
			case king:
				piece = "K";
				break;
			case -pawn:
				piece = "p";
				break;
			case -knight:
				piece = "n";
				break;
			case -bishop:
				piece = "b";
				break;
			case -rook:
				piece = "r";
				break;
			case -queen:
				piece = "q";
				break;
			case -king:
				piece = "k";
				break;
			}
			cout << " " << piece << " ";
		}
	}

	cout << endl << endl;
}

int main(void) {

	using namespace std;

	//A brief description of the program and how to play the game.
	cout << "Welcome to 3D Chess, an interactive text based chess game on your PC." << endl << endl;
	cout << "Moving your pieces may get a little confusing, so here is a brief example." << endl << "To move a pawn from A2 to A4, enter the movement as follows: a2a4 in lowercase" << endl << endl;
	cout << "Console Commands: exit or abort -> Quit, print -> Display the current board," << endl << "new -> New Game" << endl << endl;
	cout << "Please enter your choice below:" << endl << endl;

	//String containing the user's entered information, as well as setting up the initial board positions
	string passd; 
	setup(); 

	//This while loop will continue to loop until the 'break;' statement occurs
	while (1) {

		//Ask the user what they wish to do and continue depending on their choice
		getline(cin, passd);  
		if (passd.substr(0, 4) == "exit" || passd.substr(0, 5) == "abort" || passd.substr(0, 4) == "quit") {
			break;
		}
		if (passd.substr(0, 5) == "print") {
			printb();
		}
		if (passd.substr(0, 3) == "new") {
			setup();
		}
		//This validation will check that both entered squares are valid and on the board, execute the move and then display the board
		if (passd.substr(0, 1) >= "a" && passd.substr(0, 1) <= "h" && passd.substr(1, 1) >= "1" && passd.substr(1, 1) <= "8" && passd.substr(2, 1) >= "a" && passd.substr(2, 1) <= "h" && passd.substr(3, 1) >= "1" && passd.substr(3, 1) <= "8") { 
																																																													
																																																													

			int a, b, c, d;


			a = passd[0] - 'a';
			b = passd[1] - '1';
			c = passd[2] - 'a';
			d = passd[3] - '1';

			//This line of code will execute the player's move if the piece is still on the board, and then print out the board
			board[d][c] = board[b][a];
			board[b][a] = 0;

			printb();
		}
	}
}


