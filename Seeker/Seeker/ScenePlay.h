#pragma once
#include <vector>
#include <algorithm>
#include "SceneBase.h"
#include "Objects.h"
#include "StageDemo.h"
using namespace std;

class ScenePlay : public SceneBace
{
/*private:
	enum MapId
	{
		none		= 0,
		tinytim		= 1,
		stone_floor	= 2,
	};//*/

private:
	//vector < unique_ptr<Acter> > objects;//*/
	StageBase* stage;

public:
	ScenePlay();
	virtual ~ScenePlay();

	virtual void Update() override;
	virtual void Draw() override;

//private:
	//void LoadMapData();
	//void MapSet(int map_array[]);
	//void CreateObject(int obj_id, int x, int y, int f_x, int f_y);//*/
};