struct player type()
{
	
	struct player player;
		puts("There are four player options to choose from.");
		puts("Enter the number corresponding to the player option.");
		printf("1. Elf.\n2. Human.\n3. Ogre.\n4. Wizard\n");
		
		do{
			printf("Please enter the number corresponding to the type for Player 1: ");
			scanf("%d", &player.type);
			switch(player.type)
			{
				case 1:
				elf(&player);
				break;
				case 2:
				human(&player);
				break;
				case 3:
				ogre(&player);
				break;
				case 4:
				wizard(&player);
				break;
				default:
				printf("That's not a valid option.\n");
			}
		} while(player.type >4 || player.type < 0);
	
	return player;
}
void elf(struct player *Current_Player)
{	
	printf("Please enter a name for this player: ");
	scanf("%s", Current_Player->name);
	Current_Player->life_points = 100;
	srand(time(NULL));
	Current_Player->smartness = (rand() % 31) + 70;
	Current_Player->strength = (rand() % 51);
	Current_Player->magic_skills = (50 + rand() % 31);
	Current_Player->luck = (rand() % 41) + 60;
	Current_Player->dexterity = (rand() % 101);
}

void human(struct player *Current_Player)
{
	int sum;
	printf("Please enter a name for this player: ");
	scanf("%s", Current_Player->name);
	Current_Player->life_points = 100;
	srand(time(NULL));
	Current_Player->magic_skills = (rand() % 101);
	Current_Player->smartness = (rand() % 101);
	Current_Player->strength = (rand() % 101);
	Current_Player->dexterity = (rand() % 101);
	Current_Player->luck = (rand() % 101);
	sum = Current_Player->magic_skills + Current_Player->smartness + Current_Player->strength + Current_Player->dexterity + Current_Player->luck;
	sum <=300;
}

void ogre(struct player *Current_Player)
{
	printf("Please enter a name for this player: ");
	scanf("%s", Current_Player->name);
	Current_Player->life_points = 100;
	srand(time(NULL));
	Current_Player->magic_skills = 0;
	Current_Player->smartness = (rand() % 21);
	Current_Player->strength = (80 + rand() % 21);
	Current_Player->dexterity = (80 + rand() % 21);
	Current_Player->luck = 50 - Current_Player->smartness;
}

void wizard(struct player *Current_Player)
{
	printf("Please enter a name for this player: ");
	scanf("%s", Current_Player->name);
	Current_Player->life_points = 100;
	srand(time(NULL));
	Current_Player->luck = (rand() % 51) + 50;
	Current_Player->smartness = (rand() % 11) + 90;
	Current_Player->strength = (rand() % 21) + 0;
	Current_Player->magic_skills = (80 + rand() % 21);
	Current_Player->dexterity = (rand() % 101);
	Current_Player->life_points = 100;
}
