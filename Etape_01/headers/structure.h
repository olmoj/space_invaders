/*
** structures.h for  in /Users/olmo_j/Documents/Projets/Space_Invaders/Etape_01
** 
** Made by OLMO Joy
** Login   <olmo_j@etna-alternance.net>
** 
** Started on  Wed Jul 16 15:38:34 2014 OLMO Joy
** Last update Wed Jul 16 18:05:16 2014 OLMO Joy
*/

#ifndef		_STRUCTURES_H_
#define		_STRUCTURES_H_

typedef struct s_window
{
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Surface* background;
  SDL_Texture* texture;
  SDL_Rect rectangle;
  int width;
  int height;
} t_window;

#endif		/* !_STRUCTURES_H_ */
