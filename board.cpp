#include "board.h"
using namespace std;

void Board::printBoard(){
    	cout << "|----|----|----|----|----|----|----|----|" << endl;
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			cout << "| " << boardArray[i][j] << "  ";
		}
		cout << "|" << endl << "|----|----|----|----|----|----|----|----|" << endl;
	}
	    cout << endl;
    }

bool Board::winningState(){
	for(int i = 0; i < 8; i++){
	if(boardArray[0][i] == 2 || boardArray[7][i] == 1)
		return true;
	}
	return false;
}

void Board::moveRightDown(int x, int y){
	//invaild conditions
	if(isValid(x,y) == false){cout<< "Invalid Input!";}
	else if(isEmpty(x,y) == true){cout << "Invalid Input!";}
	else if(x == 7 || y == 7){cout<< "Invalid Move!";}
	else if(isEmpty(x+1, y+1) == false){cout<< "Invalid Move!";}
	//move the piece
	else{
		remove(x,y);
		boardArray[x+1][y+1] = 1;
	}
}

void moveLeftDown(int x, int y){
	//invaild conditions
	if(isValid(x,y) == false) {cout<< "Invalid Input!";}
	else if(isEmpty(x,y) == true){cout << "Invalid Input!";}
	else if(x == 7 || y == 0) {cout<< "Invalid Move!";}
	else if(boardArray[x+1][y-1] == 1) {cout<< "Invalid Move!";}
	//move the piece
	else{
		remove(x,y);
		boardArray[x+1][y-1] = 1;
	}
}

void moveRightUp(int x, int y){
	//invaild conditions
	if(isVaild(x,y) == false) {cout<< "Invalid Input!";}
	else if(isEmpty(x,y) == true){cout << "Invalid Input!";}
	else if(x == 0 || y == 7){cout<< "Invalid Move!";}
	else if(boardArray[x-1][y+1] == 2){cout<< "Invalid Move!";}
	//move the piece
	else{
		remove(x,y);
		boardArray[x-1][y+1] = 2;
	}
}

void moveLeftUp(int x, int y){
	//invaild conditions
	if(isValid(x,y) == false) {cout<< "Invalid Input!";}
	else if(isEmpty(x,y) == true){cout << "Invalid Input!";}
	else if(x == 0 || y == 0) {cout<< "Invalid Move!";}
	else if(boardArray[x-1][y-1] == 2) {cout<< "Invalid Move!";}
	//move the piece
	else{
		remove(x,y);
		boardArray[x-1][y-1] = 2;
	}
}

void jumpRightDown(int x, int y){
	//invaild conditions
	if(isValid(x,y) == false){cout<< "Invalid Input!";}
	else if(isEmpty(x,y) == true){cout << "Invalid Input!";}
	else if(x >= 6 || y >= 6){cout<< "Invalid Move!";}
	else if(boardArray[x+1][y+1] == 1){cout<< "Invalid Move!";}
	//move the piece and delete the opponents piece
	else{
		remove(x,y);
		int newX = x+2;
		int newY = y+2;
		boardArray[newX][newY] = 1;
		remove(x+1,y+1);
		//Check if the piece can jump again
		if(isLeftDown2(newX, newY) == true){
			jumLeftDown(newX, newY);
		}
		if(isRightDown2(newX, newY) == true){
			jumpRightDown(newX, newY);
		}
	}
}

void jumpLeftDown(int x, int y){
	//invaild conditions
	if(isValid(x,y) == false) {cout<< "Invalid Input!";}
	else if(isEmpty(x,y) == true){cout << "Invalid Input!";}
	else if(x >= 6 || y <= 1) {cout<< "Invalid Move!";}
	else if(boardArray[x+2][y-2] == 1) {cout<< "Invalid Move!";}
	//move the piece and delete the opponents piece
	else{
		remove(x,y);
		int newX = x+2;
		int newY = y-2;
		boardArray[newX][newY] = 1;
		remove(x+1,y-1);
		//Check if the piece can jump again
		if(isLeftDown2(newX, newY) == true){
			jumLeftDown(newX, newY);
		}
		if(isRightDown2(newX, newY) == true){
			jumpRightDown(newX, newY);
		}
	}
}

void jumpRightUp(int x, int y){
	//invaild conditions
	if(isValid(x,y) == false) {cout<< "Invalid Input!";}
	else if(isEmpty(x,y) == true){cout << "Invalid Input!";}
	else if(x <= 1 || y >= 6) {cout<< "Invalid Move!";}
	else if(boardArray[x-1][y+1] == 2) {cout<< "Invalid Move!";}
	//move the piece and delete the opponents piece
	else{
		remove(x,y);
		int newX = x-2;
		int newY = y+2;
		boardArray[newX][newY] = 2;
		remove(x-1,y+1);
		//Check if the piece can jump again
		if(isLeftUp1(newX, newY) == true){
			jumLeftUp(newX, newY);
		}
		if(isRightUp1(newX, newY) == true){
			jumpRightUp(newX, newY);
		}
	}
}

void jumpLeftUp(int x, int y){
	//invaild conditions
	if(isValid(x,y) == false) {cout<< "Invalid Input!";}
	else if(isEmpty(x,y) == true){cout << "Invalid Input!";}
	else if(x <= 1 || y<= 1) {cout<< "Invalid Move!";}
	else if(boardArray[x-1][y-1] == 2) {cout<< "Invalid Move!";}
	//move the piece and delete the opponents piece
	else{
		remove(x,y);
		int newX = x-2;
		int newY = y-2;
		boardArray[newX][newY] = 2;
		remove(x-1,y-1);
		//Check if the piece can jump again
		if(isLeftUp1(newX, newY) == true){
                	jumLeftUp(newX, newY);
		}
		if(isRightUp1(newX, newY) == true){
	  		jumpRightUp(newX, newY);
		}
	}
}