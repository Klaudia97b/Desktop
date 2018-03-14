#pragma pack (2)
typedef struct t_GetPntInv
{
    double       _far *pkt;
    short        setinc;
    tCallBack    func;
    void         _far *para;
} t_GetPntInv;

typedef struct t_DrawInv
{
    ushort       type;
    void         _far *ptr;
    ushort       lmode;
    ushort       atype;
} t_DrawInv;

typedef struct t_DlgInput
{
    ushort       num;
    char         _far *title;
    t_dlgdta     _far *dta;
} t_DlgInput;

typedef struct t_GetFilename
{
    char         _far *title;
    char         _far *fname;
} t_GetFilename;

typedef struct t_StoreMultiple
{
    double       _far *data;
    ushort       type;
} t_StoreMultiple;

typedef struct t_MegaCMD
{
    char         _far *cmd;
} t_MegaCMD;

typedef struct t_Message
{
    char         _far *str1;
    char         _far *str2;
    char         _far *but1;
    char         _far *but2;
    char         _far *but3;
    short        defbut;
} t_Message;

typedef struct t_MouseHelp
{
    char         _far *str1;
    char         _far *str2;
    ushort       inv;
} t_MouseHelp;

typedef struct t_GetPnt
{
    double       _far *pkt;
    short        setinc;
} t_GetPnt;

typedef struct t_savecount
{
    int         dummy;
} t_savecount;

typedef struct t_SetFuncText
{
    char         _far *text;
} t_SetFuncText;

typedef struct t_CreateEntity
{
    ushort       type;
    t_attribs    _far *attr;
    void         _far *data;
    t_applic     _far *appl;
    t_mat44      _far *ecs;
} t_CreateEntity;

typedef struct t_GetTextVal
{
    ushort       type;
    ushort       init;
    t_text       _far *txt;
} t_GetTextVal;

typedef struct t_ReadTxtFile
{
    char         _far *fname;
    char         _far *buf;
    uint         bufsiz;
} t_ReadTxtFile;

typedef struct t_AddPolylnPt
{
    t_polyln     _far *polyln;
    double       _far *mpd;
    double       px;
    double       py;
} t_AddPolylnPt;

typedef struct t_EraseInv
{
    int         dummy;
} t_EraseInv;

typedef struct t_GetDimVal
{
    ushort       type;
    ushort       init;
    t_dimension  _far *dim;
} t_GetDimVal;

typedef struct t_PrintDimVal
{
    double       value;
    char         _far *str;
    char         _far *tol1;
    char         _far *tol2;
} t_PrintDimVal;

typedef struct t_ClickEntity
{
    ulong        filter1;
    ulong        filter2;
    double       _far *pnt;
    double       _far *pnt3D;
    int          snp_mod;
    t_entity     _far *ent;
    void         _far *edta;
    ushort       esiz;
    t_mat44      _far *ecs;
    uchar        fModify;
} t_ClickEntity;

typedef struct t_ExChangeEntity
{
    t_entity     _far *ent;
    t_mat44      _far *ecs;
} t_ExChangeEntity;

typedef struct t_Blink
{
    tCallBack    func;
    void         _far *para;
} t_Blink;

typedef struct t_EntityLoop
{
    ulong        filter1;
    ulong        filter2;
    tCallBack    func;
    void         _far *para;
    void         _far *edta;
    t_mat44      _far *ecs;
    ushort       esiz;
} t_EntityLoop;

typedef struct t_DrawEntities
{
    ulong        _far *pid;
    ushort       num;
} t_DrawEntities;

typedef struct t_StringInput
{
    char         _far *title;
    char         _far *buf;
    ushort       buflen;
} t_StringInput;

typedef struct t_SelectInit
{
    ulong        filter1;
    ulong        filter2;
} t_SelectInit;

typedef struct t_SelectLoop
{
    tCallBack    func;
    void         _far *para;
    void         _far *edta;
    t_mat44      _far *ecs;
    ushort       esiz;
    uchar        fModify;
} t_SelectLoop;

typedef struct t_InsertMacro
{
    char         _far *fname;
    tCallBack    func;
    void         _far *para;
    void         _far *edta;
    t_mat44      _far *ecs;
    ushort       esiz;
    t_placemac   _far *pmac;
} t_InsertMacro;

typedef struct t_CalcPattern
{
    ushort       which;
    ushort       cnt;
    t_polypt     _far *ppt;
    double       _far *result;
} t_CalcPattern;

typedef struct t_DeleteEntity
{
    ulong        id;
} t_DeleteEntity;

typedef struct t_GetEntity
{
    ulong        id;
    t_entity     _far *ent;
    void         _far *edta;
    ushort       esiz;
    t_mat44      _far *ecs;
} t_GetEntity;

typedef struct t_SetIncPnt
{
    double       _far *pnt;
} t_SetIncPnt;

typedef struct t_InfoLoop
{
    tCallBack    func;
    t_entinfo    _far *inf ;
} t_InfoLoop;

typedef struct t_GetInfo
{
    ushort       iID;
    t_entinfo    _far *inf ;
} t_GetInfo;

typedef struct t_StoreInfo
{
    t_entinfo    _far *inf ;
} t_StoreInfo;

typedef struct t_ExChangeInfo
{
    t_entinfo    _far *inf ;
} t_ExChangeInfo;

typedef struct t_GetAttributes
{
    ushort       type;
    t_attribs    _far *attr;
} t_GetAttributes;

typedef struct t_GetLayGrpBits
{
    uchar        _far *bits;
} t_GetLayGrpBits;

typedef struct t_GetLayerNames
{
    t_laygrp     _far *lg;
} t_GetLayerNames;

typedef struct t_GetGroupNames
{
    t_laygrp     _far *lg;
} t_GetGroupNames;

typedef struct t_GetGridSets
{
    t_gridsets   _far *grid;
} t_GetGridSets;

typedef struct t_SetAttributes
{
    ushort       type;
    t_attribs    _far *attr;
} t_SetAttributes;

typedef struct t_SetLayGrpBits
{
    uchar        _far *bits;
} t_SetLayGrpBits;

typedef struct t_SetLayerNames
{
    t_laygrp     _far *lg;
} t_SetLayerNames;

typedef struct t_SetGroupNames
{
    t_laygrp     _far *lg;
} t_SetGroupNames;

typedef struct t_SetGridSets
{
    t_gridsets   _far *grid;
} t_SetGridSets;

typedef struct t_GetCurrentFile
{
    uchar        _far *fname;
} t_GetCurrentFile;

typedef struct t_CreateMacro
{
    t_macro      _far *mac;
    t_mkmacro    _far *mkm;
    ushort       cnt;
    t_placemac   _far *pmac;
    t_applic     _far *appl;
} t_CreateMacro;

typedef struct t_MacroLoop
{
    ulong        filter1;
    ulong        filter2;
    ulong        start;
    tCallBack    func;
    void         _far *para;
    void         _far *edta;
    t_mat44      _far *ecs;
    ushort       esiz;
} t_MacroLoop;

typedef struct t_ClickMacro
{
    double       _far *pnt;
    t_entity     _far *ent;
    void         _far *edta;
    ushort       esiz;
} t_ClickMacro;

typedef struct t_EntityLen
{
    t_entity     _far *ent;
    double       _far *len;
} t_EntityLen;

typedef struct t_PartList
{
    uchar        _far *fmt;
    uchar        _far *out;
    uchar        flags;
} t_PartList;

typedef struct t_GetPatternVal
{
    t_pattern    _far *pat;
} t_GetPatternVal;

typedef struct t_GetExpression
{
    uchar        _far *expr;
    double       _far *retval;
} t_GetExpression;

typedef struct t_DeleteMacro
{
    ulong        id;
} t_DeleteMacro;

typedef struct t_GetMacroInfo
{
    t_macinfo    _far *macinfo;
} t_GetMacroInfo;

typedef struct t_SetMacroInfo
{
    t_macinfo    _far *macinfo;
} t_SetMacroInfo;

typedef struct t_GetPntSymbol
{
    t_symbol     _far *sym;
} t_GetPntSymbol;

typedef struct t_ResetSavecount
{
    int         dummy;
} t_ResetSavecount;

typedef struct t_DoZoom
{
    double       _far *rect;
} t_DoZoom;

typedef struct t_GetZoom
{
    double       _far *rect;
} t_GetZoom;

typedef struct t_GetApplID
{
    uchar        _far *name;
} t_GetApplID;

typedef struct t_GetApplName
{
    ushort       id;
    uchar        _far *name;
} t_GetApplName;

typedef struct t_SelectEntities
{
    tCallBack    func;
    void         _far *para;
    void         _far *edta;
    t_mat44      _far *ecs;
    ushort       esiz;
    uchar        fModify;
} t_SelectEntities;

typedef struct t_SetHelpFunc
{
    tCallBack    fpHelp;
} t_SetHelpFunc;

typedef struct t_WritePolyBmp
{
    uchar        _far *fname;
    t_polygon    _far *poly;
    uchar        fMax;
} t_WritePolyBmp;

typedef struct t_GetEntPtr
{
    t_EntPtr     _far *ep;
    t_entity     _far *ent;
    void         _far *edta;
    ushort       esiz;
    t_mat44      _far *ecs;
} t_GetEntPtr;

typedef struct t_SetEntPtr
{
    t_EntPtr     _far *ep;
    t_attribs    _far *attr;
} t_SetEntPtr;

typedef struct t_SaveToPrt
{
    char         _far *fname;
    ulong        _far *pid;
    ulong        num;
    ulong        flags;
} t_SaveToPrt;

typedef struct t_FindPolyLine
{
    double       _far *pnt;
} t_FindPolyLine;

typedef struct t_SaveCurrentFile
{
    char         _far *fname;
    ulong        flags;
} t_SaveCurrentFile;

typedef struct t_GetMacroPos
{
    ulong        id;
    double       _far *mat;
    double       _far *dpt;
    double       _far *d2D;
} t_GetMacroPos;

typedef struct t_EntityLoopApp
{
    ulong        filter1;
    ulong        filter2;
    tCallBack    func;
    void         _far *para;
    void         _far *edta;
    t_mat44      _far *ecs;
    ushort       esiz;
    ushort       appid;
} t_EntityLoopApp;

typedef struct t_RunFunction
{
    tCallBack    func;
    void         _far *para;
    ushort       fStop;
} t_RunFunction;

typedef struct t_SetCharSet
{
    uchar        CharSet;
} t_SetCharSet;

typedef struct t_DllCanUnload
{
    int         dummy;
} t_DllCanUnload;

typedef struct t_IsMacroExclusive
{
    ulong        id;
} t_IsMacroExclusive;

typedef struct t_GetPntInv3D
{
    double       _far *pkt;
    short        setinc;
    tCallBack    func;
    void         _far *para;
} t_GetPntInv3D;

typedef struct t_GetPnt3D
{
    double       _far *pkt;
    short        setinc;
} t_GetPnt3D;

typedef struct t_DrawInv3D
{
    ushort       type;
    void         _far *ptr;
    ushort       lmode;
    ushort       atype;
    t_mat44      _far *ecs;
} t_DrawInv3D;

typedef struct t_StoreMultiple3D
{
    double       _far *data;
    ushort       type;
    t_mat44      _far *ecs;
} t_StoreMultiple3D;

typedef struct t_CreateMacro3D
{
    t_macro      _far *mac;
    t_mkmacro3D  _far *mkm;
    ushort       cnt;
    t_placemac   _far *pmac;
    t_applic     _far *appl;
} t_CreateMacro3D;

typedef struct t_SetIncPnt3D
{
    double       _far *pnt;
} t_SetIncPnt3D;

typedef struct t_GetUcs
{
    t_mat44      _far *ecs;
} t_GetUcs;

typedef struct t_SetUcs
{
    t_mat44      _far *ecs;
} t_SetUcs;

typedef struct t_InitObj3D
{
    t_Obj3D      _far *obj;
} t_InitObj3D;

typedef struct t_FreeObj3D
{
    t_Obj3D      _far *obj;
} t_FreeObj3D;

typedef struct t_CreateCuboid
{
    double       width;
    double       depth;
    double       height;
    t_mat44      _far *ecs;
    t_Obj3D      _far *obj ;
} t_CreateCuboid;

typedef struct t_CreateCylinder
{
    double       height;
    double       major;
    double       minor;
    t_mat44      _far *ecs;
    t_Obj3D      _far *obj ;
} t_CreateCylinder;

typedef struct t_CreateCone
{
    double       height;
    double       major;
    double       minor;
    double       top;
    t_mat44      _far *ecs;
    t_Obj3D      _far *obj ;
} t_CreateCone;

typedef struct t_CreateSphere
{
    double       rad;
    t_mat44      _far *ecs;
    t_Obj3D      _far *obj ;
} t_CreateSphere;

typedef struct t_CreateTorus
{
    double       major;
    double       minor;
    t_mat44      _far *ecs;
    t_Obj3D      _far *obj ;
} t_CreateTorus;

typedef struct t_BodyUnite
{
    t_Obj3D      _far *tool;
    t_Obj3D      _far *blank;
    int          del_t;
    int          del_b;
    t_mat44      _far *ecs;
    t_Obj3D      _far *res ;
} t_BodyUnite;

typedef struct t_BodySubtract
{
    t_Obj3D      _far *tool;
    t_Obj3D      _far *blank;
    int          del_t;
    int          del_b;
    t_mat44      _far *ecs;
    t_Obj3D      _far *res ;
} t_BodySubtract;

typedef struct t_BodyIntersect
{
    t_Obj3D      _far *tool;
    t_Obj3D      _far *blank;
    int          del_t;
    int          del_b;
    t_mat44      _far *ecs;
    t_Obj3D      _far *res ;
} t_BodyIntersect;

typedef struct t_PlanarFace
{
    ushort       cnt;
    t_polypt     _far *ppt;
    t_mat44      _far *ecs;
    t_Obj3D      _far *obj ;
} t_PlanarFace;

typedef struct t_CreateLin3D
{
    t_lin3D      _far *lin;
    t_attribs    _far *attr;
    t_applic     _far *appl;
} t_CreateLin3D;

typedef struct t_CreatePrism
{
    ushort       cnt;
    t_polypt     _far *ppt;
    double       height;
    double       _far *vec;
    int          is_solid;
    t_mat44      _far *ecs;
    t_Obj3D      _far *obj ;
} t_CreatePrism;

typedef struct t_CreateRotBody
{
    ushort       cnt;
    t_polypt     _far *ppt;
    double       _far *axis;
    double       _far *angle;
    int          is_solid;
    t_mat44      _far *ecs;
    t_Obj3D      _far *obj ;
} t_CreateRotBody;

typedef struct t_CreateSweepBody
{
    ushort       cnt_path;
    t_polypt     _far *ppt_path;
    t_mat44      _far *ecs_path;
    ushort       cnt_prof;
    t_polypt     _far *ppt_prof;
    t_mat44      _far *ecs_prof;
    int          rigid;
    int          is_solid;
    t_Obj3D      _far *obj ;
} t_CreateSweepBody;

typedef struct t_Pnt3DtoPnt2D
{
    double       _far *pnt3D;
    t_mat44      _far *lcs;
    double       _far *pnt2D ;
} t_Pnt3DtoPnt2D;

typedef struct t_Pnt2DtoPnt3D
{
    double       _far *pnt2D;
    t_mat44      _far *lcs;
    double       _far *pnt3D ;
} t_Pnt2DtoPnt3D;

typedef struct t_HiddenLine
{
    t_ProjPara   _far *ppara ;
} t_HiddenLine;

typedef struct t_HiddenLineMac
{
    t_ProjPara   _far *ppara;
    uint         num_obj;
    t_Obj3D      _far *obj_list;
    uchar        _far *fname ;
} t_HiddenLineMac;

typedef struct t_HiddenLine2DSeg
{
    t_ProjPara   _far *ppara;
    uint         num_obj;
    t_Obj3D      _far *obj_list;
    tCallBack    func;
    void         _far *para;
} t_HiddenLine2DSeg;

typedef struct t_GetAktProjPara
{
    t_ProjPara   _far *ppara ;
} t_GetAktProjPara;

typedef struct t_BegDrawInvObj3D
{
    t_Obj3D      _far *obj;
    t_DrawInvObj _far *drwobj ;
} t_BegDrawInvObj3D;

typedef struct t_EndDrawInvObj3D
{
    t_DrawInvObj _far *drwobj ;
} t_EndDrawInvObj3D;

typedef struct t_DrawInvObj3D
{
    void         _far *ptr;
    ushort       lmode;
    ushort       atype;
    t_mat44      _far *ecs;
} t_DrawInvObj3D;

typedef struct t_MatSuperpos
{
    t_mat44      _far *ecs1;
    t_mat44      _far *ecs2;
    t_mat44      _far *res;
} t_MatSuperpos;

typedef struct t_GetBodyTransform
{
    t_Obj3D      _far *obj;
    t_mat44      _far *ecs;
} t_GetBodyTransform;

typedef struct t_MatSolve
{
    t_mat44      _far *akt;
    t_mat44      _far *solve;
    t_mat44      _far *res ;
} t_MatSolve;

typedef struct t_PntNetIntp
{
    uint         n;
    uint         m;
    t_point3D    _far *pnt;
    t_Obj3D      _far *obj ;
} t_PntNetIntp;

typedef struct t_SkinWires
{
    uint         cnt;
    t_SkinCurv   _far *curv;
    t_Obj3D      _far *obj ;
} t_SkinWires;

typedef struct t_MakeCylinderFace
{
    double       height;
    double       major;
    double       minor;
    double       _far *angle;
    t_mat44      _far *ecs;
    t_Obj3D      _far *obj ;
} t_MakeCylinderFace;

typedef struct t_MakeConeFace
{
    double       height;
    double       major;
    double       minor;
    double       top;
    double       _far *angle;
    t_mat44      _far *ecs;
    t_Obj3D      _far *obj ;
} t_MakeConeFace;

typedef struct t_MakeTorusFace
{
    double       major;
    double       minor;
    double       _far *u_angle;
    double       _far *v_angle;
    t_mat44      _far *ecs;
    t_Obj3D      _far *obj ;
} t_MakeTorusFace;

typedef struct t_MakeSphereFace
{
    double       rad;
    double       _far *u_angle;
    double       _far *v_angle;
    t_mat44      _far *ecs;
    t_Obj3D      _far *obj ;
} t_MakeSphereFace;

typedef struct t_PlaneToEcs
{
    double       _far *xvec;
    double       _far *yvec;
    double       _far *origin;
    t_mat44      _far *ecs ;
} t_PlaneToEcs;

typedef struct t_PointsToEcs
{
    double       _far *pt1;
    double       _far *pt2;
    double       _far *pt3;
    t_mat44      _far *ecs ;
} t_PointsToEcs;

typedef struct t_CheckMat
{
    t_mat44      _far *ecs;
    int          _far *change ;
} t_CheckMat;

typedef struct t_Pnt2DtoPnt2D
{
    double       _far *pt1;
    t_mat44      _far *lcs1;
    t_mat44      _far *lcs2;
    double       _far *pt2 ;
} t_Pnt2DtoPnt2D;

typedef struct t_GetBodyGrav
{
    t_Obj3D      _far *obj;
    double       _far *gpts ;
} t_GetBodyGrav;

typedef struct t_Pnt3DtoPnt3D
{
    double       _far *pt1;
    t_mat44      _far *lcs1;
    t_mat44      _far *lcs2;
    double       _far *pt2 ;
} t_Pnt3DtoPnt3D;

typedef struct t_MacroPos
{
    char         _far *fname;
    tCallBack    func;
    void         _far *para;
    void         _far *edta;
    ushort       esiz;
    ushort       flags;
    t_mat44      _far *ref;
    t_mat44      _far *dst ;
} t_MacroPos;

typedef struct t_CutBodyPlane
{
    t_Obj3D      _far *obj;
    ushort       upper;
    t_mat44      _far *plane;
    t_Obj3D      _far *res ;
} t_CutBodyPlane;

typedef struct t_ObjToIGS
{
    char         _far *fname ;
} t_ObjToIGS;

typedef struct t_CurvIntrs
{
    t_Obj3D      _far *blank;
    t_Obj3D      _far *tool;
    t_mat44      _far *ecs;
    t_Obj3D      _far *curv ;
} t_CurvIntrs;

typedef struct t_OffsetFace
{
    t_Obj3D      _far *obj;
    double       dist;
    t_Obj3D      _far *ofst ;
} t_OffsetFace;

typedef struct t_GetBGravVol
{
    t_Obj3D     _far *obj;
    double      _far *gpts;
    double      _far *vol ;
} t_GetBGravVol;

typedef struct t_Update2DViews
{
    ulong       flags ;
} t_Update2DViews;

typedef struct t_AdfSize
{
    t_Obj3D     _far *obj;
    t_Adf       _far *adf ;
} t_AdfSize;

typedef struct t_BodyToAdf
{
    t_Obj3D     _far *obj;
    t_Adf       _far *adf ;
} t_BodyToAdf;

typedef struct t_AdfToBody
{
    t_Adf       _far *adf;
    t_Obj3D     _far *obj ;
} t_AdfToBody;

typedef struct t_CutElem
{
    t_entity    _far *ent1;
    t_entity    _far *ent2;
    double      _far *pnt;
    t_point3D   _far *cutp ;
} t_CutElem;

typedef struct t_SetAktProjPara
{
    t_ProjPara   _far *ppara;
    int          hid ;
} t_SetAktProjPara;

typedef struct t_PlaneNormal
{
    t_Obj3D     _far *obj;
    double      _far *nev ;
} t_PlaneNormal;

typedef struct t_PointsToFace
{
    double      _far *pt1;
    double      _far *pt2;
    double      _far *pt3;
    t_Obj3D     _far *obj ;
} t_PointsToFace;

typedef struct t_FaceToPptSize
{
    t_Obj3D     _far *obj;
    int         _far *cnt ;
} t_FaceToPptSize;

typedef struct t_FaceToPpt
{
    t_Obj3D     _far *obj;
    int         _far *cnt;
    t_polypt    _far *ppt ;
} t_FaceToPpt;

typedef struct t_TraverseBody
{
    t_Obj3D      _far *obj;
    int          flags;
    tCallBack    func;
    void         _far *para;
} t_TraverseBody;

typedef struct t_SetBodyTransform
{
    t_Obj3D      _far *obj;
    t_mat44      _far *ecs ;
} t_SetBodyTransform;

typedef struct t_SetMod2D
{
    ushort       mod2D ;
} t_SetMod2D;

typedef struct t_Pnt3DToFace
{
    int         cnt;
    t_point3D   _far *pnt;
    t_Obj3D     _far *obj ;
} t_Pnt3DToFace;

typedef struct t_CountLumps
{
    t_Obj3D     _far *obj ;
} t_CountLumps;

typedef struct t_SplitBodies
{
    t_Obj3D     _far *obj;
    t_Obj3D     _far *objs  ;
} t_SplitBodies;

typedef struct t_IsPlanarFace
{
    t_Obj3D     _far *obj ;
} t_IsPlanarFace;

typedef struct t_GetMod2D
{
    int         dummy;
} t_GetMod2D;

typedef struct t_Set0Ucs
{
    int         dummy;
} t_Set0Ucs;

typedef struct t_GetSelectMode
{
    int         dummy;
} t_GetSelectMode;

typedef struct t_AddEntToMac
{
    ulong       mac_id;
    ushort      type;
    t_attribs   _far *attr;
    void        _far *data;
    t_applic    _far *appl;
    t_mat44     _far *ecs;
} t_AddEntToMac;

typedef union t_MegaPars
{
    t_GetPntInv        m_GetPntInv;
    t_DrawInv          m_DrawInv;
    t_DlgInput         m_DlgInput;
    t_GetFilename      m_GetFilename;
    t_StoreMultiple    m_StoreMultiple;
    t_MegaCMD          m_MegaCMD;
    t_Message          m_Message;
    t_MouseHelp        m_MouseHelp;
    t_GetPnt           m_GetPnt;
    t_savecount        m_savecount;
    t_SetFuncText      m_SetFuncText;
    t_CreateEntity     m_CreateEntity;
    t_GetTextVal       m_GetTextVal;
    t_ReadTxtFile      m_ReadTxtFile;
    t_AddPolylnPt      m_AddPolylnPt;
    t_EraseInv         m_EraseInv;
    t_GetDimVal        m_GetDimVal;
    t_PrintDimVal      m_PrintDimVal;
    t_ClickEntity      m_ClickEntity;
    t_ExChangeEntity   m_ExChangeEntity;
    t_Blink            m_Blink;
    t_EntityLoop       m_EntityLoop;
    t_DrawEntities     m_DrawEntities;
    t_StringInput      m_StringInput;
    t_SelectInit       m_SelectInit;
    t_SelectLoop       m_SelectLoop;
    t_InsertMacro      m_InsertMacro;
    t_CalcPattern      m_CalcPattern;
    t_DeleteEntity     m_DeleteEntity;
    t_GetEntity        m_GetEntity;
    t_SetIncPnt        m_SetIncPnt;
    t_InfoLoop         m_InfoLoop;
    t_GetInfo          m_GetInfo;
    t_StoreInfo        m_StoreInfo;
    t_ExChangeInfo     m_ExChangeInfo;
    t_GetAttributes    m_GetAttributes;
    t_GetLayGrpBits    m_GetLayGrpBits;
    t_GetLayerNames    m_GetLayerNames;
    t_GetGroupNames    m_GetGroupNames;
    t_GetGridSets      m_GetGridSets;
    t_SetAttributes    m_SetAttributes;
    t_SetLayGrpBits    m_SetLayGrpBits;
    t_SetLayerNames    m_SetLayerNames;
    t_SetGroupNames    m_SetGroupNames;
    t_SetGridSets      m_SetGridSets;
    t_GetCurrentFile   m_GetCurrentFile;
    t_CreateMacro      m_CreateMacro;
    t_MacroLoop        m_MacroLoop;
    t_ClickMacro       m_ClickMacro;
    t_EntityLen        m_EntityLen;
    t_PartList         m_PartList;
    t_GetPatternVal    m_GetPatternVal;
    t_GetExpression    m_GetExpression;
    t_DeleteMacro      m_DeleteMacro;
    t_GetMacroInfo     m_GetMacroInfo;
    t_SetMacroInfo     m_SetMacroInfo;
    t_GetPntSymbol     m_GetPntSymbol;
    t_ResetSavecount   m_ResetSavecount;
    t_DoZoom           m_DoZoom;
    t_GetZoom          m_GetZoom;
    t_GetApplID        m_GetApplID;
    t_GetApplName      m_GetApplName;
    t_SelectEntities   m_SelectEntities;
    t_SetHelpFunc      m_SetHelpFunc;
    t_WritePolyBmp     m_WritePolyBmp;
    t_GetEntPtr        m_GetEntPtr;
    t_SetEntPtr        m_SetEntPtr;
    t_SaveToPrt        m_SaveToPrt;
    t_FindPolyLine     m_FindPolyLine;
    t_SaveCurrentFile  m_SaveCurrentFile;
    t_GetMacroPos      m_GetMacroPos;
    t_EntityLoopApp    m_EntityLoopApp;
    t_RunFunction      m_RunFunction;
    t_SetCharSet       m_SetCharSet;
    t_DllCanUnload     m_DllCanUnload;
    t_IsMacroExclusive m_IsMacroExclusive;
    t_GetPntInv3D      m_GetPntInv3D;
    t_GetPnt3D         m_GetPnt3D;
    t_DrawInv3D        m_DrawInv3D;
    t_StoreMultiple3D  m_StoreMultiple3D;
    t_CreateMacro3D    m_CreateMacro3D;
    t_SetIncPnt3D      m_SetIncPnt3D;
    t_GetUcs           m_GetUcs;
    t_SetUcs           m_SetUcs;
    t_InitObj3D        m_InitObj3D;
    t_FreeObj3D        m_FreeObj3D;
    t_CreateCuboid     m_CreateCuboid;
    t_CreateCylinder   m_CreateCylinder;
    t_CreateCone       m_CreateCone;
    t_CreateSphere     m_CreateSphere;
    t_CreateTorus      m_CreateTorus;
    t_BodyUnite        m_BodyUnite;
    t_BodySubtract     m_BodySubtract;
    t_BodyIntersect    m_BodyIntersect;
    t_PlanarFace       m_PlanarFace;
    t_CreateLin3D      m_CreateLin3D;
    t_CreatePrism      m_CreatePrism;
    t_CreateRotBody    m_CreateRotBody;
    t_CreateSweepBody  m_CreateSweepBody;
    t_Pnt3DtoPnt2D     m_Pnt3DtoPnt2D;
    t_Pnt2DtoPnt3D     m_Pnt2DtoPnt3D;
    t_HiddenLine       m_HiddenLine;
    t_HiddenLineMac    m_HiddenLineMac;
    t_HiddenLine2DSeg  m_HiddenLine2DSeg;
    t_GetAktProjPara   m_GetAktProjPara;
    t_BegDrawInvObj3D  m_BegDrawInvObj3D;
    t_EndDrawInvObj3D  m_EndDrawInvObj3D;
    t_DrawInvObj3D     m_DrawInvObj3D;
    t_MatSuperpos      m_MatSuperpos;
    t_GetBodyTransform m_GetBodyTransform;
    t_MatSolve         m_MatSolve;
    t_PntNetIntp       m_PntNetIntp;
    t_SkinWires        m_SkinWires;
    t_MakeCylinderFace m_MakeCylinderFace;
    t_MakeConeFace     m_MakeConeFace;
    t_MakeTorusFace    m_MakeTorusFace;
    t_MakeSphereFace   m_MakeSphereFace;
    t_PlaneToEcs       m_PlaneToEcs;
    t_PointsToEcs      m_PointsToEcs;
    t_CheckMat         m_CheckMat;
    t_Pnt2DtoPnt2D     m_Pnt2DtoPnt2D;
    t_GetBodyGrav      m_GetBodyGrav;
    t_Pnt3DtoPnt3D     m_Pnt3DtoPnt3D;
    t_MacroPos         m_MacroPos;
    t_CutBodyPlane     m_CutBodyPlane;
    t_ObjToIGS         m_ObjToIGS;
    t_CurvIntrs        m_CurvIntrs;
    t_OffsetFace       m_OffsetFace;
    t_GetBGravVol      m_GetBGravVol;
    t_Update2DViews    m_Update2DViews;
    t_AdfSize          m_AdfSize;
    t_BodyToAdf        m_BodyToAdf;
    t_AdfToBody        m_AdfToBody;
    t_CutElem          m_CutElem;
    t_SetAktProjPara   m_SetAktProjPara;
    t_PlaneNormal      m_PlaneNormal;
    t_PointsToFace     m_PointsToFace;
    t_FaceToPptSize    m_FaceToPptSize;
    t_FaceToPpt        m_FaceToPpt;
    t_TraverseBody     m_TraverseBody;
    t_SetBodyTransform m_SetBodyTransform;
    t_SetMod2D         m_SetMod2D;
    t_Pnt3DToFace      m_Pnt3DToFace;
    t_CountLumps       m_CountLumps;
    t_SplitBodies      m_SplitBodies;
    t_IsPlanarFace     m_IsPlanarFace;
    t_GetMod2D         m_GetMod2D;
    t_Set0Ucs          m_Set0Ucs;
    t_GetSelectMode    m_GetSelectMode;
    t_AddEntToMac      m_AddEntToMac;
    uchar              buffer[16];
} t_MegaPars;
#pragma pack ()
