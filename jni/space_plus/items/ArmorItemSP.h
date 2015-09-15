#pragma once
#include <string>
#include <vector>

#include <SpacePlusCore.h>
#include "space_plus/util/SPCoreUtil.h"
#include "space_plus/proxy/ClientProxyCore.h"
#include "mcpe/item/ArmorItem.h"
#include "SPItems.h"

class ArmorItemSP : public ArmorItem {
public:
	static std::vector<int> armorIds;
	
    ArmorItemSP(int, std::string);
	
	void setArmorTexture(int);
};