#pragma once

#include "Tile.h"

// タイルマップクラス
class TileMap
{

	// クラス定数の宣言 -------------------------------------------------
public:

	// タイルマップの幅
	static constexpr int TILEMAP_WIDTH = 10;

	// タイルマップの高さ
	static constexpr int TILEMAP_HEIGHT = 10;

	// メンバ変数の宣言 -------------------------------------------------
private:

	// マップデータ
	Tile::Type m_tileMap[TILEMAP_HEIGHT][TILEMAP_WIDTH];

	// プレイヤーの位置
	POINT m_playerPosition;

	// メンバ関数の宣言 -------------------------------------------------
public:

	// コンストラクタ
	TileMap();

	// 描画処理
	void Render(int ghTileset);

	// マップデータを読み込む関数
	bool LoadMapData(const wchar_t* filename);

	// プレイヤーの位置を取得する関数
	POINT GetPlayerPosition() const { return m_playerPosition; }

	// 指定した位置のタイルを取得する関数
	Tile::Type GetTile(int x, int y) const { return m_tileMap[y][x]; }

};
