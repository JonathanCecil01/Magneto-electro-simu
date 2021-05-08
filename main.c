#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>
// for rendering images and graphics on screen
#include <SDL2/SDL_image.h>
// for using SDL_Delay() functions
#include <SDL2/SDL_timer.h>
//including the code for simulation
#include "simulation.txt"
void main()
{
    int v, m, q, B;
    SDL_Window *win = SDL_CreateWindow("SIMULATOR", // creates a window
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                       SCR_WDT, SCR_HGT, 0);
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;
    // creates a renderer to render our images
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    // creates a surface to load an image into the main memory
    SDL_Surface *surface1;
    surface1 = IMG_Load("/Users/jonathancecil/Downloads/Black_Box.png");
    // loads image to our graphics hardware memory.
    SDL_Texture* tex1 = SDL_CreateTextureFromSurface(rend, surface1);
    // clears main-memory
    SDL_FreeSurface(surface1);
    SDL_Rect dest1;
    // connects our texture with dest to control position
    SDL_QueryTexture(tex1, NULL, NULL, &dest1.w, &dest1.h);
    // adjust height and width of our image box.
    dest1.w =SCR_WDT;
    dest1.h = SCR_HGT;
    dest1.x=0;
    dest1.y=0;
    int quit=0;
    while(!quit)
  {
      SDL_Event e;
            while (SDL_PollEvent(&e)) {
                      switch (e.type) {
            
                      case SDL_QUIT:
                          // handling of close button
                          quit = 1;
                          break;
            
                      case SDL_KEYDOWN:
                          //for key pressed
                          switch (e.key.keysym.scancode) {
                          case SDL_SCANCODE_KP_ENTER: 
                              break;
                          case SDL_SCANCODE_1:
                                  m =2;q=1;v=500;B=10;
                                  SDL_DestroyRenderer(rend);
                                  movement(m, v, q, B);
                                  break;
                          }
                      }
                
           }
      SDL_SetRenderDrawColor(rend, 0, 0, 0, 250);
      SDL_RenderCopy(rend, tex1, NULL, &dest1);
      SDL_RenderPresent(rend);
   }
}


