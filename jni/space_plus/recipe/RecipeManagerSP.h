#pragma once

#include "../util/RecipeUtil.h"
#include "../items/SPItems.h"

class RecipeManagerSP {
public:
	static std::vector<ItemInstance> aluminumIngots;
	
	static void loadRecipes();
	
private:
	static void addUniversalRecipes();
};
