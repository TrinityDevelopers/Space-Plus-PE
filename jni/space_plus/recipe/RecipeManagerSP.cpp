#include "RecipeManagerSP.h"

void RecipeManagerSP::loadRecipes(Recipes* instance) {
	RecipeUtil::setInstance(instance);
	
	RecipeManagerSP::addUniversalRecipes();
}

void RecipeManagerSP::addUniversalRecipes() {
	RecipeUtil::pushIngredient(ItemInstance(Item::ironIngot)/*SpacePlusCore::itemList["compressedSteel"]*/, 'Y');
	RecipeUtil::pushIngredient(ItemInstance(Item::stick), 'X');
    RecipeUtil::addRecipe(ItemInstance(SPItems::steelPickaxe), {"YYY", " X ", " X "}); 
	
	RecipeUtil::pushIngredient(ItemInstance(Item::ironIngot)/*SpacePlusCore::itemList["compressedSteel"]*/, 'Y');
	RecipeUtil::pushIngredient(ItemInstance(Item::stick), 'X');
    RecipeUtil::addRecipe(ItemInstance(SPItems::steelAxe), {"YY ", "YX ", " X "});
	
	RecipeUtil::pushIngredient(ItemInstance(Item::ironIngot)/*SpacePlusCore::itemList["compressedSteel"]*/, 'Y');
	RecipeUtil::pushIngredient(ItemInstance(Item::stick), 'X');
    RecipeUtil::addRecipe(ItemInstance(SPItems::steelHoe), {"YY ", " X ", " X "});
	
	RecipeUtil::pushIngredient(ItemInstance(Item::ironIngot)/*SpacePlusCore::itemList["compressedSteel"]*/, 'Y');
	RecipeUtil::pushIngredient(ItemInstance(Item::stick), 'X');
    RecipeUtil::addRecipe(ItemInstance(SPItems::steelSpade), {" Y ", " X ", " X "});
	
	RecipeUtil::pushIngredient(ItemInstance(Item::ironIngot)/*SpacePlusCore::itemList["compressedSteel"]*/, 'Y');
	RecipeUtil::pushIngredient(ItemInstance(Item::stick), 'X');
    RecipeUtil::addRecipe(ItemInstance(SPItems::steelSword), {" Y ", " Y ", " X "};
	
    /*RecipeUtil::pushIngredient(ItemInstance(Item::ironIngot)/*SpacePlusCore::itemList["compressedSteel"], 'Y');
	RecipeUtil::addRecipe(ItemInstance(SPItems::steelBoots), {"X X", "X X", "   "});

	RecipeUtil::pushIngredient(ItemInstance(Item::ironIngot)/*SpacePlusCore::itemList["compressedSteel"], 'Y');
    RecipeUtil::addRecipe(ItemInstance(SPItems::steelChestplate), {"X X", "XXX", "XXX"});

	RecipeUtil::pushIngredient(ItemInstance(Item::ironIngot)/*SpacePlusCore::itemList["compressedSteel"], 'Y');
    RecipeUtil::addRecipe(ItemInstance(SPItems::steelLeggings), {"XXX", "X X", "X X"});

	RecipeUtil::pushIngredient(ItemInstance(Item::ironIngot)/*SpacePlusCore::itemList["compressedSteel"], 'Y');
    RecipeUtil::addRecipe(ItemInstance(SPItems::steelHelmet), {"XXX", "X X", "   "});*/
}
