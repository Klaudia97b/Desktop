Attribute VB_Name = "Callbacks"
Option Explicit
Public gRefPoint As t_point
Public gDestPoint As t_point
Public gEnt As t_entity
Public gLin As t_line
Public gSpl As t_polygon
Public gPol As t_polyln

Public Function MrkEnt() As Integer
    Dim dx As Double
    Dim dy As Double
    Dim i As Integer
    
    dx = gDestPoint.x - gRefPoint.x
    dy = gDestPoint.y - gRefPoint.y
    
    Select Case gEnt.type
        Case E_LINE
            Call GetEntityData(gLin, gEnt)
            gLin.pnt1.x = gLin.pnt1.x + dx
            gLin.pnt1.y = gLin.pnt1.y + dy
            gLin.pnt2.x = gLin.pnt2.x + dx
            gLin.pnt2.y = gLin.pnt2.y + dy
            Call DrawInv(E_LINE, gLin, LMODE(0, 0, 0, 0), E_LINE)
        Case E_SPLINE
            Call GetEntityData(gSpl, gEnt)
            For i = 0 To gSpl.num - 1
                gSpl.points(i).x = gSpl.points(i).x + dx
                gSpl.points(i).y = gSpl.points(i).y + dy
            Next i
            Call DrawInv(E_SPLINE, gSpl, LMODE(0, 0, 0, 0), E_SPLINE)
        Case E_POLYLN
            Call GetEntityData(gPol, gEnt)
            For i = 0 To gPol.num - 1
                gPol.ppt(i).pnt.x = gPol.ppt(i).pnt.x + dx
                gPol.ppt(i).pnt.y = gPol.ppt(i).pnt.y + dy
            Next i
            Call DrawInv(E_POLYLN, gPol, LMODE(0, 0, 0, 0), E_POLYLN)
    End Select
    
    MrkEnt = 0
End Function


'/**********************************************************************/


