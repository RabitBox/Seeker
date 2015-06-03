#pragma once
#include <vector>
#include "SceneBase.h"
#include "Objects.h"

class ScenePlay : public SceneBace
{
private:
	enum MapId
	{
		none		= 0,
		tinytim		= 1,
		stone_floor	= 2,
	};

private:
	std::vector < std::unique_ptr<Acter> > objects;

public:
	ScenePlay();
	virtual ~ScenePlay();

	virtual void Input() override;
	virtual void Update() override;
	virtual void Draw() override;

private:
	void LoadMapData();
	void MapSet(int map_array[]);
	void CreateObject(int obj_id, int x, int y, int f_x, int f_y);
};