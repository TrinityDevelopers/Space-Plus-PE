#pragma once

#include "DiggerItem.h"

class ShovelItem : public DiggerItem
{
public:
	ShovelItem(int, const Item::Tier &);
	virtual ~ShovelItem();
	virtual bool useOn(ItemInstance *, Player *, int, int, int, signed char, float, float, float);
	virtual bool canDestroySpecial(const Tile *) const;
};
