/**********************************************************************/
#include "std.h"
#include "megatyp.h"
#include "megacad.h"
/**********************************************************************/
short MegaMain(
        char *filename,
        char *args )
{
    char   bufP[255];
    ushort which;
    double result;

    // den Umfang einer Polyline berechnen
    // der Anwender sucht die Polyline selber aus.
    which = CALC_PERIM;
    // wenn alles ok ist, Ergebniss ausgeben
    // FuncText und MouseHelp mÅssen nicht gesetzt werden, das macht die Fkt.
    if(CalcPattern(which,0,NULL,&result))
        sprintf(bufP,"Umfang : %lf",result);
    else // Fehler
        sprintf(bufP,"%s","Fehler Berechnung UMFANG");
    Message(bufP,"",NULL,NULL,"OK",3);

    return(0);
}
/**********************************************************************/
