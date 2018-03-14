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

Public Function VB_SelLoop(ByVal sName As String, ByVal sPara As String) As Integer
    Dim ent As t_entity

    Call InitInterface
    
    SetFuncText ("Farbe invertieren")
    Call MouseHelp("Element wählen", "zurück", HLP_INV(0, 0, 0))
    
    ' Selektionskriterium -> alle Elemente erlaubt
    ' z.B. ( E_LINE_FLAG + E_POINT_FLAG ) selektiert nur Linien und Punkte
    Call SelectInit(E_ALL_FLAG, E_ALL_FLAG)
    
    ' Selektionsschleife: bei jedem gefundenen Element wird SelPid aufgerufen
    Call SelectLoop(AddressOf SelPid, ent, NO_t_mat44, False)
    
    ' alle Elemente, deren ID jetzt in pids steht, invertieren
    Call Blink(AddressOf DoDraw)
    VB_SelLoop = 0

End Function

'*********************************************************************************

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

'*********************************************************************************

