#include "crossfireOperations.h"


/*
 * This function creates the board
 * Parameters:
 * 	size: the size of the board
 * 	upLeft: pointer of pointer to slot at position (0, 0)
 * 	upRight: pointer of pointer to slot at position (0, boardSize -1)
 * 	downLeft: pointer of pointer to slot at position (boardSsize -1, 0)
 * 	upLeft: pointer of pointer to slot at position (boardSize - 1, boardSize -1)
 */
void createBoard(){

	//The board is represented as a pointer of pointer to slots
	//This allocates in memory the space for the pointers to each row of the board
	struct slot ** board = malloc(boardSize * sizeof(struct slot *));


	for(int i =0; i< boardSize; i++){
		//This allocates in memory the space for the slots in each row of the board
		board[i] = malloc(boardSize * sizeof(struct slot));

		//For each slot it sets up the row and column number
		for(int j=0;j < boardSize; j++){
			board[i][j].row = i;
			board[i][j].column = j;
			board[i][j].thisSlotType = rand()%3;
		}
	}

	//It sets up the adjacent slots for the slots that are
	//not at the borders. These slots have 4 adjacent elements
	for(int i =1; i< boardSize-1; i++){
		for(int j=1;j < boardSize-1; j++){
			board[i][j].up = &board[i-1][j];
			board[i][j].right = &board[i][j+1];
			board[i][j].down = &board[i+1][j];
			board[i][j].left = &board[i][j-1];
		}
	}

	//It sets up the adjacent slots for the slots that are
	//in the first and the last row, except the slots at the edges.
	//
	for(int j = 1; j < boardSize -1; j++){
		//It sets up the adjacent slots for the slots that are in the first row.
		//These slots don't have an adjacent element on top of them
		// because they are on the first row of the board
		board[0][j].right = &board[0][j+1];
		board[0][j].left = &board[0][j-1];
		board[0][j].down = &board[1][j];
		board[0][j].up = NULL;

		//It sets up the adjacent slots for the slots that are in the last row.
		//These slots don't have an adjacent element on down them
		// because they are on the last row of the board
		board[boardSize - 1][j].right = &board[boardSize - 1][j+1];
		board[boardSize -1][j].left = &board[boardSize - 1][j-1];
		board[boardSize - 1][j].up = &board[boardSize - 2][j];
		board[boardSize - 1][j].down = NULL;
	}

	//It sets up the adjacent slots for the slots that are
	//in the first and the last column, except the slots at the edges.
	//
	for(int i = 1; i < boardSize -1; i++){
		//It sets up the adjacent slots for the slots that are in the first column.
		//These slots don't have an adjacent element on the left
		// because they are on the first column of the board
		board[i][0].right = &board[i][1];
		board[i][0].up = &board[i-1][0];
		board[i][0].down = &board[i+1][0];
		board[i][0].left = NULL;

		//It sets up the adjacent slots for the slots that are in the last column.
		//These slots don't have an adjacent element on the right
		// because they are on the last column of the board
		board[i][boardSize-1].left = &board[i][boardSize-2];
		board[i][boardSize -1].up = &board[i -1][boardSize-1];
		board[i][boardSize -1].down = &board[i+1][boardSize -1];
		board[i][boardSize -1].right = NULL;
	}


		//It sets up the adjacent slots for the slot at position (0,0).
		//This only has only 2 adjacent slots: right and down
		board[0][0].right = &board[0][1];
		board[0][0].down = &board[1][0];

		//It sets up the adjacent slots for the slot at position (0,boardSize -1).
		//This only has only 2 adjacent slots: left and down
		board[0][boardSize-1].left = &board[0][boardSize-2];
		board[0][boardSize -1].down = &board[1][boardSize -1];

		//It sets up the adjacent slots for the slot at position (boarSize -1 ,0).
		//This only has only 2 adjacent slots: up and right
		board[boardSize -1][0].right = &board[boardSize -1][1];
		board[boardSize -1][0].up = &board[boardSize -2][0];

		//It sets up the adjacent slots for the slot at position (boarSize -1 ,boardSize-1).
		//This only has only 2 adjacent slots: up and left
		board[boardSize - 1][boardSize-1].up = &board[boardSize-2][boardSize-1];
		board[boardSize - 1][boardSize -1].left = &board[boardSize -1][boardSize -2];







	//assigns a pointer to slot at position (0, 0)
	upLeft = &board[0][0];
	//assigns pointer of pointer to slot at position (0, boardSize -1)
	upRight = &board[0][boardSize -1];
	//assigns pointer of pointer to slot at position ( boardSize -1,)
	downLeft = &board[boardSize -1][0];
	//assigns pointer of pointer to slot at position (boardSize -1, boardSize -1)
	downRight = &board[boardSize -1][boardSize -1];
	}



/*
 * This function traverses the board to find a slot at a predefined
 * position (row, column)
 * Parameters:
 * 	row: the row in which the desired slot is located
 * 	column: the column in which the desired slot is located
 * 	initialSlot: the slot from which the slot search should start
 */

void PlacePlayer(struct player player)
{
	int column, row;
	column = (rand() % 7); 
	row = (rand() % 7);
	struct slot *a;
	
		// /*If the the required slot is closer to the down-right
	 // * corner of the board the search starts from downRight,
	 // * which points to slot at position (boardSize-1, boarSize -1)*/
	if(row >= boardSize/2){
		if(column >= boardSize/2)
			a = reachDesiredElement(row,column,downRight);
		else
		// /*If the the required slot is closer to the down-left
		// * corner of the board the search starts from downLeft,
		// * which points to slot at position (boardSize-1, 0)*/
			a = reachDesiredElement(row,column,downLeft);
	 } else {
		// /*If the the required slot is closer to the up-right
		// * corner of the board the search starts from upRight,
		// * which points to slot at position (0, boarSize -1)*/
		if(column >= boardSize/2)
			a = reachDesiredElement(row,column, upRight);
		// /*If the the required slot is closer to the up-left
		// * corner of the board the search starts from upLeft,
		// * which points to slot at position (0, 0)*/
		else a = reachDesiredElement(row,column,upLeft);
	 }
	player.location = a;
	if(a.playersHere)
	{
		a.playersHere = &player;
		return;
	}
	struct slot *Curr = a.playersHere;
	struct slot *prev;
	while(Curr)
	{
		prev = Curr;
		Curr = Curr.nextplayer;
	}
	prev.nextplayer = player;
}

struct slot *reachDesiredElement(int row, int column, const struct slot * initialSlot){

	bool found = false;
	//current slot
	struct slot currentSlotPtr = *initialSlot;
	struct slot *currentSlot = &currentSlotPtr;

	//while the slot is not found
	while(found == false){

		//if the row of the current slot is > of the row of the desired slot,
		//we move up
		if(currentSlot->row > row){
			//the current slot now points to the slot one row up
			currentSlot = currentSlot->up;

		}
		//if the row of the current slot is < of the row of the desired slot,
		//we move down
		if(currentSlot->row < row){
			//the current slot now points to the slot one row down
			currentSlot = currentSlot->down;

		}
		//if the column of the current slot is > of the column of the desired slot,
		//we move left
		if(currentSlot->column > column){
			//the current slot now points to the slot one column left
			currentSlot = currentSlot->left;
		}

		//if the column of the current slot is < of the column of the desired slot,
		//we move right
		if(currentSlot->column < column){
			//the current slot now points to the slot one column right
			currentSlot = currentSlot->right;

		}
		//if the current slot is at a column and a row equal to the desired column and row, respectively
		// we found the slot
		if(currentSlot->column == column && currentSlot->row == row){
			found = true;
		}

	}
	
	return currentSlot;
	
}
/*
function for printint map slot types
takes a pointer to the map slot to print
returns nothing but prints to screen
*/

void PrintMapSlotType(struct slot *toPrint){
	
	char *SlotNames[] = {"Flat Ground","Hill","City"};
	
	printf("%s",SlotNames[(*toPrint).thisSlotType]);
	
}  //End of printmapslot


