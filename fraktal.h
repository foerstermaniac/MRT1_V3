/* Datei: v3_frakt.h            */
/* P. Rieger; TUD/PLT 20.8.1999 */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Fraktal-Analyse"

*****************************************************************************/

#ifndef __fraktal
#define __fraktal

/*--- Datentypvereinbarungen -----------------------------------------------*/

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

tParam *p;

typedef struct {
	double x, y;
} tComplex;

/*--- Fraktal analysieren und grafisch darstellen --------------------------*/

#endif

/* v3_frakt.h */
