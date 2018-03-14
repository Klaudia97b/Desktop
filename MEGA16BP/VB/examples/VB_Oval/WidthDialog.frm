VERSION 5.00
Begin VB.Form WidthDialog 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Enter width"
   ClientHeight    =   1860
   ClientLeft      =   2760
   ClientTop       =   3750
   ClientWidth     =   4470
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1860
   ScaleWidth      =   4470
   ShowInTaskbar   =   0   'False
   Begin VB.TextBox EditWidth 
      Height          =   375
      Left            =   1800
      TabIndex        =   3
      Top             =   360
      Width           =   2415
   End
   Begin VB.CommandButton CancelButton 
      Caption         =   "Cancel"
      Height          =   375
      Left            =   2520
      TabIndex        =   1
      Top             =   1080
      Width           =   1215
   End
   Begin VB.CommandButton OKButton 
      Caption         =   "OK"
      Default         =   -1  'True
      Height          =   375
      Left            =   600
      TabIndex        =   0
      Top             =   1080
      Width           =   1215
   End
   Begin VB.Label Label1 
      Caption         =   "Width"
      Height          =   255
      Left            =   240
      TabIndex        =   2
      Top             =   420
      Width           =   1215
   End
End
Attribute VB_Name = "WidthDialog"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Option Explicit

Private Sub CancelButton_Click()
    gfStop = True
    Unload WidthDialog
End Sub

Private Sub Form_Activate()
    EditWidth.SetFocus
    EditWidth.SelStart = 0
    EditWidth.SelLength = Len(EditWidth.Text)
End Sub

Private Sub Form_Load()
    EditWidth.Text = gArc1.rd
End Sub

Private Sub OKButton_Click()
    Call GetExpression(EditWidth.Text, gArc1.rd)
    Unload WidthDialog
End Sub

