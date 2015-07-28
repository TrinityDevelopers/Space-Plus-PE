#pragma once

#include "DiggerItem.h"

class HatchetItem : public DiggerItem
{
public:
	HatchetItem(int, const Item::Tier &);
	virtual ~HatchetItem();
	virtual float getDestroySpeed(ItemInstance *, Tile *);
};
