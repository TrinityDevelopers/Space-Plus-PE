#pragma once

#include <string>
#include <vector>

#include "mcpe/item/ItemInstance.h"
#include "mcpe/item/Item.h"
#include "mcpe/recipe/Recipes.h"


class RecipeUtil {
private: 
	static Recipes* _Instance; 
	static std::vector<Recipes::Type> _ingredients; 
	
public:
	static void setInstance(Recipes*);
	
	static void pushIngredient(int, int, int, char);
	
	static void addRecipe(int, int, int, const std::vector<std::string>&);
    
    static void addBlockRecipe(const ItemInstance&, const ItemInstance&);
};
