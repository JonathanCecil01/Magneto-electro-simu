
//  simulation.c
/*
//  CPackageSem1
//
//  Created by Jonathan Cecil on 19/12/20.
//
//  simulation.c
//  CPackageSem1
//
//  Created by Jonathan Cecil on 11/12/20.
//


#include <stdio.h>
#include <math.h>
//for data log
#include <time.h>
#include <SDL2/SDL.h>
//to render textures, images
#include <SDL2/SDL_image.h>
// to manipulate delay functions
#include <SDL2/SDL_timer.h>

#define PI  3.14159
#define SCR_WDT  1800
#define SCR_HGT  1000
//to find the centre of screen
const int SCR_CEN_X = SCR_WDT / 2;
const int SCR_CEN_Y = SCR_HGT / 2;

struct Circle
{
    int radius;
    int h;//centre of circle
    int k;//y coordinate od circle centre
    float step;
};

void movement(int m, int v, int q, int B){
    time_t t;   // to access the time
        time(&t);
    int quit=0, length1, x1, y1, length2, length3, count=1;
  // creating a log
   FILE *log;
    log = fopen("/Users/jonathancecil/Documents/Jonathan Cecil/PSG Tech/Semester 1/CProgramming/CPackageSem1/CPackageSem1//Log.txt", "a+");
    float mO, vO, rO, time1, bO, qO;
    mO = 1.6726219;
    vO = 150000;
    bO = 1.0;
    qO = 1.6;
    rO = (mO*vO)/(qO*bO);
    time1 = ((2*PI)*mO)/(qO*bO);
    //storing initial values
    fprintf(log, "\n\n\n***********New Attempt***************\n\n\n%s\nradius(10^-8)m  : %f\ttime(10^-12)s  : %f \n",ctime(&t), rO, time1 );
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window *win = SDL_CreateWindow("CHARGED PARTICLE SIMULATOR", // creates a window
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                       SCR_WDT, SCR_HGT, 0);

    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render screen
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    // creates a surface to load an image into the main memory
    SDL_Surface *surface;

    // please provide a path for your image
    surface = IMG_Load("/Users/jonathancecil/Downloads/Unknown-2.png");

    // loads image to our graphics hardware memory.
    SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);

    // clears main-memory
    SDL_FreeSurface(surface);

    SDL_Rect dest;

    // connects our texture with dest to control position
    SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);
    // adjust height and width of our image box.
    dest.w /= 10;
    dest.h /= 10;
    struct Circle circle;
    circle.radius = (m*v)/(q*B);//formula applied here
    circle.h = SCR_CEN_X;
    circle.k = SCR_CEN_Y;
    circle.step = (PI * 2) / 50;
    float theta =0;//for covering the angle
    length1 = SCR_WDT / 50;
    length2 = SCR_WDT / 50;
    length3 = SCR_WDT / 50;
    x1 =500 ;
    y1 = SCR_HGT-length1;
    dest.x = circle.h+circle.radius;
    dest.y = circle.h;
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
                          switch (e.key.keysym.scancode) {
                          case SDL_SCANCODE_M:
                                  dest.w*=2;
                                  dest.h*=2;
                                  length1+=36;
                                  m*=2;
                                  if(m==0)
                                      m=2;
                                  circle.step/=2;
                                  mO*=2;
                                  rO = (mO*vO)/(qO*bO);
                                  time1 = ((2*PI)*mO)/(qO*bO);
                                  fprintf(log, "\n%s\nradius(10^-8)m  : %f\ttime(10^-12)s  : %f \n",ctime(&t), rO, time1 );
                              break;
                          case SDL_SCANCODE_N:
                                  dest.w/=2;
                                  dest.h/=2;
                                  length1-=36;
                                  m/=2;
                                  circle.step*=2;
                                  mO/=2;
                                  rO = (mO*vO)/(qO*bO);
                                  time1 = ((2*PI)*mO)/(qO*bO);
                                  fprintf(log, "\n%s\nradius(10^-8)m  : %f\ttime(10^-12)s  : %f \n",ctime(&t), rO, time1 );
                                  break;
                          case SDL_SCANCODE_V:
                                  if(v<0)
                                      length2-=3;
                                  else
                                      length2+=3;
                                  v+=50;
                                  vO+=15000;
                                  rO = (mO*vO)/(qO*bO);
                                  time1 = ((2*PI)*mO)/(qO*bO);
                                  fprintf(log, "\n%s\nradius(10^-8)m  : %f\ttime(10^-12)s  : %f \n",ctime(&t), rO, time1 );
                                  break;
                          case SDL_SCANCODE_C:
                                  if(v<0)
                                  {
                                      length2+=3;
                                      v-=50;
                                  }
                                  else{
                                      length2-=3;
                                      v-=50;
                                  }
                                  vO-=15000;
                                  rO = (mO*vO)/(qO*bO);
                                  time1 = ((2*PI)*mO)/(qO*bO);
                                  fprintf(log, "\n%s\nradius(10^-8)m  : %f\ttime(10^-12)s  : %f \n",ctime(&t), rO, time1 );
                                      break;
                              case SDL_SCANCODE_F:
                                  B*=2;
                                  length3+=5;
                                  circle.step*=2;
                                  bO*=2;
                                  rO = (mO*vO)/(qO*bO);
                                  time1 = ((2*PI)*mO)/(qO*bO);
                                  fprintf(log, "\n%s\nradius(10^-8)m  : %f\ttime(10^-12)s  : %f \n",ctime(&t), rO, time1 );
                                      break;
                              case SDL_SCANCODE_D:
                                  B/=2;
                                  length3-=5;
                                  circle.step/=2;
                                  bO/=2;
                                  rO = (mO*vO)/(qO*bO);
                                  time1 = ((2*PI)*mO)/(qO*bO);
                                  fprintf(log, "\n%s\nradius(10^-8)m : %f\ttime(10^-12)s  : %f \n",ctime(&t), rO, time1 );
                                  break;
                          case SDL_SCANCODE_Q:
                                  q=q*(-1);
                                  rO = (mO*vO)/(qO*bO);
                                  time1 = ((2*PI)*mO)/(qO*bO);
                                  fprintf(log, "\n%s\nradius(10^-8)m : %f\ttime(10^-12)s : %f \n",ctime(&t), rO, time1 );
                                  break;

                              
                          }
                      }
           }
         circle.radius = (m*v)/(q*B);
         if(circle.radius>=0)
         {
         dest.x = circle.h + (circle.radius * cos ( theta ));
         dest.y = circle.k + (circle.radius * sin ( theta ));
         theta += circle.step;
         }
         else{
             dest.x = circle.h + (circle.radius * cos ( theta ));
             dest.y = circle.k - (circle.radius * sin ( theta ));
             theta += circle.step;
         }
         SDL_RenderClear(rend);
         SDL_Rect massRect = { 0 , 200 , length1, 36 };
         SDL_SetRenderDrawColor( rend, 250, 00, 00, 250 );
         SDL_RenderFillRect( rend, &massRect);
         SDL_Rect fieldRect = { 0 , 600 , length3, 36 };
         SDL_SetRenderDrawColor( rend, 20, 0, 150, 250 );
         SDL_RenderFillRect( rend, &fieldRect);
      if(v<=0)
      {
          SDL_Rect velNegRect = { 1800-length2 , 400 , length2, 36};
          SDL_SetRenderDrawColor( rend, 0x00, 0xFF, 0x00, 0xFF );
          SDL_RenderFillRect( rend, &velNegRect );
      }
      else{
         SDL_Rect velRect = { 0 , 400 , length2, 36};
         SDL_SetRenderDrawColor( rend, 0x00, 0xFF, 0x00, 0xFF );
         SDL_RenderFillRect( rend, &velRect );
      }
         SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
         SDL_Rect radiusRect = { 0 , 800 , circle.radius/2, 36 };
         SDL_SetRenderDrawColor( rend, 250, 250, 250, 250 );
         SDL_RenderFillRect( rend, &radiusRect );
     
      if(circle.radius<=0)
      {
         SDL_Rect radiusNegRect = { 1800+(circle.radius/2) , 800 , (-1)*circle.radius/2, 36 };
         SDL_SetRenderDrawColor( rend, 250, 250, 250, 250 );
         SDL_RenderFillRect( rend, &radiusNegRect );
      }
         SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
         SDL_RenderCopy(rend, tex, NULL, &dest);
         SDL_RenderPresent(rend);

         // calculates to 60 fps
         SDL_Delay(1000 / 60);
         count++;
  }
    fclose(log);
    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    
}
*/



