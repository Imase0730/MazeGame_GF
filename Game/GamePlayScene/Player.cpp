#include "Player.h"
#include "Tile.h"

// コンストラクタ
Player::Player()
	: m_position{ 0, 0 }
{
}

// 更新処理
void Player::Update(int keyTrigger, TileMap* pTileMap)
{
	// 上キー押された
	if ( (keyTrigger & PAD_INPUT_UP)
	  && (IsMovable(pTileMap, m_position.x, m_position.y - 1))
	   ) 
	{
		m_position.y--;
	}

	// 下キー押された
	if ( (keyTrigger & PAD_INPUT_DOWN)
	  && (IsMovable(pTileMap, m_position.x, m_position.y + 1))
	   )
	{
		m_position.y++;
	}

	// 左キー押された
	if ( (keyTrigger & PAD_INPUT_LEFT)
	  && (IsMovable(pTileMap, m_position.x - 1, m_position.y))
	   )
	{
		m_position.x--;
	}

	// 右キー押された
	if ( (keyTrigger & PAD_INPUT_RIGHT)
	  && (IsMovable(pTileMap, m_position.x + 1, m_position.y))
	   )
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

// 指定した位置が移動できるか調べる関数
// 画面外　✖
// 壁　　　✖
bool Player::IsMovable(TileMap* pTileMap, int x, int y)
{
	// 画面外？
	if ((x < 0) || (x >= TileMap::TILEMAP_WIDTH)) return false;
	if ((y < 0) || (y >= TileMap::TILEMAP_HEIGHT)) return false;

	// 壁？
	if (pTileMap->GetTile(x, y) == Tile::Type::Wall) return false;

	return true;
}

