/* Datei: v3_dialo.c            */
/* P. Rieger; TUD/PLT 4.10.2001 */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Parameterdialog"

*****************************************************************************/

#include "dialog.h"
#include <stdio.h>
#include <stdlib.h>

/*--- Definitionen ---------------------------------------------------------*/

enum bool {FALSE, TRUE};


/*--- Tastatureingabe lesen und nur ersten Character beachten --------------*/

char InputChar ()
{
	char s[80];
  	fgets(s,sizeof(s), stdin);
  	return s[0];
};

/*--- Double-Zahl von der Tastatur lesen -----------------------------------*/

void InputDouble (double *value)
{
  	char *endptr;
  	char s[80];
  	fgets(s,sizeof(s), stdin);
  	if (s[0]!=10) *value=strtod (s, &endptr);
};


/*--- Int-Zahl von der Tastatur lesen --------------------------------------*/

void InputInt (int *value)
{
  char s[80];
  fgets(s,sizeof(s), stdin);
  if (s[0]!=10) *value=atoi (s);
};


/*--- Parameter Dialog ------------------------------------------------------*/


/* v3_frakt.c */
