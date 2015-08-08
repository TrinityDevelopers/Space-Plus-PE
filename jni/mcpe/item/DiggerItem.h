#pragma once

#include "Item.h"

class DiggerItem : public Item
{
public:
	virtual ~DiggerItem();
	virtual float getDestroySpeed(ItemInstance *, Tile *);
	virtual int getAttackDamage(Entity *);
	virtual void hurtEnemy(ItemInstance *, Mob *, Mob *);
	virtual bool mineBlock(ItemInstance *, int, int, int, int, Mob *);
	virtual bool isHandEquipped() const;
};
