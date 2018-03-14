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

Public Function VB_ClickMac(ByVal sName As String, ByVal sPara As String) As Integer

    Dim buf As String
    Dim pnt As t_point
    Dim ent As t_entity
    Dim macro As t_macro
    
    Call InitInterface
    ReDim macro.info(10)
    
    ' Funktionsnamen setzen
    Call SetFuncText("DB Info zeigen")
    ' solange Makros anklicken bis mit rechter Taste abgebrochen wird
    Do While ClickMacro(pnt, ent) <> 0
        ' die erste Zeile der DB Info und den Makronamen anzeigen
        ' wenn vorhanden
        Call GetEntityData(macro, ent)
        MsgBox macro.info(0) & "  " & macro.info(1)
        If macro.numl <> 0 Then
            Call Message(macro.name, macro.info(0), vbNullString, vbNullString, "OK", 3)
        Else
            Call Message(macro.name, _
                    "keine DB Infos ! Makro wird gelöscht !", vbNullString, vbNullString, "OK", 3)
            ' und das Makro jetzt löschen
            Call DeleteMacro(ent.id)
        End If
    Loop
    
    VB_ClickMac = 0
End Function

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

