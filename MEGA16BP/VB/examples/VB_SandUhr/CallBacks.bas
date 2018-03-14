Attribute VB_Name = "CallBacks"
Option Explicit

Public gPnt1 As t_point
Public gPnt2 As t_point
Public gArc1 As t_c_arc
Public gArc2 As t_c_arc
Public gLine1 As t_line
Public gLine2 As t_line
Public gfOK As Boolean
Public DlgInput As Boolean

'**********************************************************************

Private Sub kreispunkt( _
        ByRef mpt As t_c_arc, _
        ByRef pnt As t_point, _
        ByRef phi As Double)
        
    pnt.x = mpt.ctr.x + Cos(phi) * mpt.rd
    pnt.y = mpt.ctr.y + Sin(phi) * mpt.rd

End Sub

'**********************************************************************

Public Function MrkUhr() As Integer
    Dim dLen As Double
    Dim phi As Double
    Dim win As Double
    Dim dia As Double
    Dim dx, dy As Double
    
    win = C_atan2(gPnt2.y - gPnt1.y, gPnt2.x - gPnt1.x)
    dLen = C_hypot(gPnt2.y - gPnt1.y, gPnt2.x - gPnt1.x)
    dia = 2# * gArc1.rd

    If dLen > 2# * dia Then
        gfOK = True
        phi = C_asin(dia / (dLen - dia))
        dx = Cos(win) * gArc1.rd
        dy = Sin(win) * gArc1.rd
        win = win - pi * 0.5
        gArc1.ctr.x = gPnt1.x + dx
        gArc1.ctr.y = gPnt1.y + dy
        gArc1.a1 = win + pi - phi
        gArc1.a2 = win + phi
        gArc2.ctr.x = gPnt2.x - dx
        gArc2.ctr.y = gPnt2.y - dy
        gArc2.a1 = win - phi
        gArc2.a2 = win + pi + phi
        Call kreispunkt(gArc1, gLine1.pnt1, gArc1.a2)
        Call kreispunkt(gArc2, gLine1.pnt2, gArc2.a2)
        Call kreispunkt(gArc1, gLine2.pnt1, gArc1.a1)
        Call kreispunkt(gArc2, gLine2.pnt2, gArc2.a1)

        Call DrawInv(E_C_ARC, gArc1, LMODE(0, 0, 0, 0), E_C_ARC)
        Call DrawInv(E_C_ARC, gArc2, LMODE(0, 0, 0, 0), E_C_ARC)
        Call DrawInv(E_LINE, gLine1, LMODE(0, 0, 0, 0), E_LINE)
        Call DrawInv(E_LINE, gLine2, LMODE(0, 0, 0, 0), E_LINE)
    Else
        gfOK = False
    End If
    
    MrkUhr = 0
End Function


