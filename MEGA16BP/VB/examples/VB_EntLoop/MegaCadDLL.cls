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

Public Function VB_EntLoop(ByVal sName As String, ByVal sPara As String) As Integer
    Dim ent As t_entity
    
    Call InitInterface
    
    SetFuncText ("Grüne Elemente blinken")
    Call MouseHelp("zurück", "zurück", HLP_INV(0, 0, 0))
    
    ' Schleife über alle Elemente
    Call EntityLoop(E_ALL_FLAG, E_ALL_FLAG, AddressOf SelPid, ent, NO_t_mat44)

    ' alle Elemente, deren ID jetzt in pids steht, blinken
    Call Blink(AddressOf DoDraw)
    VB_EntLoop = 0
End Function

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

