Attribute VB_Name = "CallBacks"
Option Explicit

Public gPol As t_polyln

Public Function MrkPol() As Integer
    Dim dphi, phi, dx, dy, dLen As Double
    Dim i As Integer
    
    dphi = (2# * pi) / (gPol.num - 1)
    dx = gPol.ppt(1).pnt.x - gPol.ppt(0).pnt.x
    dy = gPol.ppt(1).pnt.y - gPol.ppt(0).pnt.y
    dLen = C_hypot(dx, dy)
    phi = C_atan2(dy, dx)
    i = 1
    Do While i < gPol.num
        phi = phi + dphi
        gPol.ppt(i + 1).pnt.x = gPol.ppt(i).pnt.x + Cos(phi) * dLen
        gPol.ppt(i + 1).pnt.y = gPol.ppt(i).pnt.y + Sin(phi) * dLen
        i = i + 1
    Loop
    Call DrawInv(E_POLYLN, gPol, LMODE(0, 0, 0, 0), E_POLYLN)
    
    MrkPol = 0
End Function



