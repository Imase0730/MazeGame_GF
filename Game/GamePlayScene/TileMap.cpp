#include "TileMap.h"
#include <fstream>
#include <sstream>
#include <string>

// �R���X�g���N�^
TileMap::TileMap()
	: m_tileMap{}
{
}

// �`�揈��
void TileMap::Render(int ghTileset)
{
    for (int i = 0; i < TILEMAP_HEIGHT; i++)
    {
        for (int j = 0; j < TILEMAP_WIDTH; j++)
        {
            int offsetX = 0;
            switch (m_tileMap[i][j])
            {
            case Tile::Type::Floor:	// ��
                offsetX = 0;
                break;
            case Tile::Type::Wall:	// ��
                offsetX = 1;
                break;
            default:
                break;
            }
            DrawRectGraph( j * Tile::TILE_SIZE, i * Tile::TILE_SIZE // �\���ʒu
                         , offsetX * Tile::TILE_SIZE, 0             // �G�̋�`�̍���
                         , Tile::TILE_SIZE, Tile::TILE_SIZE         // �G�̃T�C�Y
                         , ghTileset, FALSE);
        }
    }
}

// �}�b�v�f�[�^��ǂݍ��ފ֐�
bool TileMap::LoadMapData(const wchar_t* filename)
{
	// �t�@�C�����I�[�v��
	std::ifstream ifs(filename);

    // �I�[�v�������H
    if (!ifs.is_open())
    {
        // ���s
		OutputDebugString(L"File Open Error! : %s", filename);

		return false;
    }

    for (int i = 0; i < TILEMAP_HEIGHT; i++)
    {
        // �P�s�ǂݍ���
        std::string line;
        getline(ifs, line);
        std::istringstream iss(line);
        for (int j = 0; j < TILEMAP_WIDTH; j++)
        {
            // �J���}��؂�ŕ�������
            std::string item;
            getline(iss, item, ',');
            // �}�b�v�f�[�^�̐������^�C���̃^�C�v�ɒu��������
            switch (std::stoi(item))
            {
            case 0:     // ��
                m_tileMap[i][j] = Tile::Type::Floor;
                break;
            case 1:     // ��
                m_tileMap[i][j] = Tile::Type::Wall;
                break;
            default:
                break;
            }
        }
    }

	// �t�@�C�����N���[�Y
	ifs.close();

	return false;
}
