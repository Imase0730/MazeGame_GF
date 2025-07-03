#include "Blink.h"

// �R���X�g���N�^
Blink::Blink(int intervalFrame)
	: m_intervalFrame{ intervalFrame }
	, m_isBlinkOn{ false }
	, m_timer{ 0 }
{
}

// �X�V����
void Blink::Update()
{
	// �^�C�}�[�����Z����
	m_timer++;

	// �_�ŊԊu�𒴂��Ă�����
	if (m_timer > m_intervalFrame)
	{
		// �^�C�}�[�����Z�b�g����
		m_timer = 0;

		// �_��
		if (m_isBlinkOn)
		{
			m_isBlinkOn = false;
		}
		else
		{
			m_isBlinkOn = true;
		}
	}
}

// �_�ł̊������擾����֐�
float Blink::GetBlinkRate() const
{
	// 0.0 �� 1.0f �� 0.0f
	if (m_timer <= m_intervalFrame / 2)
	{
		return m_timer / (m_intervalFrame / 2.0f);
	}
	return (m_intervalFrame - m_timer) / (m_intervalFrame / 2.0f);
}
