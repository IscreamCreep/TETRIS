#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "tetromino.hpp"
#include "config.hpp"
#include "tetromino_utils.hpp"

class Game {
public:
    Game();
    void initialiseGame();
    void updateGame();
    void drawBoard();
    void spawnTetromino();
    void lockTetromino();
    void clearLines();
    bool isGameOver() const;

private:
    std::vector<std::vector<int>> board;
    Tetromino* currentTetromino;
    int score;
    int level;
    bool gameOver;

    void initializeBoard();
    bool isLineFull(int y) const;
    void removeLine(int y);
};

#endif // GAME_HPP