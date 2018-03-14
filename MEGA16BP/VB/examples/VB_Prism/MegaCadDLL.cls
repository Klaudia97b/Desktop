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

Public Function VB_Prism(ByVal sName As String, ByVal sPara As String) As Integer
    Dim ppt(0 To 3) As t_polypt
    Dim objdata As t_Obj3D
    Dim vec As t_vector3D
    Dim ecs As t_mat44
    
    Call InitInterface
    
    ecs.mat(0, 0) = 1#
    ecs.mat(1, 1) = 1#
    ecs.mat(2, 2) = 1#
    ecs.mat(3, 3) = 1#
    
    ' jetzt sieht ecs so aus:
    '   1.0, 0.0,  0.0,  0.0,
    '   0.0, 1.0,  0.0,  0.0,
    '   0.0, 0.0,  1.0,  0.0,
    '   0.0, 0.0,  0.0,  1.0
    
    vec.x = 0#
    vec.y = 0#
    vec.z = 1#

    Call SetP(ppt(0), 10#, 10#)
    Call SetP(ppt(1), 10#, 30#)
    Call SetP(ppt(2), 30#, 10#)
    Call SetP(ppt(3), 10#, 10#)

    ' initialisieren der 3D Datenstruktur
    Call InitObj3D(objdata)


    ' Prismenfläche erzeugen
    If CreatePrism(4, ppt, 50, vec, False, ecs, objdata) <> 0 Then
        Call CreateEntity(E_OBJ3D, NO_t_attribs, objdata, NO_t_applic, NO_t_mat44)
        Call savecount
    End If

    ' und jetzt als Solid daneben
    ecs.mat(3, 0) = 50#
    ecs.mat(3, 1) = 50#
    If CreatePrism(4, ppt, 50, vec, True, ecs, objdata) Then
        Call CreateEntity(E_OBJ3D, NO_t_attribs, objdata, NO_t_applic, NO_t_mat44)
        Call savecount
    End If

    ' Freigeben der 3D Datenstruktur
    Call FreeObj3D(objdata)

    VB_Prism = 0
End Function

'*********************************************************************************

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

'*********************************************************************************
Private Sub SetP( _
        ByRef pt As t_polypt, _
        ByRef x As Double, _
        ByRef y As Double)

pt.pnt.x = x
pt.pnt.y = y
pt.mpd = 0#
End Sub

