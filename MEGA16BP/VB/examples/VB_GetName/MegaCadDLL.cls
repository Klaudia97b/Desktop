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

Public Function VB_Getname(ByVal sName As String, ByVal sPara As String) As Integer
    Dim szFname As String
    Dim szCommand As String

    Call InitInterface
    
    ' szFname initialisieren
    szFname = "C:\\MEGACAD\\PRT\\*.PRT"
    
    ' Datei auswählen
    If GetFilename("Datei auswählen", szFname) Then
        ' Kommandostring zusammenstellen
        szCommand = "PrtLoad " + szFname
        ' MegaCAD Kommando ausführen
        Call MegaCMD(szCommand)
    End If
End Function

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

