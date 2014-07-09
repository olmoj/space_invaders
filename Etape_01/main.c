/*
** main.c for  in /Users/olmo_j/Documents/Projets/Space_Invaders/Etape_01
** 
** Made by OLMO Joy
** Login   <olmo_j@etna-alternance.net>
** 
** Started on  Wed Jul  2 14:43:55 2014 OLMO Joy
** Last update Wed Jul  9 17:34:55 2014 OLMO Joy
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>

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

static t_window myWindow;

void init()
{
  myWindow.renderer = SDL_CreateRenderer(myWindow.window, -1, SDL_RENDERER_ACCELERATED);
  myWindow.rectangle.x = 0;
  myWindow.rectangle.y = 0;
  myWindow.rectangle.w = myWindow.width;
  myWindow.rectangle.h = myWindow.height;

  myWindow.texture = IMG_LoadTexture(myWindow.renderer, "img/background.jpg");
}

int openWindow()
{
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS) != 0)
    {
      fprintf(stdout, "Échec de l'initialisation de la SDL (%s)\n",
	      SDL_GetError());
      return (-1);
    }
  else
    {
      myWindow.window = SDL_CreateWindow("Space Invaders",
				 SDL_WINDOWPOS_UNDEFINED,
				 SDL_WINDOWPOS_UNDEFINED,
				 myWindow.width,
				 myWindow.height,
				 SDL_WINDOW_SHOWN);
      if (myWindow.window)
	init();
      else
	{
	  fprintf(stderr, "Erreur de création de la fenêtre: %s\n", SDL_GetError());
	  return (-1);
	}
    }
  return (1);
}

void destroy()
{
  SDL_DestroyTexture(myWindow.texture);
  SDL_FreeSurface(myWindow.background);
  SDL_DestroyRenderer(myWindow.renderer);
  SDL_DestroyWindow(myWindow.window);
  SDL_Quit();
}

int main(int argc, char** argv)
{
  int isRunning;
  myWindow.width = 800;
  myWindow.height = 600;
  openWindow();
  isRunning = 1;
  while (isRunning)
    {
      Uint32 toWait;
      Uint32 time = SDL_GetTicks();
      SDL_RenderClear(myWindow.renderer);
      SDL_RenderCopy(myWindow.renderer, myWindow.texture, NULL, &myWindow.rectangle);
      SDL_RenderPresent(myWindow.renderer);
      toWait = SDL_GetTicks() - time;

      if (toWait < 16)
	SDL_Delay(16 - toWait);
      SDL_Delay(9000);
      isRunning = 0;
    }
  destroy();
  return (0);
}
