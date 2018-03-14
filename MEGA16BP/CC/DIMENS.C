/**********************************************************************/
#include "std.h"
#include "megatyp.h"
#include "megacad.h"
/**********************************************************************/
short MegaMain(
        char *filename,
        char *args )
{
    double      y;
    t_entity    ent;
    t_dimension dim;
    t_mat44     ecs;
    char        str[255];

    // Funtionstext und Maushilfe setzen
    SetFuncText("Linie bemassen horizontal");
    MouseHelp("Linie anklicken","Neu ansetzen",HLP_INV(RED,WHITE,0));

    // Element zum Bemassen anklicken hier werden nur Linien erkannt
    while(ClickEntity((1<<E_LINE),0L,&dim.x1,NULL,SNP_NIX,&ent,
                       NULL,0,&ecs,FALSE))
    {
        // Linienstartpunkt = erster Bemassungspunkt
        dim.x1 = ent.data.lin.x1;
        // Startpunkt eventuell umdrehen, damit die Bemassung immer
        // Åber der Linie sein soll
        //y = (ent.data.lin.y1 > ent.data.lin.y2) ? ent.data.lin.y2 : ent.data.lin.y1;
        y = ent.data.lin.y2;
        if(ent.data.lin.y1 > ent.data.lin.y2)
            y = ent.data.lin.y1;
        dim.y1 = y;

        // Linienendpunkt = zweiter Bemassungspunkt
        // aber modifiziert da hier nur horizontale Bemassung
        dim.x2 = ent.data.lin.x2;
        dim.y2 = y;

        // jetzt die Punkte fÅr die Bemassungslinie setzen
        // die Linie wird einfach um 5 Einheiten hochgesetzt
        dim.x3 = dim.x1;
        dim.y3 = dim.y1 + 5;
        dim.x4 = dim.x2;
        dim.y4 = dim.y1 + 5;
        // jetzt den Wert berechnen
        dim.value = fabs(dim.x2 - dim.x1);

        // .. und jetzt den Wert in den Textpuffer einrÑumen
        // die Toleranztexte bleiben hier leer
        dim.str = str;
        PrintDimVal(dim.value,str,"","");
        // jetzt die alle Bemassungswerte von MegaCAD holen
        // sowie die Textbox berechenen und den Bemassungstext
        // entsprechend der voreingestellten Werte plazieren
        // fÅr horizontal Bemassung
        GetDimVal(E_H_DIM,7,&dim);
        // Element speichern
        CreateEntity(E_H_DIM,NULL,&dim,NULL,&ecs);
        // ... und in die UNDO / REDO Liste eintragen
        savecount();
    }
    return(0);
}
/**********************************************************************/
