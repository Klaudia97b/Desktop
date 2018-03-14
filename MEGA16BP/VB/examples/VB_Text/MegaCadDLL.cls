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

Public Function VB_Text(ByVal sName As String, ByVal sPara As String) As Integer

    Call InitInterface

    ' Funtionstext setzen
    Call SetFuncText("Text eingeben")

    ' den Text eingeben
    If StringInput("Text eingeben", gTxtData.str, 255) <> 0 Then
        ' die in MegaCAD eingestellten Textdaten holen
        Call GetTextVal(E_TXTLIN, True, gTxtData)
        ' Funktionstext und Maushilfe setzen
        Call SetFuncText("Text setzen")
        Call MouseHelp("Punkt setzen", "zurück", HLP_INV(0, 0, 0))
        ' jetzt den Einfügepunkt für den Text holen
        ' und den Text an die Maus hängen
        If GetPntInv(gTxtData.tpos, 0, AddressOf DrwTxt) <> 0 Then
            ' Element speichern
            Call CreateEntity(E_TXTLIN, NO_t_attribs, gTxtData, NO_t_applic, NO_t_mat44)
            ' ... und in die UNDO / REDO Liste eintragen
            Call savecount
        End If
    End If
    VB_Text = 0
End Function

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

