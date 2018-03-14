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
Public Function VB_TextFile(ByVal sName As String, ByVal sPara As String) As Integer
    Dim strLineBuf As String
    Dim strLineNr As String
    Dim linenum As Integer
    Dim linecnt As Integer
    Dim butret As Integer
    Dim stroffset As Integer
    
    Dim gaTxtBuf() As Byte

    ' die Datei strings.txt wird eingelesen
    linenum = ReadTxtFile("strings.txt", gaTxtBuf, 5000)
    Do While (linecnt < linenum) And (butret <> 3)
        linecnt = linecnt + 1
        strLineNr = "Zeile : " & Format(linecnt)
        strLineBuf = ""
       
        Do While gaTxtBuf(stroffset) <> 0
            strLineBuf = strLineBuf + Chr$(gaTxtBuf(stroffset))
            stroffset = stroffset + 1
        Loop
        
        stroffset = stroffset + 1
        butret = Message(strLineNr, strLineBuf, "OK", vbNullString, "ABBRUCH", 1)
    Loop
End Function

'*********************************************************************************

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

'*********************************************************************************

