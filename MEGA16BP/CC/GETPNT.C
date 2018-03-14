/**********************************************************************/
#include "std.h"
#include "megatyp.h"
#include "megacad.h"
/********************************************************************/
short MegaMain(
        char *filename,
        char *args )
{
    t_sympnt spt;

    GetPntSymbol(&spt.sym); // Punkteinstellung von MegaCAD lesen

    // Funktionstext und Maushilfe setzen
    SetFuncText("Punkte setzen");
    MouseHelp("Punkt setzen","zurÅck",HLP_INV(0,0,0));
    for( ; ; )
    {
        // Punkt setzen
        if(GetPnt(&spt.pnt,0))
        {
            CreateEntity(E_POINT,NULL,&spt,NULL,NULL); // Punkt erzeugen
            savecount(); // Element in UNDO /REDO Liste eintragen
        }
        else
            break;
    }
    return(0);
}
/********************************************************************/
