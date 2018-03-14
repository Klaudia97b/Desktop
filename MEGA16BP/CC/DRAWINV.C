/**********************************************************************/
#include "std.h"
#include "megatyp.h"
#include "megacad.h"
/**********************************************************************/
short MrkCir(
        void *argptr )
{
    t_circle *p;

    p = argptr;
    // der Kreis wird in weiá gezeichnet
    DrawInv(E_CIRCLE,p,LMODE(0,BRIGHT_WHITE,0),E_CIRCLE);
    return(0);
}
/**********************************************************************/
short MegaMain(
        char *filename,
        char *args )
{
    t_circle c1;
    t_dlgdta dlg;

    // Radius vorbelegen
    c1.rd = 5.0;

    // Dialogstruktur belegen
    strcpy(dlg.text,"Radius :");
    dlg.type = DLG_LEN;
    dlg.val = &c1.rd;

    // den Radius vom Anwender eingeben lassen
    while ( DlgInput(1,"Kreis",&dlg) )
    {
        for ( ; ; )
        {
            // Funtionstext und Maushilfe setzen
            SetFuncText("Kreise mit Radius");
            MouseHelp("Mittelpunkt","Neu ansetzen",HLP_INV(RED,WHITE,0));
            // Punkt holen w„hren die Maus bewgt wird, h„ngt der Kreis am
            // Mauscursor (MrkCir).
            if ( GetPntInv(&c1.xm,0,MrkCir,&c1) )
            {
                // Hier wird der Kreis gespeichert, mit den eventuell
                // eingeschalteten Mehrfachelementen
                StoreMultiple(&c1.xm,E_CIRCLE | DO_SAVCNT);
            }
            else
                break;
        }
    }
    return(0);
}
/**********************************************************************/
