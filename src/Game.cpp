#include "game.hpp"
#include <DxLib.h>
#include "tetromino.hpp"
#include "config.hpp"
#include "tetromino_utils.hpp"

// ボードのデータ
std::vector<std::vector<int>> board(BOARD_HEIGHT, std::vector<int>(BOARD_WIDTH, 0));

Game::Game() : score(0), level(1), gameOver(false), currentTetromino(nullptr) 
{
    initializeBoard();
}

void Game::initializeBoard() 
{
    board = std::vector<std::vector<int>>(BOARD_HEIGHT, std::vector<int>(BOARD_WIDTH, 0));
}

void Game::initialiseGame() 
{
    ChangeWindowMode(TRUE);
	SetGraphMode(BLOCK_SIZE * (BOARD_WIDTH + 2), BLOCK_SIZE * (BOARD_HEIGHT + 2), 32);
	if (DxLib_Init() == -1)
	{
		exit(-1);
	}
    spawnTetromino();
}

void Game::drawBoard() 
{
    // 10x20のボードの背景を描画する
	// 外側は灰色，内側は黒にする．
	DrawBox(0, 0, BLOCK_SIZE * (BOARD_WIDTH + 2), BLOCK_SIZE * (BOARD_HEIGHT + 2), GetColor(192, 192, 192), TRUE);
	DrawBox(BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE * (BOARD_WIDTH + 1), BLOCK_SIZE * (BOARD_HEIGHT + 1), GetColor(0, 0, 0), TRUE);

	// グリッドの描画
	for (int y = 0; y < BOARD_HEIGHT; ++y) {
        for (int x = 0; x < BOARD_WIDTH; ++x) {
            if (board[y][x] != 0) {
                DrawBox(BLOCK_SIZE * (x + 1), BLOCK_SIZE * (y + 1),
                        BLOCK_SIZE * (x + 2), BLOCK_SIZE * (y + 2),
                        GetTetrominoColour(static_cast<TetrominoType>(board[y][x])), TRUE);
            }
        }
    }
    if (currentTetromino) 
    {
        currentTetromino->draw();
    }
}

void Game::spawnTetromino() {
    TetrominoType type = static_cast<TetrominoType>(GetRand(6));
    currentTetromino = new Tetromino(type);
    if (currentTetromino->checkCollision(board)) {
        gameOver = true;
    }
}

void Game::lockTetromino() {
    const auto& shape = currentTetromino->getShape();
    int tetX = currentTetromino->getX();
    int tetY = currentTetromino->getY();
    int colorValue = static_cast<int>(currentTetromino->getType()) + 1;

    for (int y = 0; y < shape.size(); ++y) {
        for (int x = 0; x < shape[y].size(); ++x) {
            if (shape[y][x] && tetY + y >= 0) {
                board[tetY + y][tetX + x] = colorValue;
            }
        }
    }

    delete currentTetromino;
    currentTetromino = nullptr;
}

void Game::clearLines() {
    int linesCleared = 0;
    for (int y = BOARD_HEIGHT - 1; y >= 0; --y) {
        if (isLineFull(y)) {
            removeLine(y);
            ++linesCleared;
            ++y; // 再度同じ行をチェック
        }
    }

    // スコア計算とレベルアップのロジックをここに追加
}

bool Game::isLineFull(int y) const {
    for (int x = 0; x < BOARD_WIDTH; ++x) {
        if (board[y][x] == 0) return false;
    }
    return true;
}

void Game::removeLine(int y) {
    for (int yy = y; yy > 0; --yy) {
        board[yy] = board[yy - 1];
    }
    board[0] = std::vector<int>(BOARD_WIDTH, 0);
}

bool Game::isGameOver() const {
    return gameOver;
}

void Game::updateGame() 
{
    if (gameOver) return;

    if (currentTetromino) {
        currentTetromino->move(0, 1);
        if (currentTetromino->checkCollision(board)) {
            currentTetromino->move(0, -1);
            lockTetromino();
            clearLines();
            spawnTetromino();
        }
    }
}

