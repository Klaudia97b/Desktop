/**********************************************************************/
#include "std.h"
#include "megatyp.h"
#include "megacad.h"
/********************************************************************/
short MegaMain(
        char *filename,
        char *args )
{
    t_Obj3D  objdata,objcyl,res;
    t_mat44  ecs =
    {
        1.0, 0.0,  0.0,  0.0,
        0.0, 1.0,  0.0,  0.0,
        0.0, 0.0,  1.0,  0.0,
        0.0, 0.0,  0.0,  1.0
    };

    // initialisieren der 3D Datenstrukturen
    InitObj3D(&objdata);
    InitObj3D(&objcyl);
    InitObj3D(&res);

    //erzeugen eines Quaders
    CreateCuboid(100.0,150.0,50.0,NULL,&objdata);

    // jetzt einen Zylinder erzeugen
    CreateCylinder(200.0,10.0,10.0,NULL,&objcyl);

    //den Zylinder vom Quader abziehen
    if(BodySubtract(&objcyl,&objdata,FALSE,FALSE,NULL,&res))
    {
        CreateEntity(E_OBJ3D,NULL,&res,NULL,NULL);
        savecount();
    }

    MegaCMD("RegenAll");
    Message("Zylinder vom Quader abgezogen","",NULL,NULL,"ok",3);

    //den Zylinder und den Quader addieren
    // das Ergebniss etwas versetzen
    ecs.mat[3] = 200.0;
    ecs.mat[7] = 200.0;
    if(BodyUnite(&objcyl,&objdata,FALSE,FALSE,NULL,&res))
    {
        CreateEntity(E_OBJ3D,NULL,&res,NULL,&ecs);
        savecount();
    }

    MegaCMD("AutoZoom");
    MegaCMD("RegenAll");
    Message("Zylinder und Quader addiert","",NULL,NULL,"ok",3);

    // Durchschnitt aus Zylinder und Quader
    // das Ergebniss etwas versetzen
    ecs.mat[3] += 200.0;
    ecs.mat[7] += 200.0;
    if(BodyIntersect(&objcyl,&objdata,FALSE,FALSE,NULL,&res))
    {
        CreateEntity(E_OBJ3D,NULL,&res,NULL,&ecs);
        savecount();
    }

    MegaCMD("AutoZoom");
    MegaCMD("RegenAll");
    Message("Durchschnitt aus Zylinder und Quader","",NULL,NULL,"ok",3);


    //Freigeben der 3D Datenstruktur des Quaders
    FreeObj3D(&objdata);
    FreeObj3D(&objcyl);
    FreeObj3D(&res);

    return(0);
}
/********************************************************************/
