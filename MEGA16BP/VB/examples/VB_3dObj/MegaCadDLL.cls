VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "MegaCadDLL"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public Function VB_3dObj(ByVal sName As String, ByVal sPara As String) As Integer

    Dim mret As Integer
    Dim dret As Integer
    Dim objdata As t_Obj3D
    Dim objcyl  As t_Obj3D
    Dim aktecs As t_mat44

    Call InitInterface
    
    ' initialisieren der 3D Datenstrukturen
    Call InitObj3D(objdata)
    Call InitObj3D(objcyl)

    ' erzeugen eines Quaders
    Call Message("Quader erzeugen", "", vbNullString, vbNullString, "ok", 3)
    Call CreateCuboid(100#, 150#, 50#, NO_t_mat44, objdata)
    ' Element erzeugen
    Call CreateEntity(E_OBJ3D, NO_t_attribs, objdata, NO_t_applic, NO_t_mat44)
    Call savecount

    ' festlegen der neuen Arbeitsebene
    If NeueArbeitsebene(aktecs) Then
        ' jetzt einen Zylinder auf die neue Arbeitsebene setzen
        Call Message("Zylinder erzeugen", "", vbNullString, vbNullString, "ok", 3)
        ' den Zylinder in den Quader setzen
        Call CreateCylinder(200#, 10#, 10#, NO_t_mat44, objcyl)
        Call CreateEntity(E_OBJ3D, NO_t_attribs, objcyl, NO_t_applic, NO_t_mat44)
        Call savecount
    
        'Freigeben der 3D Datenstrukturen
        Call FreeObj3D(objdata)
        Call FreeObj3D(objcyl)
    End If
    
    VB_3dObj = 0

End Function
Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

