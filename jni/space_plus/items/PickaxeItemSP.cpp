#include "PickaxeItemSP.h"

PickaxeItemSP::PickaxeItemSP(std::string assetName) : PickaxeItem(IDGenSP::findNextItemID(), SPItems::TOOL_STEEL) {
    setNameID(assetName);
    setIcon(assetName, 0);
	setCategory(3);
}
