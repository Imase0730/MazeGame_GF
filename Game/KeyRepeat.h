#pragma once

// 簡易キーリピートクラス
class KeyRepeat
{
private:

	// キーリピートの間隔
	static constexpr int KEY_REPEAT_INTERVEL = 20;

public:

	// 簡易キーリピートの取得関数
	static int GetKey(int keyCondition)
	{
		// キーが押されたフレーム数
		static int elapsedFrame = 0;
		// 1フレーム前のキーの情報
		static int oldKey = 0;
		int keyTrigger = ~oldKey & keyCondition;
		int keyRepeat = 0;
		// キーが押された
		if (keyCondition)
		{
			// キーが押された瞬間はキー情報を反映する
			if (keyTrigger)
			{
				keyRepeat = keyCondition;
				elapsedFrame = 0;
			}
			// キーが押されたフレーム数を加算する
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