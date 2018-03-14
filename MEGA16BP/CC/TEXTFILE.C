/**********************************************************************/
#include "std.h"
#include "megatyp.h"
#include "megacad.h"
/**********************************************************************/
char txtbuf[5000];
/**********************************************************************/
short MegaMain(
        char *filename,
        char *args )
{
    char  buf[255],lbuf[100];
    short linenum,linecnt = 0,butret = 1, stroffset = 0;

    // die Datei strings.txt wird eingelesen
    linenum = ReadTxtFile("strings.txt",txtbuf,5000);
    while( (linecnt < linenum) && (butret != 3) )
    {
        linecnt++;
        sprintf(lbuf,"Zeile : %d",linecnt);
        strcpy(buf,txtbuf + stroffset);
        stroffset += (strlen(buf) + 1);
        butret = Message(lbuf,buf,"OK",NULL,"ABBRUCH",1);
    }
    return(0);
}
/**********************************************************************/
