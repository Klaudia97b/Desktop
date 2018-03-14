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

Public Function VB_LinCir(ByVal sName As String, ByVal sPara As String) As Integer
    Call InitInterface
    
    gCircle1.rd = 5
    Call GetExpression(sPara, gCircle1.rd)
    
    Call SetFuncText("Linien - Endkreise")
  
    Do While GetPntInv(gCircle1.ctr, False, AddressOf MrkCir) <> 0
        ' Ersten Kreis eines Linienzuges eintragen:
        Call CreateEntity(E_CIRCLE, NO_t_attribs, gCircle1, NO_t_applic, NO_t_mat44)
        
        ' Die weiteren Kreise haben den selben Radius
        gCircle2.rd = gCircle1.rd
        Do While GetPntInv(gCircle2.ctr, False, AddressOf MrkLin) <> 0
            Call CreateEntity(E_CIRCLE, NO_t_attribs, gCircle2, NO_t_applic, NO_t_mat44)
            Call CreateEntity(E_LINE, NO_t_attribs, gLine, NO_t_applic, NO_t_mat44)
            Call savecount
            
            ' Den bisherigen Endkreis zum neuen Startkreis machen.
            gCircle1 = gCircle2
        Loop
    Loop

End Function
    
Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

