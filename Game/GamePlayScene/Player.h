#pragma once

#include "TileMap.h"

// �v���C���[�N���X
class Player
{
private:

	// �ʒu
	POINT m_position;

public:

	// �R���X�g���N�^
	Player();

	// �X�V����
	void Update(int keyTrigger, TileMap* pTileMap);

	// �`�揈��
	void Render(int ghPlayer);

	// �ʒu��ݒ肷��֐�
	void SetPosition(POINT position) { m_position = position; }

	// �ʒu���擾����֐�
	POINT GetPosition() const { return m_position; }

	// �w�肵���ʒu���ړ��ł��邩���ׂ�֐�
	bool IsMovable(TileMap* pTileMap, int x, int y);

};

