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

Public Function VB_InsMac(ByVal sName As String, ByVal sPara As String) As Integer
    Call InitInterface
    
    Dim buf1 As String
    Dim buf2 As String
    Dim mbuf As String
    
    Dim elins As Integer
    Dim pmac As t_placemac
    Dim ent As t_entity
       
    ' Anzahl für Linien und Bögen initialisieren
    giLanz = 0
    giBanz = 0
 
    ' den Textpuffer vorbesetzen
    mbuf = "c:\megav15\mac\"
    
    ' Namen des Makros eingeben
    If StringInput("Makronamen mit Pfad eingeben", mbuf, 255) <> 0 Then
        ' Makro einfügen, bei jedem Element wird LpCnt aufgerufen
        ' das Makro wird auf die Koordinate 10/10 eingefügt
        pmac.Pnt3d.x = 10
        pmac.Pnt3d.y = 10
        pmac.flags = FM_TAKE_DPT
        
        elins = InsertMacro(mbuf, AddressOf LpCnt, ent, NO_t_mat44, pmac)
        ' elins = Anzahl der eingefügten Elemente
        
        buf1 = "Anzahl Elemente : " & Format(elins)
        buf2 = "Linien : " & Format(giLanz) & " Bögen : " & Format(giBanz)
        Call Message(buf1, buf2, vbNullString, vbNullString, "OK", 3)

        ' Jetzt wird das Makro mit einem Drehwinkel von 45° an 100,100 eingefügt
        pmac.Pnt3d.x = 100
        pmac.Pnt3d.y = 100
        ' phi in rad, nicht in Grad!
        pmac.phi = pi / 4#
        pmac.flags = FM_TAKE_DPT Or FM_TAKE_PHI
        elins = InsertMacro(mbuf, 0, ent, NO_t_mat44, pmac)
    End If
    
    VB_InsMac = 0
End Function

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function


