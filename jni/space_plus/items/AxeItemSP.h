#pragma once
#include <string>

#include "DiggerItemSP.h"
#include "mcpe/tile/material/Material.h"
#include "space_plus/util/IDGenSP.h"
#include "SPItems.h"

class AxeItemSP : public DiggerItemSP {
public:
	static const std::vector<Tile*> axeBlocks;
public:
    AxeItemSP(std::string);
	virtual float getDestroySpeed(ItemInstance*, Tile*);
};
