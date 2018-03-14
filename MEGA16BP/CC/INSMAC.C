/**********************************************************************/
#include "std.h"
#include "megatyp.h"
#include "megacad.h"
/**********************************************************************/
struct _data
{
    t_entity ent;
    short lanz;
    short bganz;
};
/**********************************************************************/
short LpCnt(
            void *argptr)
{
    struct _data *pdta;

    pdta = argptr;
    // bei Linien und Bîgen einfach zÑhlen, wieviel darin sind
    if(pdta->ent.type == E_LINE)
        pdta->lanz++;
    if(pdta->ent.type == E_C_ARC)
        pdta->bganz++;
    return(0);
}
 
/**********************************************************************/
short MegaMain(
        char *filename,
        char *args )
{
    char         buf1[255],
                 buf2[25],
                 mbuf[255];
    struct _data dta;
    ushort       elins;
    t_placemac   pmac;
 
    // Anzahl fÅr Linien und Bîgen initialisieren
    dta.lanz = 0;
    dta.bganz = 0;
 
    // den Textpuffer vorbesetzen
    strcpy(mbuf,"c:\\megawin\\mac\\");
    // Namen des Makros eingeben
    if(StringInput("Makronamen mit Pfad eingeben",mbuf,255))
    {
        // Makro einfÅgen, bei jedem Element wird LpCnt aufgerufen
        // da hier die Elemente nicht verÑndert werden, kann edta NULL sein
        // das Makro wird auf die Koordinate 10/10 eingefÅgt
        pmac.dpx = 10;
        pmac.dpy = 10;
        pmac.flags = FM_TAKE_DPT;
        elins = InsertMacro(mbuf,LpCnt,&dta,NULL,NULL,0,&pmac);
        // elins = Anzahl der eingefÅgten Elemente
        sprintf(buf1,"Anzahl Elemente : %d",elins);
        sprintf(buf2,"Linien : %d Bîgen : %d",dta.lanz,dta.bganz);
        Message(buf1,buf2,NULL,NULL,"OK",3);

        // Jetzt wird das Makro mit einem Drehwinkel von 45¯ an 100,100 eingefÅgt
        pmac.dpx = 100;
        pmac.dpy = 100;
        // phi in rad, nicht in Grad!
        pmac.phi = DEF_PI / 4.0;
        pmac.flags = FM_TAKE_DPT | FM_TAKE_PHI;
        elins = InsertMacro(mbuf,LpCnt,&dta,NULL,NULL,0,&pmac);
    }
    return(0);
}
/**********************************************************************/
