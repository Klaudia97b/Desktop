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
Public Function VB_Args(ByVal sName As String, ByVal sPara As String) As Integer
    Dim str As String
    
    If sPara <> vbNullString Then
        str = sPara
    Else
        str = "Es wurde kein Argument übergeben!"
    End If
    
    Call Message("Argument:", str, vbNullString, vbNullString, "ok", 3)
   
    VB_Args = 0
    
End Function

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

