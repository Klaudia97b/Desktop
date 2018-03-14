Attribute VB_Name = "Callbacks"
Option Explicit

Dim gaIDs(500) As Long
Dim giIndex As Long

Public Function SelPid(ByRef ent As t_entity) As Integer
    If ent.attr.col = GREEN Then
        gaIDs(giIndex) = ent.id
        giIndex = giIndex + 1
    End If
    SelPid = CONTINUE_LOOP
End Function

'**********************************************************************

Public Function DoDraw() As Integer
    Call DrawEntities(gaIDs, giIndex)
    DoDraw = 0
End Function

