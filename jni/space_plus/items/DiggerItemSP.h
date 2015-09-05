#pragma once
#include <string>
#include <vector>
#include <algorithm>

#include "mcpe/item/Item.h"
#include "SPItems.h"

class DiggerItemSP : public Item {
private:
	std::vector<Tile*> blockSet;
protected:
	float efficiencyOnProperMaterial;
private:
	float damageVsEntity;
public:
	int harvestLevel;
	float enchantability;
public:
    DiggerItemSP(int, float, Item::Tier, std::vector<Tile*>);
	virtual float getDestroySpeed(ItemInstance*, Tile*);
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual bool mineBlock(ItemInstance*, int, int, int, int, Mob*);
	virtual bool isHandEquipped() const;
	virtual int getAttackDamage(Entity*);
	virtual void appendFormattedHovertext(std::string&, const ItemInstance&) const;
	virtual int getEnchantValue() const;
	virtual bool isValidRepairItem(const ItemInstance&, const ItemInstance&); 
};
