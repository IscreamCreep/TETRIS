// config.hpp
#ifndef CONFIG_HPP
#define CONFIG_HPP

#include "DxLib.h"

// ゲームボードの設定
constexpr int BOARD_WIDTH = 10;
constexpr int BOARD_HEIGHT = 20;

// ブロックのサイズ（ピクセル）
constexpr int BLOCK_SIZE = 30;

// ゲームのフレームレート
constexpr int FRAME_RATE = 60;

// 初期落下速度（フレーム数）
constexpr int INITIAL_FALL_SPEED = 60;

// レベルアップごとの速度増加（フレーム数の減少）
constexpr int LEVEL_SPEED_INCREASE = 5;

// スコア設定
constexpr int SCORE_SINGLE = 100;
constexpr int SCORE_DOUBLE = 300;
constexpr int SCORE_TRIPLE = 500;
constexpr int SCORE_TETRIS = 800;

// 色の定義
constexpr unsigned int COLOUR_BG = 0x000000;        // 背景色（黒）
constexpr unsigned int COLOUR_GRID = 0x333333;      // グリッド線の色（暗灰色）
constexpr unsigned int COLOUR_I = 0x00FFFF;         // I字ブロックの色（シアン）
constexpr unsigned int COLOUR_O = 0xFFFF00;         // O字ブロックの色（黄色）
constexpr unsigned int COLOUR_T = 0xFF00FF;         // T字ブロックの色（マゼンタ）
constexpr unsigned int COLOUR_S = 0x00FF00;         // S字ブロックの色（緑）
constexpr unsigned int COLOUR_Z = 0xFF0000;         // Z字ブロックの色（赤）
constexpr unsigned int COLOUR_J = 0x0000FF;         // J字ブロックの色（青）
constexpr unsigned int COLOUR_L = 0xFF7F00;         // L字ブロックの色（オレンジ）

// キー設定
constexpr int KEY_LEFT = KEY_INPUT_LEFT;
constexpr int KEY_RIGHT = KEY_INPUT_RIGHT;
constexpr int KEY_DOWN = KEY_INPUT_DOWN;
constexpr int KEY_ROTATE = KEY_INPUT_UP;
constexpr int KEY_HARD_DROP = KEY_INPUT_SPACE;
constexpr int KEY_PAUSE = KEY_INPUT_P;

// ウィンドウサイズ
constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;

#endif // CONFIG_HPP