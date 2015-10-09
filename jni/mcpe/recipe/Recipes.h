#pragma once

#include <string>
#include <vector>
#include "mcpe/item/ItemInstance.h"

class Recipes {
public:
	struct Type {
		Item* item;
		Tile* tile;
		ItemInstance inst;
		char letter;
	};
	
	static Recipes* getInstance();
	static Recipes* instance;

	Recipes();
	void init();
	void teardownRecipes();
	void Shape(const std::string&);
	void Shape(const std::string&, const std::string&);
	void Shape(const std::string&, const std::string&, const std::string&);
	void addShapedRecipe(ItemInstance const&, std::vector<std::string> const&, std::vector<Recipes::Type> const&);
	void addShapedRecipe(ItemInstance const&, std::string const&, std::string const&, std::string const&, std::vector<Recipes::Type> const&);
	void addShapelessRecipe(ItemInstance const&, std::vector<Recipes::Type> const&);
};
