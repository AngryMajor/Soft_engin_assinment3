#include "Functions.h"
#include "crossfireOperations.h"



int main(){

	int row, column, boardSize;

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

	/*	Asks the user the row and the column of the slot
		s/he wants to retrieve from the board.
		Note that the user needs to know the size of the board to input
		the correct row and column of the slot s/he wants to retrieve */
	getDesiredElement(boardSize, &row,&column);

	//Finds the slot


	/*If the the required slot is closer to the down-right
	 * corner of the board the search starts from downRight,
	 * which points to slot at position (boardSize-1, boarSize -1)*/
	if(row >= boardSize/2){
		if(column >= boardSize/2)
			reachDesiredElement(row,column,downRight);
		else
		/*If the the required slot is closer to the down-left
		* corner of the board the search starts from downLeft,
		* which points to slot at position (boardSize-1, 0)*/
			reachDesiredElement(row,column,downLeft);
	} else {
		/*If the the required slot is closer to the up-right
		* corner of the board the search starts from upRight,
		* which points to slot at position (0, boarSize -1)*/
		if(column >= boardSize/2)
			reachDesiredElement(row,column, upRight);
		/*If the the required slot is closer to the up-left
		* corner of the board the search starts from upLeft,
		* which points to slot at position (0, 0)*/
		else reachDesiredElement(row,column,upLeft);
	}

	int choice;  //Number to be entered by user
	printf("Please input how many players are playing the game: ");  //Prompt user to enter a number
	scanf("%d", &choice);  //Reads an integer used to represent the number of players playing the game
	struct player player[choice];  
	
	for(int i = 0; i < choice; i++)  //Loop amount of times user inputed for choice
	{
		puts("There are four player options to choose from.");
		puts("Enter the number corresponding to the player option.");
		printf("1. Elf.\n2. Human.\n3. Ogre.\n4. Wizard\n");
		
		do{
			printf("Please enter the number corresponding to the type for this player: ");
			scanf("%d", &player[i].type);
			switch(player[i].type)
			{
				case 1:
				elf(&player[i]); //Function call
				Joined_Players++;
				break;
				case 2:
				human(&player[i]);  //Function call
				Joined_Players++;
				break;
				case 3:
				ogre(&player[i]);  //Function call
				Joined_Players++;
				break;
				case 4:
				wizard(&player[i]);  //Function call
				Joined_Players++;
				break;
				default:
				printf("That's not a valid option.\n");
				}
		  } while(player[i].type >4 || player[i].type <= 0); //End while
	} 
	if(Joined_Players < 2)
	{
		printf("\nSorry, there is not enough players to play the game.\n");
		return main();
	}
return 0;
}
