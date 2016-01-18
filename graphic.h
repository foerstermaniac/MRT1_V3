/* Datei: v3_graph.h            */
/* P. Rieger; TUD/PLT 4.10.2001 */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Grafische Darstellung"

*****************************************************************************/

#ifndef __graphic
#define __graphic

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

/*----- Typdefinitionen ----------------------------------------------------*/

typedef enum {  black,         /*   0 schwarz         */
                blue,          /*   1 blau            */
                green,         /*   2 grn            */
                cyan,          /*   3 cyan            */
                red,           /*   4 rot             */
                magenta,       /*   5 violett         */
                brown,         /*   6 braun           */
                white,         /*   7 wei            */
                gray,          /*   8 grau            */
             	lightblue,     /*   9 hellblau        */
             	lightgreen,    /*  10 hellgrn        */
            	lightcyan,     /*  11 hellcyan        */
             	lightred,      /*  12 hellrot         */
            	lightmagenta,  /*  13 hellviolett     */
              	lightyellow,   /*  14 gelb            */
            	brightwhite    /*  15 intensivwei    */
      	      } tColor;


/*--------------------------------------------------------------------------*/
/*    Funktionen                                                            */
/*--------------------------------------------------------------------------*/

/*--- Grafik initialisieren und schließen ----------------------------------*/

void InitGraph (double Xmin, 
				double Xmax,
				double Ymin,
				double Ymax);

void CloseGraph (void);

/*--- Ausgabefenster sperren und entsperren --------------------------------*/

void LockScreen();
void UnlockScreen();

/*--- Grafikpunkt setzen ---------------------------------------------------*/

void SetPoint (double x, double y, tColor color);


#endif

/* v3_graph.h */
