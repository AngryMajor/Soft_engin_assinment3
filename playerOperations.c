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
