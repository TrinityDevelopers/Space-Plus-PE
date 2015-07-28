#pragma once
#include <string>

#include <SpacePlusPECore.h>
#include "space_plus/util/IDGenSP.h"
#include "space_plus/proxy/ClientProxyCore"
#include "mcpe/item/ArmorItem.h"

class ArmorItemSP : public ArmorItem {
public:
    ArmorItemSP(int, std::string);
	
	void setArmorTexture(int);
};