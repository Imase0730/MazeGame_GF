//--------------------------------------------------------------------------------------
// File: GamePlayScene.cpp
//
//--------------------------------------------------------------------------------------
#include "GamePlayScene.h"
#include "Game/Game.h"

// コンストラクタ
GamePlayScene::GamePlayScene(Game* pGame)
	: m_pGame{ pGame }
{

}

// デストラクタ
GamePlayScene::~GamePlayScene()
{

}

// 初期化処理
void GamePlayScene::Initialize()
{

}

// 更新処理
void GamePlayScene::Update(int keyCondition, int keyTrigger)
{

}

// 描画処理
void GamePlayScene::Render()
{
	DrawFormatString(10, 30, GetColor(255, 255, 255), L"GamePlayシーン");
}

// 終了処理
void GamePlayScene::Finalize()
{

}

