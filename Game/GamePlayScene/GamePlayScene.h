//--------------------------------------------------------------------------------------
// File: GamePlayScene.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "TileMap.h"
#include "Player.h"

// �N���X�̑O���錾
class Game;

// �^�C�g���V�[��
class GamePlayScene
{

	// �N���X�萔�̐錾 -------------------------------------------------
public:


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

};
