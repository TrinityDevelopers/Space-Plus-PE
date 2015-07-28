#include "AxeItemSP.h"

AxeItemSP::AxeItemSP(std::string assetName) : HatchetItem(IDGenSP::findNextItemID(), SPItems::TOOl_STEEL) {
    setNameID(assetName);
    setTexture(assetName, 0);
	setCategory(3);
}
