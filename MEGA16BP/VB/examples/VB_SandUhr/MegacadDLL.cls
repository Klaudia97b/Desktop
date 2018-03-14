VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "MegacadDLL"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public Function VB_SandUhr(ByVal sName As String, ByVal sPara As String) As Integer
    Dim fContinue As Boolean
    
    Call InitInterface
    
    gArc1.rd = 5#                  ' Standardwert
    
    DlgInput = True
    fContinue = True

    Call SetFuncText("Sanduhr")
    Do While (RadiusDlg.DlgInput(gArc1.rd) And fContinue)    ' Radius vom Anwender
        Call MouseHelp("1. Punkt", "Neu ansetzen", HLP_INV(0, 0, 0))
        If GetPnt(gPnt1, True) <> 0 Then
            Call MouseHelp("2. Punkt", "Neu ansetzen", HLP_INV(0, 0, 0))
            gArc2.rd = gArc1.rd
            If GetPntInv(gPnt2, True, AddressOf MrkUhr) <> 0 Then
                If gfOK Then
                    Call StoreMultiple(gArc1, E_C_ARC)
                    Call StoreMultiple(gArc2, E_C_ARC)
                    Call StoreMultiple(gLine1, E_LINE)
                    Call StoreMultiple(gLine2, E_LINE)
                    Call savecount
                Else
                    MsgBox "Geht nicht!!"
                End If
            End If
        Else
            fContinue = False
        End If
    Loop
    
    VB_SandUhr = 0
End Function

'*********************************************************************************

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

'*********************************************************************************

