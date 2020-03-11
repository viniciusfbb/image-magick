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

  ImageMagick drawing wand API.
}

{
  Declaration from drawing-wand.c
}
type
 PathOperation = (
  PathDefaultOperation,
  PathCloseOperation,                        // Z|z (none) */
  PathCurveToOperation,                      // C|c (x1 y1 x2 y2 x y)+ */
  PathCurveToQuadraticBezierOperation,       // Q|q (x1 y1 x y)+ */
  PathCurveToQuadraticBezierSmoothOperation, // T|t (x y)+ */
  PathCurveToSmoothOperation,                // S|s (x2 y2 x y)+ */
  PathEllipticArcOperation,                  // A|a (rx ry x-axis-rotation large-arc-flag sweep-flag x y)+ */
  PathLineToHorizontalOperation,             // H|h x+ */
  PathLineToOperation,                       // L|l (x y)+ */
  PathLineToVerticalOperation,               // V|v y+ */
  PathMoveToOperation                        // M|m (x y)+ */
 );

type
 PathMode = (
  DefaultPathMode,
  AbsolutePathMode,
  RelativePathMode
 );

  DrawingWand = record
    id: culong;

    name: array[0..MaxTextExtent] of Char;

    { Support structures }
  
    image: PImage;

    exception: ExceptionInfo;

    { MVG output string and housekeeping }
  
    mvg: PAnsiChar;               // MVG data

    mvg_alloc,                // total allocated memory
//    mvg_length: size_t;       // total MVG length

    mvg_width: culong;      // current line width 

    { Pattern support }
    
    pattern_id: PAnsiChar;

    pattern_bounds: RectangleInfo;

//    pattern_offset: size_t;

    { Graphic wand }
    
    index: culong;          // array index

    graphic_context: PPDrawInfo;

    filter_off: MagickBooleanType;    // true if not filtering attributes

    { Pretty-printing depth }
  
    indent_depth: culong;       // number of left-hand pad characters 

    { Path operation support }
  
    path_operation: PathOperation;

    path_mode: PathMode;

    destroy,
    debug: MagickBooleanType;

    signature: culong;
  end;
 
  PDrawingWand = ^DrawingWand;

const x = 9;

var
DrawGetTextAlignment: function(const wand: PDrawingWand): AlignType; cdecl;

DrawGetClipPath: function(const wand: PDrawingWand): PAnsiChar; cdecl;
DrawGetException: function(const wand: PDrawingWand; severity: PExceptionType): PAnsiChar; cdecl;
DrawGetFont: function(const wand: PDrawingWand): PAnsiChar; cdecl;
DrawGetFontFamily: function(const wand: PDrawingWand): PAnsiChar; cdecl;
DrawGetTextEncoding: function(const wand: PDrawingWand): PAnsiChar; cdecl;
DrawGetVectorGraphics: function(const wand: PDrawingWand): PAnsiChar; cdecl;

DrawGetClipUnits: function(const wand: PDrawingWand): ClipPathUnits; cdecl;

DrawGetTextDecoration: function(const wand: PDrawingWand): DecorationType; cdecl;

DrawGetFillAlpha: function(const wand: PDrawingWand): double; cdecl;
DrawGetFontSize: function(const wand: PDrawingWand): double; cdecl;
DrawGetStrokeDashArray: function(const wand: PDrawingWand; number_elements: culong): PDouble; cdecl;
DrawGetStrokeDashOffset: function(const wand: PDrawingWand): double; cdecl;
DrawGetStrokeAlpha: function(const wand: PDrawingWand): double; cdecl;
DrawGetStrokeWidth: function(const wand: PDrawingWand): double; cdecl;

PeekDrawingWand: function(const wand: PDrawingWand): PDrawInfo; cdecl;

CloneDrawingWand: function(const wand: PDrawingWand): PDrawingWand; cdecl;
DestroyDrawingWand: function(wand: PDrawingWand): PDrawingWand; cdecl;
{ Sem documenta
function DrawAllocateWand(const DrawInfo *,Image *): PDrawingWand; cdecl; external WandExport;
}
NewDrawingWand: function: PDrawingWand; cdecl;

DrawGetClipRule: function(const wand: PDrawingWand): FillRule; cdecl;
DrawGetFillRule: function(const wand: PDrawingWand): FillRule; cdecl;

DrawGetGravity: function(const wand: PDrawingWand): GravityType; cdecl;

DrawGetStrokeLineCap: function(const wand: PDrawingWand): LineCap; cdecl;

DrawGetStrokeLineJoin: function(const wand: PDrawingWand): LineJoin; cdecl;

DrawClearException: function(wand: PDrawingWand): MagickBooleanType; cdecl;
DrawComposite: function(wand: PDrawingWand; const compose: CompositeOperator; const x, y, width, height: double; magick_wand: PMagickWand): MagickBooleanType; cdecl;
DrawGetStrokeAntialias: function(const wand: PDrawingWand): MagickBooleanType; cdecl;
DrawGetTextAntialias: function(const wand: PDrawingWand): MagickBooleanType; cdecl;
DrawPopPattern: function(wand: PDrawingWand): MagickBooleanType; cdecl;
DrawPushPattern: function(wand: PDrawingWand; const pattern_id: PAnsiChar; const x, y, width, height: double): MagickBooleanType; cdecl;
DrawRender: function(wand: PDrawingWand): MagickBooleanType; cdecl;
DrawSetClipPath: function(wand: PDrawingWand; const clip_path: PAnsiChar): MagickBooleanType; cdecl;
DrawSetFillPatternURL: function(wand: PDrawingWand; const fill_url: PAnsiChar): MagickBooleanType; cdecl;
DrawSetFont: function(wand: PDrawingWand; const font_name: PAnsiChar): MagickBooleanType; cdecl;
DrawSetFontFamily: function(wand: PDrawingWand; const font_family: PAnsiChar): MagickBooleanType; cdecl;
DrawSetStrokeDashArray: function(wand: PDrawingWand; const number_elements: culong; const dash_array: Pdouble): MagickBooleanType; cdecl;
DrawSetStrokePatternURL: function(wand: PDrawingWand; const stroke_url: PAnsiChar): MagickBooleanType; cdecl;
DrawSetVectorGraphics: function(wand: PDrawingWand; const xml: PAnsiChar): MagickBooleanType; cdecl;
IsDrawingWand: function(const wand: PDrawingWand): MagickBooleanType; cdecl;
PopDrawingWand: function(wand: PDrawingWand): MagickBooleanType; cdecl;
PushDrawingWand: function(wand: PDrawingWand): MagickBooleanType; cdecl;

DrawGetFontStretch: function(const wand: PDrawingWand): StretchType; cdecl;

DrawGetFontStyle: function(const wand: PDrawingWand): StyleType; cdecl;

DrawGetFontWeight: function(const wand: PDrawingWand): culong; cdecl;
DrawGetStrokeMiterLimit: function(const wand: PDrawingWand): culong; cdecl;

ClearDrawingWand: procedure(wand: PDrawingWand); cdecl;
DrawAffine: procedure(wand: PDrawingWand; const affine: PAffineMatrix); cdecl;
DrawAnnotation: procedure(wand: PDrawingWand; const  x, y: double; const text: PAnsiChar); cdecl;
DrawArc: procedure(wand: PDrawingWand; const sx, sy, ex, ey, sd, ed: double); cdecl;
DrawBezier: procedure(wand: PDrawingWand; const number_coordinates: culong; const coordinates: PPointInfo); cdecl;
DrawCircle: procedure(wand: PDrawingWand; const ox, oy, px, py: double); cdecl;
DrawColor: procedure(wand: PDrawingWand; const x, y: double; const paint_method: PaintMethod); cdecl;
DrawComment: procedure(wand: PDrawingWand; const comment: PAnsiChar); cdecl;
DrawEllipse: procedure(wand: PDrawingWand; const ox, oy, rx, ry, start, end_: double); cdecl;
DrawGetFillColor: procedure(const wand: PDrawingWand; fill_color: PPixelWand); cdecl;
DrawGetStrokeColor: procedure(const wand: PDrawingWand; stroke_color: PPixelWand); cdecl;
DrawGetTextUnderColor: procedure(const wand: PDrawingWand; under_color: PPixelWand); cdecl;
DrawLine: procedure(wand: PDrawingWand; const sx, sy, ex, ey: double); cdecl;
DrawMatte: procedure(wand: PDrawingWand; const x, y: double; const paint_method: PaintMethod); cdecl;
DrawPathClose: procedure(wand: PDrawingWand); cdecl;
DrawPathCurveToAbsolute: procedure(wand: PDrawingWand; const x1, y1, x2, y2, x, y: double); cdecl;
DrawPathCurveToRelative: procedure(wand: PDrawingWand; const x1, y1, x2, y2, x, y: double); cdecl;
DrawPathCurveToQuadraticBezierAbsolute: procedure(wand: PDrawingWand; const x1, y1, x, y: double); cdecl;
DrawPathCurveToQuadraticBezierRelative: procedure(wand: PDrawingWand; const x1, y1, x, y: double); cdecl;
DrawPathCurveToQuadraticBezierSmoothAbsolute: procedure(wand: PDrawingWand; const x, y: double); cdecl;
DrawPathCurveToQuadraticBezierSmoothRelative: procedure(wand: PDrawingWand; const x, y: double); cdecl;
DrawPathCurveToSmoothAbsolute: procedure(wand: PDrawingWand; const x2, y2, x, y: double); cdecl;
DrawPathCurveToSmoothRelative: procedure(wand: PDrawingWand; const x2, y2, x, y: double); cdecl;
DrawPathEllipticArcAbsolute: procedure(wand: PDrawingWand; const rx, ry, x_axis_rotation: double; const large_arc_flag: MagickBooleanType; const sweep_flag: MagickBooleanType; const x, y: double); cdecl;
DrawPathEllipticArcRelative: procedure(wand: PDrawingWand; const rx, ry, x_axis_rotation: double; const large_arc_flag: MagickBooleanType; const sweep_flag: MagickBooleanType; const x, y: double); cdecl;
DrawPathFinish: procedure(wand: PDrawingWand); cdecl;
DrawPathLineToAbsolute: procedure(wand: PDrawingWand; const x, y: double); cdecl;
DrawPathLineToRelative: procedure(wand: PDrawingWand; const x, y: double); cdecl;
{procedure DrawPathLineToHorizontalAbsolute(wand: PDrawingWand;
 const mode: PathMode; const x: double); cdecl; external WandExport;
procedure DrawPathLineToHorizontalRelative(wand: PDrawingWand); cdecl; external WandExport;

Contradio na declarao
}
DrawPathLineToVerticalAbsolute: procedure(wand: PDrawingWand; const y: double); cdecl;
DrawPathLineToVerticalRelative: procedure(wand: PDrawingWand; const y: double); cdecl;
DrawPathMoveToAbsolute: procedure(wand: PDrawingWand; const x, y: double); cdecl;
DrawPathMoveToRelative: procedure(wand: PDrawingWand; const x, y: double); cdecl;
DrawPathStart: procedure(wand: PDrawingWand); cdecl;
DrawPoint: procedure(wand: PDrawingWand; const x, y: double); cdecl;
DrawPolygon: procedure(wand: PDrawingWand; const number_coordinates: culong; const coordinates: PPointInfo ); cdecl;
DrawPolyline: procedure(wand: PDrawingWand; const number_coordinates: culong; const coordinates: PPointInfo ); cdecl;
DrawPopClipPath: procedure(wand: PDrawingWand); cdecl;
DrawPopDefs: procedure(wand: PDrawingWand); cdecl;
DrawPushClipPath: procedure(wand: PDrawingWand; clip_path_id: PAnsiChar); cdecl;
DrawPushDefs: procedure(wand: PDrawingWand); cdecl;
DrawRectangle: procedure(wand: PDrawingWand; const x1, y1, x2, y2: double); cdecl;
DrawRotate: procedure(wand: PDrawingWand; const degrees: double); cdecl;
DrawRoundRectangle: procedure(wand: PDrawingWand; const x1, y1, x2, y2, rx, ry: double); cdecl;
DrawScale: procedure(wand: PDrawingWand; const x, y: double); cdecl;
DrawSetClipRule: procedure(wand: PDrawingWand; const fill_rule: FillRule); cdecl;
DrawSetClipUnits: procedure(wand: PDrawingWand; const clip_units: ClipPathUnits); cdecl;
DrawSetFillColor: procedure(wand: PDrawingWand; const fill_wand: PPixelWand); cdecl;
DrawSetFillAlpha: procedure(wand: PDrawingWand; const fill_opacity: double); cdecl;
DrawSetFillRule: procedure(wand: PDrawingWand; const fill_rule: FillRule); cdecl;
DrawSetFontSize: procedure(wand: PDrawingWand; const pointsize: double); cdecl;
DrawSetFontStretch: procedure(wand: PDrawingWand; const font_stretch: StretchType); cdecl;
DrawSetFontStyle: procedure(wand: PDrawingWand; const style: StyleType); cdecl;
DrawSetFontWeight: procedure(wand: PDrawingWand; const font_weight: culong); cdecl;
DrawSetGravity: procedure(wand: PDrawingWand; const gravity: GravityType); cdecl;
DrawSkewX: procedure(wand: PDrawingWand; const degrees: double); cdecl;
DrawSkewY: procedure(wand: PDrawingWand; const degrees: double); cdecl;
DrawSetStrokeAntialias: procedure(wand: PDrawingWand; const stroke_antialias: MagickBooleanType ); cdecl;
DrawSetStrokeColor: procedure(wand: PDrawingWand; const stroke_wand: PPixelWand); cdecl;
DrawSetStrokeDashOffset: procedure(wand: PDrawingWand; const dash_offset: double); cdecl;
DrawSetStrokeLineCap: procedure(wand: PDrawingWand; const linecap_: LineCap); cdecl;
DrawSetStrokeLineJoin: procedure(wand: PDrawingWand; const linejoin_: LineJoin); cdecl;
DrawSetStrokeMiterLimit: procedure(wand: PDrawingWand; const miterlimit: culong); cdecl;
DrawSetStrokeAlpha: procedure(wand: PDrawingWand; const stroke_opacity: double); cdecl;
DrawSetStrokeWidth: procedure(wand: PDrawingWand; const troke_width: double); cdecl;
DrawSetTextAlignment: procedure(wand: PDrawingWand; const alignment: AlignType); cdecl;
DrawSetTextAntialias: procedure(wand: PDrawingWand; const text_antialias: MagickBooleanType ); cdecl;
DrawSetTextDecoration: procedure(wand: PDrawingWand; const decoration: DecorationType); cdecl;
DrawSetTextEncoding: procedure(wand: PDrawingWand; const encoding: PAnsiChar); cdecl;
DrawSetTextUnderColor: procedure(wand: PDrawingWand; const under_wand: PPixelWand); cdecl;
DrawSetViewbox: procedure(wand: PDrawingWand; x1, y1, x2, y2: culong); cdecl;
DrawTranslate: procedure(wand: PDrawingWand; const x, y: double); cdecl;

{
  Deprecated.
}
{typedef struct _DrawingWand
  *DrawContext;

extern WandExport double
  DrawGetFillOpacity(const wand: PDrawingWand),
  DrawGetStrokeOpacity(const wand: PDrawingWand);

extern WandExport DrawInfo
  *DrawPeekGraphicWand(const wand: PDrawingWand);

extern WandExport void
  DrawPopGraphicContext(DrawingWand *),
  DrawPushGraphicContext(DrawingWand *),
  DrawSetFillOpacity(DrawingWand *,const double),
  DrawSetStrokeOpacity(DrawingWand *,const double);}
