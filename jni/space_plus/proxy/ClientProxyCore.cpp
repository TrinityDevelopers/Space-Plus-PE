#include "ClientProxyCore.h"

int ClientProxyCore::renderIndexHeavyArmor = 42;

int ClientProxyCore::getTitaniumArmorRenderIndex() {
    return ClientProxyCore::renderIndexHeavyArmor;
}