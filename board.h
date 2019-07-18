#ifndef __BOARD_H__
#define __BOARD_H__
#include <iostream>
#include <cstdlib>
using namespace std;

class Board{

public:
    //CONSTURCTOR
    Board(){

	boardArray = {
		{0,1,0,1,0,1,0,1},
		{1,0,1,0,1,0,1,0},
		{0,1,0,1,0,1,0,1},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{2,0,2,0,2,0,2,0},
		{0,2,0,2,0,2,0,2},
		{2,0,2,0,2,0,2,0}
		};
    }

    void removePiece(int x, int y){board[x][y] = 0;}
    bool isValid(int x, int y){return (x+y)%2 != 0;}
    bool isEmpty(int x, int y){return board[x][y] == 0;}
    bool is1(int x, int y){return board[x][y] == 1;}
    bool is2(int x, int y){return board[x][y] == 2;}
    bool isLeftUp1(int x, int y){return board[x-1][y-1] == 1;}
    bool isRightUp1(int x, int y){return board[x-1][y+1] == 1;}
    bool isLeftDown2(int x, int y){return board[x+1][y-1] == 2;}
    bool isLeftUp2(int x, int y){return board[x+1][y+1] == 2;}

    //INITIALIZE THE GAME
    void initializeBoard();
    //PRINT THE BOARD
    void printBoard();
    //DETERMINE IF THE GAME ENDS
    bool winningState();

    //MOVE PIECES
    void moveRightDown(int x, int y);
    void moveLeftDown(int x, int y);
    void moveRightUp(int x, int y);
    void moveLeftUp(int x, int y);
    void jumpRightDown(int x, int y);
    void jumpLeftDown(int x, int y);
    void jumpRightUp(int x, int y);
    void jumpLeftUp(int x, int y);




private:
	static int boardArray[8][8];

};

#endif
