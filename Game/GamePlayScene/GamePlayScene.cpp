//--------------------------------------------------------------------------------------
// File: GamePlayScene.cpp
//
//--------------------------------------------------------------------------------------
#include "GamePlayScene.h"
#include "Game/Game.h"
#include "Game/Screen.h"
#include "Game/KeyRepeat.h"

// �R���X�g���N�^
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

	// �v���C���[�̈ʒu��ݒ肷��
	m_player.SetPosition(m_tileMap.GetPlayerPosition());
}

// �X�V����
void GamePlayScene::Update(int keyCondition, int keyTrigger)
{
	// �_�ł̍X�V����
	m_blink.Update();

	// �L�[���s�[�g���擾
	int keyRepeat = KeyRepeat::GetKey(keyCondition);

	// �v���C���[�̍X�V
	m_player.Update(keyRepeat, &m_tileMap);

	// �v���C���[�̈ʒu�ɕ󔠂�����H
	if (m_tileMap.GetTile(m_player.GetPosition()) == Tile::Type::Chest)
	{
		// �󔠂����ɕς���
		m_tileMap.SetTile(m_player.GetPosition(), Tile::Type::Floor);
	}

	// �Q�[���N���A�H�i�󔠂̐����O�j
	if (IsGameClear())
	{
		// GameClear
		m_gameState = GameState::GameClear;
	}

	// �Q�[���I�[�o�[�H�i�v���C���[���ړ��ł��Ȃ��j
	else if (IsGameOver())
	{
		// GameOver
		m_gameState = GameState::GameOver;
	}

}

// �`�揈��
void GamePlayScene::Render()
{
	// �^�C���}�b�v��`�悷��
	m_tileMap.Render(m_ghTileset);

	//// �_�ŏ���
	//if (m_blink.IsBlinkOn())
	//{
	//	// �v���C���[�̕`�������
	//	m_player.Render(m_ghPlayer);
	//}

	int col = 100 + static_cast<int>(155 * m_blink.GetBlinkRate());
	SetDrawBright(col, col, col);

	// �v���C���[�̕`�������
	m_player.Render(m_ghPlayer);

	SetDrawBright(255, 255, 255);

	// �t�H���g�̃T�C�Y��ݒ肷��
	SetFontSize(FONT_SIZE);

	// �����\������
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

	// �t�H���g�̃T�C�Y�����ɖ߂�
	SetFontSize(20);

	DrawFormatString(10, 30, GetColor(255, 255, 255), L"GamePlay�V�[��");
}

// �I������
void GamePlayScene::Finalize()
{
	// �ǂݍ��񂾊G���������
	DeleteGraph(m_ghTileset);
	DeleteGraph(m_ghPlayer);
}

// �Q�[���N���A�����ׂ�֐�
bool GamePlayScene::IsGameClear()
{
	// �󔠂̐����O�Ȃ�
	if (m_tileMap.GetChestCount() == 0) return true;

	return false;
}

// �Q�[���I�[�o�[�����ׂ�֐�
bool GamePlayScene::IsGameOver()
{
	int x = m_player.GetPosition().x;
	int y = m_player.GetPosition().y;

	// �㉺���E�ړ��ł��邩���ׂ�
	if (m_player.IsMovable(&m_tileMap, x, y - 1)) return false;
	if (m_player.IsMovable(&m_tileMap, x, y + 1)) return false;
	if (m_player.IsMovable(&m_tileMap, x - 1, y)) return false;
	if (m_player.IsMovable(&m_tileMap, x + 1, y)) return false;

	// �S�Ă̕����Ɉړ��ł��Ȃ������̂ŃQ�[���I�[�o�[
	return true;
}

