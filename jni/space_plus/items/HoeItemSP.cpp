#include "HoeItemSP.h"

HoeItemSP::HoeItemSP(std::string assetName) : HoeItem(IDGenSP::findNextItemID(), SPItems::TOOL_STEEL) {
    setNameID(assetName);
    setIcon(assetName, 0);
	setCategory(3);
}
