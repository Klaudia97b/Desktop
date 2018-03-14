/**********************************************************************/
#include "std.h"
#include "megatyp.h"
#include "megacad.h"
/***********************************************************************/
char edta[32000];// Puffer fÅr variable Daten
/***********************************************************************/
short MegaMain(
        char *filename,
        char *args )
{
    char       buf[255];
    t_point    pnt;
    t_entity   ent;


    // Funktionsnamen setzen
    SetFuncText("DB Info zeigen");
    // solange Makros anklicken bis mit rechter Taste abgebrochen wird
    while(ClickMacro(&pnt,&ent,edta,sizeof(edta)))
    {
        // die erste Zeile der DB Info und den Makronamen anzeigen
        // wenn vorhanden
        if(ent.data.mac.numl)
            Message(ent.data.mac.name,ent.data.mac.info,NULL,NULL,"OK",3);
        else
        {
            Message(ent.data.mac.name,
                    "keine DB Infos ! Makro wird gelîscht !",NULL,NULL,"OK",3);
            // und das Makro jetzt lîschen
            DeleteMacro(ent.id);
        }
    }
    return(0);
}
/***********************************************************************/
