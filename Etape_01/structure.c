#include "include.h"

int DIR_LEFT;
int PADDING;
int FRAME_SIZE;
typedef struct s_weapon
{
	int type;
	int speed_shut;
} t_weapon;
typedef struct s_position
{
	int x;
	int y;
}t_position;
typedef struct s_block
{
	int vie;
	struct s_position position;
} t_block;
typedef struct s_space_ship
{
	int type;
	int vie;
	void * attack;
	struct s_weapon weapon;
	struct s_position position;
} t_space_ship;
typedef struct s_joueur
{
	char * pseudo;
	int score;
	int vie;
} t_joueur;
void attack()
{
	printf("Yyyyaaaaaaaaaa");
}
struct s_space_ship * init_monster()
{
	int i = 0;
	int type = 0;
	int padd_ship = 10;
	int last_pos = 0;
	int ligne = 10;
	int compteur = 0;
	t_space_ship * invaders_ship;
	invaders_ship = malloc(sizeof(invaders_ship));
	for (i = 0 ; i < 55 ; i ++)
	{
		invaders_ship[i].vie = 1;
		invaders_ship[i].weapon.type = 1;
		invaders_ship[i].position.x = last_pos + padd_ship;
		invaders_ship[i].position.y = ligne;
		if (compteur == 11)
		{
			compteur = 0;
			last_pos = 0;
			ligne += ligne;
		}
		else
		{
			last_pos = last_pos + padd_ship;
			compteur++;
		}
	}
	return &invaders_ship[0];
}
int checkDirection(t_space_ship * ships)
{
	int i = 0;
	for (i = 0; i < (int)sizeof(ships); i++)
	{
		if (ships[i].position.x < PADDING)
			DIR_LEFT = 0;
		else if (ships[i].position.x > (FRAME_SIZE - PADDING))
			DIR_LEFT = 1;
	}
	return DIR_LEFT;
}
void enemyMove(t_space_ship * Space_ship)
{
	int value_move;
	int i;
	if (checkDirection(Space_ship))
		value_move = -10;
	else 
		value_move = 10;
	for (i = 0 ; i < (int)sizeof(Space_ship) ;  i++)
		Space_ship[i].position.x = Space_ship[i].position.x + value_move; 
}

void init_variables()
{
	PADDING 	= 10;
	DIR_LEFT 	= 0;
	FRAME_SIZE 	= 100; 
}
void terminalAffiche(t_space_ship * invaders)
{
}
