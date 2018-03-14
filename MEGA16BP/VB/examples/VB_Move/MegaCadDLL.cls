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
Private Const FILTER As Long = (E_LINE_FLAG + E_SPLINE_FLAG + E_POLYLN_FLAG)

Public Function VB_Move(ByVal sName As String, ByVal sPara As String) As Integer
    Dim fStop As Boolean
    Dim pnt3D As t_point3D
    Dim pnt2D As t_point
    
    Call InitInterface
    
    Call SetFuncText("Kopieren")
    Do
        Call MouseHelp("Element wählen", "zurück", HLP_INV(0, 0, 0))
        If ClickEntity(FILTER, 0, pnt2D, pnt3D, 0, gEnt, NO_t_mat44, False) <> 0 Then
            Call move_entity
        Else
            fStop = True
        End If
    Loop Until fStop
    
    VB_Move = 0
End Function

'/**********************************************************************/

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

'/**********************************************************************/

Private Sub move_entity()

    Call MouseHelp("Bezugspunkt", "zurück", HLP_INV(BRIGHT_WHITE, RED, 0))
    If GetPnt(gRefPoint, 0) <> 0 Then
        Call MouseHelp("Zielpunkt", "zurück", HLP_INV(0, 0, 0))
        If GetPntInv(gDestPoint, 0, AddressOf MrkEnt) <> 0 Then
            Select Case gEnt.type
                Case E_LINE
                    Call CreateEntity(E_LINE, NO_t_attribs, gLin, NO_t_applic, NO_t_mat44)
                Case E_SPLINE
                    Call CreateEntity(E_SPLINE, NO_t_attribs, gSpl, NO_t_applic, NO_t_mat44)
                Case E_POLYLN
                    Call CreateEntity(E_POLYLN, NO_t_attribs, gPol, NO_t_applic, NO_t_mat44)
            End Select
            Call savecount
        End If
    End If
    
End Sub
