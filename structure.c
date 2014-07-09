#include <stdlib.h>;

struct Weapon
{
	int type;
	int speed_shut;
};
struct Position
{
	int x;
	int y;
};
struct Block
{
	int vie;
	struct Position position;
};
struct Space_ship
{
	int type;
    int vie;
    void * attack;
    struct Weapon weapon;
    struct Position position;
};
struct Joueur
{
	char * pseudo;
	int score;
	int vie;
};
struct Position createPosition(struct Position)
{
	struct Position pos;
	//controle de la positon de base;
	//calcule de la nouvelle position en fonction de la taille de l'écran
	

	//création de la nouvelle position

	return pos;
}
void attack()
{
	printf("Yyyyaaaaaaaaaa");
}
struct Space_ship * init_monster()
{
	int i = 0;
	int type = 0;

	printf("----------------------- INIT MONSTER -----------------------\n");
	struct Space_ship * invaders_ship;
	invaders_ship = malloc(sizeof(invaders_ship));
	for (i = 0 ; i < 55 ; i ++)
	{
		//pointeur sur fonction pour le type!!!;
		invaders_ship[i].vie = 1234567;
		invaders_ship[i].weapon.type = 1;
		invaders_ship[i].position.x = 0;
		invaders_ship[i].position.y = 0;
		printf("invaders_ship = %d \n", &invaders_ship[i]);
	}
	printf("----------------------- CONTROLE TAB MONSTER -----------------------\n");
	printf("adresse invaders_ship[0] = %d\n", &invaders_ship[0]);
	return &invaders_ship[0];
}
void move(struct Space_ship * Space_ship)
{
	Space_ship->vie = Space_ship->vie - 10;
}
int main(int argc, char *argv[])
{
	int i;
	struct Space_ship * invaders = init_monster();
	printf("----------------------- SEND CONTROLE TAB MONSTER -----------------------\n");
	//printf("adresse invaders_ship[0] = %d\n", &invaders[0].vie);
	
	printf("----------------------- VIEW MONSTER -----------------------\n");
	for (i = 0; i < 55 ; i++)
	{
		printf("invider[%d] = %d \n", i, invaders[i].vie);
	}

	/*struct Space_ship 	invaders[2]; // Création d'une variable "point" de type Coordonnees
    space_ship[0].vie = 100;
    space_ship[0].position.x = 4;
    space_ship[0].position.y = 0;

    for (i = 0 ;  i < 4 ; i++)
    {
		move(&space_ship[0]);
    	printf("vie = %d, posX = %d\n", space_ship[0].vie, space_ship[0].position.x);    
	}*/
    return 0;
}