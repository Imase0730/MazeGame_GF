//--------------------------------------------------------------------------------------
// File: GamePlayScene.cpp
//
//--------------------------------------------------------------------------------------
#include "GamePlayScene.h"
#include "Game/Game.h"
#include "Game/Screen.h"
#include "Game/KeyRepeat.h"

// コンストラクタ
GamePlayScene::GamePlayScene(Game* pGame)
	: m_pGame{ pGame }
	, m_tileMap{}
	, m_player{}
	, m_ghTileset{ -1 }
	, m_ghPlayer{ -1 }
	, m_gameState{ GameState::GamePlay }
	, m_blink{ 60 }
{

}

// デストラクタ
GamePlayScene::~GamePlayScene()
{
}

// 初期化処理
void GamePlayScene::Initialize()
{
	// タイルセットの絵を読み込む
	m_ghTileset = LoadGraph(L"Resources/Textures/tileset.png");

	// プレイヤーの絵を読み込む
	m_ghPlayer = LoadGraph(L"Resources/Textures/player.png");

	// マップデータを読み込む
	m_tileMap.LoadMapData(L"Resources/MapData/mapData.csv");

	// プレイヤーの位置を設定する
	m_player.SetPosition(m_tileMap.GetPlayerPosition());
}

// 更新処理
void GamePlayScene::Update(int keyCondition, int keyTrigger)
{
	// 点滅の更新処理
	m_blink.Update();

	// キーリピートを取得
	int keyRepeat = KeyRepeat::GetKey(keyCondition);

	// プレイヤーの更新
	m_player.Update(keyRepeat, &m_tileMap);

	// プレイヤーの位置に宝箱がある？
	if (m_tileMap.GetTile(m_player.GetPosition()) == Tile::Type::Chest)
	{
		// 宝箱を床に変える
		m_tileMap.SetTile(m_player.GetPosition(), Tile::Type::Floor);
	}

	// ゲームクリア？（宝箱の数が０）
	if (IsGameClear())
	{
		// GameClear
		m_gameState = GameState::GameClear;
	}

	// ゲームオーバー？（プレイヤーが移動できない）
	else if (IsGameOver())
	{
		// GameOver
		m_gameState = GameState::GameOver;
	}

}

// 描画処理
void GamePlayScene::Render()
{
	// タイルマップを描画する
	m_tileMap.Render(m_ghTileset);

	//// 点滅処理
	//if (m_blink.IsBlinkOn())
	//{
	//	// プレイヤーの描画をする
	//	m_player.Render(m_ghPlayer);
	//}

	int col = 100 + static_cast<int>(155 * m_blink.GetBlinkRate());
	SetDrawBright(col, col, col);

	// プレイヤーの描画をする
	m_player.Render(m_ghPlayer);

	SetDrawBright(255, 255, 255);

	// フォントのサイズを設定する
	SetFontSize(FONT_SIZE);

	// 文字表示する
	switch (m_gameState)
	{
	case GameState::GameOver:
		DrawFormatString(Screen::GAME_WIDTH / 2 - GetDrawStringWidth(GAMEOVER, static_cast<int>(wcslen(GAMEOVER))) / 2
			, Screen::GAME_HEIGHT / 2 - FONT_SIZE / 2
			, GetColor(255, 255, 255), GAMEOVER);
		break;
	case GameState::GameClear:
		DrawFormatString(Screen::GAME_WIDTH / 2 - GetDrawStringWidth(GAMECLEAR, static_cast<int>(wcslen(GAMECLEAR))) / 2
			, Screen::GAME_HEIGHT / 2 - FONT_SIZE / 2
			, GetColor(255, 255, 255), GAMECLEAR);
		break;
	default:
		break;
	}

	// フォントのサイズを元に戻す
	SetFontSize(20);

	DrawFormatString(10, 30, GetColor(255, 255, 255), L"GamePlayシーン");
}

// 終了処理
void GamePlayScene::Finalize()
{
	// 読み込んだ絵を解放する
	DeleteGraph(m_ghTileset);
	DeleteGraph(m_ghPlayer);
}

// ゲームクリアか調べる関数
bool GamePlayScene::IsGameClear()
{
	// 宝箱の数が０なら
	if (m_tileMap.GetChestCount() == 0) return true;

	return false;
}

// ゲームオーバーか調べる関数
bool GamePlayScene::IsGameOver()
{
	int x = m_player.GetPosition().x;
	int y = m_player.GetPosition().y;

	// 上下左右移動できるか調べる
	if (m_player.IsMovable(&m_tileMap, x, y - 1)) return false;
	if (m_player.IsMovable(&m_tileMap, x, y + 1)) return false;
	if (m_player.IsMovable(&m_tileMap, x - 1, y)) return false;
	if (m_player.IsMovable(&m_tileMap, x + 1, y)) return false;

	// 全ての方向に移動できなかったのでゲームオーバー
	return true;
}

