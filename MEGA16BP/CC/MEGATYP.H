/**********************************************************************/
/* MegaCAD entity types.                                              */
/**********************************************************************/

/**********************************************************************/
/* This is the version number of the MegaCAD interface!               */
/* Structure members that are new to version 4 are commented '// !..' */
/**********************************************************************/

#define MI_VERSION 6

#if defined ( MEGATECH_C )

#pragma C-Version MI_VERSION

#endif

/**********************************************************************/

#define E_TXTLIN   1
#define E_POINT    2
#define E_LINE     3
#define E_CIRCLE   4
#define E_C_ARC    5
#define E_H_DIM    6
#define E_V_DIM    7
#define E_P_DIM    8
#define E_A_DIM    9
#define E_D_DIM   10
#define E_R_DIM   11
#define E_T_DIM   12
#define E_SPLINE  13

#define E_TXTBLK  15
#define E_MACRO   16

#define E_XHATCH  18
#define E_ELLIPS  19
#define E_E_ARC   20

#define E_POLYLN  22
#define E_BITMAP  23
#define E_MIDLIN  24

#define E_OBJ3D   27

#define E_FEMBED  32
#define E_ENDMAC  33

#define G_LINE3D   1
#define G_ELLIPS   2
#define G_PLANE   20
#define G_CONE    21
#define G_SPHERE  22
#define G_TORUS   23

/**********************************************************************/

#define POLYLN_MAX  1300
#define POLYGON_MAX 1900

// text font 'System' values
#define GT_TRUETYPE      0
#define GT_VECTOR        1

// text font 'PitchAndFamily' values
#define GT_FFDONTCARE    0x00
#define GT_ROMAN         0x10
#define GT_SWISS         0x20
#define GT_MODERN        0x30
#define GT_SCRIPT        0x40
#define GT_DECORATIVE    0x50

#define GT_FIXED         0x01
#define GT_VARIABLE      0x02

// text font 'CharSet' values
#define GT_ANSI          0
#define GT_SYMBOL        2
#define GT_ASIAN         3
#define GT_OEM           255U

// text font 'Attribs' bits
#define GT_ITALIC        (1<<0)
#define GT_STRIKEOUT     (1<<1)
#define GT_UNDERLINE     (1<<2)
#define GT_BOLD          (1<<3)
#define GT_ISDOWN        (1<<4)

// Snap-Mode
#define SNP_NIX   0
#define SNP_MID   5
#define SNP_END   6
#define SNP_ONELM 8
#define SNP_SWP3  24

#define SELECT_SINGLE   0
#define SELECT_SCR      1
#define SELECT_REC      2
#define SELECT_RECT     3
#define SELECT_PLG      4
#define SELECT_PLGT     5
#define SELECT_CLIN     6
#define SELECT_GRP      7
#define SELECT_LAY      8
#define SELECT_COL      9
#define SELECT_STL     10
#define SELECT_WID     11
#define SELECT_PAT     12
#define SELECT_PLN     13
#define SELECT_AREA    14
#define SELECT_AREAINS 15
#define SELECT_EDGE    16
#define SELECT_AUTO    17

/**********************************************************************/

#if !defined (MEGATECH_C)
    #pragma pack (2)       // set packing to 2 Byte boundaries
#endif

/**********************************************************************/
/* Data-types common to all entity-types.                             */
/**********************************************************************/

typedef struct _attribs
{
    uchar  stl;           // linestyle (1 -  14)
    uchar  pen;           // pen       (0 -  15) user sees (1 - 16) !!!
    uchar  col;           // colour    (1 - 255)
    uchar  wid;           // linewidth (1 -   8)
    uchar  lay;           // layer     (0 - 255)
    uchar  grp;           // group     (0 - 255)
    ushort iID;           // id of entity info
} t_attribs;

/**********************************************************************/
/* Subtypes of MegaCAD-entities.                                      */
/**********************************************************************/

typedef struct _txtval
{
    double w1;           // Text-Angle
    double w2;           // Direction
    double dx;           // char-width
    double dy;           // char-height
    double sx;           // space between two chars
    double ld;           // line distance, relative to char-height
} t_txtval;

typedef struct _txtfnt
{
    uchar name[32];       // facename with TRUETYPE, filename with vector
    uchar CharSet;        // values see above
    uchar PitchAndFamily; // values see above
    uchar System;         // values see above
    uchar Attribs;        // values see above
} t_txtfnt;

typedef struct _polypt
{
    double mpd;           // signed distance of vertex
    double px;            // x-coordinate of point
    double py;            // y-coordinate of point
} t_polypt;

typedef struct _point
{
    double x;             // x-coordinate of point
    double y;             // y-coordinate of point
} t_point;

typedef struct _point3D
{
    double x;             // x-coordinate of point
    double y;             // y-coordinate of point
    double z;             // z-coordinate of point
} t_point3D;

typedef struct _symbol
{
    double size;          // size, if absolute
    ushort type;          // type, bits see below
    uchar  perc;          // size, if relative (in percent of drawing window)
    uchar  fAbs;          // absolute size?
} t_symbol;

#define SYM_CROSS  (1<<0)
#define SYM_DOT    (1<<1)
#define SYM_X      (1<<2)
#define SYM_LINE   (1<<3)
#define SYM_CIRCLE (1<<4)
#define SYM_RECT   (1<<5)
#define SYM_QUAD   (1<<6)

/**********************************************************************/

typedef struct _mat44
{
    double mat[16];
} t_mat44;

typedef struct _Adf
{
    long      pol_cnt;
    long      pnt_cnt;
    long      *pol_lst;
    t_point3D *pnt_lst;
    t_mat44   ecs;
} t_Adf;

/**********************************************************************/
/* The types of the MegaCAD-entities.                                 */
/**********************************************************************/

typedef struct _text
{
    t_txtval val;        // text attributes (see above)
    t_txtfnt fnt;        // text font (see above)
    double   tx;         // x-coordinate of text start point
    double   ty;         // y-coordinate of text start point
    double   dx1;        // baseline vector x-value
    double   dy1;        // baseline vector y-value
    double   dx2;        // leftside vector x-value
    double   dy2;        // leftside vector y-value
    uchar    fIns;       // insert point (0-8) left to right, bottom to top
    uchar    fDrg;       // drag point (0-8) left to right, bottom to top
    uchar    fFmt;       // alignment of block (left(0),right(1),centre(2)
    uchar    fVar;       // parametric text, 1=only identifier, 2=filled in
    ushort   numl;       // number of lines
    char     _far *str;  // char - string
} t_text;     // programmer has to set tx, ty, numl (if E_TXTBLK) and str
              // other members are obtained by GetTxtVal

typedef struct _sympnt
{
    t_point  pnt;        // coordinates
    t_symbol sym;        // symbol description
} t_sympnt;

typedef struct _line
{
    double x1;           // x-coordinate of start point
    double y1;           // y-coordinate of start point
    double x2;           // x-coordinate of end point
    double y2;           // y-coordinate of end point
} t_line;

typedef struct _lin3D
{
    double x1;           // x-coordinate of start point
    double y1;           // y-coordinate of start point
    double z1;           // z-coordinate of start point
    double x2;           // x-coordinate of end point
    double y2;           // y-coordinate of end point
    double z2;           // z-coordinate of end point
} t_lin3D;

typedef struct _circle
{
    double xm;           // x-coordinate of mid point
    double ym;           // y-coordinate of mid point
    double rd;           // radius
} t_circle;

typedef struct _c_arc
{
    double xm;           // x-coordinate of mid point
    double ym;           // y-coordinate of mid point
    double rd;           // radius
    double a1;           // start angle
    double a2;           // end   angle
} t_c_arc;

typedef struct _ellipse
{
    double xm;           // x-coordinate of mid point
    double ym;           // y-coordinate of mid point
    double ra;           // 1st half axis
    double rb;           // 2nd half axis
    double an;           // rotation angle
} t_ellipse;

typedef struct _e_arc
{
    double xm;           // x-coordinate of mid point
    double ym;           // y-coordinate of mid point
    double ra;           // 1st half axis
    double rb;           // 2nd half axis
    double an;           // rotation angle
    double a1;           // start angle (relative to rotation angle)
    double a2;           // end   angle (relative to rotation angle)
} t_e_arc;

typedef struct _polyln
{
    ushort   num;        // number of polyline points
    uchar    fArea;      // is an area (filled in background colour)
    uchar    fnFrame;    // frame (lines & arcs) not drawn
    uchar    atype;      // arrow type (1 - 6) (0 => no arrow)
    uchar    afill;      // arrow filled ?
    double   a_hig;      // arrow height
    double   a_wid;      // arrow width
    double   a_qud;      // arrow quad
    double   a_rad;      // arrow radius
    double   rec[4];     // surrounding rectangle
    t_polypt _far *ppt;  // array of polyline points
} t_polyln;

typedef struct _pattern
{
    double   rec[4];     // surrounding rectangle
    double   vec[2];     // alignment vector
    double   fac;        // factor
    double   phi;        // rotation angle
    char     nam[8];     // cross-hatch name ('xhatch.ini')
    ushort   num;        // number of polyline points
    t_polypt _far *ppt;  // array of polyline points
} t_pattern;

typedef struct _polygon
{
    ushort  num;         // number of points
    t_point _far *pnt;   // array of points
} t_polygon;

typedef struct _dimension
{
    t_txtval val;        // text attributes (see above)
    t_txtfnt fnt;        // text font (see above)
    double   tx;         // x-coordinate of text start point
    double   ty;         // y-coordinate of text start point
    double   dx1;        // baseline vector x-value
    double   dy1;        // baseline vector y-value
    double   dx2;        // leftside vector x-value
    double   dy2;        // leftside vector y-value
    double   x1;         //
    double   y1;         // 1st point
    double   x2;         //
    double   y2;         // 2nd point
    double   x3;         //
    double   y3;         // 3rd point
    double   x4;         //
    double   y4;         // 4th point
    double   a_hig;      // arrow height
    double   a_wid;      // arrow width
    double   a_qud;      // arrow quad
    double   a_rad;      // arrow radius
    double   a_len;      // arrow length
    double   value;      // measured value
    uchar    tcol;       // colour of dim. text
    uchar    twid;       // linewidth of dim. text
    uchar    tpen;       // pen number of dim. text
    uchar    vpos;       // vertical pos.   ( left, mid, right, free )
    uchar    hpos;       // horizontal pos. ( under, above, mid )
    uchar    plft;       // arrow type (1 - 7) of 1st arrow
    uchar    prgt;       // arrow type (1 - 7) of 2nd arrow
    uchar    xyon;       // coordinate dim. type no. (0-3)
    uchar    reli;       // which arrows/dim.lines are to be drawn
    uchar    nins;       // whether inner line of outward dim. is forbidden
    uchar    str2;       // two tolerance text strings ?
    uchar    para;       // is text parallel to dim. line ?
    uchar    edit;       // has text been edited ?
    uchar    insd;       // arrows inside ?
    uchar    mbox;       // E_T_DIM with box ?
    uchar    arch;       // architecture dimension ?
    uchar    fill;       // fill arrow type 2 ?
    uchar    ncut;       // don't cut off trailing zeroes
    uchar    comm;       // 0-15 comma, 16-23 fractional, 24-31 foot/inch
    uchar    flag;       // (flag&1) round to .0/.5, (flag&2) degrees/minutes/seconds
    uchar    pref;       // number of bytes before measured number
    uchar    post;       // number of bytes after measured number
    char     _far *str;  // char - string
} t_dimension;

typedef struct _macro
{
    char    _far *name;  // filename of macro file
    ushort  numl;        // number of lines of macro info
    char    _far *info;  // 'numl' lines of info
} t_macro;

typedef struct _midlin
{
    double mpt[2],       // center point
           cLen,         // length of cross line
           sLen,         // length of short line
           lLen,         // length of long line
           rad,          // radius
           radC,         // radius of 2nd cross element
           phi;          // rotation angle
} t_midlin;

typedef struct _bitmap
{
    double rec[4];       // rectangle
    uchar  fname[126];   // filename of bitmap file
    ushort flags;        // BMP_EMBED
} t_bitmap;

#define BMP_EMBED 1

typedef struct _Obj3D
{
    ulong  body_data;    // body handle
    void   *ptr;         // reserved
    ulong  flags;        // reserved
} t_Obj3D;

typedef struct _DrawInvObj
{
    double  *pnt;        // point to compare mouse position with
    void    *ptr1;       // used internally by MegaCAD!
    void    *ptr2;       // used internally by MegaCAD!
    ulong   i;           // used internally by MegaCAD!
} t_DrawInvObj;

typedef struct _embedfile
{
    ushort flags;        //
    uchar  fname[14];    // current (temp) name
    uchar  oname[128];   // original name
} t_embedfile;

typedef union _en_data
{
    t_text      txt;
    t_sympnt    spt;
    t_line      lin;
    t_circle    cir;
    t_c_arc     arc;
    t_ellipse   elp;
    t_e_arc     ela;
    t_pattern   pat;
    t_polyln    pol;
    t_polygon   spl;
    t_dimension dim;
    t_macro     mac;
    t_midlin    mid;
    t_bitmap    bmp;
    t_Obj3D     body;
    t_embedfile fil;
} t_en_data;

#if !defined ( MEGATECH_C )
    typedef struct _EntPtr t_EntPtr;
#endif

typedef struct _applic
{
    ushort    id;        // ! application ID
    ushort    flags;     // ! flags (APP_LOCKED...)
    ulong     L1;        // ! application data
    ulong     L2;        // ! application data
} t_applic;

#define APP_LOCKED (1<<0)
#define APP_NOTIFY (1<<1)

typedef struct _entity
{
    ushort    type;
    ulong     id;
    t_attribs attr;
    t_applic  appl;      // !
    t_en_data data;
    t_mat44   *ecs;      // ! entity coordinate system
} t_entity;

typedef struct _ProjPara
{
    double  Xvec[3];          // X-vector of the projection plane
    double  Yvec[3];          // Y-vector of the projection plane
    double  dir[3];           // direction of projection
    double  eyepos[3];        // Coordinates of the eye point
    double  dist_front;       // Clip to this Distance
    double  dist_behind;      // Clip behind this Distance
    uchar   fperspective;     // TRUE if perspective projection
    uchar   fparallel;        // TRUE if parallel projection
    uchar   fhid;             // TRUE if hidden segments needed
    uchar   fclp_front;       // TRUE if front clipp is on
    uchar   fclp_behind;      // TRUE if behind clipp is on
} t_ProjPara;

typedef struct _Hid2DSeg
{
    ushort    type;
    t_en_data data;
    t_Obj3D   obj;
    uint      vis;            // TRUE if segment is visible
} t_Hid2DSeg;

typedef struct _SkinCurv
{
    uint     num;
    t_polypt _far *ppt;       // array of polyline points
    t_mat44  *ecs;
} t_SkinCurv;

typedef struct _elip          // ellipse or circle
{
    double centre[3];         // center
    double major_axis[3];     // major axis
    double minor_axis[3];     // minor axis
    double major_radius;      // major radius
    double minor_radius;      // minor radius
    double start_angle;       // start angle in degrees
    double end_angle;         // end angle in degrees
} t_elip;

typedef struct _plane
{
    double normal[3];         // normal defining the plane
    double bpt[3];
} t_plane;

typedef struct _fcone
{
    t_elip base;              // base ellipse
    double sine_angle;        // sine of half-angle
    double cosine_angle;      // cosine of half-angle
} t_fcone;

typedef struct _fsphere
{
    double centre[3];         // center
    double radius;            // radius
} t_fsphere;

typedef struct _ftorus
{
    double centre[3];         // center
    double normal[3];         // normal
    double major_radius;      // major radius of the torus
    double minor_radius;      // minor radius of the torus
} t_ftorus;

typedef union _geomdata
{
    t_lin3D   lin3d;
    t_elip    ell;
    t_plane   pl;
    t_fcone   con;
    t_fsphere sph;
    t_ftorus  torus;
} t_geomdata;

#define TRV_TRANS     (1<<0)
#define TRV_COUNT     (1<<1)

typedef struct _TrvObj
{
    ushort     type;
    t_geomdata gdata;
    ulong      cnt;
} t_TrvObj;

/**********************************************************************/
/* Dialog field descriptor and field types.                           */
/**********************************************************************/

#define DLG_SHT  0     //  = short integer value
#define DLG_LNG  1     //  = long integer value
#define DLG_PHI  2     //  = double value containing an angle
#define DLG_LEN  3     //  = double value in user units
#define DLG_FAC  4     //  = double value containing a factor
#define DLG_STR  5     //  = char string
#define DLG_GRP  6     //  = short integer with group number
#define DLG_LAY  7     //  = short integer with layer number
#define DLG_PEN  8     //  = short integer with pen number
#define DLG_WID  9     //  = short integer with width number
#define DLG_STL 10     //  = short integer with linestyle number
#define DLG_COL 11     //  = short integer with colour number
#define DLG_BUT 12     //  = button instead of input field
#define DLG_DEF 13     //  = button as default button

#define NO_ATTRIB 32232

typedef struct _dlgdta
{
    char     text[26];    // text to the left of input field (or button)
    uchar    type;        // field type
    uchar    slen;        // size of char buffer with DLG_STR
    void     _far *val;   // address of input value (NULL if button)
} t_dlgdta;

/**********************************************************************/
/* Several data types.                                                */
/**********************************************************************/

typedef struct _entinfo
{
    ushort id;            // id
    ushort numl;          // number of lines of text
    uchar  info[15*1024]; // text
} t_entinfo;

typedef struct _laygrp
{
    uchar names[256][64];
} t_laygrp;    // the strlen of each must not be grater than 62!!

typedef struct _grid
{
    double a1, a2,        // angles (Cartesian: 0.0, PI/2)
           dx, dy;        // steps  (in mm)
} t_grid;                 // for a polar grid only 'dx' is used

typedef struct _gridsets
{
    t_grid  DrawGrid;     // draw grid
    t_grid  SnapGrid;     // snap grid
    t_point PtGrid;       // reference point for grid
    t_point PtKeybd;      // reference point for keyboard input
    double  UnitFactor;   // 1.0 for mm, 10.0 for cm, ...
    ushort  iUnit;        // 0=inch,1=mm,2=foot,3=cm,4=yard,5=m,6=factor
    uchar   fCartesian;   // cartesian vs. polar
    uchar   fDraw;        // grid visible?
    uchar   fDrawVals;    // values of 'DrawGrid' active?
    uchar   fSnapVals;    // values of 'SnapGrid' active?
} t_gridsets;

typedef struct _mkmacro
{
    t_attribs _far *attr; // entity attributes (may be NULL)
    void      _far *data; // entity data
    ushort    type;       // entity type
} t_mkmacro;

typedef struct _mkmacro3D
{
    t_attribs _far *attr; // entity attributes (may be NULL)
    void      _far *data; // entity data
    t_mat44   *ecs;       // model coordinate system
    ushort    type;       // entity type
} t_mkmacro3D;

#define FM_EXCLUSIVE      (1<<0)
#define FM_TAKE_FAC       (1<<1)
#define FM_TAKE_YFAC      (1<<2)
#define FM_TAKE_PHI       (1<<3)
#define FM_TAKE_DPT       (1<<4)
#define FM_TAKE_DPT3D     (1<<5)
#define FM_ONLY1          (1<<6)
#define FM_NO_SAVECOUNT   (1<<7)
#define FM_TAKE_FRM       (1<<8)
#define FM_TAKE_ZFAC      (1<<9)

typedef struct _placemac
{
    double  fac;          // scaling factor
    double  yfac;         // y scaling factor
    double  phi;          // rotation angle
    double  dpx;
    double  dpy;
    double  dpz;          // destination point
    t_mat44 *mcs;         // model coordinate system
    ushort  flags;        // flags (see '#defines's above)
    double  zfac;         // z scaling factor
} t_placemac;

typedef struct _invarray
{
    double    _far *pnt;  // point to compare mouse position with (may be NULL)
    t_mkmacro _far *mkm;  // array of entities
    ulong     cnt;        // number of entities
    ulong     i;          // used internally by MegaCAD!
} t_invarray;

typedef struct _invarray3D
{
    double      _far *pnt;// point to compare mouse position with (may be NULL)
    t_mkmacro3D _far *mkm;// array of entities
    ulong       cnt;      // number of entities
    ulong       i;        // used internally by MegaCAD!
} t_invarray3D;

typedef struct _rect
{
    double xmin;
    double ymin;          // lower left corner
    double xmax;
    double ymax;          // upper right corner
} t_rect;

typedef struct _macinfo
{
    t_point rpnt;                  // point of reference
    t_rect  srec[3];               // stretch rectangles
    ushort  numr;                  // number of stretch rectangles
    ushort  numl;                  // number of lines of text DB_Info
    uchar   info[15*1024];         // DB_Info
} t_macinfo;

/**********************************************************************/

#if !defined (MEGATECH_C)
    #pragma pack ()       // back to default
#endif

/**********************************************************************/
