/* Datei v3_main.c              */
/* P. Rieger; TUD/PLT 4.10.2001 */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Main-Programm

*****************************************************************************/

#include "fraktal.h"
#include "graphic.h"
#include "dialog.h"
#include <stdio.h>



//int main (void)
int main(int argc, char* argv[])
{
	/*--- Variablendeklaration ---------------------------------------------*/
	tParam p = {4, 75, apfel, -2, 2, -2, 2, 640, 480};
	tComplex c = {0.4, 0.4};
	tComplex z = {0, 0};



  	/*--- Initialwerte -----------------------------------------------------*/

  	/*----------------------------------------------------------------------*/
  	/*--- Parameter über Dialog abfragen                                  --*/
  	/*----------------------------------------------------------------------*/
	ParamDialog(&p, &c);
	InitGraph (p.xmin, p.xmax, p.ymin, p.ymax);			// Initialisierung der Grafik
    LockScreen();										// Bildschirm muss zum Setzen von Pixeln gesperrt sein
  	/*----------------------------------------------------------------------*/
  	/*--- Fraktale berechnen und ausgeben                                 --*/
  	/*----------------------------------------------------------------------*/
    fraktal(&c, &z, &p);
    UnlockScreen(); // Alle Änderungen auf Bildschirm ausgeben
    
    /*Aufrufen von InputChar() um das Programm nach dem öffnen der Graphik   */
    /*anzuhalten. Erst wenn in der Konsole eine Taste gedrückt wird, schließt*/
    /*sich das Fenster wieder. */
    InputChar(); 
    CloseGraph();
	
	return 0;
}
