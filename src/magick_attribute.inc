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

  Set or Get Magick Wand Attributes.
}

var
MagickGetException: function(wand: PMagickWand; severity: PExceptionType): PAnsiChar; cdecl;
MagickGetFilename: function(const wand: PMagickWand): PAnsiChar; cdecl;
MagickGetFormat: function(wand: PMagickWand): PAnsiChar; cdecl;
MagickGetHomeURL: function: PAnsiChar; cdecl;
MagickGetOption: function(wand: PMagickWand; const key: PAnsiChar): PAnsiChar; cdecl;
{sem documenta
extern WandExport char
  *MagickQueryConfigureOption(const char *),
  **MagickQueryConfigureOptions(const char *,unsigned long *),
  **MagickQueryFonts(const char *,unsigned long *),
  **MagickQueryFormats(const char *,unsigned long *);}

MagickGetCompression: function(wand: PMagickWand): CompressionType; cdecl;

MagickGetCopyright: function: PAnsiChar; cdecl;
MagickGetPackageName: function: PAnsiChar; cdecl;
MagickGetQuantumDepth: function(depth: Pculong): PAnsiChar; cdecl;
MagickGetQuantumRange: function(range: Pculong): PAnsiChar; cdecl;
MagickGetReleaseDate: function: PAnsiChar; cdecl;
MagickGetVersion: function(version: Pculong): PAnsiChar; cdecl;

MagickGetSamplingFactors: function(wand: PMagickWand; number_factors: Pculong): Pdouble; cdecl;
{function (wand: PMagickWand): Pdouble; cdecl; external WandExport;
  *MagickQueryFontMetrics(MagickWand *,const DrawingWand *,const char *),
  *MagickQueryMultilineFontMetrics(MagickWand *,const DrawingWand *,
    const char *);}

MagickGetInterlaceScheme: function(wand: PMagickWand): InterlaceType; cdecl;

{function (const wand: PMagickWand): ; cdecl; external WandExport;
extern WandExport MagickBooleanType
  MagickGetPage(MagickWand *,unsigned long *,unsigned long *,long *,long *),
  MagickGetSize(const MagickWand *,unsigned long *,unsigned long *),
  MagickSetBackgroundColor(MagickWand *,const PixelWand *),
  MagickSetCompression(MagickWand *,const CompressionType),
  MagickSetCompressionQuality(MagickWand *,const unsigned long),
  MagickSetFilename(MagickWand *,const char *),
  MagickSetFormat(MagickWand *,const char *),
  MagickSetInterlaceScheme(MagickWand *,const InterlaceType),
  MagickSetOption(MagickWand *,const char *,const char *),
  MagickSetPage(MagickWand *,const unsigned long,const unsigned long,
    const long,const long),
  MagickSetPassphrase(MagickWand *,const char *),
}

MagickSetResolution: function(wand: PMagickWand; const x_resolution, y_resolution:double):MagickBooleanType; cdecl;

{
  MagickSetResourceLimit(const ResourceType type,const unsigned long limit),
  MagickSetSamplingFactors(MagickWand *,const unsigned long,const double *),
  MagickSetSize(MagickWand *,const unsigned long,const unsigned long),
  MagickSetType(MagickWand *,const ImageType);

function (const wand: PMagickWand): ; cdecl; external WandExport;
extern WandExport MagickProgressMonitor
  MagickSetProgressMonitor(MagickWand *,const MagickProgressMonitor,void *);

function (const wand: PMagickWand): ; cdecl; external WandExport;
extern WandExport unsigned long
  MagickGetCompressionQuality(MagickWand *),
  MagickGetResource(const ResourceType),
  MagickGetResourceLimit(const ResourceType);}

