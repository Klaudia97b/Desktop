/**********************************************************************/
#include "std.h"
#include "megatyp.h"
#include "megacad.h"

/***********************************************************************/
static void ShowAttr(
                    char      *txt,
                    t_attribs *attr)
{
    char      buf[255],buf1[255];

    sprintf(buf,"%s  Col:%d Style:%d",txt,attr->col,attr->stl);
    sprintf(buf1,"Wid:%d Layer:%d Group:%d Pen:%d",
            attr->wid,attr->lay,attr->grp,attr->pen + 1);
    Message(buf,buf1,NULL,NULL,"OK",3);
    return;
}
/***********************************************************************/
short MegaMain(
        char *filename,
        char *args )
{
    t_attribs attr;
    char      buf[255];

    // aktuellen Attribute fÅr das Element Linie ermitteln
    GetAttributes(E_LINE,&attr);
    ShowAttr("E_LINE",&attr);
    // jetzt die Farbe auf Rot und den Layer auf 100
    attr.col = RED;
    attr.lay = 100;
    // die neuen Attribute setzen
    SetAttributes(E_LINE,&attr);

    // die neuen Atribute fÅr das Element Linie lesen
    GetAttributes(E_LINE,&attr);
    ShowAttr("E_LINE 2",&attr);

    // Attribute fÅr das Element Linie wenn Attributleiste aus
    GetAttributes((E_LINE | 0x80),&attr);
    ShowAttr("E_LINE | 0x80",&attr);

    // welche Attribute in der Attributleiste sind aktiv ?
    GetAttributes(0xf0,&attr);
    if(attr.iID & 0x01) // grp
        strcpy(buf,"grp ");
    if(attr.iID & 0x02) // lay
        strcpy(buf + strlen(buf),"lay ");
    if(attr.iID & 0x04) // pen
        strcpy(buf + strlen(buf),"pen ");
    if(attr.iID & 0x08) // stl
        strcpy(buf + strlen(buf),"stl ");
    if(attr.iID & 0x10) // col
        strcpy(buf + strlen(buf),"col ");
    if(attr.iID & 0x20) // wid
        strcpy(buf + strlen(buf),"wid ");
    ShowAttr(buf,&attr);

    return(0);
}
/***********************************************************************/
