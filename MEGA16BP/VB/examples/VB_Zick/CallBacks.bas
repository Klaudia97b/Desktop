Attribute VB_Name = "CallBacks"
Option Explicit

Public gSpl As t_polygon
Public gPnt1 As t_point
Public gPnt2 As t_point

'*********************************************************************

Private Sub add_pt( _
        ByRef spl As t_polygon, _
        ByVal x As Double, _
        ByVal y As Double)
        
    Dim lSizeArray As Long
    lSizeArray = GetArrayElementCount(spl.points, 0)
    
    If spl.num >= lSizeArray - 1 Then
        ReDim Preserve spl.points(0 To lSizeArray + 20 - 1)
    End If
    
    spl.points(spl.num).x = x
    spl.points(spl.num).y = y
    spl.num = spl.num + 1
    
End Sub

'*********************************************************************

Public Function MrkZik() As Integer
    Dim l, dLen, phi, phi1 As Double
    Dim px, py As Double
    Dim dx1, dy1 As Double
    Dim co, si As Double

    dLen = C_hypot(gPnt2.y - gPnt1.y, gPnt2.x - gPnt1.x)
    phi = C_atan2(gPnt2.y - gPnt1.y, gPnt2.x - gPnt1.x)
    phi1 = phi + (75# * pi / 180#)
    dx1 = Cos(phi1) * 2#
    dy1 = Sin(phi1) * 2#
    co = Cos(phi)
    si = Sin(phi)
    gSpl.num = 0
    Call add_pt(gSpl, gPnt1.x, gPnt1.y)
    l = 5#
    Do While l < dLen
        px = gPnt1.x + co * l
        py = gPnt1.y + si * l
        Call add_pt(gSpl, px, py)
        Call add_pt(gSpl, px + dx1, py + dy1)
        l = l + 2#
        px = gPnt1.x + co * l
        py = gPnt1.y + si * l
        Call add_pt(gSpl, px - dx1, py - dy1)
        Call add_pt(gSpl, px, py)
        
        l = l + 8#
    Loop
    Call add_pt(gSpl, gPnt2.x, gPnt2.y)
    Call DrawInv(E_SPLINE, gSpl, LMODE(0, 0, 0, 0), E_SPLINE)
    
    MrkZik = 0
End Function


