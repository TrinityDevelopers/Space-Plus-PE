#include "SwordItemSP.h"

int SwordItemSP::swordId = 0;

SwordItemSP::SwordItemSP(std::string assetName) : Item(SPCoreUtil::findNextItemID(swordId)) {
	if(!swordId)
		swordId = SPCoreUtil::ItemID - 256;
	setMaxStackSize(1);
	f1 = SPItems::TOOL_STEEL.damageVsEntity + 4.0F;
	enchantability = SPItems::TOOL_STEEL.enchantability;
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

bool SwordItemSP::mineBlock(ItemInstance *item, int i1, int i2, int i3, int i4, Mob *m) {
	item->hurtAndBreak(2, m);
	return true;
}

bool SwordItemSP::isHandEquipped() const {
	return true;
}

int SwordItemSP::getAttackDamage(Entity *ent) {
	return this->f1;
}

int SwordItemSP::getEnchantSlot() const {
	return 16;
}

int SwordItemSP::getEnchantValue() const {
	return this->enchantability;
}

bool SwordItemSP::isValidRepairItem(const ItemInstance& item1, const ItemInstance& item2) {
	return false; //ItemInstance(SPItems::basicItem, whatever) == item2;
} 

void SwordItemSP::appendFormattedHovertext(std::string& string, const ItemInstance& item) const {
	return Item::sword_iron->appendFormattedHovertext(string, item);
}

bool SwordItemSP::canDestroyInCreative() {
	return false;
}