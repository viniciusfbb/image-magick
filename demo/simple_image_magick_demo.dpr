program simple_image_magick_demo;

uses
  System.StartUpCopy,
  FMX.Forms,
  UMain in 'UMain.pas' {Form1},
  LiteBitmap in 'LiteBitmap.pas',
  LiteBitmap.ImageMagick in 'LiteBitmap.ImageMagick.pas',
  ImageMagick.CTypes in '..\src\ImageMagick.CTypes.pas',
  ImageMagick in '..\src\ImageMagick.pas',
  ImageMagick.Wand in '..\src\ImageMagick.Wand.pas';

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
