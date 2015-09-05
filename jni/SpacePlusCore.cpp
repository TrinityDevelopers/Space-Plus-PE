#include "SpacePlusCore.h"
#include "space_plus/items/SPItems.h"

const std::string SpacePlusCore::NAME = "SpacePlus Core";

ClientProxyCore* SpacePlusCore::proxy = new ClientProxyCore();

SpacePlusCore* SpacePlusCore::instance = new SpacePlusCore();

std::map<std::string, ItemInstance*> SpacePlusCore::itemList;
std::map<std::string, ItemInstance*> SpacePlusCore::blocksList;

void SpacePlusCore::preInit() {
	
	SPItems::initItems();
	
}