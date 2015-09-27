#include "RecipeManagerSP.h"

void RecipeManagerSP::loadRecipes() {
	RecipeManagerSP::addUniversalRecipes();
}

void RecipeManagerSP::addUniversalRecipes() {
    RecipeUtil::addRecipe(ItemInstance(SPItems::steelPickaxe, 1), "YYY", " X ", " X ", std::map<char, ItemInstance>{{'Y', ItemInstance(Item::stick)/*"compressedSteel"*/}, {'X', ItemInstance(Item::stick)}});

    RecipeUtil::addRecipe(ItemInstance(SPItems::steelAxe, 1), "YY ", "YX ", " X ", std::map<char, ItemInstance>{{'Y', ItemInstance(Item::stick)/*"compressedSteel"*/}, {'X', ItemInstance(Item::stick)}});

    RecipeUtil::addRecipe(ItemInstance(SPItems::steelHoe, 1), "YY ", " X ", " X ", std::map<char, ItemInstance>{{'Y', ItemInstance(Item::stick)/*"compressedSteel"*/}, {'X', ItemInstance(Item::stick)}});

    RecipeUtil::addRecipe(ItemInstance(SPItems::steelSpade, 1), " Y ", " X ", " X ", std::map<char, ItemInstance>{{'Y', ItemInstance(Item::stick)/*"compressedSteel"*/}, {'X', ItemInstance(Item::stick)}});

    RecipeUtil::addRecipe(ItemInstance(SPItems::steelSword, 1), " Y ", " Y ", " X ", std::map<char, ItemInstance>{{'Y', ItemInstance(Item::stick)/*"compressedSteel"*/}, {'X', ItemInstance(Item::stick)}});

    /*RecipeUtil::addRecipe(ItemInstance(SPItems::steelBoots, 1), "X X", "X X", "   ", std::map<char, ItemInstance>{{'X', ItemInstance(Item::stick)/*"compressedSteel"}});

    RecipeUtil::addRecipe(ItemInstance(SPItems::steelChestplate, 1), "X X", "XXX", "XXX", std::map<char, ItemInstance>{{'X', ItemInstance(Item::stick)/*"compressedSteel"}});

    RecipeUtil::addRecipe(ItemInstance(SPItems::steelLeggings, 1), "XXX", "X X", "X X", std::map<char, ItemInstance>{{'X', ItemInstance(Item::stick)/*"compressedSteel"}});

    RecipeUtil::addRecipe(ItemInstance(SPItems::steelHelmet, 1), "XXX", "X X", "   ", std::map<char, ItemInstance>{{'X', ItemInstance(Item::stick)/*"compressedSteel"}});*/
}
