#ifndef TETROMINO_HPP
#define TETROMINO_HPP

#include <vector>
#include "config.hpp"

enum class TetrominoType {
    I, O, T, S, Z, J, L
};

class Tetromino {
public:
    Tetromino(TetrominoType type);
    void rotate();
    void move(int dx, int dy);
    void draw() const;
    bool checkCollision(const std::vector<std::vector<int>>& board) const;

    int getX() const { return x; }
    int getY() const { return y; }
    const std::vector<std::vector<int>>& getShape() const { return shape; }
	TetrominoType getType() const { return type; }
	int GetTetrominoColor() const { return colour; }

private:
    TetrominoType type;
    int x, y;
    std::vector<std::vector<int>> shape;
    unsigned int colour;
};

#endif //TETROMINO_HPP