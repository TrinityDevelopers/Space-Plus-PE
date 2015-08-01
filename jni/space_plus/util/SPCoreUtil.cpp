#include "SPCoreUtil.h"

void SPCoreUtil::registerSpacePlusItem(std::string key, Item* item) {
    SpacePlusCore::itemList[key] = new ItemInstance(item);
}
