/**********************************************************************/
#include "std.h"
#include "megatyp.h"
#include "megacad.h"
/***********************************************************************/
t_entinfo inf; // Platz fr die Element Infos
/***********************************************************************/
short MegaMain(
        char *filename,
        char *args )
{
    ushort     id,slen;
    char      buf[255],buf1[255];

    buf[0]  = '\0';
    buf1[0] = '\0';
    // den Infotext besetzen 1. Zeile
    strcpy(inf.info,"Rohr 60 mm");
    // den Infotext besetzen 2. Zeile
    strcpy(inf.info + (strlen(inf.info) + 1),"L„nge 450 mm");
    // Anzahl der Zeilen bekanntgeben
    inf.numl = 2;
    sprintf(buf,"Neue Info mit (%d) Zeilen",inf.numl);
    sprintf(buf1,"[%s] [%s]",inf.info,inf.info + (strlen(inf.info) + 1));
    Message(buf,buf1,NULL,NULL,"OK",3);
    // Info eintragen
    id = StoreInfo(&inf);
    if(id)
    {
        buf[0]  = '\0';
        buf1[0] = '\0';
        // Info wieder einlesen und ausgeben
        if(GetInfo(id,&inf))
        {
            strcpy(buf,inf.info);
            strcpy(buf1,inf.info + strlen(buf) + 1);
        }
    }
    else
        strcpy(buf,"neue Info nicht eingetragen !");

    Message(buf,buf1,NULL,NULL,"OK",3);

    // jetzt eine dritte Zeile an die Info dranh„ngen
    // erst mal die alte L„nge ermitteln
    slen = strlen(inf.info);
    slen += strlen(inf.info + (slen + 1)) + 1;
    strcpy(inf.info + (slen + 1),"Inndendurchmesser 40 mm");
    slen = strlen(inf.info);
    sprintf(buf,"[%s] [%s]",inf.info,inf.info + slen + 1);
    slen += strlen(inf.info + (slen + 1)) + 1;
    sprintf(buf1,"%s -> Zusatzinfo",inf.info + slen + 1);
    Message(buf,buf1,NULL,NULL,"OK",3);

    inf.numl = 3;
    id = ExChangeInfo(&inf);

    if(id)
    {
        buf[0]  = '\0';
        buf1[0] = '\0';
        // Info wieder einlesen und ausgeben
        if(GetInfo(id,&inf))
        {
            slen = strlen(inf.info);
            sprintf(buf,"[%s] [%s]",inf.info,inf.info + slen + 1);
            slen += strlen(inf.info + slen + 1) + 1;
            sprintf(buf1,"[%s] -> erweiterte Info",inf.info + slen + 1);
        }
    }
    else
        strcpy(buf,"erweiterte Info nicht eingetragen !");

    Message(buf,buf1,NULL,NULL,"OK",3);

    return(0);
}
/**********************************************************************/
