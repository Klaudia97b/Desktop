/**********************************************************************/
#include "std.h"
#include "megatyp.h"
#include "megacad.h"
/**********************************************************************/
short MegaMain(
        char *filename,
        char *args )
{
    t_entity  ent;
    double    pnt[2];   // Platz 2D fr den angeklickten Punkt
    double    pnt3d[3]; // Platz frden angeklickten 3D Punkt
    t_attribs *attr;    // Platz fr die ge„nderten Elementattribute
    t_mat44   ecs;      // Platz fr das lokale Koordinatensystem

    // Funktionsname und Maushilfe setzen
    SetFuncText("Farbe invertieren");
    MouseHelp("Linie anklicken","zurck",HLP_INV(0,0,0));

        // Element anklicken, wobei hier nur Linien zul„ssig sind
    while ( ClickEntity(1<<E_LINE,0L,pnt,pnt3d,SNP_NIX,&ent,NULL,0,&ecs,FALSE) )
    {
        // Attribute des Elementes „ndern
        attr = &ent.attr;
        ent.attr.col ^= 0xf;
        ent.attr.col++;
        // Element neu speichern, die r„umliche Lage bleibt erhalten
        ExChangeEntity(&ent,NULL);
        savecount();
    }
    return(0);
}
/**********************************************************************/
