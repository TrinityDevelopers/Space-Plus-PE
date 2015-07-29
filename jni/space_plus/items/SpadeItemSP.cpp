#include "SpadeItemSP.h"

SpadeItemSP::SpadeItemSP(std::string assetName) : ShovelItem(IDGenSP::findNextItemID(), SPItems::TOOL_STEEL) {
    setNameID(assetName);
    setIcon(assetName, 0);
	setCategory(3);
}
