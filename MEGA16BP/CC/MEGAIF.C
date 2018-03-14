/**********************************************************************/

#include "std.h"
#include "megatyp.h"
#include "megacad.h"
#include "megapar.h"

/**********************************************************************/

typedef ulong (_far _pascal _export *t_MegaCadIF)(t_MegaPars _far*,ulong,uint);

typedef union
{
    struct
    {
        t_MegaCadIF fnIF;
        ulong       para;
    } tp;
    struct
    {
        char        _far *file;
        char        _far *args;
    } sm;
    struct
    {
        tCallBack   func;
        void        _far *data;
    } cb;
    struct
    {
        uint        reason;
        ulong       lParam;
    } nf;
} t_para;

#define MI_CALLBACK     1
#define MI_GETVERSION   2
#define MI_TAKEPARA     3
#define MI_STARTMAIN    4
#define MI_NOTIFICATION 5

/**********************************************************************/

static ulong _far _pascal IF_Dummy(
        t_MegaPars _far *pars,
        ulong      megaptr,
        uint       funcnum )
{
    if ( pars || megaptr || funcnum )
        return(0L);
    return(0L);
}

/**********************************************************************/

static t_MegaCadIF MegaCAD_IF  = IF_Dummy;
static ulong       MegaCAD_ptr = 0;

#ifdef _WIN32
    __declspec(dllexport) short __stdcall MegaCAD_Entry();
#endif

/**********************************************************************/
/* This function is the entry point that MegaCAD searches for, when   */
/* having loaded the DLL.                                             */
/**********************************************************************/

short _far _pascal _export MegaCAD_Entry(
        uint   fCode,
        t_para *par )
{
    static char mFile[256];
    static char mArgs[256];

    switch ( fCode )
    {
        case MI_CALLBACK   :
            // call the 'tCallBack' function with the given data pointer;
            // this indirect way assures that only this function has to
            // be '_export', not all the callback functions within the DLL.
            return( par->cb.func(par->cb.data) );

        case MI_GETVERSION :
            // return the version number of the MegaCAD interface
            // the number must match the number of the MegaCAD .EXE
            return( MI_VERSION );

        case MI_TAKEPARA   :
            // save the MegaCAD entry function and parameter
            MegaCAD_IF  = par->tp.fnIF;
            MegaCAD_ptr = par->tp.para;
            return(1);

        case MI_STARTMAIN  :
            // call the 'MegaMain()' function of the DLL
            par->sm.file = strcpy(mFile,par->sm.file);
            if ( par->sm.args )
                par->sm.args = strcpy(mArgs,par->sm.args);
            return( MegaMain(par->sm.file,par->sm.args) );

    #if defined ( MEGA_NOTIFY )
        case MI_NOTIFICATION :
            // call the 'MegaNotify()' function of the DLL
            return( MegaNotify(par->nf.reason,par->nf.lParam) );
    #endif

    }
    return(-1);
}

/**********************************************************************/
/* Local function, that calls the MegaCAD entry function.             */
/**********************************************************************/

#if _MSC_VER >= 700 && _MSC_VER <= 800
    #define _pSTACK _based(_segname("_STACK"))
#else
    #define _pSTACK
#endif

static ulong _near _fastcall CallMegaCAD(
        t_MegaPars _pSTACK *params,
        uint       funcnum )
{
    return( MegaCAD_IF(params,MegaCAD_ptr,funcnum) );
}

/**********************************************************************/
#if defined ( _WIN32 )
/**********************************************************************/
/* In 32 bit DLL's there has to be an extra _matherr function!!!      */
/* Especially 'atan2()' would produce floating point errors with two  */
/* identical points.                                                  */
/**********************************************************************/

int _matherr(
        struct _exception *err )
{
    err->retval = 0.0;
    return(1);
}

/**********************************************************************/
#endif   // _WIN32
/**********************************************************************/
/*--------------------------------------------------------------------*/
/**********************************************************************/
/* Function codes.                                                    */
/**********************************************************************/

#define GET_PNT_INV            1
#define DRAW_INV               2
#define DLG_INPUT              3
#define GET_FILENAME           4
#define STORE_MULTIPLE         5
#define MEGA_CMD               6
#define MESSAGE                7
#define MOUSE_HELP             8
#define GET_PNT                9
#define SAVECOUNT             10
#define SET_FUNC_TEXT         11
#define CREATE_ENTITY         12
#define GET_TEXT_VAL          13
#define READ_TXT_FILE         14
#define ADD_POLYLN_PT         15
#define ERASE_INV             16
#define GET_DIM_VAL           17
#define PRINT_DIM_VAL         18
#define CLICK_ENTITY          19
#define EX_CHANGE_ENTITY      20
#define BLINK                 21
#define ENTITY_LOOP           22
#define DRAW_ENTITIES         23
#define STRING_INPUT          24
#define SELECT_INIT           25
#define SELECT_LOOP           26
#define INSERT_MACRO          27
#define CALC_PATTERN          28
#define DELETE_ENTITY         29
#define GET_ENTITY            30
#define SET_INC_PNT           31
#define INFO_LOOP             32
#define GET_INFO              33
#define STORE_INFO            34
#define EX_CHANGE_INFO        35
#define GET_ATTRIBUTES        36
#define GET_LAY_GRP_BITS      37
#define GET_LAYER_NAMES       38
#define GET_GROUP_NAMES       39
#define GET_GRID_SETS         40
#define SET_ATTRIBUTES        41
#define SET_LAY_GRP_BITS      42
#define SET_LAYER_NAMES       43
#define SET_GROUP_NAMES       44
#define SET_GRID_SETS         45
#define GET_CURRENT_FILE      46
#define CREATE_MACRO          47
#define MACRO_LOOP            48
#define CLICK_MACRO           49
#define ENTITY_LEN            50
#define PART_LIST             51
#define GET_PATTERN_VAL       52
#define GET_EXPRESSION        53
#define DELETE_MACRO          54
#define GET_MACRO_INFO        55
#define SET_MACRO_INFO        56
#define GET_PNT_SYMBOL        57
#define RESET_SAVECOUNT       58
#define DO_ZOOM               59
#define GET_ZOOM              60
#define GET_APPL_ID           61
#define GET_APPL_NAME         62
#define SELECT_ENTITIES       63
#define SET_HELP_FUNC         64
#define WRITE_POLY_BMP        65
#define GET_ENT_PTR           66
#define SET_ENT_PTR           67
#define SAVE_TO_PRT           68
#define FIND_POLY_LINE        69
#define SAVE_CURRENT_FILE     70
#define GET_MACRO_POS         71
#define ENTITY_LOOP_APP       72
#define RUN_FUNCTION          73
#define SET_CHAR_SET          74
#define DLL_CAN_UNLOAD        75
#define IS_MACRO_EXCLUSIVE    76
#define GET_PNT_INV3D        300
#define GET_PNT3D            301
#define DRAW_INV3D           302
#define STORE_MULTIPLE3D     303
#define CREATE_MACRO3D       304
#define SET_INC_PNT3D        305
#define GET_UCS              306
#define SET_UCS              307
#define INIT_OBJ3D           308
#define FREE_OBJ3D           309
#define CREATE_CUBOID        310
#define CREATE_CYLINDER      311
#define CREATE_CONE          312
#define CREATE_SPHERE        313
#define CREATE_TORUS         314
#define BODY_UNITE           315
#define BODY_SUBTRACT        316
#define BODY_INTERSECT       317
#define PLANAR_FACE          318
#define CREATE_LIN3D         319
#define CREATE_PRISM         320
#define CREATE_ROT_BODY      321
#define CREATE_SWEEP_BODY    322
#define PNT3DTO_PNT2D        323
#define PNT2DTO_PNT3D        324
#define HIDDEN_LINE          325
#define HIDDEN_LINE_MAC      326
#define HIDDEN_LINE2DSEG     327
#define GET_AKT_PROJ_PARA    328
#define BEG_DRAW_INV_OBJ3D   329
#define END_DRAW_INV_OBJ3D   330
#define DRAW_INV_OBJ3D       331
#define MAT_SUPERPOS         332
#define GET_BODY_TRANSFORM   333
#define MAT_SOLVE            334
#define PNT_NET_INTP         335
#define SKIN_WIRES           336
#define MAKE_CYLINDER_FACE   337
#define MAKE_CONE_FACE       338
#define MAKE_TORUS_FACE      339
#define MAKE_SPHERE_FACE     340
#define PLANE_TO_ECS         341
#define POINTS_TO_ECS        342
#define CHECK_MAT            343
#define PNT2DTO_PNT2D        344
#define GET_BODY_GRAV        345
#define PNT3DTO_PNT3D        346
#define MACRO_POS            347
#define CUT_BODY_PLANE       348
#define OBJ_TO_IGS           349
#define CURV_INTRS           350
#define OFFSET_FACE          351
#define GET_BGRAV_VOL        352
#define UPDATE2DVIEWS        353
#define ADF_SIZE             354
#define BODY_TO_ADF          355
#define ADF_TO_BODY          356
#define CUT_ELEM             357
#define SET_AKT_PROJ_PARA    358
#define PLANE_NORMAL         359
#define POINTS_TO_FACE       360
#define FACE_TO_PPT_SIZE     361
#define FACE_TO_PPT          362
#define TRAVERSE_BODY        363
#define SET_BODY_TRANSFORM   364
#define SET_MOD2D            365
#define PNT3DTO_FACE         366
#define COUNT_LUMPS          367
#define SPLIT_BODIES         368
#define IS_PLANAR_FACE       369
#define GET_MOD2D            370
#define SET0UCS              371
#define GET_SELECT_MODE      372
#define ADD_ENT_TO_MAC       373

/**********************************************************************/
/* The functions of the MegaCAD interface.                            */
/**********************************************************************/

short GetPntInv(                 // get point and draw something with mouse move
        double       *pkt,       // point to be filled in
        short        setinc,     // incremental point to be set ?
        tCallBack    func,       // callback function
        void         *para)      // data pointer for callback function
{
    t_MegaPars params;

    params.m_GetPntInv.pkt    = pkt   ;
    params.m_GetPntInv.setinc = setinc;
    params.m_GetPntInv.func   = func  ;
    params.m_GetPntInv.para   = para  ;

    return( (short) CallMegaCAD(&params,GET_PNT_INV) );
}

/**********************************************************************/

void DrawInv(                    // draw and save a temporary object
        ushort       type,       // type of entity to be drawn
        void         *ptr,       // data of entity
        ushort       lmode,      // line attributes (see LMODE)
        ushort       atype)      // type to get attributes from
{
    t_MegaPars params;

    params.m_DrawInv.type  = type ;
    params.m_DrawInv.ptr   = ptr  ;
    params.m_DrawInv.lmode = lmode;
    params.m_DrawInv.atype = atype;

    CallMegaCAD(&params,DRAW_INV);
}

/**********************************************************************/

short DlgInput(                  // input some values by dialog
        ushort       num,        // number of fields (1 - 16)
        char         *title,     // title string
        t_dlgdta     *dta)       // array of field descriptors
{
    t_MegaPars params;

    params.m_DlgInput.num   = num  ;
    params.m_DlgInput.title = title;
    params.m_DlgInput.dta   = dta  ;

    return( (short) CallMegaCAD(&params,DLG_INPUT) );
}

/**********************************************************************/

short GetFilename(               // let the user select a filename
        char         *title,     // title string
        char         *fname)     // filename; must be initialized with path
{
    t_MegaPars params;

    params.m_GetFilename.title = title;
    params.m_GetFilename.fname = fname;

    return( (short) CallMegaCAD(&params,GET_FILENAME) );
}

/**********************************************************************/

void StoreMultiple(              // store an entity (maybe multiple)
        double       *data,      // entity data
        ushort       type)       // entity type (may be or'ed with DO_SAVCNT)
{
    t_MegaPars params;

    params.m_StoreMultiple.data = data;
    params.m_StoreMultiple.type = type;

    CallMegaCAD(&params,STORE_MULTIPLE);
}

/**********************************************************************/

void MegaCMD(                    // call MegaCAD command
        char         *cmd)       // command string (+ arguments)
{
    t_MegaPars params;

    params.m_MegaCMD.cmd = cmd;

    CallMegaCAD(&params,MEGA_CMD);
}

/**********************************************************************/

short Message(                   // message box
        char         *str1,      // 1st line of text
        char         *str2,      // 2nd line of text
        char         *but1,      // 1st button (may be NULL)
        char         *but2,      // 2nd button (may be NULL)
        char         *but3,      // 3rd button
        short        defbut)     // number of default button (1-3)
{
    t_MegaPars params;

    params.m_Message.str1   = str1  ;
    params.m_Message.str2   = str2  ;
    params.m_Message.but1   = but1  ;
    params.m_Message.but2   = but2  ;
    params.m_Message.but3   = but3  ;
    params.m_Message.defbut = defbut;

    return( (short) CallMegaCAD(&params,MESSAGE) );
}

/**********************************************************************/

void MouseHelp(                  // help text for mouse buttons
        char         *str1,      // help text for left mouse button
        char         *str2,      // help text for right mouse button
        ushort       inv)        // colour (beep) for 1st text (see HLP_INV)
{
    t_MegaPars params;

    params.m_MouseHelp.str1 = str1;
    params.m_MouseHelp.str2 = str2;
    params.m_MouseHelp.inv  = inv ;

    CallMegaCAD(&params,MOUSE_HELP);
}

/**********************************************************************/

short GetPnt(                    // get point
        double       *pkt,       // point to be filled in
        short        setinc)     // incremental point to be set ?
{
    t_MegaPars params;

    params.m_GetPnt.pkt    = pkt   ;
    params.m_GetPnt.setinc = setinc;

    return( (short) CallMegaCAD(&params,GET_PNT) );
}

/**********************************************************************/

void savecount(                  // end of operation
        void )                   // must be called after creation of entities
{
    t_MegaPars params;

    CallMegaCAD(&params,SAVECOUNT);
}

/**********************************************************************/

void SetFuncText(                // set name of current function
        char         *text)      // function text
{
    t_MegaPars params;

    params.m_SetFuncText.text = text;

    CallMegaCAD(&params,SET_FUNC_TEXT);
}

/**********************************************************************/

ulong CreateEntity(              // store an entity (not multiple), returns ID
        ushort       type,       // entity type
        t_attribs    *attr,      // entity attributes (may be NULL)
        void         *data,      // entity data
        t_applic     *appl,      // application data (may be NULL)
        t_mat44      *ecs)       // entity coordinate system
{
    t_MegaPars params;

    params.m_CreateEntity.type = type;
    params.m_CreateEntity.attr = attr;
    params.m_CreateEntity.data = data;
    params.m_CreateEntity.appl = appl;
    params.m_CreateEntity.ecs  = ecs ;

    return( (ulong) CallMegaCAD(&params,CREATE_ENTITY) );
}

/**********************************************************************/

void GetTextVal(                 // retrieve text attributes
        ushort       type,       // line or block
        ushort       init,       // initialize (or just calculate box)
        t_text       *txt)       // text data
{
    t_MegaPars params;

    params.m_GetTextVal.type = type;
    params.m_GetTextVal.init = init;
    params.m_GetTextVal.txt  = txt ;

    CallMegaCAD(&params,GET_TEXT_VAL);
}

/**********************************************************************/

ushort ReadTxtFile(              // read in a text file
        char         *fname,     // filename
        char         *buf,       // buffer to be filled in
        uint         bufsiz)     // size of buffer
{
    t_MegaPars params;

    params.m_ReadTxtFile.fname  = fname ;
    params.m_ReadTxtFile.buf    = buf   ;
    params.m_ReadTxtFile.bufsiz = bufsiz;

    return( (ushort) CallMegaCAD(&params,READ_TXT_FILE) );
}

/**********************************************************************/

ushort AddPolylnPt(              // add a polyline point
        t_polyln     *polyln,    // polyline structure
        double       *mpd,       // may be NULL
        double       px,         // x-coordinate of point
        double       py)         // y-coordinate of point
{
    t_MegaPars params;

    params.m_AddPolylnPt.polyln = polyln;
    params.m_AddPolylnPt.mpd    = mpd   ;
    params.m_AddPolylnPt.px     = px    ;
    params.m_AddPolylnPt.py     = py    ;

    return( (ushort) CallMegaCAD(&params,ADD_POLYLN_PT) );
}

/**********************************************************************/

void EraseInv(                   // delete temporary objects
        void ) 
{
    t_MegaPars params;

    CallMegaCAD(&params,ERASE_INV);
}

/**********************************************************************/

void GetDimVal(                  // retrieve dimension attributes
        ushort       type,       // type of dimension
        ushort       init,       // initialize (or just calculate box)
        t_dimension  *dim)       // dimension data
{
    t_MegaPars params;

    params.m_GetDimVal.type = type;
    params.m_GetDimVal.init = init;
    params.m_GetDimVal.dim  = dim ;

    CallMegaCAD(&params,GET_DIM_VAL);
}

/**********************************************************************/

void PrintDimVal(                // print dimension text
        double       value,      // measured value
        char         *str,       // string buffer to fill
        char         *tol1,      // tolerance string 1
        char         *tol2)      // tolerance string 2
{
    t_MegaPars params;

    params.m_PrintDimVal.value = value;
    params.m_PrintDimVal.str   = str  ;
    params.m_PrintDimVal.tol1  = tol1 ;
    params.m_PrintDimVal.tol2  = tol2 ;

    CallMegaCAD(&params,PRINT_DIM_VAL);
}

/**********************************************************************/

short ClickEntity(               // let the user click a single entity
        ulong        filter1,    // allowed entity types
        ulong        filter2,    // allowed entity types
        double       *pnt,       // point where entity was clicked
        double       *pnt3D,     // 3D-point
        int          snp_mod,    // Snap-Mode SNP_...
        t_entity     *ent,       // entity data to be filled in
        void         *edta,      // data ptr of variable length entities
        ushort       esiz,       // size of data buffer
        t_mat44      *ecs,       // entity coordinate system
        uchar        fModify)    // entity to be modified?
{
    t_MegaPars params;

    params.m_ClickEntity.filter1 = filter1;
    params.m_ClickEntity.filter2 = filter2;
    params.m_ClickEntity.pnt     = pnt    ;
    params.m_ClickEntity.pnt3D   = pnt3D  ;
    params.m_ClickEntity.snp_mod = snp_mod;
    params.m_ClickEntity.ent     = ent    ;
    params.m_ClickEntity.edta    = edta   ;
    params.m_ClickEntity.esiz    = esiz   ;
    params.m_ClickEntity.ecs     = ecs    ;
    params.m_ClickEntity.fModify = fModify;

    return( (short) CallMegaCAD(&params,CLICK_ENTITY) );
}

/**********************************************************************/

ulong ExChangeEntity(            // exchange an entity, returns new ID
        t_entity     *ent,       // new entity data, old id
        t_mat44      *ecs)       // entity coordinate system
{
    t_MegaPars params;

    params.m_ExChangeEntity.ent = ent;
    params.m_ExChangeEntity.ecs = ecs;

    return( (ulong) CallMegaCAD(&params,EX_CHANGE_ENTITY) );
}

/**********************************************************************/

short Blink(                     // draw something blinking
        tCallBack    func,       // callback function
        void         *para)      // data pointer for callback function
{
    t_MegaPars params;

    params.m_Blink.func = func;
    params.m_Blink.para = para;

    return( (short) CallMegaCAD(&params,BLINK) );
}

/**********************************************************************/

void EntityLoop(                 // loop through all entities
        ulong        filter1,    // allowed entity types
        ulong        filter2,    // allowed entity types
        tCallBack    func,       // callback function
        void         *para,      // data pointer for callback function
        void         *edta,      // data ptr of variable length entities
        t_mat44      *ecs,       // entity coordinate system
        ushort       esiz)       // size of data buffer
{
    t_MegaPars params;

    params.m_EntityLoop.filter1 = filter1;
    params.m_EntityLoop.filter2 = filter2;
    params.m_EntityLoop.func    = func   ;
    params.m_EntityLoop.para    = para   ;
    params.m_EntityLoop.edta    = edta   ;
    params.m_EntityLoop.ecs     = ecs    ;
    params.m_EntityLoop.esiz    = esiz   ;

    CallMegaCAD(&params,ENTITY_LOOP);
}

/**********************************************************************/

void DrawEntities(               // draw array of entity-id's
        ulong        *pid,       // array of entity-id's
        ushort       num)        // number of id's
{
    t_MegaPars params;

    params.m_DrawEntities.pid = pid;
    params.m_DrawEntities.num = num;

    CallMegaCAD(&params,DRAW_ENTITIES);
}

/**********************************************************************/

short StringInput(               // input a line of text
        char         *title,     // title string
        char         *buf,       // string buffer to be filled in
        ushort       buflen)     // size of buffer
{
    t_MegaPars params;

    params.m_StringInput.title  = title ;
    params.m_StringInput.buf    = buf   ;
    params.m_StringInput.buflen = buflen;

    return( (short) CallMegaCAD(&params,STRING_INPUT) );
}

/**********************************************************************/

void SelectInit(                 // set select filter
        ulong        filter1,    // allowed entity types
        ulong        filter2)    // allowed entity types
{
    t_MegaPars params;

    params.m_SelectInit.filter1 = filter1;
    params.m_SelectInit.filter2 = filter2;

    CallMegaCAD(&params,SELECT_INIT);
}

/**********************************************************************/

void SelectLoop(                 // select entities
        tCallBack    func,       // callback function
        void         *para,      // data pointer for callback function
        void         *edta,      // data ptr of variable length entities
        t_mat44      *ecs,       // entity coordinate system
        ushort       esiz,       // size of data buffer
        uchar        fModify)    // entities to be modified?
{
    t_MegaPars params;

    params.m_SelectLoop.func    = func   ;
    params.m_SelectLoop.para    = para   ;
    params.m_SelectLoop.edta    = edta   ;
    params.m_SelectLoop.ecs     = ecs    ;
    params.m_SelectLoop.esiz    = esiz   ;
    params.m_SelectLoop.fModify = fModify;

    CallMegaCAD(&params,SELECT_LOOP);
}

/**********************************************************************/

ushort InsertMacro(              // insert macro-file
        char         *fname,     // macro filename
        tCallBack    func,       // callback function
        void         *para,      // data pointer for callback function
        void         *edta,      // data ptr of variable length entities
        t_mat44      *ecs,       // entity coordinate system
        ushort       esiz,       // size of data buffer
        t_placemac   *pmac)      // how (and where) to place the macro
{
    t_MegaPars params;

    params.m_InsertMacro.fname = fname;
    params.m_InsertMacro.func  = func ;
    params.m_InsertMacro.para  = para ;
    params.m_InsertMacro.edta  = edta ;
    params.m_InsertMacro.ecs   = ecs  ;
    params.m_InsertMacro.esiz  = esiz ;
    params.m_InsertMacro.pmac  = pmac ;

    return( (ushort) CallMegaCAD(&params,INSERT_MACRO) );
}

/**********************************************************************/

ushort CalcPattern(              // calc perimeter, area, pt. of gravity
        ushort       which,      // PERIM, AREA, GRAVITY
        ushort       cnt,        // cnt of polyline points
        t_polypt     *ppt,       // maybe NULL
        double       *result)    // value vs. point
{
    t_MegaPars params;

    params.m_CalcPattern.which  = which ;
    params.m_CalcPattern.cnt    = cnt   ;
    params.m_CalcPattern.ppt    = ppt   ;
    params.m_CalcPattern.result = result;

    return( (ushort) CallMegaCAD(&params,CALC_PATTERN) );
}

/**********************************************************************/

ushort DeleteEntity(             // delete an entity
        ulong        id)         // ID of entity
{
    t_MegaPars params;

    params.m_DeleteEntity.id = id;

    return( (ushort) CallMegaCAD(&params,DELETE_ENTITY) );
}

/**********************************************************************/

ushort GetEntity(                // get entity data
        ulong        id,         // ID of entity
        t_entity     *ent,       // entity
        void         *edta,      // data ptr of variable length entities
        ushort       esiz,       // size of data buffer
        t_mat44      *ecs)       // entity coordinate system
{
    t_MegaPars params;

    params.m_GetEntity.id   = id  ;
    params.m_GetEntity.ent  = ent ;
    params.m_GetEntity.edta = edta;
    params.m_GetEntity.esiz = esiz;
    params.m_GetEntity.ecs  = ecs ;

    return( (ushort) CallMegaCAD(&params,GET_ENTITY) );
}

/**********************************************************************/

void SetIncPnt(                  // set incremental point
        double       *pnt)       // new incremental point
{
    t_MegaPars params;

    params.m_SetIncPnt.pnt = pnt;

    CallMegaCAD(&params,SET_INC_PNT);
}

/**********************************************************************/

void InfoLoop(                   // loop through all entity infos
        tCallBack    func,       // callback function
        t_entinfo    *inf )      // info buffer
{
    t_MegaPars params;

    params.m_InfoLoop.func = func;
    params.m_InfoLoop.inf  = inf ;

    CallMegaCAD(&params,INFO_LOOP);
}

/**********************************************************************/

ushort GetInfo(                  // get entity info data
        ushort       iID,        // info ID
        t_entinfo    *inf )      // info buffer
{
    t_MegaPars params;

    params.m_GetInfo.iID  = iID ;
    params.m_GetInfo.inf  = inf ;

    return( (ushort) CallMegaCAD(&params,GET_INFO) );
}

/**********************************************************************/

ushort StoreInfo(                // store entity info
        t_entinfo    *inf )      // info buffer
{
    t_MegaPars params;

    params.m_StoreInfo.inf  = inf ;

    return( (ushort) CallMegaCAD(&params,STORE_INFO) );
}

/**********************************************************************/

ushort ExChangeInfo(             // exchange entity info data
        t_entinfo    *inf )      // info buffer
{
    t_MegaPars params;

    params.m_ExChangeInfo.inf  = inf ;

    return( (ushort) CallMegaCAD(&params,EX_CHANGE_INFO) );
}

/**********************************************************************/

void GetAttributes(              // get attributes (stl,col...)
        ushort       type,       // entity type
        t_attribs    *attr)      // buffer to be filled in
{
    t_MegaPars params;

    params.m_GetAttributes.type = type;
    params.m_GetAttributes.attr = attr;

    CallMegaCAD(&params,GET_ATTRIBUTES);
}

/**********************************************************************/

void GetLayGrpBits(              // retrieve active/inactive layers
        uchar        *bits)      // buffer of 256 bytes !!!
{
    t_MegaPars params;

    params.m_GetLayGrpBits.bits = bits;

    CallMegaCAD(&params,GET_LAY_GRP_BITS);
}

/**********************************************************************/

void GetLayerNames(              // retrieve layer names
        t_laygrp     *lg)        // buffer of 256 * 64 bytes
{
    t_MegaPars params;

    params.m_GetLayerNames.lg = lg;

    CallMegaCAD(&params,GET_LAYER_NAMES);
}

/**********************************************************************/

void GetGroupNames(              // retrieve group names
        t_laygrp     *lg)        // buffer of 256 * 64 bytes
{
    t_MegaPars params;

    params.m_GetGroupNames.lg = lg;

    CallMegaCAD(&params,GET_GROUP_NAMES);
}

/**********************************************************************/

void GetGridSets(                // retrieve grid settings
        t_gridsets   *grid)      // buffer to be filled in
{
    t_MegaPars params;

    params.m_GetGridSets.grid = grid;

    CallMegaCAD(&params,GET_GRID_SETS);
}

/**********************************************************************/

void SetAttributes(              // alter attributes (stl,col...)
        ushort       type,       // entity type
        t_attribs    *attr)      // new attributes
{
    t_MegaPars params;

    params.m_SetAttributes.type = type;
    params.m_SetAttributes.attr = attr;

    CallMegaCAD(&params,SET_ATTRIBUTES);
}

/**********************************************************************/

void SetLayGrpBits(              // set active/inactive layers
        uchar        *bits)      // new bits (256 bytes !!!)
{
    t_MegaPars params;

    params.m_SetLayGrpBits.bits = bits;

    CallMegaCAD(&params,SET_LAY_GRP_BITS);
}

/**********************************************************************/

void SetLayerNames(              // set layer names
        t_laygrp     *lg)        // buffer of 256 * 64 Bytes
{
    t_MegaPars params;

    params.m_SetLayerNames.lg = lg;

    CallMegaCAD(&params,SET_LAYER_NAMES);
}

/**********************************************************************/

void SetGroupNames(              // set group names
        t_laygrp     *lg)        // buffer of 256 * 64 Bytes
{
    t_MegaPars params;

    params.m_SetGroupNames.lg = lg;

    CallMegaCAD(&params,SET_GROUP_NAMES);
}

/**********************************************************************/

void SetGridSets(                // alter grid settings
        t_gridsets   *grid)      // new settings
{
    t_MegaPars params;

    params.m_SetGridSets.grid = grid;

    CallMegaCAD(&params,SET_GRID_SETS);
}

/**********************************************************************/

short GetCurrentFile(            // get name of currently loaded file
        uchar        *fname)     // name buffer to be filled in
{
    t_MegaPars params;

    params.m_GetCurrentFile.fname = fname;

    return( (short) CallMegaCAD(&params,GET_CURRENT_FILE) );
}

/**********************************************************************/

ulong CreateMacro(               // create and insert a macro
        t_macro      *mac,       // macro data
        t_mkmacro    *mkm,       // entities to be created
        ushort       cnt,        // number of entries
        t_placemac   *pmac,      // how and where to place the macro
        t_applic     *appl)      // application data (may be NULL)
{
    t_MegaPars params;

    params.m_CreateMacro.mac  = mac ;
    params.m_CreateMacro.mkm  = mkm ;
    params.m_CreateMacro.cnt  = cnt ;
    params.m_CreateMacro.pmac = pmac;
    params.m_CreateMacro.appl = appl;

    return( (ulong) CallMegaCAD(&params,CREATE_MACRO) );
}

/**********************************************************************/

void MacroLoop(                  // loop through all macros
        ulong        filter1,    // allowed entity types
        ulong        filter2,    // allowed entity types
        ulong        start,      // start ID (if 0L => all macros)
        tCallBack    func,       // callback function
        void         *para,      // data pointer for callback function
        void         *edta,      // data ptr of variable length entities
        t_mat44      *ecs,       // entity coordinate system
        ushort       esiz)       // size of data buffer
{
    t_MegaPars params;

    params.m_MacroLoop.filter1 = filter1;
    params.m_MacroLoop.filter2 = filter2;
    params.m_MacroLoop.start   = start  ;
    params.m_MacroLoop.func    = func   ;
    params.m_MacroLoop.para    = para   ;
    params.m_MacroLoop.edta    = edta   ;
    params.m_MacroLoop.ecs     = ecs    ;
    params.m_MacroLoop.esiz    = esiz   ;

    CallMegaCAD(&params,MACRO_LOOP);
}

/**********************************************************************/

short ClickMacro(                // let the user click a macro
        double       *pnt,       // point where macro was clicked
        t_entity     *ent,       // macro data to be filled in
        void         *edta,      // data ptr of variable length entities
        ushort       esiz)       // size of data buffer
{
    t_MegaPars params;

    params.m_ClickMacro.pnt  = pnt ;
    params.m_ClickMacro.ent  = ent ;
    params.m_ClickMacro.edta = edta;
    params.m_ClickMacro.esiz = esiz;

    return( (short) CallMegaCAD(&params,CLICK_MACRO) );
}

/**********************************************************************/

short EntityLen(                 // retrieve the length of an entity
        t_entity     *ent,       // entity to get length of
        double       *len)       // resulting length
{
    t_MegaPars params;

    params.m_EntityLen.ent = ent;
    params.m_EntityLen.len = len;

    return( (short) CallMegaCAD(&params,ENTITY_LEN) );
}

/**********************************************************************/

short PartList(                  // create a part list
        uchar        *fmt,       // name of format file
        uchar        *out,       // name of output file (maybe NULL)
        uchar        flags)      // flags (PART_....)
{
    t_MegaPars params;

    params.m_PartList.fmt   = fmt  ;
    params.m_PartList.out   = out  ;
    params.m_PartList.flags = flags;

    return( (short) CallMegaCAD(&params,PART_LIST) );
}

/**********************************************************************/

void GetPatternVal(              // retrieve current pattern settings
        t_pattern    *pat)       // pattern data
{
    t_MegaPars params;

    params.m_GetPatternVal.pat = pat;

    CallMegaCAD(&params,GET_PATTERN_VAL);
}

/**********************************************************************/

short GetExpression(             // evaluate expression
        uchar        *expr,      // expression to be evaluated
        double       *retval)    // result
{
    t_MegaPars params;

    params.m_GetExpression.expr   = expr  ;
    params.m_GetExpression.retval = retval;

    return( (short) CallMegaCAD(&params,GET_EXPRESSION) );
}

/**********************************************************************/

short DeleteMacro(               // delete a whole macro
        ulong        id)         // ID of macro entity
{
    t_MegaPars params;

    params.m_DeleteMacro.id = id;

    return( (short) CallMegaCAD(&params,DELETE_MACRO) );
}

/**********************************************************************/

short GetMacroInfo(              // retrieve info of current macro file
        t_macinfo    *macinfo)   // buffer to be filled in
{
    t_MegaPars params;

    params.m_GetMacroInfo.macinfo = macinfo;

    return( (short) CallMegaCAD(&params,GET_MACRO_INFO) );
}

/**********************************************************************/

short SetMacroInfo(              // set info of current macro file
        t_macinfo    *macinfo)   // data to be set
{
    t_MegaPars params;

    params.m_SetMacroInfo.macinfo = macinfo;

    return( (short) CallMegaCAD(&params,SET_MACRO_INFO) );
}

/**********************************************************************/

void GetPntSymbol(               // get current symbol settings
        t_symbol     *sym)       // data to be filled in
{
    t_MegaPars params;

    params.m_GetPntSymbol.sym = sym;

    CallMegaCAD(&params,GET_PNT_SYMBOL);
}

/**********************************************************************/

void ResetSavecount(             // reset savecount, so MegaCAD won't
        void )                   // ask whether to save current file
{
    t_MegaPars params;

    CallMegaCAD(&params,RESET_SAVECOUNT);
}

/**********************************************************************/

void DoZoom(                     // zoom to given rectangle
        double       *rect)      // rectangle to zoom to
{
    t_MegaPars params;

    params.m_DoZoom.rect = rect;

    CallMegaCAD(&params,DO_ZOOM);
}

/**********************************************************************/

void GetZoom(                    // get current zoom rectangle
        double       *rect)      // rectangle to be filled in
{
    t_MegaPars params;

    params.m_GetZoom.rect = rect;

    CallMegaCAD(&params,GET_ZOOM);
}

/**********************************************************************/

ushort GetApplID(                // get application ID
        uchar        *name)      // application name
{
    t_MegaPars params;

    params.m_GetApplID.name = name;

    return( (ushort) CallMegaCAD(&params,GET_APPL_ID) );
}

/**********************************************************************/

uchar* GetApplName(              // get application name
        ushort       id,         // application id
        uchar        *name)      // application name to be filled in
{
    t_MegaPars params;

    params.m_GetApplName.id   = id  ;
    params.m_GetApplName.name = name;

    return( (uchar*) CallMegaCAD(&params,GET_APPL_NAME) );
}

/**********************************************************************/

ulong SelectEntities(            // select entities (with highlighting)
        tCallBack    func,       // callback function
        void         *para,      // data pointer for callback function
        void         *edta,      // data ptr of variable length entities
        t_mat44      *ecs,       // entity coordinate system
        ushort       esiz,       // size of data buffer
        uchar        fModify)    // entities to be modified?
{
    t_MegaPars params;

    params.m_SelectEntities.func    = func   ;
    params.m_SelectEntities.para    = para   ;
    params.m_SelectEntities.edta    = edta   ;
    params.m_SelectEntities.ecs     = ecs    ;
    params.m_SelectEntities.esiz    = esiz   ;
    params.m_SelectEntities.fModify = fModify;

    return( (ulong) CallMegaCAD(&params,SELECT_ENTITIES) );
}

/**********************************************************************/

void SetHelpFunc(                // set help function
        tCallBack    fpHelp)     // help function pointer
{
    t_MegaPars params;

    params.m_SetHelpFunc.fpHelp = fpHelp;

    CallMegaCAD(&params,SET_HELP_FUNC);
}

/**********************************************************************/

uint WritePolyBmp(               // write polygonal Bitmap
        uchar        *fname,     // name of Bitmap file
        t_polygon    *poly,      // polygon (may be NULL)
        uchar        fMax)       // take size of original bitmap
{
    t_MegaPars params;

    params.m_WritePolyBmp.fname = fname;
    params.m_WritePolyBmp.poly  = poly ;
    params.m_WritePolyBmp.fMax  = fMax ;

    return( (uint) CallMegaCAD(&params,WRITE_POLY_BMP) );
}

/**********************************************************************/

short GetEntPtr(                 // get entity data
        t_EntPtr     *ep,        // abstract entity pointer
        t_entity     *ent,       // entity
        void         *edta,      // data ptr of variable length entities
        ushort       esiz,       // size of data buffer
        t_mat44      *ecs)       // entity coordinate system
{
    t_MegaPars params;

    params.m_GetEntPtr.ep   = ep  ;
    params.m_GetEntPtr.ent  = ent ;
    params.m_GetEntPtr.edta = edta;
    params.m_GetEntPtr.esiz = esiz;
    params.m_GetEntPtr.ecs  = ecs ;

    return( (short) CallMegaCAD(&params,GET_ENT_PTR) );
}

/**********************************************************************/

short SetEntPtr(                 // set entity data
        t_EntPtr     *ep,        // abstract entity pointer
        t_attribs    *attr)      // entity attributes (may be NULL)
{
    t_MegaPars params;

    params.m_SetEntPtr.ep   = ep  ;
    params.m_SetEntPtr.attr = attr;

    return( (short) CallMegaCAD(&params,SET_ENT_PTR) );
}

/**********************************************************************/

short SaveToPrt(                 // save entities to .PRT file
        char         *fname,     // filename
        ulong        *pid,       // array of entity ID's
        ulong        num,        // number of entity ID's
        ulong        flags)      // currently not used (give 0L!)
{
    t_MegaPars params;

    params.m_SaveToPrt.fname = fname;
    params.m_SaveToPrt.pid   = pid  ;
    params.m_SaveToPrt.num   = num  ;
    params.m_SaveToPrt.flags = flags;

    return( (short) CallMegaCAD(&params,SAVE_TO_PRT) );
}

/**********************************************************************/

ulong FindPolyLine(              // find nearest enclosing polyline (ID)
        double       *pnt)       // point to search from (2D)
{
    t_MegaPars params;

    params.m_FindPolyLine.pnt = pnt;

    return( (ulong) CallMegaCAD(&params,FIND_POLY_LINE) );
}

/**********************************************************************/

int SaveCurrentFile(             // save current file to disk
        char         *fname,     // filename (may be NULL)
        ulong        flags)      // (flags&1) => extract whole file
{
    t_MegaPars params;

    params.m_SaveCurrentFile.fname = fname;
    params.m_SaveCurrentFile.flags = flags;

    return( (int) CallMegaCAD(&params,SAVE_CURRENT_FILE) );
}

/**********************************************************************/

int GetMacroPos(                 // get macro position data
        ulong        id,         // id of macro header entity
        double       *mat,       // transformation matrix (3*3)
        double       *dpt,       // pt. of destination (3D)
        double       *d2D)       // xfac, yfac, phi (only if 2D)
{
    t_MegaPars params;

    params.m_GetMacroPos.id  = id ;
    params.m_GetMacroPos.mat = mat;
    params.m_GetMacroPos.dpt = dpt;
    params.m_GetMacroPos.d2D = d2D;

    return( (int) CallMegaCAD(&params,GET_MACRO_POS) );
}

/**********************************************************************/

void EntityLoopApp(              // loop through all entities
        ulong        filter1,    // allowed entity types
        ulong        filter2,    // allowed entity types
        tCallBack    func,       // callback function
        void         *para,      // data pointer for callback function
        void         *edta,      // data ptr of variable length entities
        t_mat44      *ecs,       // entity coordinate system
        ushort       esiz,       // size of data buffer
        ushort       appid)      // application id
{
    t_MegaPars params;

    params.m_EntityLoopApp.filter1 = filter1;
    params.m_EntityLoopApp.filter2 = filter2;
    params.m_EntityLoopApp.func    = func   ;
    params.m_EntityLoopApp.para    = para   ;
    params.m_EntityLoopApp.edta    = edta   ;
    params.m_EntityLoopApp.ecs     = ecs    ;
    params.m_EntityLoopApp.esiz    = esiz   ;
    params.m_EntityLoopApp.appid   = appid  ;

    CallMegaCAD(&params,ENTITY_LOOP_APP);
}

/**********************************************************************/

void RunFunction(                // run callback function (from modeless dialog)
        tCallBack    func,       // callback function
        void         *para,      // data pointer for callback function
        ushort       fStop)      // kill recursive calls ?
{
    t_MegaPars params;

    params.m_RunFunction.func  = func ;
    params.m_RunFunction.para  = para ;
    params.m_RunFunction.fStop = fStop;

    CallMegaCAD(&params,RUN_FUNCTION);
}

/**********************************************************************/

uchar SetCharSet(                // set character set to ANSI / OEM
        uchar        CharSet)    // GT_ANSI / GT_OEM
{
    t_MegaPars params;

    params.m_SetCharSet.CharSet = CharSet;

    return( (uchar) CallMegaCAD(&params,SET_CHAR_SET) );
}

/**********************************************************************/

void DllCanUnload(               // tells MegaCAD to unload the DLL
        void )                   // after IF_NFLOAD / IF_NF_NEW
{
    t_MegaPars params;

    CallMegaCAD(&params,DLL_CAN_UNLOAD);
}

/**********************************************************************/

int IsMacroExclusive(            // is this an exclusive macro ?
        ulong        id)         // ID of macro entity
{
    t_MegaPars params;

    params.m_IsMacroExclusive.id = id;

    return( (int) CallMegaCAD(&params,IS_MACRO_EXCLUSIVE) );
}

/**********************************************************************/

short GetPntInv3D(               // get point and draw something with mouse move
        double       *pkt,       // point to be filled in
        short        setinc,     // incremental point to be set ?
        tCallBack    func,       // callback function
        void         *para)      // data pointer for callback function
{
    t_MegaPars params;

    params.m_GetPntInv3D.pkt    = pkt   ;
    params.m_GetPntInv3D.setinc = setinc;
    params.m_GetPntInv3D.func   = func  ;
    params.m_GetPntInv3D.para   = para  ;

    return( (short) CallMegaCAD(&params,GET_PNT_INV3D) );
}

/**********************************************************************/

short GetPnt3D(                  // get point
        double       *pkt,       // point to be filled in
        short        setinc)     // incremental point to be set ?
{
    t_MegaPars params;

    params.m_GetPnt3D.pkt    = pkt   ;
    params.m_GetPnt3D.setinc = setinc;

    return( (short) CallMegaCAD(&params,GET_PNT3D) );
}

/**********************************************************************/

void DrawInv3D(                  // draw and save a temporary object
        ushort       type,       // type of entity to be drawn
        void         *ptr,       // data of entity
        ushort       lmode,      // line attributes (see LMODE)
        ushort       atype,      // type to get attributes from
        t_mat44      *ecs)       // entity coordinate system
{
    t_MegaPars params;

    params.m_DrawInv3D.type  = type ;
    params.m_DrawInv3D.ptr   = ptr  ;
    params.m_DrawInv3D.lmode = lmode;
    params.m_DrawInv3D.atype = atype;
    params.m_DrawInv3D.ecs   = ecs  ;

    CallMegaCAD(&params,DRAW_INV3D);
}

/**********************************************************************/

void StoreMultiple3D(            // store an entity (maybe multiple)
        double       *data,      // entity data
        ushort       type,       // entity type (may be or'ed with DO_SAVCNT)
        t_mat44      *ecs)       // entity coordinate system
{
    t_MegaPars params;

    params.m_StoreMultiple3D.data = data;
    params.m_StoreMultiple3D.type = type;
    params.m_StoreMultiple3D.ecs  = ecs ;

    CallMegaCAD(&params,STORE_MULTIPLE3D);
}

/**********************************************************************/

ulong CreateMacro3D(             // create and insert a macro
        t_macro      *mac,       // macro data
        t_mkmacro3D  *mkm,       // entities to be created
        ushort       cnt,        // number of entries
        t_placemac   *pmac,      // how and where to place the macro
        t_applic     *appl)      // application data (may be NULL)
{
    t_MegaPars params;

    params.m_CreateMacro3D.mac  = mac ;
    params.m_CreateMacro3D.mkm  = mkm ;
    params.m_CreateMacro3D.cnt  = cnt ;
    params.m_CreateMacro3D.pmac = pmac;
    params.m_CreateMacro3D.appl = appl;

    return( (ulong) CallMegaCAD(&params,CREATE_MACRO3D) );
}

/**********************************************************************/

void SetIncPnt3D(                // set incremental point
        double       *pnt)       // new incremental point
{
    t_MegaPars params;

    params.m_SetIncPnt3D.pnt = pnt;

    CallMegaCAD(&params,SET_INC_PNT3D);
}

/**********************************************************************/

void GetUcs(                     // get current working plane
        t_mat44      *ecs)       // user coordinate system
{
    t_MegaPars params;

    params.m_GetUcs.ecs = ecs;

    CallMegaCAD(&params,GET_UCS);
}

/**********************************************************************/

void SetUcs(                     // set current working plane
        t_mat44      *ecs)       // user coordinate system
{
    t_MegaPars params;

    params.m_SetUcs.ecs = ecs;

    CallMegaCAD(&params,SET_UCS);
}

/**********************************************************************/

void InitObj3D(                  // initialize data structure 't_Obj3D'
        t_Obj3D      *obj)       // body data
{
    t_MegaPars params;

    params.m_InitObj3D.obj = obj;

    CallMegaCAD(&params,INIT_OBJ3D);
}

/**********************************************************************/

void FreeObj3D(                  // free data structure 't_Obj3D'
        t_Obj3D      *obj)       // body data
{
    t_MegaPars params;

    params.m_FreeObj3D.obj = obj;

    CallMegaCAD(&params,FREE_OBJ3D);
}

/**********************************************************************/

int CreateCuboid(                // create a cube
        double       width,      // size in x
        double       depth,      // size in y
        double       height,     // size in z
        t_mat44      *ecs,       // entity coordinate system (may be NULL)
        t_Obj3D      *obj )      // body data
{
    t_MegaPars params;

    params.m_CreateCuboid.width  = width ;
    params.m_CreateCuboid.depth  = depth ;
    params.m_CreateCuboid.height = height;
    params.m_CreateCuboid.ecs    = ecs   ;
    params.m_CreateCuboid.obj    = obj   ;

    return( (int) CallMegaCAD(&params,CREATE_CUBOID) );
}

/**********************************************************************/

int CreateCylinder(              // create a cylinder
        double       height,     // height
        double       major,      // radius in x-direction at base
        double       minor,      // radius in y-direction at base
        t_mat44      *ecs,       // entity coordinate system (may be NULL)
        t_Obj3D      *obj )      // body data
{
    t_MegaPars params;

    params.m_CreateCylinder.height = height;
    params.m_CreateCylinder.major  = major ;
    params.m_CreateCylinder.minor  = minor ;
    params.m_CreateCylinder.ecs    = ecs   ;
    params.m_CreateCylinder.obj    = obj   ;

    return( (int) CallMegaCAD(&params,CREATE_CYLINDER) );
}

/**********************************************************************/

int CreateCone(                  // create a cone
        double       height,     // height
        double       major,      // radius in x-direction at base
        double       minor,      // radius in y-direction at base
        double       top,        // radius in x-direction at top
        t_mat44      *ecs,       // entity coordinate system (may be NULL)
        t_Obj3D      *obj )      // body data
{
    t_MegaPars params;

    params.m_CreateCone.height = height;
    params.m_CreateCone.major  = major ;
    params.m_CreateCone.minor  = minor ;
    params.m_CreateCone.top    = top   ;
    params.m_CreateCone.ecs    = ecs   ;
    params.m_CreateCone.obj    = obj   ;

    return( (int) CallMegaCAD(&params,CREATE_CONE) );
}

/**********************************************************************/

int CreateSphere(                // create a sphere
        double       rad,        // radius
        t_mat44      *ecs,       // entity coordinate system (may be NULL)
        t_Obj3D      *obj )      // body data
{
    t_MegaPars params;

    params.m_CreateSphere.rad  = rad ;
    params.m_CreateSphere.ecs  = ecs ;
    params.m_CreateSphere.obj  = obj ;

    return( (int) CallMegaCAD(&params,CREATE_SPHERE) );
}

/**********************************************************************/

int CreateTorus(                 // create a torus
        double       major,      // radius
        double       minor,      // radius
        t_mat44      *ecs,       // entity coordinate system (may be NULL)
        t_Obj3D      *obj )      // body data
{
    t_MegaPars params;

    params.m_CreateTorus.major = major;
    params.m_CreateTorus.minor = minor;
    params.m_CreateTorus.ecs   = ecs  ;
    params.m_CreateTorus.obj   = obj  ;

    return( (int) CallMegaCAD(&params,CREATE_TORUS) );
}

/**********************************************************************/

int BodyUnite(                   // unify two bodies
        t_Obj3D      *tool,      // tool_body data
        t_Obj3D      *blank,     // blank_body data
        int          del_t,      // delete tool ?
        int          del_b,      // delete blank ?
        t_mat44      *ecs,       // transformation for tool (may be NULL)
        t_Obj3D      *res )      // result_body data
{
    t_MegaPars params;

    params.m_BodyUnite.tool  = tool ;
    params.m_BodyUnite.blank = blank;
    params.m_BodyUnite.del_t = del_t;
    params.m_BodyUnite.del_b = del_b;
    params.m_BodyUnite.ecs   = ecs  ;
    params.m_BodyUnite.res   = res  ;

    return( (int) CallMegaCAD(&params,BODY_UNITE) );
}

/**********************************************************************/

int BodySubtract(                // subtract one body from another
        t_Obj3D      *tool,      // tool_body data
        t_Obj3D      *blank,     // blank_body data
        int          del_t,      // delete tool ?
        int          del_b,      // delete blank ?
        t_mat44      *ecs,       // transformation for tool (may be NULL)
        t_Obj3D      *res )      // result_body data
{
    t_MegaPars params;

    params.m_BodySubtract.tool  = tool ;
    params.m_BodySubtract.blank = blank;
    params.m_BodySubtract.del_t = del_t;
    params.m_BodySubtract.del_b = del_b;
    params.m_BodySubtract.ecs   = ecs  ;
    params.m_BodySubtract.res   = res  ;

    return( (int) CallMegaCAD(&params,BODY_SUBTRACT) );
}

/**********************************************************************/

int BodyIntersect(               // intersect two bodies
        t_Obj3D      *tool,      // tool_body data
        t_Obj3D      *blank,     // blank_body data
        int          del_t,      // delete tool ?
        int          del_b,      // delete blank ?
        t_mat44      *ecs,       // transformation for tool (may be NULL)
        t_Obj3D      *res )      // result_body data
{
    t_MegaPars params;

    params.m_BodyIntersect.tool  = tool ;
    params.m_BodyIntersect.blank = blank;
    params.m_BodyIntersect.del_t = del_t;
    params.m_BodyIntersect.del_b = del_b;
    params.m_BodyIntersect.ecs   = ecs  ;
    params.m_BodyIntersect.res   = res  ;

    return( (int) CallMegaCAD(&params,BODY_INTERSECT) );
}

/**********************************************************************/

int PlanarFace(                  // create a planar face
        ushort       cnt,        // number of polyline points
        t_polypt     *ppt,       // polyline points
        t_mat44      *ecs,       // entity coordinate system (may be NULL)
        t_Obj3D      *obj )      // body data
{
    t_MegaPars params;

    params.m_PlanarFace.cnt  = cnt ;
    params.m_PlanarFace.ppt  = ppt ;
    params.m_PlanarFace.ecs  = ecs ;
    params.m_PlanarFace.obj  = obj ;

    return( (int) CallMegaCAD(&params,PLANAR_FACE) );
}

/**********************************************************************/

ulong CreateLin3D(               // create a 3D line
        t_lin3D      *lin,       // 3D-coordinates of a line
        t_attribs    *attr,      // entity attributes
        t_applic     *appl)      // application data (may be NULL)
{
    t_MegaPars params;

    params.m_CreateLin3D.lin  = lin ;
    params.m_CreateLin3D.attr = attr;
    params.m_CreateLin3D.appl = appl;

    return( (ulong) CallMegaCAD(&params,CREATE_LIN3D) );
}

/**********************************************************************/

int CreatePrism(                 // create a prism
        ushort       cnt,        // number of polyline points
        t_polypt     *ppt,       // polyline points
        double       height,     // height
        double       *vec,       // direction
        int          is_solid,   // create sheet or solid body ?
        t_mat44      *ecs,       // entity coordinate system (may be NULL)
        t_Obj3D      *obj )      // body data
{
    t_MegaPars params;

    params.m_CreatePrism.cnt      = cnt     ;
    params.m_CreatePrism.ppt      = ppt     ;
    params.m_CreatePrism.height   = height  ;
    params.m_CreatePrism.vec      = vec     ;
    params.m_CreatePrism.is_solid = is_solid;
    params.m_CreatePrism.ecs      = ecs     ;
    params.m_CreatePrism.obj      = obj     ;

    return( (int) CallMegaCAD(&params,CREATE_PRISM) );
}

/**********************************************************************/

int CreateRotBody(               // create a rotation body
        ushort       cnt,        // number of polyline points
        t_polypt     *ppt,       // polyline points
        double       *axis,      // axis of rotation
        double       *angle,     // start and end angle
        int          is_solid,   // create sheet or solid body ?
        t_mat44      *ecs,       // entity coordinate system (may be NULL)
        t_Obj3D      *obj )      // body data
{
    t_MegaPars params;

    params.m_CreateRotBody.cnt      = cnt     ;
    params.m_CreateRotBody.ppt      = ppt     ;
    params.m_CreateRotBody.axis     = axis    ;
    params.m_CreateRotBody.angle    = angle   ;
    params.m_CreateRotBody.is_solid = is_solid;
    params.m_CreateRotBody.ecs      = ecs     ;
    params.m_CreateRotBody.obj      = obj     ;

    return( (int) CallMegaCAD(&params,CREATE_ROT_BODY) );
}

/**********************************************************************/

int CreateSweepBody(             // create a sweep body
        ushort       cnt_path,   // number of polyline points (path)
        t_polypt     *ppt_path,  // polyline points (path)
        t_mat44      *ecs_path,  // entity coordinate system (path)
        ushort       cnt_prof,   // number of polyline points (profile)
        t_polypt     *ppt_prof,  // polyline points (profile)
        t_mat44      *ecs_prof,  // entity coordinate system (profile)
        int          rigid,      // rigid sweep
        int          is_solid,   // create sheet or solid body ?
        t_Obj3D      *obj )      // body data
{
    t_MegaPars params;

    params.m_CreateSweepBody.cnt_path = cnt_path;
    params.m_CreateSweepBody.ppt_path = ppt_path;
    params.m_CreateSweepBody.ecs_path = ecs_path;
    params.m_CreateSweepBody.cnt_prof = cnt_prof;
    params.m_CreateSweepBody.ppt_prof = ppt_prof;
    params.m_CreateSweepBody.ecs_prof = ecs_prof;
    params.m_CreateSweepBody.rigid    = rigid   ;
    params.m_CreateSweepBody.is_solid = is_solid;
    params.m_CreateSweepBody.obj      = obj     ;

    return( (int) CallMegaCAD(&params,CREATE_SWEEP_BODY) );
}

/**********************************************************************/

void Pnt3DtoPnt2D(               // calculate a 2D point related do a LCS
        double       *pnt3D,     // 3D point in global coordinate system
        t_mat44      *lcs,       // local coordinate system
        double       *pnt2D )    // 2D point
{
    t_MegaPars params;

    params.m_Pnt3DtoPnt2D.pnt3D  = pnt3D ;
    params.m_Pnt3DtoPnt2D.lcs    = lcs   ;
    params.m_Pnt3DtoPnt2D.pnt2D  = pnt2D ;

    CallMegaCAD(&params,PNT3DTO_PNT2D);
}

/**********************************************************************/

void Pnt2DtoPnt3D(               // calculate a 3D point from 2D pt and LCS
        double       *pnt2D,     // 2D point
        t_mat44      *lcs,       // local coordinate system
        double       *pnt3D )    // 3D point in global coordinate system
{
    t_MegaPars params;

    params.m_Pnt2DtoPnt3D.pnt2D  = pnt2D ;
    params.m_Pnt2DtoPnt3D.lcs    = lcs   ;
    params.m_Pnt2DtoPnt3D.pnt3D  = pnt3D ;

    CallMegaCAD(&params,PNT2DTO_PNT3D);
}

/**********************************************************************/

void HiddenLine(                 // draw current window as hidden line view
        t_ProjPara   *ppara )    // projection data
{
    t_MegaPars params;

    params.m_HiddenLine.ppara  = ppara ;

    CallMegaCAD(&params,HIDDEN_LINE);
}

/**********************************************************************/

void HiddenLineMac(              // create a hidden line macro file
        t_ProjPara   *ppara,     // projection data
        uint         num_obj,    // number of objects
        t_Obj3D      *obj_list,  // object list
        uchar        *fname )    // name of the macro file
{
    t_MegaPars params;

    params.m_HiddenLineMac.ppara    = ppara   ;
    params.m_HiddenLineMac.num_obj  = num_obj ;
    params.m_HiddenLineMac.obj_list = obj_list;
    params.m_HiddenLineMac.fname    = fname   ;

    CallMegaCAD(&params,HIDDEN_LINE_MAC);
}

/**********************************************************************/

void HiddenLine2DSeg(            // calculate hidden line segments
        t_ProjPara   *ppara,     // projection data
        uint         num_obj,    // number of objects
        t_Obj3D      *obj_list,  // object list
        tCallBack    func,       // callback function
        void         *para)      // data pointer for callback function
{
    t_MegaPars params;

    params.m_HiddenLine2DSeg.ppara    = ppara   ;
    params.m_HiddenLine2DSeg.num_obj  = num_obj ;
    params.m_HiddenLine2DSeg.obj_list = obj_list;
    params.m_HiddenLine2DSeg.func     = func    ;
    params.m_HiddenLine2DSeg.para     = para    ;

    CallMegaCAD(&params,HIDDEN_LINE2DSEG);
}

/**********************************************************************/

void GetAktProjPara(             // get current projection parameters
        t_ProjPara   *ppara )    // projection data
{
    t_MegaPars params;

    params.m_GetAktProjPara.ppara  = ppara ;

    CallMegaCAD(&params,GET_AKT_PROJ_PARA);
}

/**********************************************************************/

void BegDrawInvObj3D(            // initialize structure 't_DrawInvObj'
        t_Obj3D      *obj,       // body data
        t_DrawInvObj *drwobj )   // data structure to be initialized
{
    t_MegaPars params;

    params.m_BegDrawInvObj3D.obj     = obj    ;
    params.m_BegDrawInvObj3D.drwobj  = drwobj ;

    CallMegaCAD(&params,BEG_DRAW_INV_OBJ3D);
}

/**********************************************************************/

void EndDrawInvObj3D(            // free structure 't_DrawInvObj'
        t_DrawInvObj *drwobj )   // data structure to be free'd
{
    t_MegaPars params;

    params.m_EndDrawInvObj3D.drwobj  = drwobj ;

    CallMegaCAD(&params,END_DRAW_INV_OBJ3D);
}

/**********************************************************************/

void DrawInvObj3D(               // draw a 3D-object
        void         *ptr,       // pointer to t_DrawInvObj structure
        ushort       lmode,      // line attributes (see LMODE)
        ushort       atype,      // type to get attributes from
        t_mat44      *ecs)       // entity coordinate system
{
    t_MegaPars params;

    params.m_DrawInvObj3D.ptr   = ptr  ;
    params.m_DrawInvObj3D.lmode = lmode;
    params.m_DrawInvObj3D.atype = atype;
    params.m_DrawInvObj3D.ecs   = ecs  ;

    CallMegaCAD(&params,DRAW_INV_OBJ3D);
}

/**********************************************************************/

void MatSuperpos(                // calculate superposition of 2 matrixes
        t_mat44      *ecs1,      // first given matrix
        t_mat44      *ecs2,      // second given matrix
        t_mat44      *res)       // result
{
    t_MegaPars params;

    params.m_MatSuperpos.ecs1 = ecs1;
    params.m_MatSuperpos.ecs2 = ecs2;
    params.m_MatSuperpos.res  = res ;

    CallMegaCAD(&params,MAT_SUPERPOS);
}

/**********************************************************************/

void GetBodyTransform(           // get tranformation data of a body
        t_Obj3D      *obj,       // body data
        t_mat44      *ecs)       // body coordinate system
{
    t_MegaPars params;

    params.m_GetBodyTransform.obj = obj;
    params.m_GetBodyTransform.ecs = ecs;

    CallMegaCAD(&params,GET_BODY_TRANSFORM);
}

/**********************************************************************/

void MatSolve(                   // 'res' = 'akt' * 'solve'
        t_mat44      *akt,       // first given matrix
        t_mat44      *solve,     // answer
        t_mat44      *res )      // second given matrix
{
    t_MegaPars params;

    params.m_MatSolve.akt   = akt  ;
    params.m_MatSolve.solve = solve;
    params.m_MatSolve.res   = res  ;

    CallMegaCAD(&params,MAT_SOLVE);
}

/**********************************************************************/

int PntNetIntp(                  // create a free form face by a point mesh
        uint         n,          // number of columns
        uint         m,          // number of rows
        t_point3D    *pnt,       // 'n' * 'm' control points
        t_Obj3D      *obj )      // body data
{
    t_MegaPars params;

    params.m_PntNetIntp.n    = n   ;
    params.m_PntNetIntp.m    = m   ;
    params.m_PntNetIntp.pnt  = pnt ;
    params.m_PntNetIntp.obj  = obj ;

    return( (int) CallMegaCAD(&params,PNT_NET_INTP) );
}

/**********************************************************************/

int SkinWires(                   // create a free form face by several curves
        uint         cnt,        // number of curves
        t_SkinCurv   *curv,      // array of curves
        t_Obj3D      *obj )      // body data
{
    t_MegaPars params;

    params.m_SkinWires.cnt  = cnt ;
    params.m_SkinWires.curv = curv;
    params.m_SkinWires.obj  = obj ;

    return( (int) CallMegaCAD(&params,SKIN_WIRES) );
}

/**********************************************************************/

int MakeCylinderFace(            // create a cylinder face
        double       height,     // height
        double       major,      // radius in x-direction at base
        double       minor,      // radius in y-direction at base
        double       *angle,     // start and end angle
        t_mat44      *ecs,       // entity coordinate system (may be NULL)
        t_Obj3D      *obj )      // body data
{
    t_MegaPars params;

    params.m_MakeCylinderFace.height = height;
    params.m_MakeCylinderFace.major  = major ;
    params.m_MakeCylinderFace.minor  = minor ;
    params.m_MakeCylinderFace.angle  = angle ;
    params.m_MakeCylinderFace.ecs    = ecs   ;
    params.m_MakeCylinderFace.obj    = obj   ;

    return( (int) CallMegaCAD(&params,MAKE_CYLINDER_FACE) );
}

/**********************************************************************/

int MakeConeFace(                // create a cone face
        double       height,     // height
        double       major,      // radius in x-direction at base
        double       minor,      // radius in y-direction at base
        double       top,        // radius in x-direction at top
        double       *angle,     // start and end angle
        t_mat44      *ecs,       // entity coordinate system (may be NULL)
        t_Obj3D      *obj )      // body data
{
    t_MegaPars params;

    params.m_MakeConeFace.height = height;
    params.m_MakeConeFace.major  = major ;
    params.m_MakeConeFace.minor  = minor ;
    params.m_MakeConeFace.top    = top   ;
    params.m_MakeConeFace.angle  = angle ;
    params.m_MakeConeFace.ecs    = ecs   ;
    params.m_MakeConeFace.obj    = obj   ;

    return( (int) CallMegaCAD(&params,MAKE_CONE_FACE) );
}

/**********************************************************************/

int MakeTorusFace(               // create a torus face
        double       major,      // radius
        double       minor,      // radius
        double       *u_angle,   // start and end angle in u direction
        double       *v_angle,   // start and end angle in v direction
        t_mat44      *ecs,       // entity coordinate system (may be NULL)
        t_Obj3D      *obj )      // body data
{
    t_MegaPars params;

    params.m_MakeTorusFace.major   = major  ;
    params.m_MakeTorusFace.minor   = minor  ;
    params.m_MakeTorusFace.u_angle = u_angle;
    params.m_MakeTorusFace.v_angle = v_angle;
    params.m_MakeTorusFace.ecs     = ecs    ;
    params.m_MakeTorusFace.obj     = obj    ;

    return( (int) CallMegaCAD(&params,MAKE_TORUS_FACE) );
}

/**********************************************************************/

int MakeSphereFace(              // create a sphere face
        double       rad,        // radius
        double       *u_angle,   // start and end angle in u direction
        double       *v_angle,   // start and end angle in v direction
        t_mat44      *ecs,       // entity coordinate system (may be NULL)
        t_Obj3D      *obj )      // body data
{
    t_MegaPars params;

    params.m_MakeSphereFace.rad     = rad    ;
    params.m_MakeSphereFace.u_angle = u_angle;
    params.m_MakeSphereFace.v_angle = v_angle;
    params.m_MakeSphereFace.ecs     = ecs    ;
    params.m_MakeSphereFace.obj     = obj    ;

    return( (int) CallMegaCAD(&params,MAKE_SPHERE_FACE) );
}

/**********************************************************************/

void PlaneToEcs(                 // calculate a LCS from plane data
        double       *xvec,      // X-Vector
        double       *yvec,      // Y-Vector
        double       *origin,    // origin
        t_mat44      *ecs )      // entity coordinate system
{
    t_MegaPars params;

    params.m_PlaneToEcs.xvec   = xvec  ;
    params.m_PlaneToEcs.yvec   = yvec  ;
    params.m_PlaneToEcs.origin = origin;
    params.m_PlaneToEcs.ecs    = ecs   ;

    CallMegaCAD(&params,PLANE_TO_ECS);
}

/**********************************************************************/

int PointsToEcs(                 // calculate a LCS from 3 points
        double       *pt1,       // 3D-Point
        double       *pt2,       // 3D-Point
        double       *pt3,       // 3D-Point
        t_mat44      *ecs )      // entity coordinate system
{
    t_MegaPars params;

    params.m_PointsToEcs.pt1  = pt1 ;
    params.m_PointsToEcs.pt2  = pt2 ;
    params.m_PointsToEcs.pt3  = pt3 ;
    params.m_PointsToEcs.ecs  = ecs ;

    return( (int) CallMegaCAD(&params,POINTS_TO_ECS) );
}

/**********************************************************************/

int CheckMat(                    // check correctness of LCS
        t_mat44      *ecs,       // entity coordinate system
        int          *change )   // was changed ?
{
    t_MegaPars params;

    params.m_CheckMat.ecs     = ecs    ;
    params.m_CheckMat.change  = change ;

    return( (int) CallMegaCAD(&params,CHECK_MAT) );
}

/**********************************************************************/

void Pnt2DtoPnt2D(               // calculate 2D pt from one LCS to another
        double       *pt1,       // 2D point
        t_mat44      *lcs1,      // local coordinate system
        t_mat44      *lcs2,      // local coordinate system
        double       *pt2 )      // 2D point (result)
{
    t_MegaPars params;

    params.m_Pnt2DtoPnt2D.pt1  = pt1 ;
    params.m_Pnt2DtoPnt2D.lcs1 = lcs1;
    params.m_Pnt2DtoPnt2D.lcs2 = lcs2;
    params.m_Pnt2DtoPnt2D.pt2  = pt2 ;

    CallMegaCAD(&params,PNT2DTO_PNT2D);
}

/**********************************************************************/

int GetBodyGrav(                 // calculate center of gravity
        t_Obj3D      *obj,       // body data
        double       *gpts )     // gravity point
{
    t_MegaPars params;

    params.m_GetBodyGrav.obj   = obj  ;
    params.m_GetBodyGrav.gpts  = gpts ;

    return( (int) CallMegaCAD(&params,GET_BODY_GRAV) );
}

/**********************************************************************/

void Pnt3DtoPnt3D(               // calculate 3D pt from one LCS to another
        double       *pt1,       // 3D point
        t_mat44      *lcs1,      // local coordinate system (may be NULL)
        t_mat44      *lcs2,      // local coordinate system (may be NULL)
        double       *pt2 )      // 3D point (result)
{
    t_MegaPars params;

    params.m_Pnt3DtoPnt3D.pt1  = pt1 ;
    params.m_Pnt3DtoPnt3D.lcs1 = lcs1;
    params.m_Pnt3DtoPnt3D.lcs2 = lcs2;
    params.m_Pnt3DtoPnt3D.pt2  = pt2 ;

    CallMegaCAD(&params,PNT3DTO_PNT3D);
}

/**********************************************************************/

ushort MacroPos(                 // insert macro-file
        char         *fname,     // macro filename
        tCallBack    func,       // callback function
        void         *para,      // data pointer for callback function
        void         *edta,      // data ptr of variable length entities
        ushort       esiz,       // size of data buffer
        ushort       flags,      // flags
        t_mat44      *ref,       // reference LCS
        t_mat44      *dst )      // destination LCS
{
    t_MegaPars params;

    params.m_MacroPos.fname = fname;
    params.m_MacroPos.func  = func ;
    params.m_MacroPos.para  = para ;
    params.m_MacroPos.edta  = edta ;
    params.m_MacroPos.esiz  = esiz ;
    params.m_MacroPos.flags = flags;
    params.m_MacroPos.ref   = ref  ;
    params.m_MacroPos.dst   = dst  ;

    return( (ushort) CallMegaCAD(&params,MACRO_POS) );
}

/**********************************************************************/

int CutBodyPlane(                // intersect a body by a plane
        t_Obj3D      *obj,       // object data
        ushort       upper,      // which side
        t_mat44      *plane,     // plane
        t_Obj3D      *res )      // result
{
    t_MegaPars params;

    params.m_CutBodyPlane.obj   = obj  ;
    params.m_CutBodyPlane.upper = upper;
    params.m_CutBodyPlane.plane = plane;
    params.m_CutBodyPlane.res   = res  ;

    return( (int) CallMegaCAD(&params,CUT_BODY_PLANE) );
}

/**********************************************************************/

void ObjToIGS(                   // save 3D objects of current drawing as IGS file
        char         *fname )    // filename of IGS-File
{
    t_MegaPars params;

    params.m_ObjToIGS.fname  = fname ;

    CallMegaCAD(&params,OBJ_TO_IGS);
}

/**********************************************************************/

int CurvIntrs(                   // create intersection curve
        t_Obj3D      *blank,     // blank_body data
        t_Obj3D      *tool,      // tool_body data
        t_mat44      *ecs,       // transformation (may be NULL)
        t_Obj3D      *curv )     // result_body data
{
    t_MegaPars params;

    params.m_CurvIntrs.blank = blank;
    params.m_CurvIntrs.tool  = tool ;
    params.m_CurvIntrs.ecs   = ecs  ;
    params.m_CurvIntrs.curv  = curv ;

    return( (int) CallMegaCAD(&params,CURV_INTRS) );
}

/**********************************************************************/

int OffsetFace(                  // offsets a face by given distance
        t_Obj3D      *obj,       // face
        double       dist,       // distance
        t_Obj3D      *ofst )     // result
{
    t_MegaPars params;

    params.m_OffsetFace.obj   = obj  ;
    params.m_OffsetFace.dist  = dist ;
    params.m_OffsetFace.ofst  = ofst ;

    return( (int) CallMegaCAD(&params,OFFSET_FACE) );
}

/**********************************************************************/

int GetBGravVol(         
        t_Obj3D     *obj,        // body data
        double      *gpts,       // gravity point
        double      *vol )       // volumen
{
    t_MegaPars params;

    params.m_GetBGravVol.obj  = obj ;
    params.m_GetBGravVol.gpts = gpts;
    params.m_GetBGravVol.vol  = vol ;

    return( (int) CallMegaCAD(&params,GET_BGRAV_VOL) );
}

/**********************************************************************/

short Update2DViews(             // update 2D views of working sheet(s)
        ulong       flags )      // (flags & 1) => all sheets
{
    t_MegaPars params;

    params.m_Update2DViews.flags  = flags ;

    return( (short) CallMegaCAD(&params,UPDATE2DVIEWS) );
}

/**********************************************************************/

int AdfSize(         
        t_Obj3D     *obj,        // body data
        t_Adf       *adf )       // adf structure
{
    t_MegaPars params;

    params.m_AdfSize.obj  = obj ;
    params.m_AdfSize.adf  = adf ;

    return( (int) CallMegaCAD(&params,ADF_SIZE) );
}

/**********************************************************************/

int BodyToAdf(         
        t_Obj3D     *obj,        // body data
        t_Adf       *adf )       // adf structure
{
    t_MegaPars params;

    params.m_BodyToAdf.obj  = obj ;
    params.m_BodyToAdf.adf  = adf ;

    return( (int) CallMegaCAD(&params,BODY_TO_ADF) );
}

/**********************************************************************/

int AdfToBody(         
        t_Adf       *adf,        // adf structure
        t_Obj3D     *obj )       // body data
{
    t_MegaPars params;

    params.m_AdfToBody.adf  = adf ;
    params.m_AdfToBody.obj  = obj ;

    return( (int) CallMegaCAD(&params,ADF_TO_BODY) );
}

/**********************************************************************/

int CutElem(         
        t_entity    *ent1,       //
        t_entity    *ent2,       //
        double      *pnt,        //
        t_point3D   *cutp )      //
{
    t_MegaPars params;

    params.m_CutElem.ent1  = ent1 ;
    params.m_CutElem.ent2  = ent2 ;
    params.m_CutElem.pnt   = pnt  ;
    params.m_CutElem.cutp  = cutp ;

    return( (int) CallMegaCAD(&params,CUT_ELEM) );
}

/**********************************************************************/

void SetAktProjPara(             // set current projection parameters
        t_ProjPara   *ppara,     // projection data
        int          hid ) 
{
    t_MegaPars params;

    params.m_SetAktProjPara.ppara = ppara;
    params.m_SetAktProjPara.hid   = hid  ;

    CallMegaCAD(&params,SET_AKT_PROJ_PARA);
}

/**********************************************************************/

int PlaneNormal(         
        t_Obj3D     *obj,        // body data
        double      *nev )       // normal defining the plane
{
    t_MegaPars params;

    params.m_PlaneNormal.obj  = obj ;
    params.m_PlaneNormal.nev  = nev ;

    return( (int) CallMegaCAD(&params,PLANE_NORMAL) );
}

/**********************************************************************/

int PointsToFace(         
        double      *pt1,        // 3D-Point
        double      *pt2,        // 3D-Point
        double      *pt3,        // 3D-Point
        t_Obj3D     *obj )       // body data
{
    t_MegaPars params;

    params.m_PointsToFace.pt1  = pt1 ;
    params.m_PointsToFace.pt2  = pt2 ;
    params.m_PointsToFace.pt3  = pt3 ;
    params.m_PointsToFace.obj  = obj ;

    return( (int) CallMegaCAD(&params,POINTS_TO_FACE) );
}

/**********************************************************************/

int FaceToPptSize(         
        t_Obj3D     *obj,        // body data
        int         *cnt )       // number of polyline points
{
    t_MegaPars params;

    params.m_FaceToPptSize.obj  = obj ;
    params.m_FaceToPptSize.cnt  = cnt ;

    return( (int) CallMegaCAD(&params,FACE_TO_PPT_SIZE) );
}

/**********************************************************************/

int FaceToPpt(         
        t_Obj3D     *obj,        // body data
        int         *cnt,        // number of polyline points
        t_polypt    *ppt )       // polyline points
{
    t_MegaPars params;

    params.m_FaceToPpt.obj  = obj ;
    params.m_FaceToPpt.cnt  = cnt ;
    params.m_FaceToPpt.ppt  = ppt ;

    return( (int) CallMegaCAD(&params,FACE_TO_PPT) );
}

/**********************************************************************/

void TraverseBody(         
        t_Obj3D      *obj,       // body data
        int          flags,      // flags
        tCallBack    func,       // callback function
        void         *para)      // data pointer for callback function
{
    t_MegaPars params;

    params.m_TraverseBody.obj   = obj  ;
    params.m_TraverseBody.flags = flags;
    params.m_TraverseBody.func  = func ;
    params.m_TraverseBody.para  = para ;

    CallMegaCAD(&params,TRAVERSE_BODY);
}

/**********************************************************************/

int SetBodyTransform(         
        t_Obj3D      *obj,       // body data
        t_mat44      *ecs )      // coordinate system
{
    t_MegaPars params;

    params.m_SetBodyTransform.obj  = obj ;
    params.m_SetBodyTransform.ecs  = ecs ;

    return( (int) CallMegaCAD(&params,SET_BODY_TRANSFORM) );
}

/**********************************************************************/

void SetMod2D(         
        ushort       mod2D )     // TRUE mod2D else mod3D
{
    t_MegaPars params;

    params.m_SetMod2D.mod2D  = mod2D ;

    CallMegaCAD(&params,SET_MOD2D);
}

/**********************************************************************/

int Pnt3DToFace(         
        int         cnt,         // number of 3D-points
        t_point3D   *pnt,        // array of 3D-points
        t_Obj3D     *obj )       // body data
{
    t_MegaPars params;

    params.m_Pnt3DToFace.cnt  = cnt ;
    params.m_Pnt3DToFace.pnt  = pnt ;
    params.m_Pnt3DToFace.obj  = obj ;

    return( (int) CallMegaCAD(&params,PNT3DTO_FACE) );
}

/**********************************************************************/

int CountLumps(         
        t_Obj3D     *obj )       // body data
{
    t_MegaPars params;

    params.m_CountLumps.obj  = obj ;

    return( (int) CallMegaCAD(&params,COUNT_LUMPS) );
}

/**********************************************************************/

int SplitBodies(         
        t_Obj3D     *obj,        // body data
        t_Obj3D     *objs  )     // array of bodies
{
    t_MegaPars params;

    params.m_SplitBodies.obj    = obj   ;
    params.m_SplitBodies.objs   = objs  ;

    return( (int) CallMegaCAD(&params,SPLIT_BODIES) );
}

/**********************************************************************/

int IsPlanarFace(         
        t_Obj3D     *obj )       // face data
{
    t_MegaPars params;

    params.m_IsPlanarFace.obj  = obj ;

    return( (int) CallMegaCAD(&params,IS_PLANAR_FACE) );
}

/**********************************************************************/

int GetMod2D(         
        void ) 
{
    t_MegaPars params;

    return( (int) CallMegaCAD(&params,GET_MOD2D) );
}

/**********************************************************************/

void Set0Ucs(         
        void ) 
{
    t_MegaPars params;

    CallMegaCAD(&params,SET0UCS);
}

/**********************************************************************/

int GetSelectMode(         
        void ) 
{
    t_MegaPars params;

    return( (int) CallMegaCAD(&params,GET_SELECT_MODE) );
}

/**********************************************************************/

int AddEntToMac(         
        ulong       mac_id,
        ushort      type,       // entity type
        t_attribs   *attr,      // entity attributes (may be NULL)
        void        *data,      // entity data
        t_applic    *appl,      // application data (may be NULL)
        t_mat44     *ecs)       // entity coordinate system
{
    t_MegaPars params;

    params.m_AddEntToMac.mac_id = mac_id;
    params.m_AddEntToMac.type   = type  ;
    params.m_AddEntToMac.attr   = attr  ;
    params.m_AddEntToMac.data   = data  ;
    params.m_AddEntToMac.appl   = appl  ;
    params.m_AddEntToMac.ecs    = ecs   ;

    return( (int) CallMegaCAD(&params,ADD_ENT_TO_MAC) );
}

/**********************************************************************/

