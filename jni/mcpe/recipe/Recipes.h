#pragma once

#include <string>
#include <vector>

class ItemInstance;

class Recipes {
public:
	class Type {
		
	};
	static Recipes* instance;

	Recipes();
	void init();
	void teardownRecipes();
	void Shape(const std::string&);
	void Shape(const std::string&, const std::string&);
	void Shape(const std::string&, const std::string&, const std::string&);
	static Recipes* getInstance();
	void addShapedRecipe(ItemInstance const&, std::vector<std::string> const&, std::vector<Recipes::Type> const&);
	void addShapelessRecipe(ItemInstance const&, std::vector<Recipes::Type> const&);
};

static std::vector<Recipes::Type> (*recipeTypeDefinition4)(char, ItemInstance, char, ItemInstance, char, ItemInstance, char, ItemInstance);
static std::vector<Recipes::Type> (*recipeTypeDefinition3)(char, ItemInstance, char, ItemInstance, char, ItemInstance);
static std::vector<Recipes::Type> (*recipeTypeDefinition2)(char, ItemInstance, char, ItemInstance);
static std::vector<Recipes::Type> (*recipeTypeDefinition1)(char, ItemInstance);
