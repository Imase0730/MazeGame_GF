#include "Player.h"
#include "Tile.h"

// �R���X�g���N�^
Player::Player()
	: m_position{ 0, 0 }
{
}

// �X�V����
void Player::Update(int keyTrigger)
{
	// ��L�[�����ꂽ
	if (keyTrigger & PAD_INPUT_UP)
	{
		m_position.y--;
	}

	// ���L�[�����ꂽ
	if (keyTrigger & PAD_INPUT_DOWN)
	{
		m_position.y++;
	}

	// ���L�[�����ꂽ
	if (keyTrigger & PAD_INPUT_LEFT)
	{
		m_position.x--;
	}

	// �E�L�[�����ꂽ
	if (keyTrigger & PAD_INPUT_RIGHT)
	{
		m_position.x++;
	}
}

// �`�揈��
void Player::Render(int ghPlayer)
{
	// �v���C���[�̕`��
	DrawGraph(m_position.x * Tile::TILE_SIZE, m_position.y * Tile::TILE_SIZE
		, ghPlayer, TRUE);
}

