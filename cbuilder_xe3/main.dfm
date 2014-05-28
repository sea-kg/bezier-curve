object Form2: TForm2
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Bezier-Curve'
  ClientHeight = 616
  ClientWidth = 880
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    880
    616)
  PixelsPerInch = 96
  TextHeight = 13
  object imgBezier: TImage
    Left = 8
    Top = 8
    Width = 864
    Height = 563
    Cursor = crCross
    Anchors = [akLeft, akTop, akRight, akBottom]
    OnMouseUp = imgBezierMouseUp
    ExplicitWidth = 619
    ExplicitHeight = 297
  end
  object btnRandom: TButton
    Left = 328
    Top = 583
    Width = 113
    Height = 25
    Anchors = [akLeft, akBottom]
    Caption = 'Random Points'
    TabOrder = 0
    OnClick = btnRandomClick
  end
  object btnClear: TButton
    Left = 136
    Top = 583
    Width = 130
    Height = 25
    Anchors = [akLeft, akBottom]
    Caption = 'Clear User'#39's Points'
    TabOrder = 1
    OnClick = btnClearClick
    ExplicitTop = 415
  end
  object btnDrawUsersPoints: TButton
    Left = 8
    Top = 583
    Width = 122
    Height = 25
    Anchors = [akLeft, akBottom]
    Caption = 'Draw Users Points'
    TabOrder = 2
    OnClick = btnDrawUsersPointsClick
    ExplicitTop = 415
  end
  object btnClose: TButton
    Left = 797
    Top = 583
    Width = 75
    Height = 25
    Caption = 'Exit'
    TabOrder = 3
    OnClick = btnCloseClick
  end
end
