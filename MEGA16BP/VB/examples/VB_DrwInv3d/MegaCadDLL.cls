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

Public Function VB_DrwInv3d(ByVal sName As String, ByVal sPara As String) As Integer

    Call InitInterface
    
    Dim objcyl As t_Obj3D
    Dim ecs1 As t_mat44
    Dim ecs2 As t_mat44
    Dim mat As t_mat44

    ' initialisieren der 3D Datenstruktur
    Call InitObj3D(objcyl)

    Call GetUcs(mat)

    gLcs = mat

    ' den Zylinder erzeugen
    Call CreateCylinder(200#, 10#, 10#, NO_t_mat44, objcyl)

    ' initialisieren der DrawInv Struktur
    Call BegDrawInvObj3D(objcyl, gDrawObject)

    Do While GetPntInv3D(gDrawObject.Pnt3d, 0, AddressOf DrwObj) <> 0
        Call GetBodyTransform(objcyl, ecs1)
        Call MatSolve(ecs1, ecs2, gLcs)
        Call CreateEntity(E_OBJ3D, NO_t_attribs, objcyl, NO_t_applic, ecs2)
        Call savecount
    Loop

    ' Freigeben der DrawInv Struktur
    Call EndDrawInvObj3D(gDrawObject)
    ' Freigeben der 3D Datenstruktur
    Call FreeObj3D(objcyl)

    VB_DrwInv3d = 0
End Function

'*********************************************************************************

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

'**********************************************************************
