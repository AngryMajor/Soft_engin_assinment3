#include "crossfireOperations.h"

void creatPlayers(struct player player[], int choice)
{
	
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
		  }  while(player[i].type >4 || player[i].type <= 0); //End while
	}
	if(Joined_Players < 2)
	{
		printf("\nSorry, there is not enough players to play the game.\n");
	}
}

void elf(struct player *Current_Player)
{	
	printf("Please enter a name for this player: ");
	scanf("%s", Current_Player->name);  //Set name of player
	Current_Player->life_points = 100;  //Set life points to 100
	srand(time(NULL));  //Randomize random number generator using current time
	Current_Player->smartness = (rand() % 31) + 71;  //Pick a random number from 30 and 70
	Current_Player->strength = (rand() % 51);  //Pick a random number from 0 and 50
	Current_Player->magic_skills = (50 + rand() % 31);  //Pick a random number from 50 and 80
	Current_Player->luck = (rand() % 41) + 61;  //Pick a random number from 60 and 100
	Current_Player->dexterity = (rand() % 101);  //Pick a random number from 0 and 100
	Current_Player->dead = 0;  //This player is not dead
}

void human(struct player *Current_Player)
{
	int sum;  //Variable in which sum will be stored
	printf("Please enter a name for this player: ");
	scanf("%s", Current_Player->name);  //Set name of player
	Current_Player->life_points = 100;  //Set life points to 100
	srand(time(NULL));  //Randomize random number generator using current time
	Current_Player->magic_skills = (rand() % 101);  //Pick a random number from 0 and 100
	Current_Player->smartness = (rand() % 101);  //Pick a random number from 0 and 100
	Current_Player->strength = (rand() % 101); //Pick a random number from 0 and 100
	Current_Player->dexterity = (rand() % 101); //Pick a random number from 0 and 100
	Current_Player->luck = (rand() % 101);  //Pick a random number from 0 and 1-0
	sum = Current_Player->magic_skills + Current_Player->smartness + Current_Player->strength + Current_Player->dexterity + Current_Player->luck;  //Assign total to sum
	sum <=300;
	Current_Player->dead = 0;  //This player is not dead
}

void ogre(struct player *Current_Player)
{
	printf("Please enter a name for this player: ");
	scanf("%s", Current_Player->name);  //Set name of player
	Current_Player->life_points = 100;  //Set life points to 100
	srand(time(NULL));  //Randomize random number generator using current time
	Current_Player->magic_skills = 0;  //Set magic skills to 0
	Current_Player->smartness = (rand() % 21);  //Pick a random number from 0 and 20
	Current_Player->strength = (80 + rand() % 21);  //Pick a random number from 80 and 100
	Current_Player->dexterity = (80 + rand() % 21);  //Pick a random number from 80 and 100
	Current_Player->luck = 50 - Current_Player->smartness;  //Set luck to a number when smartness is taken away from 50
	Current_Player->dead = 0;  //This player is not dead
}

void wizard(struct player *Current_Player)
{
	printf("Please enter a name for this player: ");
	scanf("%s", Current_Player->name);  //Set name of player
	Current_Player->life_points = 100;  //Set life points to 100
	srand(time(NULL));  //Randomize random number generator using current time
	Current_Player->luck = (rand() % 51) + 50;  //Pick a random number from 50 and 100
	Current_Player->smartness = (rand() % 11) + 90;  //Pick a random number from 90 and 100
	Current_Player->strength = (rand() % 21) + 0;  //Pick a random number from 0 and 20
	Current_Player->magic_skills = (80 + rand() % 21);  //Pick a random number from 80 and 100
	Current_Player->dexterity = (rand() % 101);  //Pick a random number from 0 and 100
	Current_Player->life_points = 100;  //Set life points to 100
	Current_Player->dead = 0;  //This player is not dead
}

int move(struct player *player){

	printf("were would you like to move\n");
	printf("0:don't move\n");
	printf("1:up to ");
	PrintMapSlotType(player->location->up);
	printf("\n2:right to ");
	PrintMapSlotType(player->location->right);
	printf("\n3:down to ");
	PrintMapSlotType(player->location->down);
	printf("\n4:left to ");
	PrintMapSlotType(player->location->left);
	printf("\n");
	
	int input;
	scanf("%d",&input);
	if(input<0||input>4){
		printf("input invalid");
		return 1;
	}
	
	switch(input){
		case 0:
			return 1;
			break;
		case 1:
		
			player->location = player->location->up;
			break;
		case 2:
			player->location = player->location->right;
			break;
		case 3:
			player->location = player->location->down;
			break;
		case 4:
			player->location = player->location->left;
			break;
	};
	
	return 0;
}//end of move 

int AllPlayersNotDead(struct player players[],int choice){
	int i;
	for(i = 0;!players[i].dead && i<choice;i++);
	i++;
	for(;!players[i].dead && i<choice;i++);
	
	if(i<=choice) return 0;
	return 1;
	
}//end of all players not dead


/*
Makes aproprate changes to player stats when then enter a new slot
requires a pointer to the player struct and slot being entered 
modifies the player struct in acordence to the slot it is entering
*/

void EnterSlot(struct player *player, int SlotType){
	
	
	
	switch(SlotType){
		case 0:  //If flat land
			break;
			
		case 1:  //If hill
			if(player->dexterity < 50) player->strength -=10;  
			else if(player->dexterity >= 60) player->strength +=10;
			break;
			
		case 2:  //If city
			if( player->smartness > 60) player->magic_skills +=10;
			if( player->smartness <= 50) player->dexterity -=10;
			break;
		
		default:
			printf("Invalid slotType on enter\n");
	}  //End of switch
	
	
}//end of enter slot


/*
reverts a players stats to what they were before entering the slot
requires a pointer to the player struct and slot being exited 
modifies the player struct in acordence to the slot it is entering
*/

void ExitSlot(struct player *player, int SlotType){
	
	switch(SlotType){
		case 0://if flat land
			break;
			
		case 1://if hill
			if(player->dexterity < 50) player->strength +=10;  
			else if(player->dexterity >= 60) player->strength -=10;
			break;
			
		case 2://if city
			if( player->smartness > 60) player->magic_skills -=10;
			if( player->smartness<= 50) player->dexterity +=10;
			break;
		
		default:
			printf("Invalid slotType on exit\n");
	}//end of switch
	
}//end of exit slot
