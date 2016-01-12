10/* Datei: v3_graph.c             */
/* P. Rieger; TUD/PLT 4.10.2001  */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Grafische Darstellung"

*****************************************************************************/

#include "graphic.h"


/*----- Definitionen -------------------------------------------------------*/

#define WIDTH 640
#define HEIGHT 480
#define BPP 4
#define DEPTH 32
SDL_Surface *screen;
SDL_Event event;
double xmin, xmax, ymin, ymax, deltax, deltay;


/*--------------------------------------------------------------------------*/
/*    Funktionen                                                            */
/*--------------------------------------------------------------------------*/

/*--- Grafik initialisieren ------------------------------------------------*/

void InitGraph (double Xmin, double Xmax, double Ymin, double Ymax)
{
	if (SDL_Init(SDL_INIT_VIDEO)<0) printf("SDL_Init failed\n");
    if (!(screen = SDL_SetVideoMode(WIDTH, HEIGHT, DEPTH, SDL_HWSURFACE)))
    {
    	printf("SDL_SetVideoMode failed");
        SDL_Quit();
    }
    xmin = Xmin; xmax = Xmax; ymin = Ymin; ymax = Ymax;
    deltax = (xmax-xmin)/WIDTH;
    deltay = (ymax-ymin)/HEIGHT;
};


/*--- Farbpunkt setzen -----------------------------------------------------*/

void SetPoint (double x, double y, tColor inputColor)
{
	Uint32 *pixmem32;
    Uint32 color;
        
    int xdraw = (x-xmin)/deltax;
    int ydraw = (y-ymin)/deltay;
	
	switch(inputColor) {
	case 0:
	color = SDL_MapRGB( screen->format, 0, 0, 0);
	break;
	case 1:
	color = SDL_MapRGB( screen->format, 0, 0, 255);
	break;
	case 2:
	color = SDL_MapRGB( screen->format, 0, 139, 0);
	break;
	case 3:
	color = SDL_MapRGB( screen->format, 0, 255, 255);
	break;
	case 4:
	color = SDL_MapRGB( screen->format, 255, 0, 0);
	break;
	case 5:
	color = SDL_MapRGB( screen->format, 255, 0, 255);
	break;
	case 6:
	color = SDL_MapRGB( screen->format, 165, 42, 42);
	break;
	case 7:
	color = SDL_MapRGB( screen->format, 240, 240, 240);
	break;
	case 8:
	color = SDL_MapRGB( screen->format, 190, 190, 190);
	break;
	case 9:
	color = SDL_MapRGB( screen->format, 173, 216, 230);
	break;
	case 10:
	color = SDL_MapRGB( screen->format, 0, 255, 0);
	break;
	case 11:
	color = SDL_MapRGB( screen->format, 224, 255, 255);
	break;
	case 12:
	color = SDL_MapRGB( screen->format, 255, 192, 203);
	break;
	case 13:
	color = SDL_MapRGB( screen->format, 139, 0, 139);
	break;
	case 14:
	color = SDL_MapRGB( screen->format, 255, 255, 0);
	break;
	case 15:
	color = SDL_MapRGB( screen->format, 255, 255, 255);
	break;
	default:
	color = SDL_MapRGB( screen->format, 0, 0, 0);
	}
    
	pixmem32 = (Uint32*) screen->pixels + (ydraw*screen->pitch/BPP) + (xdraw);
    *pixmem32 = color;
};


/*--- Ausgabefenster sperren -----------------------------------------------*/

void LockScreen()
{
	if(SDL_MUSTLOCK(screen)) 
    {
        if(SDL_LockSurface(screen) < 0) return;
    }
}


/*--- Ausgabefenster entsperren und gepufferte Daten ausgeben --------------*/

void UnlockScreen()
{
	if(SDL_MUSTLOCK(screen)) SDL_UnlockSurface(screen);
  
    SDL_Flip(screen);
}


/*--- Grafik schließen -----------------------------------------------------*/

void CloseGraph() { SDL_Quit(); };

/* v3_graph.c */
