Attribute VB_Name = "DelPidModule"
Option Explicit

Function DelPid(ByRef ent As t_entity) As Integer

    DelPid = CONTINUE_LOOP

    If (ent.attr.col = RED) Or (ent.attr.col = BRIGHT_RED) Then
        If DeleteEntity(ent.id) <> 0 Then
            DelPid = CONTINUE_LOOP + CALL_SAVECOUNT
        End If
    End If
End Function
