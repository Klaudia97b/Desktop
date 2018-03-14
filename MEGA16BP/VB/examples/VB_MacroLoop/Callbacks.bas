Attribute VB_Name = "Callbacks"
Option Explicit
Public giCnt As Integer

Function ModEl(ByRef ent As t_entity) As Integer
    If ent.iType = E_LINE Then
        giCnt = giCnt + 1
        ent.attr.col = BRIGHT_RED
        Call ExChangeEntity(ent, NO_t_mat44)
    End If
    
    ModEl = CONTINUE_LOOP
End Function


