#include "Blink.h"

// コンストラクタ
Blink::Blink(int intervalFrame)
	: m_intervalFrame{ intervalFrame }
	, m_isBlinkOn{ false }
	, m_timer{ 0 }
{
}

// 更新処理
void Blink::Update()
{
	// タイマーを加算する
	m_timer++;

	// 点滅間隔を超えていたら
	if (m_timer > m_intervalFrame)
	{
		// タイマーをリセットする
		m_timer = 0;

		// 点滅
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

// 点滅の割合を取得する関数
float Blink::GetBlinkRate() const
{
	// 0.0 → 1.0f → 0.0f
	if (m_timer <= m_intervalFrame / 2)
	{
		return m_timer / (m_intervalFrame / 2.0f);
	}
	return (m_intervalFrame - m_timer) / (m_intervalFrame / 2.0f);
}
