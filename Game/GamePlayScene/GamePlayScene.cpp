//--------------------------------------------------------------------------------------
// File: GamePlayScene.cpp
//
//--------------------------------------------------------------------------------------
#include "GamePlayScene.h"
#include "Game/Game.h"

// �R���X�g���N�^
GamePlayScene::GamePlayScene(Game* pGame)
	: m_pGame{ pGame }
	, m_tileMap{}
	, m_player{}
	, m_ghTileset{ -1 }
	, m_ghPlayer{ -1 }
{

}

// �f�X�g���N�^
GamePlayScene::~GamePlayScene()
{
}

// ����������
void GamePlayScene::Initialize()
{
	// �^�C���Z�b�g�̊G��ǂݍ���
	m_ghTileset = LoadGraph(L"Resources/Textures/tileset.png");

	// �v���C���[�̊G��ǂݍ���
	m_ghPlayer = LoadGraph(L"Resources/Textures/player.png");

	// �}�b�v�f�[�^��ǂݍ���
	m_tileMap.LoadMapData(L"Resources/MapData/mapData.csv");
}

// �X�V����
void GamePlayScene::Update(int keyCondition, int keyTrigger)
{
	// �v���C���[�̍X�V
	m_player.Update(keyTrigger);
}

// �`�揈��
void GamePlayScene::Render()
{
	// �^�C���}�b�v��`�悷��
	m_tileMap.Render(m_ghTileset);

	// �v���C���[�̕`�������
	m_player.Render(m_ghPlayer);

	DrawFormatString(10, 30, GetColor(255, 255, 255), L"GamePlay�V�[��");
}

// �I������
void GamePlayScene::Finalize()
{
	// �ǂݍ��񂾊G���������
	DeleteGraph(m_ghTileset);
	DeleteGraph(m_ghPlayer);
}

