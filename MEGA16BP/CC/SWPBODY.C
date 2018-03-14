/**********************************************************************/
#include "std.h"
#include "megatyp.h"
#include "megacad.h"
/**********************************************************************/
short MegaMain(
        char *filename,
        char *args )
{
    t_Obj3D   obj;
    t_polypt  ppt[4], ppt_path[3];

    // Standard Koordinatensystem
    t_mat44 ecs =
        {1.0, 0.0, 0.0, 0.0 ,
         0.0, 1.0, 0.0, 0.0 ,
         0.0, 0.0, 1.0, 0.0 ,
         0.0, 0.0, 0.0, 1.0 };

    // Koordinatensystem um 90 ø um die X-Achse gedreht
    t_mat44 lcs =
        {1.0, 0.0, 0.0, 0.0 ,
         0.0, 0.0, -1.0, 0.0 ,
         0.0, 1.0, 0.0, 0.0 ,
         0.0, 0.0, 0.0, 1.0 };

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

    ppt_path[0].mpd = 0.0;
    ppt_path[0].px =  50.0;
    ppt_path[0].py =  10.0;

    ppt_path[1].mpd = 0.0;
    ppt_path[1].px =  50.0;
    ppt_path[1].py =  50.0;

    ppt_path[2].mpd = 0.0;
    ppt_path[2].px =  90.0;
    ppt_path[2].py =  80.0;

    InitObj3D(&obj);

    // Sweepfl„che erstellen
    if ( CreateSweepBody(3,ppt_path,&lcs,4,ppt,&ecs,TRUE,FALSE,&obj) )
    {
        CreateEntity(E_OBJ3D,NULL,&obj,NULL,NULL);
        savecount();
    }

    // und jetzt als SOLID etwas verschoben
    if ( CreateSweepBody(3,ppt_path,&lcs,4,ppt,&ecs,TRUE,TRUE,&obj) )
    {
        ecs.mat[3] = 100.0;
        ecs.mat[7] = 100.0;
        CreateEntity(E_OBJ3D,NULL,&obj,NULL,&ecs);
        savecount();
    }

    FreeObj3D(&obj);
    return(0);
}

/**********************************************************************/
