#pragma once
#include <string>

#include "DiggerItemSP.h"
#include "space_plus/util/SPCoreUtil.h"
#include "mcpe/tile/Tile.h"
#include "mcpe/tile/material/Material.h"
#include "SPItems.h"

class SpadeItemSP : public DiggerItemSP {
public:
	static int spadeId;
	static const std::vector<Tile*> spadeBlocks;
public:
    SpadeItemSP(std::string);
	virtual bool canDestroySpecial(const Tile*) const;
	virtual float getDestroySpeed(ItemInstance*, Tile*);
	virtual bool useOn(ItemInstance*, Player*, int, int, int, signed char, float, float, float);
	virtual int getEnchantSlot() const;
};
