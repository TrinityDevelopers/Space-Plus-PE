#include "HoeItemSP.h"

HoeItemSP::HoeItemSP(std::string assetName) : HoeItem(IDGenSP::findNextItemID(), SPItems::TOOl_STEEL) {
    setNameID(assetName);
    setTexture(assetName, 0);
	setCategory(3);
}
