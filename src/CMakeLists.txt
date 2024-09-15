# srcディレクトリ内のファイルを追加
add_library(Game Game.cpp tetromino.cpp)
target_link_libraries(Game DxLib)
