#pragma once

// �^�C���N���X
class Tile
{

	// �񋓌^�̒�` -----------------------------------------------------
public:

	// �^�C���̃^�C�v
	enum class Type
	{
		None = -1,
		Floor,		// 0:��
		Wall,		// 1:��
	};

	// �N���X�萔�̐錾 -------------------------------------------------
public:

	// �^�C���̃T�C�Y
	static constexpr int TILE_SIZE = 64;

};
