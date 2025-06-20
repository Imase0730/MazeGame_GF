//--------------------------------------------------------------------------------------
// File: GamePlayScene.cpp
//
//--------------------------------------------------------------------------------------
#include "GamePlayScene.h"
#include "Game/Game.h"

// �R���X�g���N�^
GamePlayScene::GamePlayScene(Game* pGame)
	: m_pGame{ pGame }
{

}

// �f�X�g���N�^
GamePlayScene::~GamePlayScene()
{

}

// ����������
void GamePlayScene::Initialize()
{

}

// �X�V����
void GamePlayScene::Update(int keyCondition, int keyTrigger)
{

}

// �`�揈��
void GamePlayScene::Render()
{
	DrawFormatString(10, 30, GetColor(255, 255, 255), L"GamePlay�V�[��");
}

// �I������
void GamePlayScene::Finalize()
{

}

