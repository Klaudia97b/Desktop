VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "MegaCadDLL"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public Function VB_Neck(ByVal sName As String, ByVal sPara As String) As Integer
    
    Call InitInterface
    
    ReDim gPol.ppt(0 To 31)
    gPol.num = 6
    
    Call SetFuncText("N-Eck (2 P)")
    Do While CntDialog.InputCnt(gPol.num)
        If gPol.num > 31 Then gPol.num = 31
        If gPol.num < 3 Then gPol.num = 3
        Call MouseHelp("Startpunkt", "zurück", HLP_INV(0, 0, 0))
        
        Do While GetPnt(gPol.ppt(0).pnt, 0) <> 0
            gPol.num = gPol.num + 1
            Call MouseHelp("2. Punkt", "neu ansetzen", HLP_INV(0, 0, 0))
            If GetPntInv(gPol.ppt(1).pnt, 0, AddressOf MrkPol) Then
                Call CreateEntity(E_POLYLN, NO_t_attribs, gPol, NO_t_applic, NO_t_mat44)
                Call savecount
            End If
            gPol.num = gPol.num - 1
        Loop
    Loop
    VB_Neck = 0
End Function
Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

