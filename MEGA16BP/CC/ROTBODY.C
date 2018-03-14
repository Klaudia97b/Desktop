/**********************************************************************/
#include "std.h"
#include "megatyp.h"
#include "megacad.h"
/********************************************************************/
short MegaMain(
        char *filename,
        char *args )
{
    t_polypt ppt[4];
    t_Obj3D  objdata;
    double vec[3],angle[2];
    t_mat44 ecs =
    {
        1.0, 0.0,  0.0,  0.0,
        0.0, 1.0,  0.0,  0.0,
        0.0, 0.0,  1.0,  0.0,
        0.0, 0.0,  0.0,  1.0
    };

    vec[0] = 0.0;
    vec[1] = 0.0;
    vec[2] = 20.0;
    vec[3] = 20.0;


    ppt[0].mpd = NULL;
    ppt[0].px  = 10.0;
    ppt[0].py  = 10.0;

    ppt[1].mpd = 0.0;
    ppt[1].px  = 10.0;
    ppt[1].py  = 30.0;

    ppt[2].mpd = 0.0;
    ppt[2].px  = 30.0;
    ppt[2].py  = 10.0;

    ppt[3].mpd = 0.0;
    ppt[3].px  = 10.0;
    ppt[3].py  = 10.0;

    angle[0] = 0.0;
    angle[1] = DEF_PI;

    // initialisieren der 3D Datenstrukturen
    InitObj3D(&objdata);


    // Rotationsk”rper erzeugen
    if(CreateRotBody(4,ppt,vec,angle,FALSE,&ecs,&objdata))
    {
        CreateEntity(E_OBJ3D,NULL,&objdata,NULL,NULL);
        savecount();
    }

    // und jetzt als Solid daneben
    ecs.mat[3] = 50.0;
    ecs.mat[7] = 50.0;
    if(CreateRotBody(4,ppt,vec,angle,FALSE,&ecs,&objdata))
    {
        CreateEntity(E_OBJ3D,NULL,&objdata,NULL,NULL);
        savecount();
    }

    //Freigeben der 3D Datenstruktur des Quaders
    FreeObj3D(&objdata);

    return(0);
}
/********************************************************************/
