#pragma once
#include <string>

#include <SpacePlusCore.h>
#include "space_plus/util/IDGenSP.h"
#include "space_plus/proxy/ClientProxyCore.h"
#include "mcpe/item/ArmorItem.h"

class ArmorItemSP : public ArmorItem {
public:
    ArmorItemSP(int, std::string);
	
	void setArmorTexture(int);
};