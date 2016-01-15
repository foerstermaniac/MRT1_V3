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

enum bool {FALSE, TRUE};			//Kann mir jemand sagen, warum ich das hierhin geschrieben habe? :'D


/*--- Tastatureingabe lesen und nur ersten Character beachten --------------*/

char InputChar ()
{
	char s[80];
  	fgets(s,sizeof(s), stdin);		//nicht lieber sizeof(s-1)?
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

void DisplayParam(tParam *p, tComplex *c){
	printf("Die aktuellen Parameter lauten wie folgt:\n");
	printf("Der Radius beträgt %lf,\n", p->radius);
	printf("Der Fraktaltyp %d wird mit maximal %d Iterationen im\n", p->ftype, p->imax);
	printf("Analysegebiet %lf <= x <= %lf  %lf <= y <= %lf betrachtet.\n", p->xmin, p->xmax, p->ymin, p->ymax);
	printf("Das Analysegebiet hat %dx%d Linien.\n", p->xpoints, p->ypoints);
	printf("c beträgt: %lf+j(%lf).\n", c->x, c->y);
}

/*	Hier muss ich eingestehen, dass ich selbst nicht ganz sicher bin,
 * 	ob die Konstruktionen die ich da gebastelt habe immer so funktionieren
 * 	wie sie sollen.
 * 	Ihr könnt auch gerne jeden Wert einzeln abfragen: fühlt sich dann halt
 * 	nicht so schön an.
 */

void ChangeParam(tParam *p, tComplex *c){
	int flag = 1;
	printf("Welchen Parameter moechtest du aendern?\n");
	printf("(1) - Radius\n(2) - Maximale Iterationszahl\n(3) - Fraktaltyp\n(4) - Analysegebiet\n");
	printf("(5) - Linien im Analysegebiet\n(6) - c\n(0) - Ich bin fertig!\n");
	int choice;
	InputInt(&choice);
	while(flag){
	switch (choice){
	case 1:
		printf("Der alte Radius beträgt %lf. Bitte gib einen neuen an.\n", p->radius);
		InputDouble(&p->radius);
		break;
	case 2:
		printf("Der alte imax-Wert beträgt %d. Bitte gib einen neuean an.\n", p->imax);
		InputInt(&p->imax);
		break;
	case 3:
		printf("Der alte Fraktaltyp ist %d. Bitte gib einen neuen ein.\n", p->ftype);
		printf("Tipp: 0 - Apfel, 1- Julia\n");
		if (InputChar() == '0') p->ftype=apfel; else if (InputChar() == '1') p->ftype=julia; else ;
		break;
	case 4:
		printf("Das alte Analysegebiet: %lf<=x<=%lf; %lf<=y<=%lf. Bitte gib ein neues ein.\n", p->xmin, p->xmax, p->ymin, p->ymax);
		printf("x geht von ");
		InputDouble(&p->xmin);
		printf("%lf bis ", p->xmin);
		InputDouble(&p->xmax);
		printf("%lf\ny geht von ", p->xmax);
		InputDouble(&p->ymin);
		printf("%lf bis ", p->ymin);
		InputDouble(&p->ymax);
		printf("%lf.\n", p->ymax);
		break;
	case 5:
		printf("Die alte Linienzahlen sind: x=%d y=%d. Bitte gib neue Werte ein.\n Linien in x-Richtung: ", p->xpoints, p->ypoints);
		InputInt(&p->xpoints);
		printf("%d und in y-Richtung: ", p->xpoints);
		InputInt(&p->ypoints);
		printf("%d.\n", p->ypoints);
		break;
	case 6:
		printf("Der alte Wert für c beträgt: %lf+j(%lf). Bitte gib eien neuen ein.\n", c->x, c->y);
		printf("Realteil ");
		InputDouble(&c->x);
		printf("%lf und Imaginärteil ", c->x);
		InputDouble(&c->y);
		printf("%lf\n", c->y);
		break;
	case 0:
		flag = 0;
		break;
	}
	}
}

/*	Hat noch jemand Ideen was es noch so für Fehleingaben geben könnte?
 * 	Dann immer her damit!!!
 */

int validation(tParam *p, tComplex *c){
#define ERROR printf("Das ist Quatsch! Bitte nochmal überprüfen."); return 0;
	if(p->radius <= 0) ERROR;
	if(p->xmax <= p->xmin || p->ymax <= p->ymin) ERROR;
	if(p->xpoints == 0 || p->ypoints == 0) ERROR;
	if(c->x < p->xmin || c->x > p->xmax) ERROR;
	return 1;
}

/*--- Parameter Dialog ------------------------------------------------------
 * 	Wichtig bei der ganzen Parameteränderungs-geschichte ist, dass man immer
 * 	Zeiger auf die Parameter weiter gibt. Sonst würde man die ja nur in der
 * 	Funktion änden.
 *
 *
 * 	Noch einen kleine Denkaufgabe / ein Syntaxhinweis:
 *
 * 	wenn ich einen Zeiger auf eine Struktur übergebe (in unserem Fall auf p),
 * 	muss ich diesen später dereferenzieren um an den Inhalt zu kommen. Wie?
 * 	*p.imax wäre falsch. (siehe Rangfolge: . hat größere Priorität als *)
 * 	(*p).imax wäre richtig, aber zu umständlich.
 * 	p->imax entspricht (*p).imax und ist wunderbar einfach.
 * 	Will man die Adresse von solch einem Element haben,
 * 	nutzt man einfach &p->imax.
 */

int ParamDialog(tParam *p, tComplex *c){
										//if failure: 0
										//else 1
	DisplayParam(p, c);
	printf("Sollen Parameter geändert werden?\n(j) Ja, bitte.\n(n) Nein, danke.\n(e) Programm beenden!");
	switch (InputChar()){
	case 'j':
		do {
			ChangeParam(p, c);			//Vllt sollte man eine maxAnzahl an Versuchen in Erwähgung ziehen?
		} while(validation(p,c) == 0);	//Schleife wird erst verlassen, wenn Werte Sinn machen.
		return 1;
		break;
	case 'n':
		return 1;
		break;
	case 'e':
		return 0;
		break;
	}
}



/* v3_frakt.c */
