#pragma once
#include "DxLib.h"
#include "Generic.h"

VECTOR	VGetRap(const Vector3 &vectors);
VECTOR	AVGetRap(const Vector3 &vectors);
void	DrawQuadPolygon(const Vector3 &c_pos, const Vector3 &norm, const int &graph_handle, const int &trans_flag, const Vector3 *vertex_pos);
void	DrawQuadPolygon(const Vector3 &c_pos, const AVector3 &c_rot, const Vector3 &scl, const Vector3 &pos, const AVector3 &rot, const int &graph_handle, const int &trans_flag);
void	DrawGraphExtend(int x, int y, float ext, const int &graph_handle, const int &trans_flag);
