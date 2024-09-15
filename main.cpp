#include <DxLib.h>
#include "Game.hpp"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // DXライブラリ初期化処理
    if (DxLib_Init() == -1) {
        return -1;
    }

    Game game;
    game.run();

    DrawFormatString(320, 240, GetColor(255, 255, 255), "Score: %d", game.getScore());

    // キー入力待ち
    WaitKey();

    // DXライブラリ終了処理
    DxLib_End();

    return 0;
}