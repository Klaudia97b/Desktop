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

Public Function VB_Dimens(ByVal sName As String, ByVal sPara As String) As Integer
 
    Dim y As Double
    Dim ent As t_entity
    Dim tdDim As t_dimension
    Dim pnt As t_point      'Platz für den angeklickten Punkt
    Dim Pnt3d As t_point3D      'Platz für den angeklickten Punkt
    Dim mcLine As t_line

    Call InitInterface
    
    ' Funtionstext und Maushilfe setzen
    SetFuncText ("Linie bemassen horizontal")
    Call MouseHelp("Linie anklicken", "Neu ansetzen", HLP_INV(RED, WHITE, 0))

    ' Element zum Bemassen anklicken, hier werden nur Linien erkannt
    Do While ClickEntity(E_LINE_FLAG, 0, pnt, Pnt3d, SNP_ONELM, ent, NO_t_mat44, False) <> 0
        Call GetEntityData(mcLine, ent)

        ' Linienstartpunkt = erster Bemassungspunkt
        tdDim.pnt1.x = mcLine.pnt1.x
        
        ' Startpunkt eventuell umdrehen, damit die Bemassung immer
        ' über der Linie ist
        If mcLine.pnt1.y > mcLine.pnt2.y Then
            y = mcLine.pnt1.y
        Else
            y = mcLine.pnt2.y
        End If
        
        tdDim.pnt1.y = y
        ' Linienendpunkt = zweiter Bemassungspunkt
        ' aber modifiziert da hier nur horizontale Bemassung
        tdDim.pnt2.x = mcLine.pnt2.x
        tdDim.pnt2.y = y

        ' jetzt die Punkte für die Bemassungslinie setzen
        ' die Linie wird einfach um 5 Einheiten hochgesetzt
        tdDim.pnt3.x = tdDim.pnt1.x
        tdDim.pnt3.y = tdDim.pnt1.y + 5
        tdDim.pnt4.x = tdDim.pnt2.x
        tdDim.pnt4.y = tdDim.pnt1.y + 5
        ' jetzt den Wert berechnen
        tdDim.value = Abs(tdDim.pnt2.x - tdDim.pnt1.x)

        ' und jetzt den Wert in den Textpuffer einräumen
        ' die Toleranztexte bleiben hier leer
        Call PrintDimVal(tdDim.value, tdDim.str, "", "")
        ' jetzt die alle Bemassungswerte von MegaCAD holen
        ' sowie die Textbox berechenen und den Bemassungstext
        ' entsprechend der voreingestellten Werte plazieren
        ' für horizontale Bemassung
        Call GetDimVal(E_H_DIM, 7, tdDim)
        ' Element speichern
        Call CreateEntity(E_H_DIM, NO_t_attribs, tdDim, NO_t_applic, NO_t_mat44)
        
        ' ... und in die UNDO / REDO Liste eintragen
        Call savecount
    Loop
        
End Function

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

