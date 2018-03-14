Attribute VB_Name = "CallBack"
Option Explicit

Public gDrawObject As t_DrawInvObj
Public gLcs As t_mat44

' Man beachte, daﬂ GetPntInv3D die Koordinaten der Maus in gDrawObject.Pnt3d
' ablegt (siehe den Aufruf von GetPntInv3D in VB_DrWinV3d).

Public Function DrwObj() As Integer
    gLcs.mat(3, 0) = gDrawObject.Pnt3d.x
    gLcs.mat(3, 1) = gDrawObject.Pnt3d.y
    gLcs.mat(3, 2) = gDrawObject.Pnt3d.z + 100#
    Call DrawInvObj3D(gDrawObject, LMODE(0, 0, 0, 0), E_OBJ3D, gLcs)
    
    DrwObj = 0
End Function


