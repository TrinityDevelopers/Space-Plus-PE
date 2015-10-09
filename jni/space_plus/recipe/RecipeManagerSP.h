#pragma once

#include "../util/RecipeUtil.h"
#include "../items/SPItems.h"
#include <SpacePlusCore.h>

class RecipeManagerSP {
public:
	static std::vector<ItemInstance> aluminumIngots;
	
	static void loadRecipes(Recipes*);
	
private:
	static void addUniversalRecipes();
};
