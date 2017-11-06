object FormSave: TFormSave
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Save a path'
  ClientHeight = 106
  ClientWidth = 197
  Color = clSilver
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 8
    Top = 21
    Width = 80
    Height = 16
    Caption = 'Simplify level:'
  end
  object Button1: TButton
    Left = 34
    Top = 61
    Width = 155
    Height = 32
    Caption = 'Save'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 115
    Top = 19
    Width = 74
    Height = 22
    BevelInner = bvNone
    BevelOuter = bvNone
    Color = clGrayText
    Ctl3D = False
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clScrollBar
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentCtl3D = False
    ParentFont = False
    TabOrder = 1
    Text = '0'
  end
  object Memo1: TMemo
    Left = 56
    Top = 96
    Width = 185
    Height = 89
    TabOrder = 2
    Visible = False
  end
  object ProgressBar1: TProgressBar
    Left = -8
    Top = 47
    Width = 307
    Height = 8
    Smooth = True
    Style = pbstMarquee
    TabOrder = 3
    Visible = False
  end
  object SaveDialog1: TSaveDialog
    Filter = 'Drawing eXchange Format|*.DXF'
    Left = 64
    Top = 56
  end
end
