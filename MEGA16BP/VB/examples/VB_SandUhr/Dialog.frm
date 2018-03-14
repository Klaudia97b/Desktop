VERSION 5.00
Begin VB.Form RadiusDlg 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Radius Input"
   ClientHeight    =   1920
   ClientLeft      =   2760
   ClientTop       =   3750
   ClientWidth     =   4860
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1920
   ScaleWidth      =   4860
   ShowInTaskbar   =   0   'False
   Begin VB.CommandButton CancelButton 
      Caption         =   "Cancel"
      Height          =   375
      Left            =   2783
      TabIndex        =   3
      Top             =   1200
      Width           =   1215
   End
   Begin VB.CommandButton OKButton 
      Caption         =   "OK"
      Default         =   -1  'True
      Height          =   375
      Left            =   863
      TabIndex        =   2
      Top             =   1200
      Width           =   1215
   End
   Begin VB.TextBox EditRadius 
      Height          =   375
      Left            =   1800
      TabIndex        =   0
      Top             =   360
      Width           =   2415
   End
   Begin VB.Label Label1 
      Caption         =   "Radius"
      Height          =   255
      Left            =   360
      TabIndex        =   1
      Top             =   480
      Width           =   1215
   End
End
Attribute VB_Name = "RadiusDlg"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Private fContinue As Boolean
Private mdRad As Double

Private Sub CancelButton_Click()
    fContinue = False
    Unload RadiusDlg
End Sub

Private Sub Form_Activate()
    EditRadius.SetFocus
    EditRadius.SelStart = 0
    EditRadius.SelLength = Len(EditRadius.Text)
End Sub

Private Sub Form_Load()
    EditRadius.Text = mdRad
End Sub

Private Sub OKButton_Click()
    Call GetExpression(EditRadius.Text, mdRad)
    Unload RadiusDlg
End Sub

Public Function DlgInput(dRad As Double) As Boolean
    fContinue = True
    mdRad = dRad
    Show vbModal
    dRad = mdRad
    DlgInput = fContinue
End Function
