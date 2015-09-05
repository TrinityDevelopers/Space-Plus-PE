#include "PickaxeItemSP.h"

int PickaxeItemSP::pickaxeId = 0;

const std::vector<Tile*> PickaxeItemSP::pickaxeBlocks = {Tile::stoneBrick, Tile::stoneSlab, Tile::stoneSlabHalf, Tile::rock, Tile::sandStone, Tile::mossStone, Tile::ironOre, Tile::ironBlock, Tile::coalOre, Tile::goldBlock, Tile::goldOre, Tile::diamondOre, Tile::diamondBlock, Tile::ice, Tile::netherrack, Tile::lapisOre, Tile::lapisBlock, Tile::redStoneOre, Tile::redStoneOre_lit, Tile::rail, Tile::goldenRail};

PickaxeItemSP::PickaxeItemSP(std::string assetName) : DiggerItemSP(SPCoreUtil::findNextItemID(pickaxeId), 2.0F, SPItems::TOOL_STEEL, pickaxeBlocks) {
	pickaxeId = SPCoreUtil::ItemID - 256;
    setNameID(assetName);
    setIcon(assetName, 0);
	setCategory(3);
}

bool PickaxeItemSP::canDestroySpecial(const Tile* tile) const {
	return tile == Tile::obsidian ? this->harvestLevel == 3 : (tile != Tile::diamondBlock && tile != Tile::diamondOre ? (tile != Tile::emeraldOre && tile != Tile::emeraldBlock ? (tile != Tile::goldBlock && tile != Tile::goldOre ? (tile != Tile::ironBlock && tile != Tile::ironOre ? (tile != Tile::lapisBlock && tile != Tile::lapisOre ? (tile != Tile::redStoneOre && tile != Tile::redStoneOre_lit ? (tile->material == Material::stone ? true : (tile->material == Material::metal ? true : false)) : this->harvestLevel >= 2) : this->harvestLevel >= 1) : this->harvestLevel >= 1) : this->harvestLevel >= 2) : this->harvestLevel >= 2) : this->harvestLevel >= 2);
}

float PickaxeItemSP::getDestroySpeed(ItemInstance* item, Tile* tile) {
	return tile->material != Material::metal && tile->material != Material::stone ? 1.0F : this->efficiencyOnProperMaterial;
}

int PickaxeItemSP::getEnchantSlot() const {
	return 1024;
}
