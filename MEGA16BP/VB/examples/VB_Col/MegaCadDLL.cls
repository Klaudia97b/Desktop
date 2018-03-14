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

Public Function VB_Col(ByVal sName As String, ByVal sPara As String) As Integer
    Dim ent As t_entity
    Dim pnt As t_point      'Platz für den angeklickten Punkt
    Dim Pnt3d As t_point3D      'Platz für den angeklickten Punkt
    Dim lNewID As Long
    Dim iRet As Integer
    Dim mcLine As t_line
    
    Call InitInterface

    ' Funktionsname und Maushilfe setzen
    SetFuncText ("Farbe invertieren")
    Call MouseHelp("Linie anklicken", "zurück", HLP_INV(0, 0, 0))

    ' Element anklicken, wobei hier nur Linien zulässig sind
    Do While ClickEntity(E_LINE_FLAG, 0, pnt, Pnt3d, SNP_ONELM, ent, NO_t_mat44, True) <> 0
        ' Attribute des Elementes ändern
        ent.attr.col = 15 - ent.attr.col
        
        ' Linie Ändern:
        Call GetEntityData(mcLine, ent)
        mcLine.pnt2.x = mcLine.pnt2.x + 10
        mcLine.pnt2.y = mcLine.pnt2.y + 10
        
        ' Element neu speichern
        lNewID = ExChangeEntityData(ent, mcLine, NO_t_mat44)
        Call savecount
    Loop
    VB_Col = 0
End Function

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

