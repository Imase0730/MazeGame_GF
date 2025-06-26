#pragma once

// プレイヤークラス
class Player
{
private:

	// 位置
	POINT m_position;

public:

	// コンストラクタ
	Player();

	// 更新処理
	void Update(int keyTrigger);

	// 描画処理
	void Render(int ghPlayer);

};

