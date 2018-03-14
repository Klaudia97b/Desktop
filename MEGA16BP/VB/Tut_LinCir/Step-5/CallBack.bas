Attribute VB_Name = "CallBack"
Option Explicit
Public gCircle As t_circle

Function MrkCir() As Integer
    Call DrawInv(E_CIRCLE, gCircle, lmode(0, 0, 0, 0), E_CIRCLE)
End Function

