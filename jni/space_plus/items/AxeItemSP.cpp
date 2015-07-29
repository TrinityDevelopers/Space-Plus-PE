#include "AxeItemSP.h"

AxeItemSP::AxeItemSP(std::string assetName) : HatchetItem(IDGenSP::findNextItemID(), SPItems::TOOL_STEEL) {
    setNameID(assetName);
    setIcon(assetName, 0);
	setCategory(3);
}
