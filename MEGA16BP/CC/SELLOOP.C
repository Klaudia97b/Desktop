/**********************************************************************/
#include "std.h"
#include "megatyp.h"
#include "megacad.h"
#define MAXPIDS 500
/**********************************************************************/
char edta[32000];// Puffer fr variable Daten
ulong pids[MAXPIDS]; // Platz fr 500 Element ID's
ushort pidnum;  // Z„hler fr die Anzahl der Elemet ID's
/**********************************************************************/
short SelPid(
        void *argptr )
{
    t_entity  *ent;

    ent = argptr;
    pids[pidnum] = ent->id;
    pidnum++;
    if(pidnum == MAXPIDS)
        return(BREAK_LOOP);
    else
        return(CONTINUE_LOOP);
}
/**********************************************************************/
short DoDraw(
        void *ptr )
{
    DrawEntities(pids,pidnum);
}
/**********************************************************************/
short MegaMain(
        char *filename,
        char *args )
{
    t_entity ent;
    t_mat44  ecs;

    // Anzahl auf 0 vorinitialisieren
    pidnum = 0;
    SetFuncText("Farbe invertieren");
    MouseHelp("Element w„hlen","zurck",HLP_INV(0,0,0));
    // Selektionskriterium -> alle Elemente erlaubt
    // ( (1<<E_LINE) || (1<<E_POINT) ) selektiert nur Linien und Punkte
    // Selektionsschleife bei jedem gefundenen Element wird SelPid aufgerufen
    SelectInit(0xffffffff,0xffffffff);
    SelectLoop(SelPid,&ent,edta,&ecs,sizeof(edta),FALSE);
    // alle Elemente, deren ID jetzt in pids steht, invertieren
    Blink(DoDraw,NULL);
    return(0);
}
/**********************************************************************/
