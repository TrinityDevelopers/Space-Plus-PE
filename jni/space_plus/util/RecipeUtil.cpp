#include "RecipeUtil.h"

void RecipeUtil::addRecipe(const ItemInstance& result, std::string row1, std::string row2, std::string row3, std::map<char, ItemInstance> itemMap) {
	std::vector<std::string> shape = {row1, row2, row3};
	std::vector<Recipes::Type> ingredients;
	if(itemMap.size() == 1) {
		auto group0 = itemMap.begin();
		ingredients = recipeTypeDefinition1(group0->first, group0->second);
	}
	else if(itemMap.size() == 2) {
		auto group0 = itemMap.begin();
		auto group1 = std::next(itemMap.begin(), 1);
		ingredients = recipeTypeDefinition2(group0->first, group0->second, group1->first, group1->second);
	}
	else if(itemMap.size() == 3) {
		auto group0 = itemMap.begin();
		auto group1 = std::next(itemMap.begin(), 1);
		auto group2 = std::next(itemMap.begin(), 2);
		ingredients = recipeTypeDefinition3(group0->first, group0->second, group1->first, group1->second, group2->first, group2->second);
	}
	else if(itemMap.size() == 4) {
		auto group0 = itemMap.begin();
		auto group1 = std::next(itemMap.begin(), 1);
		auto group2 = std::next(itemMap.begin(), 2);
		auto group3 = std::next(itemMap.begin(), 3);
		ingredients = recipeTypeDefinition4(group0->first, group0->second, group1->first, group1->second, group2->first, group2->second, group3->first, group3->second);
	}
	Recipes::getInstance()->addShapedRecipe(result, shape, ingredients);
}

void RecipeUtil::addBlockRecipe(const ItemInstance& result, const ItemInstance& ingredient) {
	RecipeUtil::addRecipe(result, "XXX", "XXX", "XXX", std::map<char, ItemInstance>{{'X', ingredient}});
}
