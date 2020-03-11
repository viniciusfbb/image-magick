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

  Magick Wand Image Methods.
}

{ BugFix :
  - MagickDrawImage(...const drawing_wand: PMagickWand...
  + MagickDrawImage(...const drawing_wand: PDrawingWand...
  - MagickAffineTransformImage(...const drawing_wand: PMagickWand...
  + MagickAffineTransformImage(...const drawing_wand: PDrawingWand...
  - MagickAnnotateImage(...const drawing_wand: PMagickWand...
  + MagickAnnotateImage(...const drawing_wand: PDrawingWand...
}

var
MagickGetImageChannelStatistics: function(wand: PMagickWand): PChannelStatistics; cdecl;

MagickGetImageAttribute: function(wand: PMagickWand): PAnsiChar; cdecl;
MagickGetImageFilename: function(wand: PMagickWand): PAnsiChar; cdecl;
MagickGetImageFormat: function(wand: PMagickWand): PAnsiChar; cdecl;
MagickGetImageSignature: function(wand: PMagickWand): PAnsiChar; cdecl;
MagickIdentifyImage: function(wand: PMagickWand): PAnsiChar; cdecl;

MagickGetImageCompose: function(wand: PMagickWand): CompositeOperator; cdecl;

MagickGetImageColorspace: function(wand: PMagickWand): ColorspaceType; cdecl;

MagickGetImageCompression: function(wand: PMagickWand): CompressionType; cdecl;

MagickGetImageDispose: function(wand: PMagickWand): DisposeType; cdecl;

MagickGetImageGamma: function(wand: PMagickWand): double; cdecl;
MagickGetImageTotalInkDensity: function(wand: PMagickWand): double; cdecl;

GetImageFromMagickWand: function(wand: PMagickWand): PImage; cdecl;

MagickGetImageType: function(wand: PMagickWand): ImageType; cdecl;

MagickGetImageInterlaceScheme: function(wand: PMagickWand): InterlaceType; cdecl;

MagickGetImageIndex: function(wand: PMagickWand): clong; cdecl;

MagickAdaptiveThresholdImage: function(wand: PMagickWand; const width, height: culong; const offset: clong): MagickBooleanType; cdecl;
MagickAddImage: function(wand: PMagickWand; const add_wand: PMagickWand): MagickBooleanType; cdecl;
MagickAddNoiseImage: function(wand: PMagickWand; const noise_type: NoiseType): MagickBooleanType; cdecl;
MagickAffineTransformImage: function(wand: PMagickWand; const drawing_wand: PDrawingWand): MagickBooleanType; cdecl;
MagickAnnotateImage: function(wand: PMagickWand; const drawing_wand: PDrawingWand; const x, y, angle: double; const text: PAnsiChar): MagickBooleanType; cdecl;
MagickAnimateImages: function(wand: PMagickWand; const server_name: PAnsiChar): MagickBooleanType; cdecl;
MagickBlackThresholdImage: function(wand: PMagickWand; const threshold: PPixelWand): MagickBooleanType; cdecl;
MagickBlurImage: function(wand: PMagickWand; const radius, sigma: double): MagickBooleanType; cdecl;
MagickBlurImageChannel: function(wand: PMagickWand; const channel: ChannelType; const radius, sigma: double): MagickBooleanType; cdecl;
MagickBorderImage: function(wand: PMagickWand; const bordercolor: PPixelWand; const width, height: culong): MagickBooleanType; cdecl;
MagickCharcoalImage: function(wand: PMagickWand; const radius, sigma: double): MagickBooleanType; cdecl;
MagickChopImage: function(wand: PMagickWand; const width, height: culong; const x, y: clong): MagickBooleanType; cdecl;
MagickClipImage: function(wand: PMagickWand): MagickBooleanType; cdecl;
MagickClipPathImage: function(wand: PMagickWand; const pathname: PAnsiChar; const inside: MagickBooleanType): MagickBooleanType; cdecl;
MagickColorFloodfillImage: function(wand: PMagickWand; const fill: PPixelWand; const fuzz: double; const bordercolor: PPixelWand; const x, y: clong): MagickBooleanType; cdecl;
MagickColorizeImage: function(wand: PMagickWand; const colorize, opacity: PPixelWand): MagickBooleanType; cdecl;
MagickCommentImage: function(wand: PMagickWand; const comment: PAnsiChar): MagickBooleanType; cdecl;
MagickCompositeImage: function(wand: PMagickWand; const composite_wand: PMagickWand; const compose: CompositeOperator; const x, y: clong): MagickBooleanType; cdecl;
MagickConstituteImage: function(wand: PMagickWand; const columns, rows: culong; const map: PAnsiChar; const storage: StorageType; pixels: Pointer): MagickBooleanType; cdecl;
MagickContrastImage: function(wand: PMagickWand; const sharpen: MagickBooleanType): MagickBooleanType; cdecl;
MagickConvolveImage: function(wand: PMagickWand; const order: culong; const kernel: PDouble): MagickBooleanType; cdecl;
MagickConvolveImageChannel: function(wand: PMagickWand; const channel: ChannelType; const order: culong; const kernel: PDouble): MagickBooleanType; cdecl;
MagickCropImage: function(wand: PMagickWand; const width, height: culong; const x, y: clong): MagickBooleanType; cdecl;
MagickCycleColormapImage: function(wand: PMagickWand; const displace: clong): MagickBooleanType; cdecl;
MagickDespeckleImage: function(wand: PMagickWand): MagickBooleanType; cdecl;
MagickDisplayImage: function(wand: PMagickWand; const server_name: PAnsiChar): MagickBooleanType; cdecl;
MagickDisplayImages: function(wand: PMagickWand; const server_name: PAnsiChar): MagickBooleanType; cdecl;
MagickDrawImage: function(wand: PMagickWand; const drawing_wand: PDrawingWand): MagickBooleanType; cdecl;
MagickEdgeImage: function(wand: PMagickWand; const radius: double): MagickBooleanType; cdecl;
MagickEmbossImage: function(wand: PMagickWand; const radius, sigma: double): MagickBooleanType; cdecl;
MagickEnhanceImage: function(wand: PMagickWand): MagickBooleanType; cdecl;
MagickEqualizeImage: function(wand: PMagickWand): MagickBooleanType; cdecl;
MagickEvaluateImage: function(wand: PMagickWand; const op: MagickEvaluateOperator; const constant: double): MagickBooleanType; cdecl;
MagickEvaluateImageChannel: function(wand: PMagickWand; const op: MagickEvaluateOperator; const constant: double): MagickBooleanType; cdecl;
MagickFlipImage: function(wand: PMagickWand): MagickBooleanType; cdecl;
MagickFlopImage: function(wand: PMagickWand): MagickBooleanType; cdecl;
MagickFrameImage: function(wand: PMagickWand; const matte_color: PPixelWand; const width, height: culong; const inner_bevel, outer_bevel: clong): MagickBooleanType; cdecl;
MagickGammaImage: function(wand: PMagickWand; const gamma: double): MagickBooleanType; cdecl;
MagickGammaImageChannel: function(wand: PMagickWand; const channel: ChannelType; const gamma: double): MagickBooleanType; cdecl;
MagickGaussianBlurImage: function(wand: PMagickWand; const radius, sigma: double): MagickBooleanType; cdecl;
MagickGaussianBlurImageChannel: function(wand: PMagickWand; const channel: ChannelType; const radius, sigma: double): MagickBooleanType; cdecl;
MagickGetImageBackgroundColor: function(wand: PMagickWand; background_color: PPixelWand): MagickBooleanType; cdecl;
MagickGetImageBluePrimary: function(wand: PMagickWand; x, y: Pdouble): MagickBooleanType; cdecl;
MagickGetImageBorderColor: function(wand: PMagickWand; border_color: PPixelWand ): MagickBooleanType; cdecl;
MagickGetImageChannelDistortion: function(wand: PMagickWand; const reference: PMagickWand; const channel: ChannelType; const metric: MetricType; distortion: Pdouble): MagickBooleanType; cdecl;
MagickGetImageDistortion: function(wand: PMagickWand; const reference: PMagickWand; const metric: MetricType; distortion: Pdouble): MagickBooleanType; cdecl;
MagickGetImageChannelExtrema: function(wand: PMagickWand; const channel: ChannelType; minima, maxima: Pculong): MagickBooleanType; cdecl;
MagickGetImageChannelMean: function(wand: PMagickWand; const channel: ChannelType; mean, standard_deviation: Pdouble): MagickBooleanType; cdecl;
MagickGetImageColormapColor: function(wand: PMagickWand; const index: culong; color: PPixelWand): MagickBooleanType; cdecl;
MagickGetImageExtrema: function(wand: PMagickWand; min, max: culong): MagickBooleanType; cdecl;
MagickGetImageGreenPrimary: function(wand: PMagickWand; x, y: Pdouble): MagickBooleanType; cdecl;
MagickGetImageMatteColor: function(wand: PMagickWand; matte_color: PPixelWand): MagickBooleanType; cdecl;
MagickGetImagePage: function(wand: PMagickWand; width, height: Pculong; x, y: Pclong): MagickBooleanType; cdecl;
MagickGetImagePixelColor: function(wand: PMagickWand; const x, y: clong; color: PPixelWand): MagickBooleanType; cdecl;
MagickGetImagePixels: function(wand: PMagickWand; const x, y: clong; const columns, rows: culong; const map: PAnsiChar; const storage: StorageType; pixels: Pointer): MagickBooleanType; cdecl;
MagickGetImageRedPrimary: function(wand: PMagickWand; x, y: Pdouble): MagickBooleanType; cdecl;
MagickGetImageResolution: function(wand: PMagickWand; x, y: Pdouble): MagickBooleanType; cdecl;
MagickGetImageWhitePoint: function(wand: PMagickWand; x, y: Pdouble): MagickBooleanType; cdecl;
MagickHasNextImage: function(wand: PMagickWand): MagickBooleanType; cdecl;
MagickHasPreviousImage: function(wand: PMagickWand): MagickBooleanType; cdecl;
MagickImplodeImage: function(wand: PMagickWand; const radius: double): MagickBooleanType; cdecl;
MagickLabelImage: function(wand: PMagickWand; const _label: PAnsiChar): MagickBooleanType; cdecl;
MagickLevelImage: function(wand: PMagickWand; const black_point, gamma, white_point: double): MagickBooleanType; cdecl;
MagickLevelImageChannel: function(wand: PMagickWand; const channel: ChannelType; const black_point, gamma, white_point: double ): MagickBooleanType; cdecl;
MagickMagnifyImage: function(wand: PMagickWand): MagickBooleanType; cdecl;
MagickMapImage: function(wand: PMagickWand; const map_wand: PMagickWand; const dither: MagickBooleanType): MagickBooleanType; cdecl;
MagickMatteFloodfillImage: function(wand: PMagickWand; const opacity: Quantum; const fuzz: double; const bordercolor: PPixelWand; const x, y: clong): MagickBooleanType; cdecl;
MagickMedianFilterImage: function(wand: PMagickWand; const radius: double): MagickBooleanType; cdecl;
MagickMinifyImage: function(wand: PMagickWand): MagickBooleanType; cdecl;
MagickModulateImage: function(wand: PMagickWand; const brightness, saturation, hue: double): MagickBooleanType; cdecl;
MagickMotionBlurImage: function(wand: PMagickWand; const radius, sigma, angle: double): MagickBooleanType; cdecl;
MagickNegateImage: function(wand: PMagickWand; const gray: MagickBooleanType): MagickBooleanType; cdecl;
{
function MagickNegateImageChannel(wand: PMagickWand): MagickBooleanType; external WandExport delayed;
  (MagickWand *,const ChannelType,
    const MagickBooleanType),
  Documentation not found
}
MagickNewImage: function(wand: PMagickWand; const columns, rows: culong; const background: PPixelWand): MagickBooleanType; cdecl;
MagickNextImage: function(wand: PMagickWand): MagickBooleanType; cdecl;
MagickNormalizeImage: function(wand: PMagickWand): MagickBooleanType; cdecl;
MagickOilPaintImage: function(wand: PMagickWand; const radius: double): MagickBooleanType; cdecl;
MagickPaintOpaqueImage: function(wand: PMagickWand; const target, fill: PPixelWand; const fuzz: double): MagickBooleanType; cdecl;
MagickPaintTransparentImage: function(wand: PMagickWand; const target: PPixelWand; const opacity: Quantum; const fuzz: double): MagickBooleanType; cdecl;
MagickPingImage: function(wand: PMagickWand; const filename: PAnsiChar): MagickBooleanType; cdecl;
{
function MagickPosterizeImage(wand: PMagickWand;
 const levels: Word; const dither: MagickBooleanType): MagickBooleanType; cdecl; external WandExport delayed;
??
}
MagickPreviousImage: function(wand: PMagickWand): MagickBooleanType; cdecl;
MagickProfileImage: function(wand: PMagickWand; const name: PAnsiChar; const profile: PAnsiChar; const length: culong): MagickBooleanType; cdecl;
MagickQuantizeImage: function(wand: PMagickWand; const number_colors: culong; const colorspace: ColorspaceType; const treedepth: culong; const dither, measure_error): MagickBooleanType; cdecl;
MagickQuantizeImages: function(wand: PMagickWand; const number_colors: culong; const colorspace: ColorspaceType; const treedepth: culong; const dither: MagickBooleanType; const measure_error: MagickBooleanType): MagickBooleanType; cdecl;
MagickRadialBlurImage: function(wand: PMagickWand; const angle: double): MagickBooleanType; cdecl;
MagickRadialBlurImageChannel: function(wand: PMagickWand; const channel: ChannelType; const angle: double): MagickBooleanType; cdecl;
MagickRaiseImage: function(wand: PMagickWand; const width, height: culong; const x, y: clong; const raise_: MagickBooleanType): MagickBooleanType; cdecl;
MagickReadImage: function(wand: PMagickWand; const filename: PAnsiChar): MagickBooleanType; cdecl;
MagickReadImageBlob: function(wand: PMagickWand; const blob: Pointer; const length: clong): MagickBooleanType; cdecl;
//function MagickReadImageFile(wand: PMagickWand; file_: file): MagickBooleanType; external WandExport delayed;

MagickReduceNoiseImage: function(wand: PMagickWand; const radius: double): MagickBooleanType; cdecl;
MagickRemoveImage: function(wand: PMagickWand): MagickBooleanType; cdecl;
MagickResampleImage: function(wand: PMagickWand; const x_resolution, y_resolution: double; const filter: FilterTypes; const blur: double): MagickBooleanType; cdecl;
MagickResizeImage: function(wand: PMagickWand; const columns, rows: culong; const filter: FilterTypes; const blur: double): MagickBooleanType; cdecl;
MagickRollImage: function(wand: PMagickWand; const x: clong; const y: culong): MagickBooleanType; cdecl;
MagickRotateImage: function(wand: PMagickWand; const background: PPixelWand; const degrees: double): MagickBooleanType; cdecl;
MagickSampleImage: function(wand: PMagickWand; const columns, rows: culong): MagickBooleanType; cdecl;
MagickScaleImage: function(wand: PMagickWand; const columns, rows: culong): MagickBooleanType; cdecl;
MagickSeparateImageChannel: function(wand: PMagickWand; const channel: ChannelType): MagickBooleanType; cdecl;

// MagickSepiaToneImage(MagickWand *,const double),

MagickSetImage: function(wand: PMagickWand; const set_wand: PMagickWand): MagickBooleanType; cdecl;
MagickSetImageAttribute: function(wand: PMagickWand; const key, attribute: PAnsiChar): MagickBooleanType; cdecl;
MagickSetImageBackgroundColor: function(wand: PMagickWand; const background: PPixelWand): MagickBooleanType; cdecl;
MagickSetImageBias: function(wand: PMagickWand; const bias: double): MagickBooleanType; cdecl;
MagickSetImageBluePrimary: function(wand: PMagickWand; const x, y: double): MagickBooleanType; cdecl;
MagickSetImageBorderColor: function(wand: PMagickWand; const border: PPixelWand): MagickBooleanType; cdecl;
MagickSetImageChannelDepth: function(wand: PMagickWand; const channel: ChannelType; const depth: culong): MagickBooleanType; cdecl;
MagickSetImageColormapColor: function(wand: PMagickWand; const index: culong; const color: PPixelWand): MagickBooleanType; cdecl;
MagickSetImageColorspace: function(wand: PMagickWand; const colorspace: ColorspaceType): MagickBooleanType; cdecl;
MagickSetImageCompose: function(wand: PMagickWand; const compose: CompositeOperator): MagickBooleanType; cdecl;
MagickSetImageCompression: function(wand: PMagickWand; const compression: CompressionType): MagickBooleanType; cdecl;
MagickSetImageCompressionQuality: function(wand: PMagickWand; const quality: culong): MagickBooleanType; cdecl;
MagickSetImageDelay: function(wand: PMagickWand; const delay: culong): MagickBooleanType; cdecl;
MagickSetImageDepth: function(wand: PMagickWand; const depth: culong): MagickBooleanType; cdecl;
MagickSetImageDispose: function(wand: PMagickWand; const dispose: DisposeType): MagickBooleanType; cdecl;
MagickSetImageExtent: function(wand: PMagickWand; const columns, rows: culong): MagickBooleanType; cdecl;
MagickSetImageFilename: function(wand: PMagickWand; const filename: PAnsiChar): MagickBooleanType; cdecl;
MagickSetImageFormat: function(wand: PMagickWand; const format: PAnsiChar): MagickBooleanType; cdecl;
MagickSetImageGamma: function(wand: PMagickWand; const gamma: Double): MagickBooleanType; cdecl;
MagickSetImageGreenPrimary: function(wand: PMagickWand; const x, y: Double): MagickBooleanType; cdecl;
MagickSetImageIndex: function(wand: PMagickWand; const index: clong): MagickBooleanType; cdecl;
MagickSetImageInterlaceScheme: function(wand: PMagickWand; const interlace_scheme: InterlaceType): MagickBooleanType; cdecl;
MagickSetImageIterations: function(wand: PMagickWand; const iterations: culong): MagickBooleanType; cdecl;
MagickSetImageMatteColor: function(wand: PMagickWand; const matte: PPixelWand): MagickBooleanType; cdecl;
MagickSetImagePage: function(wand: PMagickWand; const width, height: culong; const x, y: clong): MagickBooleanType; cdecl;
MagickSetImagePixels: function(wand: PMagickWand; const x, y: clong; const columns, rows: culong; const map: PAnsiChar; const storage: StorageType; const pixels: Pointer): MagickBooleanType; cdecl;
MagickSetImageProfile: function(wand: PMagickWand; const name: PAnsiChar; const profile: Pointer; const length: culong): MagickBooleanType; cdecl;
MagickSetImageRedPrimary: function(wand: PMagickWand; const x, y: Double): MagickBooleanType; cdecl;
MagickSetImageRenderingIntent: function(wand: PMagickWand; const rendering_intent: RenderingIntent ): MagickBooleanType; cdecl;
MagickSetImageResolution: function(wand: PMagickWand; const x_resolution, y_resolution: double ): MagickBooleanType; cdecl;
MagickSetImageScene: function(wand: PMagickWand; const scene: culong): MagickBooleanType; cdecl;
MagickSetImageType: function(wand: PMagickWand; const image_type: ImageType ): MagickBooleanType; cdecl;
MagickSetImageUnits: function(wand: PMagickWand; const units: ResolutionType ): MagickBooleanType; cdecl;
//function MagickSetImageVirtualPixelMethod(wand: PMagickWand;
// const method: VirtualPixelMethod): MagickBooleanType; cdecl;
MagickSetImageWhitePoint: function(wand: PMagickWand; const x, y: double ): MagickBooleanType; cdecl;
MagickShadowImage: function(wand: PMagickWand; const radius, sigma: double; const x, y: clong ): MagickBooleanType; cdecl;
MagickSharpenImage: function(wand: PMagickWand; const radius, sigma: double ): MagickBooleanType; cdecl;
MagickSharpenImageChannel: function(wand: PMagickWand; const channel: ChannelType; const radius, sigma: double): MagickBooleanType; cdecl;
MagickShaveImage: function(wand: PMagickWand; const columns, rows: culong ): MagickBooleanType; cdecl;
MagickShearImage: function(wand: PMagickWand; const background: PPixelWand; const x_shear, y_shear: double): MagickBooleanType; cdecl;
MagickSigmoidalContrastImage: function(wand: PMagickWand; const sharpen: MagickBooleanType; const alpha, beta: double ): MagickBooleanType; cdecl;
MagickSigmoidalContrastImageChannel: function(wand: PMagickWand; const channel: ChannelType; const sharpen: MagickBooleanType; const alpha, beta: double ): MagickBooleanType; cdecl;
MagickSolarizeImage: function(wand: PMagickWand; const threshold: double ): MagickBooleanType; cdecl;
MagickSpliceImage: function(wand: PMagickWand; const width, height: culong; const x, y: clong ): MagickBooleanType; cdecl;
MagickSpreadImage: function(wand: PMagickWand; const radius: double): MagickBooleanType; cdecl;
MagickStripImage: function(wand: PMagickWand): MagickBooleanType; cdecl;
MagickSwirlImage: function(wand: PMagickWand; const degrees: double): MagickBooleanType; cdecl;
MagickTintImage: function(wand: PMagickWand; const tint: PPixelWand; const opacity: PPixelWand ): MagickBooleanType; cdecl;
MagickThresholdImage: function(wand: PMagickWand; const threshold: double): MagickBooleanType; cdecl;
MagickThresholdImageChannel: function(wand: PMagickWand; const channel: ChannelType; const threshold: double): MagickBooleanType; cdecl;
MagickTrimImage: function(wand: PMagickWand; const fuzz: double): MagickBooleanType; cdecl;
MagickUnsharpMaskImage: function(wand: PMagickWand; const radius, sigma, amount, threshold: double): MagickBooleanType; cdecl;
MagickUnsharpMaskImageChannel: function(wand: PMagickWand; const channel: ChannelType; const radius, sigma, amount, threshold: double ): MagickBooleanType; cdecl;
MagickWaveImage: function(wand: PMagickWand; const amplitude, wave_length: double ): MagickBooleanType; cdecl;
MagickWhiteThresholdImage: function(wand: PMagickWand; const threshold: PPixelWand): MagickBooleanType; cdecl;
MagickWriteImage: function(wand: PMagickWand; const filename: PAnsiChar): MagickBooleanType; cdecl;
//  MagickWriteImageFile(MagickWand *,FILE *),
MagickWriteImages: function(wand: PMagickWand; const filename: PAnsiChar; const adjoin: MagickBooleanType ): MagickBooleanType; cdecl;
//  MagickWriteImagesFile(MagickWand *,FILE *);


MagickSetImageProgressMonitor: function(wand: PMagickWand; const progress_monitor: MagickProgressMonitor; client_data: Pointer): MagickProgressMonitor; cdecl;

MagickGetImageSize: function(wand: PMagickWand): MagickSizeType; cdecl;

MagickAppendImages: function(wand: PMagickWand; const stack: MagickBooleanType): PMagickWand; cdecl;
MagickAverageImages: function(wand: PMagickWand): PMagickWand; cdecl;
MagickCoalesceImages: function(wand: PMagickWand): PMagickWand; cdecl;
MagickCombineImages: function(wand: PMagickWand; para2: ChannelType): PMagickWand; cdecl;
MagickCompareImageChannels: function(wand: PMagickWand; const reference: PMagickWand; const channel: ChannelType; const metric: MetricType; distortion: PDouble ): PMagickWand; cdecl;
MagickCompareImages: function(wand: PMagickWand; const reference: PMagickWand; const metric: MetricType; distortion: PDouble ): PMagickWand; cdecl;
MagickDeconstructImages: function(wand: PMagickWand): PMagickWand; cdecl;
MagickFlattenImages: function(wand: PMagickWand): PMagickWand; cdecl;
MagickFxImage: function(wand: PMagickWand; const expression: PAnsiChar): PMagickWand; cdecl;
MagickFxImageChannel: function(wand: PMagickWand; const channel: ChannelType; const expression: PAnsiChar ): PMagickWand; cdecl;
MagickGetImage: function(wand: PMagickWand): PMagickWand; cdecl;
MagickGetImageRegion: function(wand: PMagickWand; const width, height: culong; const x, y: clong ): PMagickWand; cdecl;
MagickMorphImages: function(wand: PMagickWand; const number_frames: culong): PMagickWand; cdecl;
MagickMosaicImages: function(wand: PMagickWand): PMagickWand; cdecl;
//function MagickMontageImage(wand: PMagickWand;
// const drawing_wand: DrawingWand; const tile_geometry: PAnsiChar;
// const thumbnail_geometry: PAnsiChar; const mode: MontageMode; const frame: PAnsiChar
// ): PMagickWand; cdecl;
MagickPreviewImages: function(wand: PMagickWand; const preview: PreviewType): PMagickWand; cdecl;
MagickSteganoImage: function(wand: PMagickWand; const watermark_wand: PMagickWand; const offset: clong): PMagickWand; cdecl;
MagickStereoImage: function(wand: PMagickWand; const offset_wand: PMagickWand): PMagickWand; cdecl;
MagickTextureImage: function(wand: PMagickWand; const texture_wand: PMagickWand): PMagickWand; cdecl;
MagickTransformImage: function(wand: PMagickWand; const crop, geometry: PAnsiChar): PMagickWand; cdecl;
NewMagickWandFromImage: function(para1: PImage): PMagickWand; cdecl;

MagickGetImageHistogram: function(wand: PMagickWand; number_colors: Pculong): PPPixelWand; cdecl;

MagickGetImageRenderingIntent: function(wand: PMagickWand): RenderingIntent; cdecl;

MagickGetImageUnits: function(wand: PMagickWand): ResolutionType; cdecl;

MagickGetImageBlob: function(wand: PMagickWand; length: Pcsize_t): PByte; cdecl;
MagickGetImagesBlob: function(wand: PMagickWand; length: Pcsize_t): PByte; cdecl;
MagickGetImageProfile: function(wand: PMagickWand; name: PAnsiChar; length: Pcsize_t): PByte; cdecl;
MagickRemoveImageProfile: function(wand: PMagickWand; name: PAnsiChar; length: Pcsize_t): PByte; cdecl;

MagickGetImageColors: function(wand: PMagickWand): culong; cdecl;
MagickGetImageCompressionQuality: function(wand: PMagickWand): culong; cdecl;
MagickGetImageDelay: function(wand: PMagickWand): culong; cdecl;
MagickGetImageChannelDepth: function(wand: PMagickWand; const channel: ChannelType): culong; cdecl;
MagickGetImageDepth: function(wand: PMagickWand): culong; cdecl;
MagickGetImageHeight: function(wand: PMagickWand): culong; cdecl;
MagickGetImageIterations: function(wand: PMagickWand): culong; cdecl;
MagickGetImageScene: function(wand: PMagickWand): culong; cdecl;
MagickGetImageWidth: function(wand: PMagickWand): culong; cdecl;
MagickGetNumberImages: function(wand: PMagickWand): culong; cdecl;

//function MagickGetImageVirtualPixelMethod(wand: PMagickWand): VirtualPixelMethod; cdecl;

{
  Deprecated methods.
}
{extern WandExport char
  *MagickDescribeImage(MagickWand *);

extern WandExport MagickBooleanType
  MagickOpaqueImage(MagickWand *,const PixelWand *,const PixelWand *,
    const double),
  MagickSetImageOption(MagickWand *,const char *,const char *,const char *),
  MagickTransparentImage(MagickWand *,const PixelWand *,const Quantum,
    const double);

extern WandExport MagickWand
  *MagickRegionOfInterestImage(MagickWand *,const unsigned long,
	  const unsigned long,const long,const long);

extern WandExport unsigned char
  *MagickWriteImageBlob(MagickWand *,size_t *);
}
