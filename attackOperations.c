#include "crossfireOperations.h"

int choosePlayer_NearAtt(struct player *CurrPlayer,struct player players[],int numofplayers){
		
	struct player *targets[6];  //List of the player's targets
	
	//Put all the slot pointers that the player can attack in an array so that they can be checked
	struct slot *locations[5];
	locations[0] = CurrPlayer->location;
	locations[1] = CurrPlayer->location->up;
	locations[2] = CurrPlayer->location->down;
	locations[3] = CurrPlayer->location->right;
	locations[4] = CurrPlayer->location->left;
	
	int count = 0; //Number of other players found in attackable slots
	
	//Compare the attackable slot pointers to the list of players location pointers to see who is in a slot that the player can attack
	for(int i=0;i<numofplayers;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(players[i].location == locations[j]) targets[count++] = &players[i];
		}
	}
	
	//Get the players choice from them
	int input;
	printf("possible targets are:\n");
	for(int i=0;i<count;i++) 
		printf("%d %s\n",i,(*targets[i]).name);
	printf("Input the corresponding number: ");
	scanf("%d",&input);
	
	//Check their choice is valid
	if(input<0 || input>count){
		printf("Invalid input");
		return 1;
	}
	
	NearAttack(CurrPlayer,targets[input]);//attack
	
	return 0;
	
}//endo of choose player near attack


int choosePlayer_DistantAtt(struct player player,struct player players[]){
	
	struct slot *InRange[37];
	struct player *targets[6];
	checkRange(player.location,4,InRange,0);
	
	int count = 0;
	
	for(int i=0;i<6;i++){
		for(int j=0;j<37;j++){
			if(players[i].location == InRange[j]){
				targets[count++] = &players[i];
				break;
			}
		}
	}	
	
	count--;
	
	int input;
	printf("who would you like to attack\n");
	for(int i=0;i<count;i++) printf("%d %s\n",i,players[i].name);
	scanf("%d",&input);
	
	if(input<0 ||input>count){
		printf("invalid input");
		return 1;
	}
	
	DistantAttack(&player,&players[input]);
	
	return 0;
	
}//end of choose player distant attack

/*
finds all the slots that are within a certen range of a proticular slot
takes in a slot to start from and the desired range
it returns with pass by refrence an array of the slots in range
the last argument should always be set to 0 when inishalising this funciont
*/

void checkRange(struct slot *currSlot,int range,struct slot *InRange[], int count){
	
	if(!range){//if range is 0
		
		//check if slot is already in array, if it is return
		for(int i;i<count;i++){
			if(currSlot == InRange[i]) return;
		}
		//log this slot
		InRange[count++] = currSlot;
		
		return;
	}
	if(range = 1){//when range is almost to the end required to get all slots within range
		
		//check if slot is already in array, if it is return
		for(int i;i<count;i++){
			if(currSlot == InRange[i]) return;
		}
		//log this slot
		InRange[count++] = currSlot;
		
		if(currSlot->up	!=	NULL)	
	 	checkRange(currSlot->up,range-1,InRange,count);
	if(currSlot->right	!=	NULL)	
	 	checkRange(currSlot->right,range-1,InRange,count);	
	if(currSlot->left	!=	NULL)	
	 	checkRange(currSlot->left,range-1,InRange,count);
	if(currSlot->down !=	NULL)	
		checkRange(currSlot->down,range-1,InRange,count);
		
	}
	
	//if range is not 1 or 0
	if(currSlot->up	!=	NULL)	
	 	checkRange(currSlot->up,range-1,InRange,count);
	if(currSlot->right	!=	NULL)	
	 	checkRange(currSlot->right,range-1,InRange,count);	
	if(currSlot->left	!=	NULL)	
	 	checkRange(currSlot->left,range-1,InRange,count);
	if(currSlot->down !=	NULL)	
		checkRange(currSlot->down,range-1,InRange,count);
	
}//end of check range

int choosePlayer_MagAtt(int num_ofplayers,struct player CurrPlayer, struct player player[])
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
		return 1;
	}
	if(player[decision].dead)
	{
		printf("This player is dead.\n");
		return 1;
	}
	MagicAttack(CurrPlayer, &player[decision]);
	return 0;
}


void MagicAttack(struct player AttackerPlayer, struct player *AttackedPlayer)
{
	printf("Zap\n");
	if(AttackerPlayer.smartness + AttackerPlayer.magic_skills > 150)
	{
		AttackedPlayer->life_points = AttackedPlayer->life_points - ((0.5 * AttackerPlayer.magic_skills) + (0.2 * AttackerPlayer.smartness));
	}
}



void DistantAttack(struct player *AttackerPlayer, struct player *AttackedPlayer)
{
	printf("twang\n");
	if(AttackedPlayer->dexterity >= AttackerPlayer->dexterity)
	{
		AttackedPlayer->life_points = AttackedPlayer->life_points;
	}
	else if(AttackerPlayer->dexterity > AttackedPlayer->dexterity)
	{
		AttackedPlayer->life_points = AttackedPlayer->life_points - (0.3 * AttackerPlayer->strength);
	}
}

void NearAttack(struct player *AttackerPlayer, struct player *AttackedPlayer)
{
	printf("slash\n");
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
