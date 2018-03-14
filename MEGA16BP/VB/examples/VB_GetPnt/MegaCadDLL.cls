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

Public Function VB_GetPnt(ByVal sName As String, ByVal sPara As String) As Integer
    Dim spt As t_sympnt
    Call InitInterface
    
    Call GetPntSymbol(spt.sym) ' Punkteinstellung von MegaCAD lesen
    MsgBox Format(spt.sym.size)
    
    ' Funktionstext und Maushilfe setzen
    Call SetFuncText("Punkte setzen")
    Call MouseHelp("Punkt setzen", "zurück", HLP_INV(0, 0, 0))
    Do While GetPnt(spt.pnt, 0)
        ' Punkt setzen
        Call CreateEntity(E_POINT, NO_t_attribs, spt, NO_t_applic, NO_t_mat44) ' Punkt erzeugen
        Call savecount   ' Element in UNDO /REDO Liste eintragen
    Loop
End Function

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

