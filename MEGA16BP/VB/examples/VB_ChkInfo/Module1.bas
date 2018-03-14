Attribute VB_Name = "Module1"
Option Explicit
Public mCount As Integer

Function check_info(ByRef ent As t_entity) As Integer
    Dim info As t_entinfo
    
    mCount = mCount + 1
    If ent.attr.iID <> 0 Then
        If GetInfo(ent.attr.iID, info) <> 0 Then
            MsgBox "Elm-ID:" & Format(ent.id) & " Info-ID:" & Format(ent.attr.iID) & _
                   "; mit " & Format(info.numl) & " Zeilen Info"
            MsgBox info.info(0)
        End If
    End If
            
    check_info = CONTINUE_LOOP

End Function

