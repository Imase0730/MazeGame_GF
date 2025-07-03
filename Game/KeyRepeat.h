#pragma once

// �ȈՃL�[���s�[�g�N���X
class KeyRepeat
{
private:

	// �L�[���s�[�g�̊Ԋu
	static constexpr int KEY_REPEAT_INTERVEL = 20;

public:

	// �ȈՃL�[���s�[�g�̎擾�֐�
	static int GetKey(int keyCondition)
	{
		// �L�[�������ꂽ�t���[����
		static int elapsedFrame = 0;
		// 1�t���[���O�̃L�[�̏��
		static int oldKey = 0;
		int keyTrigger = ~oldKey & keyCondition;
		int keyRepeat = 0;
		// �L�[�������ꂽ
		if (keyCondition)
		{
			// �L�[�������ꂽ�u�Ԃ̓L�[���𔽉f����
			if (keyTrigger)
			{
				keyRepeat = keyCondition;
				elapsedFrame = 0;
			}
			// �L�[�������ꂽ�t���[���������Z����
			elapsedFrame++;
			if (elapsedFrame >= KEY_REPEAT_INTERVEL)
			{
				keyRepeat = keyCondition;
				elapsedFrame = 0;
			}
		}
		oldKey = keyCondition;
		return keyRepeat;
	}
};