/**********************************************************************/
/* MegaCAD colour values                                              */
/**********************************************************************/

#define BLACK          0
#define BLUE           1
#define GREEN          2
#define CYAN           3
#define RED            4
#define MAGENTA        5
#define YELLOW         6
#define WHITE          7
#define BRIGHT_BLACK   8
#define BRIGHT_BLUE    9
#define BRIGHT_GREEN   10
#define BRIGHT_CYAN    11
#define BRIGHT_RED     12
#define BRIGHT_MAGENTA 13
#define BRIGHT_YELLOW  14
#define BRIGHT_WHITE   15

/**********************************************************************/

#define NIB(i,s)       (((i) & 0xf)<<(s))

#define LMODE(s,c,w) ((ushort)(NIB(s,0) | (((c)&0xff)<<8) | NIB(w,4)))
//      s = linestyle, c = colour, w = linewidth
//      with 'DrawInv()' values may be constant or 0,
//                       if 0, current values are taken
//      if you want a continuous line with width 1, you can call :
//          DrawInv(E_LINE,&line,LMODE(1,WHITE,1),0);
//      if you want the current settings of entity type 'type', you call :
//          DrawInv(E_LINE,&line,LMODE(0,0,0),type);

#define HLP_INV(f,b,s) ((ushort)(NIB(f,0) | NIB(b,4) | ((s)<<15)))
//      f = foreground colour, b = background colour, s = sound ?
//      if you set both colours to 0, the default colours are taken

#define DO_SAVCNT      (1<<7)
//      calls 'savecount()' at the end of 'StoreMultiple()'
//      if or'ed together with entity type

#if defined ( MEGATECH_C )
    #define tCallBack void *
#else
    typedef short (_far *tCallBack)(void _far *para);
#endif

#define CONTINUE_LOOP  0
#define CALL_SAVECOUNT 1
#define BREAK_LOOP     2

#define CALC_PERIM   0
#define CALC_AREA    1
#define CALC_GRAVITY 2

#define LAY_ON    (1<<0)
#define LAY_LOCK  (1<<1)
#define LAY_ATTR  (1<<2)

#define GRP_ON    (1<<4)
#define GRP_LOCK  (1<<5)
#define GRP_ATTR  (1<<6)

#define PART_ALL   1
#define PART_MAC   2
#define PART_ENT   4
#define PART_NOCNT 8

#define SCF_EXTRACT  1
#define SCF_ASK_2DWS 0
#define SCF_DO_2DWS  2
#define SCF_NO_2DWS  4

#define InsertMac(f,c,p,e,s) InsertMacro(f,c,p,e,s,NULL)

/**********************************************************************/
/* Tell C++ compilers that these functions are C functions!           */
/**********************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/**********************************************************************/
/* MegaCAD function prototypes.                                       */
/**********************************************************************/

EXT(201) short GetPntInv(        // get point and draw something with mouse move
        double       *pkt,       // point to be filled in
        short        setinc,     // incremental point to be set ?
        tCallBack    func,       // callback function
        void         *para);     // data pointer for callback function

EXT(202) void DrawInv(           // draw and save a temporary object
        ushort       type,       // type of entity to be drawn
        void         *ptr,       // data of entity
        ushort       lmode,      // line attributes (see LMODE)
        ushort       atype);     // type to get attributes from

EXT(203) short DlgInput(         // input some values by dialog
        ushort       num,        // number of fields (1 - 16)
        char         *title,     // title string
        t_dlgdta     *dta);      // array of field descriptors

EXT(204) short GetFilename(      // let the user select a filename
        char         *title,     // title string
        char         *fname);    // filename; must be initialized with path

EXT(205) void StoreMultiple(     // store an entity (maybe multiple)
        double       *data,      // entity data
        ushort       type);      // entity type (may be or'ed with DO_SAVCNT)

EXT(206) void MegaCMD(           // call MegaCAD command
        char         *cmd);      // command string (+ arguments)

EXT(207) short Message(          // message box
        char         *str1,      // 1st line of text
        char         *str2,      // 2nd line of text
        char         *but1,      // 1st button (may be NULL)
        char         *but2,      // 2nd button (may be NULL)
        char         *but3,      // 3rd button
        short        defbut);    // number of default button (1-3)

EXT(208) void MouseHelp(         // help text for mouse buttons
        char         *str1,      // help text for left mouse button
        char         *str2,      // help text for right mouse button
        ushort       inv);       // colour (beep) for 1st text (see HLP_INV)

EXT(209) short GetPnt(           // get point
        double       *pkt,       // point to be filled in
        short        setinc);    // incremental point to be set ?

EXT(210) void savecount(         // end of operation
        void );                  // must be called after creation of entities

EXT(211) void SetFuncText(       // set name of current function
        char         *text);     // function text

EXT(212) ulong CreateEntity(     // store an entity (not multiple), returns ID
        ushort       type,       // entity type
        t_attribs    *attr,      // entity attributes (may be NULL)
        void         *data,      // entity data
        t_applic     *appl,      // application data (may be NULL)
        t_mat44      *ecs);      // entity coordinate system

EXT(213) void GetTextVal(        // retrieve text attributes
        ushort       type,       // line or block
        ushort       init,       // initialize (or just calculate box)
        t_text       *txt);      // text data

EXT(214) ushort ReadTxtFile(     // read in a text file
        char         *fname,     // filename
        char         *buf,       // buffer to be filled in
        uint         bufsiz);    // size of buffer

EXT(215) ushort AddPolylnPt(     // add a polyline point
        t_polyln     *polyln,    // polyline structure
        double       *mpd,       // may be NULL
        double       px,         // x-coordinate of point
        double       py);        // y-coordinate of point

EXT(216) void EraseInv(          // delete temporary objects
        void );

EXT(217) void GetDimVal(         // retrieve dimension attributes
        ushort       type,       // type of dimension
        ushort       init,       // initialize (or just calculate box)
        t_dimension  *dim);      // dimension data

EXT(218) void PrintDimVal(       // print dimension text
        double       value,      // measured value
        char         *str,       // string buffer to fill
        char         *tol1,      // tolerance string 1
        char         *tol2);     // tolerance string 2

EXT(219) short ClickEntity(      // let the user click a single entity
        ulong        filter1,    // allowed entity types
        ulong        filter2,    // allowed entity types
        double       *pnt,       // point where entity was clicked
        double       *pnt3D,     // 3D-point
        int          snp_mod,    // Snap-Mode SNP_...
        t_entity     *ent,       // entity data to be filled in
        void         *edta,      // data ptr of variable length entities
        ushort       esiz,       // size of data buffer
        t_mat44      *ecs,       // entity coordinate system
        uchar        fModify);   // entity to be modified?

EXT(220) ulong ExChangeEntity(   // exchange an entity, returns new ID
        t_entity     *ent,       // new entity data, old id
        t_mat44      *ecs);      // entity coordinate system

EXT(221) short Blink(            // draw something blinking
        tCallBack    func,       // callback function
        void         *para);     // data pointer for callback function

EXT(222) void EntityLoop(        // loop through all entities
        ulong        filter1,    // allowed entity types
        ulong        filter2,    // allowed entity types
        tCallBack    func,       // callback function
        void         *para,      // data pointer for callback function
        void         *edta,      // data ptr of variable length entities
        t_mat44      *ecs,       // entity coordinate system
        ushort       esiz);      // size of data buffer

EXT(223) void DrawEntities(      // draw array of entity-id's
        ulong        *pid,       // array of entity-id's
        ushort       num);       // number of id's

EXT(224) short StringInput(      // input a line of text
        char         *title,     // title string
        char         *buf,       // string buffer to be filled in
        ushort       buflen);    // size of buffer

EXT(225) void SelectInit(        // set select filter
        ulong        filter1,    // allowed entity types
        ulong        filter2);   // allowed entity types

EXT(226) void SelectLoop(        // select entities
        tCallBack    func,       // callback function
        void         *para,      // data pointer for callback function
        void         *edta,      // data ptr of variable length entities
        t_mat44      *ecs,       // entity coordinate system
        ushort       esiz,       // size of data buffer
        uchar        fModify);   // entities to be modified?

EXT(227) ushort InsertMacro(     // insert macro-file
        char         *fname,     // macro filename
        tCallBack    func,       // callback function
        void         *para,      // data pointer for callback function
        void         *edta,      // data ptr of variable length entities
        t_mat44      *ecs,       // entity coordinate system
        ushort       esiz,       // size of data buffer
        t_placemac   *pmac);     // how (and where) to place the macro

EXT(228) ushort CalcPattern(     // calc perimeter, area, pt. of gravity
        ushort       which,      // PERIM, AREA, GRAVITY
        ushort       cnt,        // cnt of polyline points
        t_polypt     *ppt,       // maybe NULL
        double       *result);   // value vs. point

EXT(229) ushort DeleteEntity(    // delete an entity
        ulong        id);        // ID of entity

EXT(230) ushort GetEntity(       // get entity data
        ulong        id,         // ID of entity
        t_entity     *ent,       // entity
        void         *edta,      // data ptr of variable length entities
        ushort       esiz,       // size of data buffer
        t_mat44      *ecs);      // entity coordinate system

EXT(231) void SetIncPnt(         // set incremental point
        double       *pnt);      // new incremental point

EXT(232) void InfoLoop(          // loop through all entity infos
        tCallBack    func,       // callback function
        t_entinfo    *inf );     // info buffer

EXT(233) ushort GetInfo(         // get entity info data
        ushort       iID,        // info ID
        t_entinfo    *inf );     // info buffer

EXT(234) ushort StoreInfo(       // store entity info
        t_entinfo    *inf );     // info buffer

EXT(235) ushort ExChangeInfo(    // exchange entity info data
        t_entinfo    *inf );     // info buffer

EXT(236) void GetAttributes(     // get attributes (stl,col...)
        ushort       type,       // entity type
        t_attribs    *attr);     // buffer to be filled in

EXT(237) void GetLayGrpBits(     // retrieve active/inactive layers
        uchar        *bits);     // buffer of 256 bytes !!!

EXT(238) void GetLayerNames(     // retrieve layer names
        t_laygrp     *lg);       // buffer of 256 * 64 bytes

EXT(239) void GetGroupNames(     // retrieve group names
        t_laygrp     *lg);       // buffer of 256 * 64 bytes

EXT(240) void GetGridSets(       // retrieve grid settings
        t_gridsets   *grid);     // buffer to be filled in

EXT(241) void SetAttributes(     // alter attributes (stl,col...)
        ushort       type,       // entity type
        t_attribs    *attr);     // new attributes

EXT(242) void SetLayGrpBits(     // set active/inactive layers
        uchar        *bits);     // new bits (256 bytes !!!)

EXT(243) void SetLayerNames(     // set layer names
        t_laygrp     *lg);       // buffer of 256 * 64 Bytes

EXT(244) void SetGroupNames(     // set group names
        t_laygrp     *lg);       // buffer of 256 * 64 Bytes

EXT(245) void SetGridSets(       // alter grid settings
        t_gridsets   *grid);     // new settings

EXT(246) short GetCurrentFile(   // get name of currently loaded file
        uchar        *fname);    // name buffer to be filled in

EXT(247) ulong CreateMacro(      // create and insert a macro
        t_macro      *mac,       // macro data
        t_mkmacro    *mkm,       // entities to be created
        ushort       cnt,        // number of entries
        t_placemac   *pmac,      // how and where to place the macro
        t_applic     *appl);     // application data (may be NULL)

EXT(248) void MacroLoop(         // loop through all macros
        ulong        filter1,    // allowed entity types
        ulong        filter2,    // allowed entity types
        ulong        start,      // start ID (if 0L => all macros)
        tCallBack    func,       // callback function
        void         *para,      // data pointer for callback function
        void         *edta,      // data ptr of variable length entities
        t_mat44      *ecs,       // entity coordinate system
        ushort       esiz);      // size of data buffer

EXT(249) short ClickMacro(       // let the user click a macro
        double       *pnt,       // point where macro was clicked
        t_entity     *ent,       // macro data to be filled in
        void         *edta,      // data ptr of variable length entities
        ushort       esiz);      // size of data buffer

EXT(250) short EntityLen(        // retrieve the length of an entity
        t_entity     *ent,       // entity to get length of
        double       *len);      // resulting length

EXT(251) short PartList(         // create a part list
        uchar        *fmt,       // name of format file
        uchar        *out,       // name of output file (maybe NULL)
        uchar        flags);     // flags (PART_....)

EXT(252) void GetPatternVal(     // retrieve current pattern settings
        t_pattern    *pat);      // pattern data

EXT(253) short GetExpression(    // evaluate expression
        uchar        *expr,      // expression to be evaluated
        double       *retval);   // result

EXT(254) short DeleteMacro(      // delete a whole macro
        ulong        id);        // ID of macro entity

EXT(255) short GetMacroInfo(     // retrieve info of current macro file
        t_macinfo    *macinfo);  // buffer to be filled in

EXT(256) short SetMacroInfo(     // set info of current macro file
        t_macinfo    *macinfo);  // data to be set

EXT(257) void GetPntSymbol(      // get current symbol settings
        t_symbol     *sym);      // data to be filled in

EXT(258) void ResetSavecount(    // reset savecount, so MegaCAD won't
        void );                  // ask whether to save current file

EXT(259) void DoZoom(            // zoom to given rectangle
        double       *rect);     // rectangle to zoom to

EXT(260) void GetZoom(           // get current zoom rectangle
        double       *rect);     // rectangle to be filled in

EXT(261) ushort GetApplID(       // get application ID
        uchar        *name);     // application name

EXT(262) uchar* GetApplName(     // get application name
        ushort       id,         // application id
        uchar        *name);     // application name to be filled in

EXT(263) ulong SelectEntities(   // select entities (with highlighting)
        tCallBack    func,       // callback function
        void         *para,      // data pointer for callback function
        void         *edta,      // data ptr of variable length entities
        t_mat44      *ecs,       // entity coordinate system
        ushort       esiz,       // size of data buffer
        uchar        fModify);   // entities to be modified?

EXT(264) void SetHelpFunc(       // set help function
        tCallBack    fpHelp);    // help function pointer

EXT(265) uint WritePolyBmp(      // write polygonal Bitmap
        uchar        *fname,     // name of Bitmap file
        t_polygon    *poly,      // polygon (may be NULL)
        uchar        fMax);      // take size of original bitmap

#if !defined ( MEGATECH_C )
EXT(266) short GetEntPtr(        // get entity data
        t_EntPtr     *ep,        // abstract entity pointer
        t_entity     *ent,       // entity
        void         *edta,      // data ptr of variable length entities
        ushort       esiz,       // size of data buffer
        t_mat44      *ecs);      // entity coordinate system

EXT(267) short SetEntPtr(        // set entity data
        t_EntPtr     *ep,        // abstract entity pointer
        t_attribs    *attr);     // entity attributes (may be NULL)
#endif

EXT(268) short SaveToPrt(        // save entities to .PRT file
        char         *fname,     // filename
        ulong        *pid,       // array of entity ID's
        ulong        num,        // number of entity ID's
        ulong        flags);     // currently not used (give 0L!)

EXT(269) ulong FindPolyLine(     // find nearest enclosing polyline (ID)
        double       *pnt);      // point to search from (2D)

EXT(270) int SaveCurrentFile(    // save current file to disk
        char         *fname,     // filename (may be NULL)
        ulong        flags);     // (flags&1) => extract whole file

EXT(271) int GetMacroPos(        // get macro position data
        ulong        id,         // id of macro header entity
        double       *mat,       // transformation matrix (3*3)
        double       *dpt,       // pt. of destination (3D)
        double       *d2D);      // xfac, yfac, phi (only if 2D)

EXT(272) void EntityLoopApp(     // loop through all entities
        ulong        filter1,    // allowed entity types
        ulong        filter2,    // allowed entity types
        tCallBack    func,       // callback function
        void         *para,      // data pointer for callback function
        void         *edta,      // data ptr of variable length entities
        t_mat44      *ecs,       // entity coordinate system
        ushort       esiz,       // size of data buffer
        ushort       appid);     // application id

EXT(273) void RunFunction(       // run callback function (from modeless dialog)
        tCallBack    func,       // callback function
        void         *para,      // data pointer for callback function
        ushort       fStop);     // kill recursive calls ?

EXT(274) uchar SetCharSet(       // set character set to ANSI / OEM
        uchar        CharSet);   // GT_ANSI / GT_OEM

EXT(275) void DllCanUnload(      // tells MegaCAD to unload the DLL
        void );                  // after IF_NFLOAD / IF_NF_NEW

EXT(276) int IsMacroExclusive(   // is this an exclusive macro ?
        ulong        id);        // ID of macro entity

EXT(500) short GetPntInv3D(      // get point and draw something with mouse move
        double       *pkt,       // point to be filled in
        short        setinc,     // incremental point to be set ?
        tCallBack    func,       // callback function
        void         *para);     // data pointer for callback function

EXT(501) short GetPnt3D(         // get point
        double       *pkt,       // point to be filled in
        short        setinc);    // incremental point to be set ?

EXT(502) void DrawInv3D(         // draw and save a temporary object
        ushort       type,       // type of entity to be drawn
        void         *ptr,       // data of entity
        ushort       lmode,      // line attributes (see LMODE)
        ushort       atype,      // type to get attributes from
        t_mat44      *ecs);      // entity coordinate system

EXT(503) void StoreMultiple3D(   // store an entity (maybe multiple)
        double       *data,      // entity data
        ushort       type,       // entity type (may be or'ed with DO_SAVCNT)
        t_mat44      *ecs);      // entity coordinate system

EXT(504) ulong CreateMacro3D(    // create and insert a macro
        t_macro      *mac,       // macro data
        t_mkmacro3D  *mkm,       // entities to be created
        ushort       cnt,        // number of entries
        t_placemac   *pmac,      // how and where to place the macro
        t_applic     *appl);     // application data (may be NULL)

EXT(505) void SetIncPnt3D(       // set incremental point
        double       *pnt);      // new incremental point

EXT(506) void GetUcs(            // get current working plane
        t_mat44      *ecs);      // user coordinate system

EXT(507) void SetUcs(            // set current working plane
        t_mat44      *ecs);      // user coordinate system

EXT(508) void InitObj3D(         // initialize data structure 't_Obj3D'
        t_Obj3D      *obj);      // body data

EXT(509) void FreeObj3D(         // free data structure 't_Obj3D'
        t_Obj3D      *obj);      // body data

EXT(510) int CreateCuboid(       // create a cube
        double       width,      // size in x
        double       depth,      // size in y
        double       height,     // size in z
        t_mat44      *ecs,       // entity coordinate system (may be NULL)
        t_Obj3D      *obj );     // body data

EXT(511) int CreateCylinder(     // create a cylinder
        double       height,     // height
        double       major,      // radius in x-direction at base
        double       minor,      // radius in y-direction at base
        t_mat44      *ecs,       // entity coordinate system (may be NULL)
        t_Obj3D      *obj );     // body data

EXT(512) int CreateCone(         // create a cone
        double       height,     // height
        double       major,      // radius in x-direction at base
        double       minor,      // radius in y-direction at base
        double       top,        // radius in x-direction at top
        t_mat44      *ecs,       // entity coordinate system (may be NULL)
        t_Obj3D      *obj );     // body data

EXT(513) int CreateSphere(       // create a sphere
        double       rad,        // radius
        t_mat44      *ecs,       // entity coordinate system (may be NULL)
        t_Obj3D      *obj );     // body data

EXT(514) int CreateTorus(        // create a torus
        double       major,      // radius
        double       minor,      // radius
        t_mat44      *ecs,       // entity coordinate system (may be NULL)
        t_Obj3D      *obj );     // body data

EXT(515) int BodyUnite(          // unify two bodies
        t_Obj3D      *tool,      // tool_body data
        t_Obj3D      *blank,     // blank_body data
        int          del_t,      // delete tool ?
        int          del_b,      // delete blank ?
        t_mat44      *ecs,       // transformation for tool (may be NULL)
        t_Obj3D      *res );     // result_body data

EXT(516) int BodySubtract(       // subtract one body from another
        t_Obj3D      *tool,      // tool_body data
        t_Obj3D      *blank,     // blank_body data
        int          del_t,      // delete tool ?
        int          del_b,      // delete blank ?
        t_mat44      *ecs,       // transformation for tool (may be NULL)
        t_Obj3D      *res );     // result_body data

EXT(517) int BodyIntersect(      // intersect two bodies
        t_Obj3D      *tool,      // tool_body data
        t_Obj3D      *blank,     // blank_body data
        int          del_t,      // delete tool ?
        int          del_b,      // delete blank ?
        t_mat44      *ecs,       // transformation for tool (may be NULL)
        t_Obj3D      *res );     // result_body data

EXT(518) int PlanarFace(         // create a planar face
        ushort       cnt,        // number of polyline points
        t_polypt     *ppt,       // polyline points
        t_mat44      *ecs,       // entity coordinate system (may be NULL)
        t_Obj3D      *obj );     // body data

EXT(519) ulong CreateLin3D(      // create a 3D line
        t_lin3D      *lin,       // 3D-coordinates of a line
        t_attribs    *attr,      // entity attributes
        t_applic     *appl);     // application data (may be NULL)

EXT(520) int CreatePrism(        // create a prism
        ushort       cnt,        // number of polyline points
        t_polypt     *ppt,       // polyline points
        double       height,     // height
        double       *vec,       // direction
        int          is_solid,   // create sheet or solid body ?
        t_mat44      *ecs,       // entity coordinate system (may be NULL)
        t_Obj3D      *obj );     // body data

EXT(521) int CreateRotBody(      // create a rotation body
        ushort       cnt,        // number of polyline points
        t_polypt     *ppt,       // polyline points
        double       *axis,      // axis of rotation
        double       *angle,     // start and end angle
        int          is_solid,   // create sheet or solid body ?
        t_mat44      *ecs,       // entity coordinate system (may be NULL)
        t_Obj3D      *obj );     // body data

EXT(522) int CreateSweepBody(    // create a sweep body
        ushort       cnt_path,   // number of polyline points (path)
        t_polypt     *ppt_path,  // polyline points (path)
        t_mat44      *ecs_path,  // entity coordinate system (path)
        ushort       cnt_prof,   // number of polyline points (profile)
        t_polypt     *ppt_prof,  // polyline points (profile)
        t_mat44      *ecs_prof,  // entity coordinate system (profile)
        int          rigid,      // rigid sweep
        int          is_solid,   // create sheet or solid body ?
        t_Obj3D      *obj );     // body data

EXT(523) void Pnt3DtoPnt2D(      // calculate a 2D point related do a LCS
        double       *pnt3D,     // 3D point in global coordinate system
        t_mat44      *lcs,       // local coordinate system
        double       *pnt2D );   // 2D point

EXT(524) void Pnt2DtoPnt3D(      // calculate a 3D point from 2D pt and LCS
        double       *pnt2D,     // 2D point
        t_mat44      *lcs,       // local coordinate system
        double       *pnt3D );   // 3D point in global coordinate system

EXT(525) void HiddenLine(        // draw current window as hidden line view
        t_ProjPara   *ppara );   // projection data

EXT(526) void HiddenLineMac(     // create a hidden line macro file
        t_ProjPara   *ppara,     // projection data
        uint         num_obj,    // number of objects
        t_Obj3D      *obj_list,  // object list
        uchar        *fname );   // name of the macro file

EXT(527) void HiddenLine2DSeg(   // calculate hidden line segments
        t_ProjPara   *ppara,     // projection data
        uint         num_obj,    // number of objects
        t_Obj3D      *obj_list,  // object list
        tCallBack    func,       // callback function
        void         *para);     // data pointer for callback function

EXT(528) void GetAktProjPara(    // get current projection parameters
        t_ProjPara   *ppara );   // projection data

EXT(529) void BegDrawInvObj3D(   // initialize structure 't_DrawInvObj'
        t_Obj3D      *obj,       // body data
        t_DrawInvObj *drwobj );  // data structure to be initialized

EXT(530) void EndDrawInvObj3D(   // free structure 't_DrawInvObj'
        t_DrawInvObj *drwobj );  // data structure to be free'd

EXT(531) void DrawInvObj3D(      // draw a 3D-object
        void         *ptr,       // pointer to t_DrawInvObj structure
        ushort       lmode,      // line attributes (see LMODE)
        ushort       atype,      // type to get attributes from
        t_mat44      *ecs);      // entity coordinate system

EXT(532) void MatSuperpos(       // calculate superposition of 2 matrixes
        t_mat44      *ecs1,      // first given matrix
        t_mat44      *ecs2,      // second given matrix
        t_mat44      *res);      // result

EXT(533) void GetBodyTransform(  // get tranformation data of a body
        t_Obj3D      *obj,       // body data
        t_mat44      *ecs);      // body coordinate system

EXT(534) void MatSolve(          // 'res' = 'akt' * 'solve'
        t_mat44      *akt,       // first given matrix
        t_mat44      *solve,     // answer
        t_mat44      *res );     // second given matrix

EXT(535) int PntNetIntp(         // create a free form face by a point mesh
        uint         n,          // number of columns
        uint         m,          // number of rows
        t_point3D    *pnt,       // 'n' * 'm' control points
        t_Obj3D      *obj );     // body data

EXT(536) int SkinWires(          // create a free form face by several curves
        uint         cnt,        // number of curves
        t_SkinCurv   *curv,      // array of curves
        t_Obj3D      *obj );     // body data

EXT(537) int MakeCylinderFace(   // create a cylinder face
        double       height,     // height
        double       major,      // radius in x-direction at base
        double       minor,      // radius in y-direction at base
        double       *angle,     // start and end angle
        t_mat44      *ecs,       // entity coordinate system (may be NULL)
        t_Obj3D      *obj );     // body data

EXT(538) int MakeConeFace(       // create a cone face
        double       height,     // height
        double       major,      // radius in x-direction at base
        double       minor,      // radius in y-direction at base
        double       top,        // radius in x-direction at top
        double       *angle,     // start and end angle
        t_mat44      *ecs,       // entity coordinate system (may be NULL)
        t_Obj3D      *obj );     // body data

EXT(539) int MakeTorusFace(      // create a torus face
        double       major,      // radius
        double       minor,      // radius
        double       *u_angle,   // start and end angle in u direction
        double       *v_angle,   // start and end angle in v direction
        t_mat44      *ecs,       // entity coordinate system (may be NULL)
        t_Obj3D      *obj );     // body data

EXT(540) int MakeSphereFace(     // create a sphere face
        double       rad,        // radius
        double       *u_angle,   // start and end angle in u direction
        double       *v_angle,   // start and end angle in v direction
        t_mat44      *ecs,       // entity coordinate system (may be NULL)
        t_Obj3D      *obj );     // body data

EXT(541) void PlaneToEcs(        // calculate a LCS from plane data
        double       *xvec,      // X-Vector
        double       *yvec,      // Y-Vector
        double       *origin,    // origin
        t_mat44      *ecs );     // entity coordinate system

EXT(542) int PointsToEcs(        // calculate a LCS from 3 points
        double       *pt1,       // 3D-Point
        double       *pt2,       // 3D-Point
        double       *pt3,       // 3D-Point
        t_mat44      *ecs );     // entity coordinate system

EXT(543) int CheckMat(           // check correctness of LCS
        t_mat44      *ecs,       // entity coordinate system
        int          *change );  // was changed ?

EXT(544) void Pnt2DtoPnt2D(      // calculate 2D pt from one LCS to another
        double       *pt1,       // 2D point
        t_mat44      *lcs1,      // local coordinate system
        t_mat44      *lcs2,      // local coordinate system
        double       *pt2 );     // 2D point (result)

EXT(545) int GetBodyGrav(        // calculate center of gravity
        t_Obj3D      *obj,       // body data
        double       *gpts );    // gravity point

EXT(546) void Pnt3DtoPnt3D(      // calculate 3D pt from one LCS to another
        double       *pt1,       // 3D point
        t_mat44      *lcs1,      // local coordinate system (may be NULL)
        t_mat44      *lcs2,      // local coordinate system (may be NULL)
        double       *pt2 );     // 3D point (result)

EXT(547) ushort MacroPos(        // insert macro-file
        char         *fname,     // macro filename
        tCallBack    func,       // callback function
        void         *para,      // data pointer for callback function
        void         *edta,      // data ptr of variable length entities
        ushort       esiz,       // size of data buffer
        ushort       flags,      // flags
        t_mat44      *ref,       // reference LCS
        t_mat44      *dst );     // destination LCS

EXT(548) int CutBodyPlane(       // intersect a body by a plane
        t_Obj3D      *obj,       // object data
        ushort       upper,      // which side
        t_mat44      *plane,     // plane
        t_Obj3D      *res );     // result

EXT(549) void ObjToIGS(          // save 3D objects of current drawing as IGS file
        char         *fname );   // filename of IGS-File

EXT(550) int CurvIntrs(          // create intersection curve
        t_Obj3D      *blank,     // blank_body data
        t_Obj3D      *tool,      // tool_body data
        t_mat44      *ecs,       // transformation (may be NULL)
        t_Obj3D      *curv );    // result_body data

EXT(551) int OffsetFace(         // offsets a face by given distance
        t_Obj3D      *obj,       // face
        double       dist,       // distance
        t_Obj3D      *ofst );    // result

EXT(552) int GetBGravVol(
        t_Obj3D     *obj,        // body data
        double      *gpts,       // gravity point
        double      *vol );      // volumen

EXT(553) short Update2DViews(    // update 2D views of working sheet(s)
        ulong       flags );     // (flags & 1) => all sheets

EXT(554) int AdfSize(
        t_Obj3D     *obj,        // body data
        t_Adf       *adf );      // adf structure

EXT(555) int BodyToAdf(
        t_Obj3D     *obj,        // body data
        t_Adf       *adf );      // adf structure

EXT(556) int AdfToBody(
        t_Adf       *adf,        // adf structure
        t_Obj3D     *obj );      // body data

EXT(557) int CutElem(
        t_entity    *ent1,       //
        t_entity    *ent2,       //
        double      *pnt,        //
        t_point3D   *cutp );     //

EXT(558) void SetAktProjPara(    // set current projection parameters
        t_ProjPara   *ppara,     // projection data
        int          hid );

EXT(559) int PlaneNormal(
        t_Obj3D     *obj,        // body data
        double      *nev );      // normal defining the plane

EXT(560) int PointsToFace(
        double      *pt1,        // 3D-Point
        double      *pt2,        // 3D-Point
        double      *pt3,        // 3D-Point
        t_Obj3D     *obj );      // body data

EXT(561) int FaceToPptSize(
        t_Obj3D     *obj,        // body data
        int         *cnt );      // number of polyline points

EXT(562) int FaceToPpt(
        t_Obj3D     *obj,        // body data
        int         *cnt,        // number of polyline points
        t_polypt    *ppt );      // polyline points

EXT(563) void TraverseBody(
        t_Obj3D      *obj,       // body data
        int          flags,      // flags
        tCallBack    func,       // callback function
        void         *para);     // data pointer for callback function

EXT(564) int SetBodyTransform(
        t_Obj3D      *obj,       // body data
        t_mat44      *ecs );     // coordinate system

EXT(565) void SetMod2D(
        ushort       mod2D );    // TRUE mod2D else mod3D

EXT(566) int Pnt3DToFace(
        int         cnt,         // number of 3D-points
        t_point3D   *pnt,        // array of 3D-points
        t_Obj3D     *obj );      // body data

EXT(567) int CountLumps(
        t_Obj3D     *obj );      // body data

EXT(568) int SplitBodies(
        t_Obj3D     *obj,        // body data
        t_Obj3D     *objs  );    // array of bodies

EXT(569) int IsPlanarFace(
        t_Obj3D     *obj );      // face data

EXT(570) int GetMod2D(
        void );

EXT(571) void Set0Ucs(
        void );

EXT(572) int GetSelectMode(
        void );

EXT(573) int AddEntToMac(
        ulong       mac_id,
        ushort      type,       // entity type
        t_attribs   *attr,      // entity attributes (may be NULL)
        void        *data,      // entity data
        t_applic    *appl,      // application data (may be NULL)
        t_mat44     *ecs);      // entity coordinate system

/**********************************************************************/
#ifdef __cplusplus
}
#endif
/**********************************************************************/
