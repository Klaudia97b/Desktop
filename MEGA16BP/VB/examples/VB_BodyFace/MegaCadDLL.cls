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

Public Function VB_BodyFace(ByVal sName As String, ByVal sPara As String) As Integer
    Dim objdata As t_Obj3D
    Dim objcyl As t_Obj3D
    Dim res As t_Obj3D

    Call InitInterface
    
    ' initialisieren der 3D Datenstrukturen
    Call InitObj3D(objdata)
    Call InitObj3D(objcyl)
    Call InitObj3D(res)

    ' erzeugen eines Quaders
    Call CreateCuboid(100#, 150#, 50#, NO_t_mat44, objdata)

    ' jetzt einen Zylinder erzeugen
    Call CreateCylinder(200#, 10#, 10#, NO_t_mat44, objcyl)

    ' jetzt die Schnittkurve(n) berechnen und als Element erzeugen
    If CurvIntrs(objdata, objcyl, NO_t_mat44, res) <> 0 Then
        Call CreateEntity(E_OBJ3D, NO_t_attribs, res, NO_t_applic, NO_t_mat44)
        Call savecount
    End If

    ' Freigeben der 3D Datenstrukturen
    Call FreeObj3D(objdata)
    Call FreeObj3D(objcyl)
    Call FreeObj3D(res)

    VB_BodyFace = 0

End Function

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

