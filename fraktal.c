/* Datei: v3_frakt.c              */
/* P. Rieger; TUD/PLT 4.10.2001   */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Fraktal-Analyse"

*****************************************************************************/

#include "fraktal.h"
#include "graphic.h"
#include <math.h>
typedef enum fracType {
	apfel,
	julia
}fracType;
typedef struct {
	double radius;
	int imax;
	fracType ftype;
	double xmin, xmax, ymin, ymax;
	int xpoints, ypoints;
} tParam;

typedef struct {
	double x, y;
} tComplex;

double getAbsolute(tComplex z){
	return sqrt((z.x+z.x)+(z.y+z.y));
}

double getDistance(tComplex a, tComplex b){
	tComplex d;
	d.x = b.x - a.x;
	d.y = b.y - a.y;
	return getAbsolute(d);
}

/*--- Interne Funktion: Analyse der Iterationsanzahl -----------------------*/

int getItera(tComplex c, tComplex z, tParam p){
	tComplex mitte;
	tComplex znew;
	tComplex zold;
	double distance = 0;
	int i = 0;

	if(p.ftype == apfel) mitte = z;
	if(p.ftype == julia) mitte = c;
	zold = z;
	while((distance <= p.radius)&&(i < p.imax)){
		znew.x = c.x + (zold.x * zold.x) - (zold.y * zold.y);
		znew.y = c.y + (2 * zold.x * zold.y);
		zold = znew;
		distance = getDistance(mitte, znew);
		i++;
	}
	return i;

}

/*--- Interne Funktion: Farbwert bestimmen ---------------------------------*/

tColor getColorValue(tParam p, int i){
	if (i > p.imax) return 0;
	else return i%16;
}

/*--- Fraktal-Figur analysieren und zeichnen -------------------------------*/

void fraktal(tComplex z, tComplex c, tParam p){
	double dx = (p.xmax-p.xmin)/(double)(p.xpoints);
	double dy = (p.ymax-p.ymin)/(double)(p.ypoints);
	if(p.ftype == apfel){
		for(double x=p.xmin; x<=p.xmax; x+=dx){
			for(double y=p.ymin; y<=p.ymin; y+=dy){
				tComplex cn = {x, y};
				LockScreen();
				setPoint(x, y, getColorValue(p, getItera(cn, z, p)));
				UnlockScreen();
			}
		}
	}
	else if(p.ftype == julia){
		for(double x=p.xmin; x<=p.xmax; x+=dx){
			for(double y=p.ymin; y<=p.ymin; y+=dy){
				tComplex zn = {x, y};
				LockScreen();
				setPoint(x, y, getColorValue(p, getItera(c, zn, p)));
				UnlockScreen();
			}
		}
	}
}

/* v3_frakt.c */
