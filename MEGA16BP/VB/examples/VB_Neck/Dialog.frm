VERSION 5.00
Begin VB.Form CntDialog 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Eingabe N-Eck"
   ClientHeight    =   1905
   ClientLeft      =   2760
   ClientTop       =   3750
   ClientWidth     =   4215
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1905
   ScaleWidth      =   4215
   ShowInTaskbar   =   0   'False
   Begin VB.CommandButton OKButton 
      Caption         =   "OK"
      Height          =   375
      Left            =   720
      TabIndex        =   3
      Top             =   1200
      Width           =   1215
   End
   Begin VB.CommandButton CancelButton 
      Caption         =   "Cancel"
      Height          =   375
      Left            =   2280
      TabIndex        =   2
      Top             =   1200
      Width           =   1215
   End
   Begin VB.TextBox CntInput 
      Height          =   405
      Left            =   1800
      TabIndex        =   1
      Top             =   240
      Width           =   1695
   End
   Begin VB.Label LabelCnt 
      Caption         =   "Anzahl Ecken"
      Height          =   285
      Left            =   360
      TabIndex        =   0
      Top             =   360
      Width           =   1335
   End
End
Attribute VB_Name = "CntDialog"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Option Explicit

Private fContinue As Boolean
Private miCnt As Integer

Private Sub CancelButton_Click()
    fContinue = False
    Unload CntDialog
End Sub

Private Sub Form_Activate()
    CntInput.SetFocus
    CntInput.SelStart = 0
    CntInput.SelLength = Len(CntInput.Text)
End Sub

Private Sub Form_Load()
    CntInput.Text = miCnt
End Sub

Private Sub OKButton_Click()
    Dim dValue As Double
    Call GetExpression(CntInput.Text, dValue)
    miCnt = Round(dValue)
    Unload CntDialog
End Sub

Public Function InputCnt(ByRef iCnt As Integer) As Boolean
    fContinue = True
    miCnt = iCnt
    Show vbModal
    iCnt = miCnt
    InputCnt = fContinue
End Function

