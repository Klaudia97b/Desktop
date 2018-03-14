Attribute VB_Name = "CallBacks"
Option Explicit

Public gArc1 As t_c_arc
Public gArc2 As t_c_arc
Public gLine1 As t_line
Public gLine2 As t_line

Public gfStop As Boolean


Public Function MrkOvl() As Integer

    Dim phi, dx, dy As Double
    
    phi = C_atan2(gArc2.ctr.y - gArc1.ctr.y, gArc2.ctr.x - gArc1.ctr.x)
    phi = phi + (pi * 0.5)
    dx = Cos(phi) * gArc1.rd
    dy = Sin(phi) * gArc1.rd
    
    gLine1.pnt1.x = gArc1.ctr.x + dx
    gLine1.pnt1.y = gArc1.ctr.y + dy
    gLine1.pnt2.x = gArc2.ctr.x + dx
    gLine1.pnt2.y = gArc2.ctr.y + dy
    
    gLine2.pnt1.x = gArc1.ctr.x - dx
    gLine2.pnt1.y = gArc1.ctr.y - dy
    gLine2.pnt2.x = gArc2.ctr.x - dx
    gLine2.pnt2.y = gArc2.ctr.y - dy
      
    gArc1.a1 = phi
    gArc1.a2 = phi - pi
    gArc2.a1 = phi - pi
    gArc2.a2 = phi
    
    Call DrawInv(E_LINE, gLine1, LMODE(0, 0, 0, 0), E_LINE)
    Call DrawInv(E_LINE, gLine2, LMODE(0, 0, 0, 0), E_LINE)
    Call DrawInv(E_C_ARC, gArc1, LMODE(0, 0, 0, 0), E_C_ARC)
    Call DrawInv(E_C_ARC, gArc2, LMODE(0, 0, 0, 0), E_C_ARC)
    
    MrkOvl = 0
End Function

