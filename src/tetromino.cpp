// tetromino.cpp
#include "tetromino.hpp"
#include <DxLib.h>

Tetromino::Tetromino(TetrominoType type) : type(type), x(BOARD_WIDTH / 2 - 2), y(0) {
    switch (type) {
        case TetrominoType::I:
            shape = {{1, 1, 1, 1}};
            colour = COLOUR_I;
            break;
        case TetrominoType::O:
            shape = {{1, 1}, 
					{1, 1}};
            colour = COLOUR_O;
            break;
        case TetrominoType::T:
			shape = {{0, 1, 0},
					{1, 1, 1},
					{0, 0, 0}};
			colour = COLOUR_T;
			break;
		case TetrominoType::S:
			shape = {{0, 1, 1},
					{1, 1, 0},
					{0, 0, 0}};
			colour = COLOUR_S;
			break;
		case TetrominoType::Z:
			shape = {{1, 1, 0},
					{0, 1, 1},
					{0, 0, 0}};
			colour = COLOUR_Z;
			break;
		case TetrominoType::J:
			shape = {{1, 0, 0},
					{1, 1, 1},
					{0, 0, 0}};
			colour = COLOUR_J;
			break;
		case TetrominoType::L:
			shape = {{0, 0, 1},
					{1, 1, 1},
					{0, 0, 0}};
			colour = COLOUR_L;
			break;
    }
}

void Tetromino::rotate() {
    // 回転のロジックを実装
}

void Tetromino::move(int dx, int dy) {
    x += dx;
    y += dy;
}

void Tetromino::draw() const {
    for (int i = 0; i < shape.size(); ++i) {
        for (int j = 0; j < shape[i].size(); ++j) {
            if (shape[i][j]) {
                DrawBox((x + j + 1) * BLOCK_SIZE, (y + i + 1) * BLOCK_SIZE,
                        (x + j + 2) * BLOCK_SIZE, (y + i + 2) * BLOCK_SIZE,
                        colour, TRUE);
            }
        }
    }
}

bool Tetromino::checkCollision(const std::vector<std::vector<int>>& board) const {
    // 衝突判定のロジックを実装
    return false;
}