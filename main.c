#include "crossfireOperations.h"
#define numberofplayers 6

int main()
{
	//creat the board 
	createBoard(); 
	
	//creat the players
	int choice;//Number to be entered by user
	printf("Please input how many players are playing the game: ");  //Prompt user to enter a number
	scanf("%d", &choice);  //Reads an integer used to represent the number of players playing the game
	
	//check there are a valid number of players
	if(choice<2){
		printf("you must have at least 2 players\n\n");
		return main();
	}	
	if(choice>6){
		printf("you may only have up to 6 players\n\n");
		return main();
	}
	
	//creat player data
	struct player players[choice];  
	creatPlayers(players,choice);
	
	
	
	PlacePlayer(players[0]);
	
	//round loop
	int loop = 1;
	while(loop){
		for(int i=0;i<choice;i++)
		{ //Start of player turn loop
			if(!players[i].dead){
				printf("\nit is player %d's turn\n\n",i);
				int action = getPlayerAction(players[0]);
				switch (action){
					case 0: //Quit
						players[i].dead = 1;
						break;
					case 1: //Move
						break;
					case 2: //Near Attack
						
						break;
					case 3: //Distant Attack
						
						break;
					case 4: //Magic Attack
						choosePlayer_MagAtt(choice,players[i], players);
						break;
					
				} //End of switch action
			}
		} //End of loop for player's turn
		//Check if the game terminates
		loop = AllPlayersNotDead(players, choice);
	}
return 0;
}
