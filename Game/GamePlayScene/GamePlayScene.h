//--------------------------------------------------------------------------------------
// File: GamePlayScene.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "TileMap.h"
#include "Player.h"
#include "Game/Blink.h"

// クラスの前方宣言
class Game;

// ゲームプレイシーン
class GamePlayScene
{
	// 列挙型の宣言 -------------------------------------------------
private:

	// ゲームの状態
	enum class GameState
	{
		GamePlay,		// ゲームプレイ中
		GameOver,		// ゲームオーバー
		GameClear,		// ゲームクリア
	};

	// クラス定数の宣言 -------------------------------------------------
public:

	// フォントサイズ
	static constexpr int FONT_SIZE = 50;

	// ゲームオーバーの文字列
	static constexpr wchar_t GAMEOVER[] = L"Game Over";

	// ゲームクリアの文字列
	static constexpr wchar_t GAMECLEAR[] = L"Game Clear";

	// データメンバの宣言 -----------------------------------------------
private:

	// このシーンを含むゲームオブジェクトへのポインタ
	Game* m_pGame;

	// タイルマップ
	TileMap m_tileMap;

	// プレイヤー
	Player m_player;

	// タイルセットの絵のグラフィックハンドル
	int m_ghTileset;

	// プレイヤーの絵のグラフィックハンドル
	int m_ghPlayer;

	// ゲームの状態
	GameState m_gameState;

	// 点滅オブジェクト
	Blink m_blink;

	// メンバ関数の宣言 -------------------------------------------------
public:

	// コンストラクタ
	GamePlayScene(Game* pGame);

	// デストラクタ
	~GamePlayScene();

	// 初期化処理
	void Initialize();

	// 更新処理
	void Update(int keyCondition, int keyTrigger);

	// 描画処理
	void Render();

	// 終了処理
	void Finalize();

private:

	// ゲームクリアか調べる関数
	bool IsGameClear();

	// ゲームオーバーか調べる関数
	bool IsGameOver();

};
