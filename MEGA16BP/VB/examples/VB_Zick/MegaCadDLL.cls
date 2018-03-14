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

Public Function VB_Zick(ByVal sName As String, ByVal sPara As String) As Integer

    Call InitInterface
    
    Call SetFuncText("Zickzack")
    Do While get_p(gPnt1, "Startpunkt", "zurück")
        Call MouseHelp("Endpunkt", "Neu ansetzen", HLP_INV(0, 0, 0))
        If GetPntInv(gPnt2, 0, AddressOf MrkZik) <> 0 Then
            Call CreateEntity(E_SPLINE, NO_t_attribs, gSpl, NO_t_applic, NO_t_mat44)
            Call savecount
        End If
    Loop
    
    VB_Zick = 0
End Function

'*********************************************************************************

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

'**********************************************************************

Private Function get_p( _
        ByRef pnt As t_point, _
        lft As String, _
        rgt As String) As Boolean
        
    Call MouseHelp(lft, rgt, HLP_INV(0, 0, 0))
    get_p = GetPnt(pnt, 0) <> 0
End Function

'*********************************************************************************

