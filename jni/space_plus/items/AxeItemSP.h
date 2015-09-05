#pragma once
#include <string>

#include "DiggerItemSP.h"
#include "mcpe/tile/material/Material.h"
#include "mcpe/tile/Tile.h"
#include "space_plus/util/SPCoreUtil.h"
#include "SPItems.h"

class AxeItemSP : public DiggerItemSP {
public:
	static int axeId;

	static const std::vector<Tile*> axeBlocks;
public:
    AxeItemSP(std::string);
	virtual float getDestroySpeed(ItemInstance*, Tile*);
	virtual int getEnchantSlot() const;
};
