/**********************************************************************/
#include "std.h"
#include "megatyp.h"
#include "megacad.h"
/***********************************************************************/
short MegaMain(
        char *filename,
        char *args )
{
    t_gridsets grid;
    char buf[255],buf1[255];
    char einheit[7][10];

    strcpy(einheit[0],"Inch");
    strcpy(einheit[1],"Mm");
    strcpy(einheit[2],"Fuss");
    strcpy(einheit[3],"Cm");
    strcpy(einheit[4],"Yard");
    strcpy(einheit[5],"Meter");
    strcpy(einheit[6],"Faktor");

    // die aktuellen Rastereinstellungen holen
    GetGridSets(&grid);

    if(grid.fDraw == TRUE)
    {
        sprintf(buf,"Raster sichtbar Einheit %s",einheit[grid.iUnit]);
        sprintf(buf1,"Raster wird ausgeschaltet");
        grid.fDraw = FALSE;
    }
    else
    {
        sprintf(buf,"Raster unsichtbar Einheit %s",einheit[grid.iUnit]);
        sprintf(buf1,"Raster wird eingeschaltet");
        grid.fDraw = TRUE;
    }
    Message(buf,buf1,NULL,NULL,"OK",3);

    SetGridSets(&grid);

   return(0);
}
/***********************************************************************/
