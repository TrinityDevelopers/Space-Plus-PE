#include "SPCoreUtil.h"

void SPCoreUtil::registerSpacePlusItem(std::string key, Item* item) {
    SpacePlusCore::itemList.insert(key, new ItemInstance(item));
}
