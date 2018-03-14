Attribute VB_Name = "CallBack"
Option Explicit

Public gTxtData As t_text

Public Function DrwTxt() As Integer
    Call DrawInv(E_TXTLIN, gTxtData, LMODE(0, 0, 0, 0), E_TXTLIN)
    DrwTxt = 0
End Function

