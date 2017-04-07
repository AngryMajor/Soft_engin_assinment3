#include "crossfireOperations.h"
#define numberofplayers 6


int main()
{

	int row, columm;
	
	//creat players

	//pointer to slot (0,0)
	struct slot *upLeft;

	//pointer to slot (0,boardSize -1)
	struct slot *upRight;

	//pointer to slot (boardSize - 1, 0)
	struct slot *downLeft;

	//pointer to slot (boardSize - 1, boardSize -1)
	struct slot *downRight;

	//Creates the board
	createBoard(&upLeft, &upRight, &downLeft, &downRight);
	
	struct player players[numberofplayers];
	
	
	PlacePlayer(players[0]);
	
	//round loop
		for(int i=0;i<numberofplayers;i++){//start of player turn loop
			int action = getPlayerAction(players[0]);
			switch (action){
				case 0://quit
					break;
				case 1://move
					break;
				case 2://near attack
					break;
				case 3://far attack
					break;
				case 4://magic attack
					break;
				default:
			}//end of action switch
		}//end of player turn loop
		//check if game terminates
	
	int choice;  //Number to be entered by user
	


return 0;
}
