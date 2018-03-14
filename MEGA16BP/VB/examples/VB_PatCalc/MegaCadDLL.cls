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

Public Function VB_PatCalc(ByVal sName As String, ByVal sPara As String) As Integer

    Dim pt(0 To 4) As t_polypt
    Dim dErg As Double
    Dim ptErg As t_point

    Call InitInterface
    
    Call SetP(pt(0), 10#, 10#)
    Call SetP(pt(1), 50#, 10#)
    Call SetP(pt(2), 50#, 50#)
    Call SetP(pt(3), 10#, 50#)
    pt(4) = pt(0)

    If CalcPattern(CALC_PERIM, 5, pt, dErg) <> 0 Then
        MsgBox "Umfang: " & Format(dErg)
    End If
    If (CalcPattern(CALC_AREA, 5, pt, dErg)) <> 0 Then
        MsgBox "Fläche: " & Format(dErg)
    End If
    If CalcPatternPoint(CALC_GRAVITY, 5, pt, ptErg) <> 0 Then
        MsgBox Format(ptErg.x) & " : " & Format(ptErg.y)
    End If
    
    VB_PatCalc = 0
End Function
'*********************************************************************************

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

'***********************************************************************

Private Sub SetP( _
        ByRef pt As t_polypt, _
        ByRef x As Double, _
        ByRef y As Double)

    pt.pnt.x = x
    pt.pnt.y = y
    pt.mpd = 0#
End Sub
