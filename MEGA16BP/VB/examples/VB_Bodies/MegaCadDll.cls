VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "MegaCadDll"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public Function VB_Bodies(ByVal sName As String, ByVal sPara As String) As Integer

    Dim objdata As t_Obj3D
    Dim objcyl As t_Obj3D
    Dim res As t_Obj3D
    Dim ecs As t_mat44

    Call InitInterface
    
    ' initialisieren der 3D Datenstrukturen
    Call InitObj3D(objdata)
    Call InitObj3D(objcyl)
    Call InitObj3D(res)

    ecs.mat(0, 0) = 1#
    ecs.mat(1, 1) = 1#
    ecs.mat(2, 2) = 1#
    ecs.mat(3, 3) = 1#
    
    ' damit sieht die Matrix so aus:
        ' 1.0, 0.0,  0.0,  0.0,
        ' 0.0, 1.0,  0.0,  0.0,
        ' 0.0, 0.0,  1.0,  0.0,
        ' 0.0, 0.0,  0.0,  1.0
    
    ' erzeugen eines Quaders
    Call CreateCuboid(100#, 150#, 50#, NO_t_mat44, objdata)

    ' jetzt einen Zylinder erzeugen
    Call CreateCylinder(200#, 10#, 10#, NO_t_mat44, objcyl)

    ' den Zylinder vom Quader abziehen
    If BodySubtract(objcyl, objdata, False, False, NO_t_mat44, res) <> 0 Then
        Call CreateEntity(E_OBJ3D, NO_t_attribs, res, NO_t_applic, NO_t_mat44)
        Call savecount
    End If

    Call MegaCMD("RegenAll")
    Call Message("Zylinder vom Quader abgezogen", "", vbNullString, vbNullString, "ok", 3)

    ' den Zylinder und den Quader addieren
    ' das Ergebniss etwas versetzen
    ecs.mat(3, 0) = 200#
    ecs.mat(3, 1) = 200#
    If BodyUnite(objcyl, objdata, False, False, NO_t_mat44, res) <> 0 Then
        Call CreateEntity(E_OBJ3D, NO_t_attribs, res, NO_t_applic, ecs)
        Call savecount
    End If

    Call MegaCMD("AutoZoom")
    Call MegaCMD("RegenAll")
    Call Message("Zylinder und Quader addiert", "", vbNullString, vbNullString, "ok", 3)

    ' Durchschnitt aus Zylinder und Quader
    ' das Ergebniss etwas versetzen
    ecs.mat(3, 0) = ecs.mat(3, 0) + 200#
    ecs.mat(3, 1) = ecs.mat(3, 1) + 200#
    If BodyIntersect(objcyl, objdata, False, False, NO_t_mat44, res) Then
        Call CreateEntity(E_OBJ3D, NO_t_attribs, res, NO_t_applic, ecs)
        Call savecount
    End If

    Call MegaCMD("AutoZoom")
    Call MegaCMD("RegenAll")
    Call Message("Durchschnitt aus Zylinder und Quader", "", vbNullString, vbNullString, "ok", 3)

    ' Freigeben der 3D Datenstruktur des Quaders
    Call FreeObj3D(objdata)
    Call FreeObj3D(objcyl)
    Call FreeObj3D(res)

    VB_Bodies = 0
End Function

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

