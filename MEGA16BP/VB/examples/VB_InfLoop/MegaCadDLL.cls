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

Public Function VB_InfLoop(ByVal sName As String, ByVal sPara As String) As Integer
    Dim i As Integer
    Dim buf As String
    Dim buf1 As String
    Dim infoData As t_entinfo

    giIdCnt = 0      ' Zähler vorinitialisieren
    gbIsInfo = False ' wenn keine Infos vorhanden, bleibt isinfo FALSE
 
    Call InitInterface
    
    Call InfoLoop(AddressOf ChkInfo)
    
    If gbIsInfo Then        ' // es wurden Infos gefunden
        For i = 0 To giIdCnt - 1
            buf = ""
            buf1 = ""
            buf = "ID : " & Format(gaIdNum(i))
            ' Infotext holen und die erste Zeile anzeigen
            If GetInfo(gaIdNum(i), infoData) Then
                buf1 = "[" & infoData.info(0) & "]"
            End If
            Call Message(buf, buf1, vbNullString, vbNullString, "OK", 3)
        Next i
    End If

    VB_InfLoop = 0
End Function

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function


