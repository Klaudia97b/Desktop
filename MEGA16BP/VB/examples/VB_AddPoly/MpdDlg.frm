VERSION 5.00
Begin VB.Form MpdDlg 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Scheitelpunkt angeben"
   ClientHeight    =   1875
   ClientLeft      =   2760
   ClientTop       =   3750
   ClientWidth     =   3855
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1875
   ScaleWidth      =   3855
   ShowInTaskbar   =   0   'False
   Begin VB.TextBox MpdCtrl 
      Height          =   375
      Left            =   1560
      TabIndex        =   0
      Top             =   480
      Width           =   1695
   End
   Begin VB.CommandButton CancelButton 
      Cancel          =   -1  'True
      Caption         =   "Abbrechen"
      Height          =   375
      Left            =   2040
      TabIndex        =   2
      ToolTipText     =   "Doch kein Kreis"
      Top             =   1200
      Width           =   1215
   End
   Begin VB.CommandButton OKButton 
      Caption         =   "OK"
      Height          =   375
      Left            =   480
      TabIndex        =   1
      ToolTipText     =   "Kreis übernehmen"
      Top             =   1200
      Width           =   1215
   End
   Begin VB.Label Label1 
      Caption         =   "mpd:"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   600
      TabIndex        =   3
      Top             =   480
      Width           =   855
   End
End
Attribute VB_Name = "MpdDlg"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Option Explicit
Private mdRad As Double

Private Sub CancelButton_Click()
    Unload MpdDlg
End Sub

Private Sub Form_Activate()
    MpdCtrl.SetFocus
    MpdCtrl.SelStart = 0
    MpdCtrl.SelLength = Len(MpdCtrl.Text)
End Sub

Private Sub Form_Load()
    MpdCtrl.Text = mdRad
End Sub


Private Sub OKButton_Click()
    Dim iRet As Integer
    Call GetExpression(MpdCtrl.Text, mdRad)
    iRet = AddPolylnCir(gPolyline, gdCirX, gdCirY, mdRad)
    Unload MpdDlg
End Sub
