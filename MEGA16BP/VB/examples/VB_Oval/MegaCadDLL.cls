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

Public Function VB_Oval(ByVal sName As String, ByVal sPara As String) As Integer

    Call InitInterface
    
    gArc1.rd = 5#
    
    Call GetExpression(sPara, gArc1.rd)     ' Radius übernehmen
                                            ' falls Argumentzeile

    Do
        Call SetFuncText("Oval")
        gArc2.rd = gArc1.rd
        Do While get_p(gArc1.ctr, "Startpunkt", "zurück")
            Call MouseHelp("Endpunkt", "Neu ansetzen", HLP_INV(0, 0, 0))
            Do While GetPntInv(gArc2.ctr, 0, AddressOf MrkOvl) <> 0
                Call CreateEntity(E_C_ARC, NO_t_attribs, gArc1, NO_t_applic, NO_t_mat44)
                Call CreateEntity(E_C_ARC, NO_t_attribs, gArc2, NO_t_applic, NO_t_mat44)
                Call CreateEntity(E_LINE, NO_t_attribs, gLine1, NO_t_applic, NO_t_mat44)
                Call CreateEntity(E_LINE, NO_t_attribs, gLine2, NO_t_applic, NO_t_mat44)
                Call savecount
                gArc1 = gArc2
            Loop
        Loop
        WidthDialog.Show vbModal
    Loop Until gfStop
    
    VB_Oval = 0
End Function

'*********************************************************************************

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

'*********************************************************************************

Private Function get_p( _
        pnt As t_point, _
        lft As String, _
        rgt As String) As Integer
        
    Call MouseHelp(lft, rgt, HLP_INV(0, 0, 0))
    get_p = GetPnt(pnt, 0)
End Function


