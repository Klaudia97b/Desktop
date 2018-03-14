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

Public Function VB_MacroLoop(ByVal sName As String, ByVal sPara As String) As Integer
    Dim id As Long
    Dim ent As t_entity
    Dim buf As String

    Call InitInterface
    
    giCnt = 0
    ' Über alle eingefügten Makros laufen, bei jeder Linie
    ' die Farbe auf Hellrot und den Linienzähler um 1 hochzählen
    Call MacroLoop(E_LINE_FLAG, 0, 0, AddressOf ModEl, ent, NO_t_mat44)
    buf = "Linien : " & Format(giCnt)
    Call Message(buf, "", vbNullString, vbNullString, "OK", 3)
    VB_MacroLoop = 0

End Function

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

