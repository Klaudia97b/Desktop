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

Public Function VB_Infos(ByVal sName As String, ByVal sPara As String) As Integer

    Dim inf As t_entinfo ' Platz für die Element Infos
    Dim id As Integer
    Dim slen As Integer
    
    Dim string1 As String
    Dim string2 As String
    
    ReDim inf.info(0 To 1)
    
    Call InitInterface
    
    ' den Infotext besetzen 1. Zeile
    inf.info(0) = "Rohr 60 mm"
    ' den Infotext besetzen 2. Zeile
    inf.info(1) = "Länge 450 mm"
    ' Anzahl der Zeilen bekanntgeben
    inf.numl = 2
    
    string1 = "Neue Info mit " & Format(inf.numl) & " Zeilen"
    string2 = inf.info(0) & inf.info(1)
    Call Message(string1, string2, vbNullString, vbNullString, "OK", 3)
    
    ' Info eintragen
    id = StoreInfo(inf)
    If id <> 0 Then
        inf.info(0) = ""
        inf.info(1) = ""
        ' Info wieder einlesen und ausgeben
        Call GetInfo(id, inf)
    Else
        inf.info(0) = "neue Info nicht eingetragen !"
    End If

    Call Message(inf.info(0), inf.info(1), vbNullString, vbNullString, "OK", 3)

    ' jetzt eine dritte Zeile an die Info dranhängen
    ReDim Preserve inf.info(0 To 2)
    inf.info(2) = "Innendurchmesser 40 mm"
    Call Message("ZusatzInfo:", inf.info(2), vbNullString, vbNullString, "OK", 3)

    inf.numl = 3
    id = ExChangeInfo(inf)
    
    inf.info(0) = ""
    inf.info(1) = ""
    inf.info(2) = ""

    If id <> 0 Then
        ' Info wieder einlesen
        Call GetInfo(id, inf)
    Else
        inf.info(0) = "erweiterte Info nicht eingetragen !"
    End If

    Call Message( _
               inf.info(0) & inf.info(1), _
               inf.info(2), _
               vbNullString, vbNullString, "OK", 3)
               
    VB_Infos = 0
End Function

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function


