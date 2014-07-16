/*
** main.c for  in /Users/olmo_j/Documents/Projets/Space_Invaders/Etape_01
** 
** Made by OLMO Joy
** Login   <olmo_j@etna-alternance.net>
** 
** Started on  Wed Jul  2 14:43:55 2014 OLMO Joy
** Last update Wed Jul 16 17:58:39 2014 OLMO Joy
*/

#include "include.h"
#include "structure.h"
#include "prototype.h"

void destroy(t_window *myWindow)
{
  SDL_DestroyTexture(myWindow->texture);
  SDL_FreeSurface(myWindow->background);
  SDL_DestroyRenderer(myWindow->renderer);
  SDL_DestroyWindow(myWindow->window);
  SDL_Quit();
}

int main()
{
  t_window myWindow;
  int isRunning;
  myWindow.width = 800;
  myWindow.height = 600;
  openWindow(&myWindow);
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
  destroy(&myWindow);
  return (0);
}
