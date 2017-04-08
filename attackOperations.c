#include "crossfireOperations.h"

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

void MagicAttack(struct player *AttackerPlayer, struct player *AttackedPlayer)
{
	if(AttackerPlayer->smartness + AttackerPlayer->magic_skills > 150)
	{
		AttackedPlayer->life_points = AttackedPlayer->life_points - ((0.5 * AttackerPlayer->magic_skills) + (0.2 * AttackerPlayer->smartness));
	}
}
