/**********************************************************************/
#include "std.h"
#include "megatyp.h"
#include "megacad.h"
/***********************************************************************/
char edta[32000];// Puffer fÅr variable Daten
short lcnt;
/***********************************************************************/
short ModEl(void *para)
{
    t_entity *ent;

    ent = para;

    if(ent->type == E_LINE)
    {
        lcnt++;
        ent->attr.col = BRIGHT_RED;
        ExChangeEntity(ent,NULL);
    }

    return(CONTINUE_LOOP);
}
/***********************************************************************/
short MegaMain(
        char *filename,
        char *args )
{
    char       buf[255];
    ulong      id;
    t_entity   ent;

    lcnt = 0;
    // Åber alle eingefÅgten Makros laufen, bei jeder Linie
    // die Farbe auf Hellrot und den linienzÑhler um 1 hochzÑhlen
    MacroLoop((1<<E_LINE),0L,0L,ModEl,&ent,edta,NULL,sizeof(edta));
    sprintf(buf,"Linien : %d",lcnt);
    Message(buf,"",NULL,NULL,"OK",3);
    return(0);
}
/***********************************************************************/
