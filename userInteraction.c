/*
 * userInteraction.c

 *
 *  Created on: 29 Mar 2017
 *      Author: liliana
 */

#include <stdio.h>
#include "crossfireOperations.h"

//THis function takes as input the size of the board and the pointers
// to the integers representing the row and the column of the slot that
// the user want to retrieve
struct slot *getDesiredElement(int * row, int * col){
	printf("Please enter the column and the Row of the desired slot \n");
	printf("Note that size of the board is %d\n", boardSize);

		//it will cycle asking the user to insert the row
		//until the value of the desired row is >= 0 or < of the
		// size of the board
		do {
			printf("Row: ");
			scanf("%d", &row);
			printf("%d\n", *row);
			if(row < 0 && *row >= boardSize)
				printf("Error: Incorrect row dimension\n");
		} while(*row < 0 && *row >= boardSize);

		//it will cycle asking the user to insert the column
		//until the value of the desired row is >= 0 or < of the
		// size of the board
		do {
			printf("Column: ");
			scanf("%d", &col);
			printf("%d\n", *col);
			if(*col < 0 && *col >= boardSize)
				printf("Error: Incorrect column dimension\n");
		} while(*col < 0 && *col >= boardSize);
}

/*
funciton that gets the players action off the user
takes a player as input
returns an int of what they want to do
0=quit 1=move 2=near attack 3=far attack 4=magic attack
*/
int getPlayerAction(struct player Player){
	
	int option;//stor input
	//check the curent player can do magic
	int canMagic = 0;
	if(Player.magic_skills + Player.smartness > 150) canMagic = 1;
	
	//get action from user
	printf("What would you like to do?\n0: quit\n1: move\n2: attack");
	scanf("%d",&option);
	
	//check option is valid, make the user go again if its not
	if(option<0 ||option >2){
		printf("invalid input");
		return getPlayerAction(Player);
	}
	
	if(option == 2){//if player wants to attack
		
		printf("please input what kind of attack youd like to do?\n0:near\n1:far\n");
		if(canMagic) printf("2:magic\n");
		int option2;
		scanf("%d",&option2);
		
		//check option is valid
		if(option2<0 ||option2 >(1+canMagic)){
			printf("invalid input");
			return getPlayerAction(Player);
		}
		
		option += option2;
	}//end of attack option
	
	return option; 
	
}//end of get player action 
