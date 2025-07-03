#pragma once

// �_�ŃN���X
class Blink
{
	// �����o�ϐ� --------------------------------------------
private:

	// �_�ł̊Ԋu
	int m_intervalFrame;

	// �_�ŁiON/OFF�j
	bool m_isBlinkOn;

	// �^�C�}�[
	int m_timer;

	// �����o�֐� --------------------------------------------
public:

	// �R���X�g���N�^
	Blink(int intervalFrame);

	// �X�V����
	void Update();

	// �_�ŁiON/OFF�j���擾����֐�
	bool IsBlinkOn() const { return m_isBlinkOn; }

	// �_�ł̊������擾����֐�
	float GetBlinkRate() const;

};
