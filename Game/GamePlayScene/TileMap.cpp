#include "TileMap.h"
#include <fstream>
#include <sstream>
#include <string>

// コンストラクタ
TileMap::TileMap()
	: m_tileMap{}
    , m_playerPosition{ 0, 0 }
{
}

// 描画処理
void TileMap::Render(int ghTileset)
{
    for (int i = 0; i < TILEMAP_HEIGHT; i++)
    {
        for (int j = 0; j < TILEMAP_WIDTH; j++)
        {
            int offsetX = 0;
            switch (m_tileMap[i][j])
            {
            case Tile::Type::Floor:	// 床
                offsetX = 0;
                break;
            case Tile::Type::Wall:	// 壁
                offsetX = 1;
                break;
            case Tile::Type::Chest:	// 宝箱
                offsetX = 2;
                break;
            default:
                break;
            }
            DrawRectGraph( j * Tile::TILE_SIZE, i * Tile::TILE_SIZE // 表示位置
                         , offsetX * Tile::TILE_SIZE, 0             // 絵の矩形の左上
                         , Tile::TILE_SIZE, Tile::TILE_SIZE         // 絵のサイズ
                         , ghTileset, FALSE);
        }
    }
}

// マップデータを読み込む関数
bool TileMap::LoadMapData(const wchar_t* filename)
{
	// ファイルをオープン
	std::ifstream ifs(filename);

    // オープン成功？
    if (!ifs.is_open())
    {
        // 失敗
		OutputDebugString(L"File Open Error! : %s", filename);

		return false;
    }

    for (int i = 0; i < TILEMAP_HEIGHT; i++)
    {
        // １行読み込む
        std::string line;
        getline(ifs, line);
        std::istringstream iss(line);
        for (int j = 0; j < TILEMAP_WIDTH; j++)
        {
            // カンマ区切りで分割する
            std::string item;
            getline(iss, item, ',');
            // マップデータの数字をタイルのタイプに置き換える
            switch (std::stoi(item))
            {
            case 0:     // 床
                m_tileMap[i][j] = Tile::Type::Floor;
                break;
            case 1:     // 壁
                m_tileMap[i][j] = Tile::Type::Wall;
                break;
            case 2:     // 宝箱
                m_tileMap[i][j] = Tile::Type::Chest;
                break;
            case 3:     // プレイヤー
                // プレイヤーの位置を記録する
                m_playerPosition = POINT{ j, i };
                // 床で登録する
                m_tileMap[i][j] = Tile::Type::Floor;
                break;
            default:
                break;
            }
        }
    }

	// ファイルをクローズ
	ifs.close();

	return true;
}

// 宝箱の数を取得する関数
int TileMap::GetChestCount() const
{
    int cnt = 0;

    for (int i = 0; i < TILEMAP_HEIGHT; i++)
    {
        for (int j = 0; j < TILEMAP_WIDTH; j++)
        {
            if (m_tileMap[i][j] == Tile::Type::Chest) cnt++;
        }
    }

    return cnt;
}
