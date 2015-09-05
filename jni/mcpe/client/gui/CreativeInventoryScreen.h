#pragma once

#include <vector>

#include "Screen.h"
#include "InventoryPane.h"
#include "../../item/ItemInstance.h"

class CreativeInventoryScreen : public Screen
{
public:
	std::vector<ItemInstance*> filteredItems;
	std::vector<ItemInstance*> items;
public:
	CreativeInventoryScreen();
	virtual ~CreativeInventoryScreen();
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual bool handleBackEvent(bool);
	virtual void tick();
	virtual bool renderGameBehind();
	virtual bool closeOnPlayerHurt();
	virtual void updateTabButtonSelection();
	virtual void buttonClicked(Button *);
	virtual void mouseClicked(int, int, int);
	virtual void mouseReleased(int, int, int);
	virtual void controllerDirectionChanged(int, Controller::StickDirection);
	virtual void controllerDirectionHeld(int, Controller::StickDirection);
	virtual void keyPressed(int);
	virtual bool addItem(const Touch::InventoryPane*, int);
	virtual bool isAllowed(int);
	virtual std::vector<ItemInstance*> getItems(const Touch::InventoryPane*);
	int getCategoryFromPanel(const Touch::InventoryPane*);
};
