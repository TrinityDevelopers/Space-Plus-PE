#include "SpadeItemSP.h"

const std::vector<Tile*> SpadeItemSP::spadeBlocks = {Tile::grass, Tile::dirt, Tile::sand, Tile::gravel, Tile::topSnow, Tile::snow, Tile::clay, Tile::farmland, /*Tile::soul_sand,*/ Tile::mycelium};

SpadeItemSP::SpadeItemSP(std::string assetName) : DiggerItemSP(IDGenSP::findNextItemID(), 1.0F, SPItems::TOOL_STEEL, spadeBlocks) {
    setNameID(assetName);
    setIcon(assetName, 0);
	setCategory(3);
}

bool SpadeItemSP::canDestroySpecial(const Tile* tile) const {
	return tile == Tile::topSnow ? true : (tile == Tile::snow);
}

/*bool SpadeItemSP::useOn(ItemInstance* item, Player* player, int x, int y, int z, signed char sc1, float f1, float f2, float f3) {
	Level* level = player->tileSource->getLevel();
	if(player->tileSource->getTilePtr(x, y, z) == Tile::grass) {
		level->playSound((float)x + 0.5F, (float)y + 0.5F, (float)z + 0.5F, Tile::grassPathBlock->soundType->stepOnSound, 0.8F * Tile::grassPathBlock->soundType->volume, 0.8 * Tile::grassPathBlock->soundType->frequency);
		item->hurtAndBreak(1, player);
		if(!level->isRemote) {
			player->tileSource->setTileAndData(x, y, z, {Tile::grassPathBlock->id, 0}, 3);
			return true;
		}
	}
	return true;
}*/