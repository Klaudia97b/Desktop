VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "MegacadDLL"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit


Public Function VB_SwpBody(ByVal sName As String, ByVal sPara As String) As Integer

    Dim objSweep As t_Obj3D
    Dim objSolid As t_Obj3D
    Dim ppt(0 To 3) As t_polypt
    Dim ppt_path(0 To 2) As t_polypt
    
    Dim ecs As t_mat44
    Dim lcs As t_mat44
    
    Call InitInterface

    ' Standard Koordinatensystem
    '
    '    {1.0, 0.0, 0.0, 0.0 ,
    '     0.0, 1.0, 0.0, 0.0 ,
    '     0.0, 0.0, 1.0, 0.0 ,
    '     0.0, 0.0, 0.0, 1.0 };
    ecs.mat(0, 0) = 1#
    ecs.mat(1, 1) = 1#
    ecs.mat(2, 2) = 1#
    ecs.mat(3, 3) = 1#
    

    ' Koordinatensystem um 90° um die X-Achse gedreht
    '
    '    {1.0, 0.0, 0.0, 0.0 ,
    '     0.0, 0.0, -1.0, 0.0 ,
    '     0.0, 1.0, 0.0, 0.0 ,
    '     0.0, 0.0, 0.0, 1.0 };
    lcs.mat(0, 0) = 1#
    lcs.mat(2, 1) = -1#
    lcs.mat(1, 2) = 1#
    lcs.mat(3, 3) = 1#

    ppt(0).mpd = 0#
    ppt(0).pnt.x = 10#
    ppt(0).pnt.y = 10#

    ppt(1).mpd = 0#
    ppt(1).pnt.x = 10#
    ppt(1).pnt.y = 30#

    ppt(2).mpd = 0#
    ppt(2).pnt.x = 30#
    ppt(2).pnt.y = 10#

    ppt(3).mpd = 0#
    ppt(3).pnt.x = 10#
    ppt(3).pnt.y = 10#

    ppt_path(0).mpd = 0#
    ppt_path(0).pnt.x = 50#
    ppt_path(0).pnt.y = 10#

    ppt_path(1).mpd = 0#
    ppt_path(1).pnt.x = 50#
    ppt_path(1).pnt.y = 50#

    ppt_path(2).mpd = 0#
    ppt_path(2).pnt.x = 90#
    ppt_path(2).pnt.y = 80#

    Call InitObj3D(objSweep)
    Call InitObj3D(objSolid)

    ' Sweepfläche erstellen
    If CreateSweepBody(3, ppt_path, lcs, 4, ppt, ecs, True, False, objSweep) <> 0 Then
        Call CreateEntity(E_OBJ3D, NO_t_attribs, objSweep, NO_t_applic, NO_t_mat44)
        Call savecount
    End If

    ' und jetzt als SOLID etwas verschoben
    If CreateSweepBody(3, ppt_path, lcs, 4, ppt, ecs, True, True, objSolid) <> 0 Then
        ecs.mat(3, 0) = 100#
        ecs.mat(3, 1) = 100#
        Call CreateEntity(E_OBJ3D, NO_t_attribs, objSolid, NO_t_applic, ecs)
        Call savecount
    End If
    
    Call FreeObj3D(objSweep)
    Call FreeObj3D(objSolid)
    
    VB_SwpBody = 0
End Function

'*********************************************************************************

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

'*********************************************************************************

