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
    gCircle.rd = 5
    
    Do While GetPntInv(gCircle.ctr, False, AddressOf MrkCir) <> 0
        Call CreateEntity(E_CIRCLE, NO_t_attribs, gCircle, NO_t_applic, NO_t_mat44)
    Loop

End Function
    
Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function


