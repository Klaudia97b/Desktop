VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "MegaCAD_DLL"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public Function VB_CutBody(ByVal sName As String, ByVal sPara As String) As Integer

    Dim res As t_Obj3D
    Dim body As t_Obj3D
    Dim bid As Long
    Dim pnt As t_point
    Dim pnt3D As t_point3D
    Dim ent As t_entity
    Dim ecs As t_mat44

    Call InitInterface
    Call SetFuncText("Körper schneiden")

    ' initialisieren der 3D Datenstrukturen
    Call InitObj3D(res)
    Call InitObj3D(body)

    Call MouseHelp("Körper anklicken", "zurück", HLP_INV(0, 0, 0))
    If ClickEntity(E_OBJ3D_FLAG, 0, pnt, pnt3D, SNP_NIX, ent, NO_t_mat44, False) <> 0 Then
        Call GetEntityData(body, ent)
        ' die Schnittfläche bestimmen
        If NeueArbeitsebene(ecs) Then
            ' den Quader mit der Fläche schneiden
            If CutBodyPlane(body, True, ecs, res) Then
                Call CreateEntity(E_OBJ3D, NO_t_attribs, res, NO_t_applic, NO_t_mat44)
                Call savecount
            Else
                Call Message("CutBodyPlane fehlgeschlagen", "", vbNullString, vbNullString, "ok", 3)
            End If
        End If
    End If
    
    VB_CutBody = 0
End Function

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

