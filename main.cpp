#include <DxLib.h>
#include "game.hpp"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    int timeLimit = 10000;
	int timeToMove = 1000;

    // DXライブラリ初期化処理
    if (DxLib_Init() == -1) {
        return -1;
    }
    
    Game game;

    game.initialiseGame();

    // 時間計測用変数
	int startTime = GetNowCount();
	int timerToMove = GetNowCount();

    // ゲームループ
    while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE)) 
    {
        if (GetNowCount() - timerToMove > timeToMove) 
        {
            game.updateGame();
            timerToMove = GetNowCount();
        }
        game.drawBoard();
        ScreenFlip();
    }
    
    // 終了処理
    DxLib_End();
    return 0;
}