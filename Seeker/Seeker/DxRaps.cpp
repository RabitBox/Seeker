#include "DxRaps.h"

VECTOR VGetRap(const Vector3 &vectors)
{
	VECTOR v = VGet(vectors.x, vectors.y, vectors.z);
	return v;
}
VECTOR AVGetRap(const AVector3 &vectors)
{
	VECTOR v = VGet(vectors.x, vectors.y, vectors.z);
	return v;
}//*/

void DrawQuadPolygon(const Vector3 &c_pos,	// ���S���W
	const Vector3 &norm,					// �@��
	const int &graph_handle,				// �摜�f�[�^
	const int &trans_flag,					// �������n���h��
	const Vector3 *vertex_pos)				// �z��œn�����߁A��ނȂ�const�|�C���^
{
	WORD index[6] = { 0, 1, 2, 3, 2, 1 };		// �C���f�b�N�X�̏���
	VERTEX3D vertex[4];							// �o�[�e�b�N�X�̏���

	for (int i = 0; i < 4; i++)
	{
		vertex[i].pos = VGetRap(vertex_pos[i]);
		vertex[i].norm = VGetRap(norm);
		vertex[i].dif = GetColorU8(255, 255, 255, 255);
		vertex[i].spc = GetColorU8(0, 0, 0, 0);
		vertex[i].u = 0.0f;
		vertex[i].v = 0.0f;
		vertex[i].su = 0.0f;
		vertex[i].sv = 0.0f;
	}
	DrawPolygonIndexed3D(vertex, 4, index, 2, graph_handle, trans_flag);
}

// �ʂ�Z��������-1�Ō��Ă���ꍇ�̐���
void DrawQuadPolygon(const Vector3 &c_pos,	// ��_���W
	const AVector3 &c_rot,					// ��_��]
	const Vector3 &scl,						// �T�C�Y
	const Vector3 &pos,						// ���W
	const AVector3 &rot,					// ��]
	const int &graph_handle,				// �摜�f�[�^
	const int &trans_flag)					// �������̃n���h��
{
	WORD index[6] = { 0, 1, 2, 3, 2, 1 };		// �C���f�b�N�X�̏���
	VERTEX3D vertex[4];							// �o�[�e�b�N�X�̏���
	AVector3 total_rotation = c_rot + rot;		// ��]�����v�����l
	Vector3 def_norm = {0.f, 0.f, -1.f};		// �f�t�H���g�̖@��
	float h_x = scl.x / 2, h_y = scl.y / 2, h_z = scl.z / 2;

	Vector3 norm = MatrixRotation3D(def_norm, { 0.0f, 0.0f, 0.0f }, {180.f,0.f,0.f});// total_rotation);
	DrawFormatString(0, 60, GetColor(255, 255, 255), "x:%f y:%f z:%f", norm.x, norm.y, norm.z);
	//DrawFormatString(0, 60, GetColor(255, 255, 255), "x:%f y:%f z:%f", total_rotation.x, total_rotation.y, total_rotation.z);

	Vector3 set_pos = MatrixRotation3D({ -h_x, h_y, h_z }, c_pos, total_rotation);
	//DrawFormatString(0, 60, GetColor(255, 255, 255), "x:%f y:%f z:%f", set_pos.x, set_pos.y, set_pos.z);
	vertex[0].pos = VGetRap(set_pos);
	vertex[0].norm = VGetRap(norm.normalized());
	vertex[0].dif = GetColorU8(255, 255, 255, 255);
	vertex[0].spc = GetColorU8(0, 0, 0, 0);
	vertex[0].u = 0.0f;
	vertex[0].v = 0.0f;
	vertex[0].su = 0.0f;
	vertex[0].sv = 0.0f;
	//DrawFormatString(0, 60, GetColor(255, 255, 255), "x:%f y:%f z:%f", set_pos.x, set_pos.y, set_pos.z);

	set_pos = MatrixRotation3D({ h_x, h_y, h_z }, c_pos, total_rotation);
	//DrawFormatString(0, 60, GetColor(255, 255, 255), "x:%f y:%f z:%f", set_pos.x, set_pos.y, set_pos.z);
	vertex[1].pos = VGetRap(set_pos);
	vertex[1].norm = VGetRap(norm.normalized());
	vertex[1].dif = GetColorU8(255, 255, 255, 255);
	vertex[1].spc = GetColorU8(0, 0, 0, 0);
	vertex[1].u = 1.0f;
	vertex[1].v = 0.0f;
	vertex[1].su = 0.0f;
	vertex[1].sv = 0.0f;
	//DrawFormatString(0, 75, GetColor(255, 255, 255), "x:%f y:%f z:%f", set_pos.x, set_pos.y, set_pos.z);

	set_pos = MatrixRotation3D({ -h_x, -h_y, h_z }, c_pos, total_rotation);
	//DrawFormatString(0, 60, GetColor(255, 255, 255), "x:%f y:%f z:%f", set_pos.x, set_pos.y, set_pos.z);
	vertex[2].pos = VGetRap(set_pos);
	vertex[2].norm = VGetRap(norm.normalized());
	vertex[2].dif = GetColorU8(255, 255, 255, 255);
	vertex[2].spc = GetColorU8(0, 0, 0, 0);
	vertex[2].u = 0.0f;
	vertex[2].v = 1.0f;
	vertex[2].su = 0.0f;
	vertex[2].sv = 0.0f;
	//DrawFormatString(0, 90, GetColor(255, 255, 255), "x:%f y:%f z:%f", set_pos.x, set_pos.y, set_pos.z);

	set_pos = MatrixRotation3D({ h_x, -h_y, h_z }, c_pos, total_rotation);
	//DrawFormatString(0, 60, GetColor(255, 255, 255), "x:%f y:%f z:%f", set_pos.x, set_pos.y, set_pos.z);
	vertex[3].pos = VGetRap(set_pos);
	vertex[3].norm = VGetRap(norm.normalized());
	vertex[3].dif = GetColorU8(255, 255, 255, 255);
	vertex[3].spc = GetColorU8(0, 0, 0, 0);
	vertex[3].u = 1.0f;
	vertex[3].v = 1.0f;
	vertex[3].su = 0.0f;
	vertex[3].sv = 0.0f;
	//DrawFormatString(0, 105, GetColor(255, 255, 255), "x:%f y:%f z:%f", set_pos.x, set_pos.y, set_pos.z);

	DrawPolygonIndexed3D(vertex, 4, index, 2, graph_handle, trans_flag);
}

void DrawQuad(const Vector3 &c_pos,	// ��_���W
	const AVector3 &c_rot,			// ��_��]
	const Vector3 &scl,				// �T�C�Y
	const Vector3 &pos,				// ���W
	const AVector3 &rot,			// ��]
	const int &graph_handle,		// �摜�f�[�^
	const int &trans_flag)			// �������̃n���h��
{
	WORD index[6] = { 0, 1, 2, 3, 2, 1 };		// �C���f�b�N�X�̏���
	VERTEX3D vertex[4];							// �o�[�e�b�N�X�̏���

	// vertex[0]


	// vertex[1]

	
	// vertex[2]


	// vertex[3]


	DrawPolygonIndexed3D(vertex, 4, index, 2, graph_handle, trans_flag);
}