Attribute VB_Name = "MrkCir"
Option Explicit
Public gCircle As t_circle

Function MrkCircle() As Integer
    ' der Kreis wird in weiﬂ gezeichnet
    Call DrawInv(E_CIRCLE, gCircle, LMODE(0, PIX_XOR, BRIGHT_WHITE, 0), E_CIRCLE)
    MrkCircle = 0
End Function
