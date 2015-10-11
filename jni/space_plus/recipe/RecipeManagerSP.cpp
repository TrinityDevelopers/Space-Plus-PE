#include "RecipeManagerSP.h"

void RecipeManagerSP::loadRecipes(Recipes* instance) {
	RecipeUtil::setInstance(instance);
	
	RecipeManagerSP::addUniversalRecipes();
}

void RecipeManagerSP::addUniversalRecipes() {
	RecipeUtil::pushIngredient(Item::ironIngot->id, 0, 1/*SpacePlusCore::itemList["compressedSteel"]*/, 'Y');
	RecipeUtil::pushIngredient(Item::stick->id, 0, 1, 'X');
	RecipeUtil::addRecipe(SPItems::steelPickaxe->id, 0, 1, {"YYY", " X ", " X "}); 
	
	RecipeUtil::pushIngredient(Item::ironIngot->id, 0, 1/*SpacePlusCore::itemList["compressedSteel"]*/, 'Y');
	RecipeUtil::pushIngredient(Item::stick->id, 0, 1, 'X');
	RecipeUtil::addRecipe(SPItems::steelAxe->id, 0, 1, {"YY ", "YX ", " X "});
	
	RecipeUtil::pushIngredient(Item::ironIngot->id, 0, 1/*SpacePlusCore::itemList["compressedSteel"]*/, 'Y');
	RecipeUtil::pushIngredient(Item::stick->id, 0, 1, 'X');
	RecipeUtil::addRecipe(SPItems::steelHoe->id, 0, 1, {"YY ", " X ", " X "});
	
	RecipeUtil::pushIngredient(Item::ironIngot->id, 0, 1/*SpacePlusCore::itemList["compressedSteel"]*/, 'Y');
	RecipeUtil::pushIngredient(Item::stick->id, 0, 1, 'X');
	RecipeUtil::addRecipe(SPItems::steelSpade->id, 0, 1, {" Y ", " X ", " X "});
	
	RecipeUtil::pushIngredient(Item::ironIngot->id, 0, 1/*SpacePlusCore::itemList["compressedSteel"]*/, 'Y');
	RecipeUtil::pushIngredient(Item::stick->id, 0, 1, 'X');
	RecipeUtil::addRecipe(SPItems::steelSword_>id, 0, 1, {" Y ", " Y ", " X "});
	
	/*RecipeUtil::pushIngredient(Item::ironIngot->id, 0, 1/*SpacePlusCore::itemList["compressedSteel"], 'Y');
	RecipeUtil::addRecipe(SPItems::steelBoots->id, 0, 1, {"X X", "X X", "   "});

	RecipeUtil::pushIngredient(Item::ironIngot->id, 0, 1/*SpacePlusCore::itemList["compressedSteel"], 'Y');
	RecipeUtil::addRecipe(SPItems::steelChestplate->id, 0, 1, {"X X", "XXX", "XXX"});

	RecipeUtil::pushIngredient(Item::ironIngot->id, 0, 1/*SpacePlusCore::itemList["compressedSteel"], 'Y');
	RecipeUtil::addRecipe(SPItems::steelLeggings->id, 0, 1, {"XXX", "X X", "X X"});

	RecipeUtil::pushIngredient(Item::ironIngot->id, 0, 1/*SpacePlusCore::itemList["compressedSteel"], 'Y');
	RecipeUtil::addRecipe(SPItems::steelHelmet->id, 0, 1, {"XXX", "X X", "   "});*/
}
