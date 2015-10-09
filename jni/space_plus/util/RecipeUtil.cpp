#include "RecipeUtil.h"

Recipes* RecipeUtil::_Instance; 
std::vector<Recipes::Type> RecipeUtil::_ingredients; 

void RecipeUtil::setInstance(Recipes* instance) {
	_Instance = instance;
}

void RecipeUtil::addRecipe(const ItemInstance& result, const std::vector<std::string>& shape) {
	_Instance->addShapedRecipe(result, shape, _ingredients);
	_ingredients.clear();
}

void RecipeUtil::pushIngredient(const ItemInstance& inst, char letter) {
	Recipes::Type type {inst.item, inst.tile, inst, letter};
	_ingredients.push_back(type);
}

void RecipeUtil::addBlockRecipe(const ItemInstance& result, const ItemInstance& ingredient) {
	addRecipe(result, {"XXX", "XXX", "XXX"});
	pushIngredient(ingredient, 'X');
}
