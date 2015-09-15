#pragma once

#include <SpacePlusCore.h>
#include "mcpe/item/Item.h"

class SPCoreUtil {
public:
	static int ItemID;
	static std::string armorTextures[4096];

	static void registerSpacePlusItem(std::string, Item*);
	
	static int findNextItemID(int);
};
