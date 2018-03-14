/**********************************************************************/
#include "std.h"
#include "megatyp.h"
#include "megacad.h"
/**********************************************************************/
#define MAXID 15
ushort Iidnum[MAXID]; // Platz fÅr max. 15 Info IDÔs
short Iid,isinfo;
t_entinfo idata; // Platz fÅr die Element Infos
/***********************************************************************/
/* vergleicht txt1 mit txt2                                            */
/* Besonderheit : wenn tx2 lÑnger als txt1 ist, wird nur bis zur LÑnge */
/* von txt1 verglichen                                                 */
short TxtCmp(
            char txt1[], // erster Vergleichsstring
            char txt2[]) // zweiter Vergleichsstring
{
    short sl1,sl2,i,ret;

    ret = TRUE;
    sl1 = strlen(txt1);
    sl2 = strlen(txt2);

    for(i = 0 ; i < sl1 && i < sl2 ; i++)
    {
        if(txt1[i] != txt2[i])
        {
            ret = FALSE;
            break;
        }
    }
    return(ret);
}
/**********************************************************************/
short ChkInfo(
        void *ptr )
{
    t_entinfo *inf;
    uchar     txt[60];

    inf = ptr;
    // in den Element Infos die EintrÑge suchen, wo in der ersten Zeile
    // die Bezeichnung "Rohr" steht
    strcpy(txt,"Rohr");
    if(TxtCmp(txt,inf->info)) // der Eintrag existiert
    {
        isinfo = TRUE;
        if(Iid < MAXID)
        {
            Iidnum[Iid] = inf->id;
            Iid++;
        }
    }
    return(CONTINUE_LOOP);
}
/**********************************************************************/
short MegaMain(
        char *filename,
        char *args )
{
    short     i;
    char      buf[255],buf1[255];

    Iid = 0; // ZÑhler vorinitialisieren
    isinfo = FALSE; // wenn keine Infos vorhanden, bleibt isinfo FALSE

    InfoLoop(ChkInfo,&idata);
    if(isinfo) // es wurden Infos gefunden
    {
        for( i = 0 ; i < Iid ; i++)
        {
            buf[0]  = '\0';
            buf1[0] = '\0';
            sprintf(buf,"ID : (%d)",Iidnum[i]);
            // Infotext holen und die erste Zeile anzeigen
            if(GetInfo(Iidnum[i],&idata))
                sprintf(buf1,"[%s]",idata.info);
            Message(buf,buf1,NULL,NULL,"OK",3);
        }
    }

    return(0);
}
/**********************************************************************/
