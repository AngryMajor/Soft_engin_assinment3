#include "crossfireOperations.h"

void findSlots(int reqDist, int currDist,struct slot * currSlot,struct slot * foundSlots,int * count, bool explored[7][7])
{
	if(currDist == reqDist)
	{
		if(explored[currSlot->row][currSlot->column] == false){
			*(foundSlots + *count) = *currSlot;
			(*count)++;
			explored[currSlot->row][currSlot->column] = true;
		}
	}
	else
	{	
	if(currSlot->up	!=	NULL)	
		findSlots(reqDist,	currDist	+1,		currSlot->up,	foundSlots,	count,	explored);	
	if(currSlot->right	!=	NULL)	
		findSlots(reqDist,	currDist	+1,		currSlot->right,	foundSlots,	count,	explored);		
	if(currSlot->left	!=	NULL)	
	 	findSlots(reqDist,	currDist	+1,		currSlot->left,	foundSlots,	count,	explored);	
	if(currSlot->down	!=	NULL)	
	 	findSlots(reqDist,	currDist	+1,		currSlot->down,	foundSlots,	count,	explored);	
	}	
}
void NearAttack(struct player *AttackerPlayer, struct player *AttackedPlayer)
{
	struct	slot*	currSlot	=	NULL;	
	struct	slot	*foundSlots;	
	bool	explored[7][7] = {false};	
	int	count	= 0;	
	int reqDist	= 4;
	int row = AttackerPlayer->location->row;
	int column = AttackerPlayer->location->column;
	
	
		// /*If the the required slot is closer to the down-right
	 // * corner of the board the search starts from downRight,
	 // * which points to slot at position (boardSize-1, boarSize -1)*/
	if(row >= boardSize/2)
	{
		if(column >= boardSize/2)
			a = reachDesiredElement(row,column,downRight);
		else
		// /*If the the required slot is closer to the down-left
		// * corner of the board the search starts from downLeft,
		// * which points to slot at position (boardSize-1, 0)*/
			a = reachDesiredElement(row,column,downLeft);
	 } 
	 else {
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
	foundSlots	=	malloc(20	*	sizeof(struct	slot	));	
	if(currSlot!=	NULL){	
	findSlots(reqDist,	0,	currSlot,	foundSlots,	&count,	explored);	
	for(int i=0;	i<count;	i++){	
	 	printf("(%d,	%d)->	",foundSlots[i].row,	foundSlots[i].column);	
	 	}
	if(AttackedPlayer->strength <=70)
	{
		AttackedPlayer->life_points = AttackedPlayer->life_points - (0.5 * AttackedPlayer->strength);
		printf("1. Attacked Player Life points = %d", AttackedPlayer->life_points);
	}
	else if(AttackedPlayer->strength > 70)
	{
		AttackerPlayer->life_points = AttackerPlayer->life_points - (0.3 * AttackedPlayer->strength);
		printf("2. Attcker Player Life Points = %d", AttackerPlayer->life_points);
	}
}



















void choosePlayer_MagAtt(int num_ofplayers,struct player CurrPlayer, struct player player[])
{
	int i,decision;
	printf("Players available to attack:\n");
	for(i = 0; i < num_ofplayers ; i++)
	{
		if(!player[i].dead)
			printf("%d, %s\n", i, player->name);
	}
	printf("Which player would you like to attack?:\n");
	scanf("%d", &decision);
	if(decision > i  || decision < 0)
	{
		printf("Option is not valid.\n");
		return choosePlayer_MagAtt(num_ofplayers,CurrPlayer ,player);
	}
	if(player[decision].dead)
	{
		printf("This player is dead.\n");
		return choosePlayer_MagAtt(num_ofplayers,CurrPlayer,player);
	}
	MagicAttack(CurrPlayer, &player[decision]);
}

void MagicAttack(struct player AttackerPlayer, struct player *AttackedPlayer)
{
	if(AttackerPlayer.smartness + AttackerPlayer.magic_skills > 150)
	{
		AttackedPlayer->life_points = AttackedPlayer->life_points - ((0.5 * AttackerPlayer.magic_skills) + (0.2 * AttackerPlayer.smartness));
	}
}

void DistantAttack(struct player *AttackerPlayer, struct player *AttackedPlayer)
{
	if(AttackedPlayer->dexterity >= AttackerPlayer->dexterity)
	{
		AttackedPlayer->life_points = AttackedPlayer->life_points;
	}
	else if(AttackerPlayer->dexterity > AttackedPlayer->dexterity)
	{
		AttackedPlayer->life_points = AttackedPlayer->life_points - (0.3 * AttackerPlayer->strength);
	}
}
