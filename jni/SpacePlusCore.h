#pragma once
#include <map>
#include <string>
#include <Constants.h>

#include "mcpe/item/ItemInstance.h"
#include "mcpe/item/Item.h"
#include "space_plus/proxy/ClientProxyCore.h"

class SpacePlusCore {
public:
	static const std::string NAME;

	static ClientProxyCore* proxy;
	
	static SpacePlusCore* instance;
	
    static std::map<std::string, ItemInstance*> itemList; 
    static std::map<std::string, ItemInstance*> blocksList; 
	
	void preInit();
};