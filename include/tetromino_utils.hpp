#ifndef TETROMINO_UTILS_HPP
#define TETROMINO_UTILS_HPP

#include <DxLib.h>
#include "config.hpp"

// テトロミノの色を取得する関数
inline unsigned int GetTetrominoColour(TetrominoType type) {
    switch (type) {
        case TetrominoType::I: return COLOUR_I;
        case TetrominoType::O: return COLOUR_O;
        case TetrominoType::T: return COLOUR_T;
        case TetrominoType::S: return COLOUR_S;
        case TetrominoType::Z: return COLOUR_Z;
        case TetrominoType::J: return COLOUR_J;
        case TetrominoType::L: return COLOUR_L;
        default: return COLOUR_BG;  // デフォルトの背景色
    }
}

#endif // TETROMINO_UTILS_HPP