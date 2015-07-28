#include "SpadeItemSP.h"

SpadeItemSP::SpadeItemSP(std::string assetName) : ShovelItem(IDGenSP::findNextItemID(), SPItems::TOOl_STEEL) {
    setNameID(assetName);
    setTexture(assetName, 0);
	setCategory(3);
}
