	
//put this in a function, i think you just forgot to copy the function part over formt the old assingment

	int choice;  //Number to be entered by user
	printf("Please input how many players are playing the game: ");  //Prompt user to enter a number
	scanf("%d", &choice);  //Reads an integer used to represent the number of players playing the game
	struct player player[choice];  
//	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//	this aray will be forgoten as soon as the function ends, either make it static and return a pointer to it or move it and pass it into this function
	
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
		return main();//!!!!!!!!!!!!!!!!!!!!!! Dont return main here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}
