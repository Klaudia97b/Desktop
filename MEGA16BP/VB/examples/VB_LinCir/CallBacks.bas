Attribute VB_Name = "CallBacks"
'/**********************************************************************/
'/* Die Callback-Funktionen 'MrkCir()' und 'MrkLin()' m�ssen auf die   */
'/* Kreis- und Liniendaten zugreifen, daher werden sie hier global     */
'/* angelegt                                                           */
'/**********************************************************************/

Public gcirCircle1 As t_circle
Public gcirCircle2 As t_circle
Public gLine As t_line


'/**********************************************************************/
'/* W�hrend der Startpunkt gesetzt wird h�ngt nur ein Kreis an der     */
'/* Maus. Dieser Kreis ('c1') wird mit 'DrawInv()' gezeichnet und      */
'/* gemerkt (damit er beim Redraw nicht verschwindet).                 */
'/* Der Radius des Kreises wird bereits in 'MegaMain()' zugewiesen, der*/
'/* Mittelpunkt wird laufend von 'GetPntInv()' einger�umt. (Siehe      */
'/* Aufruf von GetPntInv!)                                             */
'/* Linestyle, Farbe und Breite werden von der aktuellen Einstellung   */
'/* f�r den Elemettyp E_CIRCLE �bernommen.                             */
'/**********************************************************************/

Function MrkCir() As Integer
    Call DrawInv(E_CIRCLE, gcirCircle1, LMODE(0, 0, 0, 0), E_CIRCLE)
    MrkCir = 0
End Function

'/**********************************************************************/
'/* W�hrend ein Endpunkt gesetzt wird, soll sowohl ein Kreis ('c2')    */
'/* als auch die Linie ('ln') an der Maus h�ngen.                      */
'/* Der Radius des Kreises wurde bereits in 'MegaMain()' zugewiesen,der*/
'/* Mittelpunkt des Kreises wird laufend von 'GetPntInv()' einger�umt. */
'/* Die Linie ('ln') wird hier berechnet, und zwar so, da� ihre Enden  */
'/* um den Radius der Kreise ('c1' und 'c2') gek�rzt werden.           */
'/* Linestyle, Farbe und Breite werden von der aktuellen Einstellung   */
'/* f�r den Elemettyp E_CIRCLE bzw. E_LINE �bernommen.                 */
'/**********************************************************************/

Function MrkLin() As Integer
    Dim phi As Double
    Dim dx As Double
    Dim dy As Double
    
    phi = C_atan2(gcirCircle2.ctr.y - gcirCircle1.ctr.y, _
                  gcirCircle2.ctr.x - gcirCircle1.ctr.x)
    dx = Cos(phi) * gcirCircle1.rd
    dy = Sin(phi) * gcirCircle1.rd
    gLine.pnt1.x = gcirCircle1.ctr.x + dx
    gLine.pnt1.y = gcirCircle1.ctr.y + dy
    gLine.pnt2.x = gcirCircle2.ctr.x - dx
    gLine.pnt2.y = gcirCircle2.ctr.y - dy
    Call DrawInv(E_CIRCLE, gcirCircle2, LMODE(0, 0, 0, 0), E_CIRCLE)
    Call DrawInv(E_LINE, gLine, LMODE(0, 0, 0, 0), E_LINE)
    
    MrkLin = 0
End Function

