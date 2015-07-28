#pragma once

#include "CommonProxyCore.h"

class ClientProxyCore : public CommonProxyCore {
private:
    static int renderIndexHeavyArmor;
	
public:
	static char** bl_armorRenders;

    int getTitaniumArmorRenderIndex();
};