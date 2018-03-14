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

Public Function VB_LayGrp(ByVal sName As String, ByVal sPara As String) As Integer

    Dim layer As t_LayGrpBits     ' Platz für die Layer Bits
    Dim layNames() As String      ' Platz für die Layer Namen
    Dim i, but As Integer
    Dim buf As String

    Call GetLayGrpBits(layer)    ' die Layereinstellungen holen
    Call GetLayerNames(layNames) ' die Layernamen holen
      
    For i = 0 To 255
        If layer.bits(i) And LAY_ON Then ' wenn Layer eingeschaltet, Namen anzeigen
            buf = "Layer Nummer (" & Format(i) & ") eingeschaltet"
            but = Message(buf, layNames(i), "OK", vbNullString, "ABBRUCH", 1)
            If but = 3 Then GoTo END_FOR_1
        End If
    Next i
    
END_FOR_1:
    
    ' Layer Nr. 11 - 200 ausschalten
    For i = 11 To 200
        layer.bits(i) = layer.bits(i) And Not LAY_ON
    Next i
    Call Message("Layer 11 - 200 ausgeschaltet", "", vbNullString, vbNullString, "OK", 3)

    ' Layer Nr. 1 - 10 neue Namen setzen
    For i = 1 To 10
        layNames(i) = "Layername : " & Format(i) & ".ter Layer"
    Next i
    Call SetLayerNames(layNames)
    Call Message("Layer 1 - 10 bekommen neue Namen", "Layername : .ter Layer", _
                  vbNullString, vbNullString, "OK", 3)
                  
                  
    Call GetLayerNames(layNames) ' die Layernamen holen
    For i = 0 To 255
        If layer.bits(i) And LAY_ON Then ' wenn Layer eingeschaltet, Namen anzeigen
            buf = "Layer Nummer (" & Format(i) & ") eingeschaltet"
            but = Message(buf, layNames(i), "OK", vbNullString, "ABBRUCH", 1)
            If but = 3 Then GoTo END_FOR_2
        End If
    Next i
    
END_FOR_2:
    
    VB_LayGrp = 0
End Function

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function



