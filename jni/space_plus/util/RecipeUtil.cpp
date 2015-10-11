#include "RecipeUtil.h"

Recipes* RecipeUtil::_Instance; 
std::vector<Recipes::Type> RecipeUtil::_ingredients; 

void RecipeUtil::setInstance(Recipes* instance) {
	_Instance = instance;
}

void RecipeUtil::pushIngredient(int id, int data, int count, char letter) {
	Recipes::Type type {Item::items[id], NULL, ItemInstance(), letter};
	_ingredients.push_back(type);
}

void RecipeUtil::addRecipe(int id, int data, int count, const std::vector<std::string>& shape) {
	ItemInstance result(Item::items[id]);
	result.count = count;
	_Instance->addShapedRecipe(result, shape, _ingredients);
	_ingredients.clear();
}

void RecipeUtil::addBlockRecipe(const ItemInstance& result, const ItemInstance& ingredient) {
	pushIngredient(ingredient.getId(), ingredient.damage, ingredient.count, 'X');
	addRecipe(result.getId(), result.damage, result.count, {"XXX", "XXX", "XXX"});
}
