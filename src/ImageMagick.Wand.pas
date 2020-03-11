{
  Copyright 1999-2005 ImageMagick Studio LLC, a non-profit organization
  dedicated to making software imaging solutions freely available.
  
  You may not use this file except in compliance with the License.
  obtain a copy of the License at
  
    http://www.imagemagick.org/script/license.php
  
  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  ImageMagick MagickWand API.
}
{
  Based on ImageMagick 6.2

  Converted from c by: Felipe Monteiro de Carvalho Dez/2005

	Bug-fixed by Ángel Eduardo García Hernández
	Thanks to Marc Geldon and RuBBeR
}
{Version 0.4}
unit ImageMagick.Wand;

{$IFDEF FPC}
  {$mode objfpc}
	{$PACKRECORDS C}
{$ENDIF}

{$z4}

interface

{$IFDEF MSWINDOWS}
uses
  { ImageMagick }
  ImageMagick,
  ImageMagick.CTypes;

{ Various types }
type
  MagickWand = record
    id: culong;
    name: array[1..MaxTextExtent] of Char;
    exception: ExceptionInfo;
    image_info: PImageInfo;
    quantize_info: PQuantizeInfo;
    images: PImage;
    active, pend, debug: MagickBooleanType;
    signature: culong;
  end;

  PMagickWand = ^MagickWand;

{$include pixel_wand.inc}
{$include drawing_wand.inc}
{$include magick_attribute.inc}
{$include magick_image.inc}
{$include pixel_iterator.inc}

var
  IsMagickWand: function(const wand: PMagickWand): MagickBooleanType; cdecl;
  MagickClearException: function(wand: PMagickWand): MagickBooleanType; cdecl;

  CloneMagickWand: function(const wand: PMagickWand): PMagickWand; cdecl;
  DestroyMagickWand: function(wand: PMagickWand): PMagickWand; cdecl;
  NewMagickWand: function: PMagickWand; cdecl;

  ClearMagickWand: procedure(wand: PMagickWand); cdecl;
  MagickWandGenesis: procedure; cdecl;
  MagickWandTerminus: procedure; cdecl;
  MagickRelinquishMemory: function(resource: Pointer): Pointer; cdecl;
  MagickResetIterator: procedure(wand: PMagickWand); cdecl;
  MagickSetFirstIterator: procedure(wand: PMagickWand); cdecl;
  MagickSetLastIterator: procedure(wand: PMagickWand); cdecl;

function TryInitializeImageMagickWand: Boolean;
procedure FinalizeImageMagickWand;

var
  GInitializedImageMagickWand: Boolean;

implementation

uses
  { Windows }
  Winapi.Windows;

var
  FModule: HMODULE;

function TryInitializeImageMagickWand: Boolean;
begin
  if not GInitializedImageMagick then
  begin
    FModule := LoadLibrary(PChar(WandExport));
    Result := FModule <> 0;
    if Result then
    begin
      // ImageMagick.Wand.pas
      IsMagickWand := GetProcAddress(FModule, 'IsMagickWand');
      MagickClearException := GetProcAddress(FModule, 'MagickClearException');

      CloneMagickWand := GetProcAddress(FModule, 'CloneMagickWand');
      DestroyMagickWand := GetProcAddress(FModule, 'DestroyMagickWand');
      NewMagickWand := GetProcAddress(FModule, 'NewMagickWand');

      ClearMagickWand := GetProcAddress(FModule, 'ClearMagickWand');
      MagickWandGenesis := GetProcAddress(FModule, 'MagickWandGenesis');
      MagickWandTerminus := GetProcAddress(FModule, 'MagickWandTerminus');
      MagickRelinquishMemory := GetProcAddress(FModule, 'MagickRelinquishMemory');
      MagickResetIterator := GetProcAddress(FModule, 'MagickResetIterator');
      MagickSetFirstIterator := GetProcAddress(FModule, 'MagickSetFirstIterator');
      MagickSetLastIterator := GetProcAddress(FModule, 'MagickSetLastIterator');

      // pixel_iterator.inc
      PixelGetIteratorException := GetProcAddress(FModule, 'PixelGetIteratorException');

      IsPixelIterator := GetProcAddress(FModule, 'IsPixelIterator');
      PixelClearIteratorException := GetProcAddress(FModule, 'PixelClearIteratorException');
      PixelSetIteratorRow := GetProcAddress(FModule, 'PixelSetIteratorRow');
      PixelSyncIterator := GetProcAddress(FModule, 'PixelSyncIterator');

      DestroyPixelIterator := GetProcAddress(FModule, 'DestroyPixelIterator');
      NewPixelIterator := GetProcAddress(FModule, 'NewPixelIterator');
      NewPixelRegionIterator := GetProcAddress(FModule, 'NewPixelRegionIterator');

      PixelGetNextIteratorRow := GetProcAddress(FModule, 'PixelGetNextIteratorRow');
      PixelGetPreviousIteratorRow := GetProcAddress(FModule, 'PixelGetPreviousIteratorRow');

      ClearPixelIterator := GetProcAddress(FModule, 'ClearPixelIterator');
      PixelResetIterator := GetProcAddress(FModule, 'PixelResetIterator');
      PixelSetFirstIteratorRow := GetProcAddress(FModule, 'PixelSetFirstIteratorRow');
      PixelSetLastIteratorRow := GetProcAddress(FModule, 'PixelSetLastIteratorRow');

      // magick_image.inc
      MagickNegateImage := GetProcAddress(FModule, 'MagickNegateImage');
      MagickMotionBlurImage := GetProcAddress(FModule, 'MagickMotionBlurImage');
      MagickModulateImage := GetProcAddress(FModule, 'MagickModulateImage');
      MagickMinifyImage := GetProcAddress(FModule, 'MagickMinifyImage');
      MagickMedianFilterImage := GetProcAddress(FModule, 'MagickMedianFilterImage');
      MagickMatteFloodfillImage := GetProcAddress(FModule, 'MagickMatteFloodfillImage');
      MagickMapImage := GetProcAddress(FModule, 'MagickMapImage');
      MagickMagnifyImage := GetProcAddress(FModule, 'MagickMagnifyImage');
      MagickLevelImageChannel := GetProcAddress(FModule, 'MagickLevelImageChannel');
      MagickLevelImage := GetProcAddress(FModule, 'MagickLevelImage');
      MagickLabelImage := GetProcAddress(FModule, 'MagickLabelImage');
      MagickImplodeImage := GetProcAddress(FModule, 'MagickImplodeImage');
      MagickHasPreviousImage := GetProcAddress(FModule, 'MagickHasPreviousImage');
      MagickHasNextImage := GetProcAddress(FModule, 'MagickHasNextImage');
      MagickGetImageWhitePoint := GetProcAddress(FModule, 'MagickGetImageWhitePoint');
      MagickGetImageResolution := GetProcAddress(FModule, 'MagickGetImageResolution');
      MagickGetImageRedPrimary := GetProcAddress(FModule, 'MagickGetImageRedPrimary');
      MagickGetImagePixels := GetProcAddress(FModule, 'MagickGetImagePixels');
      MagickGetImagePixelColor := GetProcAddress(FModule, 'MagickGetImagePixelColor');
      MagickGetImagePage := GetProcAddress(FModule, 'MagickGetImagePage');
      MagickGetImageMatteColor := GetProcAddress(FModule, 'MagickGetImageMatteColor');
      MagickGetImageGreenPrimary := GetProcAddress(FModule, 'MagickGetImageGreenPrimary');
      MagickGetImageExtrema := GetProcAddress(FModule, 'MagickGetImageExtrema');
      MagickGetImageColormapColor := GetProcAddress(FModule, 'MagickGetImageColormapColor');
      MagickGetImageChannelMean := GetProcAddress(FModule, 'MagickGetImageChannelMean');
      MagickGetImageChannelExtrema := GetProcAddress(FModule, 'MagickGetImageChannelExtrema');
      MagickGetImageDistortion := GetProcAddress(FModule, 'MagickGetImageDistortion');
      MagickGetImageChannelDistortion := GetProcAddress(FModule, 'MagickGetImageChannelDistortion');
      MagickGetImageBorderColor := GetProcAddress(FModule, 'MagickGetImageBorderColor');
      MagickGetImageBluePrimary := GetProcAddress(FModule, 'MagickGetImageBluePrimary');
      MagickGetImageBackgroundColor := GetProcAddress(FModule, 'MagickGetImageBackgroundColor');
      MagickGaussianBlurImageChannel := GetProcAddress(FModule, 'MagickGaussianBlurImageChannel');
      MagickGaussianBlurImage := GetProcAddress(FModule, 'MagickGaussianBlurImage');
      MagickGammaImageChannel := GetProcAddress(FModule, 'MagickGammaImageChannel');
      MagickGammaImage := GetProcAddress(FModule, 'MagickGammaImage');
      MagickFrameImage := GetProcAddress(FModule, 'MagickFrameImage');
      MagickFlopImage := GetProcAddress(FModule, 'MagickFlopImage');
      MagickFlipImage := GetProcAddress(FModule, 'MagickFlipImage');
      MagickEvaluateImageChannel := GetProcAddress(FModule, 'MagickEvaluateImageChannel');
      MagickEvaluateImage := GetProcAddress(FModule, 'MagickEvaluateImage');
      MagickEqualizeImage := GetProcAddress(FModule, 'MagickEqualizeImage');
      MagickEnhanceImage := GetProcAddress(FModule, 'MagickEnhanceImage');
      MagickEmbossImage := GetProcAddress(FModule, 'MagickEmbossImage');
      MagickEdgeImage := GetProcAddress(FModule, 'MagickEdgeImage');
      MagickDrawImage := GetProcAddress(FModule, 'MagickDrawImage');
      MagickDisplayImages := GetProcAddress(FModule, 'MagickDisplayImages');
      MagickDisplayImage := GetProcAddress(FModule, 'MagickDisplayImage');
      MagickDespeckleImage := GetProcAddress(FModule, 'MagickDespeckleImage');
      MagickCycleColormapImage := GetProcAddress(FModule, 'MagickCycleColormapImage');
      MagickCropImage := GetProcAddress(FModule, 'MagickCropImage');
      MagickConvolveImageChannel := GetProcAddress(FModule, 'MagickConvolveImageChannel');
      MagickConvolveImage := GetProcAddress(FModule, 'MagickConvolveImage');
      MagickContrastImage := GetProcAddress(FModule, 'MagickContrastImage');
      MagickConstituteImage := GetProcAddress(FModule, 'MagickConstituteImage');
      MagickCompositeImage := GetProcAddress(FModule, 'MagickCompositeImage');
      MagickCommentImage := GetProcAddress(FModule, 'MagickCommentImage');
      MagickColorizeImage := GetProcAddress(FModule, 'MagickColorizeImage');
      MagickColorFloodfillImage := GetProcAddress(FModule, 'MagickColorFloodfillImage');
      MagickClipPathImage := GetProcAddress(FModule, 'MagickClipPathImage');
      MagickClipImage := GetProcAddress(FModule, 'MagickClipImage');
      MagickChopImage := GetProcAddress(FModule, 'MagickChopImage');
      MagickCharcoalImage := GetProcAddress(FModule, 'MagickCharcoalImage');
      MagickBorderImage := GetProcAddress(FModule, 'MagickBorderImage');
      MagickBlurImageChannel := GetProcAddress(FModule, 'MagickBlurImageChannel');
      MagickBlurImage := GetProcAddress(FModule, 'MagickBlurImage');
      MagickBlackThresholdImage := GetProcAddress(FModule, 'MagickBlackThresholdImage');
      MagickAnimateImages := GetProcAddress(FModule, 'MagickAnimateImages');
      MagickAnnotateImage := GetProcAddress(FModule, 'MagickAnnotateImage');
      MagickAffineTransformImage := GetProcAddress(FModule, 'MagickAffineTransformImage');
      MagickAddNoiseImage := GetProcAddress(FModule, 'MagickAddNoiseImage');
      MagickAddImage := GetProcAddress(FModule, 'MagickAddImage');
      MagickAdaptiveThresholdImage := GetProcAddress(FModule, 'MagickAdaptiveThresholdImage');
      MagickGetImageIndex := GetProcAddress(FModule, 'MagickGetImageIndex');
      MagickGetImageInterlaceScheme := GetProcAddress(FModule, 'MagickGetImageInterlaceScheme');
      MagickGetImageType := GetProcAddress(FModule, 'MagickGetImageType');
      GetImageFromMagickWand := GetProcAddress(FModule, 'GetImageFromMagickWand');
      MagickGetImageTotalInkDensity := GetProcAddress(FModule, 'MagickGetImageTotalInkDensity');
      MagickGetImageGamma := GetProcAddress(FModule, 'MagickGetImageGamma');
      MagickGetImageDispose := GetProcAddress(FModule, 'MagickGetImageDispose');
      MagickGetImageCompression := GetProcAddress(FModule, 'MagickGetImageCompression');
      MagickGetImageColorspace := GetProcAddress(FModule, 'MagickGetImageColorspace');
      MagickGetImageCompose := GetProcAddress(FModule, 'MagickGetImageCompose');
      MagickIdentifyImage := GetProcAddress(FModule, 'MagickIdentifyImage');
      MagickGetImageSignature := GetProcAddress(FModule, 'MagickGetImageSignature');
      MagickGetImageFormat := GetProcAddress(FModule, 'MagickGetImageFormat');
      MagickGetImageFilename := GetProcAddress(FModule, 'MagickGetImageFilename');
      MagickGetImageAttribute := GetProcAddress(FModule, 'MagickGetImageAttribute');
      MagickGetImageChannelStatistics := GetProcAddress(FModule, 'MagickGetImageChannelStatistics');
      MagickPingImage := GetProcAddress(FModule, 'MagickPingImage');
      MagickPaintTransparentImage := GetProcAddress(FModule, 'MagickPaintTransparentImage');
      MagickPaintOpaqueImage := GetProcAddress(FModule, 'MagickPaintOpaqueImage');
      MagickOilPaintImage := GetProcAddress(FModule, 'MagickOilPaintImage');
      MagickNormalizeImage := GetProcAddress(FModule, 'MagickNormalizeImage');
      MagickNextImage := GetProcAddress(FModule, 'MagickNextImage');
      MagickNewImage := GetProcAddress(FModule, 'MagickNewImage');
      MagickReadImageBlob := GetProcAddress(FModule, 'MagickReadImageBlob');
      MagickReadImage := GetProcAddress(FModule, 'MagickReadImage');
      MagickRaiseImage := GetProcAddress(FModule, 'MagickRaiseImage');
      MagickRadialBlurImageChannel := GetProcAddress(FModule, 'MagickRadialBlurImageChannel');
      MagickRadialBlurImage := GetProcAddress(FModule, 'MagickRadialBlurImage');
      MagickQuantizeImages := GetProcAddress(FModule, 'MagickQuantizeImages');
      MagickQuantizeImage := GetProcAddress(FModule, 'MagickQuantizeImage');
      MagickProfileImage := GetProcAddress(FModule, 'MagickProfileImage');
      MagickPreviousImage := GetProcAddress(FModule, 'MagickPreviousImage');
      MagickGetNumberImages := GetProcAddress(FModule, 'MagickGetNumberImages');
      MagickGetImageWidth := GetProcAddress(FModule, 'MagickGetImageWidth');
      MagickGetImageScene := GetProcAddress(FModule, 'MagickGetImageScene');
      MagickGetImageIterations := GetProcAddress(FModule, 'MagickGetImageIterations');
      MagickGetImageHeight := GetProcAddress(FModule, 'MagickGetImageHeight');
      MagickGetImageDepth := GetProcAddress(FModule, 'MagickGetImageDepth');
      MagickGetImageChannelDepth := GetProcAddress(FModule, 'MagickGetImageChannelDepth');
      MagickGetImageDelay := GetProcAddress(FModule, 'MagickGetImageDelay');
      MagickGetImageCompressionQuality := GetProcAddress(FModule, 'MagickGetImageCompressionQuality');
      MagickGetImageColors := GetProcAddress(FModule, 'MagickGetImageColors');
      MagickRemoveImageProfile := GetProcAddress(FModule, 'MagickRemoveImageProfile');
      MagickGetImageProfile := GetProcAddress(FModule, 'MagickGetImageProfile');
      MagickGetImagesBlob := GetProcAddress(FModule, 'MagickGetImagesBlob');
      MagickGetImageBlob := GetProcAddress(FModule, 'MagickGetImageBlob');
      MagickGetImageUnits := GetProcAddress(FModule, 'MagickGetImageUnits');
      MagickGetImageRenderingIntent := GetProcAddress(FModule, 'MagickGetImageRenderingIntent');
      MagickGetImageHistogram := GetProcAddress(FModule, 'MagickGetImageHistogram');
      NewMagickWandFromImage := GetProcAddress(FModule, 'NewMagickWandFromImage');
      MagickTransformImage := GetProcAddress(FModule, 'MagickTransformImage');
      MagickTextureImage := GetProcAddress(FModule, 'MagickTextureImage');
      MagickStereoImage := GetProcAddress(FModule, 'MagickStereoImage');
      MagickSteganoImage := GetProcAddress(FModule, 'MagickSteganoImage');
      MagickPreviewImages := GetProcAddress(FModule, 'MagickPreviewImages');
      MagickMosaicImages := GetProcAddress(FModule, 'MagickMosaicImages');
      MagickMorphImages := GetProcAddress(FModule, 'MagickMorphImages');
      MagickGetImageRegion := GetProcAddress(FModule, 'MagickGetImageRegion');
      MagickGetImage := GetProcAddress(FModule, 'MagickGetImage');
      MagickFxImageChannel := GetProcAddress(FModule, 'MagickFxImageChannel');
      MagickFxImage := GetProcAddress(FModule, 'MagickFxImage');
      MagickFlattenImages := GetProcAddress(FModule, 'MagickFlattenImages');
      MagickDeconstructImages := GetProcAddress(FModule, 'MagickDeconstructImages');
      MagickCompareImages := GetProcAddress(FModule, 'MagickCompareImages');
      MagickCompareImageChannels := GetProcAddress(FModule, 'MagickCompareImageChannels');
      MagickCombineImages := GetProcAddress(FModule, 'MagickCombineImages');
      MagickCoalesceImages := GetProcAddress(FModule, 'MagickCoalesceImages');
      MagickAverageImages := GetProcAddress(FModule, 'MagickAverageImages');
      MagickAppendImages := GetProcAddress(FModule, 'MagickAppendImages');
      MagickGetImageSize := GetProcAddress(FModule, 'MagickGetImageSize');
      MagickSetImageProgressMonitor := GetProcAddress(FModule, 'MagickSetImageProgressMonitor');
      MagickWriteImages := GetProcAddress(FModule, 'MagickWriteImages');
      MagickWriteImage := GetProcAddress(FModule, 'MagickWriteImage');
      MagickWhiteThresholdImage := GetProcAddress(FModule, 'MagickWhiteThresholdImage');
      MagickWaveImage := GetProcAddress(FModule, 'MagickWaveImage');
      MagickUnsharpMaskImageChannel := GetProcAddress(FModule, 'MagickUnsharpMaskImageChannel');
      MagickUnsharpMaskImage := GetProcAddress(FModule, 'MagickUnsharpMaskImage');
      MagickTrimImage := GetProcAddress(FModule, 'MagickTrimImage');
      MagickThresholdImageChannel := GetProcAddress(FModule, 'MagickThresholdImageChannel');
      MagickThresholdImage := GetProcAddress(FModule, 'MagickThresholdImage');
      MagickTintImage := GetProcAddress(FModule, 'MagickTintImage');
      MagickSwirlImage := GetProcAddress(FModule, 'MagickSwirlImage');
      MagickStripImage := GetProcAddress(FModule, 'MagickStripImage');
      MagickSpreadImage := GetProcAddress(FModule, 'MagickSpreadImage');
      MagickSpliceImage := GetProcAddress(FModule, 'MagickSpliceImage');
      MagickSolarizeImage := GetProcAddress(FModule, 'MagickSolarizeImage');
      MagickSigmoidalContrastImageChannel := GetProcAddress(FModule, 'MagickSigmoidalContrastImageChannel');
      MagickSigmoidalContrastImage := GetProcAddress(FModule, 'MagickSigmoidalContrastImage');
      MagickShearImage := GetProcAddress(FModule, 'MagickShearImage');
      MagickShaveImage := GetProcAddress(FModule, 'MagickShaveImage');
      MagickSharpenImageChannel := GetProcAddress(FModule, 'MagickSharpenImageChannel');
      MagickSharpenImage := GetProcAddress(FModule, 'MagickSharpenImage');
      MagickShadowImage := GetProcAddress(FModule, 'MagickShadowImage');
      MagickSetImageWhitePoint := GetProcAddress(FModule, 'MagickSetImageWhitePoint');
      MagickSetImageUnits := GetProcAddress(FModule, 'MagickSetImageUnits');
      MagickSetImageType := GetProcAddress(FModule, 'MagickSetImageType');
      MagickSetImageScene := GetProcAddress(FModule, 'MagickSetImageScene');
      MagickSetImageResolution := GetProcAddress(FModule, 'MagickSetImageResolution');
      MagickSetImageRenderingIntent := GetProcAddress(FModule, 'MagickSetImageRenderingIntent');
      MagickSetImageRedPrimary := GetProcAddress(FModule, 'MagickSetImageRedPrimary');
      MagickSetImageProfile := GetProcAddress(FModule, 'MagickSetImageProfile');
      MagickSetImagePixels := GetProcAddress(FModule, 'MagickSetImagePixels');
      MagickSetImagePage := GetProcAddress(FModule, 'MagickSetImagePage');
      MagickSetImageMatteColor := GetProcAddress(FModule, 'MagickSetImageMatteColor');
      MagickSetImageIterations := GetProcAddress(FModule, 'MagickSetImageIterations');
      MagickSetImageInterlaceScheme := GetProcAddress(FModule, 'MagickSetImageInterlaceScheme');
      MagickSetImageIndex := GetProcAddress(FModule, 'MagickSetImageIndex');
      MagickSetImageGreenPrimary := GetProcAddress(FModule, 'MagickSetImageGreenPrimary');
      MagickSetImageGamma := GetProcAddress(FModule, 'MagickSetImageGamma');
      MagickSetImageFormat := GetProcAddress(FModule, 'MagickSetImageFormat');
      MagickSetImageFilename := GetProcAddress(FModule, 'MagickSetImageFilename');
      MagickSetImageExtent := GetProcAddress(FModule, 'MagickSetImageExtent');
      MagickSetImageDispose := GetProcAddress(FModule, 'MagickSetImageDispose');
      MagickSetImageDepth := GetProcAddress(FModule, 'MagickSetImageDepth');
      MagickSetImageDelay := GetProcAddress(FModule, 'MagickSetImageDelay');
      MagickSetImageCompressionQuality := GetProcAddress(FModule, 'MagickSetImageCompressionQuality');
      MagickSetImageCompression := GetProcAddress(FModule, 'MagickSetImageCompression');
      MagickSetImageCompose := GetProcAddress(FModule, 'MagickSetImageCompose');
      MagickSetImageColorspace := GetProcAddress(FModule, 'MagickSetImageColorspace');
      MagickSetImageColormapColor := GetProcAddress(FModule, 'MagickSetImageColormapColor');
      MagickSetImageChannelDepth := GetProcAddress(FModule, 'MagickSetImageChannelDepth');
      MagickSetImageBorderColor := GetProcAddress(FModule, 'MagickSetImageBorderColor');
      MagickSetImageBluePrimary := GetProcAddress(FModule, 'MagickSetImageBluePrimary');
      MagickSetImageBias := GetProcAddress(FModule, 'MagickSetImageBias');
      MagickSetImageBackgroundColor := GetProcAddress(FModule, 'MagickSetImageBackgroundColor');
      MagickSetImageAttribute := GetProcAddress(FModule, 'MagickSetImageAttribute');
      MagickSetImage := GetProcAddress(FModule, 'MagickSetImage');
      MagickSeparateImageChannel := GetProcAddress(FModule, 'MagickSeparateImageChannel');
      MagickScaleImage := GetProcAddress(FModule, 'MagickScaleImage');
      MagickSampleImage := GetProcAddress(FModule, 'MagickSampleImage');
      MagickRotateImage := GetProcAddress(FModule, 'MagickRotateImage');
      MagickRollImage := GetProcAddress(FModule, 'MagickRollImage');
      MagickResizeImage := GetProcAddress(FModule, 'MagickResizeImage');
      MagickResampleImage := GetProcAddress(FModule, 'MagickResampleImage');
      MagickRemoveImage := GetProcAddress(FModule, 'MagickRemoveImage');
      MagickReduceNoiseImage := GetProcAddress(FModule, 'MagickReduceNoiseImage');
      PixelGetMagickColor := GetProcAddress(FModule, 'PixelGetMagickColor');
      PixelSetYellowQuantum := GetProcAddress(FModule, 'PixelSetYellowQuantum');
      PixelSetYellow := GetProcAddress(FModule, 'PixelSetYellow');
      PixelSetRedQuantum := GetProcAddress(FModule, 'PixelSetRedQuantum');
      PixelSetRed := GetProcAddress(FModule, 'PixelSetRed');
      PixelSetQuantumColor := GetProcAddress(FModule, 'PixelSetQuantumColor');
      PixelSetOpacityQuantum := GetProcAddress(FModule, 'PixelSetOpacityQuantum');
      PixelSetOpacity := GetProcAddress(FModule, 'PixelSetOpacity');
      PixelSetMagickColor := GetProcAddress(FModule, 'PixelSetMagickColor');
      PixelSetMagentaQuantum := GetProcAddress(FModule, 'PixelSetMagentaQuantum');
      PixelSetMagenta := GetProcAddress(FModule, 'PixelSetMagenta');
      PixelSetIndex := GetProcAddress(FModule, 'PixelSetIndex');
      PixelSetGreenQuantum := GetProcAddress(FModule, 'PixelSetGreenQuantum');
      PixelSetGreen := GetProcAddress(FModule, 'PixelSetGreen');
      PixelSetCyanQuantum := GetProcAddress(FModule, 'PixelSetCyanQuantum');
      PixelSetCyan := GetProcAddress(FModule, 'PixelSetCyan');
      PixelSetColorCount := GetProcAddress(FModule, 'PixelSetColorCount');
      PixelSetBlueQuantum := GetProcAddress(FModule, 'PixelSetBlueQuantum');
      PixelSetBlue := GetProcAddress(FModule, 'PixelSetBlue');
      PixelSetBlackQuantum := GetProcAddress(FModule, 'PixelSetBlackQuantum');
      PixelSetBlack := GetProcAddress(FModule, 'PixelSetBlack');
      PixelSetAlphaQuantum := GetProcAddress(FModule, 'PixelSetAlphaQuantum');
      PixelSetAlpha := GetProcAddress(FModule, 'PixelSetAlpha');
      PixelGetQuantumColor := GetProcAddress(FModule, 'PixelGetQuantumColor');
      ClearPixelWand := GetProcAddress(FModule, 'ClearPixelWand');
      PixelGetColorCount := GetProcAddress(FModule, 'PixelGetColorCount');
      PixelGetYellowQuantum := GetProcAddress(FModule, 'PixelGetYellowQuantum');
      PixelGetRedQuantum := GetProcAddress(FModule, 'PixelGetRedQuantum');
      PixelGetOpacityQuantum := GetProcAddress(FModule, 'PixelGetOpacityQuantum');
      PixelGetMagentaQuantum := GetProcAddress(FModule, 'PixelGetMagentaQuantum');
      PixelGetGreenQuantum := GetProcAddress(FModule, 'PixelGetGreenQuantum');
      PixelGetCyanQuantum := GetProcAddress(FModule, 'PixelGetCyanQuantum');
      PixelGetBlueQuantum := GetProcAddress(FModule, 'PixelGetBlueQuantum');
      PixelGetBlackQuantum := GetProcAddress(FModule, 'PixelGetBlackQuantum');
      PixelGetAlphaQuantum := GetProcAddress(FModule, 'PixelGetAlphaQuantum');
      NewPixelWands := GetProcAddress(FModule, 'NewPixelWands');
      NewPixelWand := GetProcAddress(FModule, 'NewPixelWand');
      DestroyPixelWands := GetProcAddress(FModule, 'DestroyPixelWands');
      DestroyPixelWand := GetProcAddress(FModule, 'DestroyPixelWand');
      PixelSetColor := GetProcAddress(FModule, 'PixelSetColor');
      PixelClearException := GetProcAddress(FModule, 'PixelClearException');
      IsPixelWandSimilar := GetProcAddress(FModule, 'IsPixelWandSimilar');
      IsPixelWand := GetProcAddress(FModule, 'IsPixelWand');
      PixelGetIndex := GetProcAddress(FModule, 'PixelGetIndex');
      PixelGetYellow := GetProcAddress(FModule, 'PixelGetYellow');
      PixelGetRed := GetProcAddress(FModule, 'PixelGetRed');
      PixelGetOpacity := GetProcAddress(FModule, 'PixelGetOpacity');
      PixelGetMagenta := GetProcAddress(FModule, 'PixelGetMagenta');
      PixelGetGreen := GetProcAddress(FModule, 'PixelGetGreen');
      PixelGetCyan := GetProcAddress(FModule, 'PixelGetCyan');
      PixelGetBlue := GetProcAddress(FModule, 'PixelGetBlue');
      PixelGetBlack := GetProcAddress(FModule, 'PixelGetBlack');
      PixelGetAlpha := GetProcAddress(FModule, 'PixelGetAlpha');
      PixelGetColorAsString := GetProcAddress(FModule, 'PixelGetColorAsString');
      PixelGetException := GetProcAddress(FModule, 'PixelGetException');

      // drawing_wand.inc
      DestroyDrawingWand := GetProcAddress(FModule, 'DestroyDrawingWand');
      CloneDrawingWand := GetProcAddress(FModule, 'CloneDrawingWand');
      PeekDrawingWand := GetProcAddress(FModule, 'PeekDrawingWand');
      DrawGetStrokeWidth := GetProcAddress(FModule, 'DrawGetStrokeWidth');
      DrawGetStrokeAlpha := GetProcAddress(FModule, 'DrawGetStrokeAlpha');
      DrawGetStrokeDashOffset := GetProcAddress(FModule, 'DrawGetStrokeDashOffset');
      DrawGetStrokeDashArray := GetProcAddress(FModule, 'DrawGetStrokeDashArray');
      DrawGetFontSize := GetProcAddress(FModule, 'DrawGetFontSize');
      DrawGetFillAlpha := GetProcAddress(FModule, 'DrawGetFillAlpha');
      DrawGetTextDecoration := GetProcAddress(FModule, 'DrawGetTextDecoration');
      DrawGetClipUnits := GetProcAddress(FModule, 'DrawGetClipUnits');
      DrawGetVectorGraphics := GetProcAddress(FModule, 'DrawGetVectorGraphics');
      DrawGetTextEncoding := GetProcAddress(FModule, 'DrawGetTextEncoding');
      DrawGetFontFamily := GetProcAddress(FModule, 'DrawGetFontFamily');
      DrawGetFont := GetProcAddress(FModule, 'DrawGetFont');
      DrawGetException := GetProcAddress(FModule, 'DrawGetException');
      DrawGetClipPath := GetProcAddress(FModule, 'DrawGetClipPath');
      DrawGetTextAlignment := GetProcAddress(FModule, 'DrawGetTextAlignment');
      DrawPathLineToRelative := GetProcAddress(FModule, 'DrawPathLineToRelative');
      DrawPathLineToAbsolute := GetProcAddress(FModule, 'DrawPathLineToAbsolute');
      DrawPathFinish := GetProcAddress(FModule, 'DrawPathFinish');
      DrawPathEllipticArcRelative := GetProcAddress(FModule, 'DrawPathEllipticArcRelative');
      DrawPathEllipticArcAbsolute := GetProcAddress(FModule, 'DrawPathEllipticArcAbsolute');
      DrawPathCurveToSmoothRelative := GetProcAddress(FModule, 'DrawPathCurveToSmoothRelative');
      DrawPathCurveToSmoothAbsolute := GetProcAddress(FModule, 'DrawPathCurveToSmoothAbsolute');
      DrawPathCurveToQuadraticBezierSmoothRelative := GetProcAddress(FModule, 'DrawPathCurveToQuadraticBezierSmoothRelative');
      DrawPathCurveToQuadraticBezierSmoothAbsolute := GetProcAddress(FModule, 'DrawPathCurveToQuadraticBezierSmoothAbsolute');
      DrawPathCurveToQuadraticBezierRelative := GetProcAddress(FModule, 'DrawPathCurveToQuadraticBezierRelative');
      DrawPathCurveToQuadraticBezierAbsolute := GetProcAddress(FModule, 'DrawPathCurveToQuadraticBezierAbsolute');
      DrawPathCurveToRelative := GetProcAddress(FModule, 'DrawPathCurveToRelative');
      DrawPathCurveToAbsolute := GetProcAddress(FModule, 'DrawPathCurveToAbsolute');
      DrawPathClose := GetProcAddress(FModule, 'DrawPathClose');
      DrawMatte := GetProcAddress(FModule, 'DrawMatte');
      DrawLine := GetProcAddress(FModule, 'DrawLine');
      DrawGetTextUnderColor := GetProcAddress(FModule, 'DrawGetTextUnderColor');
      DrawGetStrokeColor := GetProcAddress(FModule, 'DrawGetStrokeColor');
      DrawGetFillColor := GetProcAddress(FModule, 'DrawGetFillColor');
      DrawEllipse := GetProcAddress(FModule, 'DrawEllipse');
      DrawComment := GetProcAddress(FModule, 'DrawComment');
      DrawColor := GetProcAddress(FModule, 'DrawColor');
      DrawCircle := GetProcAddress(FModule, 'DrawCircle');
      DrawBezier := GetProcAddress(FModule, 'DrawBezier');
      DrawArc := GetProcAddress(FModule, 'DrawArc');
      DrawAnnotation := GetProcAddress(FModule, 'DrawAnnotation');
      DrawAffine := GetProcAddress(FModule, 'DrawAffine');
      ClearDrawingWand := GetProcAddress(FModule, 'ClearDrawingWand');
      DrawGetStrokeMiterLimit := GetProcAddress(FModule, 'DrawGetStrokeMiterLimit');
      DrawGetFontWeight := GetProcAddress(FModule, 'DrawGetFontWeight');
      DrawGetFontStyle := GetProcAddress(FModule, 'DrawGetFontStyle');
      DrawGetFontStretch := GetProcAddress(FModule, 'DrawGetFontStretch');
      PushDrawingWand := GetProcAddress(FModule, 'PushDrawingWand');
      PopDrawingWand := GetProcAddress(FModule, 'PopDrawingWand');
      IsDrawingWand := GetProcAddress(FModule, 'IsDrawingWand');
      DrawSetVectorGraphics := GetProcAddress(FModule, 'DrawSetVectorGraphics');
      DrawSetStrokePatternURL := GetProcAddress(FModule, 'DrawSetStrokePatternURL');
      DrawSetStrokeDashArray := GetProcAddress(FModule, 'DrawSetStrokeDashArray');
      DrawSetFontFamily := GetProcAddress(FModule, 'DrawSetFontFamily');
      DrawSetFont := GetProcAddress(FModule, 'DrawSetFont');
      DrawSetFillPatternURL := GetProcAddress(FModule, 'DrawSetFillPatternURL');
      DrawSetClipPath := GetProcAddress(FModule, 'DrawSetClipPath');
      DrawRender := GetProcAddress(FModule, 'DrawRender');
      DrawPushPattern := GetProcAddress(FModule, 'DrawPushPattern');
      DrawPopPattern := GetProcAddress(FModule, 'DrawPopPattern');
      DrawGetTextAntialias := GetProcAddress(FModule, 'DrawGetTextAntialias');
      DrawGetStrokeAntialias := GetProcAddress(FModule, 'DrawGetStrokeAntialias');
      DrawComposite := GetProcAddress(FModule, 'DrawComposite');
      DrawClearException := GetProcAddress(FModule, 'DrawClearException');
      DrawGetStrokeLineJoin := GetProcAddress(FModule, 'DrawGetStrokeLineJoin');
      DrawGetStrokeLineCap := GetProcAddress(FModule, 'DrawGetStrokeLineCap');
      DrawGetGravity := GetProcAddress(FModule, 'DrawGetGravity');
      DrawGetFillRule := GetProcAddress(FModule, 'DrawGetFillRule');
      DrawGetClipRule := GetProcAddress(FModule, 'DrawGetClipRule');
      NewDrawingWand := GetProcAddress(FModule, 'NewDrawingWand');
      DrawTranslate := GetProcAddress(FModule, 'DrawTranslate');
      DrawSetViewbox := GetProcAddress(FModule, 'DrawSetViewbox');
      DrawSetTextUnderColor := GetProcAddress(FModule, 'DrawSetTextUnderColor');
      DrawSetTextEncoding := GetProcAddress(FModule, 'DrawSetTextEncoding');
      DrawSetTextDecoration := GetProcAddress(FModule, 'DrawSetTextDecoration');
      DrawSetTextAntialias := GetProcAddress(FModule, 'DrawSetTextAntialias');
      DrawSetTextAlignment := GetProcAddress(FModule, 'DrawSetTextAlignment');
      DrawSetStrokeWidth := GetProcAddress(FModule, 'DrawSetStrokeWidth');
      DrawSetStrokeAlpha := GetProcAddress(FModule, 'DrawSetStrokeAlpha');
      DrawSetStrokeMiterLimit := GetProcAddress(FModule, 'DrawSetStrokeMiterLimit');
      DrawSetStrokeLineJoin := GetProcAddress(FModule, 'DrawSetStrokeLineJoin');
      DrawSetStrokeLineCap := GetProcAddress(FModule, 'DrawSetStrokeLineCap');
      DrawSetStrokeDashOffset := GetProcAddress(FModule, 'DrawSetStrokeDashOffset');
      DrawSetStrokeColor := GetProcAddress(FModule, 'DrawSetStrokeColor');
      DrawSetStrokeAntialias := GetProcAddress(FModule, 'DrawSetStrokeAntialias');
      DrawSkewY := GetProcAddress(FModule, 'DrawSkewY');
      DrawSkewX := GetProcAddress(FModule, 'DrawSkewX');
      DrawSetGravity := GetProcAddress(FModule, 'DrawSetGravity');
      DrawSetFontWeight := GetProcAddress(FModule, 'DrawSetFontWeight');
      DrawSetFontStyle := GetProcAddress(FModule, 'DrawSetFontStyle');
      DrawSetFontStretch := GetProcAddress(FModule, 'DrawSetFontStretch');
      DrawSetFontSize := GetProcAddress(FModule, 'DrawSetFontSize');
      DrawSetFillRule := GetProcAddress(FModule, 'DrawSetFillRule');
      DrawSetFillAlpha := GetProcAddress(FModule, 'DrawSetFillAlpha');
      DrawSetFillColor := GetProcAddress(FModule, 'DrawSetFillColor');
      DrawSetClipUnits := GetProcAddress(FModule, 'DrawSetClipUnits');
      DrawSetClipRule := GetProcAddress(FModule, 'DrawSetClipRule');
      DrawScale := GetProcAddress(FModule, 'DrawScale');
      DrawRoundRectangle := GetProcAddress(FModule, 'DrawRoundRectangle');
      DrawRotate := GetProcAddress(FModule, 'DrawRotate');
      DrawRectangle := GetProcAddress(FModule, 'DrawRectangle');
      DrawPushDefs := GetProcAddress(FModule, 'DrawPushDefs');
      DrawPushClipPath := GetProcAddress(FModule, 'DrawPushClipPath');
      DrawPopDefs := GetProcAddress(FModule, 'DrawPopDefs');
      DrawPopClipPath := GetProcAddress(FModule, 'DrawPopClipPath');
      DrawPolyline := GetProcAddress(FModule, 'DrawPolyline');
      DrawPolygon := GetProcAddress(FModule, 'DrawPolygon');
      DrawPoint := GetProcAddress(FModule, 'DrawPoint');
      DrawPathStart := GetProcAddress(FModule, 'DrawPathStart');
      DrawPathMoveToRelative := GetProcAddress(FModule, 'DrawPathMoveToRelative');
      DrawPathMoveToAbsolute := GetProcAddress(FModule, 'DrawPathMoveToAbsolute');
      DrawPathLineToVerticalRelative := GetProcAddress(FModule, 'DrawPathLineToVerticalRelative');
      DrawPathLineToVerticalAbsolute := GetProcAddress(FModule, 'DrawPathLineToVerticalAbsolute');

      // magick_attribute.inc
      MagickGetException := GetProcAddress(FModule, 'MagickGetException');
      MagickGetFilename := GetProcAddress(FModule, 'MagickGetFilename');
      MagickGetFormat := GetProcAddress(FModule, 'MagickGetFormat');
      MagickGetHomeURL := GetProcAddress(FModule, 'MagickGetHomeURL');
      MagickGetOption := GetProcAddress(FModule, 'MagickGetOption');
      MagickGetCompression := GetProcAddress(FModule, 'MagickGetCompression');
      MagickGetCopyright := GetProcAddress(FModule, 'MagickGetCopyright');
      MagickGetPackageName := GetProcAddress(FModule, 'MagickGetPackageName');
      MagickGetQuantumDepth := GetProcAddress(FModule, 'MagickGetQuantumDepth');
      MagickGetQuantumRange := GetProcAddress(FModule, 'MagickGetQuantumRange');
      MagickGetReleaseDate := GetProcAddress(FModule, 'MagickGetReleaseDate');
      MagickGetVersion := GetProcAddress(FModule, 'MagickGetVersion');
      MagickGetSamplingFactors := GetProcAddress(FModule, 'MagickGetSamplingFactors');
      MagickGetInterlaceScheme := GetProcAddress(FModule, 'MagickGetInterlaceScheme');
      MagickSetResolution := GetProcAddress(FModule, 'MagickSetResolution');

      GInitializedImageMagick := True;
      MagickWandGenesis;
    end;
  end
  else
    Result := True;
end;

procedure FinalizeImageMagickWand;
begin
  if GInitializedImageMagick then
  begin
    MagickWandTerminus;
    FreeLibrary(FModule);
    GInitializedImageMagick := False;
  end;
end;

{$ELSE}
implementation
{$ENDIF}
end.
