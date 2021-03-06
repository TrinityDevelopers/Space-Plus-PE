#include "DiggerItemSP.h"

DiggerItemSP::DiggerItemSP(int id, float efficiency, Item::Tier category, std::vector<Tile*> set) : Item(id) {
	this->blockSet = set;
	this->_maxStackSize = 1;
	this->setMaxDamage(category.maxUses);
	this->efficiencyOnProperMaterial = category.efficiencyOnProperMaterial;
	this->damageVsEntity = efficiency + category.damageVsEntity;
	this->harvestLevel = category.harvestLevel;
	this->enchantability = category.enchantability;
}

float DiggerItemSP::getDestroySpeed(ItemInstance* item, Tile* tile) {
	std::find(blockSet.begin(), blockSet.end(), tile) != blockSet.end() ? this->efficiencyOnProperMaterial : 1.0F;
}

void DiggerItemSP::hurtEnemy(ItemInstance* item, Mob* victim, Mob* attacker) {
	item->hurtAndBreak(2, attacker);
}

bool DiggerItemSP::mineBlock(ItemInstance* item, int x, int y, int z, int i1, Mob* miner) {
	item->hurtAndBreak(1, miner);
	return true;
}

bool DiggerItemSP::isHandEquipped() const {
	return true;
}

int DiggerItemSP::getAttackDamage(Entity* ent) {
	return this->damageVsEntity;
}

void DiggerItemSP::appendFormattedHovertext(std::string& string, const ItemInstance& item) const {
	return Item::pickAxe_iron->appendFormattedHovertext(string, item);
}

int DiggerItemSP::getEnchantValue() const {
	return this->enchantability;
}

bool DiggerItemSP::isValidRepairItem(const ItemInstance& item1, const ItemInstance& item2) {
	return false; //ItemInstance(SPItems::basicItem, whatever) == item2;
}
	