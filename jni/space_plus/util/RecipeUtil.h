#pragma once

#include <map>
#include <iterator>

#include "mcpe/item/ItemInstance.h"
#include "mcpe/item/Item.h"
#include "mcpe/recipe/Recipes.h"

class RecipeUtil {
private: 
	static Recipes* _Instance; 
	static std::vector<Recipes::Type> _ingredients; 
	
public:
	static void setInstance(Recipes*);
	
	static void addRecipe(const ItemInstance&, const std::vector<std::string>&, std::map<char, ItemInstance>);
	
	static void pushIngredient(const ItemInstance&, char);
    
    static void addBlockRecipe(const ItemInstance&, const ItemInstance&);
};
