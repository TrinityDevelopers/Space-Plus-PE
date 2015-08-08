#pragma once
#include <string>

#include "DiggerItemSP.h"
#include "mcpe/level/TileSource.h"
#include "mcpe/level/Level.h"
#include "mcpe/entity/player/Player.h"
#include "space_plus/util/IDGenSP.h"
#include "SPItems.h"

class SpadeItemSP : public DiggerItemSP {
public:
	static const std::vector<Tile*> spadeBlocks;
public:
    SpadeItemSP(std::string);
	virtual bool canDestroySpecial(const Tile*) const;
	//virtual bool useOn(ItemInstance*, Player*, int, int, int, signed char, float, float, float);
};
