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

	// �v���C���[�̈ʒu
	POINT m_playerPosition;

	// �����o�֐��̐錾 -------------------------------------------------
public:

	// �R���X�g���N�^
	TileMap();

	// �`�揈��
	void Render(int ghTileset);

	// �}�b�v�f�[�^��ǂݍ��ފ֐�
	bool LoadMapData(const wchar_t* filename);

	// �v���C���[�̈ʒu���擾����֐�
	POINT GetPlayerPosition() const { return m_playerPosition; }

	// �w�肵���ʒu�̃^�C�����擾����֐�
	Tile::Type GetTile(int x, int y) const { return m_tileMap[y][x]; }

};
