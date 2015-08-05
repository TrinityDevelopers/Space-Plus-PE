#include "SwordItemSP.h"

SwordItemSP::SwordItemSP(std::string assetName) : Item(322 - 256/*IDGenSP::findNextItemID()*/) {
	setMaxStackSize(1);
	f1 = SPItems::TOOL_STEEL.damageVsEntity + 4.0F;
	setMaxDamage(SPItems::TOOL_STEEL.maxUses);
    setNameID(assetName);
    setIcon(assetName, 0);
	setCategory(3);
}

int SwordItemSP::getMaxUseDuration() const {
	return 72000;
}

float SwordItemSP::getDestroySpeed(ItemInstance *item, Tile *tile) {
	if(tile == Tile::web) {
		return 15.0F;
	} else {
		return 1.5F;
	}
}

bool SwordItemSP::canDestroySpecial(const Tile *tile) const {
	return tile == Tile::web;
}

void SwordItemSP::hurtEnemy(ItemInstance *item, Mob *m1, Mob *m2) {
	item->hurtAndBreak(1, m2);
}

void SwordItemSP::mineBlock(ItemInstance *item, int i1, int i2, int i3, int i4, Mob *m) {
	item->hurtAndBreak(2, m);
}

bool SwordItemSP::isHandEquipped() const {
	return true;
}

int SwordItemSP::getAttackDamage(Entity *ent) {
	return this->f1;
}