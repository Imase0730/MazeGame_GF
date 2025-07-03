#pragma once

// 点滅クラス
class Blink
{
	// メンバ変数 --------------------------------------------
private:

	// 点滅の間隔
	int m_intervalFrame;

	// 点滅（ON/OFF）
	bool m_isBlinkOn;

	// タイマー
	int m_timer;

	// メンバ関数 --------------------------------------------
public:

	// コンストラクタ
	Blink(int intervalFrame);

	// 更新処理
	void Update();

	// 点滅（ON/OFF）を取得する関数
	bool IsBlinkOn() const { return m_isBlinkOn; }

	// 点滅の割合を取得する関数
	float GetBlinkRate() const;

};
