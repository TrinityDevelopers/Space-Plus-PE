#pragma once

#include "CommonProxyCore.h"

class ClientProxyCore : public CommonProxyCore {
private:
    static int renderIndexHeavyArmor;
	
	static char** bl_armorRenders;

public:
    int getTitaniumArmorRenderIndex();
};