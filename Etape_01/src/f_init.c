/*
** f_init.c for  in /Users/olmo_j/Documents/Projets/Space_Invaders/Etape_01
** 
** Made by OLMO Joy
** Login   <olmo_j@etna-alternance.net>
** 
** Started on  Wed Jul 16 17:47:19 2014 OLMO Joy
** Last update Wed Jul 16 18:05:50 2014 OLMO Joy
*/

#include "include.h"
#include "structure.h"

void init(t_window *myWindow)
{
  myWindow->renderer = SDL_CreateRenderer(myWindow->window, -1, SDL_RENDERER_ACCELERATED);
  myWindow->rectangle.x = 0;
  myWindow->rectangle.y = 0;
  myWindow->rectangle.w = myWindow->width;
  myWindow->rectangle.h = myWindow->height;
  myWindow->texture = IMG_LoadTexture(myWindow->renderer, "img/background.jpg");
}

int openWindow(t_window *myWindow)
{
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS) != 0)
    {
      fprintf(stdout, "Échec de l'initialisation de la SDL (%s)\n",
              SDL_GetError());
      return (-1);
    }
  else
    {
      myWindow->window = SDL_CreateWindow("Space Invaders",
					 SDL_WINDOWPOS_UNDEFINED,
					 SDL_WINDOWPOS_UNDEFINED,
					 myWindow->width,
					 myWindow->height,
					 SDL_WINDOW_SHOWN);
      if (myWindow->window)
        init(myWindow);
      else
        {
	  fprintf(stderr, "Erreur de création de la fenêtre: %s\n", SDL_GetError());
          return (-1);
        }
    }
  return (1);
}
