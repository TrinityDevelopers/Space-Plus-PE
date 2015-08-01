#include "SpacePlusCore.h"

const std::string SpacePlusCore::NAME = "SpacePlus Core";

CommonProxyCore* SpacePlusCore::proxy = new CommonProxyCore();

std::map<std::string, ItemInstance*> SpacePlusCore::itemList;
std::map<std::string, ItemInstance*> SpacePlusCore::blocksList;