/**********************************************************************/
#include "std.h"
#include "megatyp.h"
#include "megacad.h"
/**********************************************************************/
struct _data
{
    t_circle cir;
    int      j;
};
/**********************************************************************/
short circle(
        void *argptr )
{
    struct _data *p;

    p = argptr;
    if ( p->j != 0 )
        EraseInv();
    else
        DrawInv(E_CIRCLE,&p->cir,LMODE(1,BRIGHT_WHITE,1),0);
    p->j ^= 1;
    return(0);
}
/**********************************************************************/
short MegaMain(
        char *filename,
        char *args )
{
    struct _data data;

    // Kreisdaten initialisieren
    data.cir.xm = 10.0;
    data.cir.ym = 10.0;
    data.cir.rd = 10.0;
    data.j      = 0;

    // linke Maustaste oder Enter -> Return Wert true
    if ( Blink(circle,&data) )
        Message("Blink OK","",NULL,NULL,"ok",3);

    // rechte Maustaste oder ESC -> Return Wert false
    else
        Message("Blink abgebrochen","",NULL,NULL,"ok",3);
    return(0);
}
/**********************************************************************/
