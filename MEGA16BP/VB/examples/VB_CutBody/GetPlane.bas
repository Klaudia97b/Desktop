Attribute VB_Name = "GetPlane"
Option Explicit


'/**********************************************************************/
'/* Festelegen der Ebene über drei Punkte                              */
'/* die drei 3D Punkte werden in eine t_mat44 Matrix umgerechnet       */
'/**********************************************************************/

Function NeueArbeitsebene(ByRef ecs As t_mat44) As Boolean

    Dim p1 As t_point3D
    Dim p2 As t_point3D
    Dim p3 As t_point3D
      
    NeueArbeitsebene = False
    
    ' die neue Arbeitsebene über 3 Punkte bestimmen
    Call Message("Arbeitsebene über 3 Punkte bestimmen", "", vbNullString, vbNullString, "ok", 3)
    Call SetFuncText("Arbeitsebene 3 Punkte")

    If L_GetPoint(1, p1) Then
        If L_GetPoint(2, p2) Then
            If L_GetPoint(3, p3) Then
                ' Die 3 Punkte umrechnen
                If PointsToEcs(p1, p2, p3, ecs) Then
                    ' die aktuelle Arbeitsebene setzen
                   Call SetUcs(ecs)
                   NeueArbeitsebene = True
                Else
                    Call Message("Keine Arbeitsebene bestimmt", "", vbNullString, vbNullString, "ok", 3)
                End If
            End If
        End If
    End If
End Function
    

Function L_GetPoint( _
        ByVal n As Integer, _
        ByRef pnt As t_point3D) As Boolean
        
    Dim sHelp As String
    sHelp = Format(n) + ". Punkt setzen"
    Call MouseHelp(sHelp, "zurück", HLP_INV(0, 0, 0))
    
    ' Punkt setzen
    L_GetPoint = GetPnt3D(pnt, 0)
       
End Function


