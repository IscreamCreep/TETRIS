#include "Game.hpp"
#include <DxLib.h>

Game::Game() : score(0) {}

void Game::run() {
    // ここにゲームのメインループを実装します
    // 例: スコアを増やす
    score += 10;
}

int Game::getScore() const {
    return score;
}