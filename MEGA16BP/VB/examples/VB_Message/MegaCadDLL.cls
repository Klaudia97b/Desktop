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

Public Function VB_Message(ByVal sName As String, ByVal sPara As String) As Integer
    Dim butret As Integer
    Dim iRet As Integer
    Dim wayout As Boolean

    Do Until wayout
        ' zeigt eine Meldung und wertet den gedrückten Knopf aus.
        butret = Message("Drücken Sie Knopf1 oder Knopf2 oder Knopf 3", _
                         "zum Abbrechen klicken Sie bitte außerhalb", _
                         "Knopf1", "Knopf2", "Knopf3", 3)
        Select Case butret
            Case 1
                iRet = Message("Knopf 1 gedrückt", "", vbNullString, vbNullString, "ok", 3)
            Case 2
                iRet = Message("Knopf 2 gedrückt", "", vbNullString, vbNullString, "ok", 3)
            Case 3
                iRet = Message("Knopf 3 gedrückt", "", vbNullString, vbNullString, "ok", 3)
            Case Else
                iRet = Message("Außerhalb gedrückt", "", vbNullString, vbNullString, "ok", 3)
                wayout = True
        End Select
    Loop
    VB_Message = 0
End Function
Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

