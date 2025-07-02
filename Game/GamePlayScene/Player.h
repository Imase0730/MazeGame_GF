#pragma once

#include "TileMap.h"

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
	void Update(int keyTrigger, TileMap* pTileMap);

	// 描画処理
	void Render(int ghPlayer);

	// 位置を設定する関数
	void SetPosition(POINT position) { m_position = position; }

	// 位置を取得する関数
	POINT GetPosition() const { return m_position; }

	// 指定した位置が移動できるか調べる関数
	bool IsMovable(TileMap* pTileMap, int x, int y);

};

