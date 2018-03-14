/**********************************************************************/
#include "std.h"
#include "megatyp.h"
#include "megacad.h"
/***********************************************************************/
short MegaMain(
        char *filename,
        char *args )
{
    uchar    layer[256]; // Platz fÅr die Layer Bits
    t_laygrp lay;       // Platz fÅr die Layer Namen
    short    i,but;
    char     buf[255];

    GetLayGrpBits(layer); // die Layereinstellungen holen
    GetLayerNames(&lay); // die Layernamen holen

    for(i = 0 ; i < 256 ; i++)
    {
        if(layer[i] & LAY_ON) // wenn Layer eingeschaltet, Namen anzeigen
        {
            sprintf(buf,"Layer Nummer (%d) eingeschaltet",i);
            but = Message(buf,lay.names[i],"OK",NULL,"ABBRUCH",1);
            if(but == 3)
                break;
        }
    }
    // Layer Nr. 11 - 200 ausschalten
    for(i = 11 ; i <= 200 ; i++)
        layer[i] &= ~LAY_ON;
    Message("Layer 11 - 200 ausgeschaltet","",NULL,NULL,"OK",3);

    // Layer Nr. 1 - 10 neue Namen setzen
    for(i = 1 ; i <= 10 ; i++)
        sprintf(lay.names[i],"Layername : %d.ter Layer",i);
    SetLayerNames(&lay);
    Message("Layer 1 - 10 bekommen neue Namen","Layername : .ter Layer",
            NULL,NULL,"OK",3);

    GetLayerNames(&lay); // die Layernamen holen
    for(i = 0 ; i < 256 ; i++)
    {
        if(layer[i] & LAY_ON) // wenn Layer eingeschaltet, Namen anzeigen
        {
            sprintf(buf,"Layer Nummer (%d) eingeschaltet",i);
            but = Message(buf,lay.names[i],"OK",NULL,"ABBRUCH",1);
            if(but == 3)
                break;
        }
    }
    return(0);
}
/***********************************************************************/
