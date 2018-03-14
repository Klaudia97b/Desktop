Attribute VB_Name = "CallBack"
Option Explicit

Public giLanz As Integer
Public giBanz As Integer

Public Function LpCnt(ByRef ent As t_entity) As Integer
    ' bei Linien und Bögen einfach zählen, wieviel darin sind
    If ent.iType = E_LINE Then
        giLanz = giLanz + 1
    End If
    If ent.iType = E_C_ARC Then
        giBanz = giBanz + 1
    End If
        
    LpCnt = 0
End Function
 


