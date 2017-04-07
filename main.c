#include "crossfireOperations.h"
#define numberofplayers 6

int main()
{

	int row, columm;
	createBoard(); //Creates the board
	
	struct player players[numberofplayers];
	
	
	PlacePlayer(players[0]);
	
	//round loop
		for(int i=0;i<numberofplayers;i++)
		{ //Start of player turn loop
			int action = getPlayerAction(players[0]);
			switch (action){
				case 0: //Quit
					break;
				case 1: //Move
					break;
				case 2: //Near Attack
					void NearAttack(struct player *AttackerPlayer, struct player *AttackedPlayer);
					break;
				case 3: //Distant Attack
					void DistantAttack(struct player *AttackerPlayer, struct player *AttackedPlayer);
					break;
				case 4: //Magic Attack
					void MagicAttack(struct player *AttackerPlayer, struct player *AttackedPlayer);
					break;
				default:
			} //End of switch action
		} //End of loop for player's turn
		//Check if the game terminates
	
	int choice;  //Number to be entered by user
	


return 0;
}
