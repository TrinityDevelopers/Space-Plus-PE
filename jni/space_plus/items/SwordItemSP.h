#pragma once
#include <string>

#include "mcpe/item/Item.h"
#include "space_plus/util/SPCoreUtil.h"
#include "mcpe/tile/Tile.h"
#include "mcpe/item/ItemInstance.h"
#include "SPItems.h"

class SwordItemSP : public Item {
public:
	static int swordId;
	
	float f1;
	int enchantability;
public:
    SwordItemSP(std::string);
	virtual int getMaxUseDuration() const;
	virtual float getDestroySpeed(ItemInstance *, Tile *);
	virtual bool canDestroySpecial(const Tile *) const;
	virtual void hurtEnemy(ItemInstance *, Mob *, Mob *);
	virtual bool mineBlock(ItemInstance *, int, int, int, int, Mob *);
	virtual bool isHandEquipped() const;
	virtual int getAttackDamage(Entity *);
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual bool isValidRepairItem(const ItemInstance&, const ItemInstance&); 
	virtual void appendFormattedHovertext(std::string&, const ItemInstance&) const;
	bool canDestroyInCreative();
};
