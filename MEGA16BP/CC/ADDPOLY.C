/**********************************************************************/
#include "std.h"
#include "megatyp.h"
#include "megacad.h"

# define MAXPOLYPTS 30  // maximale Anzahl der Polylinienpunkte
/********************************************************************/
/* Dieses Programm erzeugt eine Polyline, die Daten kînnen Åber die */
/* Funktion DlgInput eingegeben werden.                             */
/* Dies Polyline wird einmal in der X/Y Ebene angelegt und einmal   */
/* in der X / Z Ebene.                                              */
/********************************************************************/
static void SetDlg(
                    t_dlgdta *t,
                    char *text,
                    uchar typ,
                    void *val)
{
    strcpy(&t->text[0],text);
    t->type = typ;
    t->val = val;
    return;
}
/********************************************************************/
short MegaMain(
        char *filename,
        char *args )
{
    short mret,dret;
    double px,py,mpd, *pmpd;
    t_dlgdta tg[6]; // Array der Dialogfeldbeschreiber
    t_polyln poly;  // Polylinienstruktur
    t_polypt polypt[MAXPOLYPTS]; // Platz fÅr 30 Polylinepunkte

    // ecs beschreibt die Verschiebung des Koordinatensystemes in die
    // X/Z Ebene
    t_mat44 ecs =
    {
        1.0, 0.0,  0.0,  0.0,
        0.0, 0.0, -1.0,  0.0,
        0.0, 1.0,  0.0,  0.0,
        0.0, 0.0,  0.0,  1.0
    };

    // zuweisen des Pointers fÅr die Polylinepunkte
    poly.ppt = polypt;

    // px, py und num vorinitialisieren
    px = 0.0;
    py = 0.0;
    poly.num = 0;

    // setzen der Dialogfelder
    SetDlg(&tg[0],"LÅcke",DLG_BUT,NULL);
    SetDlg(&tg[1],"Linie",DLG_BUT,NULL);
    SetDlg(&tg[2],"Kreisbg.",DLG_BUT,NULL);
    SetDlg(&tg[3],"X - Wert",DLG_LEN,&px);
    SetDlg(&tg[4],"Y - Wert",DLG_LEN,&py);
    SetDlg(&tg[5],"mpd :",DLG_LEN,&mpd);

    mret = 1;
    while(mret != 0)
    {
        mret = DlgInput(5,"Polylinie",tg);

        if(mret == 1) // LÅcke, mpd auf NULL setzen
            pmpd = NULL;
        else
            pmpd = &mpd;
        if(mret == 2) // Linie, mpd auf 0.0 setzen
            mpd = 0.0;
        if(mret == 3) // Kreisbogen, Scheitelpunkt abfragen
        {
            // Dialog mit nur einem Feld um mpd einzugeben
            dret = DlgInput(1,"Scheitelpunkt angeben",&tg[5]);
            if(dret == 0) // Abbruch, neue Eingabe
                continue;
        }

        if(mret) // nicht zurÅck gewÑhlt, Polylinepunkt hinzufÅgen
        {
            dret = AddPolylnPt(&poly,pmpd,px,py);
            if(dret == 0) // maximale Anzahl von POLYLN_MAX Åberschritten
            {             // darf in diesem Beispiel nicht passieren.
                Message("Anzahl von POLYLN_MAX Åbershritten !","",
                        NULL,NULL,"OK",3);
                mret = 0;
            }
            else
            {
                if(poly.num == MAXPOLYPTS) // max Anzahl Punkte erreicht
                {
                    Message("Die Punktliste ist voll!",
                            "mehr Punkte kînnen nicht eingegeben werden !",
                            NULL,NULL,"OK",3);
                    mret = 0;
                }
            }
        }
    }
    CreateEntity(E_POLYLN,NULL,&poly,NULL,NULL); // Polylinienelement erzeugen
                                                 // X/Y Ebene
    savecount(); // Element in UNDO /REDO Liste eintragen

    CreateEntity(E_POLYLN,NULL,&poly,NULL,&ecs); // Polylinienelement erzeugen
                                                 // X/Z Ebene
    savecount(); // Element in UNDO /REDO Liste eintragen

    return(0);
}
/********************************************************************/
