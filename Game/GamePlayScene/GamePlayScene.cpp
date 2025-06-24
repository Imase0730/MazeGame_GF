//--------------------------------------------------------------------------------------
// File: GamePlayScene.cpp
//
//--------------------------------------------------------------------------------------
#include "GamePlayScene.h"
#include "Game/Game.h"

// コンストラクタ
GamePlayScene::GamePlayScene(Game* pGame)
	: m_pGame{ pGame }
	, m_tileMap{}
	, m_ghTileset{ -1 }
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

	// マップデータを読み込む
	m_tileMap.LoadMapData(L"Resources/MapData/mapData.csv");
}

// 更新処理
void GamePlayScene::Update(int keyCondition, int keyTrigger)
{

}

// 描画処理
void GamePlayScene::Render()
{
	// タイルマップを描画する
	m_tileMap.Render(m_ghTileset);

	DrawFormatString(10, 30, GetColor(255, 255, 255), L"GamePlayシーン");
}

// 終了処理
void GamePlayScene::Finalize()
{
	// 読み込んだ絵を解放する
	DeleteGraph(m_ghTileset);
}

