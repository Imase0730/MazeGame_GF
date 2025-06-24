#pragma once

#include "Tile.h"

// �^�C���}�b�v�N���X
class TileMap
{

	// �N���X�萔�̐錾 -------------------------------------------------
public:

	// �^�C���}�b�v�̕�
	static constexpr int TILEMAP_WIDTH = 10;

	// �^�C���}�b�v�̍���
	static constexpr int TILEMAP_HEIGHT = 10;

	// �����o�ϐ��̐錾 -------------------------------------------------
private:

	// �}�b�v�f�[�^
	Tile::Type m_tileMap[TILEMAP_HEIGHT][TILEMAP_WIDTH];

	// �����o�֐��̐錾 -------------------------------------------------
public:

	// �R���X�g���N�^
	TileMap();

	// �`�揈��
	void Render(int ghTileset);

	// �}�b�v�f�[�^��ǂݍ��ފ֐�
	bool LoadMapData(const wchar_t* filename);

};
