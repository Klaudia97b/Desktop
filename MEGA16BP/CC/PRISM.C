/**********************************************************************/
#include "std.h"
#include "megatyp.h"
#include "megacad.h"
/********************************************************************/
short MegaMain(
        char *filename,
        char *args )
{
    short    mret,dret;
    t_polypt ppt[4];
    t_Obj3D  objdata;
    double vec[3];
    t_mat44 ecs =
    {
        1.0, 0.0,  0.0,  0.0,
        0.0, 1.0,  0.0,  0.0,
        0.0, 0.0,  1.0,  0.0,
        0.0, 0.0,  0.0,  1.0
    };

    vec[0] = 0.0;
    vec[1] = 0.0;
    vec[2] = 1.0;


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

    // initialisieren der 3D Datenstrukturen
    InitObj3D(&objdata);


    // Prismenfl„che erzeugen
    if(CreatePrism(4,ppt,50,vec,FALSE,&ecs,&objdata))
    {
        CreateEntity(E_OBJ3D,NULL,&objdata,NULL,NULL);
        savecount();
    }

    // und jetzt als Solid daneben
    ecs.mat[3] = 50.0;
    ecs.mat[7] = 50.0;
    if(CreatePrism(4,ppt,50,vec,TRUE,&ecs,&objdata))
    {
        CreateEntity(E_OBJ3D,NULL,&objdata,NULL,NULL);
        savecount();
    }

    //Freigeben der 3D Datenstruktur des Quaders
    FreeObj3D(&objdata);

    return(0);
}
/********************************************************************/
