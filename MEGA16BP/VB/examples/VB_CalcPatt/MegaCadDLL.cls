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
Public Function VB_CalcPatt(ByVal sName As String, ByVal sPara As String) As Integer

    Dim bufP As String
    Dim result As Double
    Dim aPoints() As t_polypt
    
    Call InitInterface
    
    ' aPoints wird als dynamisches Array angelegt, aber leer gelassen.
    ' Damit kann der Anwender in MegaCAD die Polyline auswählen.
    ' Dies entspricht der Übergabe von NULL in C oder C++.

    ' den Umfang einer Polyline berechnen
    ' der Anwender sucht die Polyline selber aus.
    ' wenn alles ok ist, Ergebniss ausgeben
    ' FuncText und MouseHelp müssen nicht gesetzt werden, das macht die Fkt.
    If CalcPattern(CALC_PERIM, 0, aPoints, result) <> 0 Then
        bufP = "Umfang : " & Format(result)
    Else  ' Fehler
        bufP = "Fehler Berechnung UMFANG"
    End If
            
    Call Message(bufP, "", vbNullString, vbNullString, "OK", 3)

    VB_CalcPatt = 0
End Function

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

