#include "Player.h"
#include "Tile.h"

// コンストラクタ
Player::Player()
	: m_position{ 0, 0 }
{
}

// 更新処理
void Player::Update(int keyTrigger)
{
	// 上キー押された
	if (keyTrigger & PAD_INPUT_UP)
	{
		m_position.y--;
	}

	// 下キー押された
	if (keyTrigger & PAD_INPUT_DOWN)
	{
		m_position.y++;
	}

	// 左キー押された
	if (keyTrigger & PAD_INPUT_LEFT)
	{
		m_position.x--;
	}

	// 右キー押された
	if (keyTrigger & PAD_INPUT_RIGHT)
	{
		m_position.x++;
	}
}

// 描画処理
void Player::Render(int ghPlayer)
{
	// プレイヤーの描画
	DrawGraph(m_position.x * Tile::TILE_SIZE, m_position.y * Tile::TILE_SIZE
		, ghPlayer, TRUE);
}

