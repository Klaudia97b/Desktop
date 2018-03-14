Attribute VB_Name = "Module1"
Option Explicit

Public Const MAXPIDS As Integer = 500
Dim gaIds(MAXPIDS) As Long
Dim giIdNum As Integer

Function SelPid(ByRef ent As t_entity) As Integer
    gaIds(giIdNum) = ent.id
    giIdNum = giIdNum + 1
    If giIdNum = MAXPIDS Then
        SelPid = BREAK_LOOP
    Else
        SelPid = CONTINUE_LOOP
    End If
End Function

'**********************************************************************

Function DoDraw() As Integer
    Call DrawEntities(gaIds, giIdNum)
    DoDraw = 0
End Function


