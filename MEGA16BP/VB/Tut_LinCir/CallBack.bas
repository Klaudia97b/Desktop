Attribute VB_Name = "CallBack"
Option Explicit
Public gCircle1 As t_circle
Public gCircle2 As t_circle
Public gLine As t_line

Function MrkCir() As Integer
    Call MouseHelp("Startpunkt", "zurück", HLP_INV(0, 0, 0))
    Call DrawInv(E_CIRCLE, gCircle1, LMODE(0, 0, 0, 0), E_CIRCLE)
End Function

'/**********************************************************************/
'/* Während ein Endpunkt gesetzt wird, soll sowohl ein Kreis           */
'/* ('gCircle2') als auch die Linie ('gLine') an der Maus hängen.      */
'/* Der Radius des Kreises wurde bereits in 'MegaMain()' zugewiesen,der*/
'/* Mittelpunkt des Kreises wird laufend von 'GetPntInv()' eingeräumt. */
'/* Die Linie ('gLine') wird hier berechnet, und zwar so, daß ihre     */
'/* Enden um den Radius der Kreise gekürzt werden.                     */
'/* Linestyle, Farbe und Breite werden von der aktuellen Einstellung   */
'/* für den Elemettyp E_CIRCLE bzw. E_LINE übernommen.                 */
'/**********************************************************************/
Function MrkLin() As Integer
    Dim phi As Double
    Dim dx As Double
    Dim dy As Double
    
    Call MouseHelp("Startpunkt", "Neu ansetzen", HLP_INV(0, 0, 0))
    
    phi = C_atan2(gCircle2.ctr.y - gCircle1.ctr.y, _
                  gCircle2.ctr.x - gCircle1.ctr.x)
    dx = Cos(phi) * gCircle1.rd
    dy = Sin(phi) * gCircle1.rd
    gLine.pnt1.x = gCircle1.ctr.x + dx
    gLine.pnt1.y = gCircle1.ctr.y + dy
    gLine.pnt2.x = gCircle2.ctr.x - dx
    gLine.pnt2.y = gCircle2.ctr.y - dy
    Call DrawInv(E_CIRCLE, gCircle2, LMODE(0, 0, 0, 0), E_CIRCLE)
    Call DrawInv(E_LINE, gLine, LMODE(0, 0, 0, 0), E_LINE)
    
    MrkLin = 0
End Function


