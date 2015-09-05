#include "HoeItemSP.h"

int HoeItemSP::hoeId = 0;

HoeItemSP::HoeItemSP(std::string assetName) : HoeItem(SPCoreUtil::findNextItemID(hoeId), SPItems::TOOL_STEEL) {
	if(!hoeId)
		hoeId = SPCoreUtil::ItemID - 256;
    setNameID(assetName);
    setIcon(assetName, 0);
	setCategory(3);
}
