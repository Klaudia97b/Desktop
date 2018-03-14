/**********************************************************************/
#include "std.h"
#include "megatyp.h"
#include "megacad.h"
/**********************************************************************/
char edta[32000];// Puffer fÅr variable Daten
/**********************************************************************/
short DelPid(
        void *argptr )
{
    t_entity  *ent;

    ent = argptr;
    if( (ent->attr.col == RED) || (ent->attr.col == BRIGHT_RED) )
        if(DeleteEntity(ent->id))
        return(CONTINUE_LOOP | CALL_SAVECOUNT);
    else
        return(CONTINUE_LOOP);
}
/**********************************************************************/
short MegaMain(
        char *filename,
        char *args )
{
    t_entity ent;
    t_mat44  ecs;

    // Anzahl auf 0 vorinitialisieren
    SetFuncText("Elemente Rot&Hellrot lîschen");
    MouseHelp("Element wÑhlen","zurÅck",HLP_INV(0,0,0));

    // ( (1<<E_LINE) || (1<<E_POINT) ) selektiert nur Linien und Punkte
    // Selektionskriterium -> alle Elemente erlaubt
    SelectInit(0xffffffff,0xffffffff);
    // Selektionsschleife jedes Element mit der Farbe Rot oder Hellrot
    // wird gelîscht
    SelectLoop(DelPid,&ent,edta,&ecs,sizeof(edta),FALSE);

    return(0);
}
/**********************************************************************/
