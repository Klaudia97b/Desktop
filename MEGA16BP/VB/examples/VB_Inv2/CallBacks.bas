Attribute VB_Name = "CallBacks"
Public gLine As t_line

Function MrkLin() As Integer
    Call DrawInv(E_LINE, gLine, LMODE(0, 0, 0, 0), E_LINE)
    MrkLin = 0
End Function

