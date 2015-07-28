#pragma once

#include "mcpe/tile/Tile.h"
#include "mcpe/level/Level.h"

class CommonProxyCore {
public:
    int getBlockRender(Tile* blockID);
	int getTitaniumArmorRenderIndex();
};
