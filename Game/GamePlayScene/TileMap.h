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

	// メンバ関数の宣言 -------------------------------------------------
public:

	// コンストラクタ
	TileMap();

	// 描画処理
	void Render(int ghTileset);

	// マップデータを読み込む関数
	bool LoadMapData(const wchar_t* filename);

};
