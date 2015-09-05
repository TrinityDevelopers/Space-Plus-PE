#pragma once

#include <string>
#include <array>
#include "CommonProxyCore.h"

static std::string** bl_armorRenders;

class ClientProxyCore : public CommonProxyCore {
private:
    static int renderIndexHeavyArmor;

public:
    int getTitaniumArmorRenderIndex();
};