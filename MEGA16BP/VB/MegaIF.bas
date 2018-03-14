Attribute VB_Name = "MegaIF"
'/**********************************************************************/
'/* The functions of the MegaCAD interface.                            */
'/**********************************************************************/

'**********************************************************************/
'* Data-types common to all entity-types.                             */
'**********************************************************************/

Type t_symbol
    size As Double          ' size, if absolute
    iType As Integer        ' type, bits see below
    perc As Byte            ' size, if relative (in percent of drawing window)
    fAbs As Byte            ' absolute size?
End Type

Type t_attribs
    stl As Byte           ' linestyle (1 -  14)
    pen As Byte           ' pen       (0 -  15) user sees (1 - 16) !!!
    col As Byte           ' colour    (1 - 255)
    wid As Byte           ' linewidth (1 -   8)
    lay As Byte           ' layer     (0 - 255)
    grp As Byte           ' group     (0 - 255)
    iID As Integer        ' id of entity info
End Type

Public NO_t_attribs As t_attribs


Type t_txtval
    w1 As Double         ' Text-Angle
    w2 As Double         ' Direction
    dx As Double         ' char-width
    dy As Double         ' char-height
    sx As Double         ' space between two chars
    ld As Double         ' line distance, relative to char-height
End Type

Type t_txtfnt
    sName As String        ' facename with TRUETYPE, filename with vector
    CharSet As Byte        ' values see GT_ - Constants
    PitchAndFamily As Byte ' values see GT_ - Constants
    System As Byte         ' values see GT_ - Constants
    Attribs As Byte        ' values see GT_ - Constants
End Type

Type t_point
    x As Double            ' x-coordinate of point
    y As Double            ' y-coordinate of point
End Type

Type t_circle
    ctr As t_point         ' centre point
    rd As Double           ' radius
End Type

Type t_c_arc
    ctr As t_point       ' centre point
    rd As Double         ' radius
    a1 As Double         ' start angle
    a2 As Double         ' end   angle
End Type

Type t_ellipse
    ctr As t_point       ' centre point
    ra As Double         ' 1st half axis
    rb As Double         ' 2nd half axis
    an As Double         ' rotation angle
End Type

Type t_e_arc
    ctr As t_point       ' centre point
    ra As Double         ' 1st half axis
    rb As Double         ' 2nd half axis
    an As Double         ' rotation angle
    a1 As Double         ' start angle (relative to rotation angle)
    a2 As Double         ' end   angle (relative to rotation angle)
End Type

Type t_point3D
    x As Double            ' x-coordinate of point
    y As Double            ' y-coordinate of point
    z As Double            ' z-coordinate of point
End Type

Type t_point3D_4
    aPnts(0 To 3) As t_point3D
End Type

Type t_vector
    x As Double
    y As Double
End Type

Type t_vector3D
    x As Double
    y As Double
    z As Double
End Type

Type t_angle_2
    a1 As Double            ' first angle
    a2 As Double            ' second angle
End Type

Type t_line
    pnt1 As t_point         ' start point
    pnt2 As t_point         ' end point
End Type

Type t_sympnt
    pnt As t_point       ' coordinates
    sym As t_symbol      ' symbol description
End Type

Type t_rect
    pnt1 As t_point         ' lower left
    pnt2 As t_point         ' upper right
End Type

Type t_lin3D
    pnt1 As t_point3D       ' start point
    pnt2 As t_point3D       ' end point
End Type

Type t_text
    val As t_txtval          ' text attributes (see above)
    fnt As t_txtfnt          ' text font (see above)
    tpos As t_point          ' coordinates of text start point
    dx1 As Double            ' baseline vector x-value
    dy1 As Double            ' baseline vector y-value
    dx2 As Double            ' leftside vector x-value
    dy2 As Double            ' leftside vector y-value
    fIns As Byte             ' insert point (0-8) left to right, bottom to top
    fDrg As Byte             ' drag point (0-8) left to right, bottom to top
    fFmt As Byte             ' alignment of block (left(0),right(1),centre(2)
    fVar As Byte             ' parametric text, 1=only identifier, 2=filled in
    numl As Integer          ' number of lines
    str As String            ' char - string
End Type                ' programmer has to set tpos.x, tpos.y, numl (if E_TXTBLK) and str
                        ' other members are obtained by GetTxtVal
                        
Type t_dimension
    val As t_txtval      ' text attributes (see above)
    fnt As t_txtfnt      ' text font (see above)
    pntText As t_point   ' text start point
    dx1 As Double        ' baseline vector x-value
    dy1 As Double        ' baseline vector y-value
    dx2 As Double        ' leftside vector x-value
    dy2 As Double        ' leftside vector y-value
    pnt1 As t_point      ' 1st point
    pnt2 As t_point      ' 2nd point
    pnt3 As t_point      ' 3rd point
    pnt4 As t_point      ' 4th point
    a_hig As Double      ' arrow height
    a_wid As Double      ' arrow width
    a_qud As Double      ' arrow quad
    a_rad As Double      ' arrow radius
    a_len As Double      ' arrow length
    value As Double      ' measured value
    tcol As Byte         ' colour of dim. text
    twid As Byte         ' linewidth of dim. text
    tpen As Byte         ' pen number of dim. text
    vpos As Byte         ' vertical pos.   ( left, mid, right, free )
    hpos As Byte         ' horizontal pos. ( under, above, mid )
    plft As Byte         ' arrow type (1 - 7) of 1st arrow
    prgt As Byte         ' arrow type (1 - 7) of 2nd arrow
    xyon As Byte         ' coordinate dim. type no. (0-3)
    reli As Byte         ' which arrows/dim.lines are to be drawn
    nins As Byte         ' whether inner line of outward dim. is forbidden
    str2 As Byte         ' two tolerance text strings ?
    para As Byte         ' is text parallel to dim. line ?
    edit As Byte         ' has text been edited ?
    insd As Byte         ' arrows inside ?
    mbox As Byte         ' E_T_DIM with box ?
    arch As Byte         ' architecture dimension ?
    fill As Byte         ' fill arrow type 2 ?
    ncut As Byte         ' don't cut off trailing zeroes
    comm As Byte         ' 0-15 comma, 16-23 fractional, 24-31 foot/inch
    flag As Byte         ' (flag&1) round to .0/.5, (flag&2) degrees/minutes/seconds
    pref As Byte         ' number of bytes before measured number
    post As Byte         ' number of bytes after measured number
    str As String        ' char - string
End Type

Type t_macro
    name As String       ' filename of macro file
    numl As Integer      ' number of lines of macro info
    info() As String     ' 'numl' lines of info
End Type

Type t_Obj3D
    body_data As Long         ' body handle
    ptr As Long               ' reserved
    flags As Long             ' reserved
End Type

Type t_DrawInvObj
    Pnt3d As t_point3D   ' point to compare mouse position with
    hPtr1 As Long        ' used internally by MegaCAD!
    hPtr2 As Long        ' used internally by MegaCAD!
    i As Long            ' used internally by MegaCAD!
End Type

Type t_polypt
   mpd As Double         ' signed distance of vertex
   pnt As t_point        ' coordinates of point
End Type

Type t_polyln
    num As Integer        ' number of polyline points
    fArea As Byte         ' is an area (filled in background colour)
    fnFrame As Byte       ' frame (lines & arcs) not drawn
    atype As Byte         ' arrow type (1 - 6) (0 => no arrow)
    afill As Byte         ' arrow filled ?
    a_hig As Double       ' arrow height
    a_wid As Double       ' arrow width
    a_qud As Double       ' arrow quad
    a_rad As Double       ' arrow radius
    rec As t_rect         ' surrounding rectangle
    ppt() As t_polypt     ' array of polyline points
End Type

Type t_polygon
    num As Integer        ' number of points
    points() As t_point   ' array of points
End Type

Type t_pattern
    rec As t_rect         ' surrounding rectangle
    vec As t_vector       ' alignment vector
    fac As Double         ' factor
    phi As Double         ' rotation angle
    nam As String         ' cross-hatch name, max 7 Char are used ('xhatch.ini')
    num As Integer        ' number of polyline points
    ppt() As t_polypt     ' array of polyline points
End Type

Type t_entinfo
    id As Integer           ' id
    numl As Integer         ' number of lines of text
    info() As String        ' text
End Type

Type t_grid
    a1 As Double
    a2 As Double            ' angles (Cartesian: 0.0, PI/2)
    dx As Double
    dy As Double            ' steps  (in mm)
End Type                    ' for a polar grid only 'dx' is used

Type t_gridsets
   DrawGrid As t_grid       ' draw grid
   SnapGrid As t_grid       ' snap grid
   PtGrid As t_point        ' reference point for grid
   PtKeybd As t_point       ' reference point for keyboard input
   UnitFactor As Double     ' 1.0 for mm, 10.0 for cm, ...
   iUnit As Integer         ' 0=inch,1=mm,2=foot,3=cm,4=yard,5=m,6=factor
   fCartesian As Byte       ' cartesian vs. polar
   fDraw As Byte            ' grid visible?
   fDrawVals As Byte        ' values of 'DrawGrid' active?
   fSnapVals As Byte        ' values of 'SnapGrid' active?
End Type

Type t_LayGrpBits
    bits(0 To 255) As Byte
End Type

Public Const FM_EXCLUSIVE    As Long = (2 ^ 0)
Public Const FM_TAKE_FAC     As Long = (2 ^ 1)
Public Const FM_TAKE_YFAC    As Long = (2 ^ 2)
Public Const FM_TAKE_PHI     As Long = (2 ^ 3)
Public Const FM_TAKE_DPT     As Long = (2 ^ 4)
Public Const FM_TAKE_DPT3D   As Long = (2 ^ 5)
Public Const FM_ONLY1        As Long = (2 ^ 6)
Public Const FM_NO_SAVECOUNT As Long = (2 ^ 7)
Public Const FM_TAKE_FRM     As Long = (2 ^ 8)
Public Const FM_TAKE_ZFAC    As Long = (2 ^ 9)

Type t_mat44
    mat(0 To 3, 0 To 3) As Double
End Type

Public NO_t_mat44 As t_mat44

Type t_placemac
    fac As Double         ' scaling factor
    yfac As Double        ' y scaling factor
    phi As Double         ' rotation angle
    Pnt3d As t_point3D    ' destination point
    mcs As t_mat44        ' model coordinate system
    flags As Long         ' flags (see Public Const's FM_... above)
    zfac As Double        ' z scaling factor
End Type
             
Type t_applic
    id As Integer       ' ! application ID
    flags As Integer    ' ! flags (APP_LOCKED...)
    L1 As Long          ' ! application data
    L2 As Long          ' ! application data
End Type

Public NO_t_applic As t_applic


Type t_entity
    iType As Integer
    id As Long
    attr As t_attribs
    appl As t_applic
    hData As Long
    hEcs As Long        ' for internal use only, do not change or use!
    ecs As t_mat44
End Type

Type t_Adf
    pol_cnt As Long
    pnt_cnt As Long
    pol_lst() As Long
    pnt_lst() As t_point3D
    ecs As t_mat44
End Type

Type t_ProjPara
   xvec As t_vector3D         ' X-vector of the projection plane
   yvec As t_vector3D         ' Y-vector of the projection plane
   vDir As t_vector3D         ' direction of projection
   eyepos As t_point3D        ' Coordinates of the eye point
   dist_front As Double       ' Clip to this Distance
   dist_behind As Double      ' Clip behind this Distance
   fperspective As Byte       ' TRUE if perspective projection
   fparallel As Byte          ' TRUE if parallel projection
   fhid As Byte               ' TRUE if hidden segments needed
   fclp_front As Byte         ' TRUE if front clipp is on
   fclp_behind As Byte        ' TRUE if behind clipp is on
End Type

Type t_SkinCurv
    num As Long
    ppt() As t_polypt         ' array of polyline points
    ecs As t_mat44
End Type

                                       
Public Const APP_LOCKED As Integer = 1  ' (1<<0)
Public Const APP_NOTIFY As Integer = 2  ' (1<<1)

Public Const E_TXTLIN   As Integer = 1
Public Const E_POINT    As Integer = 2
Public Const E_LINE     As Integer = 3
Public Const E_CIRCLE   As Integer = 4
Public Const E_C_ARC   As Integer = 5
Public Const E_H_DIM   As Integer = 6
Public Const E_V_DIM    As Integer = 7
Public Const E_P_DIM    As Integer = 8
Public Const E_A_DIM   As Integer = 9
Public Const E_D_DIM   As Integer = 10
Public Const E_R_DIM   As Integer = 11
Public Const E_T_DIM   As Integer = 12
Public Const E_SPLINE As Integer = 13

Public Const E_TXTBLK   As Integer = 15
Public Const E_MACRO    As Integer = 16

Public Const E_XHATCH   As Integer = 18
Public Const E_ELLIPS As Integer = 19
Public Const E_E_ARC   As Integer = 20

Public Const E_POLYLN   As Integer = 22
Public Const E_BITMAP As Integer = 23
Public Const E_MIDLIN As Integer = 24

Public Const E_OBJ3D   As Integer = 27

Public Const E_FEMBED As Integer = 32

' Type flags
Public Const E_TXTLIN_FLAG   As Long = 2 ^ E_TXTLIN
Public Const E_POINT_FLAG    As Long = 2 ^ E_POINT
Public Const E_LINE_FLAG     As Long = 2 ^ E_LINE
Public Const E_CIRCLE_FLAG   As Long = 2 ^ E_CIRCLE
Public Const E_C_ARC_FLAG   As Long = 2 ^ E_C_ARC
Public Const E_H_DIM_FLAG   As Long = 2 ^ E_H_DIM
Public Const E_V_DIM_FLAG    As Long = 2 ^ E_V_DIM
Public Const E_P_DIM_FLAG    As Long = 2 ^ E_P_DIM
Public Const E_A_DIM_FLAG   As Long = 2 ^ E_A_DIM
Public Const E_D_DIM_FLAG   As Long = 2 ^ E_D_DIM
Public Const E_R_DIM_FLAG   As Long = 2 ^ E_R_DIM
Public Const E_T_DIM_FLAG   As Long = 2 ^ E_T_DIM
Public Const E_SPLINE_FLAG As Long = 2 ^ E_SPLINE

Public Const E_TXTBLK_FLAG   As Long = 2 ^ E_TXTBLK
Public Const E_MACRO_FLAG    As Long = 2 ^ E_MACRO

Public Const E_XHATCH_FLAG   As Long = 2 ^ E_XHATCH
Public Const E_ELLIPS_FLAG As Long = 2 ^ E_ELLIPS
Public Const E_E_ARC_FLAG   As Long = 2 ^ E_E_ARC

Public Const E_POLYLN_FLAG   As Long = 2 ^ E_POLYLN
Public Const E_BITMAP_FLAG As Long = 2 ^ E_BITMAP
Public Const E_MIDLIN_FLAG As Long = 2 ^ E_MIDLIN

Public Const E_OBJ3D_FLAG  As Long = 2 ^ E_OBJ3D

Public Const E_FEMBED_FLAG As Long = 2 ^ (E_FEMBED - 31)

Public Const E_ALL_FLAG As Long = -1

Public Const POLYLN_MAX As Integer = 1300
Public Const POLYGON_MAX As Integer = 1900

Public Const DO_SAVCNT As Long = (2 ^ 7)

' Zeichenmodi
Public Const PIX_XOR As Integer = 2
Public Const PIX_REP As Integer = 3
Public Const PIX_NO  As Integer = 4

' MegaCAD colour values
Public Const BLACK          As Integer = 0
Public Const BLUE           As Integer = 1
Public Const GREEN          As Integer = 2
Public Const CYAN           As Integer = 3
Public Const RED            As Integer = 4
Public Const MAGENTA        As Integer = 5
Public Const YELLOW         As Integer = 6
Public Const WHITE          As Integer = 7
Public Const BRIGHT_BLACK   As Integer = 8
Public Const BRIGHT_BLUE    As Integer = 9
Public Const BRIGHT_GREEN   As Integer = 10
Public Const BRIGHT_CYAN    As Integer = 11
Public Const BRIGHT_RED     As Integer = 12
Public Const BRIGHT_MAGENTA As Integer = 13
Public Const BRIGHT_YELLOW  As Integer = 14
Public Const BRIGHT_WHITE   As Integer = 15

' Snap-Mode
Public Const SNP_NIX    As Integer = 0
Public Const SNP_MID    As Integer = 5
Public Const SNP_END    As Integer = 6
Public Const SNP_ONELM  As Integer = 8
Public Const SNP_SWP3   As Integer = 24


Public Const CONTINUE_LOOP   As Integer = 0
Public Const CALL_SAVECOUNT As Integer = 1
Public Const BREAK_LOOP As Integer = 2

Public Const CALC_PERIM   As Integer = 0
Public Const CALC_AREA    As Integer = 1
Public Const CALC_GRAVITY As Integer = 2

Public Const LAY_ON   As Integer = (2 ^ 0)
Public Const LAY_LOCK As Integer = (2 ^ 1)
Public Const LAY_ATTR As Integer = (2 ^ 2)

Public Const GRP_ON  As Integer = (2 ^ 4)
Public Const GRP_LOCK As Integer = (2 ^ 5)
Public Const GRP_ATTR As Integer = (2 ^ 6)

Public Const PART_ALL As Integer = 1
Public Const PART_MAC As Integer = 2
Public Const PART_ENT As Integer = 4

Public Const SCF_EXTRACT  As Long = 1
Public Const SCF_ASK_2DWS As Long = 0
Public Const SCF_DO_2DWS  As Long = 2
Public Const SCF_NO_2DWS  As Long = 4

Public Const pi As Double = 3.14159265358979

Public Const MI_VERSION As Integer = 6

' Constants for t_txtfnt
' text font 'System' values
Public Const GT_TRUETYPE As Integer = 0
Public Const GT_VECTOR   As Integer = 1

' text font 'PitchAndFamily' values
Public Const GT_FFDONTCARE  As Integer = 0
Public Const GT_ROMAN       As Integer = 16 ' 0x10
Public Const GT_SWISS       As Integer = 32 ' 0x20
Public Const GT_MODERN      As Integer = 48 ' 0x30
Public Const GT_SCRIPT      As Integer = 64 ' 0x40
Public Const GT_DECORATIVE  As Integer = 90 ' 0x50

Public Const GT_FIXED       As Integer = 1
Public Const GT_VARIABLE    As Integer = 2

' text font 'CharSet' values
Public Const GT_ANSI       As Integer = 0
Public Const GT_SYMBOL     As Integer = 2
Public Const GT_ASIAN      As Integer = 3
Public Const GT_OEM        As Integer = 255

' text font 'Attribs' bits
Public Const GT_ITALIC      As Integer = (2 ^ 0)
Public Const GT_STRIKEOUT   As Integer = (2 ^ 1)
Public Const GT_UNDERLINE   As Integer = (2 ^ 2)
Public Const GT_BOLD        As Integer = (2 ^ 3)
Public Const GT_ISDOWN      As Integer = (2 ^ 4)


'*********************************************************************************
' retrieve current pattern settings
Declare Sub GetPatternVal Lib "megavbasic.dll" Alias "_GetPatternVal@4" ( _
   ByRef pat As t_pattern)
   
Declare Function GetExpression Lib "megavbasic.dll" Alias "_GetExpression@8" _
       (ByVal szString As String, _
        ByRef retval As Double) As Integer
        
Declare Function GetCurrentFile Lib "megavbasic.dll" Alias "_GetCurrentFile@4" _
       (ByRef szString As String) As Integer
       
Declare Function GetPntInv Lib "megavbasic.dll" Alias "_GetPntInv@12" ( _
        ByRef pkt As t_point, _
        ByVal setinc As Integer, _
        ByVal func As Long) As Integer
        
Declare Function GetPnt Lib "megavbasic.dll" Alias "_GetPnt@8" ( _
        ByRef pkt As t_point, _
        ByVal setinc As Integer) As Integer
                    
Declare Sub SetFuncText Lib "megavbasic.dll" Alias "_SetFuncText@4" _
       (ByVal szString As String)
         
Declare Function StringInput Lib "megavbasic.dll" Alias "_StringInput@12" _
       (ByVal szTitle As String, _
        ByRef szBuf As String, _
        ByVal sizeBuf As Integer) As Integer
        
Declare Function Message Lib "megavbasic.dll" Alias "_Message@24" _
       (ByVal str1 As String, _
        ByVal str2 As String, _
        ByVal but1 As String, _
        ByVal but2 As String, _
        ByVal but3 As String, _
        ByVal defbut As Integer) As Integer
        
Declare Function GetFilename Lib "megavbasic.dll" Alias "_GetFilename@8" _
       (ByVal szTitle As String, _
        ByRef szFileName As String) As Integer
        
Declare Sub MegaCMD Lib "megavbasic.dll" Alias "_MegaCMD@4" _
       (ByVal szCommand As String)
  
Declare Sub GetTextVal Lib "megavbasic.dll" Alias "_GetTextVal@12" _
       (ByVal iType As Integer, _
        ByVal iInit As Integer, _
        ByRef txt As t_text)
        
Declare Sub GetDimVal Lib "megavbasic.dll" Alias "_GetDimVal@12" _
       (ByVal iType As Integer, _
        ByVal iInit As Integer, _
        ByRef pDim As t_dimension)
           
Declare Sub MouseHelp Lib "megavbasic.dll" Alias "_MouseHelp@12" _
       (ByVal str1 As String, _
        ByVal str2 As String, _
        ByVal inv As Integer)
        
Declare Function CreateEntity Lib "megavbasic.dll" Alias "_CreateEntity@20" _
       (ByVal iType As Integer, _
        ByRef attr As t_attribs, _
        ByRef data As Any, _
        ByRef appl As t_applic, _
        ByRef ecs As t_mat44) As Long

Declare Sub savecount Lib "megavbasic.dll" Alias "_savecount@0" ()

Declare Sub StoreMultiple Lib "megavbasic.dll" Alias "_StoreMultiple@8" _
        (ByRef data As Any, _
         ByVal iType As Integer)
         
Declare Sub StoreMultiple3D Lib "megavbasic.dll" Alias "_StoreMultiple3D@12" _
        (ByRef data As Any, _
         ByVal iType As Integer, _
         ByRef ecs As t_mat44)

Declare Sub DrawInv Lib "megavbasic.dll" Alias "_DrawInv@16" _
       (ByVal iType As Integer, _
        ByRef ptr As Any, _
        ByVal LMODE As Long, _
        ByVal atype As Integer)

Declare Sub DrawInv3D Lib "megavbasic.dll" Alias "_DrawInv3D@20" _
       (ByVal iType As Integer, _
        ByRef ptr As Any, _
        ByVal LMODE As Long, _
        ByVal atype As Integer, _
        ByRef ecs As t_mat44)

Declare Function LMODE Lib "megavbasic.dll" Alias "_LMODE@16" _
       (ByVal style As Integer, _
        ByVal pixmode As Integer, _
        ByVal col As Integer, _
        ByVal width As Integer) As Long
        
Declare Function HLP_INV Lib "megavbasic.dll" Alias "_HLP_INV@12" _
       (ByVal fore As Integer, _
        ByVal back As Integer, _
        ByVal sound As Boolean) As Integer
        
Declare Function Blink Lib "megavbasic.dll" Alias "_Blink@4" _
       (ByVal func As Long) As Boolean

Declare Sub EraseInv Lib "megavbasic.dll" Alias "_EraseInv@0" ()

Declare Function ClickEntity Lib "megavbasic.dll" Alias "_ClickEntity@32" _
       (ByVal filter1 As Long, _
        ByVal filter2 As Long, _
        ByRef pnt As t_point, _
        ByRef Pnt3d As t_point3D, _
        ByVal snp_mod As Long, _
        ByRef ent As t_entity, _
        ByRef ecs As t_mat44, _
        ByVal fModify As Boolean) As Integer
        
Declare Function ClickMacro Lib "megavbasic.dll" Alias "_ClickMacro@8" ( _
        ByRef pnt As t_point, _
        ByRef ent As t_entity) As Integer
        
Declare Function GetEntity Lib "megavbasic.dll" Alias "_GetEntity@12" ( _
        ByVal id As Long, _
        ByRef ent As t_entity, _
        ByRef ecs As t_mat44) As Integer
                
Declare Function DeleteEntity Lib "megavbasic.dll" Alias "_DeleteEntity@4" ( _
        ByVal id As Long) As Integer
        
Declare Sub GetEntityData Lib "megavbasic.dll" Alias "_GetEntityData@8" _
       (ByRef pData As Any, _
        ByRef entity As t_entity)
        
Declare Sub SetEntityData Lib "megavbasic.dll" Alias "_SetEntityData@8" _
       (ByRef pData As Any, _
        ByRef entity As t_entity)
        
Declare Function ExChangeEntity Lib "megavbasic.dll" Alias "_ExChangeEntity@8" _
       (ByRef ent As t_entity, _
        ByRef ecs As t_mat44) As Long

Declare Function ExChangeEntityData Lib "megavbasic.dll" Alias "_ExChangeEntityData@12" _
       (ByRef ent As t_entity, _
        ByRef data As Any, _
        ByRef ecs As t_mat44) As Long
        
Declare Sub PrintDimVal Lib "megavbasic.dll" Alias "_PrintDimVal@20" _
       (ByVal value As Double, _
        ByRef str As String, _
        ByVal tol1 As String, _
        ByVal tol2 As String)
        
Declare Sub EntityLoop Lib "megavbasic.dll" Alias "_EntityLoop@20" _
       (ByVal filter1 As Long, _
        ByVal filter2 As Long, _
        ByVal func As Long, _
        ByRef ent As t_entity, _
        ByRef ecs As t_mat44)
    
Declare Sub MacroLoop Lib "megavbasic.dll" Alias "_MacroLoop@24" _
       (ByVal filter1 As Long, _
        ByVal filter2 As Long, _
        ByVal start As Long, _
        ByVal func As Long, _
        ByRef ent As t_entity, _
        ByRef ecs As t_mat44)
    
Declare Sub InfoLoop Lib "megavbasic.dll" Alias "_InfoLoop@4" ( _
        ByVal func As Long)
        
Declare Sub GetLastInfo Lib "megavbasic.dll" Alias "_GetLastInfo@4" ( _
        ByRef inf As t_entinfo)
     
Declare Sub DrawEntities Lib "megavbasic.dll" Alias "_DrawEntities@8" _
       (ByRef iArray() As Long, _
        ByVal iCnt As Integer)
        
Declare Sub SelectInit Lib "megavbasic.dll" Alias "_SelectInit@8" _
       (ByVal filter1 As Long, _
        ByVal filter2 As Long)
        
Declare Sub SelectLoop Lib "megavbasic.dll" Alias "_SelectLoop@16" _
       (ByVal func As Long, _
        ByRef ent As t_entity, _
        ByRef ecs As t_mat44, _
        ByVal fModify As Boolean)
              
Declare Function SelectEntities Lib "megavbasic.dll" Alias "_SelectLoop@16" _
       (ByVal func As Long, _
        ByRef ent As t_entity, _
        ByRef ecs As t_mat44, _
        ByVal fModify As Boolean) As Long
              
Declare Function ReadTxtFile Lib "megavbasic.dll" Alias "_ReadTxtFile@12" _
        (ByVal fname As String, _
         ByRef bArray() As Byte, _
         ByVal size As Long) As Integer
               
Declare Sub GetLayerNames Lib "megavbasic.dll" Alias "_GetLayerNames@4" _
        (ByRef names() As String)
       
Declare Sub GetGroupNames Lib "megavbasic.dll" Alias "_GetGroupNames@4" _
        (ByRef names() As String)
        
Declare Sub SetLayerNames Lib "megavbasic.dll" Alias "_SetLayerNames@4" _
        (ByRef names() As String)
       
Declare Sub SetGroupNames Lib "megavbasic.dll" Alias "_SetGroupNames@4" _
        (ByRef names() As String)
        
Declare Function InsertMacro Lib "megavbasic.dll" Alias "_InsertMacro@20" _
        (ByVal fname As String, _
         ByVal func As Long, _
         ByRef ent As t_entity, _
         ByRef ecs As t_mat44, _
         ByRef pmac As t_placemac) As Integer
         
Declare Function DeleteMacro Lib "megavbasic.dll" Alias "_DeleteMacro@4" _
       (ByVal id As Long) As Integer
       
Declare Sub GetPntSymbol Lib "megavbasic.dll" Alias "_GetPntSymbol@4" _
        (ByRef sym As t_symbol)
        
Declare Sub ResetSavecount Lib "megavbasic.dll" Alias "_ResetSavecount@0" ()

Declare Sub DoZoom Lib "megavbasic.dll" Alias "_DoZoom@4" _
       (ByRef rect As t_rect)
        
Declare Sub GetZoom Lib "megavbasic.dll" Alias "_GetZoom@4" _
       (ByRef rect As t_rect)
       
Declare Function GetApplID Lib "megavbasic.dll" Alias "_GetApplID@4" _
       (ByVal sName As String) As Integer

Declare Sub GetApplName Lib "megavbasic.dll" Alias "_GetApplName@8" _
       (ByVal id As Integer, _
        ByRef sName As String)
        
Declare Sub SetHelpFunc Lib "megavbasic.dll" Alias "_SetHelpFunc@4" _
       (ByVal fpHelp As Long)
       
Declare Function WritePolyBmp Lib "megavbasic.dll" Alias "_WritePolyBmp@12" _
       (ByVal fname As String, _
        ByRef poly As t_polygon, _
        ByVal fMax As Byte) As Long
        
Declare Function WritePolyBmpSelect Lib "megavbasic.dll" Alias "_WritePolyBmpSelect@8" _
       (ByVal fname As String, _
        ByVal fMax As Byte) As Long
           
Declare Function StoreInfo Lib "megavbasic.dll" Alias "_StoreInfo@4" ( _
        ByRef inf As t_entinfo) As Integer
        
Declare Function GetInfo Lib "megavbasic.dll" Alias "_GetInfo@8" ( _
        ByVal iID As Integer, _
        ByRef inf As t_entinfo) As Integer
                    
Declare Function ExChangeInfo Lib "megavbasic.dll" Alias "_ExChangeInfo@4" ( _
        ByRef inf As t_entinfo) As Integer
        
Declare Sub GetAttributes Lib "megavbasic.dll" Alias "_GetAttributes@8" ( _
        ByVal iType As Integer, _
        ByRef attr As t_attribs)
        
Declare Sub SetGridSets Lib "megavbasic.dll" Alias "_SetGridSets@4" ( _
        ByRef grid As t_gridsets)

Declare Sub GetGridSets Lib "megavbasic.dll" Alias "_GetGridSets@4" ( _
        ByRef grid As t_gridsets)
        
Declare Sub SetAttributes Lib "megavbasic.dll" Alias "_SetAttributes@8" ( _
        ByVal iType As Integer, _
        ByRef attr As t_attribs)
        
Declare Sub GetLayGrpBits Lib "megavbasic.dll" Alias "_GetLayGrpBits@4" ( _
        ByRef bits As t_LayGrpBits)
                
Declare Sub SetLayGrpBits Lib "megavbasic.dll" Alias "_SetLayGrpBits@4" ( _
        ByRef bits As t_LayGrpBits)
                
Declare Function EntityLen Lib "megavbasic.dll" Alias "_EntityLen@8" ( _
        ByRef ent As t_entity, _
        ByRef dLen As Double) As Integer
        
Declare Function PartList Lib "megavbasic.dll" Alias "_PartList@12" ( _
        ByVal fmt As String, _
        ByVal out As String, _
        ByVal flags As Byte) As Integer
' flags: PART_...
                
                
'res' = 'akt' * 'solve'
Declare Sub MatSolve Lib "megavbasic.dll" Alias "_MatSolve@12" ( _
        ByRef akt As t_mat44, _
        ByRef solve As t_mat44, _
        ByRef res As t_mat44)
                  
Declare Function PointsToEcs Lib "megavbasic.dll" Alias "_PointsToEcs@16" ( _
        ByRef pt1 As t_point3D, _
        ByRef pt1 As t_point3D, _
        ByRef pt1 As t_point3D, _
        ByRef ecs As t_mat44) As Long
        
Declare Sub PlaneToEcs Lib "megavbasic.dll" Alias "_PlaneToEcs@16" ( _
        ByRef xvec As t_vector3D, _
        ByRef yvec As t_vector3D, _
        ByRef origin As t_point3D, _
        ByRef ecs As t_mat44)
        
Declare Sub SetUcs Lib "megavbasic.dll" Alias "_SetUcs@4" ( _
        ByRef ecs As t_mat44)
       
Declare Sub GetUcs Lib "megavbasic.dll" Alias "_GetUcs@4" ( _
        ByRef ecs As t_mat44)
        
Declare Function CheckMat Lib "megavbasic.dll" Alias "_CheckMat@8" ( _
        ByRef ecs As t_mat44, _
        ByRef change As Long) As Long
        
Declare Function FindPolyLine Lib "megavbasic.dll" Alias "_FindPolyLine@4" ( _
        ByRef pkt As t_point) As Long
        
Declare Function SaveCurrentFile Lib "megavbasic.dll" Alias "_SaveCurrentFile@8" _
       (ByVal fname As String, _
        ByVal flags As Long) As Long
             
Declare Function SaveToPrt Lib "megavbasic.dll" Alias "_SaveToPrt@16" _
       (ByVal fname As String, _
        ByRef pid() As Long, _
        ByVal num As Long, _
        ByVal flags As Long) As Integer
        
Declare Sub SetIncPnt Lib "megavbasic.dll" Alias "_SetIncPnt@4" ( _
        ByRef pkt As t_point)
        
Declare Sub SetIncPnt3D Lib "megavbasic.dll" Alias "_SetIncPnt3D@4" ( _
        ByRef pkt As t_point3D)
               
Declare Function GetPntInv3D Lib "megavbasic.dll" Alias "_GetPntInv3D@12" ( _
        ByRef pkt As t_point3D, _
        ByVal setinc As Integer, _
        ByVal func As Long) As Integer
        
Declare Function GetPnt3D Lib "megavbasic.dll" Alias "_GetPnt3D@8" ( _
        ByRef pkt As t_point3D, _
        ByVal setinc As Integer) As Integer
        
Declare Sub InitObj3D Lib "megavbasic.dll" Alias "_InitObj3D@4" ( _
        ByRef obj As t_Obj3D)
        
Declare Sub FreeObj3D Lib "megavbasic.dll" Alias "_FreeObj3D@4" ( _
        ByRef obj As t_Obj3D)
        
Declare Function GetBodyGrav Lib "megavbasic.dll" Alias "_GetBodyGrav@4" ( _
        ByRef obj As t_Obj3D, _
        ByRef gpts As Double) As Long
        
Declare Function CreateCuboid Lib "megavbasic.dll" Alias "_CreateCuboid@32" ( _
        ByVal width As Double, _
        ByVal depth As Double, _
        ByVal height As Double, _
        ByRef ecs As t_mat44, _
        ByRef obj As t_Obj3D) As Long
        
Declare Function CreateCylinder Lib "megavbasic.dll" Alias "_CreateCylinder@32" ( _
        ByVal height As Double, _
        ByVal major As Double, _
        ByVal minor As Double, _
        ByRef ecs As t_mat44, _
        ByRef obj As t_Obj3D) As Long
        
Declare Function CreateCone Lib "megavbasic.dll" Alias "_CreateCone@40" ( _
        ByVal height As Double, _
        ByVal major As Double, _
        ByVal minor As Double, _
        ByVal top As Double, _
        ByRef ecs As t_mat44, _
        ByRef obj As t_Obj3D) As Long
        
Declare Function CreateSphere Lib "megavbasic.dll" Alias "_CreateSphere@16" ( _
        ByVal rad As Double, _
        ByRef ecs As t_mat44, _
        ByRef obj As t_Obj3D) As Long
        
 Declare Function CreateTorus Lib "megavbasic.dll" Alias "_CreateTorus@24" ( _
        ByVal major As Double, _
        ByVal minor As Double, _
        ByRef ecs As t_mat44, _
        ByRef obj As t_Obj3D) As Long
        
Declare Function CreateLin3D Lib "megavbasic.dll" Alias "_CreateLin3D@12" ( _
        ByRef lin As t_lin3D, _
        ByRef attr As t_attribs, _
        ByRef appl As t_applic) As Long
        
Declare Function CreatePrism Lib "megavbasic.dll" Alias "_CreatePrism@32" ( _
        ByVal cnt As Integer, _
        ByRef ppt() As t_polypt, _
        ByVal height As Double, _
        ByRef vec As t_vector3D, _
        ByVal is_solid As Long, _
        ByRef ecs As t_mat44, _
        ByRef obj As t_Obj3D) As Long
        
Declare Function CreateRotBody Lib "megavbasic.dll" Alias "_CreateRotBody@28" ( _
        ByVal cnt As Integer, _
        ByRef ppt() As t_polypt, _
        ByRef axis As t_line, _
        ByRef angle As t_angle_2, _
        ByVal is_solid As Long, _
        ByRef ecs As t_mat44, _
        ByRef obj As t_Obj3D) As Long
                                                        
Declare Function CurvIntrs Lib "megavbasic.dll" Alias "_CurvIntrs@16" ( _
        ByRef blank As t_Obj3D, _
        ByRef tool As t_Obj3D, _
        ByRef ecs As t_mat44, _
        ByRef curv As t_Obj3D) As Long
        
Declare Function BodyUnite Lib "megavbasic.dll" Alias "_BodyUnite@24" ( _
        ByRef tool As t_Obj3D, _
        ByRef blank As t_Obj3D, _
        ByVal del_t As Long, _
        ByVal del_b As Long, _
        ByRef ecs As t_mat44, _
        ByRef res As t_Obj3D) As Long
        
Declare Function BodySubtract Lib "megavbasic.dll" Alias "_BodySubtract@24" ( _
        ByRef tool As t_Obj3D, _
        ByRef blank As t_Obj3D, _
        ByVal del_t As Long, _
        ByVal del_b As Long, _
        ByRef ecs As t_mat44, _
        ByRef res As t_Obj3D) As Long
        
Declare Function BodyIntersect Lib "megavbasic.dll" Alias "_BodyIntersect@24" ( _
        ByRef tool As t_Obj3D, _
        ByRef blank As t_Obj3D, _
        ByVal del_t As Long, _
        ByVal del_b As Long, _
        ByRef ecs As t_mat44, _
        ByRef res As t_Obj3D) As Long
        
Declare Function CutBodyPlane Lib "megavbasic.dll" Alias "_CutBodyPlane@16" ( _
        ByRef obj As t_Obj3D, _
        ByVal upper As Integer, _
        ByRef plane As t_mat44, _
        ByRef res As t_Obj3D) As Long
        
Declare Sub ObjToIGS Lib "megavbasic.dll" Alias "_ObjToIGS@4" ( _
        ByVal fname As String)
        
Declare Function OffsetFace Lib "megavbasic.dll" Alias "_OffsetFace@16" ( _
        ByRef obj As t_Obj3D, _
        ByVal dist As Double, _
        ByRef ofst As t_Obj3D) As Long
        
Declare Function GetBGravVol Lib "megavbasic.dll" Alias "_GetBGravVol@12" ( _
        ByRef obj As t_Obj3D, _
        ByRef gpnt As t_point3D, _
        ByRef vol As Double) As Long
        
Declare Function Update2DViews Lib "megavbasic.dll" Alias "_Update2DViews@4" ( _
        ByVal flags As Long) As Integer
     
Declare Function CreateSweepBody Lib "megavbasic.dll" Alias "_CreateSweepBody@36" ( _
        ByVal cnt_path As Integer, _
        ByRef ppt_path() As t_polypt, _
        ByRef ecs_path As t_mat44, _
        ByVal cnt_prof As Integer, _
        ByRef ppt_prof() As t_polypt, _
        ByRef ecs_prof As t_mat44, _
        ByVal rigid As Boolean, _
        ByVal is_solid As Boolean, _
        ByRef obj As t_Obj3D) As Long
        
Declare Function PlanarFace Lib "megavbasic.dll" Alias "_PlanarFace@16" ( _
        ByVal cnt As Integer, _
        ByRef ppt() As t_polypt, _
        ByRef ecs As t_mat44, _
        ByRef obj As t_Obj3D) As Long
        
Declare Function MakeCylinderFace Lib "megavbasic.dll" Alias "_MakeCylinderFace@36" ( _
        ByVal height As Double, _
        ByVal major As Double, _
        ByVal minor As Double, _
        ByRef angle As t_angle_2, _
        ByRef ecs As t_mat44, _
        ByRef obj As t_Obj3D) As Long
        
Declare Function MakeConeFace Lib "megavbasic.dll" Alias "_MakeConeFace@44" ( _
        ByVal height As Double, _
        ByVal major As Double, _
        ByVal minor As Double, _
        ByVal top As Double, _
        ByRef angle As t_angle_2, _
        ByRef ecs As t_mat44, _
        ByRef obj As t_Obj3D) As Long
        
Declare Function MakeTorusFace Lib "megavbasic.dll" Alias "_MakeTorusFace@40" ( _
        ByVal major As Double, _
        ByVal minor As Double, _
        ByVal top As Double, _
        ByRef u_angle As t_angle_2, _
        ByRef v_angle As t_angle_2, _
        ByRef ecs As t_mat44, _
        ByRef obj As t_Obj3D) As Long
        
Declare Function MakeSphereFace Lib "megavbasic.dll" Alias "_MakeSphereFace@24" ( _
        ByVal rad As Double, _
        ByRef u_angle As t_angle_2, _
        ByRef v_angle As t_angle_2, _
        ByRef ecs As t_mat44, _
        ByRef obj As t_Obj3D) As Long
              
Declare Sub Pnt3DtoPnt2D Lib "megavbasic.dll" Alias "_Pnt3DtoPnt2D@12" ( _
        ByRef Pnt3d As t_point3D, _
        ByRef lcs As t_mat44, _
        ByRef pnt2D As t_point)

Declare Sub Pnt2DtoPnt3D Lib "megavbasic.dll" Alias "_Pnt2DtoPnt3D@12" ( _
        ByRef pnt2D As t_point, _
        ByRef lcs As t_mat44, _
        ByRef Pnt3d As t_point3D)
        
Declare Sub Pnt2DtoPnt2D Lib "megavbasic.dll" Alias "_Pnt2DtoPnt2D@16" ( _
        ByRef pt1 As t_point, _
        ByRef lcs1 As t_mat44, _
        ByRef lcs2 As t_mat44, _
        ByRef pt2 As t_point)
        
Declare Sub Pnt3DtoPnt3D Lib "megavbasic.dll" Alias "_Pnt3DtoPnt3D@16" ( _
        ByRef pt1 As t_point3D, _
        ByRef lcs1 As t_mat44, _
        ByRef lcs2 As t_mat44, _
        ByRef pt2 As t_point3D)
        
Declare Function MacroPos Lib "megavbasic.dll" Alias "_MacroPos@24" ( _
        ByVal fname As String, _
        ByVal func As Long, _
        ByRef pEntity As t_entity, _
        ByVal flags As Integer, _
        ByRef ref As t_mat44, _
        ByRef dst As t_mat44) As Integer

Declare Sub HiddenLine Lib "megavbasic.dll" Alias "_HiddenLine@4" ( _
        ByRef ppara As t_ProjPara)
        
Declare Sub HiddenLineMac Lib "megavbasic.dll" Alias "_HiddenLineMac@16" ( _
        ByRef ppara As t_ProjPara, _
        ByVal num_obj As Long, _
        obj_list() As t_Obj3D, _
        ByVal fname As String)
        
Declare Sub HiddenLine2DSeg Lib "megavbasic.dll" Alias "_HiddenLine2DSeg@20" ( _
        ByRef ppara As t_ProjPara, _
        ByVal num_obj As Long, _
        obj_list() As t_Obj3D, _
        func As Long, _
        ent As t_entity)
        
Declare Sub GetAktProjPara Lib "megavbasic.dll" Alias "_GetAktProjPara@4" ( _
        ByRef ppara As t_ProjPara)
        
Declare Sub BegDrawInvObj3D Lib "megavbasic.dll" Alias "_BegDrawInvObj3D@8" ( _
        ByRef obj As t_Obj3D, _
        ByRef DrwObj As t_DrawInvObj)
        
Declare Sub EndDrawInvObj3D Lib "megavbasic.dll" Alias "_EndDrawInvObj3D@4" ( _
        ByRef DrwObj As t_DrawInvObj)
        
Declare Sub DrawInvObj3D Lib "megavbasic.dll" Alias "_DrawInvObj3D@16" ( _
        ByRef DrwObj As t_DrawInvObj, _
        ByVal LMODE As Long, _
        ByVal atype As Integer, _
        ByRef ecs As t_mat44)
        
Declare Sub MatSuperpos Lib "megavbasic.dll" Alias "_MatSuperpos@12" ( _
        ByRef ecs1 As t_mat44, _
        ByRef ecs2 As t_mat44, _
        ByRef res As t_mat44)
        
Declare Sub GetBodyTransform Lib "megavbasic.dll" Alias "_GetBodyTransform@8" ( _
        ByRef obj As t_Obj3D, _
        ByRef ecs As t_mat44)
        
        
' pnt is a two dimensional array
Declare Function PntNetIntp Lib "megavbasic.dll" Alias "_PntNetIntp@8" ( _
        ByRef pnt() As t_point3D, _
        ByRef obj As t_Obj3D) As Long
        
Declare Function SkinWires Lib "megavbasic.dll" Alias "_SkinWires@12" ( _
        ByVal cnt As Long, _
        ByRef curv() As t_SkinCurv, _
        ByRef obj As t_Obj3D) As Long
               
Declare Function AdfSize Lib "megavbasic.dll" Alias "_AdfSize@8" ( _
        ByRef obj As t_Obj3D, _
        ByRef adf As t_Adf) As Long
               
Declare Function BodyToAdf Lib "megavbasic.dll" Alias "_BodyToAdf@8" ( _
        ByRef obj As t_Obj3D, _
        ByRef adf As t_Adf) As Long
        
Declare Function AdfToBody Lib "megavbasic.dll" Alias "_AdfToBody@8" ( _
        ByRef adf As t_Adf, _
        ByRef obj As t_Obj3D) As Long

Declare Function CutElem Lib "megavbasic.dll" Alias "_CutElem@16" ( _
        ByRef ent1 As t_entity, _
        ByRef ent2 As t_entity, _
        ByRef pnt As t_point3D, _
        ByRef cutp As t_point3D_4) As Long

Declare Sub SetAktProjPara Lib "megavbasic.dll" Alias "_SetAktProjPara@8" ( _
        ByRef ppara As t_ProjPara, _
        ByVal hid As Long)

Declare Function PlaneNormal Lib "megavbasic.dll" Alias "_PlaneNormal@8" ( _
        ByRef obj As t_Obj3D, _
        ByRef nev As t_vector3D) As Long

Declare Function PointsToFace Lib "megavbasic.dll" Alias "_PointsToFace@16" ( _
        ByRef pt1 As t_point3D, _
        ByRef pt2 As t_point3D, _
        ByRef pt3 As t_point3D, _
        ByRef obj As t_Obj3D) As Long

Declare Function FaceToPptSize Lib "megavbasic.dll" Alias "_FaceToPptSize@8" ( _
        ByRef obj As t_Obj3D, _
        ByRef cnt As Long) As Long
        
Declare Function FaceToPpt Lib "megavbasic.dll" Alias "_FaceToPpt@12" ( _
        ByRef obj As t_Obj3D, _
        ByRef cnt As Long, _
        ByRef pnts() As t_polypt) As Long
        
Declare Function SetBodyTransform Lib "megavbasic.dll" Alias "_SetBodyTransform@8" ( _
        ByRef obj As t_Obj3D, _
        ByRef ecs As t_mat44) As Long

' Parameter mod2D = TRUE --> mod2D else mod3D
Declare Sub SetMod2D Lib "megavbasic.dll" Alias "_SetMod2D@4" ( _
        ByVal mod2D As Integer)
        
Declare Function Pnt3DToFace Lib "megavbasic.dll" Alias "_Pnt3DToFace@12" ( _
        ByVal cnt As Long, _
        ByRef pnts() As t_point3D, _
        ByRef obj As t_Obj3D) As Long
        
'*************  Polylines *****************
Declare Function AddPolylnPt Lib "megavbasic.dll" Alias "_AddPolylnPt@20" _
       (ByRef poly As t_polyln, _
        ByVal x As Double, _
        ByVal y As Double) As Integer

Declare Function AddPolylnJump Lib "megavbasic.dll" Alias "_AddPolylnJump@20" _
       (ByRef poly As t_polyln, _
        ByVal x As Double, _
        ByVal y As Double) As Integer

Declare Function AddPolylnCir Lib "megavbasic.dll" Alias "_AddPolylnCir@28" _
       (ByRef poly As t_polyln, _
        ByVal x As Double, _
        ByVal y As Double, _
        ByVal mpd As Double) As Integer
        
Declare Function CalcPattern Lib "megavbasic.dll" Alias "_CalcPattern@16" ( _
        ByVal which As Integer, _
        ByVal cnt As Integer, _
        ByRef ppt() As t_polypt, _
        ByRef result As Double) As Integer
        
Declare Function CalcPatternPoint Lib "megavbasic.dll" Alias "_CalcPattern@16" ( _
        ByVal which As Integer, _
        ByVal cnt As Integer, _
        ByRef ppt() As t_polypt, _
        ByRef result As t_point) As Integer
        
 '************* Low level helpers *****************
 
Declare Function C_asin Lib "megavbasic.dll" Alias "_C_asin@8" ( _
        ByVal phi As Double) As Double

Declare Function C_acos Lib "megavbasic.dll" Alias "_C_acos@8" ( _
        ByVal phi As Double) As Double

Declare Function C_atan2 Lib "megavbasic.dll" Alias "_C_atan2@16" ( _
        ByVal y As Double, _
        ByVal x As Double) As Double

Declare Function C_hypot Lib "megavbasic.dll" Alias "_C_hypot@16" ( _
        ByVal x As Double, _
        ByVal y As Double) As Double

Declare Function GetArrayElementCount Lib "megavbasic.dll" Alias "_GetArrayElementCount@8" ( _
        ByRef saArray() As Any, _
        ByVal iDim As Integer) As Long
    
Declare Sub CopyMemory Lib "KERNEL32" Alias "RtlMoveMemory" ( _
        lpvDest As Any, lpvSource As Any, ByVal cbCopy As Long)
    
Declare Sub MakeInvalid Lib "megavbasic.dll" Alias "_MakeInvalid@8" ( _
        ByRef lpvDest As Any, _
        ByVal iSize As Long)
    
Declare Sub TestVbArray Lib "megavbasic.dll" Alias "_TestVbArray@4" ( _
        ByRef lpvDest() As Any)
    
'***************  Wrappers **********************

Sub InitInterface()
    Call MakeInvalid(NO_t_mat44, Len(NO_t_mat44))
    Call MakeInvalid(NO_t_attribs, Len(NO_t_attribs))
    Call MakeInvalid(NO_t_applic, Len(NO_t_applic))
End Sub


