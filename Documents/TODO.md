CypryCPP 2D GAME FRAMEWORK - ROUND 1
-------------------------------------

ALL CLASSES WILL BE UP FOR MODIFICATION FOLLOWING TESTING.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

- STEP 1: Complete all conversions so that the code will build.
- STEP 2: Refactor, where possible and necessary, to take advantage of C# language features.
    - Some classes can become structs / records instead.
    - Some/Most Get / Set method declarations in interfaces could become Properties.
    - switch expressions instead of switch statements where appropriate.
    - Check methods to see if they can be virtual.
    - Check and/or correct visibility of classes/methods/properties etc.
    - Use sealed classes only where strictly necessary.
    - Use of virtual for base classes/methods and classes that are likely to be extended is essential.
    - Constantly look for opportunities to improve this code.
- STEP 3: Resolve ALL remaining TODOs.
- STEP 4: Ensure code is fully documented.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

- Methods like **Dispose(), ToString(), Equals(), GetHashCode() ( Essentially overridden system methods )**
- should be positioned at the END of source files.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

- All uses of IRunnable.Runnable need checking and correcting.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

- NO MAGIC NUMBERS!!!
- SORT OUT VERSIONING!!!
- PRIORITY is 2D classes first

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

- IP = Conversion In Progress.
-      = Class finished but may not be fully 'C++-ified'
- First column is for Code, Second column is for Documentation.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

Integrate DesktopBackend into CypryCPP?

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

ASSETS
------

    CODE   DOCUMENT
    ----   --------
    -      -      - AssetDescriptor
    -      -      - AssetLoaderParameters
    -      -      - AssetLoadingTask
    -      -      - AssetManager
    -      -      - AssetManagerHelper
    -      -      - IAssetErrorListener
    -      -      - IAssetManager
    -      -      - RefCountedContainer

ASSETS/LOADERS
--------------

    CODE   DOCUMENT
    ----   --------
    -      -      - AssetLoader
    -      -      - AsynchronousAssetLoader
    -      -      - BitmapFontLoader
    -      -      - CubemapLoader
    -      -      - ModelLoader
    -      -      - MusicLoader
    -      -      - ParticleEffectLoader
    -      -      - PixmapLoader
    -      -      - ShaderProgramLoader
    -      -      - SkinLoader
    -      -      - SoundLoader
    -      -      - SynchronousAssetLoader
    -      -      - TextureAtlasLoader
    -      -      - TextureLoader

ASSETS/LOADERS/RESOLVERS
------------------------

    CODE   DOCUMENT
    ----   --------
    -      -      - AbsoluteFileHandleResolver
    -      -      - ClasspathFileHandleResolver
    -      -      - ExternalFileHandleResolver
    -      -      - IFileHandleResolver
    -      -      - InternalFileHandleResolver
    -      -      - LocalFileHandleResolver
    -      -      - PrefixFileHandleResolver
    -      -      - ResolutionFileResolver

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

- **I'm currently considering ditching Lugh.Audio in favour of NAudio.**
- **Decision to be made asap.**

AUDIO
-----

    CODE   DOCUMENT
    ----   --------
    -      -      - IAudio
    -      -      - IAudioDevice
    -      -      - IAudioDeviceAsync
    -      -      - IAudioRecorder
    -      -      - IMusic
    -      -      - ISound

AUDIO/MAPONUS ( MAPONUS is the God of Music )
---------------------------------------------

    CODE   DOCUMENT
    ----   --------
    -      -      - Buffer16BitSterso
    -      -      - MP3SharpException
    -      -      - MP3Stream
    -      -      - SoundFormat

AUDIO/MAPONUS/DECODING
-----------------------

    CODE   DOCUMENT
    ----   --------
    -      -      - AudioBase
    -      -      - BitReserve
    -      -      - Bitstream
    -      -      - BitstreamErrors
    -      -      - BitstreamException
    -      -      - CircularByteBuffer
    -      -      - Crc16
    -      -      - Decoder
    -      -      - DecoderParameters
    -      -      - DecoderErrors
    -      -      - DecoderException
    -      -      - Equalizer
    -      -      - Header
    -      -      - Huffman
    -      -      - OutputChannels
    -      -      - PushbackStream
    -      -      - SampleBuffer
    -      -      - SynthesisFilter

AUDIO/MAPONUS/DECODING/DECODERS
-----------------------

    CODE   DOCUMENT
    ----   --------
    -      -      - ASubband
    -      -      - IFrameDecoder
    -      -      - LayerIDecoder
    -      -      - LayerIIDecoder
    -      -      - LayerIIIDecoder

AUDIO/MAPONUS/DECODING/DECODERS/LAYERI
---------------------------------------

    CODE   DOCUMENT
    ----   --------
    -      -      - SubbandLayer1
    -      -      - SubbandLayer1IntensityStereo
    -      -      - SubbandLayer1Stereo

AUDIO/MAPONUS/DECODING/DECODERS/LAYERII
----------------------------------------

    CODE   DOCUMENT
    ----   --------
    -      -      - SubbandLayer2
    -      -      - SubbandLayer2IntensityStereo
    -      -      - SubbandLayer2Stereo

AUDIO/MAPONUS/DECODING/DECODERS/LAYERIII
-----------------------------------------

    CODE   DOCUMENT
    ----   --------
    -      -      - ChannelData
    -      -      - GranuleInfo
    -      -      - Layer3SideInfo
    -      -      - SBI
    -      -      - ScaleFactorData
    -      -      - ScaleFactorTable

AUDIO/MAPONUS/IO
-----------------

    CODE   DOCUMENT
    ----   --------
    -      -      - RandomAccessFileStream
    -      -      - RiffFile
    -      -      - WaveFile
    -      -      - WaveFileBuffer

AUDIO/MAPONUS/SUPPORT
----------------------

    CODE   DOCUMENT
    ----   --------
    -      -      - SupportClass

AUDIO/OPENAL
------------

    CODE   DOCUMENT
    ----   --------
    -      - N/A  - AL
    -      - N/A  - ALC

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

CORE
----

    CODE   DOCUMENT
    ----   --------
    -      -      - ApplicationAdapter
    -      -      - ApplicationConfiguration
    -      -      - Engine
    -      -      - Game
    -      -      - GameTime
    -      -      - IApplication
    -      -      - IApplicationListener
    -      -      - ILifecycleListener
    -      -      - IPreferences
    - DONE - DONE - IScreen
    -      -      - LibraryVersion
    -      -      - Platform
    -      -      - ScreenAdapter

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

FILES
-----

    CODE   DOCUMENT
    ----   --------
    -      -      - Files
    -      -      - IFilenameFilter
    -      -      - IFiles
    -      -      - InputStream
    -      -      - IOUtils

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

GRAPHICS
--------

    CODE   DOCUMENT
    ----   --------
    -      -      - AbstractGraphics
    -      -      - BMPFormatStructs
    -      -      - Color
    -      -      - Colors
    -      -      - Cubemap
    -      -      - FrameBufferConfig
    -      -      - GLTexture
    -      -      - GLTextureArray
    -      -      - GraphicsBackend
    -      -      - GraphicsDevice
    -      -      - GraphicsEnums
    -      -      - GStructs
    -      -      - ICubemapData
    -      -      - ICursor
    -      -      - IGraphicsDevice
    -      -      - IGraphicsDevice.DisplayMode
    -      -      - IGraphicsDevice.Monitor
    -      -      - ITextureArrayData
    -      -      - ITextureData
    -      -      - ManagedTextureHandle
    -      -      - Mesh
    -      -      - Pixmap
    -      -      - PixmapFormat
    -      -      - PixmapIO
    -      -      - ShaderLoader
    -      -      - Texture
    -      -      - TextureDataFactory
    -      -      - TextureRegion
    -      -      - VertexAttribute
    -      -      - VertexAttributes

GRAPHICS/ATLASES
----------------

    CODE   DOCUMENT
    ----   --------
    -      -      - AtlasRegion
    -      -      - AtlasSprite
    -      -      - TextureAtlas
    -      -      - TextureAtlasData
    -      -      - TextureAtlasDataExtensions

GRAPHICS/CAMERAS
----------------

    CODE   DOCUMENT
    ----   --------
    -      -      - Camera
    -      -      - IGameCamera
    -      -      - OrthographicCamera
    -      -      - OrthographicGameCamera
    -      -      - PerspectiveCamera
    -      -      - Shake

GRAPHICS/FRAMEBUFFERS
---------------------

    CODE   DOCUMENT
    ----   --------
    -      -      - FloatFrameBuffer
    -      -      - FloatFrameBufferBuilder
    -      -      - FrameBuffer
    -      -      - FrameBufferBuilder
    -      -      - FrameBufferCubemap
    -      -      - FrameBufferCubemapBuilder
    -      -      - FrameBufferRenderBufferAttachmentSpec
    -      -      - FrameBufferTextureAttachmentSpec
    -      -      - GLFrameBuffer
    -      -      - GLFrameBufferBuilder

GRAPHICS/G2D
------------

    CODE   DOCUMENT
    ----   --------
    -      -      - Animation
    -      -      - CpuSpriteBatch
    -      -      - Gdx2DPixmap
    -      -      - Gdx2DPixmapExtensions
    -      -      - Gdx2DPixmapUtils
    -      -      - IBatch
    -      -      - IPolygonBatch
    -      -      - NinePatch
    -      -      - ParticleEffect
    -      -      - ParticleEffectPool
    -      -      - ParticleEmitter
    -      -      - PixmapPacker
    -      -      - PixmapPackerIO
    -      -      - PolygonRegion
    -      -      - PolygonRegionLoader
    -      -      - PolygonSprite
    -      -      - PolygonSpriteBatch
    -      -      - RepeatablePolygonSprite
    -      -      - Sprite
    -      -      - SpriteBatch
    -      -      - SpriteCache

GRAPHICS/G3D
------------

    See Documents/TODO_G3D.MD

GRAPHICS/OPENGL
---------------

    Change uint parameters in Bindings methods to int, and do conversion to uint
    inside those methods when necessary. This will remove the amount of casting to
    uint in the code.

    CODE   DOCUMENT
    ----   --------
    -      -      - GLBindings
    -      -      - GLBindingsHelpers
    -      -      - GLBindingsStructs
    -      -      - GLConsts
    -      -      - GLFormatChooser
    -      -      - GLFunctionDelegates
    -      -      - GLFunctionsLoader
    -      -      - GLImage
    -      -      - GLUtils
    -      -      - IGL
    -      -      - IGLBindings
    -      -      - IGLBindingsExtra
    -      -      - IGLBindingsHelpers

GRAPHICS/OPENGL/ENUMS
---------------------

    CODE   DOCUMENT
    ----   --------
    -      -      - BlendMode
    -      -      - BufferEnums
    -      -      - ClearBufferMask
    -      -      - CompareFunction
    -      -      - CullFaceMode
    -      -      - DataType
    -      -      - DebugEnums
    -      -      - DrawElementsType
    -      -      - EnableCap
    -      -      - FrameBufferEnums
    -      -      - GetPName
    -      -      - LogicOp
    -      -      - MatrixMode
    -      -      - PixelEnums
    -      -      - PolygonMode
    -      -      - PrimitiveType
    -      -      - ProgramParameter
    -      -      - QueryTarget
    -      -      - ShaderEnums
    -      -      - StencilEnums
    -      -      - StringName
    -      -      - TextureFilterMode
    -      -      - TextureFormat
    -      -      - TextureLimits
    -      -      - TextureParameterName
    -      -      - TextureTarget
    -      -      - TextureUnit
    -      -      - TextureWrapMode
    -      -      - VertexAttribParameter
    -      -      - VertexAttribType

GRAPHICS/OPENGL/GLSL
--------------------

    CODE   DOCUMENT
    ----   --------
    -      -      - ColorTest.glsl.frag
    -      -      - ColorTest.glsl.vert
    -      -      - Default.glsl.frag
    -      -      - Default.glsl.vert
    -      -      - Quad.glsl.frag
    -      -      - Quad.glsl.vert

GRAPHICS/OPENGL/NEWBINDINGS <= Merge into GRAPHICS/OPENGL
---------------------------

    CODE   DOCUMENT
    ----   --------
    -      -      - BufferObjectBindings
    -      -      - ContextBindings
    -      -      - DebugBindings
    -      -      - DebugSeverity
    -      -      - DrawBindings
    -      -      - ErrorBindings
    -      -      - FrameBufferBindings
    -      -      - ProgramBindings
    -      -      - QueryBindings
    -      -      - RenderBufferBindings
    -      -      - ShaderBindings
    -      -      - StateBindings
    -      -      - StencilBindings
    -      -      - TextureBindings
    -      -      - TextureSamplerBindings
    -      -      - TransformBindings
    -      -      - TransformFeedbackBindings
    -      -      - UniformBindings
    -      -      - VertexArrayBindings
    -      -      - VertexAttribBindings

GRAPHICS/TEXT
-------------

    CODE   DOCUMENT
    ----   --------
    -      -      - BitmapFont
    -      -      - BitmapFontCache
    -      -      - CharacterUtils
    -      -      - DistanceFieldFont
    -      -      - FontUtils
    -      -      - GlyphLayout
    -      -      - RegexUtils
    -      -      - Subset
    -      -      - UnicodeBlock

GRAPHICS/TEXT/FREETYPE
----------------------

    CODE   DOCUMENT
    ----   --------
    -      -      - FreeType
    -      -      - FreeTypeConstants
    -      -      - FreeTypeFontGenerator
    -      -      - FreeTypeFontGeneratorLoader
    -      -      - FreeTypeFontLoader

GRAPHICS/UTILS
--------------

    CODE   DOCUMENT
    ----   --------
    -      -      - ETC1
    -      -      - ETC1TextureData
    -      -      - FacedCubemapData
    -      -      - FileTextureArrayData
    -      -      - FileTextureData
    -      -      - FloatTextureData
    -      -      - GLOnlyTextureData
    -      -      - GLVersion
    -      -      - HdpiMode
    -      -      - HdpiUtils
    -      -      - IIndexData
    -      -      - IInstanceData
    -      -      - IndexArray
    -      -      - IndexBufferObject
    -      -      - IndexBufferObjectSubData
    -      -      - InstanceBufferObject
    -      -      - InstanceBufferObjectSubData
    -      -      - IVertexData
    -      -      - KTXTTextureData
    -      -      - MipMapGenerator
    -      -      - MipMapTextureData
    -      -      - PixmapTextureData
    -      -      - PNGDecoder
    -      -      - ShaderProgram
    -      -      - ShapeRenderer
    -      -      - TextureUtils
    -      -      - Vertex
    -      -      - VertexArray
    -      -      - VertexBufferObject
    -      -      - VertexBufferObjectSubData
    -      -      - VertexBufferObjectWithVAO
    -      -      - VertexConstants

GRAPHICS/VIEWPORT
-----------------

    CODE   DOCUMENT
    ----   --------
    -      -      - ExtendedViewport
    -      -      - FillViewport
    -      -      - FitViewport
    -      -      - ScalingViewport
    -      -      - ScreenViewport
    -      -      - StretchViewport
    -      -      - Viewport

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

INPUT
-----

    -      -      - AbstractInput
    -      -      - GestureDetector
    -      -      - IInput
    -      -      - IInputProcessor
    -      -      - InputAdapter
    -      -      - InputEventQueue
    -      -      - InputMultiplexer
    -      -      - InputUtils
    -      -      - RemoteInput
    -      -      - RemoteSender

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

MAPS
----

    CODE   DOCUMENT
    ----   --------
    -      -      - IImageResolver
    -      -      - IMapRenderer
    -      -      - Map
    -      -      - MapGroupLayer
    -      -      - MapLayer
    -      -      - MapLayers
    -      -      - MapObject
    -      -      - MapObjects
    -      -      - MapProperties

MAPS/OBJECTS
------------

    CODE   DOCUMENT
    ----   --------
    -      -      - CircleMapObject
    -      -      - EllipseMapObject
    -      -      - PolygonMapObject
    -      -      - PolylineMapObject
    -      -      - RectangleMapObject
    -      -      - TextureMapObject

MAPS/TILED
----------

    CODE   DOCUMENT
    ----   --------
    -      -      - ITiledMapTile
    -      -      - TiledMap
    -      -      - TiledMapImageLayer
    -      -      - TiledMapTileLayer
    -      -      - TiledMapTileSet
    -      -      - TiledMapTileSets

MAPS/TILED/LOADERS
------------------

    CODE   DOCUMENT
    ----   --------
    -      -      - AtlasTmxMapLoader
    -      -      - BaseTmxMapLoader
    -      -      - TmxMapLoader

MAPS/TILED/OBJECTS
------------------

    CODE   DOCUMENT
    ----   --------
    -      -      - TiledMapTileMapObject

MAPS/TILED/RENDERERS
--------------------

    CODE   DOCUMENT
    ----   --------
    -      -      - BatchTiledMapRenderer
    -      -      - HexagonalTiledMapRenderer
    -      -      - IsometricStaggeredTiledMapRenderer
    -      -      - IsometricTiledMapRenderer
    -      -      - ITiledMapRenderer
    -      -      - OrthoCachedTiledMapRenderer
    -      -      - OrthogonalTiledMapRenderer

MAPS/TILED/TILES
----------------

    CODE   DOCUMENT
    ----   --------
    -      -      - AnimatedTileMapTile
    -      -      - StaticTiledMapTile

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

MATHS
-----

    CODE   DOCUMENT
    ----   --------
    -      -      - Affine2
    -      -      - Bezier
    -      -      - Bresenham2
    -      -      - BSpline
    -      -      - CatmullRomSpline
    -      -      - Circle
    -      -      - ConvexHull
    -      -      - CumulativeDistribution
    -      -      - DelaunayTriangulator
    -      -      - EarClippingTriangulator
    -      -      - Ellipse
    -      -      - FloatCounter
    -      -      - FloatMatrixStructs
    -      -      - Frustrum
    -      -      - GeometryUtils
    -      -      - GridPoint2
    -      -      - GridPoint3
    -      -      - Interpolation
    -      -      - Intersector
    -      -      - IntToByte
    -      -      - IPath
    -      -      - IShape2D
    -      -      - IVector
    -      -      - MathUtils
    -      -      - Matrix3x3
    -      -      - Matrix4x4
    -      -      - Number
    -      -      - NumberUtils
    -      -      - Plane
    -      -      - Point2D
    -      -      - Polygon
    -      -      - Polyline
    -      -      - Quaternion
    -      -      - RandomXS128
    -      -      - Rectangle
    -      -      - SimpleVectors
    -      -      - Vector2
    -      -      - Vector3
    -      -      - Vector4
    -      -      - WindowedMean

MATH/COLLISION
--------------

    CODE   DOCUMENT
    ----   --------
    -      -      - Area2D
    -      -      - BoundingBox
    -      -      - Ray
    -      -      - Segment
    -      -      - Sphere

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

NETWORK
-------

    CODE   DOCUMENT
    ----   --------
    -      -      - HttpParameterUtils
    -      -      - HttpRequestBuilder
    -      -      - HttpStatus
    -      -      - IHttpRequestHeader
    -      -      - IHttpResponseHeader
    -      -      - INet
    -      -      - IServerSocket
    -      -      - ISocket
    -      -      - NetJavaImpl
    -      -      - NetJavaServerSocketImpl
    -      -      - NetJavaSocketImpl
    -      -      - ServerSocketHints
    -      -      - SocketHints

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

SCENES/SCENE2D
--------------

    CODE   DOCUMENT
    ----   --------
    -      -      - Action
    -      -      - Actor
    -      -      - Event
    -      -      - Group
    -      -      - IActor
    -      -      - InputEvent
    -      -      - Stage
    -      -      - Touchable

SCENES/SCENE2D/ACTIONS
----------------------

    CODE   DOCUMENT
    ----   --------
    -      -      - Actions
    -      -      - AddAction
    -      -      - AddListenerAction
    -      -      - AfterAction
    -      -      - AlphaAction
    -      -      - ColorAction
    -      -      - CountdownEventAction
    -      -      - DelayAction
    -      -      - DelegateAction
    -      -      - EventAction
    -      -      - FloatAction
    -      -      - IntAction
    -      -      - LayoutAction
    -      -      - MoveByAction
    -      -      - MoveToAction
    -      -      - ParallelAction
    -      -      - RelativeTemporalAction
    -      -      - RemoveAction
    -      -      - RemoveActorAction
    -      -      - RemoveListenerAction
    -      -      - RepeatAction
    -      -      - RotateByAction
    -      -      - RotateToAction
    -      -      - RunnableAction
    -      -      - ScaleByAction
    -      -      - ScaleToAction
    -      -      - SequenceAction
    -      -      - SizeByAction
    -      -      - SizeToAction
    -      -      - TemporalAction
    -      -      - TimeScaleAction
    -      -      - TouchableAction
    -      -      - VisibleAction

SCENES/SCENE2D/LISTENERS
------------------------

    CODE   DOCUMENT
    ----   --------
    -      -      - ActorGestureListener
    -      -      - ChangeListener
    -      -      - ClickListener
    -      -      - DragListener
    -      -      - DragScrollListener
    -      -      - FocusListener
    -      -      - IEventListener
    -      -      - InputListener


SCENES/SCENE2D/UI
-----------------

    TODO: I don't like the way Cell and Value classes are implemented.
          They seem confusing and are candidates for a rewrite.

    CODE   DOCUMENT
    ----   --------
    -      -      - Button
    -      -      - ButtonGroup
    -      -      - Cell
    -      -      - CheckBox
    -      -      - Container
    -      -      - Dialog
    -      -      - DialogChangeListener
    -      -      - DialogFocusListener
    -      -      - DialogInputListener
    -      -      - HorizontalGroup
    -      -      - Image
    -      -      - ImageButton
    -      -      - ImageTextButton
    -      -      - IOnScreenKeyboard
    -      -      - Label
    -      -      - ListBox
    -      -      - ParticleEffectActor
    -      -      - ProgressBar
    -      -      - ScrollPane
    -      -      - ScrollPaneListeners
    -      -      - SelectBox
    -      -      - Skin
    -      -      - Slider
    -      -      - SplitPane
    -      -      - Stack
    -      -      - Table
    -      -      - TextArea
    -      -      - TextButton
    -      -      - TextField
    -      -      - TextTooltip
    -      -      - Tooltip
    -      -      - TooltipManager
    -      -      - Touchpad
    -      -      - Tree
    -      -      - Value
    -      -      - VerticalGroup
    -      -      - Widget
    -      -      - WidgetGroup
    -      -      - Window

SCENES/SCENE2D/UTILS
--------------------

    CODE   DOCUMENT
    ----   --------
    -      -      - ArraySelection
    -      -      - BaseDrawable
    -      -      - DragAndDrop
    -      -      - ICullable
    -      -      - IDisableable
    -      -      - IDrawable
    -      -      - ILayout
    -      -      - ITransformDrawable
    -      -      - NinePatchDrawable
    -      -      - ScissorStack
    -      -      - Selection
    -      -      - SpriteDrawable
    -      -      - TextureRegionDrawable
    -      -      - TiledDrawable

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

UTILS
-----

    - Move Utils/Collections out of Utils and into somewhere more appropriate.

    CODE   DOCUMENT
    ----   --------
    -      -      - Alignment
    -      -      - BaseClassFactory
    -      -      - BinaryHeap
    -      -      - Bits
    -      -      - Buffer<T>
    -      -      - BufferUtils
    -      -      - ByteOrder
    -      -      - BytePointerToString
    -      -      - CaseInsensitiveEnumArrayConverterFactory
    -      -      - ComparableTimSort
    -      -      - Constants
    -      -      - DataInput
    -      -      - DataOutput
    -      -      - DataUtils
    -      -      - FPSLogger
    -      -      - GCSuppressor
    -      -      - GdxNativesLoader
    -      -      - HashHelpers
    -      -      - IClearablePool
    -      -      - IClipboard
    -      -      - ICloseable
    -      -      - IDrawable
    -      -      - IManaged
    -      -      - IReadable
    -      -      - IResetable
    -      -      - IRunnable
    -      -      - Logger
    -      -      - LughTestAdapter
    -      -      - PerformanceCounter
    -      -      - PerformanceCounters
    -      -      - PhysicsUtils
    -      -      - PropertiesUtils
    -      -      - QuadTreeFloat
    -      -      - QuickSelect
    -      -      - Scaling
    -      -      - ScreenUtils
    -      -      - Selector
    -      -      - SingletonBase<T>
    -      -      - SortUtils
    -      -      - StringUtils
    -      -      - SystemArrayUtils
    -      -      - Timer
    -      -      - TimeUtils
    -      -      - TimSort

UTILS/COLLECTIONS
-----------------

    CODE   DOCUMENT
    ----   --------
    -      -      - ArrayList<T>
    -      -      - ByteArray
    -      -      - DelayedRemovalList
    -      -      - DictionaryExtensions
    -      -      - IdentityMap< K, V >
    -      -      - IPredicate
    -      -      - ListExtensions
    -      -      - ObjectMap< K, V >
    -      -      - OrderedMap<K, V>
    -      -      - PredicateIterable
    -      -      - PredicateIterator
    -      -      - SnapshotArrayList<T>

UTILS/EXCEPTIONS
----------------

    CODE   DOCUMENT
    ----   --------
    -      -      - AssetNotLoadedException
    -      -      - BufferOverflowException
    -      -      - BufferUnderflowException
    -      -      - Guard
    -      -      - GdxRuntimeException
    -      -      - NumberFormatException
    -      -      - ReadOnlyBufferException
    -      -      - SerializationException
    -      -      - SpriteBatchException

UTILS/POOLING
-------------

    CODE   DOCUMENT
    ----   --------
    -      -      - FlushablePool
    -      -      - IPoolable
    -      -      - Pool
    -      -      - PooledLinkedList
    -      -      - Pools

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    CODE   DOCUMENT
    ----   --------
    -      -      - 

