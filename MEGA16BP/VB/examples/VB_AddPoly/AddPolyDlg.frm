VERSION 5.00
Begin VB.Form AddPolyDlg 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Dialog Caption"
   ClientHeight    =   3120
   ClientLeft      =   2760
   ClientTop       =   3750
   ClientWidth     =   4995
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3120
   ScaleWidth      =   4995
   ShowInTaskbar   =   0   'False
   Begin VB.CommandButton KreisBtn 
      Caption         =   "Kreis"
      Height          =   375
      Left            =   480
      TabIndex        =   4
      ToolTipText     =   "Einen Kresbogen zu diesem Punkt erzeugen"
      Top             =   1200
      Width           =   2175
   End
   Begin VB.TextBox YCtrl 
      Height          =   375
      Left            =   720
      TabIndex        =   1
      Top             =   2520
      Width           =   1455
   End
   Begin VB.CommandButton LinieBtn 
      Caption         =   "Linie"
      Height          =   375
      Left            =   480
      TabIndex        =   3
      ToolTipText     =   "Eine Linie zu diesem Punkt"
      Top             =   720
      Width           =   2175
   End
   Begin VB.CommandButton LueckeBtn 
      Caption         =   "Lücke"
      Height          =   375
      Left            =   480
      TabIndex        =   2
      ToolTipText     =   "Zu diesem Punkt springen"
      Top             =   240
      Width           =   2175
   End
   Begin VB.TextBox XCtrl 
      Height          =   375
      Left            =   720
      TabIndex        =   0
      Top             =   2040
      Width           =   1455
   End
   Begin VB.CommandButton CancelButton 
      Cancel          =   -1  'True
      Caption         =   "Cancel"
      Height          =   375
      Left            =   3360
      TabIndex        =   7
      ToolTipText     =   "Doch kein Polygon erzeugen"
      Top             =   2520
      Width           =   1215
   End
   Begin VB.CommandButton OKButton 
      Caption         =   "OK"
      Height          =   375
      Left            =   3360
      TabIndex        =   5
      ToolTipText     =   "Polygon ist fertig --> abspeichern"
      Top             =   1920
      Width           =   1215
   End
   Begin VB.Label Label2 
      Caption         =   "Y:"
      Height          =   255
      Left            =   480
      TabIndex        =   8
      Top             =   2520
      Width           =   135
   End
   Begin VB.Label Label1 
      Caption         =   "X:"
      Height          =   255
      Left            =   480
      TabIndex        =   6
      Top             =   2160
      Width           =   135
   End
End
Attribute VB_Name = "AddPolyDlg"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Option Explicit

Private Sub CancelButton_Click()
    Unload AddPolyDlg
End Sub

Private Sub KreisBtn_Click()
    Call GetExpression(XCtrl.Text, gdCirX)
    Call GetExpression(YCtrl.Text, gdCirY)
    MpdDlg.Show vbModal
    XCtrl.SetFocus
End Sub

Private Sub LinieBtn_Click()
    Dim iRet As Integer
    Dim x As Double
    Dim y As Double
    
    Call GetExpression(XCtrl.Text, x)
    Call GetExpression(YCtrl.Text, y)

    iRet = AddPolylnPt(gPolyline, x, y)
    XCtrl.SetFocus
End Sub

Private Sub LueckeBtn_Click()
    Dim iRet As Integer
    Dim x As Double
    Dim y As Double
    
    Call GetExpression(XCtrl.Text, x)
    Call GetExpression(YCtrl.Text, y)

    iRet = AddPolylnJump(gPolyline, x, y)
    XCtrl.SetFocus
End Sub

Private Sub OKButton_Click()
    If GetArrayElementCount(gPolyline.ppt, 0) <> 0 Then
        Call CreateEntity(E_POLYLN, NO_t_attribs, gPolyline, NO_t_applic, NO_t_mat44)
    End If
    Unload AddPolyDlg
End Sub

Private Sub XCtrl_GotFocus()
    XCtrl.SelStart = 0
    XCtrl.SelLength = Len(XCtrl.Text)
End Sub

Private Sub YCtrl_GotFocus()
    YCtrl.SelStart = 0
    YCtrl.SelLength = Len(YCtrl.Text)
End Sub

