#pragma once

#include <string>
#include <array>
#include "CommonProxyCore.h"

class ClientProxyCore : public CommonProxyCore {
private:
    static int renderIndexHeavyArmor;
	
public:
	static std::array <std::string, 4096>* bl_armorRenders;

    int getTitaniumArmorRenderIndex();
};