Attribute VB_Name = "CallBacks"
Public Const MAXID As Integer = 15

Public gbIsInfo As Boolean
Public giIdCnt As Integer
Public gaIdNum(MAXID) As Long


'**********************************************************************
Public Function ChkInfo() As Integer

    Dim inf As t_entinfo
    
    Call GetLastInfo(inf)
   
    ' in den Element-Infos die Einträge suchen, wo in der ersten Zeile
    ' die Bezeichnung "Rohr" steht
    
    If Left$(inf.info(0), 4) = "Rohr" Then   ' der Eintrag existiert
        gbIsInfo = True
        If giIdCnt < MAXID Then
            gaIdNum(gIdCnt) = inf.id
            giIdCnt = giIdCnt + 1
        End If
    End If
    ChkInfo = CONTINUE_LOOP
End Function

