cmake_minimum_required(VERSION 3.10)
project(Tetris)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include と dxlib ディレクトリをインクルードパスに追加
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/dxlib)

# dxlibフォルダ内のライブラリパスを設定
link_directories(${PROJECT_SOURCE_DIR}/dxlib)

# 実行ファイルを生成
add_executable(Tetris main.cpp src/Game.cpp)

# DXlibをリンク
target_link_libraries(Tetris 
                        DxLib
                        DxUseCLib
                        DxDrawFunc
                        jpeg
                        png
                        zlib
                        tiff
                        theora_static
                        vorbis_static
                        vorbisfile_static
                        ogg_static
                        bulletdynamics
                        bulletcollision
                        bulletmath
                        opusfile
                        opus
                        silk_common
                        celt)
