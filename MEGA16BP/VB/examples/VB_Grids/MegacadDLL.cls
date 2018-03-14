VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "MegacadDLL"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit
Public Function VB_Grids(ByVal sName As String, ByVal sPara As String) As Integer

    Dim grid As t_gridsets
    Dim buf As String
    Dim buf1 As String
    Dim einheit(0 To 6) As String

    Call InitInterface
    
    einheit(0) = "Inch"
    einheit(1) = "Mm"
    einheit(2) = "Fuss"
    einheit(3) = "Cm"
    einheit(4) = "Yard"
    einheit(5) = "Meter"
    einheit(6) = "Faktor"

    ' die aktuellen Rastereinstellungen holen
    Call GetGridSets(grid)

    If grid.fDraw <> 0 Then
        buf = "Raster sichtbar Einheit " & einheit(grid.iUnit)
        buf1 = "Raster wird ausgeschaltet"
        grid.fDraw = 0
    Else
        buf = "Raster unsichtbar Einheit " & einheit(grid.iUnit)
        buf1 = "Raster wird eingeschaltet"
        grid.fDraw = 1
    End If
    Call Message(buf, buf1, vbNullString, vbNullString, "OK", 3)

    Call SetGridSets(grid)

   VB_Grids = 0
End Function

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function


