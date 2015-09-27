#pragma once

#include <map>
#include <iterator>

#include "mcpe/item/ItemInstance.h"
#include "mcpe/recipe/Recipes.h"

class RecipeUtil {
public: 
	static void addRecipe(const ItemInstance&, std::string, std::string, std::string, std::map<char, ItemInstance>);
    
    static void addBlockRecipe(const ItemInstance&, const ItemInstance&);
};
