//--------------------------------------------------------------------------------------
// File: GamePlayScene.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "TileMap.h"
#include "Player.h"
#include "Game/Blink.h"

// �N���X�̑O���錾
class Game;

// �Q�[���v���C�V�[��
class GamePlayScene
{
	// �񋓌^�̐錾 -------------------------------------------------
private:

	// �Q�[���̏��
	enum class GameState
	{
		GamePlay,		// �Q�[���v���C��
		GameOver,		// �Q�[���I�[�o�[
		GameClear,		// �Q�[���N���A
	};

	// �N���X�萔�̐錾 -------------------------------------------------
public:

	// �t�H���g�T�C�Y
	static constexpr int FONT_SIZE = 50;

	// �Q�[���I�[�o�[�̕�����
	static constexpr wchar_t GAMEOVER[] = L"Game Over";

	// �Q�[���N���A�̕�����
	static constexpr wchar_t GAMECLEAR[] = L"Game Clear";

	// �f�[�^�����o�̐錾 -----------------------------------------------
private:

	// ���̃V�[�����܂ރQ�[���I�u�W�F�N�g�ւ̃|�C���^
	Game* m_pGame;

	// �^�C���}�b�v
	TileMap m_tileMap;

	// �v���C���[
	Player m_player;

	// �^�C���Z�b�g�̊G�̃O���t�B�b�N�n���h��
	int m_ghTileset;

	// �v���C���[�̊G�̃O���t�B�b�N�n���h��
	int m_ghPlayer;

	// �Q�[���̏��
	GameState m_gameState;

	// �_�ŃI�u�W�F�N�g
	Blink m_blink;

	// �����o�֐��̐錾 -------------------------------------------------
public:

	// �R���X�g���N�^
	GamePlayScene(Game* pGame);

	// �f�X�g���N�^
	~GamePlayScene();

	// ����������
	void Initialize();

	// �X�V����
	void Update(int keyCondition, int keyTrigger);

	// �`�揈��
	void Render();

	// �I������
	void Finalize();

private:

	// �Q�[���N���A�����ׂ�֐�
	bool IsGameClear();

	// �Q�[���I�[�o�[�����ׂ�֐�
	bool IsGameOver();

};
