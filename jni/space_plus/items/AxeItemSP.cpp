#include "AxeItemSP.h"

const std::vector<Tile*> AxeItemSP::axeBlocks = {Tile::wood, Tile::bookshelf, Tile::log, Tile::log2, Tile::chest, Tile::pumpkin, Tile::litPumpkin};

AxeItemSP::AxeItemSP(std::string assetName) : DiggerItemSP(IDGenSP::findNextItemID(), 3.0F, SPItems::TOOL_STEEL, axeBlocks) {
    setNameID(assetName);
    setIcon(assetName, 0);
	setCategory(3);
}

float AxeItemSP::getDestroySpeed(ItemInstance* item, Tile* tile) {
	return tile->material != Material::wood && tile->material != Material::plant && tile->material != Material::replaceable_plant ? 1.0F : this->efficiencyOnProperMaterial;
}