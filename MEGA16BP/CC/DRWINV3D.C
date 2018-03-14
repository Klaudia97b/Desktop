/**********************************************************************/
#include "std.h"
#include "megatyp.h"
#include "megacad.h"

/********************************************************************/
/* einen Zylinder erzeugen und mit der Maus in der aktuellen        */
/* Arbeitsebene plazieren.                                          */
/********************************************************************/
typedef struct _data
{
    double       pkt[3];
    t_DrawInvObj drwobj;
    t_mat44      lcs;
} data;
/********************************************************************/
short DrwObj(
             void *argptr )
{
    data *ptr;

    ptr = argptr;

    ptr->drwobj.pnt  = ptr->pkt;
    ptr->lcs.mat[3]  = ptr->pkt[0];
    ptr->lcs.mat[7]  = ptr->pkt[1];
    ptr->lcs.mat[11] = ptr->pkt[2] + 100.0;
    //ptr->lcs.mat[11] = ptr->pkt[2];

    DrawInvObj3D(&ptr->drwobj,LMODE(0,0,0),E_OBJ3D,&ptr->lcs);
    return(0);
}

/********************************************************************/
short MegaMain(
        char *filename,
        char *args )
{
    t_Obj3D  objcyl;
    data     dta;
    t_mat44  ecs1,ecs2,mat;
    /*
    t_mat44 mat =
    {1.0, 0.0, 0.0, 0.0 ,
     0.0, 1.0, 0.0, 0.0 ,
     0.0, 0.0, 1.0, 0.0 ,
     0.0, 0.0, 0.0, 1.0 };
    */



    // initialisieren der 3D Datenstrukturen
    InitObj3D(&objcyl);

    GetUcs(&mat);

    dta.lcs = mat;

    // den Zylinder erzeugen
    CreateCylinder(200.0,10.0,10.0,NULL,&objcyl);

    // initialisieren der DrawInv Struktur
    BegDrawInvObj3D(&objcyl,&dta.drwobj);

    while(GetPntInv3D(dta.pkt,0,DrwObj,&dta))
    {
        GetBodyTransform(&objcyl,&ecs1);
        MatSolve(&ecs1,&ecs2,&dta.lcs);
        CreateEntity(E_OBJ3D,NULL,&objcyl,NULL,&ecs2);
        savecount();
    }

    // Freigeben derDrawInv Struktur
    EndDrawInvObj3D(&dta.drwobj);
    //Freigeben der 3D Datenstruktur
    FreeObj3D(&objcyl);

    return(0);
}
/********************************************************************/
