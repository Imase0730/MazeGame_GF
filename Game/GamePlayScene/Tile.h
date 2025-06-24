#pragma once

// タイルクラス
class Tile
{

	// 列挙型の定義 -----------------------------------------------------
public:

	// タイルのタイプ
	enum class Type
	{
		None = -1,
		Floor,		// 0:床
		Wall,		// 1:壁
	};

	// クラス定数の宣言 -------------------------------------------------
public:

	// タイルのサイズ
	static constexpr int TILE_SIZE = 64;

};
