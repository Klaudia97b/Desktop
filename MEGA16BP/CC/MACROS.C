/**********************************************************************/
#include "std.h"
#include "megatyp.h"
#include "megacad.h"
/***********************************************************************/
short MegaMain(
        char *filename,
        char *args )
{
    char       buf[255];
    ulong      id;
    t_macro    mac;        // Makro Infos
    t_mkmacro  mkm[10];    // Elmentdaten max 10 Elemente
    t_placemac pmac;       // EinfÅgeoptionen
    t_line     ln;
    t_circle   cir;

    // ein Makro mit Linie und Kreis erzeugen
    // zuerst die Elementdaten einrÑumen
    ln.x1 = 5.0;
    ln.y1 = 5.0;
    ln.x2 = 30.0;
    ln.y2 = 5.0;
    cir.xm = 15.0;
    cir.ym = 5.0;
    cir.rd = 10.0;

    mkm[0].attr = NULL;
    mkm[0].data = &ln;
    mkm[0].type = E_LINE;

    mkm[1].attr = NULL;
    mkm[1].data = &cir;
    mkm[1].type = E_CIRCLE;
    mac.name = "?.MAC";
    mac.numl = 0;

    // Makro erzeugen das Makro hÑngt an der Maus und kann mehrfach
    // eingefÅgt werden.
    id = CreateMacro(&mac,&mkm[0],2,NULL,NULL);
    if(id)
        sprintf(buf,"Makro ID : %ld",id);
    else
        sprintf(buf,"Fehler beim Makro erzeugen !!!");
    Message(buf,"",NULL,NULL,"OK",3);
    return(0);
}
/***********************************************************************/
