#pragma once

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
	void Update(int keyTrigger);

	// �`�揈��
	void Render(int ghPlayer);

};

