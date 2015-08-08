#pragma once

#include "Item.h"

class WeaponItem : public Item
{
public:
	float f1;
	const Item::Tier& tier;
public:
	virtual ~WeaponItem();
	virtual ItemInstance &use(ItemInstance &, Player &);
	virtual int getMaxUseDuration() const;
	virtual float getDestroySpeed(ItemInstance *, Tile *);
	virtual bool canDestroySpecial(const Tile *) const;
	virtual int getAttackDamage(Entity *);
	virtual void hurtEnemy(ItemInstance *, Mob *, Mob *);
	virtual bool mineBlock(ItemInstance *, int, int, int, int, Mob *);
	virtual bool isHandEquipped() const;
};
