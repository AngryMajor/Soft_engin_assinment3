/*
 * crossfireOperations.h
 *
 *  Created on: 29 Mar 2017
 *      Author: liliana
 */

#ifndef CROSSFIREOPERATIONS_H_
#define CROSSFIREOPERATIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NumOfSlotTypes 3
#define boardSize 7


struct player
{
	int dead;
	int type;
	char name[32];
	int life_points;
	int smartness;
	int strength;
	int magic_skills;
	int luck;
	int dexterity;
	struct slot *location;
};

void IsDead(struct player *player);

void PlacePlayer(struct player *player);
void creatPlayers(struct player player[], int choice);  //Function prototype
void elf(struct player *Current_Player);  //Function prototype
void human(struct player *Current_Player);   //Function prototype
void ogre(struct player *Current_Player);   //Function prototype
void wizard(struct player *Current_Player); //Function prototype

static int Joined_Players = 0;

void MagicAttack(struct player AttackerPlayer, struct player *AttackedPlayer);
int choosePlayer_MagAtt(int num_ofplayers, struct player CurrPlayer, struct player player[]);

void NearAttack(struct player *AttackerPlayer, struct player *AttackedPlayer);
int choosePlayer_NearAtt(struct player *CurrPlayer,struct player players[],int numofplayers);

void DistantAttack(struct player *AttackerPlayer, struct player *AttackedPlayer);
void checkRange(struct slot *currSlot,int range,struct slot *InRange[], int count);
int choosePlayer_DistantAtt(struct player player,struct player players[]);

int AllPlayersNotDead(struct player players[],int choice);

int move(struct player *player);
/*
 * Definition of boolean types
 * This avoids using <stdbool.h>
 */
typedef int bool;
enum { false, true };

/*
 * The slot template
 */
struct slot{
	//row number
	int row;
	//column number
	int column;

	// adjacent left slot
	struct slot *left;
	// adjacent right slot
	struct slot *right;
	// adjacent up slot
	struct slot *up;
	// adjacent down slot
	struct slot *down;
	
	int thisSlotType;//holds the slot type of this slot
	
}slot;


/*
global consts
*/
const struct slot *upRight;
const struct slot *upLeft;
const struct slot *downRight;
const struct slot *downLeft;

/*
 * FUNCTIONS PROTOTYPES
 */

 /*
Function that gets the players action off the user
takes a player as input
returns an int of what they want to do
0=quit 1=move 2=near attack 3=far attack 4=magic attack
*/
int getPlayerAction(struct player Player);

/*
 * Functions getBoardSize and getDesiredElement
 * manage the interaction with the users
*/

//Asks the user to insert the row and the column of the element
//she wants to find given a board of size equal to maxsize
struct slot *getDesiredElement( int * row, int * col);

/*
 * Functions createBoard and reachDesiredElement
 * manage the creation and manipulation of the board
 */
/*
 * This function creates the board
 * Parameters:
 * 	boardSize: the size of the board
 * 	upLeft: pointer of pointer to slot at position (0, 0)
 * 	upRight: pointer of pointer to slot at position (0, size -1)
 * 	downLeft: pointer of pointer to slot at position (size -1, 0)
 * 	upLeft: pointer of pointer to slot at position (size - 1, size -1)
 */
void createBoard();

/*
 * This function traverses the board to find a slot at a predefined
 * position (row, column)
 * Parameters:
 * 	row: the row in which the desired slot is located
 * 	column: the column in which the desired slot is located
 * 	initialSlot: the slot from which the slot search should start
 */
struct slot *reachDesiredElement(int row, int column,const struct slot * initialSlot);

/*
function for printint map slot types
takes a pointer to the map slot to print
returns nothing but prints to screen
*/

void PrintMapSlotType(struct slot *toPrint);

void findSlots(int reqDist, int currDist,
struct slot * currSlot,
struct slot * foundSlots,
int * count, bool explored[7][7]);

#endif /* CROSSFIREOPERATIONS_H_ */
