unit LiteBitmap;

interface

{$SCOPEDENUMS ON}

uses
  { Delphi }
  System.SysUtils,
  System.Types;

type
  TipLiteBitmapClass = class of TipLiteBitmap;
  TipImageFormat     = (Gif = 0, Bmp, Png, Tiff, Jpg);
  TipScaleAlgorithm  = (FastBilinear = 0, Bilinear, Bicubic, NearestNeighbor, Lanczos);


  { IipLiteBitmap }

  IipLiteBitmap = interface
    ['{197998A9-32FC-450E-9039-74C53571B2F3}']
    function GetHeight: Integer;
    function GetWidth: Integer;
    function IsEmpty: Boolean;
    procedure Resize(AWidth, AHeight: Integer; AAlgorithm: TipScaleAlgorithm);
    function ToBytes(AFormat: TipImageFormat; AQuality: Byte = 0): TBytes;
    property Height: Integer read GetHeight;
    property Width: Integer read GetWidth;
  end;

  { TipLiteBitmap }

  TipLiteBitmap = class abstract(TInterfacedObject)
  protected
    function GetHeight: Integer; virtual; abstract;
    function GetWidth: Integer; virtual; abstract;
  public
    constructor Create(const ABytes: TBytes); overload; virtual; abstract;
    constructor Create(const ABytes: TBytes; ASrcRect: TRect); overload; virtual; abstract;
    function IsEmpty: Boolean;
    property Height: Integer read GetHeight;
    property Width: Integer read GetWidth;
  end;

implementation

{ TipLiteBitmap }

function TipLiteBitmap.IsEmpty: Boolean;
begin
  Result := (Width <= 0) or (Height <= 0);
end;

end.
