VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "MegaCadDll"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public Function VB_DrawInv(ByVal sName As String, ByVal sPara As String) As Integer
    Dim bEndLoop As Boolean

    Call InitInterface
    
    ' Radius vorbelegen
    gCircle.rd = 10#
 
    ' den Radius vom Anwender eingeben lassen
    Do While (RadiusDlg.GetRadius(gCircle.rd))
        bEndLoop = False
        Do
            ' Funtionstext und Maushilfe setzen
            Call SetFuncText("Kreise mit Radius")
            Call MouseHelp("Mittelpunkt", "Neu ansetzen", HLP_INV(RED, WHITE, 0))
            ' Punkt holen. Während die Maus bewegt wird, hängt der Kreis am
            ' Mauscursor (MrkCir).
            
            If GetPntInv(gCircle.ctr, 0, AddressOf MrkCircle) Then
                ' Hier wird der Kreis gespeichert, mit den eventuell
                ' eingeschalteten Mehrfachelementen
                Call StoreMultiple(gCircle, E_CIRCLE + DO_SAVCNT)
            Else
                bEndLoop = True
            End If
        Loop Until bEndLoop
    Loop
    
    VB_DrawInv = 0
End Function

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

