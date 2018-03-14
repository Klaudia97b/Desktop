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
'/**********************************************************************/
'/*                                                                    */
'/* lin_cir.c                                                          */
'/*                                                                    */
'/* Mit diesem DLL-Programm kann der MegaCAD-Anwender einen            */
'/* Linienzug konstruieren, bei dem an den Endpunkten der Linien       */
'/* ein Kreis erzeugt wird. Die Linien werden an den Rändern der       */
'/* Kreise abgeschnitten.                                              */
'/*                                                                    */
'/**********************************************************************/

Public Function VB_LinCir(ByVal sName As String, ByVal sPara As String) As Integer
    Dim bStop As Boolean
    
    Call InitInterface
    
    bStop = False
    gcirCircle1.rd = 5#                           ' Standardwert
    
                                                  ' falls Argumentzeile
    Call GetExpression(sPara, gcirCircle1.rd)     ' Radius übernehmen

    Call SetFuncText("Linien - Endkreise")
    
    Do
        Call MouseHelp("Startpunkt", "Neu ansetzen", HLP_INV(0, 0, 0))

        '/* Hier wird der Startpunkt eines Linienzuges gesetzt.    */
        '/* Bei Abbruch mit rechter Maustaste wird beendet.        */

        If GetPntInv(gcirCircle1.ctr, True, AddressOf MrkCir) <> 0 Then
            '/* Hier wird der Kreis um den Startpunkt gespeichert. */
            Call StoreMultiple(gcirCircle1, E_CIRCLE + DO_SAVCNT)

            '/* Der zweite Kreis hat denselben Radius.             */
            gcirCircle2.rd = gcirCircle1.rd
            Call MouseHelp("Endpunkt", "zurück", HLP_INV(0, 0, 0))

            '/* Hier wird der Endpunkt einer Linie gesetzt. Bei    */
            '/* Abbruch mit rechter Maustaste zurück zum Startpunkt*/
            
            Do While GetPntInv(gcirCircle2.ctr, True, AddressOf MrkLin) <> 0
                '/* Linie und Kreis speichern.                     */
                '/* Man beachte, daß alle Berechnungen bereits in  */
                '/* der Callback-Funktion 'MrkLin()' vorgenommen   */
                '/* wurden.                                        */

                Call StoreMultiple(gLine, E_LINE)
                Call StoreMultiple(gcirCircle2, E_CIRCLE + DO_SAVCNT)

                '/* Den bisherigen Endkreis zum neuen Startkreis   */
                '/* machen.                                        */
                gcirCircle1 = gcirCircle2
            Loop
        Else
            bStop = True
        End If
    Loop Until bStop
    
    VB_LinCir = 0
End Function

Public Function VB_GetVersion() As Integer
    VB_GetVersion = MI_VERSION
End Function

