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



int main (void)
{
	/*--- Variablendeklaration ---------------------------------------------*/



  	/*--- Initialwerte -----------------------------------------------------*/

  	/*----------------------------------------------------------------------*/
  	/*--- Parameter über Dialog abfragen                                  --*/
  	/*----------------------------------------------------------------------*/


    InitGraph (/*xmin, xmax, ymin, ymax übergeben*/); 	// Initialisierung der Grafik
    
    LockScreen(); // Bildschirm muss zum Setzen von Pixeln gesperrt sein
  	/*----------------------------------------------------------------------*/
  	/*--- Fraktale berechnen und ausgeben                                 --*/
  	/*----------------------------------------------------------------------*/
    UnlockScreen(); // Alle Änderungen auf Bildschirm ausgeben
    
    /*Aufrufen von InputChar() um das Programm nach dem öffnen der Graphik   */
    /*anzuhalten. Erst wenn in der Konsole eine Taste gedrückt wird, schließt*/
    /*sich das Fenster wieder. */
    InputChar(); 
    CloseGraph();
	
	return 0;
}
