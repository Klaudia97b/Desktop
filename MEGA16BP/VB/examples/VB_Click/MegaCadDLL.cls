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

Public Function VB_Click(ByVal sName As String, ByVal sPara As String) As Integer

    Dim ent As t_entity
    Dim line As t_line
    Dim pnt As t_point
    Dim Pnt3d As t_point3D
    Dim id As Long
    Dim buf1 As String
    Dim buf2 As String
    
    Call InitInterface

    Call SetFuncText("Koordinaten")
    Call MouseHelp("Linie anklicken", "zurück", HLP_INV(0, 0, 0))
    
    Do While ClickEntity(E_LINE_FLAG, 0, pnt, Pnt3d, SNP_NIX, ent, NO_t_mat44, False)
        Call GetEntityData(line, ent)
        buf1 = " x1:" & Format(line.pnt1.x) & _
               " y1:" & Format(line.pnt1.y) & _
               " x2:" & Format(line.pnt2.x) & _
               " y2:" & Format(line.pnt2.y)

        buf2 = "ID:" & Format(ent.id)
        Call Message(buf1, buf2, vbNullString, vbNullString, "OK", 3)
    Loop
    VB_Click = 0
End Function

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

