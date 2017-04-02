#include "crossfireOperations.h"



int main(){

	int row, column, boardSize;
	
	//creat players

	//pointer to slot (0,0)
	struct slot *upLeft;

	//pointer to slot (0,boardSize -1)
	struct slot *upRight;

	//pointer to slot (boardSize - 1, 0)
	struct slot *downLeft;

	//pointer to slot (boardSize - 1, boardSize -1)
	struct slot *downRight;

	//Obtains the board size from the user input
	boardSize = getBoardSize();

	//Creates the board
	createBoard(boardSize,&upLeft, &upRight, &downLeft, &downRight);

	//fill board
	//turn loop
		//ask player what they want to do
			//attack near
			//attack far
			//attack magic
			//move
			//quite
		//check if game terminates
	int choice;  //Number to be entered by user
	option(&choice);


return 0;
}
