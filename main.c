#include "crossfireOperations.h"
#define numberofplayers 6


int main()
{

	int row, columm;

	//Creates the board
	createBoard();
	
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
