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

Public Function VB_Inv2(ByVal sName As String, ByVal sPara As String) As Integer

    Dim bStop As Boolean

    Call SetFuncText("Sternlinien")
    bStop = False
    
    Do
        Call MouseHelp("Startpunkt", "zurück", HLP_INV(0, 0, 0))
        If GetPnt(gLine.pnt1, 1) <> 0 Then
            Call MouseHelp("Endpunkt", "Neu ansetzen", HLP_INV(0, 0, 0))
            Do While GetPntInv(gLine.pnt2, 0, AddressOf MrkLin) <> 0
                Call StoreMultiple(gLine, E_LINE + DO_SAVCNT)
            Loop
        Else
            bStop = True
        End If
    Loop Until bStop
    
    VB_Inv2 = 0
End Function


Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function


