/**********************************************************************/
#define SEEK_CUR 1
#define SEEK_END 2
#define SEEK_SET 0

#include "std.h"
#include "megatyp.h"
#include "megacad.h"
/**********************************************************************/
static short SeekMess(short cwritten,short pos,short fh)
{
    long fpos;
    char buf1[255];
    if( ! cwritten)
    {
        fpos = ML_Tell(fh);
        sprintf(buf1,"Dateiposition : %ld Pos %d",fpos,pos);
        Message("ML_Seek OK",buf1,NULL,NULL,"OK",3);
        return(FALSE);
    }
    else
    {
        sprintf(buf1,"Dateiposition : %ld Pos %d",fpos,pos);
        Message("ML_Seek Fehler",buf1,NULL,NULL,"OK",3);
        ML_Close(fh);
        return(TRUE);
    }
}
/**********************************************************************/
short MegaMain(
        char *filename,
        char *args )
{
    short fh, cwritten;
    long fpos;
    uint uread;
    char buf[51], buf1[51], *pbuf;

    // Datei ”ffnen zum Schreiben und Lesen im Textmodus
    fh = ML_Open("dummy.txt",ML_WRITE | ML_PLUS | ML_TEXT);

    // Handle anzeigen
    sprintf(buf1,"%d",fh);
    Message("Dateihandle :",buf1,NULL,NULL,"OK",3);

    // mit ML_Puts einen Text schreiben
    strcpy(buf,"Werner");
    cwritten = ML_Puts(buf,fh);
    sprintf(buf1,"geschriebene Zeichen : %d",cwritten);
    Message("ML_Puts",buf1,NULL,NULL,"OK",3);

    // mit ML_Tell die Dateiposition holen
    fpos = ML_Tell(fh);
    sprintf(buf1,"Dateiposition : %ld",fpos);
    Message("ML_Tell",buf1,NULL,NULL,"OK",3);

    // Datei wieder auf Anfang
    ML_Rewind(fh);
    fpos = ML_Tell(fh);
    sprintf(buf1,"Dateiposition : %ld",fpos);
    Message("ML_Rewind",buf1,NULL,NULL,"OK",3);

    // mit ML_Gets den Text wieder einlesen
    pbuf = ML_Gets(buf,20,fh);
    sprintf(buf1,"gel : (%s) ret. Pointer : (%s)",buf,pbuf);
    Message("ML_Gets",buf1,NULL,NULL,"OK",3);

    // 2 Zeichen vor Dateiende positionieren
    fpos = ML_Tell(fh);
    sprintf(buf1,"Dateiposition vor ML_Seek : %ld",fpos);
    Message("ML_Seek",buf1,NULL,NULL,"OK",3);

    cwritten = ML_Seek(fh,(-2L),SEEK_END);
    if(SeekMess(cwritten,1,fh))
        return;

    // wieder an das Dateiende gehen
    cwritten = ML_Seek(fh,(0L),SEEK_END);
    if(SeekMess(cwritten,2,fh))
        return;

    // mit ML_Putc 1 Zeichen wegschreiben
    cwritten = ML_Putc(fh,'a');
    sprintf(buf1,"'a' geschrieben  Ret. Zeichen : %c",cwritten);
    Message("ML_Putc",buf1,NULL,NULL,"OK",3);

    // mit ML_Getc das erste Zeichen der Datei lesen
    ML_Rewind(fh);
    cwritten = ML_Getc(fh);
    sprintf(buf1,"Zeichen muá 'W' sein. Ret. Zeichen : %c",cwritten);
    Message("ML_Getc",buf1,NULL,NULL,"OK",3);

    // wieder an das Dateiende gehen
    cwritten = ML_Seek(fh,(0L),SEEK_END);
    if(SeekMess(cwritten,3,fh))
        return;

    fpos = ML_Tell(fh);
    // mit ML_Write einen String mit 10 Zeichen rausschreiben
    strcpy(buf,"HUGOvomORT");
    cwritten = ML_Write(buf,10,fh);
    sprintf(buf1,"%s geschrieben geschr.Zeichen : %d",buf,cwritten);
    Message("ML_Write",buf1,NULL,NULL,"OK",3);

    // wieder auf den ANfang des neuen Textes positionieren.
    cwritten = ML_Seek(fh,fpos,SEEK_SET);
    if(SeekMess(0,4,fh))
        return;
    // mit ML_Read den Text einlesen, aber nur 8 Zeichen
    cwritten = ML_Read(buf,8,fh);
    buf[cwritten] = '\0'; // NULL terminieren, da ML_Read das nicht macht
    sprintf(buf1,"Text :[%s] Ret:(%d)",buf,cwritten);
    Message("ML_Read",buf1,NULL,NULL,"OK",3);

    // wieder an das Dateiende gehen
    cwritten = ML_Seek(fh,(0L),SEEK_END);
    if(SeekMess(cwritten,5,fh))
        return;

    // mit ML_Printf die aktuelle Dateipos. rausschreiben
    ML_Printf(fh,"%s : %ld","akt.Position",ML_Tell(fh));

    // Datei wieder schlieáen
    ML_Close(fh);

    return(0);
}
/**********************************************************************/
