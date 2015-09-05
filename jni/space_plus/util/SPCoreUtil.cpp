#include "SPCoreUtil.h"

int SPCoreUtil::ItemID = 256;

void SPCoreUtil::registerSpacePlusItem(std::string key, Item* item) {
    SpacePlusCore::itemList[key] = new ItemInstance(item);
}

int SPCoreUtil::findNextItemID(int testId) {
	if(testId != 0)	
		return testId;
	while(Item::items[SPCoreUtil::ItemID] != NULL) {
		SPCoreUtil::ItemID++;
	}
	return SPCoreUtil::ItemID - 256;
}

