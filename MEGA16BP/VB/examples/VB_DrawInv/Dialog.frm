VERSION 5.00
Begin VB.Form RadiusDlg 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Radius-Eingabe"
   ClientHeight    =   1830
   ClientLeft      =   2760
   ClientTop       =   3750
   ClientWidth     =   3795
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1830
   ScaleWidth      =   3795
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  'CenterOwner
   Begin VB.TextBox ctrlRadius 
      BeginProperty DataFormat 
         Type            =   1
         Format          =   "0"
         HaveTrueFalseNull=   0
         FirstDayOfWeek  =   0
         FirstWeekOfYear =   0
         LCID            =   4105
         SubFormatType   =   1
      EndProperty
      BeginProperty Font 
         Name            =   "System"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   405
      Left            =   1800
      TabIndex        =   0
      Text            =   "5"
      Top             =   360
      Width           =   1215
   End
   Begin VB.CommandButton CancelButton 
      Cancel          =   -1  'True
      Caption         =   "Cancel"
      Height          =   375
      Left            =   2070
      TabIndex        =   3
      Top             =   1200
      Width           =   1215
   End
   Begin VB.CommandButton OKButton 
      Caption         =   "OK"
      Default         =   -1  'True
      Height          =   375
      Left            =   510
      TabIndex        =   1
      Top             =   1200
      Width           =   1215
   End
   Begin VB.Label Label1 
      Alignment       =   1  'Right Justify
      Caption         =   "Radius"
      Height          =   255
      Left            =   480
      TabIndex        =   2
      Top             =   480
      Width           =   1095
   End
End
Attribute VB_Name = "RadiusDlg"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Option Explicit
Private bContinue As Boolean

Public Function GetRadius(ByRef dRad As Double) As Boolean
    ctrlRadius.Text = dRad
    RadiusDlg.Show vbModal
    If bContinue Then
        Call GetExpression(ctrlRadius.Text, dRad)
    End If
    GetRadius = bContinue
End Function

Private Sub CancelButton_Click()
    bContinue = False
    Hide
End Sub

Private Sub Form_Activate()
    ctrlRadius.SetFocus
    ctrlRadius.SelStart = 0
    ctrlRadius.SelLength = Len(ctrlRadius.Text)
End Sub

Private Sub OKButton_Click()
    bContinue = True
    Hide
End Sub
