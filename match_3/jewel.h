#ifndef JEWEL_H
#define JEWEL_H

#include "raylib.h"

namespace M3
{
	const int GRID_SIZE = 54;
	struct Jewel
	{
		Vector2 pos_xy;		//where will draw in XY
		Vector2 pos_mat;	//where will be in the grid
		//X will be columns and Y will be row
		int kind;			//type of jewel
		int match;			//this way, if there's more than 2 matches, it will be destroyed
		Color color;
	};
	
	extern Jewel _jewels[10][10];	//For the moment, the grid will be hardcoded to be 10x10

	void init_jewel(Jewel jewels[10][10]);

}
#endif // !JEWEL_H