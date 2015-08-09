#pragma once
#include <string>

#include "DiggerItemSP.h"
#include "mcpe/tile/Tile.h"
#include "mcpe/tile/material/Material.h"
#include "space_plus/util/IDGenSP.h"
#include "SPItems.h"

class PickaxeItemSP : public DiggerItemSP {
public:
	static const std::vector<Tile*> pickaxeBlocks;
public:
    PickaxeItemSP(std::string);
	virtual bool canDestroySpecial(const Tile*) const;
	virtual float getDestroySpeed(ItemInstance*, Tile*);
};
