#include "crossfireOperations.h"

int main()
{

	createBoard(); //Creates the board
	
	
	int numberofplayers;
	printf("How many players would like to play?");
	scanf("%d",&numberofplayers);
	if(numberofplayers<2){
		printf("There must be at least 2 players");
		return main();
	}else if(numberofplayers>6){
		printf("There can not be more then 6 players");
		return main();
	}
	
	struct player players[numberofplayers];
	
	creatPlayers(players,numberofplayers);
	
	for(int i=0;i<numberofplayers;i++){
		PlacePlayer(&players[i]);
	}
	
	int turnFail;  //If turn fail = 1 the player can repeat their turn
	int loop = 1;
	while(loop){
		for(int i=0;i<numberofplayers;i++)
			{ //Start of player turn loop
			do{
				printf("\nPlayer %d, its your turn\n\n",i);
			
				int action = getPlayerAction(players[0]);
				switch (action){
					case 0: //Quit
						players[i].dead = 1;
						turnFail = 0;
						break;
					case 1: //Move
						turnFail = move(&players[i]);
						break;
					case 2:
						turnFail = 1;
						break;
					case 3: //Near Attack
						turnFail = choosePlayer_NearAtt(&players[i],players, numberofplayers);
						break;
					case 4: //Distant Attack
						turnFail = choosePlayer_DistantAtt(players[i],players);
						break;
					case 5: //Magic Attack
						turnFail = choosePlayer_MagAtt(numberofplayers,players[i],players);
						break;
					default:
						printf("That is not an option\n");
						turnFail = 1;
				
				} //End of switch action
			}while(turnFail);
		} //End of loop for player's turn
		loop = AllPlayersNotDead(players,numberofplayers);
	}//Check if the game terminates

return 0;
}
