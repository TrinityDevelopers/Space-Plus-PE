#pragma once

#include <vector>

#include <SpacePlusCore.h>
#include "mcpe/item/Item.h"

class SPCoreUtil {
public:
	static int ItemID;
	static std::vector<std::string> armorTextures;

	static void registerSpacePlusItem(std::string, Item*);
	
	static int findNextItemID(int);
};
