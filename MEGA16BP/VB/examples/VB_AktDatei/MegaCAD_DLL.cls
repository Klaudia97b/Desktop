VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "MegaCAD_DLL"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public Function VB_AktDatei(ByVal sName As String, ByVal sPara As String) As Integer
    Dim curfile As String
    Dim txt As String
    Call InitInterface
    
    txt = "Aktuelle Zeichnung:"

    If GetCurrentFile(curfile) = 0 Then
        txt = "Keine Zeichnung geladen!"
    End If
    
    Call Message(txt, curfile, vbNullString, vbNullString, "ok", 3)
    VB_AktDatei = 0
End Function

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

