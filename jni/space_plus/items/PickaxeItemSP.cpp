#include "PickaxeItemSP.h"

PickaxeItemSP::PickaxeItemSP(std::string assetName) : PickaxeItem(IDGenSP::findNextItemID(), SPItems::TOOl_STEEL) {
    setNameID(assetName);
    setTexture(assetName, 0);
	setCategory(3);
}
