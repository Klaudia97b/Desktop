/**********************************************************************/
#include "std.h"
#include "megatyp.h"
#include "megacad.h"
/**********************************************************************/
short MegaMain(
        char *filename,
        char *args )
{
    short butret, wayout = FALSE;

    while(wayout == FALSE)
    {
        // zeigt eine Meldung und wertet den gedr…kten Knopf aus.
        butret = Message("Dr…ken Sie Knopf oder Knopf2 oder Knopf 3",
                         "zum Abbrechen klicken Sie bitte au疇rhalb",
                         "Knopf1","Knopf2","Knopf3",3);
        switch(butret)
        {
            case 1:
                    Message("Knopf 1 gedr…kt","",NULL,NULL,"ok",3);
                    break;
            case 2:
                    Message("Knopf 2 gedr…kt","",NULL,NULL,"ok",3);
                    break;
            case 3:
                    Message("Knopf 3 gedr…kt","",NULL,NULL,"ok",3);
                    break;
            default:
                    Message("Au疇rhalb gedr…kt","",NULL,NULL,"ok",3);
                    wayout = TRUE;
                    break;
        }
    }
    return(0);
}
/**********************************************************************/
