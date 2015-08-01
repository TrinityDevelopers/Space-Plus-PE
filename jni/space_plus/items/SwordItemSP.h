#pragma once
#include <string>

#include "mcpe/item/Item.h"
#include "space_plus/util/IDGenSP.h"
#include "mcpe/tile/Tile.h"
#include "mcpe/item/ItemInstance.h"
#include "SPItems.h"

class SwordItemSP : public Item {
public:
	float f1;
public:
    SwordItemSP(std::string);
	virtual int getMaxUseDuration() const;
	virtual float getDestroySpeed(ItemInstance *, Tile *);
	virtual bool canDestroySpecial(const Tile *) const;
	virtual void hurtEnemy(ItemInstance *, Mob *, Mob *);
	virtual void mineBlock(ItemInstance *, int, int, int, int, Mob *);
	virtual bool isHandEquipped() const;
	virtual int getAttackDamage(Entity *);
};
