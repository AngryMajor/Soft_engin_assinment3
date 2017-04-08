#include "crossfireOperations.h"

void choosePlayer_NearAtt(struct player CurrPlayer, struct player player[])
{
	// Search for players in the same slot, or players in slots adjacent to current player.
	
	int i, decision;
	printf("Players available to attack:\n");
	for(i = 0l player[i]; i++)
	{
		if(!player[i]->dead)
			printf("%d %s\n", i, player->name);
	}
	printf("Which player would you like to attack?: \n");
	scanf("%d", &decision);
	if(decision > 1 || decision < 0)
	{
		printf("This option is not valid.\n");
		return choosePlayer_NearAtt(player[]);
	}
	if(player[decision]->dead)
	{
		printf("This player is dead.\n");
		return choosePlayer_NearAtt(player[]);
	}
	NearAttack(CurrPlayer, player[decision]);
}

void choosePlayer_MagAtt(int num_ofplayers,struct player CurrPlayer, struct player player[])
{
	int i,decision;
	printf("Players available to attack:\n");
	for(i = 0; i < num_ofplayers ; i++)
	{
		if(!player[i].dead)
			printf("%d, %s\n", i, player[i].name);
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

void NearAttack(struct player *AttackerPlayer, struct player *AttackedPlayer)
{
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
